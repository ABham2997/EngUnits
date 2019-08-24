#ifndef __ENGUNITS_CONSTANTS_H
#define __ENGUNITS_CONSTANTS_H

#include "../engunits/si_units.h"

namespace engunits::constant{

    constexpr double e = 2.71828182846;
    constexpr double pi = 3.14159265359;
    constexpr acceleration::meters_per_second_sq g = -9.87;
    constexpr double G = 6.672e-11;
    constexpr distance::meters AU = 149597870700;

} // namespace engunits::const

#endif