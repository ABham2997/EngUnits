#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>

#include "../../engunits/abstract/abstract_base.h"
#include "../../engunits/conversion/conversion_funcs.h"

namespace EngUnits::length{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class LengthUnit: public abstract::PhysicalUnit<LengthUnit<Child>, Child> {
    protected:
        using abstract::PhysicalUnit<LengthUnit<Child>, Child>::PhysicalUnit;

    public:
        LengthUnit<Child>(const LengthUnit<Child> &other) : abstract::PhysicalUnit<LengthUnit<Child>, Child>{other.val} {};
        LengthUnit<Child>(const LengthUnit<Child> &&other) : abstract::PhysicalUnit<LengthUnit<Child>, Child>{other.val} {};
        template <typename T>
        LengthUnit<Child>(const LengthUnit<T> &other) : abstract::PhysicalUnit<LengthUnit<Child>, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        LengthUnit<Child>(const LengthUnit<T> &&other) : abstract::PhysicalUnit<LengthUnit<Child>, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double abs_val() const override { return this->val; }
        double SI_val() const override { return this->val*Child::conversion; }

        LengthUnit<Child> &operator=(const double value) {this->val=value; return *this;}
        LengthUnit<Child> &operator=(const LengthUnit<Child> &other) { this->val = other.val; return *this;}
        LengthUnit<Child> &operator=(const LengthUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> LengthUnit<Child> &operator=(const LengthUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> LengthUnit<Child> &operator=(const LengthUnit<T> &&other) { this->val = other.val; return *this;}      

        Child operator*(const double value) const {return Child(this->val*value);}
        Child operator+(const double value) const {return Child(this->val+value);}
        Child operator-(const double value) const {return Child(this->val-value);}
        Child operator/(const double value) const {return Child(this->val/value);}
        template<typename T> double operator*(const LengthUnit<T> other) const {return this->val*Child(other).val;}
        template<typename T> double operator/(const LengthUnit<T> other) const {return this->val/Child(other).val;}
        template<typename C, typename G> double operator*(const abstract::PhysicalUnit<C,G> &other) const {return this->val*other.abs_val();}
        template<typename C, typename G> double operator/(const abstract::PhysicalUnit<C,G> &other) const {return this->val/other.abs_val();}
        template<typename T> Child operator+(const LengthUnit<T> other) const {return *this+Child(other).val;}
        template<typename T> Child operator-(const LengthUnit<T> other) const {return *this-Child(other).val;}
        LengthUnit<Child> &operator*=(const double value) {this->val*=value;return *this;}
        LengthUnit<Child> &operator+=(LengthUnit<Child> other) {this->val+=other.val;return *this;}
        LengthUnit<Child> &operator-=(LengthUnit<Child> other) {this->val-=other.val;return *this;}
        LengthUnit<Child> &operator/=(const double value) {this->val/=value;return *this;}
        
};
}

#endif