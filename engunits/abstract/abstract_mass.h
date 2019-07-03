#ifndef __ENGUNITS_ABSTRACT_MASS_H
#define __ENGUNITS_ABSTRACT_MASS_H

#include "../../engunits/abstract/abstract_base.h"

namespace EngUnits::abstract{
//Child of this class is Grandchild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class MassUnit: public PhysicalUnit<MassUnit<Child>, Child> {
    protected:
        using PhysicalUnit<MassUnit<Child>, Child>::PhysicalUnit;

    public:
        MassUnit<Child>(const MassUnit<Child> &other) : PhysicalUnit<MassUnit<Child>, Child>{other.val} {};
        MassUnit<Child>(const MassUnit<Child> &&other) : PhysicalUnit<MassUnit<Child>, Child>{other.val} {};
        template <typename T>
        MassUnit<Child>(const MassUnit<T> &other) : PhysicalUnit<MassUnit<Child>, Child>{(other.SI_val()/Child::conversion)} {};
        template<typename T>
        MassUnit<Child>(const MassUnit<T> &&other) : PhysicalUnit<MassUnit<Child>, Child>{(other.SI_val()/Child::conversion)} {};

        double abs_val() const override { return this->val; }
        double SI_val() const override { return this->val*Child::conversion; }

        MassUnit<Child> &operator=(const double value) {this->val=value; return *this;}
        MassUnit<Child> &operator=(const MassUnit<Child> &other) { this->val = other.val; return *this;}
        MassUnit<Child> &operator=(const MassUnit<Child> &&other) { this->val = other.val; return *this;}        

        MassUnit<Child> operator*(const double value) const { return MassUnit<Child>(this->val*value);}
        MassUnit<Child> operator+(const double value) const {return MassUnit<Child>(this->val+value);}
        MassUnit<Child> operator-(const double value) const {return MassUnit<Child>(this->val-value);}
        MassUnit<Child> operator/(const double value) const {return MassUnit<Child>(this->val/value);}
        MassUnit<Child> &operator*=(const double value) {this->val*=value;return *this;}
        MassUnit<Child> &operator+=(const double value) {this->val+=value;return *this;}
        MassUnit<Child> &operator-=(const double value) {this->val-=value;return *this;}
        MassUnit<Child> &operator/=(const double value) {this->val/=value;return *this;}
        template<typename T> MassUnit<Child> operator*(MassUnit<T> other) const { return MassUnit<Child>(this->val*other.val);}
        template<typename T> MassUnit<Child> operator+(MassUnit<T> other) const {return MassUnit<Child>(this->val+other.val);}
        template<typename T> MassUnit<Child> operator-(MassUnit<T> other) const {return MassUnit<Child>(this->val-other.val);}
        template<typename T> MassUnit<Child> operator/(MassUnit<T> other) const {return MassUnit<Child>(this->val/other.val);}
        template<typename T> MassUnit<Child> &operator*=(MassUnit<T> other) {this->val*=other.val;return *this;}
        template<typename T> MassUnit<Child> &operator+=(MassUnit<T> other) {this->val+=other.val;return *this;}
        template<typename T> MassUnit<Child> &operator-=(MassUnit<T> other) {this->val-=other.val;return *this;}
        template<typename T> MassUnit<Child> &operator/=(MassUnit<T> other) {this->val/=other.val;return *this;}
        template<typename T> friend MassUnit<Child> operator*(const double value, MassUnit<T> self) { return self * value; }
        template<typename T> friend MassUnit<Child> operator+(const double value, MassUnit<T> self) { return self + value; }
        template<typename T> friend MassUnit<Child> operator-(const double value, MassUnit<T> self) { return MassUnit<Child>(value-self.val); }
        template<typename T> friend MassUnit<Child> operator/(const double value, MassUnit<T> self) { return MassUnit<Child>(value/self.val); }
        
        using ProxyComp = typename PhysicalUnit<MassUnit<Child>, Child>::ProxyComp;
        friend ProxyComp operator==(const double value, MassUnit<Child> self) { return MassUnit<Child>(value) == self; }
        friend ProxyComp operator!=(const double value, MassUnit<Child> self) {return MassUnit<Child>(value) != self;}
        friend ProxyComp operator<=(const double value, MassUnit<Child> self) {return MassUnit<Child>(value) <= self;}
        friend ProxyComp operator>=(const double value, MassUnit<Child> self) {return MassUnit<Child>(value) >= self;}
        friend ProxyComp operator<(const double value, MassUnit<Child> self) {return MassUnit<Child>(value) < self;}
        friend ProxyComp operator>(const double value, MassUnit<Child> self) {return MassUnit<Child>(value) > self;}

};
}


#endif