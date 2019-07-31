#ifndef __ENGUNITS_ABSTRACT_TEMPERATURE_H
#define __ENGUNITS_ABSTRACT_TEMPERATURE_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_abstract/core.h"

namespace engunits::temperature{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class TemperatureUnit: public abstract::PhysicalUnit<TemperatureUnit, Child> {
    protected:
        using abstract::PhysicalUnit<TemperatureUnit, Child>::PhysicalUnit;

    public:
        TemperatureUnit<Child>(const TemperatureUnit<Child> &other) : abstract::PhysicalUnit<TemperatureUnit, Child>{other.val} {};
        TemperatureUnit<Child>(TemperatureUnit<Child> &&other) : abstract::PhysicalUnit<TemperatureUnit, Child>{other.val} {};
        template <typename T>
        TemperatureUnit<Child>(const TemperatureUnit<T> &other) : abstract::PhysicalUnit<TemperatureUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        TemperatureUnit<Child>(TemperatureUnit<T> &&other) : abstract::PhysicalUnit<TemperatureUnit, Child>{(convert<Child>(other))} {};

        virtual std::string symbol() const = 0;

        TemperatureUnit<Child> &operator=(double value) {this->val=value; return *this;}
        TemperatureUnit<Child> &operator=(const TemperatureUnit<Child> &other) { this->val = other.val; return *this;}
        TemperatureUnit<Child> &operator=(TemperatureUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> TemperatureUnit<Child> &operator=(const TemperatureUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> TemperatureUnit<Child> &operator=(TemperatureUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif