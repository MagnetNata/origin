#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};

class Observable {
public:
    void addObserver(Observer* observer) {
        observers_.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers_.erase(
            std::remove(observers_.begin(), observers_.end(), observer),
            observers_.end()
        );
    }

    void warning(const std::string& message) const {
        for (auto observer : observers_) {
            if (observer) {
                observer->onWarning(message);
            }
        }
    }

    void error(const std::string& message) const {
        for (auto observer : observers_) {
            if (observer) {
                observer->onError(message);
            }
        }
    }

    void fatalError(const std::string& message) const {
        for (auto observer : observers_) {
            if (observer) {
                observer->onFatalError(message);
            }
        }
    }

private:
    std::vector<Observer*> observers_;
};

class WarningObserver : public Observer {
public:
    void onWarning(const std::string& message) override {
        std::cout << "Warning: " << message << std::endl;
    }
};

class ErrorObserver : public Observer {
public:
    explicit ErrorObserver(const std::string& filePath)
        : filePath_(filePath) {}

    void onError(const std::string& message) override {
        std::ofstream file(filePath_, std::ios::app);
        if (file.is_open()) {
            file << "Error: " << message << std::endl;
        }
    }

private:
    std::string filePath_;
};

class FatalErrorObserver : public Observer {
public:
    explicit FatalErrorObserver(const std::string& filePath)
        : filePath_(filePath) {}

    void onFatalError(const std::string& message) override {
        std::cout << "Fatal Error: " << message << std::endl;

        std::ofstream file(filePath_, std::ios::app);
        if (file.is_open()) {
            file << "Fatal Error: " << message << std::endl;
        }
    }

private:
    std::string filePath_;
};

int main() {
    Observable logger;

    WarningObserver warningObserver;
    ErrorObserver errorObserver("errors.log");
    FatalErrorObserver fatalErrorObserver("fatal_errors.log");

    logger.addObserver(&warningObserver);
    logger.addObserver(&errorObserver);
    logger.addObserver(&fatalErrorObserver);

    logger.warning("Disk space low");
    logger.error("Network connection lost");
    logger.fatalError("Critical system failure");

    logger.removeObserver(&errorObserver);
    logger.error("This error won't be logged");

    return 0;
}