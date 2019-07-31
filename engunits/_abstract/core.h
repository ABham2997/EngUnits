#ifndef __ENGUNITS_CORE_H
#define __ENGUNITS_CORE_H

#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

//this namespace is for misc functions which should always be available
namespace engunits{

template <template<typename> typename C, typename G>
using PhysicalUnit = typename abstract::PhysicalUnit<C, G>;

template<typename Unit, typename=std::enable_if_t<std::is_constructible<Unit, double>::value>>
Unit make_unit(long double value){
    return Unit{value};
}

template<typename To, typename From, template<typename> typename C>
constexpr To convert(const PhysicalUnit<C,From> &other){
    return other.scalar() * (From::conversion / To::conversion);
}

template<typename From, typename To, typename Other, typename=std::enable_if_t<std::is_arithmetic<Other>::value>>
constexpr Other convert(Other other) {
    return other * (From::conversion / To::conversion);
}

}//namespace engunits
#endif