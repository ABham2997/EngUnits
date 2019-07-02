#ifndef __ENGUNITS_CONVERSION_H
#define __ENGUNITS_CONVERSION_H

namespace EngUnits::length::conversion{

//conversions have been standardised to SI units: all values are conversion factors from meters
constexpr double METERS = 1;
constexpr double DECIMETERS = 10;
constexpr double KILOMETERS = 1000;
constexpr double CENTIMETERS = 1e-2;
constexpr double MILIMETERS = 1e-3;
constexpr double MICROMETERS = 1e-6;
constexpr double NANOMETERS = 1e-9;
constexpr double MILES = 1609.344;
constexpr double YARDS = 0.9144;
constexpr double FEET = 0.3048;
constexpr double INCHES = 0.0254;
constexpr double LIGHT_YEARS = 9.46073047258e+15;
constexpr double EXAMETERS = 1e+18;
constexpr double PETAMETERS = 1e+15;
constexpr double NAUTICAL_MILE = 1852;

} // namespace EngUnits::length::conversion

#endif