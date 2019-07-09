#ifndef __ENGUNITS_ABSTRACT_AREA_H
#define __ENGUNITS_ABSTRACT_AREA_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::area{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class AreaUnit: public abstract::PhysicalUnit<AreaUnit, Child> {
    protected:
        using abstract::PhysicalUnit<AreaUnit, Child>::PhysicalUnit;

    public:
        AreaUnit<Child>(const AreaUnit<Child> &other) : abstract::PhysicalUnit<AreaUnit, Child>{other.val} {};
        AreaUnit<Child>(const AreaUnit<Child> &&other) : abstract::PhysicalUnit<AreaUnit, Child>{other.val} {};
        template <typename T>
        AreaUnit<Child>(const AreaUnit<T> &other) : abstract::PhysicalUnit<AreaUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        AreaUnit<Child>(const AreaUnit<T> &&other) : abstract::PhysicalUnit<AreaUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double scalar() const override { return this->val; } 
        double si_val() const override { return this->val*Child::conversion; };

        AreaUnit<Child> &operator=(const double value) {this->val=value; return *this;}
        AreaUnit<Child> &operator=(const AreaUnit<Child> &other) { this->val = other.val; return *this;}
        AreaUnit<Child> &operator=(const AreaUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> AreaUnit<Child> &operator=(const AreaUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> AreaUnit<Child> &operator=(const AreaUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif