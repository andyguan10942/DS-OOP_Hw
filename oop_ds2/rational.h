#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
class Rational{
private:
    int a; // numerator
    int b; // denominator

public:
	Rational(const int numerator=1, const int denominator=1);
    // TODO 
	// write all declarations here
	int gcd(int num1,int num2);//算最大公因數 
	
	//1) Binary Arithmetic
	const Rational operator+(const Rational & in);
	const Rational operator-(const Rational & in);
	const Rational operator*(const Rational & in);
	const Rational operator/(const Rational & in);
	
	//2) Assignment
	Rational & operator=(const Rational & in);
	const Rational & operator+=(const Rational & in);
	const Rational & operator-=(const Rational & in);
	const Rational & operator*=(const Rational & in);
	const Rational & operator/=(const Rational & in);
	
	//3)Relational
	bool operator>(const Rational & in);
	bool operator<(const Rational & in);
	bool operator>=(const Rational & in);
	bool operator<=(const Rational & in);
	bool operator==(const Rational & in);
	bool operator!=(const Rational & in);
		
	//4) Unary Arithmetic
    Rational & operator++(); //prefix++
    Rational operator++(int);//postfix++
	Rational & operator--(); //prefix--
	Rational operator--(int);//postfix--
	Rational operator-();    //negative	
	//friend
	friend ostream & operator<<(ostream & os,const Rational & in);
};
