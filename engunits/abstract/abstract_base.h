#ifndef __ENGUNITS_ABSTRACT_BASE_H
#define __ENGUNITS_ABSTRACT_BASE_H

#include<string>
#include<iostream>

namespace EngUnits::abstract{
/* The immediate derived class of this class should only interact with itself, not with other immediate derivations of
    this class. However, all derivations of this class share a lot in common. For e.g. lengths should only interact
    with other lengths (by interact, I mean adding, subtracting, comparing etc.) Lengths should not interact with masses,
    volumes etc. */
template<char ID, typename T=double>
class PhysicalUnit{
    protected:
        T val;

        class ProxyComp {
            public:
                T val;
                bool b;

                ProxyComp(const T value, bool bb) : val{value}, b{bb} {};
        
                operator T() { return this->val; }

                ProxyComp operator==(const T value) { this->b=(this->val==value && this->b) ; this->val=value; return *this; }
                ProxyComp operator!=(const T value) {this->b=(this->val!=value && this->b) ; this->val=value; return *this;}
                ProxyComp operator<=(const T value) {this->b=(this->val<=value && this->b) ; this->val=value; return *this;}
                ProxyComp operator>=(const T value) {this->b=(this->val>=value && this->b) ; this->val=value; return *this;}
                ProxyComp operator<(const T value) {this->b=(this->val<value && this->b) ; this->val=value; return *this;}
                ProxyComp operator>(const T value) {this->b=(this->val>value && this->b) ; this->val=value; return *this;}
                ProxyComp operator==(const PhysicalUnit<ID, T> &other) { return *this == other.val; }
                ProxyComp operator!=(const PhysicalUnit<ID, T> &other) { return *this != other.val; }
                ProxyComp operator<=(const PhysicalUnit<ID, T> &other) { return *this <= other.val; }
                ProxyComp operator>=(const PhysicalUnit<ID, T> &other) { return *this >= other.val; }
                ProxyComp operator<(const PhysicalUnit<ID, T> &other) { return *this < other.val; }
                ProxyComp operator>(const PhysicalUnit<ID, T> &other) { return *this > other.val; }
                friend ProxyComp operator==(const T value, ProxyComp self) {return ProxyComp(self.val, value==self.val); }
                friend ProxyComp operator!=(const T value, ProxyComp self) {return ProxyComp(self.val, value!=self.val);}
                friend ProxyComp operator<=(const T value, ProxyComp self) {return ProxyComp(self.val, value<=self.val);}
                friend ProxyComp operator>=(const T value, ProxyComp self) {return ProxyComp(self.val, value>=self.val);}
                friend ProxyComp operator<(const T value, ProxyComp self) {return ProxyComp(self.val, value<self.val);}
                friend ProxyComp operator>(const T value, ProxyComp self) {return ProxyComp(self.val, value>self.val);}
        };

    public:
        PhysicalUnit<ID, T>():val{} {};
        PhysicalUnit<ID, T>(const T value, const double conversion=1): val{value*conversion} {};
        PhysicalUnit<ID, T>(const ProxyComp &&other):val{other.val()} {};

        virtual T SI_val() const = 0; //this function ensures this base class remains purely abstract
        virtual T abs_val() const = 0;//same for this function

        void operator++() {this->val++;}
        void operator++(int i) { ++this->val; }
        void operator--() {this->val--;}
        void operator--(int i) { --this->val; }

        operator bool() const {return (this->val);}

        ProxyComp operator==(const double value) {return ProxyComp(value, (this->val)==value);}
        ProxyComp operator!=(const double value) {return ProxyComp(value, (this->val)!=value);}
        ProxyComp operator<=(const double value) {return ProxyComp(value, (this->val)<=value);}
        ProxyComp operator>=(const double value) {return ProxyComp(value, (this->val)>=value);}
        ProxyComp operator<(const double value) {return ProxyComp(value, (this->val)<value);}
        ProxyComp operator>(const double value) {return ProxyComp(value, (this->val)>value);}
        ProxyComp operator==(const PhysicalUnit<ID, T> &other) { return *this == other.val; }
        ProxyComp operator!=(const PhysicalUnit<ID, T> &other) {return *this!=other.val;}
        ProxyComp operator<=(const PhysicalUnit<ID, T> &other) {return *this<=other.val;}
        ProxyComp operator>=(const PhysicalUnit<ID, T> &other) {return *this>=other.val;}
        ProxyComp operator<(const PhysicalUnit<ID, T> &other) {return *this<other.val;}
        ProxyComp operator>(const PhysicalUnit<ID, T> &other) {return *this>other.val;}
        ProxyComp operator==(const ProxyComp other) {return *this==other.val;}
        ProxyComp operator!=(const ProxyComp other) {return *this!=other.val;}
        ProxyComp operator<=(const ProxyComp other) {return *this<=other.val;}
        ProxyComp operator>=(const ProxyComp other) {return *this>=other.val;}
        ProxyComp operator<(const ProxyComp other) {return *this<other.val;}
        ProxyComp operator>(const ProxyComp other) {return *this>other.val;}

};
}
#endif