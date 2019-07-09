#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::acceleration{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class Acceleration: public abstract::PhysicalUnit<Acceleration, Child> {
    protected:
        using abstract::PhysicalUnit<Acceleration, Child>::PhysicalUnit;

    public:
        Acceleration<Child>(const Acceleration<Child> &other) : abstract::PhysicalUnit<Acceleration, Child>{other.val} {};
        Acceleration<Child>(const Acceleration<Child> &&other) : abstract::PhysicalUnit<Acceleration, Child>{other.val} {};
        template <typename T>
        Acceleration<Child>(const Acceleration<T> &other) : abstract::PhysicalUnit<Acceleration, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        Acceleration<Child>(const Acceleration<T> &&other) : abstract::PhysicalUnit<Acceleration, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double SI_val() const override { return this->val; } 
        double abs_val() const override { return this->val*Grandchild::conversion; };

        Acceleration<Child> &operator=(const double value) {this->val=value; return *this;}
        Acceleration<Child> &operator=(const Acceleration<Child> &other) { this->val = other.val; return *this;}
        Acceleration<Child> &operator=(const Acceleration<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> Acceleration<Child> &operator=(const Acceleration<T> &other) { this->val = other.val; return *this;}
        template<typename T> Acceleration<Child> &operator=(const Acceleration<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif