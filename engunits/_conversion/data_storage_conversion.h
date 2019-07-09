#ifndef __ENGUNITS_DATA_STORAGE_CONVERSION_H
#define __ENGUNITS_DATA_STORAGE_CONVERSION_H

namespace engunits::conversion{
//Conversions have been aggregated here to make them easier to view and change

//conversions have been standardised to SI units: all values are conversion factors from bit (how many bits make up the unit)
constexpr double DS_BITS = 1;
constexpr double DS_KILOBITS = 1024;
constexpr double DS_MEGABITS = 1048576;
constexpr double DS_GIGABITS = 1073741824;
constexpr double DS_TERABITS = 1099511627776;
constexpr double DS_PETABITS = 1125899906842624;
constexpr double DS_EXABITS = 1.152921504606847e+18;
constexpr double DS_ZETTABITS = 1.1805916207174113e+21;
constexpr double DS_YOTTABITS = 1.2089258196146292e+24;
constexpr double DS_BYTES = 8;
constexpr double DS_KILOBYTES = 8000;
constexpr double DS_MEGABYTES = 8e+6;
constexpr double DS_GIGABYTES = 8e+9;
constexpr double DS_TERABYTES = 8e+12;
constexpr double DS_PETABYTES = 8e+15;
constexpr double DS_EXABYTES = 8e+18;
constexpr double DS_ZETTABYTES = 8e+21;
constexpr double DS_YOTTABYTES = 8e+24;

} // namespace engunits::conversion

#endif