#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::time{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class Time: public abstract::PhysicalUnit<Time, Child> {
    protected:
        using abstract::PhysicalUnit<Time, Child>::PhysicalUnit;

    public:
        Time<Child>(const Time<Child> &other) : abstract::PhysicalUnit<Time, Child>{other.val} {};
        Time<Child>(const Time<Child> &&other) : abstract::PhysicalUnit<Time, Child>{other.val} {};
        template <typename T>
        Time<Child>(const Time<T> &other) : abstract::PhysicalUnit<Time, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        Time<Child>(const Time<T> &&other) : abstract::PhysicalUnit<Time, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double SI_val() const override { return this->val; } 
        double abs_val() const override { return this->val*Grandchild::conversion; };

        Time<Child> &operator=(const double value) {this->val=value; return *this;}
        Time<Child> &operator=(const Time<Child> &other) { this->val = other.val; return *this;}
        Time<Child> &operator=(const Time<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> Time<Child> &operator=(const Time<T> &other) { this->val = other.val; return *this;}
        template<typename T> Time<Child> &operator=(const Time<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif