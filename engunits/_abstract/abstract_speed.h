#ifndef __ENGUNITS_ABSTRACT_SPEED_H
#define __ENGUNITS_ABSTRACT_SPEED_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::speed{
class metersPerSecond; //forward declaration

//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child=metersPerSecond> //TODO: constrain to children of this class
class SpeedUnit: public abstract::PhysicalUnit<SpeedUnit, Child> {
    protected:
        using abstract::PhysicalUnit<SpeedUnit, Child>::PhysicalUnit;

    public:
        using SI_type = metersPerSecond;

        SpeedUnit<Child>(const SpeedUnit<Child> &other) : abstract::PhysicalUnit<SpeedUnit, Child>{other.val} {};
        SpeedUnit<Child>(SpeedUnit<Child> &&other) : abstract::PhysicalUnit<SpeedUnit, Child>{other.val} {};
        template <typename T>
        SpeedUnit<Child>(const SpeedUnit<T> &other) : abstract::PhysicalUnit<SpeedUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        SpeedUnit<Child>(SpeedUnit<T> &&other) : abstract::PhysicalUnit<SpeedUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        Child &operator=(double value) {this->val=value; return *static_cast<Child*>(this);}
        Child &operator=(const SpeedUnit<Child> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        Child &operator=(SpeedUnit<Child> &&other) { this->val = other.val; return *static_cast<Child*>(this);}     
        template<typename T> 
        Child &operator=(const SpeedUnit<T> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        template<typename T> 
        Child &operator=(SpeedUnit<T> &&other) { this->val = other.val; return *static_cast<Child*>(this);}
        
};
}

#endif