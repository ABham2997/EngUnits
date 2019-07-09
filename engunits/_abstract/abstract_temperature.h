#ifndef __ENGUNITS_ABSTRACT_TEMPERATURE_H
#define __ENGUNITS_ABSTRACT_TEMPERATURE_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::temperature{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class TemperatureUnit: public abstract::PhysicalUnit<TemperatureUnit, Child> {
    protected:
        using abstract::PhysicalUnit<TemperatureUnit, Child>::PhysicalUnit;

    public:
        TemperatureUnit<Child>(const TemperatureUnit<Child> &other) : abstract::PhysicalUnit<TemperatureUnit, Child>{other.val} {};
        TemperatureUnit<Child>(const TemperatureUnit<Child> &&other) : abstract::PhysicalUnit<TemperatureUnit, Child>{other.val} {};
        template <typename T>
        TemperatureUnit<Child>(const TemperatureUnit<T> &other) : abstract::PhysicalUnit<TemperatureUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        TemperatureUnit<Child>(const TemperatureUnit<T> &&other) : abstract::PhysicalUnit<TemperatureUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double si_val() const override { return this->val; } 
        double abs_val() const override { return this->val*Grandchild::conversion; };

        TemperatureUnit<Child> &operator=(const double value) {this->val=value; return *this;}
        TemperatureUnit<Child> &operator=(const TemperatureUnit<Child> &other) { this->val = other.val; return *this;}
        TemperatureUnit<Child> &operator=(const TemperatureUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> TemperatureUnit<Child> &operator=(const TemperatureUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> TemperatureUnit<Child> &operator=(const TemperatureUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif