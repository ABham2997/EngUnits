#ifndef __ENGUNITS_FUEL_ECONOMY_CONVERSION_H
#define __ENGUNITS_FUEL_ECONOMY_CONVERSION_H

namespace engunits::conversion{
//Conversions have been aggregated here to make them easier to view and change

//conversions have been standardised to SI units: all values are conversion factors from kilometer per litre(how many kilometer per litre make up the unit)
constexpr double FE_KILOMETERSPERLITRE = 1;
constexpr double FE_USMILESPERGALLON = 0.425144;
constexpr double FE_IMPERIALMILESPERGALLON = 0.354006;

} // namespace engunits::conversion

#endif