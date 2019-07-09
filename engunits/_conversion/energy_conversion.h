#ifndef __ENGUNITS_ENERGY_CONVERSION_H
#define __ENGUNITS_ENERGY_CONVERSION_H

namespace engunits::conversion{
//Conversions have been aggregated here to make them easier to view and change

//conversions have been standardised to SI units: all values are conversion factors from Joules (how many Joules make up the unit)
constexpr double E_JOULES = 1;
constexpr double E_KILOJOULES = 1000;
constexpr double E_GRAMCALORIES = 4.184;
constexpr double E_KILOCALORIES = 4184;
constexpr double E_WATTHOURS = 3600;
constexpr double E_KILOWATTHOURS = 3.6e+6;
constexpr double E_ELECTRONVOLTS = 1.6022e-19;
constexpr double E_BRITISHTHERMALUNITS = 1055.06;
constexpr double E_USTHERMALUNITS = 1.055e+8;
constexpr double E_FOOTPOUNDS = 1.35582;

} // namespace engunits::conversion

#endif