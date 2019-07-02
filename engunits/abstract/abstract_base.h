#ifndef __ENGUNITS_ABSTRACT_BASE_H
#define __ENGUNITS_ABSTRACT_BASE_H

#include<string>
#include<iostream>

namespace EngUnits::core{

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
        PhysicalUnit<ID, T>(const T value, const double conversion): val{value*conversion} {};
        PhysicalUnit<ID, T>(const ProxyComp &&other):val{other.val()} {};

        virtual T true_val() const = 0; //this function ensures this base class remains purely abstract

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