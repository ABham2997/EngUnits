#ifndef __ENGUNITS_COREMATHS_H
#define __ENGUNITS_COREMATHS_H

#include<cmath>

namespace engunits::maths{

template<typename T=double> constexpr T pow(const double &value, const double &exp) {
    switch (exp){
    case -1: return 1 / value;
    case 0: return 1;
    case 1: return value; }
    if (exp>1) return value * pow(value, exp-1);
    else return 1/(pow(value, -exp));
}

template<typename T=double> constexpr T pow(const double &value, const int &exp) {
    switch (exp){
    case -1: return 1 / value;
    case 0: return 1;
    case 1: return value; }
    if (exp>1) return value * pow(value, exp-1);
    else return 1/(pow(value, -exp));
}

}

#endif