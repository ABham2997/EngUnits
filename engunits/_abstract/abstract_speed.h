#ifndef __ENGUNITS_ABSTRACT_SPEED_H
#define __ENGUNITS_ABSTRACT_SPEED_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::speed{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class SpeedUnit: public abstract::PhysicalUnit<SpeedUnit, Child> {
    protected:
        using abstract::PhysicalUnit<SpeedUnit, Child>::PhysicalUnit;

    public:
        SpeedUnit<Child>(const SpeedUnit<Child> &other) : abstract::PhysicalUnit<SpeedUnit, Child>{other.val} {};
        SpeedUnit<Child>(const SpeedUnit<Child> &&other) : abstract::PhysicalUnit<SpeedUnit, Child>{other.val} {};
        template <typename T>
        SpeedUnit<Child>(const SpeedUnit<T> &other) : abstract::PhysicalUnit<SpeedUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        SpeedUnit<Child>(const SpeedUnit<T> &&other) : abstract::PhysicalUnit<SpeedUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double scalar() const override { return this->val; } 
        double si_val() const override { return this->val*Child::conversion; };

        SpeedUnit<Child> &operator=(const double value) {this->val=value; return *this;}
        SpeedUnit<Child> &operator=(const SpeedUnit<Child> &other) { this->val = other.val; return *this;}
        SpeedUnit<Child> &operator=(const SpeedUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> SpeedUnit<Child> &operator=(const SpeedUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> SpeedUnit<Child> &operator=(const SpeedUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif