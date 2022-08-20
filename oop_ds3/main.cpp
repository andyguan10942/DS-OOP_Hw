#include <iostream>
#include "mylist.h"
using namespace std;
int main () {
    myList<int> int_list;
    myList<double> double_list;
    int T;
    int command;
    cin >> T;
    while(T--) {
        cin >> command;
        int int_data;
        double double_data;
        int index;
        if (command == 1) {
            cin >> int_data >> double_data;
            int_list.push_back(int_data);
            double_list.push_back(double_data);
        } else if (command == 2) {
            cin >> int_data >> double_data;
            int_list.push_front(int_data);
            double_list.push_front(double_data);
        } else if (command == 3) {
            cin >> index >> int_data >> double_data;
            int_list.insert(index, int_data);
            double_list.insert(index, double_data);
        } else if (command == 4) {
            int_list.pop_back();
            double_list.pop_back();
        } else if (command == 5) {
            int_list.pop_front();
            double_list.pop_front();
        } else if (command == 6) {
            cin >> index;
            int_list.pop_index(index);
            double_list.pop_index(index);
        } else if (command == 7) {
            cout << "int_list: ";
            int_list.print();
            cout << "double_list: ";
            double_list.print();
        }
    }
    return 0;
}
