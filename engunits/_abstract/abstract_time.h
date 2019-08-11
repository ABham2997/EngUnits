#ifndef __ENGUNITS_ABSTRACT_TIME_H
#define __ENGUNITS_ABSTRACT_TIME_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::time{
class seconds; //forward declaration

//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child=seconds> //TODO: constrain to children of this class
class TimeUnit: public abstract::PhysicalUnit<TimeUnit, Child> {
    protected:
        using abstract::PhysicalUnit<TimeUnit, Child>::PhysicalUnit;

    public:
        using SI_type = seconds;

        TimeUnit<Child>(const TimeUnit<Child> &other) : abstract::PhysicalUnit<TimeUnit, Child>{other.val} {};
        TimeUnit<Child>(TimeUnit<Child> &&other) : abstract::PhysicalUnit<TimeUnit, Child>{other.val} {};
        template <typename T>
        TimeUnit<Child>(const TimeUnit<T> &other) : abstract::PhysicalUnit<TimeUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        TimeUnit<Child>(TimeUnit<T> &&other) : abstract::PhysicalUnit<TimeUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        TimeUnit<Child> &operator=(double value) {this->val=value; return *this;}
        TimeUnit<Child> &operator=(const TimeUnit<Child> &other) { this->val = other.val; return *this;}
        TimeUnit<Child> &operator=(TimeUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> TimeUnit<Child> &operator=(const TimeUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> TimeUnit<Child> &operator=(TimeUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif