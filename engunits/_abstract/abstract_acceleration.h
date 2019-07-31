#ifndef __ENGUNITS_ABSTRACT_ACCELERATION_H
#define __ENGUNITS_ABSTRACT_ACCELERATION_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::acceleration{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class AccelerationUnit: public abstract::PhysicalUnit<AccelerationUnit, Child> {
    protected:
        using abstract::PhysicalUnit<AccelerationUnit, Child>::PhysicalUnit;

    public:
        AccelerationUnit<Child>(const AccelerationUnit<Child> &other) : abstract::PhysicalUnit<AccelerationUnit, Child>{other.val} {};
        AccelerationUnit<Child>(const AccelerationUnit<Child> &&other) : abstract::PhysicalUnit<AccelerationUnit, Child>{other.val} {};
        template <typename T>
        AccelerationUnit<Child>(const AccelerationUnit<T> &other) : abstract::PhysicalUnit<AccelerationUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        AccelerationUnit<Child>(const AccelerationUnit<T> &&other) : abstract::PhysicalUnit<AccelerationUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};

        virtual std::string symbol() const = 0;

        AccelerationUnit<Child> &operator=(const double value) {this->val=value; return *this;}
        AccelerationUnit<Child> &operator=(const AccelerationUnit<Child> &other) { this->val = other.val; return *this;}
        AccelerationUnit<Child> &operator=(const AccelerationUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> AccelerationUnit<Child> &operator=(const AccelerationUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> AccelerationUnit<Child> &operator=(const AccelerationUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif