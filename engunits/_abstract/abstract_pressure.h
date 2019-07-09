#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::pressure{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class Pressure: public abstract::PhysicalUnit<Pressure, Child> {
    protected:
        using abstract::PhysicalUnit<Pressure, Child>::PhysicalUnit;

    public:
        Pressure<Child>(const Pressure<Child> &other) : abstract::PhysicalUnit<Pressure, Child>{other.val} {};
        Pressure<Child>(const Pressure<Child> &&other) : abstract::PhysicalUnit<Pressure, Child>{other.val} {};
        template <typename T>
        Pressure<Child>(const Pressure<T> &other) : abstract::PhysicalUnit<Pressure, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        Pressure<Child>(const Pressure<T> &&other) : abstract::PhysicalUnit<Pressure, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double SI_val() const override { return this->val; } 
        double abs_val() const override { return this->val*Grandchild::conversion; };

        Pressure<Child> &operator=(const double value) {this->val=value; return *this;}
        Pressure<Child> &operator=(const Pressure<Child> &other) { this->val = other.val; return *this;}
        Pressure<Child> &operator=(const Pressure<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> Pressure<Child> &operator=(const Pressure<T> &other) { this->val = other.val; return *this;}
        template<typename T> Pressure<Child> &operator=(const Pressure<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif