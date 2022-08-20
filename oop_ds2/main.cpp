#include <iostream>
#include "rational.h"

using namespace std;
int main () {
    int T;
    int command, a, b, c, d;
    cin >> T;
    while (T--) {
        cin >> command >> a >> b >> c >> d;
        if (command == 1) {
            // Binary Arithmetic
            Rational in1(a, b);
            Rational in2(c, d);
            cout << "Operator + " << in1+in2 << endl;
            cout << "Operator - " << in1-in2 << endl;
            cout << "Operator * " << in1*in2 << endl;
            cout << "Operator / " << in1/in2 << endl;

        } else if(command == 2) {
            // Assignment
            Rational in1(a, b);
            Rational in2(c, d);
            Rational tmp(1, 1);
            tmp += in1;
            tmp += in2;
            cout << "Operator += " << tmp << endl;

            tmp = Rational(1, 1);
            tmp -= in1;
            tmp -= in2;
            cout << "Operator -= " << tmp << endl;

            tmp = Rational(1, 1);
            tmp *= in1;
            tmp *= in2;
            cout << "Operator *= " << tmp << endl;

            tmp = Rational(1, 1);
            tmp /= in1;
            tmp /= in2;
            cout << "Operator /= " << tmp << endl;

        } else if(command == 3) {
            // Relational
            Rational in1(a, b);
            Rational in2(c, d);
            cout << "Operator > " << (in1>in2) << endl;
            cout << "Operator < " << (in1<in2) << endl;
            cout << "Operator >= " << (in1>=in2) << endl;
            cout << "Operator <= " << (in1<=in2) << endl;
            cout << "Operator == " << (in1==in2) << endl;
            cout << "Operator != " << (in1!=in2) << endl;

        } else if(command == 4) {
            // Unary Arithmetic
            Rational in1(a, b);
            Rational in2(c, d);
            Rational tmp(0, 1);
            tmp = (++in1) + (++in2);
            cout << "Operator prefix ++ " << tmp << ' ' << in1 << ' ' << in2 << endl;
            in1 = Rational(a, b);
            in2 = Rational(c, d);
            tmp = Rational(0, 1);
            tmp = (in1++) + (in2++);
            cout << "Operator postfix ++ " << tmp << ' ' << in1 << ' ' << in2 << endl;
            in1 = Rational(a, b);
            in2 = Rational(c, d);
            tmp = Rational(0, 1);
            tmp = (--in1) + (--in2);
            cout << "Operator prefix -- " << tmp << ' ' << in1 << ' ' << in2 << endl;
            in1 = Rational(a, b);
            in2 = Rational(c, d);
            tmp = Rational(0, 1);
            tmp = (in1--) + (in2--);
            cout << "Operator postfix -- " << tmp << ' ' << in1 << ' ' << in2 << endl;
            in1 = Rational(a, b);
            in2 = Rational(c, d);
            cout << "Operator negative- " << (-in1) << ' ' << (-in2) << endl;
        }
    }
}
