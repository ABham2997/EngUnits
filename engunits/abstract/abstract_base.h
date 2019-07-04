#ifndef __ENGUNITS_ABSTRACT_BASE_H
#define __ENGUNITS_ABSTRACT_BASE_H

#include<string>
#include<iostream>

#include "../../engunits/conversion/conversion_funcs.h"

namespace EngUnits::abstract{
template<typename Child, typename Grandchild, typename T=double>
class PhysicalUnit{
    private:
        template <typename S> friend double conversion::double_cast(S arg);

    protected:
        T val;

        class ProxyComp {
            public:
                T val;
                bool b;

                ProxyComp(const T value, bool bb) : val{value}, b{bb} {};
        
                operator bool() { return this->val; }

                ProxyComp operator==(const T value) { this->b=(this->val==value && this->b) ; this->val=value; return *this; }
                ProxyComp operator!=(const T value) {this->b=(this->val!=value && this->b) ; this->val=value; return *this;}
                ProxyComp operator<=(const T value) {this->b=(this->val<=value && this->b) ; this->val=value; return *this;}
                ProxyComp operator>=(const T value) {this->b=(this->val>=value && this->b) ; this->val=value; return *this;}
                ProxyComp operator<(const T value) {this->b=(this->val<value && this->b) ; this->val=value; return *this;}
                ProxyComp operator>(const T value) {this->b=(this->val>value && this->b) ; this->val=value; return *this;}
                ProxyComp operator==(const PhysicalUnit<Child, Grandchild, T> &other) { return *this == other.val; }
                ProxyComp operator!=(const PhysicalUnit<Child, Grandchild, T> &other) { return *this != other.val; }
                ProxyComp operator<=(const PhysicalUnit<Child, Grandchild, T> &other) { return *this <= other.val; }
                ProxyComp operator>=(const PhysicalUnit<Child, Grandchild, T> &other) { return *this >= other.val; }
                ProxyComp operator<(const PhysicalUnit<Child, Grandchild, T> &other) { return *this < other.val; }
                ProxyComp operator>(const PhysicalUnit<Child, Grandchild, T> &other) { return *this > other.val; }
                friend ProxyComp operator==(const T value, ProxyComp self) {return ProxyComp(self.val, value==self.val); }
                friend ProxyComp operator!=(const T value, ProxyComp self) {return ProxyComp(self.val, value!=self.val);}
                friend ProxyComp operator<=(const T value, ProxyComp self) {return ProxyComp(self.val, value<=self.val);}
                friend ProxyComp operator>=(const T value, ProxyComp self) {return ProxyComp(self.val, value>=self.val);}
                friend ProxyComp operator<(const T value, ProxyComp self) {return ProxyComp(self.val, value<self.val);}
                friend ProxyComp operator>(const T value, ProxyComp self) {return ProxyComp(self.val, value>self.val);}
        };

    public:
        PhysicalUnit<Child, Grandchild, T>():val{} {};
        PhysicalUnit<Child, Grandchild, T>(const T value): val{value} {};
        PhysicalUnit<Child, Grandchild, T>(const ProxyComp &&other):val{other.val()} {};

        virtual T SI_val() const = 0; //this function ensures this base class remains purely abstract
        virtual T abs_val() const = 0;

        void operator++() {this->val++;}
        void operator++(int i) { ++this->val; }
        void operator--() {this->val--;}
        void operator--(int i) { --this->val; }

        operator bool() const {return (this->val);}

        friend T &operator*=(T &value, Child self) { value*=self.val; return value; }
        friend T &operator-=(T &value, Child self) { value-=self.val; return value; }
        friend T &operator+=(T &value, Child self) { value+=self.val; return value; }
        friend T &operator/=(T &value, Child self) { value/=self.val; return value; }

        friend Grandchild operator*(const T value, Child self) { return Grandchild(value*self.val); }
        friend Grandchild operator+(const T value, Child self) { return Grandchild(value+self.val); }
        friend Grandchild operator-(const T value, Child self) { return Grandchild(value-self.val); }
        friend Grandchild operator/(const T value, Child self) { return Grandchild(value/self.val); }

        ProxyComp operator==(const double value) {return ProxyComp(value, (this->val)==value);}
        ProxyComp operator!=(const double value) {return ProxyComp(value, (this->val)!=value);}
        ProxyComp operator<=(const double value) {return ProxyComp(value, (this->val)<=value);}
        ProxyComp operator>=(const double value) {return ProxyComp(value, (this->val)>=value);}
        ProxyComp operator<(const double value) {return ProxyComp(value, (this->val)<value);}
        ProxyComp operator>(const double value) {return ProxyComp(value, (this->val)>value);}
        ProxyComp operator==(const PhysicalUnit<Child, Grandchild, T> &other) { return *this == other.val; }
        ProxyComp operator!=(const PhysicalUnit<Child, Grandchild, T> &other) {return *this!=other.val;}
        ProxyComp operator<=(const PhysicalUnit<Child, Grandchild, T> &other) {return *this<=other.val;}
        ProxyComp operator>=(const PhysicalUnit<Child, Grandchild, T> &other) {return *this>=other.val;}
        ProxyComp operator<(const PhysicalUnit<Child, Grandchild, T> &other) {return *this<other.val;}
        ProxyComp operator>(const PhysicalUnit<Child, Grandchild, T> &other) {return *this>other.val;}
        ProxyComp operator==(const ProxyComp other) {return *this==other.val;}
        ProxyComp operator!=(const ProxyComp other) {return *this!=other.val;}
        ProxyComp operator<=(const ProxyComp other) {return *this<=other.val;}
        ProxyComp operator>=(const ProxyComp other) {return *this>=other.val;}
        ProxyComp operator<(const ProxyComp other) {return *this<other.val;}
        ProxyComp operator>(const ProxyComp other) {return *this>other.val;}

        friend ProxyComp operator==(const double value, Child self) { return Child(value) == self; }
        friend ProxyComp operator!=(const double value, Child self) {return Child(value) != self;}
        friend ProxyComp operator<=(const double value, Child self) {return Child(value) <= self;}
        friend ProxyComp operator>=(const double value, Child self) {return Child(value) >= self;}
        friend ProxyComp operator<(const double value, Child self) {return Child(value) < self;}
        friend ProxyComp operator>(const double value, Child self) {return Child(value) > self;}

        friend std::ostream &operator<<(std::ostream &os, const PhysicalUnit<Child, Grandchild, T> &self) {
            if (self.val<10000 && self.val>0.01){
                os << self.val << Grandchild::suffix(); 
                return os;
            }
            else {
                os << std::scientific << self.val << Grandchild::suffix();
            }
        }

};

}
#endif