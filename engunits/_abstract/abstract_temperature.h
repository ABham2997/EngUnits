#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::temperature{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class Temperature: public abstract::PhysicalUnit<Temperature, Child> {
    protected:
        using abstract::PhysicalUnit<Temperature, Child>::PhysicalUnit;

    public:
        Temperature<Child>(const Temperature<Child> &other) : abstract::PhysicalUnit<Temperature, Child>{other.val} {};
        Temperature<Child>(const Temperature<Child> &&other) : abstract::PhysicalUnit<Temperature, Child>{other.val} {};
        template <typename T>
        Temperature<Child>(const Temperature<T> &other) : abstract::PhysicalUnit<Temperature, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        Temperature<Child>(const Temperature<T> &&other) : abstract::PhysicalUnit<Temperature, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double SI_val() const override { return this->val; } 
        double abs_val() const override { return this->val*Grandchild::conversion; };

        Temperature<Child> &operator=(const double value) {this->val=value; return *this;}
        Temperature<Child> &operator=(const Temperature<Child> &other) { this->val = other.val; return *this;}
        Temperature<Child> &operator=(const Temperature<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> Temperature<Child> &operator=(const Temperature<T> &other) { this->val = other.val; return *this;}
        template<typename T> Temperature<Child> &operator=(const Temperature<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif