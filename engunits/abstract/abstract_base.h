#ifndef __ENGUNITS_ABSTRACT_BASE_H
#define __ENGUNITS_ABSTRACT_BASE_H

namespace EngUnits{

template<typename T=double>
class PhysicalUnit{ 
    protected:
        T val;

        class ProxyComp {
            protected:
                T val;
                bool b;

                template<typename TT> friend class PhysicalUnit;
                friend class LengthUnit;

                ProxyComp(const T value, bool bb) : val{value}, b{bb} {};

            public:
        
                operator bool() { return this->b; }
                operator T() { return this->val; }
                operator PhysicalUnit<T>() { return PhysicalUnit<T>(this->val); }

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

        PhysicalUnit<T>():val{} {};
        PhysicalUnit<T>(const T value):val(value) {};
        PhysicalUnit<T>(const ProxyComp &&other):val{other.val} {};
};

}
#endif