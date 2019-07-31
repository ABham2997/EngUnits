#ifndef __ENGUNITS_TYPE_TRAITS_H
#define __ENGUNITS_TYPE_TRAITS_H

#include "../engunits/_abstract/abstract_base.h"

namespace engunits::traits{

template <template <typename> typename C, typename G>
using PhysicalUnit = typename engunits::abstract::PhysicalUnit<C, G>;

template <template<typename> typename C, typename T>
using is_unit = std::is_base_of<C, T>;

template <template<typename> typename C, typename T>
constexpr bool is_unit_v = is_unit<C, T>::value;

}//namespace traits

#endif