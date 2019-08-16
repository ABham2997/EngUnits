#ifndef __ENGUNITS_ABSTRACT_MASS_H
#define __ENGUNITS_ABSTRACT_MASS_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::mass{
class kilograms; //forward declaration

//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child=kilograms> //TODO: constrain to children of this class
class MassUnit: public abstract::PhysicalUnit<MassUnit, Child> {
    protected:
        using abstract::PhysicalUnit<MassUnit, Child>::PhysicalUnit;

    public:
        using SI_type = kilograms;

        constexpr MassUnit<Child>(const MassUnit<Child> &other) : abstract::PhysicalUnit<MassUnit, Child>{other.val} {};
        constexpr MassUnit<Child>(MassUnit<Child> &&other) : abstract::PhysicalUnit<MassUnit, Child>{other.val} {};
        template <typename T>
        constexpr MassUnit<Child>(const MassUnit<T> &other) : abstract::PhysicalUnit<MassUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        constexpr MassUnit<Child>(MassUnit<T> &&other) : abstract::PhysicalUnit<MassUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        Child &operator=(double value) {this->val=value; return *static_cast<Child*>(this);}
        Child &operator=(const MassUnit<Child> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        Child &operator=(MassUnit<Child> &&other) { this->val = other.val; return *static_cast<Child*>(this);}     
        template<typename T> 
        Child &operator=(const MassUnit<T> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        template<typename T> 
        Child &operator=(MassUnit<T> &&other) { this->val = other.val; return *static_cast<Child*>(this);}
        
};
}

#endif