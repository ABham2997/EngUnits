#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::frequency{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class Frequency: public abstract::PhysicalUnit<Frequency, Child> {
    protected:
        using abstract::PhysicalUnit<Frequency, Child>::PhysicalUnit;

    public:
        Frequency<Child>(const Frequency<Child> &other) : abstract::PhysicalUnit<Frequency, Child>{other.val} {};
        Frequency<Child>(const Frequency<Child> &&other) : abstract::PhysicalUnit<Frequency, Child>{other.val} {};
        template <typename T>
        Frequency<Child>(const Frequency<T> &other) : abstract::PhysicalUnit<Frequency, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        Frequency<Child>(const Frequency<T> &&other) : abstract::PhysicalUnit<Frequency, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double SI_val() const override { return this->val; } 
        double abs_val() const override { return this->val*Grandchild::conversion; };

        Frequency<Child> &operator=(const double value) {this->val=value; return *this;}
        Frequency<Child> &operator=(const Frequency<Child> &other) { this->val = other.val; return *this;}
        Frequency<Child> &operator=(const Frequency<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> Frequency<Child> &operator=(const Frequency<T> &other) { this->val = other.val; return *this;}
        template<typename T> Frequency<Child> &operator=(const Frequency<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif