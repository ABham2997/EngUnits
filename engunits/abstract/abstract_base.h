#ifndef __ENGUNITS_ABSTRACT_BASE_H
#define __ENGUNITS_ABSTRACT_BASE_H

namespace EngUnits{

template<typename T=double>
class PhysicalUnit{ 
    private:
        T val;

        class ProxyComp {
            private:
                T val;
                bool b;

                template<typename TT> friend class PhysicalUnit;

                ProxyComp(const PhysicalUnit<T> value, bool bb) : val{value.val}, b{bb} {};

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

    protected:
        PhysicalUnit<T>():val{} {};
        PhysicalUnit<T>(const T value):val(value) {};
        PhysicalUnit<T>(const ProxyComp &other):val{other.val} {};

    public:
        virtual PhysicalUnit<T> &operator=(const T value) {this->val=value; return *this;}
        virtual PhysicalUnit<T> &operator=(const PhysicalUnit<T> &other) { this->val = other.val; return *this;}
        virtual operator bool() const {return (this->val);}
        virtual operator T() const {return this->val;}
        
        virtual PhysicalUnit<T> operator*(const T value) const { return PhysicalUnit<T>(this->val*value);}
        virtual PhysicalUnit<T> operator+(const T value) const {return PhysicalUnit<T>(this->val+value);}
        virtual PhysicalUnit<T> operator-(const T value) const {return PhysicalUnit<T>(this->val-value);}
        virtual PhysicalUnit<T> operator/(const T value) const {return PhysicalUnit<T>(this->val/value);}
        virtual PhysicalUnit<T> &operator*=(const T value) {this->val*=value;return *this;}
        virtual PhysicalUnit<T> &operator+=(const T value) {this->val+=value;return *this;}
        virtual PhysicalUnit<T> &operator-=(const T value) {this->val-=value;return *this;}
        virtual PhysicalUnit<T> &operator/=(const T value) {this->val/=value;return *this;}
        virtual PhysicalUnit<T> operator*(PhysicalUnit<T> other) const { return PhysicalUnit<T>(this->val*other.val);}
        virtual PhysicalUnit<T> operator+(PhysicalUnit<T> other) const {return PhysicalUnit<T>(this->val+other.val);}
        virtual PhysicalUnit<T> operator-(PhysicalUnit<T> other) const {return PhysicalUnit<T>(this->val-other.val);}
        virtual PhysicalUnit<T> operator/(PhysicalUnit<T> other) const {return PhysicalUnit<T>(this->val/other.val);}
        virtual PhysicalUnit<T> &operator*=(PhysicalUnit<T> other) {this->val*=other.val;return *this;}
        virtual PhysicalUnit<T> &operator+=(PhysicalUnit<T> other) {this->val+=other.val;return *this;}
        virtual PhysicalUnit<T> &operator-=(PhysicalUnit<T> other) {this->val-=other.val;return *this;}
        virtual PhysicalUnit<T> &operator/=(PhysicalUnit<T> other) {this->val/=other.val;return *this;}
        friend PhysicalUnit<T> operator*(const T value, PhysicalUnit<T> self) { return self * value; }
        friend PhysicalUnit<T> operator+(const T value, PhysicalUnit<T> self) { return self + value; }
        friend PhysicalUnit<T> operator-(const T value, PhysicalUnit<T> self) { return PhysicalUnit<T>(value-self.val); }
        friend PhysicalUnit<T> operator/(const T value, PhysicalUnit<T> self) { return PhysicalUnit<T>(value/self.val); }

        virtual void operator++() {this->val++;}
        virtual void operator++(int i) { ++this->val; }
        virtual void operator--() {this->val--;}
        virtual void operator--(int i) { --this->val; }

        virtual ProxyComp operator==(const T value) {return ProxyComp(value, (this->val)==value);}
        virtual ProxyComp operator!=(const T value) {return ProxyComp(value, (this->val)!=value);}
        virtual ProxyComp operator<=(const T value) {return ProxyComp(value, (this->val)<=value);}
        virtual ProxyComp operator>=(const T value) {return ProxyComp(value, (this->val)>=value);}
        virtual ProxyComp operator<(const T value) {return ProxyComp(value, (this->val)<value);}
        virtual ProxyComp operator>(const T value) {return ProxyComp(value, (this->val)>value);}
        virtual ProxyComp operator==(const PhysicalUnit<T> &other) { return *this == other.val; }
        virtual ProxyComp operator!=(const PhysicalUnit<T> &other) {return *this!=other.val;}
        virtual ProxyComp operator<=(const PhysicalUnit<T> &other) {return *this<=other.val;}
        virtual ProxyComp operator>=(const PhysicalUnit<T> &other) {return *this>=other.val;}
        virtual ProxyComp operator<(const PhysicalUnit<T> &other) {return *this<other.val;}
        virtual ProxyComp operator>(const PhysicalUnit<T> &other) {return *this>other.val;}
        virtual ProxyComp operator==(const ProxyComp other) {return *this==other.val;}
        virtual ProxyComp operator!=(const ProxyComp other) {return *this!=other.val;}
        virtual ProxyComp operator<=(const ProxyComp other) {return *this<=other.val;}
        virtual ProxyComp operator>=(const ProxyComp other) {return *this>=other.val;}
        virtual ProxyComp operator<(const ProxyComp other) {return *this<other.val;}
        virtual ProxyComp operator>(const ProxyComp other) {return *this>other.val;}
        friend ProxyComp operator==(const T value, PhysicalUnit<T> self) { return PhysicalUnit<T>(value) == self; }
        friend ProxyComp operator!=(const T value, PhysicalUnit<T> self) {return PhysicalUnit<T>(value) != self;}
        friend ProxyComp operator<=(const T value, PhysicalUnit<T> self) {return PhysicalUnit<T>(value) <= self;}
        friend ProxyComp operator>=(const T value, PhysicalUnit<T> self) {return PhysicalUnit<T>(value) >= self;}
        friend ProxyComp operator<(const T value, PhysicalUnit<T> self) {return PhysicalUnit<T>(value) < self;}
        friend ProxyComp operator>(const T value, PhysicalUnit<T> self) {return PhysicalUnit<T>(value) > self;}
};

}
#endif