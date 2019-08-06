#ifndef __ENGUNITS_ABSTRACT_ANGLE_H
#define __ENGUNITS_ABSTRACT_ANGLE_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::angle{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class AngleUnit: public abstract::PhysicalUnit<AngleUnit, Child> {
    protected:
        using abstract::PhysicalUnit<AngleUnit, Child>::PhysicalUnit;

    public:
        AngleUnit<Child>(const AngleUnit<Child> &other) : abstract::PhysicalUnit<AngleUnit, Child>{other.val} {};
        AngleUnit<Child>(AngleUnit<Child> &&other) : abstract::PhysicalUnit<AngleUnit, Child>{other.val} {};
        template <typename T>
        AngleUnit<Child>(const AngleUnit<T> &other) : abstract::PhysicalUnit<AngleUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        AngleUnit<Child>(AngleUnit<T> &&other) : abstract::PhysicalUnit<AngleUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        AngleUnit<Child> &operator=(double value) {this->val=value; return *this;}
        AngleUnit<Child> &operator=(const AngleUnit<Child> &other) { this->val = other.val; return *this;}
        AngleUnit<Child> &operator=(AngleUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> AngleUnit<Child> &operator=(const AngleUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> AngleUnit<Child> &operator=(AngleUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif