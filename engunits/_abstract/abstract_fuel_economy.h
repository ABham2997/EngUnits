#ifndef __ENGUNITS_ABSTRACT_FUEL_ECONOMY_H
#define __ENGUNITS_ABSTRACT_FUEL_ECONOMY_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::fuel_economy{
class milePerGallon; //forward declaration

//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child=milePerGallon> //TODO: constrain to children of this class
class FuelEconomyUnit: public abstract::PhysicalUnit<FuelEconomyUnit, Child> {
    protected:
        using abstract::PhysicalUnit<FuelEconomyUnit, Child>::PhysicalUnit;

    public:
        using SI_type = milePerGallon;

        FuelEconomyUnit<Child>(const FuelEconomyUnit<Child> &other) : abstract::PhysicalUnit<FuelEconomyUnit, Child>{other.val} {};
        FuelEconomyUnit<Child>(FuelEconomyUnit<Child> &&other) : abstract::PhysicalUnit<FuelEconomyUnit, Child>{other.val} {};
        template <typename T>
        FuelEconomyUnit<Child>(const FuelEconomyUnit<T> &other) : abstract::PhysicalUnit<FuelEconomyUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        FuelEconomyUnit<Child>(FuelEconomyUnit<T> &&other) : abstract::PhysicalUnit<FuelEconomyUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        FuelEconomyUnit<Child> &operator=(double value) {this->val=value; return *this;}
        FuelEconomyUnit<Child> &operator=(const FuelEconomyUnit<Child> &other) { this->val = other.val; return *this;}
        FuelEconomyUnit<Child> &operator=(FuelEconomyUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> FuelEconomyUnit<Child> &operator=(const FuelEconomyUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> FuelEconomyUnit<Child> &operator=(FuelEconomyUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif