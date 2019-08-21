#ifndef ENGUNITS_MATHS_SQRT_H
#define ENGUNITS_MATHS_SQRT_H

#include<limits>

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

}

#endif