#ifndef __ENGUNITS_ABSTRACT_DATA_STORAGE_H
#define __ENGUNITS_ABSTRACT_DATA_STORAGE_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::data_storage{
class byte; //forward declaration

//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child=byte> //TODO: constrain to children of this class
class DataStorageUnit: public abstract::PhysicalUnit<DataStorageUnit, Child> {
    protected:
        using abstract::PhysicalUnit<DataStorageUnit, Child>::PhysicalUnit;

    public:
        constexpr DataStorageUnit<Child>(const DataStorageUnit<Child> &other) : abstract::PhysicalUnit<DataStorageUnit, Child>{other.val} {};
        constexpr DataStorageUnit<Child>(DataStorageUnit<Child> &&other) : abstract::PhysicalUnit<DataStorageUnit, Child>{other.val} {};
        template <typename T>
        constexpr DataStorageUnit<Child>(const DataStorageUnit<T> &other) : abstract::PhysicalUnit<DataStorageUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        constexpr DataStorageUnit<Child>(DataStorageUnit<T> &&other) : abstract::PhysicalUnit<DataStorageUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        Child &operator=(double value) {this->val=value; return *static_cast<Child*>(this);}
        Child &operator=(const DataStorageUnit<Child> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        Child &operator=(DataStorageUnit<Child> &&other) { this->val = other.val; return *static_cast<Child*>(this);}     
        template<typename T> 
        Child &operator=(const DataStorageUnit<T> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        template<typename T> 
        Child &operator=(DataStorageUnit<T> &&other) { this->val = other.val; return *static_cast<Child*>(this);}
        
};
}

#endif