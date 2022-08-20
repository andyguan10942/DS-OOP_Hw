#include <iostream>
#include "ration.h"

using namespace std;
int main () {
    int T;
    int command, a, b, c, d;
    cin >> T;
    
    while (T--) {
        cin >> command >> a >> b >> c >> d;
        if (command == 1) {
            // add
            Rational in1(a, b);
            Rational in2(c, d);
            in1.add(in2);
            in1.print();

        } else if(command == 2) {
            // sub
            Rational in1(a, b);
            Rational in2(c, d);
            in1.sub(in2);
            in1.print();
        } else if(command == 3) {
            // mul
            Rational in1(a, b);
            Rational in2(c, d);
            in1.mul(in2);
            in1.print();
        } else if(command == 4) {
            // div
            Rational in1(a, b);
            Rational in2(c, d);
            in1.div(in2);
            in1.print();
        }
    }
}
