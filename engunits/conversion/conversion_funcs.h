#ifndef __ENGUNITS_CONVERSION_FUNCS_H
#define __ENGUNITS_CONVERSION_FUNCS_H

namespace EngUnits::conversion {

template<typename S>
double double_cast(S self) {
    return self.val;
}

template<typename S>
double SI_cast(S self) {
    return double_cast(self) * S::conversion;
}

template<typename O, typename S>
constexpr double unit_cast() {
    constexpr double convFactor = O::conversion / S::conversion;
    return convFactor;
}

template<typename O, typename S>
constexpr double unit_cast(S toConv) {
    return unit_cast<O, S>() * double_cast(toConv);
}

template<typename O, typename S, typename T>
constexpr double unit_cast(T toConv) {
    return unit_cast<O,S>()*double_cast(toConv);
}

}

#endif