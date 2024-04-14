#include <iostream>
#include "ErrorArgument1.h"
#include <string>
using namespace std;

std::string err;
const char* ErrorArgument::get_err()
{
   return err.c_str();
}
const char* ErrorArgument::what()
{
    return err.c_str();
}
