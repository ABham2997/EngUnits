#ifndef __ENGUNITS_FREQUENCY_CONVERSION_H
#define __ENGUNITS_FREQUENCY_CONVERSION_H

namespace engunits::conversion{
//Conversions have been aggregated here to make them easier to view and change

//conversions have been standardised to SI units: all values are conversion factors from Herts (how many Herts make up the unit)
constexpr double F_HERTS = 1;
constexpr double F_KILOHERTS = 1000;
constexpr double F_MEGAHERTS = 1e+6;
constexpr double F_GIGAHERTS = 1e+9;

} // namespace engunits::conversion

#endif