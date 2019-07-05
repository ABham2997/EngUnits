#ifndef __ENGUNITS_MASS_CONVERSION_H
#define __ENGUNITS_MASS_CONVERSION_H

namespace engunits::conversion{
//Conversions have been aggregated here to make them easier to view and change

//conversions have been standardised to SI units: all values are conversion factors from kilograms (how many kilograms make up the unit)
constexpr double M_KILOGRAMS = 1;
constexpr double M_GRAMS = 1e-3;
constexpr double M_TONNES = 1000;
constexpr double M_MILLIGRAMS = 1e-6;
constexpr double M_MICROGRAMS = 1e-9;
constexpr double M_IMPERIAL_TONS = 1.01605e+3;
constexpr double M_US_TONS = 9.07185e+2;
constexpr double M_STONES = 6.35029;
constexpr double M_POUNDS = 0.453592;
constexpr double M_OUNCES = 0.0283495;

} // namespace engunits::conversion

#endif