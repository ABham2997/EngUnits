#ifndef __ENGUNITS_SPEED_CONVERSION_H
#define __ENGUNITS_SPEED_CONVERSION_H

namespace engunits::conversion{
//Conversions have been aggregated here to make them easier to view and change

//conversions have been standardised to SI units: all values are conversion factors from meters per second (how many meters per second make up the unit)
constexpr double S_METERSPERSECOND = 1;
constexpr double S_FOOTPERHOUR = 8.466667e-05;
constexpr double S_FOOTPERMINUTE = 0.00508;
constexpr double S_FOOTPERSECOND = 0.3048;
constexpr double S_FURLONGPERHOUR = 0.05588;
constexpr double S_FURLONGPERMINUTE = 3.3528;
constexpr double S_FURLONGPERSECOND = 201.168;
constexpr double S_INCHPERHOUR = 7.055556e-06;
constexpr double S_INCHPERMINUTE = 0.0004233333;
constexpr double S_INCHPERSECOND = 0.0254;
constexpr double S_KNOT = 0.514444444444444;
constexpr double S_MACH = 331.0;
constexpr double S_METERPERHOUR = 0.0002777778;
constexpr double S_METERPERMINUTE = 0.0166666666666667;
constexpr double S_METERPERSECOND = 1.0;
constexpr double S_CENTIMETERPERMILLISECOND = 10.0;
constexpr double S_CENTIMETERPERSECOND = 0.01;
constexpr double S_METERPERMILLISECOND = 1000.0;
constexpr double S_KILOMETERPERMILLISECOND = 1000000.0;
constexpr double S_KILOMETERPERSECOND = 1000.0;
constexpr double S_MILEPERHOUR = 0.44704;
constexpr double S_MILEPERMINUTE = 26.8224;
constexpr double S_MILEPERSECOND = 1609.344;
constexpr double S_YARDPERHOUR = 0.000254;
constexpr double S_YARDPERMINUTE = 0.01524;
constexpr double S_YARDPERSECOND = 0.9144;

} // namespace engunits::conversion

#endif