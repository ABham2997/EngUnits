#ifndef __ENGUNITS_TEMPERATURE_CONVERSION_H
#define __ENGUNITS_TEMPERATURE_CONVERSION_H

namespace engunits::conversion{
//Conversions have been aggregated here to make them easier to view and change

//conversions have been standardised to SI units: all values are conversion factors from Kelvin(how many Kelvin make up the unit)
constexpr double T_KELVIN = 1;
constexpr double T_CELSIUS = 274.15;
constexpr double T_FAHRENHEIT = 255.928;

} // namespace engunits::conversion

#endif