#ifndef __ENGUNITS_ACCELERATION_CONVERSION_H
#define __ENGUNITS_ACCELERATION_CONVERSION_H

namespace engunits::conversion{
//Conversions have been aggregated here to make them easier to view and change

//conversions have been standardised to SI units: all values are conversion factors from MetersPerSecSQ (how many MetersPerSecSQ make up the unit)
constexpr double AC_METERS_PER_SECOND_SQ = 1;
constexpr double AC_MILE_PER_SECOND_SQ = 1609.26939169;
constexpr double AC_KILOMETERS_PER_SECOND_SQ = 1000;
constexpr double AC_MILLIMETER_PER_SECOND_SQ = 0.001;

} // namespace engunits::conversion

#endif