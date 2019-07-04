#ifndef __ENGUNITS_ABSTRACT_MASS_H
#define __ENGUNITS_ABSTRACT_MASS_H

#include "../../engunits/abstract/abstract_base.h"

namespace EngUnits::mass{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class MassUnit: public abstract::PhysicalUnit<MassUnit<Child>, Child> {
    protected:
        using abstract::PhysicalUnit<MassUnit<Child>, Child>::PhysicalUnit;

    public:
        MassUnit<Child>(const MassUnit<Child> &other) : abstract::PhysicalUnit<MassUnit<Child>, Child>{other.val} {};
        MassUnit<Child>(const MassUnit<Child> &&other) : abstract::PhysicalUnit<MassUnit<Child>, Child>{other.val} {};
        template <typename T>
        MassUnit<Child>(const MassUnit<T> &other) : abstract::PhysicalUnit<MassUnit<Child>, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        MassUnit<Child>(const MassUnit<T> &&other) : abstract::PhysicalUnit<MassUnit<Child>, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double abs_val() const override { return this->val; }
        double SI_val() const override { return this->val*Child::conversion; }

        MassUnit<Child> &operator=(const double value) {this->val=value; return *this;}
        MassUnit<Child> &operator=(const MassUnit<Child> &other) { this->val = other.val; return *this;}
        MassUnit<Child> &operator=(const MassUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> MassUnit<Child> &operator=(const MassUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> MassUnit<Child> &operator=(const MassUnit<T> &&other) { this->val = other.val; return *this;}      

        Child operator*(const double value) const {return Child(this->val*value);}
        Child operator+(const double value) const {return Child(this->val+value);}
        Child operator-(const double value) const {return Child(this->val-value);}
        Child operator/(const double value) const {return Child(this->val/value);}
        template<typename T> double operator*(const MassUnit<T> other) const {return this->val*Child(other).val;}
        template<typename T> double operator/(const MassUnit<T> other) const {return this->val/Child(other).val;}
        template<typename C, typename G> double operator*(const abstract::PhysicalUnit<C,G> &other) const {return this->val*other.abs_val();}
        template<typename C, typename G> double operator/(const abstract::PhysicalUnit<C,G> &other) const {return this->val/other.abs_val();}
        template<typename T> Child operator+(const MassUnit<T> other) const {return *this+Child(other).val;}
        template<typename T> Child operator-(const MassUnit<T> other) const {return *this-Child(other).val;}
        MassUnit<Child> &operator*=(const double value) {this->val*=value;return *this;}
        MassUnit<Child> &operator+=(MassUnit<Child> other) {this->val+=other.val;return *this;}
        MassUnit<Child> &operator-=(MassUnit<Child> other) {this->val-=other.val;return *this;}
        MassUnit<Child> &operator/=(const double value) {this->val/=value;return *this;}
        
};
}

#endif