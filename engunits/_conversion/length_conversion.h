#ifndef __ENGUNITS_LENGTH_CONVERSION_H
#define __ENGUNITS_LENGTH_CONVERSION_H

namespace EngUnits::conversion{
//Conversions have been aggregated here to make them easier to view and change

//conversions have been standardised to SI units: all values are conversion factors from meters (how many meters make up the unit)
constexpr double L_METERS = 1;
constexpr double L_DECIMETERS = 10;
constexpr double L_KILOMETERS = 1000;
constexpr double L_CENTIMETERS = 1e-2;
constexpr double L_MILIMETERS = 1e-3;
constexpr double L_MICROMETERS = 1e-6;
constexpr double L_NANOMETERS = 1e-9;
constexpr double L_MILES = 1609.344;
constexpr double L_YARDS = 0.9144;
constexpr double L_FEET = 0.3048;
constexpr double L_INCHES = 0.0254;
constexpr double L_LIGHT_YEARS = 9.46073047258e+15;
constexpr double L_EXAMETERS = 1e+18;
constexpr double L_PETAMETERS = 1e+15;
constexpr double L_NAUTICAL_MILE = 1852;

} // namespace EngUnits::conversion

#endif