#include <iostream>
#include "ErrorArgument1.h"
#include <string>
using namespace std;

std::string err;
const char* get_err()
{
   return err.c_str();
}
const char* what()
{
    return err.c_str();
}
