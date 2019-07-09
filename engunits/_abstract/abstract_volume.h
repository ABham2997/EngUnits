#ifndef __ENGUNITS_ABSTRACT_VOLUME_H
#define __ENGUNITS_ABSTRACT_VOLUME_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::volume{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class VolumeUnit: public abstract::PhysicalUnit<VolumeUnit, Child> {
    protected:
        using abstract::PhysicalUnit<VolumeUnit, Child>::PhysicalUnit;

    public:
        VolumeUnit<Child>(const VolumeUnit<Child> &other) : abstract::PhysicalUnit<VolumeUnit, Child>{other.val} {};
        VolumeUnit<Child>(const VolumeUnit<Child> &&other) : abstract::PhysicalUnit<VolumeUnit, Child>{other.val} {};
        template <typename T>
        VolumeUnit<Child>(const VolumeUnit<T> &other) : abstract::PhysicalUnit<VolumeUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        VolumeUnit<Child>(const VolumeUnit<T> &&other) : abstract::PhysicalUnit<VolumeUnit, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double si_val() const override { return this->val; } 
        double abs_val() const override { return this->val*Grandchild::conversion; };

        VolumeUnit<Child> &operator=(const double value) {this->val=value; return *this;}
        VolumeUnit<Child> &operator=(const VolumeUnit<Child> &other) { this->val = other.val; return *this;}
        VolumeUnit<Child> &operator=(const VolumeUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> VolumeUnit<Child> &operator=(const VolumeUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> VolumeUnit<Child> &operator=(const VolumeUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif