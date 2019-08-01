#ifndef __ENGUNITS_ABSTRACT_BASE_H
#define __ENGUNITS_ABSTRACT_BASE_H

#include<string>
#include<iostream>
#include<cmath>
#include<sstream>
#include<type_traits>

#include "../../engunits/_abstract/core.h"

namespace engunits::abstract{
template<template<typename> typename Child, typename Grandchild>
class PhysicalUnit{
    private:
        using ValType = double;

        class ProxyComp {
            public:
                ValType val;
                bool b;

                ProxyComp(const ValType value, bool bb) : val{value}, b{bb} {};
        
                operator bool() { return this->b; }

                ProxyComp &operator==(const ValType value) {b=(this->val==value && b) ; this->val=value; return *this; }
                ProxyComp &operator!=(const ValType value) {b=(this->val!=value && b) ; this->val=value; return *this;}
                ProxyComp &operator<=(const ValType value) {b=(this->val<=value && b) ; this->val=value; return *this;}
                ProxyComp &operator>=(const ValType value) {b=(this->val>=value && b) ; this->val=value; return *this;}
                ProxyComp &operator<(const ValType value) {b=(this->val<value && b) ; this->val=value; return *this;}
                ProxyComp &operator>(const ValType value) {b=(this->val>value && b) ; this->val=value; return *this;}

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
                
                friend ProxyComp &operator==(const ValType value, ProxyComp &&self){ 
                    self.b=(value==self.val && self.b); self.val=value; return self;}
                friend ProxyComp &operator!=(const ValType value, ProxyComp &&self){ 
                    self.b=(value!=self.val && self.b); self.val=value; return self;}
                friend ProxyComp &operator<=(const ValType value, ProxyComp &&self){ 
                    self.b=(value<=self.val && self.b); self.val=value; return self;}
                friend ProxyComp &operator>=(const ValType value, ProxyComp &&self){ 
                    self.b=(value>=self.val && self.b); self.val=value; return self;}
                friend ProxyComp &operator<(const ValType value, ProxyComp &&self){ 
                    self.b=(value<self.val && self.b); self.val=value; return self;}
                friend ProxyComp &operator>(const ValType value, ProxyComp &&self){ 
                    self.b=(value>self.val && self.b); self.val=value; return self;}
        };

    protected:
        ValType val;

    public:
        PhysicalUnit():val{} {};
        PhysicalUnit(const ValType value): val{value} {};
        PhysicalUnit(const ProxyComp other) : val{other.val} {};

        virtual std::string symbol() const = 0;

        constexpr ValType si_val() const { return this->val * Grandchild::conversion; }
        constexpr ValType scalar() const { return this->val; }

        template <typename Other, typename=std::enable_if_t<std::is_constructible<Other,ValType>::value>>
        Other cast_to() { return Other{val}; }

        std::string to_string(bool scientific=true) {
            std::stringstream ss;
            if (scientific) ss << std::scientific;
            ss << (*this);
            return ss.str();
        }

        PhysicalUnit &operator++(int) {val++; *this;} //this is not good, needs improvement, should be ref return type
        Grandchild operator++() { ++val; return Grandchild{val-1};}
        PhysicalUnit &operator--(int) {val--; return *this;}// also not good
        Grandchild operator--() { --val; return Grandchild{val+1};}
        operator bool() const { return (this->val); }
        ValType operator^(const ValType value) const { return std::pow(this->val,value); }
        int operator%(const int value) const { return int(this->val) % value; }

        Grandchild operator*(const ValType value) const {return Grandchild(this->val*value);}
        Grandchild operator+(const ValType value) const {return Grandchild(this->val+value);}
        Grandchild operator-(const ValType value) const {return Grandchild(this->val-value);}
        Grandchild operator/(const ValType value) const {return Grandchild(this->val/value);}
        ValType operator*(const Grandchild other) const { return this->val * other.val; }
        ValType operator/(const Grandchild other) const { return this->val / other.val; }
        template<typename T> ValType operator*(const Child<T> other) const {return *this*Grandchild(other);}
        template<typename T> ValType operator/(const Child<T> other) const {return *this/Grandchild(other);}
        template<template<typename> typename C, typename G> ValType operator*(const PhysicalUnit<C,G> &other) const {return this->val*other.val;}
        template<template<typename> typename C, typename G> ValType operator/(const PhysicalUnit<C,G> &other) const {return this->val/other.val;}
        template<template<typename> typename C, typename G> ValType operator*(const PhysicalUnit<C,G> &&other) const {return this->val*other.val;}
        template<template<typename> typename C, typename G> ValType operator/(const PhysicalUnit<C,G> &&other) const {return this->val/other.val;}
        template<typename T> Grandchild operator+(const Child<T> other) const {return *this+Grandchild(other).val;}
        template<typename T> Grandchild operator-(const Child<T> other) const {return *this-Grandchild(other).val;}

        PhysicalUnit<Child, Grandchild> &operator*=(Grandchild other) {this->val*=other.val;return *this;}
        PhysicalUnit<Child, Grandchild> &operator+=(Grandchild other) {this->val+=other.val;return *this;}
        PhysicalUnit<Child, Grandchild> &operator-=(Grandchild other) {this->val-=other.val;return *this;}
        PhysicalUnit<Child, Grandchild> &operator/=(Grandchild other) {this->val/=other.val;return *this;}

        friend ValType &operator*=(ValType &value, Grandchild self) { value*=self.val; return value; }
        friend ValType &operator-=(ValType &value, Grandchild self) { value-=self.val; return value; }
        friend ValType &operator+=(ValType &value, Grandchild self) { value+=self.val; return value; }
        friend ValType &operator/=(ValType &value, Grandchild self) { value/=self.val; return value; }

        friend Grandchild operator*(const ValType value, Grandchild self) { return Grandchild(value*self.val); }
        friend Grandchild operator+(const ValType value, Grandchild self) { return Grandchild(value+self.val); }
        friend Grandchild operator-(const ValType value, Grandchild self) { return Grandchild(value-self.val); }
        friend Grandchild operator/(const ValType value, Grandchild self) { return Grandchild(value/self.val); }

        friend ProxyComp operator==(const ValType value, const Grandchild &self) {return ProxyComp(self.val, value==self.val); }
        friend ProxyComp operator!=(const ValType value, const Grandchild &self) {return ProxyComp(self.val, value!=self.val);}
        friend ProxyComp operator<=(const ValType value, const Grandchild &self) {return ProxyComp(self.val, value<=self.val);}
        friend ProxyComp operator>=(const ValType value, const Grandchild &self) {return ProxyComp(self.val, value>=self.val);}
        friend ProxyComp operator<(const ValType value, const Grandchild &self) {return ProxyComp(self.val, value<self.val);}
        friend ProxyComp operator>(const ValType value, const Grandchild &self) {return ProxyComp(self.val, value>self.val);}

        ProxyComp operator==(const ValType value) {return ProxyComp(value, (this->val)==value);}
        ProxyComp operator!=(const ValType value) {return ProxyComp(value, (this->val)!=value);}
        ProxyComp operator<=(const ValType value) {return ProxyComp(value, (this->val)<=value);}
        ProxyComp operator>=(const ValType value) {return ProxyComp(value, (this->val)>=value);}
        ProxyComp operator<(const ValType value) {return ProxyComp(value, (this->val)<value);}
        ProxyComp operator>(const ValType value) {return ProxyComp(value, (this->val)>value);}

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
            os << self.val << ' ' << self.symbol();
            return os;
        }

};
}//namespace engunits::abstract
#endif