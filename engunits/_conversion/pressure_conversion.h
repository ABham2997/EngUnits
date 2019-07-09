#ifndef __ENGUNITS_PRESSURE_CONVERSION_H
#define __ENGUNITS_PRESSURE_CONVERSION_H

namespace engunits::conversion{
//Conversions have been aggregated here to make them easier to view and change

//conversions have been standardised to SI units: all values are conversion factors from Pascal(how many Pascals make up the unit)
constexpr double P_PASCAL = 1;
constexpr double P_BAR = 100000;
constexpr double P_ATMOSPHERE = 101325;
constexpr double P_POUNDFORCEPERSQINCH = 6894.76; //pound force per square inch
constexpr double P_TORR = 133.322;

} // namespace engunits::conversion

#endif