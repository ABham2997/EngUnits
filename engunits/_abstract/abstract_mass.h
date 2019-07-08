#ifndef __ENGUNITS_ABSTRACT_MASS_H
#define __ENGUNITS_ABSTRACT_MASS_H

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::mass{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class MassUnit: public abstract::PhysicalUnit<MassUnit, Child> {
    protected:
        using abstract::PhysicalUnit<MassUnit, Child>::PhysicalUnit;

    public:
        MassUnit<Child>(const MassUnit<Child> &other) : abstract::PhysicalUnit<MassUnit, Child>{other.val} {};
        MassUnit<Child>(const MassUnit<Child> &&other) : abstract::PhysicalUnit<MassUnit, Child>{other.val} {};
        template <typename T>
        MassUnit<Child>(const MassUnit<T> &other) : abstract::PhysicalUnit<MassUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        MassUnit<Child>(const MassUnit<T> &&other) : abstract::PhysicalUnit<MassUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double abs_val() const override { return this->val; }
        double SI_val() const override { return this->val*Child::conversion; }

        MassUnit<Child> &operator=(const double value) {this->val=value; return *this;}
        MassUnit<Child> &operator=(const MassUnit<Child> &other) { this->val = other.val; return *this;}
        MassUnit<Child> &operator=(const MassUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> MassUnit<Child> &operator=(const MassUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> MassUnit<Child> &operator=(const MassUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif