#include<iostream>
#include<map>
#include<string>
#include<cassert>
#include<sstream>

#include <engunits/distance.h>

void print_bool (bool b){
    std::cout<< (b ? "true" : "false") << std::endl;
}

void almost_equal(double self, double other) {
    if (self==0 || other==0) {
        assert(self==other);
        return;
    }
    assert(self * 0.99 < other && other < self * 1.01);
}

int main() {
    using namespace engunits::distance;
    using namespace std;

    cout << "---Testing Constructors---" << endl;
    cout << "Default Constructor: ";
    meters defcon;
    feet defcon2;
    almost_equal(defcon.scalar(),0);
    almost_equal(defcon2.scalar(),0);
    almost_equal(defcon2.si_val(),0);
    cout << "success" << endl;
    meters stcon{5};
    cout << "Standard Constructor: ";
    almost_equal(stcon.scalar(),5);
    almost_equal(stcon.si_val(),5);
    feet stcon2{5555555555555555};
    almost_equal(stcon2.scalar(),5555555555555555);
    almost_equal(stcon2.si_val(),1693333333333333.25);
    feet stcon3{0.5};
    almost_equal(stcon3.si_val(),0.1524);
    cout << "success" << endl;
    cout << "Copy Constructor : ";
    meters cpy{50};
    feet cpy2{1234};
    inches cpy3{13.32443};
    inches cpy4{12};
    meters cpcon{cpy};
    feet cpcon2{cpy2};
    inches cpcon3{cpy};
    feet cpcon4{cpy3};
    meters cpcon5{cpy2};
    inches cpcon6{cpy2};
    feet cpcon7{cpy4};
    almost_equal(cpcon.scalar(),50);
    almost_equal(cpcon.si_val(),50);
    almost_equal(cpcon2.si_val(),376.1232);
    almost_equal(cpcon3.si_val(),50);
    almost_equal(cpcon3.scalar(),1968.503937);
    almost_equal(cpcon4.scalar(),1.1103691);
    almost_equal(cpcon4.si_val(),0.3384405);
    almost_equal(cpcon5.scalar(),376.1232);
    almost_equal(cpcon6.si_val(),376.1232);
    almost_equal(cpcon7.scalar(),0.9999999);
    cout << "success" << endl;
    cout << endl;

    cout << "---Testing Assignment---" << endl;
    cout << "Assignment: ";
    meters as;
    as = 234;
    feet as2{41332};
    as2 = 41723;
    inches as3{as2};
    as3 = 12;
    as3 = 45.67;
    almost_equal(as.scalar(),234);
    almost_equal(as2.scalar(),41723);
    almost_equal(as3.scalar(),45.67);
    cout << "success" << endl;
    cout << "Copy Assignment: ";
    meters cp{50};
    feet cp2{1234};
    inches cp3{13.32443};
    inches cp4{12};
    meters cpas=cp;
    feet cpas2{cp};
    cpas2 = cp2;
    inches cpas3 = cp;
    feet cpas4;
    cpas4 = cp3;
    meters cpas5{50};
    cpas5 = cp2;
    inches cpas6 = cp2;
    feet cpas7=cp4;
    almost_equal(cpas.scalar(),50);
    almost_equal(cpas.si_val(),50);
    almost_equal(cpas2.si_val(),376.1232);
    almost_equal(cpas3.si_val(),50);
    almost_equal(cpas3.scalar(),1968.50393);
    almost_equal(cpas4.scalar(),1.110369166);
    almost_equal(cpas4.si_val(),0.338440991);
    almost_equal(cpas5.scalar(),376.1232);
    almost_equal(cpas6.si_val(),376.1232);
    almost_equal(cpas7.scalar(),0.9999999);
    cout << "success" << endl;
    cout << "Assignment Chaining: ";
    meters asch1{123.456};
    meters asch2;
    meters asch3;
    asch3 = asch2 = asch1;
    assert(asch1.scalar()==asch2.scalar() && asch2.scalar()==asch3.scalar() && asch1.scalar()==asch3.scalar());
    cout << "success" << '\n';
    cout << endl;

    cout << endl;
    cout << "All Tests Successfully Completed" << endl;

    return 0;
}