#ifndef __ENGUNITS_ABSTRACT_FORCE_H
#define __ENGUNITS_ABSTRACT_FORCE_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::force{
class Newtons; //forward declaration

//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child=Newtons> //TODO: constrain to children of this class
class ForceUnit: public abstract::PhysicalUnit<ForceUnit, Child> {
    protected:
        using abstract::PhysicalUnit<ForceUnit, Child>::PhysicalUnit;

    public:
        constexpr ForceUnit<Child>(const ForceUnit<Child> &other) : abstract::PhysicalUnit<ForceUnit, Child>{other.val} {};
        constexpr ForceUnit<Child>(ForceUnit<Child> &&other) : abstract::PhysicalUnit<ForceUnit, Child>{other.val} {};
        template <typename T>
        constexpr ForceUnit<Child>(const ForceUnit<T> &other) : abstract::PhysicalUnit<ForceUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        constexpr ForceUnit<Child>(ForceUnit<T> &&other) : abstract::PhysicalUnit<ForceUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        Child &operator=(double value) {this->val=value; return *static_cast<Child*>(this);}
        Child &operator=(const ForceUnit<Child> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        Child &operator=(ForceUnit<Child> &&other) { this->val = other.val; return *static_cast<Child*>(this);}     
        template<typename T> 
        Child &operator=(const ForceUnit<T> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        template<typename T> 
        Child &operator=(ForceUnit<T> &&other) { this->val = other.val; return *static_cast<Child*>(this);}
        
};
}

#endif