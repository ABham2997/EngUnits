#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::length{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class LengthUnit: public abstract::PhysicalUnit<LengthUnit, Child> {
    protected:
        using abstract::PhysicalUnit<LengthUnit, Child>::PhysicalUnit;

    public:
        LengthUnit<Child>(const LengthUnit<Child> &other) : abstract::PhysicalUnit<LengthUnit, Child>{other.val} {};
        LengthUnit<Child>(const LengthUnit<Child> &&other) : abstract::PhysicalUnit<LengthUnit, Child>{other.val} {};
        template <typename T>
        LengthUnit<Child>(const LengthUnit<T> &other) : abstract::PhysicalUnit<LengthUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        LengthUnit<Child>(const LengthUnit<T> &&other) : abstract::PhysicalUnit<LengthUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};

        std::string type() const override { return "length"; }

        LengthUnit<Child> &operator=(const double value) {this->val=value; return *this;}
        LengthUnit<Child> &operator=(const LengthUnit<Child> &other) { this->val = other.val; return *this;}
        LengthUnit<Child> &operator=(const LengthUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> LengthUnit<Child> &operator=(const LengthUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> LengthUnit<Child> &operator=(const LengthUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif