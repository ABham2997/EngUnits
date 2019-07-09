#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::data_storage{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class DataStorage: public abstract::PhysicalUnit<DataStorage, Child> {
    protected:
        using abstract::PhysicalUnit<DataStorage, Child>::PhysicalUnit;

    public:
        DataStorage<Child>(const DataStorage<Child> &other) : abstract::PhysicalUnit<DataStorage, Child>{other.val} {};
        DataStorage<Child>(const DataStorage<Child> &&other) : abstract::PhysicalUnit<DataStorage, Child>{other.val} {};
        template <typename T>
        DataStorage<Child>(const DataStorage<T> &other) : abstract::PhysicalUnit<DataStorage, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        DataStorage<Child>(const DataStorage<T> &&other) : abstract::PhysicalUnit<DataStorage, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double SI_val() const override { return this->val; } 
        double abs_val() const override { return this->val*Grandchild::conversion; };

        DataStorage<Child> &operator=(const double value) {this->val=value; return *this;}
        DataStorage<Child> &operator=(const DataStorage<Child> &other) { this->val = other.val; return *this;}
        DataStorage<Child> &operator=(const DataStorage<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> DataStorage<Child> &operator=(const DataStorage<T> &other) { this->val = other.val; return *this;}
        template<typename T> DataStorage<Child> &operator=(const DataStorage<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif