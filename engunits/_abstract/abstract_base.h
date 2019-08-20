#ifndef __ENGUNITS_ABSTRACT_BASE_H
#define __ENGUNITS_ABSTRACT_BASE_H

#include<string>
#include<iostream>
#include<sstream>
#include<type_traits>
#include<limits>

#include "../../engunits/_abstract/core.h"
#include "../../engunits/_abstract/coremaths.h"

namespace engunits::abstract{
template<template<typename> typename Child, typename Grandchild>
class PhysicalUnit{
    private:
    #ifdef ENGUNITS_UNDERLYING_TYPE
        using ValType = ENGUNITS_UNDERLYING_TYPE;
    #else
        using ValType = double;
    #endif

        ValType val;
        
        template<typename T> friend class Child;

        class ProxyComp {
            private:
                template<template<typename> typename C, typename G> friend class PhysicalUnit;

                ValType val;
                bool b;

                constexpr ProxyComp(const ValType &value, bool bb) : val{value}, b{bb} {};

            public:
        
                constexpr explicit operator bool() const { return this->b; }

                constexpr ProxyComp operator==(const double &value) const {return ProxyComp(value, val==value&&b);}
                constexpr ProxyComp operator!=(const double &value) const {return ProxyComp(value, val!=value&&b);}
                constexpr ProxyComp operator<=(const double &value) const {return ProxyComp(value, val<=value&&b);}
                constexpr ProxyComp operator>=(const double &value) const {return ProxyComp(value, val>=value&&b);}
                constexpr ProxyComp operator<(const double &value) const {return ProxyComp(value, val<value&&b);}
                constexpr ProxyComp operator>(const double &value) const {return ProxyComp(value, val>value&&b);}

                constexpr ProxyComp operator==(const Grandchild &other) const {return ProxyComp(other.val, val==other.val&&b);}
                constexpr ProxyComp operator!=(const Grandchild &other) const {return ProxyComp(other.val, val!=other.val&&b);}
                constexpr ProxyComp operator<=(const Grandchild &other) const {return ProxyComp(other.val, val<=other.val&&b);}
                constexpr ProxyComp operator>=(const Grandchild &other) const {return ProxyComp(other.val, val>=other.val&&b);}
                constexpr ProxyComp operator<(const Grandchild &other) const {return ProxyComp(other.val, val<other.val&&b);}
                constexpr ProxyComp operator>(const Grandchild &other) const {return ProxyComp(other.val, val>other.val&&b);}
                
                constexpr friend ProxyComp operator==(const double &value, const ProxyComp &self){ 
                    return ProxyComp(self.val, value==self.val&&self.b);}
                constexpr friend ProxyComp operator!=(const double &value, const ProxyComp &self){ 
                    return ProxyComp(self.val, value!=self.val&&self.b);}
                constexpr friend ProxyComp operator<=(const double &value, const ProxyComp &self){ 
                    return ProxyComp(self.val, value<=self.val&&self.b);}
                constexpr friend ProxyComp operator>=(const double &value, const ProxyComp &self){ 
                    return ProxyComp(self.val, value>=self.val&&self.b);}
                constexpr friend ProxyComp operator<(const double &value, const ProxyComp &self){ 
                    return ProxyComp(self.val, value<self.val&&self.b);}
                constexpr friend ProxyComp operator>(const double &value, const ProxyComp &self){ 
                    return ProxyComp(self.val, value>self.val&&self.b);}
        };

    protected:
        void set_val(const ValType &value) { val = value; }
        constexpr ValType get_val() const { return val; }

    public:
        constexpr PhysicalUnit():val{} {};
        constexpr PhysicalUnit(const ValType &value) : val{value} {};

        virtual const std::string symbol() const = 0;

        constexpr ValType si_val() const { return this->val * Grandchild::conversion; }
        constexpr ValType scalar() const { return this->val; }

        template <typename Other, 
            typename=std::enable_if_t<std::is_constructible<Other,ValType>::value&&!std::is_rvalue_reference<Other>::value>>
        constexpr Other cast_to() const { return val; }

        std::string to_string(bool scientific=false) const {
            std::stringstream ss;
            if (scientific) ss << std::scientific;
            ss << (*this);
            return ss.str();
        }

        Grandchild &operator++(int) {val++; return *static_cast<Grandchild*>(this);}
        Grandchild operator++() { ++val; return Grandchild{val-1};}
        Grandchild &operator--(int) {val--; return *static_cast<Grandchild*>(this);}
        Grandchild operator--() { --val; return Grandchild{val+1};}
        constexpr Grandchild operator-() const { return this->val * (-1); }
        constexpr Grandchild operator+() const { return *this; }
        constexpr explicit operator bool() const { return val; }

        template<typename Exp, typename=std::enable_if_t<std::is_arithmetic_v<Exp>>> 
        constexpr auto pow(const Exp &value) const {return maths::pow(val, value);}

        constexpr Grandchild operator*(const double &value) const {return val*value;}
        constexpr Grandchild operator+(const double &value) const {return val+value;}
        constexpr Grandchild operator-(const double &value) const {return val-value;}
        constexpr Grandchild operator/(const double &value) const {return val/value;}
        template<typename T> constexpr Grandchild operator+(const Child<T> &other) const {return val+Grandchild(other).val;}
        template<typename T> constexpr Grandchild operator-(const Child<T> &other) const {return val-Grandchild(other).val;}
        constexpr Grandchild operator+(const Grandchild &other) const { return Grandchild(val+other.val); }
        constexpr Grandchild operator-(const Grandchild &other) const { return Grandchild(val-other.val); }
        constexpr ValType operator/(const Grandchild &other) const { return this->val / other.val; }

        Grandchild &operator*=(const Grandchild &other) {this->val*=other.val;return *static_cast<Grandchild*>(this);}
        Grandchild &operator+=(const Grandchild &other) {this->val+=other.val;return *static_cast<Grandchild*>(this);}
        Grandchild &operator-=(const Grandchild &other) {this->val-=other.val;return *static_cast<Grandchild*>(this);}
        Grandchild &operator/=(const Grandchild &other) {this->val/=other.val;return *static_cast<Grandchild*>(this);}

        friend ValType &operator*=(ValType &value, const Grandchild &self) { value*=self.val; return value; }
        friend ValType &operator-=(ValType &value, const Grandchild &self) { value-=self.val; return value; }
        friend ValType &operator+=(ValType &value, const Grandchild &self) { value+=self.val; return value; }
        friend ValType &operator/=(ValType &value, const Grandchild &self) { value/=self.val; return value; }

        constexpr friend Grandchild operator*(const ValType &value, const Grandchild &self) { return value*self.val; }
        constexpr friend Grandchild operator+(const ValType &value, const Grandchild &self) { return value+self.val; }
        constexpr friend Grandchild operator-(const ValType &value, const Grandchild &self) { return value-self.val; }
        constexpr friend Grandchild operator/(const ValType &value, const Grandchild &self) { return value/self.val; }

        constexpr friend ProxyComp operator==(const double &value, const Grandchild &self) {return ProxyComp(self.val, value==self.val); }
        constexpr friend ProxyComp operator!=(const double &value, const Grandchild &self) {return ProxyComp(self.val, value!=self.val);}
        constexpr friend ProxyComp operator<=(const double &value, const Grandchild &self) {return ProxyComp(self.val, value<=self.val);}
        constexpr friend ProxyComp operator>=(const double &value, const Grandchild &self) {return ProxyComp(self.val, value>=self.val);}
        constexpr friend ProxyComp operator<(const double &value, const Grandchild &self) {return ProxyComp(self.val, value<self.val);}
        constexpr friend ProxyComp operator>(const double &value, const Grandchild &self) {return ProxyComp(self.val, value>self.val);}
        constexpr friend ProxyComp operator^=(const double &value, const Grandchild &self) {return ProxyComp(self.val, value>self.val);}

        constexpr ProxyComp operator==(const double &value) const {return ProxyComp(value, (this->val)==value);}
        constexpr ProxyComp operator!=(const double &value) const {return ProxyComp(value, (this->val)!=value);}
        constexpr ProxyComp operator<=(const double &value) const {return ProxyComp(value, (this->val)<=value);}
        constexpr ProxyComp operator>=(const double &value) const {return ProxyComp(value, (this->val)>=value);}
        constexpr ProxyComp operator<(const double &value) const {return ProxyComp(value, (this->val)<value);}
        constexpr ProxyComp operator>(const double &value) const {return ProxyComp(value, (this->val)>value);}

        constexpr ProxyComp operator==(const Grandchild &other) const {return ProxyComp(other.val, (this->val)==other.val);}
        constexpr ProxyComp operator!=(const Grandchild &other) const {return ProxyComp(other.val, (this->val)!=other.val);}
        constexpr ProxyComp operator<=(const Grandchild &other) const {return ProxyComp(other.val, (this->val)<=other.val);}
        constexpr ProxyComp operator>=(const Grandchild &other) const {return ProxyComp(other.val, (this->val)>=other.val);}
        constexpr ProxyComp operator<(const Grandchild &other) const {return ProxyComp(other.val, (this->val)<other.val);}
        constexpr ProxyComp operator>(const Grandchild &other) const {return ProxyComp(other.val, (this->val)>other.val);}

        constexpr ProxyComp operator==(const ProxyComp &other) const {return ProxyComp(other.val, val==other.val&&other.b);}
        constexpr ProxyComp operator!=(const ProxyComp &other) const {return ProxyComp(other.val, val!=other.val&&other.b);}
        constexpr ProxyComp operator<=(const ProxyComp &other) const {return ProxyComp(other.val, val<=other.val&&other.b);}
        constexpr ProxyComp operator>=(const ProxyComp &other) const {return ProxyComp(other.val, val>=other.val&&other.b);}
        constexpr ProxyComp operator<(const ProxyComp &other) const {return ProxyComp(other.val, val<other.val&&other.b);}
        constexpr ProxyComp operator>(const ProxyComp &other) const {return ProxyComp(other.val, val>other.val&&other.b);}

        friend std::istream &operator>>(std::istream &is, PhysicalUnit<Child,Grandchild> &self){
            is >> self.val;
            return is;
        }

        friend std::ostream &operator<<(std::ostream &os, const PhysicalUnit<Child, Grandchild> &self) {
            os << self.val << ' ' << self.symbol();
            return os;
        }

};
}//namespace engunits::abstract
#endif