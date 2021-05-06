#include<iostream>
using namespace std;
class RationalNumber
{
private:
	int numerator;
	int denominator;
	int gcd(int, int);
	void simplify();
public:
	RationalNumber(int,int);
	void print();
	friend RationalNumber operator +(RationalNumber, RationalNumber);
	friend RationalNumber operator -(RationalNumber, RationalNumber);
	friend RationalNumber operator *(RationalNumber, RationalNumber);
	friend RationalNumber operator /(RationalNumber, RationalNumber);
	friend ostream& operator <<(ostream& outputStream, RationalNumber number);
};
int RationalNumber::gcd(int x, int y)
{
	if (x < y)
		return gcd(y, x);
	if (x % y != 0)
		return gcd(x, x % y);
	else
		return y;
}
void RationalNumber::simplify()
{
	if (numerator)
	{
		int g = gcd(abs(numerator), denominator);
		numerator /= g;
		denominator /= g;
	}
	else
		denominator = 1;
}
RationalNumber::RationalNumber(int nume,int deno)
{
	numerator = nume;
	denominator = deno;
	if (deno==0)
	{
		cout << "Denominator should not be zero." << endl;
		exit(1);
	}
	simplify();
}
RationalNumber operator + (RationalNumber num1, RationalNumber num2)
{
	return RationalNumber(num1.numerator * num2.denominator + num2.numerator * num1.denominator, num1.denominator * num2.denominator);
}
RationalNumber operator - (RationalNumber num1, RationalNumber num2)
{
	return RationalNumber(num1.numerator * num2.denominator - num2.numerator * num1.denominator, num1.denominator * num2.denominator);
}
RationalNumber operator * (RationalNumber num1, RationalNumber num2)
{
	return RationalNumber(num1.numerator * num2.numerator,num1.denominator*num2.denominator);
}RationalNumber operator / (RationalNumber num1, RationalNumber num2)
{
	if (num1.denominator == 0 || num2.denominator == 0)
	{
		cout << "Divisor should not be zero." << endl;
		exit(1);
	}
	return RationalNumber(num1.numerator * num2.denominator, num1.denominator * num2.numerator);
}
void RationalNumber::print()
{
	if (numerator % denominator == 0)
		cout << numerator / denominator;
	else
		cout << numerator << "/" << denominator;
}

ostream& operator << (ostream& outputstream, RationalNumber number)
{
	cout << number.numerator << '/' << number.denominator;
}