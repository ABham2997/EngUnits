#ifndef __ENGUNITS_MATHS_H
#define __ENGUNITS_MATHS_H

#include <cmath>

#include "../engunits/_conversion/conversion_funcs.h"
#include "../engunits/_abstract/abstract_base.h"

namespace engunits::maths{

double cos(const double value) { return std::cos(value); }
double sin(const double value) { return std::sin(value); }
double tan(const double value) { return std::tan(value); }
double acos(const double value) { return std::acos(value); }
double asin(const double value) { return std::asin(value); }
double atan(const double value) { return std::atan(value); }
double cosh(const double value) { return std::cosh(value); }
double sinh(const double value) { return std::sinh(value); }
double tanh(const double value) { return std::tanh(value); }
double acosh(const double value) { return std::acosh(value); }
double asinh(const double value) { return std::asinh(value); }
double atanh(const double value) { return std::atanh(value); }


template <template<typename> typename S, typename T>
double cos(const abstract::PhysicalUnit<S, T> unit) { return std::cos(conversion::double_cast(unit)); }
template <template<typename> typename S, typename T>
double sin(const abstract::PhysicalUnit<S, T> unit) { return std::sin(conversion::double_cast(unit)); }
template <template<typename> typename S, typename T>
double tan(const abstract::PhysicalUnit<S, T> unit) { return std::tan(conversion::double_cast(unit)); }

} // namespace engunits::maths

#endif