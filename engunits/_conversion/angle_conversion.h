#ifndef __ENGUNITS_ANGLE_CONVERSION_H
#define __ENGUNITS_ANGLE_CONVERSION_H

namespace engunits::conversion{
//Conversions have been aggregated here to make them easier to view and change

//conversions have been standardised to SI units: all values are conversion factors from radians(how many radians make up the unit)
constexpr double AN_RADIANS = 1;
constexpr double AN_DEGREES = 0.0174533;
constexpr double AN_MILLIRADIAN = 0.001;
constexpr double AN_GRADIAN = 0.015708;
constexpr double AN_MINUTEOFARC = 0.000290888;
constexpr double AN_SECONDOFARC = 4.8481e-6;

} // namespace engunits::conversion

#endif