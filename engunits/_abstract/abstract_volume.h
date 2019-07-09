#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include<iostream>
#include<string>

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::volume{
//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child> //TODO: constrain to children of this class
class Volume: public abstract::PhysicalUnit<Volume, Child> {
    protected:
        using abstract::PhysicalUnit<Volume, Child>::PhysicalUnit;

    public:
        Volume<Child>(const Volume<Child> &other) : abstract::PhysicalUnit<Volume, Child>{other.val} {};
        Volume<Child>(const Volume<Child> &&other) : abstract::PhysicalUnit<Volume, Child>{other.val} {};
        template <typename T>
        Volume<Child>(const Volume<T> &other) : abstract::PhysicalUnit<Volume, Child>{(conversion::unit_cast<T,Child>(other))} {};
        template<typename T>
        Volume<Child>(const Volume<T> &&other) : abstract::PhysicalUnit<Volume, Child>{(conversion::unit_cast<T,Child>(other))} {};

        double SI_val() const override { return this->val; } 
        double abs_val() const override { return this->val*Grandchild::conversion; };

        Volume<Child> &operator=(const double value) {this->val=value; return *this;}
        Volume<Child> &operator=(const Volume<Child> &other) { this->val = other.val; return *this;}
        Volume<Child> &operator=(const Volume<Child> &&other) { this->val = other.val; return *this;}     
        template<typename T> Volume<Child> &operator=(const Volume<T> &other) { this->val = other.val; return *this;}
        template<typename T> Volume<Child> &operator=(const Volume<T> &&other) { this->val = other.val; return *this;}
        
};
}

#endif