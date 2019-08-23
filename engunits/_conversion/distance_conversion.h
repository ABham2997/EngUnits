#ifndef __ENGUNITS_DISTANCE_CONVERSION_H
#define __ENGUNITS_DISTANCE_CONVERSION_H

namespace engunits::conversion{
//Conversions have been aggregated here to make them easier to view and change

//conversions have been standardised to SI units: all values are conversion factors from meters (how many meters make up the unit)
constexpr double D_METERS = 1;
constexpr double D_DECIMETERS = 10;
constexpr double D_KILOMETERS = 1000;
constexpr double D_CENTIMETERS = 1e-2;
constexpr double D_MILIMETERS = 1e-3;
constexpr double D_MICROMETERS = 1e-6;
constexpr double D_NANOMETERS = 1e-9;
constexpr double D_MILES = 1609.344;
constexpr double D_YARDS = 0.9144;
constexpr double D_FEET = 0.3048;
constexpr double D_INCHES = 0.0254;
constexpr double D_LIGHT_YEARS = 9.46073047258e+15;
constexpr double D_EXAMETERS = 1e+18;
constexpr double D_PETAMETERS = 1e+15;
constexpr double D_NAUTICAL_MILE = 1852;

} // namespace engunits::conversion

#endif