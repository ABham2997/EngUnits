#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::data_transfer{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class DataTransfer: public abstract::PhysicalUnit<DataTransfer, Child> {
    protected:
        using abstract::PhysicalUnit<DataTransfer, Child>::PhysicalUnit;

    public:
        DataTransfer<Child>(const DataTransfer<Child> &other) : abstract::PhysicalUnit<DataTransfer, Child>{other.val} {};
        DataTransfer<Child>(const DataTransfer<Child> &&other) : abstract::PhysicalUnit<DataTransfer, Child>{other.val} {};
        template <typename T>
        DataTransfer<Child>(const DataTransfer<T> &other) : abstract::PhysicalUnit<DataTransfer, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        DataTransfer<Child>(const DataTransfer<T> &&other) : abstract::PhysicalUnit<DataTransfer, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double SI_val() const override { return this->val; } 
        double abs_val() const override { return this->val*Grandchild::conversion; };

        DataTransfer<Child> &operator=(const double value) {this->val=value; return *this;}
        DataTransfer<Child> &operator=(const DataTransfer<Child> &other) { this->val = other.val; return *this;}
        DataTransfer<Child> &operator=(const DataTransfer<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> DataTransfer<Child> &operator=(const DataTransfer<T> &other) { this->val = other.val; return *this;}
        template<typename T> DataTransfer<Child> &operator=(const DataTransfer<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif