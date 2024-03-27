#pragma once
#include <iostream>
#include <string>
using namespace std;

class ErrorArgument: public std::exception
{
public:
    std::string err;
    ErrorArgument(std::string _err) :err(_err) {}
    const char* get_err();
    virtual const char* what() const override;
};