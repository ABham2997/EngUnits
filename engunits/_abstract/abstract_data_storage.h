#ifndef __ENGUNITS_ABSTRACT_DATA_STORAGE_H
#define __ENGUNITS_ABSTRACT_DATA_STORAGE_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::data_storage{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class DataStorageUnit: public abstract::PhysicalUnit<DataStorageUnit, Child> {
    protected:
        using abstract::PhysicalUnit<DataStorageUnit, Child>::PhysicalUnit;

    public:
        DataStorageUnit<Child>(const DataStorageUnit<Child> &other) : abstract::PhysicalUnit<DataStorageUnit, Child>{other.val} {};
        DataStorageUnit<Child>(const DataStorageUnit<Child> &&other) : abstract::PhysicalUnit<DataStorageUnit, Child>{other.val} {};
        template <typename T>
        DataStorageUnit<Child>(const DataStorageUnit<T> &other) : abstract::PhysicalUnit<DataStorageUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        DataStorageUnit<Child>(const DataStorageUnit<T> &&other) : abstract::PhysicalUnit<DataStorageUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double SI_val() const override { return this->val; } 
        double abs_val() const override { return this->val*Grandchild::conversion; };

        DataStorageUnit<Child> &operator=(const double value) {this->val=value; return *this;}
        DataStorageUnit<Child> &operator=(const DataStorageUnit<Child> &other) { this->val = other.val; return *this;}
        DataStorageUnit<Child> &operator=(const DataStorageUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> DataStorageUnit<Child> &operator=(const DataStorageUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> DataStorageUnit<Child> &operator=(const DataStorageUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif