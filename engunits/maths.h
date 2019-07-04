#ifndef __ENGUNITS_MATHS_H
#define __ENGUNITS_MATHS_H

#include <cmath>

#include "../engunits/conversion/conversion_funcs.h"
#include "../engunits/abstract/abstract_base.h"

namespace EngUnits::maths{

double cos(const double value) { return std::cos(value); }
double sin(const double value) { return std::sin(value); }
double tan(const double value) { return std::tan(value); }
template <typename S, typename T, typename G>
double cos(const abstract::PhysicalUnit<S, T, G> unit) { return std::cos(conversion::double_cast(unit)); }
template <typename S, typename T, typename G>
double sin(const abstract::PhysicalUnit<S, T, G> unit) { return std::sin(conversion::double_cast(unit)); }
template <typename S, typename T, typename G>
double tan(const abstract::PhysicalUnit<S, T, G> unit) { return std::tan(conversion::double_cast(unit)); }

} // namespace EngUnits::maths

#endif