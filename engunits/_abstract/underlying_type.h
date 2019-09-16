#ifndef __ENGUNITS_UNDERLYING_TYPE_H
#define __ENGUNITS_UNDERLYING_TYPE_H

#include<type_traits>

namespace engunits::underlying{

#ifdef ENGUNITS_UNDERLYING_TYPE
    using __type = ENGUNITS_UNDERLYING_TYPE;
#else
    using __type = double;
#endif

template<typename T, typename=void>
struct ValType{};

template<typename T>
struct ValType<T, std::enable_if_t<std::is_arithmetic_v<T>>>{
    using type = T;
};

using type = ValType<__type>::type;

} // namespace engunits::underlying

#endif