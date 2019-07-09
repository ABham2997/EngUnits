#ifndef __ENGUNITS_VOLUME_CONVERSION_H
#define __ENGUNITS_VOLUME_CONVERSION_H

namespace engunits::conversion{
//Conversions have been aggregated here to make them easier to view and change

//conversions have been standardised to SI units: all values are conversion factors from litres (how many litres make up the unit)
constexpr double V_LITRES = 1;
constexpr double V_CUBIC_KILOMETER = 1000000000000.0;
constexpr double V_CUBIC_METER = 1000.0;
constexpr double V_CUBIC_DECIMETER = 1.0;
constexpr double V_CUBIC_CENTIMETER = 0.001;
constexpr double V_CUBIC_MILLIMETER = 1e-06;
constexpr double V_HECTOLITER = 100.0;
constexpr double V_DECALITER = 10.0;
constexpr double V_DECILITER = 0.1;
constexpr double V_CENTILITER = 0.01;
constexpr double V_MILLILITER = 0.001;
constexpr double V_MICROLITER = 1e-06;
constexpr double V_GALLON = 4.405286343612334;
constexpr double V_QUART = 1.1012003083360864;
constexpr double V_PINT = 0.5506607929515418;

} // namespace engunits::conversion

#endif