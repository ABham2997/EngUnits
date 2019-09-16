#include<iostream>
#include<sstream>
#include<cassert>

#include <engunits/distance.h>

int main () {
    using namespace engunits::distance;
    using namespace std;
    cout << "---Testing Misc---" << endl;
    cout << "cout: ";
    ostringstream oss;
    meters co1{50};
    feet co2{100.5};
    inches co3{231323.126878};
    oss << co1;
    assert(oss.str() == "50 m");
    ostringstream oss2;
    oss2 << co2;
    assert(oss2.str() == "100.5 ft");
    ostringstream oss3;
    oss3 << co3;
    assert(oss3.str() == "231323.126878 in");
    cout << "success" << endl;

    return 0;
}