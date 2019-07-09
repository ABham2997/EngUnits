#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::fuel_economy{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class FuelEconomy: public abstract::PhysicalUnit<FuelEconomy, Child> {
    protected:
        using abstract::PhysicalUnit<FuelEconomy, Child>::PhysicalUnit;

    public:
        FuelEconomy<Child>(const FuelEconomy<Child> &other) : abstract::PhysicalUnit<FuelEconomy, Child>{other.val} {};
        FuelEconomy<Child>(const FuelEconomy<Child> &&other) : abstract::PhysicalUnit<FuelEconomy, Child>{other.val} {};
        template <typename T>
        FuelEconomy<Child>(const FuelEconomy<T> &other) : abstract::PhysicalUnit<FuelEconomy, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        FuelEconomy<Child>(const FuelEconomy<T> &&other) : abstract::PhysicalUnit<FuelEconomy, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double SI_val() const override { return this->val; } 
        double abs_val() const override { return this->val*Grandchild::conversion; };

        FuelEconomy<Child> &operator=(const double value) {this->val=value; return *this;}
        FuelEconomy<Child> &operator=(const FuelEconomy<Child> &other) { this->val = other.val; return *this;}
        FuelEconomy<Child> &operator=(const FuelEconomy<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> FuelEconomy<Child> &operator=(const FuelEconomy<T> &other) { this->val = other.val; return *this;}
        template<typename T> FuelEconomy<Child> &operator=(const FuelEconomy<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif