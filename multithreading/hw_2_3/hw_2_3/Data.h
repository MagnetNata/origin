#pragma once
#include <mutex>
#include <vector>


class Data
{
private:
	int value1 = 0;


public:
	Data() = default;
	Data(int value) : value1(value) {}

	std::mutex mutex1;

	int getValue() const;
	void setValue(int value);
};