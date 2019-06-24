#include<iostream>

#include "../engunits/length.h"

int main() {
    using namespace EngUnits::length;
    using namespace std;

    meters m=5;
    
    if (4<m<7) {
    cout << m << endl;
    }
    return 0;
}