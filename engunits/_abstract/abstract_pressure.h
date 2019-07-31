#ifndef __ENGUNITS_ABSTRACT_PRESSURE_H
#define __ENGUNITS_ABSTRACT_PRESSURE_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::pressure{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class PressureUnit: public abstract::PhysicalUnit<PressureUnit, Child> {
    protected:
        using abstract::PhysicalUnit<PressureUnit, Child>::PhysicalUnit;

    public:
        PressureUnit<Child>(const PressureUnit<Child> &other) : abstract::PhysicalUnit<PressureUnit, Child>{other.val} {};
        PressureUnit<Child>(PressureUnit<Child> &&other) : abstract::PhysicalUnit<PressureUnit, Child>{other.val} {};
        template <typename T>
        PressureUnit<Child>(const PressureUnit<T> &other) : abstract::PhysicalUnit<PressureUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        PressureUnit<Child>(PressureUnit<T> &&other) : abstract::PhysicalUnit<PressureUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};

        virtual std::string symbol() const = 0;

        PressureUnit<Child> &operator=(double value) {this->val=value; return *this;}
        PressureUnit<Child> &operator=(const PressureUnit<Child> &other) { this->val = other.val; return *this;}
        PressureUnit<Child> &operator=(PressureUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> PressureUnit<Child> &operator=(const PressureUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> PressureUnit<Child> &operator=(PressureUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif