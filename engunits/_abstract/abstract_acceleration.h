#ifndef __ENGUNITS_ABSTRACT_ACCELERATION_H
#define __ENGUNITS_ABSTRACT_ACCELERATION_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::acceleration{
class metersPerSecondSq; //forward declaration

//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child=metersPerSecondSq> //TODO: constrain to children of this class
class AccelerationUnit: public abstract::PhysicalUnit<AccelerationUnit, Child> {
    protected:
        using abstract::PhysicalUnit<AccelerationUnit, Child>::PhysicalUnit;

    public:
        using si_t = metersPerSecondSq;

        constexpr AccelerationUnit<Child>(const AccelerationUnit<Child> &other) : abstract::PhysicalUnit<AccelerationUnit, Child>{other.val} {};
        constexpr AccelerationUnit<Child>(AccelerationUnit<Child> &&other) : abstract::PhysicalUnit<AccelerationUnit, Child>{other.val} {};
        template <typename T>
        constexpr AccelerationUnit<Child>(const AccelerationUnit<T> &other) : abstract::PhysicalUnit<AccelerationUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        constexpr AccelerationUnit<Child>(AccelerationUnit<T> &&other) : abstract::PhysicalUnit<AccelerationUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        Child &operator=(const double &value) {this->val=value; return *static_cast<Child*>(this);}
        Child &operator=(const AccelerationUnit<Child> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        Child &operator=(AccelerationUnit<Child> &&other) { this->val = other.val; return *static_cast<Child*>(this);}  
        
};

}

#endif