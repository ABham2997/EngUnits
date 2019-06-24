#ifndef __ENGUNITS_ABSTRACT_LENGTH_H
#define __ENGUNITS_ABSTRACT_LENGTH_H

#include "../../engunits/abstract/abstract_base.h"

namespace EngUnits{

class LengthUnit: public PhysicalUnit<> {

    protected:
        LengthUnit() : PhysicalUnit<>{} {};
        LengthUnit(const double value) : PhysicalUnit<>{value} {};

    public:
        virtual double true_val() const {};

        virtual LengthUnit &operator=(const double value) {this->val=value; return *this;}
        virtual LengthUnit &operator=(const LengthUnit &other) { this->val = other.val; return *this;}
        virtual operator bool() const {return (this->val);}
        virtual operator double() const { return (this->val); }

        virtual LengthUnit operator*(const double value) const { return LengthUnit(this->val*value);}
        virtual LengthUnit operator+(const double value) const {return LengthUnit(this->val+value);}
        virtual LengthUnit operator-(const double value) const {return LengthUnit(this->val-value);}
        virtual LengthUnit operator/(const double value) const {return LengthUnit(this->val/value);}
        virtual LengthUnit &operator*=(const double value) {this->val*=value;return *this;}
        virtual LengthUnit &operator+=(const double value) {this->val+=value;return *this;}
        virtual LengthUnit &operator-=(const double value) {this->val-=value;return *this;}
        virtual LengthUnit &operator/=(const double value) {this->val/=value;return *this;}
        virtual LengthUnit operator*(LengthUnit other) const { return LengthUnit(this->val*other.val);}
        virtual LengthUnit operator+(LengthUnit other) const {return LengthUnit(this->val+other.val);}
        virtual LengthUnit operator-(LengthUnit other) const {return LengthUnit(this->val-other.val);}
        virtual LengthUnit operator/(LengthUnit other) const {return LengthUnit(this->val/other.val);}
        virtual LengthUnit &operator*=(LengthUnit other) {this->val*=other.val;return *this;}
        virtual LengthUnit &operator+=(LengthUnit other) {this->val+=other.val;return *this;}
        virtual LengthUnit &operator-=(LengthUnit other) {this->val-=other.val;return *this;}
        virtual LengthUnit &operator/=(LengthUnit other) {this->val/=other.val;return *this;}
        friend LengthUnit operator*(const double value, LengthUnit self) { return self * value; }
        friend LengthUnit operator+(const double value, LengthUnit self) { return self + value; }
        friend LengthUnit operator-(const double value, LengthUnit self) { return LengthUnit(value-self.val); }
        friend LengthUnit operator/(const double value, LengthUnit self) { return LengthUnit(value/self.val); }

        virtual void operator++() {this->val++;}
        virtual void operator++(int i) { ++this->val; }
        virtual void operator--() {this->val--;}
        virtual void operator--(int i) { --this->val; }

        virtual ProxyComp operator==(const double value) {return ProxyComp(value, (this->val)==value);}
        virtual ProxyComp operator!=(const double value) {return ProxyComp(value, (this->val)!=value);}
        virtual ProxyComp operator<=(const double value) {return ProxyComp(value, (this->val)<=value);}
        virtual ProxyComp operator>=(const double value) {return ProxyComp(value, (this->val)>=value);}
        virtual ProxyComp operator<(const double value) {return ProxyComp(value, (this->val)<value);}
        virtual ProxyComp operator>(const double value) {return ProxyComp(value, (this->val)>value);}
        virtual ProxyComp operator==(const LengthUnit &other) { return *this == other.val; }
        virtual ProxyComp operator!=(const LengthUnit &other) {return *this!=other.val;}
        virtual ProxyComp operator<=(const LengthUnit &other) {return *this<=other.val;}
        virtual ProxyComp operator>=(const LengthUnit &other) {return *this>=other.val;}
        virtual ProxyComp operator<(const LengthUnit &other) {return *this<other.val;}
        virtual ProxyComp operator>(const LengthUnit &other) {return *this>other.val;}
        virtual ProxyComp operator==(const ProxyComp other) {return *this==other.val;}
        virtual ProxyComp operator!=(const ProxyComp other) {return *this!=other.val;}
        virtual ProxyComp operator<=(const ProxyComp other) {return *this<=other.val;}
        virtual ProxyComp operator>=(const ProxyComp other) {return *this>=other.val;}
        virtual ProxyComp operator<(const ProxyComp other) {return *this<other.val;}
        virtual ProxyComp operator>(const ProxyComp other) {return *this>other.val;}
        friend ProxyComp operator==(const double value, LengthUnit self) { return LengthUnit(value) == self; }
        friend ProxyComp operator!=(const double value, LengthUnit self) {return LengthUnit(value) != self;}
        friend ProxyComp operator<=(const double value, LengthUnit self) {return LengthUnit(value) <= self;}
        friend ProxyComp operator>=(const double value, LengthUnit self) {return LengthUnit(value) >= self;}
        friend ProxyComp operator<(const double value, LengthUnit self) {return LengthUnit(value) < self;}
        friend ProxyComp operator>(const double value, LengthUnit self) {return LengthUnit(value) > self;}

};
}

#endif