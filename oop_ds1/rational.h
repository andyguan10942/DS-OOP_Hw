#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
class Rational{
private:
    int a; // numerator
    int b; // denominator

public:
    Rational(const int &numerator=1,const int &denominator=1);
    void add(const Rational &in);
    void sub(const Rational &in);
    void mul(const Rational &in);
    void div(const Rational &in);
    int gcd(int num1,int num2);//算最大公因數 
    void print();

};
