#include<iostream>
#include<map>
#include<string>
#include<cassert>
#include<sstream>

#include "../engunits/length.h"

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
    using namespace engunits::length;
    using namespace std;

    cout << "---Testing Constructors---" << endl;
    cout << "Default Constructor: ";
    meters defcon;
    feet defcon2;
    almost_equal(defcon.abs_val(),0);
    almost_equal(defcon2.abs_val(),0);
    almost_equal(defcon2.SI_val(),0);
    cout << "success" << endl;
    meters stcon{5};
    cout << "Standard Constructor: ";
    almost_equal(stcon.abs_val(),5);
    almost_equal(stcon.SI_val(),5);
    feet stcon2{5555555555555555};
    almost_equal(stcon2.abs_val(),5555555555555555);
    almost_equal(stcon2.SI_val(),1693333333333333.25);
    feet stcon3{0.5};
    almost_equal(stcon3.SI_val(),0.1524);
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
    almost_equal(cpcon.abs_val(),50);
    almost_equal(cpcon.SI_val(),50);
    almost_equal(cpcon2.SI_val(),376.1232);
    almost_equal(cpcon3.SI_val(),50);
    almost_equal(cpcon3.abs_val(),1968.503937);
    almost_equal(cpcon4.abs_val(),1.1103691);
    almost_equal(cpcon4.SI_val(),0.3384405);
    almost_equal(cpcon5.abs_val(),376.1232);
    almost_equal(cpcon6.SI_val(),376.1232);
    almost_equal(cpcon7.abs_val(),0.9999999);
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
    almost_equal(as.abs_val(),234);
    almost_equal(as2.abs_val(),41723);
    almost_equal(as3.abs_val(),45.67);
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
    almost_equal(cpas.abs_val(),50);
    almost_equal(cpas.SI_val(),50);
    almost_equal(cpas2.SI_val(),376.1232);
    almost_equal(cpas3.SI_val(),50);
    almost_equal(cpas3.abs_val(),1968.50393);
    almost_equal(cpas4.abs_val(),1.110369166);
    almost_equal(cpas4.SI_val(),0.338440991);
    almost_equal(cpas5.abs_val(),376.1232);
    almost_equal(cpas6.SI_val(),376.1232);
    almost_equal(cpas7.abs_val(),0.9999999);
    cout << "success" << endl;
    cout << endl;

    cout << endl;
    cout << "All Tests Successfully Completed" << endl;

    return 0;
}