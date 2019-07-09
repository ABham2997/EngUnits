#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::energy{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class Energy: public abstract::PhysicalUnit<Energy, Child> {
    protected:
        using abstract::PhysicalUnit<Energy, Child>::PhysicalUnit;

    public:
        Energy<Child>(const Energy<Child> &other) : abstract::PhysicalUnit<Energy, Child>{other.val} {};
        Energy<Child>(const Energy<Child> &&other) : abstract::PhysicalUnit<Energy, Child>{other.val} {};
        template <typename T>
        Energy<Child>(const Energy<T> &other) : abstract::PhysicalUnit<Energy, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        Energy<Child>(const Energy<T> &&other) : abstract::PhysicalUnit<Energy, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double SI_val() const override { return this->val; } 
        double abs_val() const override { return this->val*Grandchild::conversion; };

        Energy<Child> &operator=(const double value) {this->val=value; return *this;}
        Energy<Child> &operator=(const Energy<Child> &other) { this->val = other.val; return *this;}
        Energy<Child> &operator=(const Energy<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> Energy<Child> &operator=(const Energy<T> &other) { this->val = other.val; return *this;}
        template<typename T> Energy<Child> &operator=(const Energy<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif