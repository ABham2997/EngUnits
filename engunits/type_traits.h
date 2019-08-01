#ifndef __ENGUNITS_TYPE_TRAITS_H
#define __ENGUNITS_TYPE_TRAITS_H

namespace engunits::abstract{
template <template <typename> typename C, typename G>
class PhysicalUnit;//forward declaration
}//namespace engunits::abstract

namespace engunits::traits{

template <template<typename> typename C, typename G>
using PhysicalUnit = typename abstract::PhysicalUnit<C, G>;

template <typename T, template <typename> typename C>
using is_unit_of_type = std::is_base_of<C<T>, T>;

template <typename T, template <typename> typename C>
using is_unit_of_type_t = typename is_unit_of_type<T, C>::type;

template <typename T, template <typename> typename C>
constexpr bool is_unit_of_type_v = is_unit_of_type<T, C>::value;

template<typename Derived>
struct is_unit{
    template <template<typename> typename C, typename T>
    static constexpr std::true_type check(const PhysicalUnit<C,T> *);
    static constexpr std::false_type check(...);
    using type = decltype(check(std::declval<Derived *>()));
    static constexpr bool value = type::value;
};

template <typename T>
using is_unit_t = typename is_unit<T>::type;

template <typename T>
constexpr bool is_unit_v = is_unit<T>::value;

}//namespace traits

#endif