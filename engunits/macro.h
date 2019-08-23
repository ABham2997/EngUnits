#ifndef __ENGUNITS_ABSTRACT_MACRO_H
#define __ENGUNITS_ABSTRACT_MACRO_H

#include "../engunits/_abstract/abstract_base.h"

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
        Child &operator=(const double &value) {this->val=value; return *static_cast<Child*>(this);}\
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
};\

#endif