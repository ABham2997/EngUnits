#ifndef __ENGUNITS_ABSTRACT_TIME_H
#define __ENGUNITS_ABSTRACT_TIME_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::time{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class TimeUnit: public abstract::PhysicalUnit<TimeUnit, Child> {
    protected:
        using abstract::PhysicalUnit<TimeUnit, Child>::PhysicalUnit;

    public:
        TimeUnit<Child>(const TimeUnit<Child> &other) : abstract::PhysicalUnit<TimeUnit, Child>{other.val} {};
        TimeUnit<Child>(const TimeUnit<Child> &&other) : abstract::PhysicalUnit<TimeUnit, Child>{other.val} {};
        template <typename T>
        TimeUnit<Child>(const TimeUnit<T> &other) : abstract::PhysicalUnit<TimeUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        TimeUnit<Child>(const TimeUnit<T> &&other) : abstract::PhysicalUnit<TimeUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double SI_val() const override { return this->val; } 
        double abs_val() const override { return this->val*Grandchild::conversion; };

        TimeUnit<Child> &operator=(const double value) {this->val=value; return *this;}
        TimeUnit<Child> &operator=(const TimeUnit<Child> &other) { this->val = other.val; return *this;}
        TimeUnit<Child> &operator=(const TimeUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> TimeUnit<Child> &operator=(const TimeUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> TimeUnit<Child> &operator=(const TimeUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif