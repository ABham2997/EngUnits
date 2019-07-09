#ifndef __ENGUNITS_DATA_TRANSFER_CONVERSION_H
#define __ENGUNITS_DATA_TRANSFER_CONVERSION_H

namespace engunits::conversion{
//Conversions have been aggregated here to make them easier to view and change

//conversions have been standardised to SI units: all values are conversion factors from bits (how many bits make up the unit)
constexpr double DTR_BITS = 1;
constexpr double DTR_KILOBITS = 1024.0;
constexpr double DTR_MEGABITS = 1048576.0;
constexpr double DTR_GIGABITS = 1073741823.9999983;
constexpr double DTR_BYTES = 8.0;
constexpr double DTR_KILOBYTES = 8192.0;
constexpr double DTR_MEGABYTES = 8388608.000000088;
constexpr double DTR_GIGABYTES = 8589934592.000357;

} // namespace engunits::conversion

#endif