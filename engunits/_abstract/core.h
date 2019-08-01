#ifndef __ENGUNITS_CORE_H
#define __ENGUNITS_CORE_H

#include<type_traits>

#include "../../engunits/type_traits.h"

//this namespace is for misc functions which should always be available
namespace engunits{

namespace abstract{
template <template <typename> typename C, typename G>
class PhysicalUnit; //forward declaration
}//namespace engunits::abstract

template <template<typename> typename C, typename G>
using PhysicalUnit = typename abstract::PhysicalUnit<C, G>;

template<typename To, typename From, template<typename> typename C>
constexpr To convert(const PhysicalUnit<C,From> &other){
    return other.scalar() * (From::conversion / To::conversion);
}

template<typename From, typename To, typename Other, typename=std::enable_if_t<std::is_arithmetic<Other>::value>>
constexpr Other convert(Other other) {
    return other * (From::conversion / To::conversion);
}

template<typename Unit, typename Value,
    typename=std::enable_if_t<traits::is_unit_v<Unit>&&std::is_arithmetic<Value>::value>>
Unit make_unit(Value value){
    return Unit(value);
}

}//namespace engunits
#endif