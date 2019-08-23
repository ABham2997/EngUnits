#ifndef __ENGUNITS_MATHS_H
#define __ENGUNITS_MATHS_H

#include <cmath>
#include<type_traits>
#include<limits>

#include "../engunits/maths/pow.h"
#include "../engunits/maths/sqrt.h"
#include "../engunits/maths/fraction.h"
#include "../engunits/distance.h"
#include "../engunits/mass.h"
#include "../engunits/constants.h"
#include "../engunits/force.h"

namespace engunits::maths{

//enable this function if arg has member "scalar" that returns an arithmetic value
template<typename T, typename=std::enable_if_t<std::is_arithmetic_v<decltype(std::declval<T>().scalar())>>>
constexpr double sqrt(const T& unit) {
    return sqrt(unit.scalar());
}

//enable this function if arg has member "scalar" that returns an arithmetic value and exp arg is arithmetic type
template<typename T, typename V,
    typename=std::enable_if_t<std::is_arithmetic_v<decltype(std::declval<T>().scalar())>&&std::is_arithmetic_v<V>>>
constexpr double pow(const T& unit, const V& exp) {
    return pow(unit.scalar(), exp);
}

constexpr inline force::Newtons calculate_fgrav(const mass::kilograms& mass1, const mass::kilograms& mass2, 
    const distance::meters& radius){
        return (constant::G * mass1.scalar() * mass2.scalar() / (radius.scalar() * radius.scalar()));
}

} // namespace engunits::maths

#endif