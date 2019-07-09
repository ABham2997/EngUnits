#ifndef __ENGUNITS_DATA_STORAGE_CONVERSION_H
#define __ENGUNITS_DATA_STORAGE_CONVERSION_H

namespace engunits::conversion{
//Conversions have been aggregated here to make them easier to view and change

//conversions have been standardised to SI units: all values are conversion factors from bit (how many bits make up the unit)
constexpr double DS_BITS = 1;
constexpr double DS_KILOBITS = 0.0009765625;
constexpr double DS_MEGABITS = 9.5367431640625e-07;
constexpr double DS_GIGABITS = 9.313225746154785e-10;
constexpr double DS_TERABITS = 9.094947017729282e-13;
constexpr double DS_PETABITS = 8.881784197001252e-16;
constexpr double DS_EXABITS = 8.673617379884035e-19;
constexpr double DS_ZETTABITS = 8.470329472543003e-22;
constexpr double DS_YOTTABITS = 8.271806125530277e-25;
constexpr double DS_BYTES = 0.125;
constexpr double DS_KILOBYTES = 0.0009765625;
constexpr double DS_MEGABYTES = 9.5367431640625e-07;
constexpr double DS_GIGABYTES = 9.313225746154785e-10;
constexpr double DS_TERABYTES = 9.094947017729282e-13;
constexpr double DS_PETABYTES = 8.881784197001252e-16;
constexpr double DS_EXABYTES = 8.673617379884035e-19;
constexpr double DS_ZETTABYTES = 8.470329472543003e-22;
constexpr double DS_YOTTABYTES = 8.271806125530277e-25;

} // namespace engunits::conversion

#endif