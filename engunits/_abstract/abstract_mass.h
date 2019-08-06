#ifndef __ENGUNITS_ABSTRACT_MASS_H
#define __ENGUNITS_ABSTRACT_MASS_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::mass{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class MassUnit: public abstract::PhysicalUnit<MassUnit, Child> {
    protected:
        using abstract::PhysicalUnit<MassUnit, Child>::PhysicalUnit;

    public:
        MassUnit<Child>(const MassUnit<Child> &other) : abstract::PhysicalUnit<MassUnit, Child>{other.val} {};
        MassUnit<Child>(MassUnit<Child> &&other) : abstract::PhysicalUnit<MassUnit, Child>{other.val} {};
        template <typename T>
        MassUnit<Child>(const MassUnit<T> &other) : abstract::PhysicalUnit<MassUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        MassUnit<Child>(MassUnit<T> &&other) : abstract::PhysicalUnit<MassUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        MassUnit<Child> &operator=(double value) {this->val=value; return *this;}
        MassUnit<Child> &operator=(const MassUnit<Child> &other) { this->val = other.val; return *this;}
        MassUnit<Child> &operator=(MassUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> MassUnit<Child> &operator=(const MassUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> MassUnit<Child> &operator=(MassUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif