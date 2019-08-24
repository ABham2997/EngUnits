#ifndef __ENGUNITS_ABSTRACT_MACRO_H
#define __ENGUNITS_ABSTRACT_MACRO_H

#include "../../engunits/_abstract/abstract_base.h"

#define ADD_ABSTRACT_UNIT_TYPE(abstract_unit_name, si_unit_name, si_unit_symbol)\
class si_unit_name;\
\
template<typename Child=si_unit_name>\
class abstract_unit_name: public engunits::abstract::PhysicalUnit<abstract_unit_name, Child> {\
    template<template<typename> typename C, typename G>\
    using PhysUnit = typename engunits::abstract::PhysicalUnit<C,G>;\
    protected:\
        using abstract::PhysicalUnit<abstract_unit_name, Child>::PhysicalUnit;\
\
    public:\
        using si_t=si_unit_name;\
\
        constexpr abstract_unit_name<Child>(const abstract_unit_name<Child> &other) : PhysUnit<abstract_unit_name, Child>{other.val} {};\
        constexpr abstract_unit_name<Child>(abstract_unit_name<Child> &&other) : PhysUnit<abstract_unit_name, Child>{other.val} {};\
        template <typename T>\
        constexpr abstract_unit_name<Child>(const abstract_unit_name<T> &other) : PhysUnit<abstract_unit_name, Child>{(convert<Child>(other))} {};\
        template<typename T>\
        constexpr abstract_unit_name<Child>(abstract_unit_name<T> &&other) : PhysUnit<abstract_unit_name, Child>{(convert<Child>(other))} {};\
\
        virtual const std::string symbol() const = 0;\
\
        Child &operator=(const abstract_unit_name<Child> &other) { this->val = other.val; return *static_cast<Child*>(this);}\
        Child &operator=(abstract_unit_name<Child> &&other) { this->val = other.val; return *static_cast<Child*>(this);}     \
        \
};\
\
class si_unit_name : public abstract_unit_name<si_unit_name> {\
    public:\
        using abstract_unit_name<si_unit_name>::abstract_unit_name;\
\
        static constexpr double conversion = 1;\
\
        const std::string symbol() const override { return #si_unit_symbol; }\
};

#define ADD_LITERALS(namespace, unit, symbol)                                               \
        constexpr namespace ::unit operator""_##symbol(long double value) { return value; } \
        constexpr namespace ::unit operator""_##symbol(unsigned long long value) { return value; }

#define ADD_TRI_OPERATORS(Unit1, Unit2, Unit3)                                                                           \
        constexpr Unit1 operator*(const Unit2 &unit2, const Unit3 &unit3) { return unit2.scalar() * unit3.scalar(); } \
        constexpr Unit1 operator*(const Unit3 &unit3, const Unit2 &unit2) { return unit3.scalar() * unit2.scalar(); }  \
        constexpr Unit2 operator/(const Unit1 &unit1, const Unit3 &unit3) { return unit1.scalar() / unit3.scalar(); }  \
        constexpr Unit3 operator/(const Unit1 &unit1, const Unit2 &unit2) { return unit1.scalar() / unit2.scalar(); }

#define ADD_SQ_OPERATORS(Unit_to_sq, Res_unit)                                                                                     \
        constexpr Res_unit operator*(const Unit_to_sq &unit1, const Unit_to_sq &unit2) { return unit1.scalar() * unit2.scalar(); } \
        constexpr Unit_to_sq operator/(const Res_unit &unit1, const Unit_to_sq &unit2) { return unit1.scalar() / unit2.scalar(); }

#define ADD_RECIPROCAL_OPERATORS(Unit_to_inv, Res_unit) \
        constexpr Res_unit operator/(const double &value, const Unit_to_inv &unit) { return value / unit.scalar(); }\
        constexpr Unit_to_inv operator/(const double &value, const Res_unit &unit) { return value / unit.scalar();}

#define ADD_MULT_ONLY_OPERATOR(Unit1, Unit2, Unit3)                                                                   \
        constexpr Unit1 operator*(const Unit2 &unit2, const Unit3 &unit3) { return unit2.scalar() * unit3.scalar(); } \
        constexpr Unit1 operator*(const Unit3 &unit3, const Unit2 &unit2) { return unit2.scalar() * unit3.scalar(); }

#endif