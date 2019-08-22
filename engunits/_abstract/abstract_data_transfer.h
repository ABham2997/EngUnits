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
        using si_t = megabytePerSecond;

        constexpr DataTransferUnit<Child>(const DataTransferUnit<Child> &other) : abstract::PhysicalUnit<DataTransferUnit, Child>{other.val} {};
        constexpr DataTransferUnit<Child>(DataTransferUnit<Child> &&other) : abstract::PhysicalUnit<DataTransferUnit, Child>{other.val} {};
        template <typename T>
        constexpr DataTransferUnit<Child>(const DataTransferUnit<T> &other) : abstract::PhysicalUnit<DataTransferUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        constexpr DataTransferUnit<Child>(DataTransferUnit<T> &&other) : abstract::PhysicalUnit<DataTransferUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        Child &operator=(const double &value) {this->val=value; return *static_cast<Child*>(this);}
        Child &operator=(const DataTransferUnit<Child> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        Child &operator=(DataTransferUnit<Child> &&other) { this->val = other.val; return *static_cast<Child*>(this);}  
        
};

}

#endif