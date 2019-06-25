#include<iostream>
#include<map>

#include "../engunits/length.h"

int main() {
    using namespace EngUnits::length;
    using namespace std;

    meters m;
    m = 5;
    feet f = 10;
    f += m;
    inches i = 12;
    feet ff(i);
    if ((m-2)<m<(m+2)!=m){
        cout << ff << endl;
    }
    return 0;
}