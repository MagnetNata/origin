#include <iostream>
#include "Counterr.h"
using namespace std;

Counter::Counter()
{
    x = 1;
}
Counter::Counter(int x)
{
    this->x = x;
}
void Counter::setX(int x)
{
    this->x = x;
}
void Counter::bolshe()
{
    x++;
}
void Counter::menshe()
{
    x--;
}
void Counter::prosmotr()
{
    std::cout << std::endl << x << std::endl;
}