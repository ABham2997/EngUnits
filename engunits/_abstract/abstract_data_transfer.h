#ifndef __ENGUNITS_ABSTRACT_DATA_TRANSFER_H
#define __ENGUNITS_ABSTRACT_DATA_TRANSFER_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::data_transfer{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class DataTransferUnit: public abstract::PhysicalUnit<DataTransferUnit, Child> {
    protected:
        using abstract::PhysicalUnit<DataTransferUnit, Child>::PhysicalUnit;

    public:
        DataTransferUnit<Child>(const DataTransferUnit<Child> &other) : abstract::PhysicalUnit<DataTransferUnit, Child>{other.val} {};
        DataTransferUnit<Child>(const DataTransferUnit<Child> &&other) : abstract::PhysicalUnit<DataTransferUnit, Child>{other.val} {};
        template <typename T>
        DataTransferUnit<Child>(const DataTransferUnit<T> &other) : abstract::PhysicalUnit<DataTransferUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        DataTransferUnit<Child>(const DataTransferUnit<T> &&other) : abstract::PhysicalUnit<DataTransferUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};

        virtual std::string symbol() const = 0;

        DataTransferUnit<Child> &operator=(const double value) {this->val=value; return *this;}
        DataTransferUnit<Child> &operator=(const DataTransferUnit<Child> &other) { this->val = other.val; return *this;}
        DataTransferUnit<Child> &operator=(const DataTransferUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> DataTransferUnit<Child> &operator=(const DataTransferUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> DataTransferUnit<Child> &operator=(const DataTransferUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif