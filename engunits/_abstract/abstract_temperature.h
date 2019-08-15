#ifndef __ENGUNITS_ABSTRACT_TEMPERATURE_H
#define __ENGUNITS_ABSTRACT_TEMPERATURE_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::temperature{
class Kelvin; //forward declaration

//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child=Kelvin> //TODO: constrain to children of this class
class TemperatureUnit: public abstract::PhysicalUnit<TemperatureUnit, Child> {
    protected:
        using abstract::PhysicalUnit<TemperatureUnit, Child>::PhysicalUnit;

    public:
        using SI_type = Kelvin;

        constexpr TemperatureUnit<Child>(const TemperatureUnit<Child> &other) : abstract::PhysicalUnit<TemperatureUnit, Child>{other.val} {};
        TemperatureUnit<Child>(TemperatureUnit<Child> &&other) : abstract::PhysicalUnit<TemperatureUnit, Child>{other.val} {};
        template <typename T>
        constexpr TemperatureUnit<Child>(const TemperatureUnit<T> &other) : abstract::PhysicalUnit<TemperatureUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        TemperatureUnit<Child>(TemperatureUnit<T> &&other) : abstract::PhysicalUnit<TemperatureUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        Child &operator=(double value) {this->val=value; return *static_cast<Child*>(this);}
        Child &operator=(const TemperatureUnit<Child> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        Child &operator=(TemperatureUnit<Child> &&other) { this->val = other.val; return *static_cast<Child*>(this);}     
        template<typename T> 
        Child &operator=(const TemperatureUnit<T> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        template<typename T> 
        Child &operator=(TemperatureUnit<T> &&other) { this->val = other.val; return *static_cast<Child*>(this);}
        
};
}

#endif