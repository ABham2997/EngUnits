#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>

#include "../../engunits/abstract/abstract_base.h"

namespace EngUnits::abstract{
//Child of this class is Grandchild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class LengthUnit: public PhysicalUnit<LengthUnit<Child>, Child> {
    protected:
        using PhysicalUnit<LengthUnit<Child>, Child>::PhysicalUnit;

    public:
        LengthUnit<Child>(const LengthUnit<Child> &other) : PhysicalUnit<LengthUnit<Child>, Child>{other.val} {};
        LengthUnit<Child>(const LengthUnit<Child> &&other) : PhysicalUnit<LengthUnit<Child>, Child>{other.val} {};
        template <typename T>
        LengthUnit<Child>(const LengthUnit<T> &other) : PhysicalUnit<LengthUnit<Child>, Child>{(other.SI_val()/Child::conversion)} {};
        template<typename T>
        LengthUnit<Child>(const LengthUnit<T> &&other) : PhysicalUnit<LengthUnit<Child>, Child>{(other.SI_val()/Child::conversion)} {};

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
        LengthUnit<Child> operator*(LengthUnit<Child> other) const { return LengthUnit<Child>(this->val*other.val);}
        LengthUnit<Child> operator+(LengthUnit<Child> other) const {return LengthUnit<Child>(this->val+other.val);}
        LengthUnit<Child> operator-(LengthUnit<Child> other) const {return LengthUnit<Child>(this->val-other.val);}
        LengthUnit<Child> operator/(LengthUnit<Child> other) const {return LengthUnit<Child>(this->val/other.val);}
        LengthUnit<Child> &operator*=(LengthUnit<Child> other) {this->val*=other.val;return *this;}
        LengthUnit<Child> &operator+=(LengthUnit<Child> other) {this->val+=other.val;return *this;}
        LengthUnit<Child> &operator-=(LengthUnit<Child> other) {this->val-=other.val;return *this;}
        LengthUnit<Child> &operator/=(LengthUnit<Child> other) {this->val/=other.val;return *this;}
        friend LengthUnit<Child> operator*(const double value, LengthUnit<Child> self) { return self * value; }
        friend LengthUnit<Child> operator+(const double value, LengthUnit<Child> self) { return self + value; }
        friend LengthUnit<Child> operator-(const double value, LengthUnit<Child> self) { return LengthUnit<Child>(value-self.val); }
        friend LengthUnit<Child> operator/(const double value, LengthUnit<Child> self) { return LengthUnit<Child>(value/self.val); }
        friend double &operator*=(double &value, LengthUnit<Child> self) { value*=self.val; return value; }
        friend double &operator-=(double &value, LengthUnit<Child> self) { value-=self.val; return value; }
        friend double &operator+=(double &value, LengthUnit<Child> self) { value+=self.val; return value; }
        friend double &operator/=(double &value, LengthUnit<Child> self) { value/=self.val; return value; }
        
        using ProxyComp = typename PhysicalUnit<LengthUnit<Child>, Child>::ProxyComp;
        friend ProxyComp operator==(const double value, LengthUnit<Child> self) { return LengthUnit<Child>(value) == self; }
        friend ProxyComp operator!=(const double value, LengthUnit<Child> self) {return LengthUnit<Child>(value) != self;}
        friend ProxyComp operator<=(const double value, LengthUnit<Child> self) {return LengthUnit<Child>(value) <= self;}
        friend ProxyComp operator>=(const double value, LengthUnit<Child> self) {return LengthUnit<Child>(value) >= self;}
        friend ProxyComp operator<(const double value, LengthUnit<Child> self) {return LengthUnit<Child>(value) < self;}
        friend ProxyComp operator>(const double value, LengthUnit<Child> self) {return LengthUnit<Child>(value) > self;}

};
}

#endif