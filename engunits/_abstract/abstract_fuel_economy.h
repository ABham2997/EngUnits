#ifndef __ENGUNITS_ABSTRACT_FUEL_ECONOMY_H
#define __ENGUNITS_ABSTRACT_FUEL_ECONOMY_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::fuel_economy{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class FuelEconomyUnit: public abstract::PhysicalUnit<FuelEconomyUnit, Child> {
    protected:
        using abstract::PhysicalUnit<FuelEconomyUnit, Child>::PhysicalUnit;

    public:
        FuelEconomyUnit<Child>(const FuelEconomyUnit<Child> &other) : abstract::PhysicalUnit<FuelEconomyUnit, Child>{other.val} {};
        FuelEconomyUnit<Child>(const FuelEconomyUnit<Child> &&other) : abstract::PhysicalUnit<FuelEconomyUnit, Child>{other.val} {};
        template <typename T>
        FuelEconomyUnit<Child>(const FuelEconomyUnit<T> &other) : abstract::PhysicalUnit<FuelEconomyUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        FuelEconomyUnit<Child>(const FuelEconomyUnit<T> &&other) : abstract::PhysicalUnit<FuelEconomyUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};

        virtual std::string symbol() const = 0;

        FuelEconomyUnit<Child> &operator=(const double value) {this->val=value; return *this;}
        FuelEconomyUnit<Child> &operator=(const FuelEconomyUnit<Child> &other) { this->val = other.val; return *this;}
        FuelEconomyUnit<Child> &operator=(const FuelEconomyUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> FuelEconomyUnit<Child> &operator=(const FuelEconomyUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> FuelEconomyUnit<Child> &operator=(const FuelEconomyUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif