#include<iostream>
#include<map>

#include "../engunits/length.h"

void print_bool (bool b){
    std::cout<< (b ? "true" : "false") << std::endl;
}

int main() {
    using namespace EngUnits::length;
    using namespace std;

    // meters m;
    // m = 5;
    // feet f = 10;
    // f += m;
    // inches i = 13;
    // feet ff(i);
    // if ((m-2)<m<(m+2)!=m){
    //     cout << ff << endl;
    // }
    meters mb{5};
    feet fb{5};
    mb=10;
    cout << mb << endl;
    cout << fb.true_val() << endl;

    return 0;
}