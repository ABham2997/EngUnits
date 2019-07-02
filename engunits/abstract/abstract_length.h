#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include "../../engunits/abstract/abstract_base.h"

namespace EngUnits::length{

class LengthUnit: public core::PhysicalUnit<> {
    
    protected:
        using core::PhysicalUnit<>::PhysicalUnit;

    public:
        explicit LengthUnit(const LengthUnit &other) : core::PhysicalUnit<>{other.true_val(), other.get_conversion()} {};
        explicit LengthUnit(const LengthUnit &&other) : core::PhysicalUnit<>{other.true_val(), other.get_conversion()} {};

        virtual double get_conversion() const override { return 1; }
        virtual std::string get_suffix() const override { return ""; }

        LengthUnit &operator=(const double value) {this->val=value*get_conversion(); return *this;}
        LengthUnit &operator=(const LengthUnit &other) { this->val = other.true_val()*get_conversion(); return *this;}
        LengthUnit &operator=(const LengthUnit &&other) { this->val = other.true_val()*get_conversion(); return *this;}        
        operator bool() const {return (this->val);}

        LengthUnit operator*(const double value) const { return LengthUnit(this->val*value);}
        LengthUnit operator+(const double value) const {return LengthUnit(this->val+value);}
        LengthUnit operator-(const double value) const {return LengthUnit(this->val-value);}
        LengthUnit operator/(const double value) const {return LengthUnit(this->val/value);}
        LengthUnit &operator*=(const double value) {this->val*=value;return *this;}
        LengthUnit &operator+=(const double value) {this->val+=value;return *this;}
        LengthUnit &operator-=(const double value) {this->val-=value;return *this;}
        LengthUnit &operator/=(const double value) {this->val/=value;return *this;}
        LengthUnit operator*(LengthUnit other) const { return LengthUnit(this->val*other.val);}
        LengthUnit operator+(LengthUnit other) const {return LengthUnit(this->val+other.val);}
        LengthUnit operator-(LengthUnit other) const {return LengthUnit(this->val-other.val);}
        LengthUnit operator/(LengthUnit other) const {return LengthUnit(this->val/other.val);}
        LengthUnit &operator*=(LengthUnit other) {this->val*=other.val;return *this;}
        LengthUnit &operator+=(LengthUnit other) {this->val+=other.val;return *this;}
        LengthUnit &operator-=(LengthUnit other) {this->val-=other.val;return *this;}
        LengthUnit &operator/=(LengthUnit other) {this->val/=other.val;return *this;}
        friend LengthUnit operator*(const double value, LengthUnit self) { return self * value; }
        friend LengthUnit operator+(const double value, LengthUnit self) { return self + value; }
        friend LengthUnit operator-(const double value, LengthUnit self) { return LengthUnit(value-self.val); }
        friend LengthUnit operator/(const double value, LengthUnit self) { return LengthUnit(value/self.val); }

        void operator++() {this->val++;}
        void operator++(int i) { ++this->val; }
        void operator--() {this->val--;}
        void operator--(int i) { --this->val; }

        ProxyComp operator==(const double value) {return ProxyComp(value, (this->val)==value);}
        ProxyComp operator!=(const double value) {return ProxyComp(value, (this->val)!=value);}
        ProxyComp operator<=(const double value) {return ProxyComp(value, (this->val)<=value);}
        ProxyComp operator>=(const double value) {return ProxyComp(value, (this->val)>=value);}
        ProxyComp operator<(const double value) {return ProxyComp(value, (this->val)<value);}
        ProxyComp operator>(const double value) {return ProxyComp(value, (this->val)>value);}
        ProxyComp operator==(const LengthUnit &other) { return *this == other.val; }
        ProxyComp operator!=(const LengthUnit &other) {return *this!=other.val;}
        ProxyComp operator<=(const LengthUnit &other) {return *this<=other.val;}
        ProxyComp operator>=(const LengthUnit &other) {return *this>=other.val;}
        ProxyComp operator<(const LengthUnit &other) {return *this<other.val;}
        ProxyComp operator>(const LengthUnit &other) {return *this>other.val;}
        ProxyComp operator==(const ProxyComp other) {return *this==other.val;}
        ProxyComp operator!=(const ProxyComp other) {return *this!=other.val;}
        ProxyComp operator<=(const ProxyComp other) {return *this<=other.val;}
        ProxyComp operator>=(const ProxyComp other) {return *this>=other.val;}
        ProxyComp operator<(const ProxyComp other) {return *this<other.val;}
        ProxyComp operator>(const ProxyComp other) {return *this>other.val;}
        friend ProxyComp operator==(const double value, LengthUnit self) { return LengthUnit(value) == self; }
        friend ProxyComp operator!=(const double value, LengthUnit self) {return LengthUnit(value) != self;}
        friend ProxyComp operator<=(const double value, LengthUnit self) {return LengthUnit(value) <= self;}
        friend ProxyComp operator>=(const double value, LengthUnit self) {return LengthUnit(value) >= self;}
        friend ProxyComp operator<(const double value, LengthUnit self) {return LengthUnit(value) < self;}
        friend ProxyComp operator>(const double value, LengthUnit self) {return LengthUnit(value) > self;}

};
}

#endif