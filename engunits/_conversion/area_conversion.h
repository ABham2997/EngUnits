#ifndef __ENGUNITS_AREA_CONVERSION_H
#define __ENGUNITS_AREA_CONVERSION_H

namespace engunits::conversion{
//Conversions have been aggregated here to make them easier to view and change

//conversions have been standardised to SI units: all values are conversion factors from square meters (how many square meters make up the unit)
constexpr double A_SQMETERS = 1;
constexpr double A_SQKILOMETERS = 1e+6;
constexpr double A_SQMILES = 2.59e+6;
constexpr double A_SQYARD = 0.836127;
constexpr double A_SQFOOT = 0.092903;
constexpr double A_SQINCH = 0.00064516;
constexpr double A_SQHECTARE = 10000;
constexpr double A_ACRE = 4046.86;

} // namespace engunits::conversion

#endif