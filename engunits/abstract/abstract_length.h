#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>

#include "../../engunits/abstract/abstract_base.h"

namespace EngUnits::abstract{
template<typename Child> //TODO: constrain to children of this class
class LengthUnit: public PhysicalUnit<'L'> {
    protected:
        using PhysicalUnit<'L'>::PhysicalUnit;

    public:
        LengthUnit<Child>(const double value) : PhysicalUnit<'L'>{value} {};
        LengthUnit<Child>(const LengthUnit<Child> &other) : PhysicalUnit<'L'>{other.val} {};
        LengthUnit<Child>(const LengthUnit<Child> &&other) : PhysicalUnit<'L'>{other.val} {};
        template <typename T>
        LengthUnit<Child>(const LengthUnit<T> &other) : PhysicalUnit<'L'>{(other.SI_val()/Child::conversion)} {};
        template<typename T>
        LengthUnit<Child>(const LengthUnit<T> &&other) : PhysicalUnit<'L'>{(other.SI_val()/Child::conversion)} {};

        double abs_val() const override { return this->val; }
        double SI_val() const override { return this->val*Child::conversion; }

        LengthUnit<Child> &operator=(const double value) {this->val=value; return *this;}
        LengthUnit<Child> &operator=(const LengthUnit<Child> &other) { this->val = other.val; return *this;}
        LengthUnit<Child> &operator=(const LengthUnit<Child> &&other) { this->val = other.val; return *this;}        

        LengthUnit<Child> operator*(const double value) const { return LengthUnit<Child>(this->val*value);}
        LengthUnit<Child> operator+(const double value) const {return LengthUnit<Child>(this->val+value);}
        LengthUnit<Child> operator-(const double value) const {return LengthUnit<Child>(this->val-value);}
        LengthUnit<Child> operator/(const double value) const {return LengthUnit<Child>(this->val/value);}
        LengthUnit<Child> &operator*=(const double value) {this->val*=value;return *this;}
        LengthUnit<Child> &operator+=(const double value) {this->val+=value;return *this;}
        LengthUnit<Child> &operator-=(const double value) {this->val-=value;return *this;}
        LengthUnit<Child> &operator/=(const double value) {this->val/=value;return *this;}
        template<typename T> LengthUnit<Child> operator*(LengthUnit<T> other) const { return LengthUnit<Child>(this->val*other.val);}
        template<typename T> LengthUnit<Child> operator+(LengthUnit<T> other) const {return LengthUnit<Child>(this->val+other.val);}
        template<typename T> LengthUnit<Child> operator-(LengthUnit<T> other) const {return LengthUnit<Child>(this->val-other.val);}
        template<typename T> LengthUnit<Child> operator/(LengthUnit<T> other) const {return LengthUnit<Child>(this->val/other.val);}
        template<typename T> LengthUnit<Child> &operator*=(LengthUnit<T> other) {this->val*=other.val;return *this;}
        template<typename T> LengthUnit<Child> &operator+=(LengthUnit<T> other) {this->val+=other.val;return *this;}
        template<typename T> LengthUnit<Child> &operator-=(LengthUnit<T> other) {this->val-=other.val;return *this;}
        template<typename T> LengthUnit<Child> &operator/=(LengthUnit<T> other) {this->val/=other.val;return *this;}
        template<typename T> friend LengthUnit<Child> operator*(const double value, LengthUnit<T> self) { return self * value; }
        template<typename T> friend LengthUnit<Child> operator+(const double value, LengthUnit<T> self) { return self + value; }
        template<typename T> friend LengthUnit<Child> operator-(const double value, LengthUnit<T> self) { return LengthUnit<Child>(value-self.val); }
        template<typename T> friend LengthUnit<Child> operator/(const double value, LengthUnit<T> self) { return LengthUnit<Child>(value/self.val); }
        
        using ProxyComp = typename PhysicalUnit<'L'>::ProxyComp;
        friend ProxyComp operator==(const double value, LengthUnit<Child> self) { return LengthUnit<Child>(value) == self; }
        friend ProxyComp operator!=(const double value, LengthUnit<Child> self) {return LengthUnit<Child>(value) != self;}
        friend ProxyComp operator<=(const double value, LengthUnit<Child> self) {return LengthUnit<Child>(value) <= self;}
        friend ProxyComp operator>=(const double value, LengthUnit<Child> self) {return LengthUnit<Child>(value) >= self;}
        friend ProxyComp operator<(const double value, LengthUnit<Child> self) {return LengthUnit<Child>(value) < self;}
        friend ProxyComp operator>(const double value, LengthUnit<Child> self) {return LengthUnit<Child>(value) > self;}

        friend std::ostream &operator<<(std::ostream &os, const LengthUnit<Child> &self) {
            os << std::scientific << self.abs_val() << Child::suffix(); 
            return os;
        }
};
}

#endif