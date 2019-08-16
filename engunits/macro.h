#ifndef __ENGUNITS_ABSTRACT_MACRO_H
#define __ENGUNITS_ABSTRACT_MACRO_H

#include "../engunits/_abstract/abstract_base.h"

#define ADD_ABSTRACT_UNIT_TYPE(abstract_unit_name, si_unit_name)\
namespace engunits::abstract_unit_name{\
class si_unit_name;\
\
template<typename Child=si_unit_name>\
class abstract_unit_name: public abstract::PhysicalUnit<abstract_unit_name, Child> {\
    protected:\
        using abstract::PhysicalUnit<abstract_unit_name, Child>::PhysicalUnit;\
\
    public:\
\
        constexpr abstract_unit_name<Child>(const abstract_unit_name<Child> &other) : abstract::PhysicalUnit<abstract_unit_name, Child>{other.val} {};\
        constexpr abstract_unit_name<Child>(abstract_unit_name<Child> &&other) : abstract::PhysicalUnit<abstract_unit_name, Child>{other.val} {};\
        template <typename T>\
        constexpr abstract_unit_name<Child>(const abstract_unit_name<T> &other) : abstract::PhysicalUnit<abstract_unit_name, Child>{(convert<Child>(other))} {};\
        template<typename T>\
        constexpr abstract_unit_name<Child>(abstract_unit_name<T> &&other) : abstract::PhysicalUnit<abstract_unit_name, Child>{(convert<Child>(other))} {};\
\
        virtual const std::string symbol() const = 0;\
\
        Child &operator=(double value) {this->val=value; return *static_cast<Child*>(this);}\
        Child &operator=(const abstract_unit_name<Child> &other) { this->val = other.val; return *static_cast<Child*>(this);}\
        Child &operator=(abstract_unit_name<Child> &&other) { this->val = other.val; return *static_cast<Child*>(this);}     \
        template<typename T> \
        Child &operator=(const abstract_unit_name<T> &other) { this->val = other.val; return *static_cast<Child*>(this);}\
        template<typename T> \
        Child &operator=(abstract_unit_name<T> &&other) { this->val = other.val; return *static_cast<Child*>(this);}\
        \
};\
}\

#endif