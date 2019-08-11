#ifndef __ENGUNITS_ABSTRACT_VOLUME_H
#define __ENGUNITS_ABSTRACT_VOLUME_H

#include<iostream>
#include<string>
#include<type_traits>

#include "../../engunits/_abstract/abstract_base.h"

namespace engunits::volume{
class cubicMeters; //forward declaration

//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child=cubicMeters> //TODO: constrain to children of this class
class VolumeUnit: public abstract::PhysicalUnit<VolumeUnit, Child> {
    protected:
        using abstract::PhysicalUnit<VolumeUnit, Child>::PhysicalUnit;

    public:
        using SI_type = cubicMeters;

        VolumeUnit<Child>(const VolumeUnit<Child> &other) : abstract::PhysicalUnit<VolumeUnit, Child>{other.val} {};
        VolumeUnit<Child>(VolumeUnit<Child> &&other) : abstract::PhysicalUnit<VolumeUnit, Child>{other.val} {};
        template <typename T>
        VolumeUnit<Child>(const VolumeUnit<T> &other) : abstract::PhysicalUnit<VolumeUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        VolumeUnit<Child>(VolumeUnit<T> &&other) : abstract::PhysicalUnit<VolumeUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        VolumeUnit<Child> &operator=(double value) {this->val=value; return *this;}
        VolumeUnit<Child> &operator=(const VolumeUnit<Child> &other) { this->val = other.val; return *this;}
        VolumeUnit<Child> &operator=(VolumeUnit<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> VolumeUnit<Child> &operator=(const VolumeUnit<T> &other) { this->val = other.val; return *this;}
        template<typename T> VolumeUnit<Child> &operator=(VolumeUnit<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif