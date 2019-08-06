#ifndef __ENGUNITS_ABSTRACT_AREA_H
#define __ENGUNITS_ABSTRACT_AREA_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::area{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class AreaUnit: public abstract::PhysicalUnit<AreaUnit, Child> {
    protected:
        using abstract::PhysicalUnit<AreaUnit, Child>::PhysicalUnit;

    public:
        AreaUnit<Child>(const AreaUnit<Child> &other) : abstract::PhysicalUnit<AreaUnit, Child>{other.val} {};
        AreaUnit<Child>(AreaUnit<Child> &&other) : abstract::PhysicalUnit<AreaUnit, Child>{other.val} {};
        template <typename T>
        AreaUnit<Child>(const AreaUnit<T> &other) : abstract::PhysicalUnit<AreaUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        AreaUnit<Child>(AreaUnit<T> &&other) : abstract::PhysicalUnit<AreaUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        AreaUnit<Child> &operator=(double value) {this->val=value; return *this;}
        AreaUnit<Child> &operator=(const AreaUnit<Child> &other) { this->val = other.val; return *this;}
        AreaUnit<Child> &operator=(AreaUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> AreaUnit<Child> &operator=(const AreaUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> AreaUnit<Child> &operator=(AreaUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif