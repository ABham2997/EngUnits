#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::mass{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class Mass: public abstract::PhysicalUnit<Mass, Child> {
    protected:
        using abstract::PhysicalUnit<Mass, Child>::PhysicalUnit;

    public:
        Mass<Child>(const Mass<Child> &other) : abstract::PhysicalUnit<Mass, Child>{other.val} {};
        Mass<Child>(const Mass<Child> &&other) : abstract::PhysicalUnit<Mass, Child>{other.val} {};
        template <typename T>
        Mass<Child>(const Mass<T> &other) : abstract::PhysicalUnit<Mass, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        Mass<Child>(const Mass<T> &&other) : abstract::PhysicalUnit<Mass, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double SI_val() const override { return this->val; } 
        double abs_val() const override { return this->val*Grandchild::conversion; };

        Mass<Child> &operator=(const double value) {this->val=value; return *this;}
        Mass<Child> &operator=(const Mass<Child> &other) { this->val = other.val; return *this;}
        Mass<Child> &operator=(const Mass<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> Mass<Child> &operator=(const Mass<T> &other) { this->val = other.val; return *this;}
        template<typename T> Mass<Child> &operator=(const Mass<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif