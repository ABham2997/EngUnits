#ifndef __ENGUNITS_DATA_STORAGE_CONVERSION_H
#define __ENGUNITS_DATA_STORAGE_CONVERSION_H

namespace engunits::conversion{
//Conversions have been aggregated here to make them easier to view and change

//conversions have been standardised to SI units: all values are conversion factors from square meters (how many square meters make up the unit)
constexpr double DS_BIT = 1;
constexpr double DS_KILOBIT = 0.0009765625;
constexpr double DS_MEGABIT = 9.5367431640625e-07;
constexpr double DS_GIGABIT = 9.313225746154785e-10;
constexpr double DS_TERABIT = 9.094947017729282e-13;
constexpr double DS_PETABIT = 8.881784197001252e-16;
constexpr double DS_EXABIT = 8.673617379884035e-19;
constexpr double DS_ZETTABIT = 8.470329472543003e-22;
constexpr double DS_YOTTABIT = 8.271806125530277e-25;
constexpr double DS_BYTE = 0.125;
constexpr double DS_KILOBYTE = 0.0009765625;
constexpr double DS_MEGABYTE = 9.5367431640625e-07;
constexpr double DS_GIGABYTE = 9.313225746154785e-10;
constexpr double DS_TERABYTE = 9.094947017729282e-13;
constexpr double DS_PETABYTE = 8.881784197001252e-16;
constexpr double DS_EXABYTE = 8.673617379884035e-19;
constexpr double DS_ZETTABYTE = 8.470329472543003e-22;
constexpr double DS_YOTTABYTE = 8.271806125530277e-25;

} // namespace engunits::conversion

#endif