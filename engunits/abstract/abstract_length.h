#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include "../../engunits/abstract/abstract_base.h"

namespace EngUnits::length{
template<typename Child> //TODO: constrain to children of this class
class LengthUnit: public core::PhysicalUnit<'L'> {
    public:
        using core::PhysicalUnit<'L'>::PhysicalUnit;
        LengthUnit<Child>(const double value) : PhysicalUnit<'L'>{value, Child::conversion} {};
        template <typename T>
        LengthUnit<Child>(const LengthUnit<T> &other) : core::PhysicalUnit<'L'>{other.true_val(), other.Child::conversion} {};
        template<typename T>
        LengthUnit<Child>(const LengthUnit<T> &&other) : core::PhysicalUnit<'L'>{other.true_val(), other.Child::conversion} {};

        double true_val() const override { return this->val / Child::conversion; }

        LengthUnit<Child> &operator=(const double value) {this->val=value*Child::conversion; return *this;}
        LengthUnit<Child> &operator=(const LengthUnit<Child> &other) { this->val = other.true_val()*Child::conversion; return *this;}
        LengthUnit<Child> &operator=(const LengthUnit<Child> &&other) { this->val = other.true_val()*Child::conversion; return *this;}        
        operator bool() const {return (this->val);}

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

        friend ProxyComp operator==(const double value, LengthUnit<Child> self) { return LengthUnit<Child>(value) == self; }
        friend ProxyComp operator!=(const double value, LengthUnit<Child> self) {return LengthUnit<Child>(value) != self;}
        friend ProxyComp operator<=(const double value, LengthUnit<Child> self) {return LengthUnit<Child>(value) <= self;}
        friend ProxyComp operator>=(const double value, LengthUnit<Child> self) {return LengthUnit<Child>(value) >= self;}
        friend ProxyComp operator<(const double value, LengthUnit<Child> self) {return LengthUnit<Child>(value) < self;}
        friend ProxyComp operator>(const double value, LengthUnit<Child> self) {return LengthUnit<Child>(value) > self;}

        friend std::ostream &operator<<(std::ostream &os, const LengthUnit<Child> &self) {
            os << std::scientific << self.true_val() << Child::suffix; 
            return os;
        }
};
}

#endif