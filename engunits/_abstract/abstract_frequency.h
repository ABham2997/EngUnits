#ifndef __ENGUNITS_ABSTRACT_FREQUENCY_H
#define __ENGUNITS_ABSTRACT_FREQUENCY_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::frequency{
class Herts; //forward declaration

//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child=Herts> //TODO: constrain to children of this class
class FrequencyUnit: public abstract::PhysicalUnit<FrequencyUnit, Child> {
    protected:
        using abstract::PhysicalUnit<FrequencyUnit, Child>::PhysicalUnit;

    public:
        using SI_type = Herts;

        FrequencyUnit<Child>(const FrequencyUnit<Child> &other) : abstract::PhysicalUnit<FrequencyUnit, Child>{other.val} {};
        FrequencyUnit<Child>(FrequencyUnit<Child> &&other) : abstract::PhysicalUnit<FrequencyUnit, Child>{other.val} {};
        template <typename T>
        FrequencyUnit<Child>(const FrequencyUnit<T> &other) : abstract::PhysicalUnit<FrequencyUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        FrequencyUnit<Child>(FrequencyUnit<T> &&other) : abstract::PhysicalUnit<FrequencyUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        FrequencyUnit<Child> &operator=(double value) {this->val=value; return *this;}
        FrequencyUnit<Child> &operator=(const FrequencyUnit<Child> &other) { this->val = other.val; return *this;}
        FrequencyUnit<Child> &operator=(FrequencyUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> FrequencyUnit<Child> &operator=(const FrequencyUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> FrequencyUnit<Child> &operator=(FrequencyUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif