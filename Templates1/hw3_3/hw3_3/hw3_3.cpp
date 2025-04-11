#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <memory>

enum class Type {
    WARNING,
    ERROR,
    FATAL_ERROR,
    UNKNOWN
};

class LogMessage {
public:
    LogMessage(Type type, const std::string& message)
        : type_(type), message_(message) {}

    Type type() const { return type_; }
    const std::string& message() const { return message_; }

private:
    Type type_;
    std::string message_;
};

class Handler {
public:
    virtual ~Handler() = default;

    void setNext(std::shared_ptr<Handler> next) {
        next_ = next;
    }

    virtual void handle(const LogMessage& msg) {
        if (next_) {
            next_->handle(msg);
        }
    }

protected:
    std::shared_ptr<Handler> next_;
};

class FatalErrorHandler : public Handler {
public:
    void handle(const LogMessage& msg) override {
        if (msg.type() == Type::FATAL_ERROR) {
            throw std::runtime_error("Fatal error: " + msg.message());
        }
        Handler::handle(msg);
    }
};

class ErrorHandler : public Handler {
public:
    explicit ErrorHandler(const std::string& filePath)
        : filePath_(filePath) {}

    void handle(const LogMessage& msg) override {
        if (msg.type() == Type::ERROR) {
            std::ofstream file(filePath_, std::ios::app);
            if (file.is_open()) {
                file << "Error: " << msg.message() << std::endl;
            }
            return;
        }
        Handler::handle(msg);
    }

private:
    std::string filePath_;
};

class WarningHandler : public Handler {
public:
    void handle(const LogMessage& msg) override {
        if (msg.type() == Type::WARNING) {
            std::cout << "Warning: " << msg.message() << std::endl;
            return;
        }
        Handler::handle(msg);
    }
};

class UnknownHandler : public Handler {
public:
    void handle(const LogMessage& msg) override {
        if (msg.type() == Type::UNKNOWN) {
            throw std::runtime_error("Unhandled message: " + msg.message());
        }
        Handler::handle(msg);
    }
};

std::shared_ptr<Handler> createChain(const std::string& errorLogPath) {
    auto fatal = std::make_shared<FatalErrorHandler>();
    auto error = std::make_shared<ErrorHandler>(errorLogPath);
    auto warning = std::make_shared<WarningHandler>();
    auto unknown = std::make_shared<UnknownHandler>();

    fatal->setNext(error);
    error->setNext(warning);
    warning->setNext(unknown);

    return fatal;
}

int main() {
    try {
        auto chain = createChain("errors.log");

        chain->handle(LogMessage(Type::WARNING, "Low disk space"));
        chain->handle(LogMessage(Type::ERROR, "Network failure"));
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}