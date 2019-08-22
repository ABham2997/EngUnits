#ifndef __ENGUNITS_ABSTRACT_AREA_H
#define __ENGUNITS_ABSTRACT_AREA_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::area{
class sq_meters; //forward declaration

//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child=sq_meters> //TODO: constrain to children of this class
class AreaUnit: public abstract::PhysicalUnit<AreaUnit, Child> {
    protected:
        using abstract::PhysicalUnit<AreaUnit, Child>::PhysicalUnit;

    public:
        using si_t = sq_meters;

        constexpr AreaUnit<Child>(const AreaUnit<Child> &other) : abstract::PhysicalUnit<AreaUnit, Child>{other.val} {};
        constexpr AreaUnit<Child>(AreaUnit<Child> &&other) : abstract::PhysicalUnit<AreaUnit, Child>{other.val} {};
        template <typename T>
        constexpr AreaUnit<Child>(const AreaUnit<T> &other) : abstract::PhysicalUnit<AreaUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        constexpr AreaUnit<Child>(AreaUnit<T> &&other) : abstract::PhysicalUnit<AreaUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        Child &operator=(const double &value) {this->val=value; return *static_cast<Child*>(this);}
        Child &operator=(const AreaUnit<Child> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        Child &operator=(AreaUnit<Child> &&other) { this->val = other.val; return *static_cast<Child*>(this);}  
        
};

}

#endif