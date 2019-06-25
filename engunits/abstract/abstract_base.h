#ifndef __ENGUNITS_ABSTRACT_BASE_H
#define __ENGUNITS_ABSTRACT_BASE_H

#include<string>

namespace EngUnits{

template<typename T=double>
class PhysicalUnit{ 
    protected:
        T val;

        class ProxyComp {
            public:
                T val;
                bool b;

                ProxyComp(const T value, bool bb) : val{value}, b{bb} {};
        
                operator bool() { return this->b; }
                operator T() { return this->val; }

                ProxyComp operator==(const T value) { this->b=(this->val==value && this->b) ; this->val=value; return *this; }
                ProxyComp operator!=(const T value) {this->b=(this->val!=value && this->b) ; this->val=value; return *this;}
                ProxyComp operator<=(const T value) {this->b=(this->val<=value && this->b) ; this->val=value; return *this;}
                ProxyComp operator>=(const T value) {this->b=(this->val>=value && this->b) ; this->val=value; return *this;}
                ProxyComp operator<(const T value) {this->b=(this->val<value && this->b) ; this->val=value; return *this;}
                ProxyComp operator>(const T value) {this->b=(this->val>value && this->b) ; this->val=value; return *this;}
                ProxyComp operator==(const PhysicalUnit<T> &other) { return *this == other.val; }
                ProxyComp operator!=(const PhysicalUnit<T> &other) { return *this != other.val; }
                ProxyComp operator<=(const PhysicalUnit<T> &other) { return *this <= other.val; }
                ProxyComp operator>=(const PhysicalUnit<T> &other) { return *this >= other.val; }
                ProxyComp operator<(const PhysicalUnit<T> &other) { return *this < other.val; }
                ProxyComp operator>(const PhysicalUnit<T> &other) { return *this > other.val; }
                friend ProxyComp operator==(const T value, ProxyComp self) {return ProxyComp(self.val, value==self.val); }
                friend ProxyComp operator!=(const T value, ProxyComp self) {return ProxyComp(self.val, value!=self.val);}
                friend ProxyComp operator<=(const T value, ProxyComp self) {return ProxyComp(self.val, value<=self.val);}
                friend ProxyComp operator>=(const T value, ProxyComp self) {return ProxyComp(self.val, value>=self.val);}
                friend ProxyComp operator<(const T value, ProxyComp self) {return ProxyComp(self.val, value<self.val);}
                friend ProxyComp operator>(const T value, ProxyComp self) {return ProxyComp(self.val, value>self.val);}
        };

        virtual T get_conversion() const { return 1; }
        virtual std::string get_suffix() const = 0;

    public:
        PhysicalUnit<T>():val{} {};
        PhysicalUnit<T>(const T value):val{value*get_conversion()} {};
        PhysicalUnit<T>(const ProxyComp &&other):val{other.val()} {};

        T true_val() const { return this->val / get_conversion(); }
};
}
#endif