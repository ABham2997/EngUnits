#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::length{
class meters; //forward declaration

//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child=meters> //TODO: constrain to children of this class
class LengthUnit: public abstract::PhysicalUnit<LengthUnit, Child> {
    protected:
        using abstract::PhysicalUnit<LengthUnit, Child>::PhysicalUnit;

    public:
        using SI_type = meters;

        LengthUnit<Child>(const LengthUnit<Child> &other) : abstract::PhysicalUnit<LengthUnit, Child>{other.val} {};
        LengthUnit<Child>(LengthUnit<Child> &&other) : abstract::PhysicalUnit<LengthUnit, Child>{other.val} {};
        template <typename T>
        LengthUnit<Child>(const LengthUnit<T> &other) : abstract::PhysicalUnit<LengthUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        LengthUnit<Child>(LengthUnit<T> &&other) : abstract::PhysicalUnit<LengthUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        LengthUnit<Child> &operator=(double value) {this->val=value; return *this;}
        LengthUnit<Child> &operator=(const LengthUnit<Child> &other) { this->val = other.val; return *this;}
        LengthUnit<Child> &operator=(LengthUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> LengthUnit<Child> &operator=(const LengthUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> LengthUnit<Child> &operator=(LengthUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif