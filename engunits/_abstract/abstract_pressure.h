#ifndef __ENGUNITS_ABSTRACT_PRESSURE_H
#define __ENGUNITS_ABSTRACT_PRESSURE_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::pressure{
class Pascals; //forward declaration

//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child=Pascals> //TODO: constrain to children of this class
class PressureUnit: public abstract::PhysicalUnit<PressureUnit, Child> {
    protected:
        using abstract::PhysicalUnit<PressureUnit, Child>::PhysicalUnit;

    public:
        using si_t = Pascals;

        constexpr PressureUnit<Child>(const PressureUnit<Child> &other) : abstract::PhysicalUnit<PressureUnit, Child>{other.val} {};
        constexpr PressureUnit<Child>(PressureUnit<Child> &&other) : abstract::PhysicalUnit<PressureUnit, Child>{other.val} {};
        template <typename T>
        constexpr PressureUnit<Child>(const PressureUnit<T> &other) : abstract::PhysicalUnit<PressureUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        constexpr PressureUnit<Child>(PressureUnit<T> &&other) : abstract::PhysicalUnit<PressureUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        Child &operator=(const double &value) {this->val=value; return *static_cast<Child*>(this);}
        Child &operator=(const PressureUnit<Child> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        Child &operator=(PressureUnit<Child> &&other) { this->val = other.val; return *static_cast<Child*>(this);}  
        
};

}

#endif