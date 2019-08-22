#ifndef __ENGUNITS_ABSTRACT_ANGLE_H
#define __ENGUNITS_ABSTRACT_ANGLE_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::angle{
class radians; //forward declaration

//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child=radians> //TODO: constrain to children of this class
class AngleUnit: public abstract::PhysicalUnit<AngleUnit, Child> {
    protected:
        using abstract::PhysicalUnit<AngleUnit, Child>::PhysicalUnit;

    public:
        using si_t = radians;

        constexpr AngleUnit<Child>(const AngleUnit<Child> &other) : abstract::PhysicalUnit<AngleUnit, Child>{other.val} {};
        constexpr AngleUnit<Child>(AngleUnit<Child> &&other) : abstract::PhysicalUnit<AngleUnit, Child>{other.val} {};
        template <typename T>
        constexpr AngleUnit<Child>(const AngleUnit<T> &other) : abstract::PhysicalUnit<AngleUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        constexpr AngleUnit<Child>(AngleUnit<T> &&other) : abstract::PhysicalUnit<AngleUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        Child &operator=(const double &value) {this->val=value; return *static_cast<Child*>(this);}
        Child &operator=(const AngleUnit<Child> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        Child &operator=(AngleUnit<Child> &&other) { this->val = other.val; return *static_cast<Child*>(this);}  
        
};

}

#endif