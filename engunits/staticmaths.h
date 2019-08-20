#ifndef __ENGUNITS_ENGMATHS_H
#define __ENGUNITS_ENGMATHS_H

#include<cmath>

#include "../engunits/_abstract/coremaths.h"

namespace engunits::maths{

constexpr double sqrt(const double &value) { //Newton-Raphson iterative
    if (value<0 || value > std::numeric_limits<double>::infinity()){
        return 0;
    }
    double x1 = 1 + value * (0.18 + 0.009 * value);
    double x0=0;
    while(x1!=x0) {//iterate until conversion
        x0 = x1;
        x1 = 0.5*(x0 + (value/x0));
    }
    return x1;  
}

double cos(const double &value) { return std::cos(value); }
double sin(const double &value) { return std::sin(value); }
double tan(const double &value) { return std::tan(value); }
double acos(const double &value) { return std::acos(value); }
double asin(const double &value) { return std::asin(value); }
double atan(const double &value) { return std::atan(value); }
double cosh(const double &value) { return std::cosh(value); }
double sinh(const double &value) { return std::sinh(value); }
double tanh(const double &value) { return std::tanh(value); }
double acosh(const double &value) { return std::acosh(value); }
double asinh(const double &value) { return std::asinh(value); }
double atanh(const double &value) { return std::atanh(value); }
}

#endif