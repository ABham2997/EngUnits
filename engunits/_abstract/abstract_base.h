#ifndef __ENGUNITS_ABSTRACT_BASE_H
#define __ENGUNITS_ABSTRACT_BASE_H

#include<string>
#include<iostream>
#include<cmath>

#include "../../engunits/_conversion/conversion_funcs.h"

namespace engunits::abstract{
template<template<typename> typename Child, typename Grandchild>
class PhysicalUnit{
    private:
        template <typename S> friend double conversion::double_cast(S arg);

        class ProxyComp {
            public:
                double val;
                bool b;

                ProxyComp(const double value, bool bb) : val{value}, b{bb} {};
        
                operator bool() { return this->b; }

                ProxyComp &operator==(const double value) {b=(this->val==value && b) ; this->val=value; return *this; }
                ProxyComp &operator!=(const double value) {b=(this->val!=value && b) ; this->val=value; return *this;}
                ProxyComp &operator<=(const double value) {b=(this->val<=value && b) ; this->val=value; return *this;}
                ProxyComp &operator>=(const double value) {b=(this->val>=value && b) ; this->val=value; return *this;}
                ProxyComp &operator<(const double value) {b=(this->val<value && b) ; this->val=value; return *this;}
                ProxyComp &operator>(const double value) {b=(this->val>value && b) ; this->val=value; return *this;}

                ProxyComp &operator==(const Grandchild other) { *this == other.val; return *this;}
                ProxyComp &operator!=(const Grandchild other) { *this != other.val; return *this;}
                ProxyComp &operator<=(const Grandchild other) { *this <= other.val; return *this;}
                ProxyComp &operator>=(const Grandchild other) { *this >= other.val; return *this;}
                ProxyComp &operator<(const Grandchild other) { *this < other.val; return *this;}
                ProxyComp &operator>(const Grandchild other) { *this > other.val; return *this;}

                template<typename T> ProxyComp &operator==(const Child<T> other) { *this == Grandchild{other}; return *this;}
                template<typename T> ProxyComp &operator!=(const Child<T> other) { *this != Grandchild{other}; return *this;}
                template<typename T> ProxyComp &operator<=(const Child<T> other) { *this <= Grandchild{other}; return *this;}
                template<typename T> ProxyComp &operator>=(const Child<T> other) { *this >= Grandchild{other}; return *this;}
                template<typename T> ProxyComp &operator<(const Child<T> other) { *this < Grandchild{other}; return *this;}
                template<typename T> ProxyComp &operator>(const Child<T> other) { *this > Grandchild{other}; return *this;}
                
                friend ProxyComp &operator==(const double value, ProxyComp &&self){ 
                    self.b=(value==self.val && self.b); self.val=value; return self;}
                friend ProxyComp &operator!=(const double value, ProxyComp &&self){ 
                    self.b=(value!=self.val && self.b); self.val=value; return self;}
                friend ProxyComp &operator<=(const double value, ProxyComp &&self){ 
                    self.b=(value<=self.val && self.b); self.val=value; return self;}
                friend ProxyComp &operator>=(const double value, ProxyComp &&self){ 
                    self.b=(value>=self.val && self.b); self.val=value; return self;}
                friend ProxyComp &operator<(const double value, ProxyComp &&self){ 
                    self.b=(value<self.val && self.b); self.val=value; return self;}
                friend ProxyComp &operator>(const double value, ProxyComp &&self){ 
                    self.b=(value>self.val && self.b); self.val=value; return self;}

                friend std::ostream &operator<<(std::ostream &os, const ProxyComp &self) {
                    os << self.val << ":" << (self.b?"true":"false");
                    return os;
                }
        };

    protected:
        double val;

    public:
        PhysicalUnit<Child, Grandchild>():val{} {};
        PhysicalUnit<Child, Grandchild>(const double value): val{value} {};
        PhysicalUnit<Child, Grandchild>(const ProxyComp other) : val{other.val} {};

        virtual double SI_val() const = 0; //this function ensures this base class remains purely abstract
        virtual double abs_val() const = 0;

        void operator++() {this->val++;}
        void operator++(int i) { ++this->val; }
        void operator--() {this->val--;}
        void operator--(int i) { --this->val; }
        operator bool() const {return (this->val);}
        double operator^(const double value) const { return std::pow(this->val,value); }
        int operator%(const int value) const { return int(this->val) % value; }

        Grandchild operator*(const double value) const {return Grandchild(this->val*value);}
        Grandchild operator+(const double value) const {return Grandchild(this->val+value);}
        Grandchild operator-(const double value) const {return Grandchild(this->val-value);}
        Grandchild operator/(const double value) const {return Grandchild(this->val/value);}
        double operator*(const Grandchild other) const { return this->val * other.val; }
        double operator/(const Grandchild other) const { return this->val / other.val; }
        template<typename T> double operator*(const Child<T> other) const {return *this*Grandchild(other);}
        template<typename T> double operator/(const Child<T> other) const {return *this/Grandchild(other);}
        template<template<typename> typename C, typename G> double operator*(const PhysicalUnit<C,G> &other) const {return this->val*other.val;}
        template<template<typename> typename C, typename G> double operator/(const PhysicalUnit<C,G> &other) const {return this->val/other.val;}
        template<typename T> Grandchild operator+(const Child<T> other) const {return *this+Grandchild(other).val;}
        template<typename T> Grandchild operator-(const Child<T> other) const {return *this-Grandchild(other).val;}

        PhysicalUnit<Child, Grandchild> &operator*=(Child<Grandchild> other) {this->val*=other.val;return *this;}
        PhysicalUnit<Child, Grandchild> &operator+=(Child<Grandchild> other) {this->val+=other.val;return *this;}
        PhysicalUnit<Child, Grandchild> &operator-=(Child<Grandchild> other) {this->val-=other.val;return *this;}
        PhysicalUnit<Child, Grandchild> &operator/=(Child<Grandchild> other) {this->val/=other.val;return *this;}

        friend double &operator*=(double &value, Child<Grandchild> self) { value*=self.val; return value; }
        friend double &operator-=(double &value, Child<Grandchild> self) { value-=self.val; return value; }
        friend double &operator+=(double &value, Child<Grandchild> self) { value+=self.val; return value; }
        friend double &operator/=(double &value, Child<Grandchild> self) { value/=self.val; return value; }

        friend Grandchild operator*(const double value, Child<Grandchild> self) { return Grandchild(value*self.val); }
        friend Grandchild operator+(const double value, Child<Grandchild> self) { return Grandchild(value+self.val); }
        friend Grandchild operator-(const double value, Child<Grandchild> self) { return Grandchild(value-self.val); }
        friend Grandchild operator/(const double value, Child<Grandchild> self) { return Grandchild(value/self.val); }

        friend ProxyComp operator==(const double value, const Grandchild &self) {return ProxyComp(self.val, value==self.val); }
        friend ProxyComp operator!=(const double value, const Grandchild &self) {return ProxyComp(self.val, value!=self.val);}
        friend ProxyComp operator<=(const double value, const Grandchild &self) {return ProxyComp(self.val, value<=self.val);}
        friend ProxyComp operator>=(const double value, const Grandchild &self) {return ProxyComp(self.val, value>=self.val);}
        friend ProxyComp operator<(const double value, const Grandchild &self) {return ProxyComp(self.val, value<self.val);}
        friend ProxyComp operator>(const double value, const Grandchild &self) {return ProxyComp(self.val, value>self.val);}

        ProxyComp operator==(const double value) {return ProxyComp(value, (this->val)==value);}
        ProxyComp operator!=(const double value) {return ProxyComp(value, (this->val)!=value);}
        ProxyComp operator<=(const double value) {return ProxyComp(value, (this->val)<=value);}
        ProxyComp operator>=(const double value) {return ProxyComp(value, (this->val)>=value);}
        ProxyComp operator<(const double value) {return ProxyComp(value, (this->val)<value);}
        ProxyComp operator>(const double value) {return ProxyComp(value, (this->val)>value);}

        template<typename T> ProxyComp operator==(const Child<T> &other) {return ProxyComp(Grandchild{other}.val, (this->val)==Grandchild{other}.val);}
        template<typename T> ProxyComp operator!=(const Child<T> &other) {return ProxyComp(Grandchild{other}.val, (this->val)!=Grandchild{other}.val);}
        template<typename T> ProxyComp operator<=(const Child<T> &other) {return ProxyComp(Grandchild{other}.val, (this->val)<=Grandchild{other}.val);}
        template<typename T> ProxyComp operator>=(const Child<T> &other) {return ProxyComp(Grandchild{other}.val, (this->val)>=Grandchild{other}.val);}
        template<typename T> ProxyComp operator<(const Child<T> &other) {return ProxyComp(Grandchild{other}.val, (this->val)<Grandchild{other}.val);}
        template<typename T> ProxyComp operator>(const Child<T> &other) {return ProxyComp(Grandchild{other}.val, (this->val)>Grandchild{other}.val);}

        ProxyComp &operator==(const ProxyComp &&other) {return *this==other.val;}
        ProxyComp &operator!=(const ProxyComp &&other) {return *this!=other.val;}
        ProxyComp &operator<=(const ProxyComp &&other) {return *this<=other.val;}
        ProxyComp &operator>=(const ProxyComp &&other) {return *this>=other.val;}
        ProxyComp &operator<(const ProxyComp &&other) {return *this<other.val;}
        ProxyComp &operator>(const ProxyComp &&other) {return *this>other.val;}

        friend std::ostream &operator<<(std::ostream &os, const PhysicalUnit<Child, Grandchild> &self) {
            if (self.val>10000 || self.val<0.01){
                os << std::scientific;
            }
            os << self.val << Grandchild::symbol();
            return os;
        }

};

}
#endif