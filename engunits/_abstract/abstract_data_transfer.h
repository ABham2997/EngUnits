#ifndef __ENGUNITS_ABSTRACT_DATA_TRANSFER_H
#define __ENGUNITS_ABSTRACT_DATA_TRANSFER_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::data_transfer{
class megabytePerSecond; //forward declaration

//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child=megabytePerSecond> //TODO: constrain to children of this class
class DataTransferUnit: public abstract::PhysicalUnit<DataTransferUnit, Child> {
    protected:
        using abstract::PhysicalUnit<DataTransferUnit, Child>::PhysicalUnit;

    public:
        using SI_type = megabytePerSecond;

        DataTransferUnit<Child>(const DataTransferUnit<Child> &other) : abstract::PhysicalUnit<DataTransferUnit, Child>{other.val} {};
        DataTransferUnit<Child>(DataTransferUnit<Child> &&other) : abstract::PhysicalUnit<DataTransferUnit, Child>{other.val} {};
        template <typename T>
        DataTransferUnit<Child>(const DataTransferUnit<T> &other) : abstract::PhysicalUnit<DataTransferUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        DataTransferUnit<Child>(DataTransferUnit<T> &&other) : abstract::PhysicalUnit<DataTransferUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        Child &operator=(double value) {this->val=value; return *static_cast<Child*>(this);}
        Child &operator=(const DataTransferUnit<Child> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        Child &operator=(DataTransferUnit<Child> &&other) { this->val = other.val; return *static_cast<Child*>(this);}     
        template<typename T> 
        Child &operator=(const DataTransferUnit<T> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        template<typename T> 
        Child &operator=(DataTransferUnit<T> &&other) { this->val = other.val; return *static_cast<Child*>(this);}
        
};
}

#endif