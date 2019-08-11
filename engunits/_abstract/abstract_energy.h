#ifndef __ENGUNITS_ABSTRACT_ENERGY_H
#define __ENGUNITS_ABSTRACT_ENERGY_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::energy{
class Joules; //forward declaration

//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child=Joules> //TODO: constrain to children of this class
class EnergyUnit: public abstract::PhysicalUnit<EnergyUnit, Child> {
    protected:
        using abstract::PhysicalUnit<EnergyUnit, Child>::PhysicalUnit;

    public:
        using SI_type = Joules;

        EnergyUnit<Child>(const EnergyUnit<Child> &other) : abstract::PhysicalUnit<EnergyUnit, Child>{other.val} {};
        EnergyUnit<Child>(EnergyUnit<Child> &&other) : abstract::PhysicalUnit<EnergyUnit, Child>{other.val} {};
        template <typename T>
        EnergyUnit<Child>(const EnergyUnit<T> &other) : abstract::PhysicalUnit<EnergyUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        EnergyUnit<Child>(EnergyUnit<T> &&other) : abstract::PhysicalUnit<EnergyUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        EnergyUnit<Child> &operator=(double value) {this->val=value; return *this;}
        EnergyUnit<Child> &operator=(const EnergyUnit<Child> &other) { this->val = other.val; return *this;}
        EnergyUnit<Child> &operator=(EnergyUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> EnergyUnit<Child> &operator=(const EnergyUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> EnergyUnit<Child> &operator=(EnergyUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif