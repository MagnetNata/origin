#include <iostream>
#include <exception>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	bool operator==(const Fraction& x) const
	{
		if (this->numerator_ == x.numerator_ and this->denominator_ == x.denominator_)
			return true;
		else
			return false;
	}
	bool operator!=(const Fraction& x) const
	{
		if (this->numerator_ == x.numerator_ and this->denominator_ == x.denominator_)
			return false;
		else
			return true;
	}
	bool operator<(const Fraction& x) const
	{
		if (this->numerator_ < x.numerator_)
			return true;
		else if (this->numerator_ == x.numerator_ and this->denominator_ < x.denominator_)
			return true;
		else
			return false;
	}
	bool operator>(const Fraction& x) const
	{
		if (this->numerator_ > x.numerator_)
			return true;
		else if (this->numerator_ == x.numerator_ and this->denominator_ > x.denominator_)
			return true;
		else
			return false;
	}
	bool operator<=(const Fraction& x) const
	{
		if (this->numerator_ <= x.numerator_)
			return true;
		else if (this->numerator_ == x.numerator_ and this->denominator_ <= x.denominator_)
			return true;
		else
			return false;
	}
	bool operator>=(const Fraction& x) const
	{
		if (this->numerator_ >= x.numerator_)
			return true;
		else if (this->numerator_ == x.numerator_ and this->denominator_ >= x.denominator_)
			return true;
		else
			return false;
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}