#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::area{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class Area: public abstract::PhysicalUnit<Area, Child> {
    protected:
        using abstract::PhysicalUnit<Area, Child>::PhysicalUnit;

    public:
        Area<Child>(const Area<Child> &other) : abstract::PhysicalUnit<Area, Child>{other.val} {};
        Area<Child>(const Area<Child> &&other) : abstract::PhysicalUnit<Area, Child>{other.val} {};
        template <typename T>
        Area<Child>(const Area<T> &other) : abstract::PhysicalUnit<Area, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        Area<Child>(const Area<T> &&other) : abstract::PhysicalUnit<Area, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double SI_val() const override { return this->val; } 
        double abs_val() const override { return this->val*Grandchild::conversion; };

        Area<Child> &operator=(const double value) {this->val=value; return *this;}
        Area<Child> &operator=(const Area<Child> &other) { this->val = other.val; return *this;}
        Area<Child> &operator=(const Area<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> Area<Child> &operator=(const Area<T> &other) { this->val = other.val; return *this;}
        template<typename T> Area<Child> &operator=(const Area<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif