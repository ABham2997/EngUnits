#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::angle{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class Angle: public abstract::PhysicalUnit<Angle, Child> {
    protected:
        using abstract::PhysicalUnit<Angle, Child>::PhysicalUnit;

    public:
        Angle<Child>(const Angle<Child> &other) : abstract::PhysicalUnit<Angle, Child>{other.val} {};
        Angle<Child>(const Angle<Child> &&other) : abstract::PhysicalUnit<Angle, Child>{other.val} {};
        template <typename T>
        Angle<Child>(const Angle<T> &other) : abstract::PhysicalUnit<Angle, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        Angle<Child>(const Angle<T> &&other) : abstract::PhysicalUnit<Angle, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double SI_val() const override { return this->val; } 
        double abs_val() const override { return this->val*Grandchild::conversion; };

        Angle<Child> &operator=(const double value) {this->val=value; return *this;}
        Angle<Child> &operator=(const Angle<Child> &other) { this->val = other.val; return *this;}
        Angle<Child> &operator=(const Angle<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> Angle<Child> &operator=(const Angle<T> &other) { this->val = other.val; return *this;}
        template<typename T> Angle<Child> &operator=(const Angle<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif