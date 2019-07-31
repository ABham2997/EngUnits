#ifndef __ENGUNITS_ABSTRACT_FREQUENCY_H
#define __ENGUNITS_ABSTRACT_FREQUENCY_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::frequency{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class FrequencyUnit: public abstract::PhysicalUnit<FrequencyUnit, Child> {
    protected:
        using abstract::PhysicalUnit<FrequencyUnit, Child>::PhysicalUnit;

    public:
        FrequencyUnit<Child>(const FrequencyUnit<Child> &other) : abstract::PhysicalUnit<FrequencyUnit, Child>{other.val} {};
        FrequencyUnit<Child>(FrequencyUnit<Child> &&other) : abstract::PhysicalUnit<FrequencyUnit, Child>{other.val} {};
        template <typename T>
        FrequencyUnit<Child>(const FrequencyUnit<T> &other) : abstract::PhysicalUnit<FrequencyUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        FrequencyUnit<Child>(FrequencyUnit<T> &&other) : abstract::PhysicalUnit<FrequencyUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};

        virtual std::string symbol() const = 0;

        FrequencyUnit<Child> &operator=(double value) {this->val=value; return *this;}
        FrequencyUnit<Child> &operator=(const FrequencyUnit<Child> &other) { this->val = other.val; return *this;}
        FrequencyUnit<Child> &operator=(FrequencyUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> FrequencyUnit<Child> &operator=(const FrequencyUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> FrequencyUnit<Child> &operator=(FrequencyUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif