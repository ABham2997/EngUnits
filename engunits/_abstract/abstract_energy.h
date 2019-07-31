#ifndef __ENGUNITS_ABSTRACT_ENERGY_H
#define __ENGUNITS_ABSTRACT_ENERGY_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::energy{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class EnergyUnit: public abstract::PhysicalUnit<EnergyUnit, Child> {
    protected:
        using abstract::PhysicalUnit<EnergyUnit, Child>::PhysicalUnit;

    public:
        EnergyUnit<Child>(const EnergyUnit<Child> &other) : abstract::PhysicalUnit<EnergyUnit, Child>{other.val} {};
        EnergyUnit<Child>(const EnergyUnit<Child> &&other) : abstract::PhysicalUnit<EnergyUnit, Child>{other.val} {};
        template <typename T>
        EnergyUnit<Child>(const EnergyUnit<T> &other) : abstract::PhysicalUnit<EnergyUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        EnergyUnit<Child>(const EnergyUnit<T> &&other) : abstract::PhysicalUnit<EnergyUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};

        virtual std::string symbol() const = 0;

        EnergyUnit<Child> &operator=(const double value) {this->val=value; return *this;}
        EnergyUnit<Child> &operator=(const EnergyUnit<Child> &other) { this->val = other.val; return *this;}
        EnergyUnit<Child> &operator=(const EnergyUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> EnergyUnit<Child> &operator=(const EnergyUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> EnergyUnit<Child> &operator=(const EnergyUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif