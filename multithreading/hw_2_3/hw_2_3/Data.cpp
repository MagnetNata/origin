#include "Data.h"
#include <iostream>

int Data::getValue() const
{
	return Data::value1;
}

void Data::setValue(int value)
{
	Data::value1 = value;
}
