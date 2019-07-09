#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::speed{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class Speed: public abstract::PhysicalUnit<Speed, Child> {
    protected:
        using abstract::PhysicalUnit<Speed, Child>::PhysicalUnit;

    public:
        Speed<Child>(const Speed<Child> &other) : abstract::PhysicalUnit<Speed, Child>{other.val} {};
        Speed<Child>(const Speed<Child> &&other) : abstract::PhysicalUnit<Speed, Child>{other.val} {};
        template <typename T>
        Speed<Child>(const Speed<T> &other) : abstract::PhysicalUnit<Speed, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        Speed<Child>(const Speed<T> &&other) : abstract::PhysicalUnit<Speed, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double SI_val() const override { return this->val; } 
        double abs_val() const override { return this->val*Grandchild::conversion; };

        Speed<Child> &operator=(const double value) {this->val=value; return *this;}
        Speed<Child> &operator=(const Speed<Child> &other) { this->val = other.val; return *this;}
        Speed<Child> &operator=(const Speed<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> Speed<Child> &operator=(const Speed<T> &other) { this->val = other.val; return *this;}
        template<typename T> Speed<Child> &operator=(const Speed<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif