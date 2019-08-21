#ifndef __ENGUNITS_MATHS_FRACTION_H
#define __ENGUNITS_MATHS_FRACTION_H

#include<iostream>

#include<type_traits>

namespace engunits::maths{

class fraction{
    private:
        int num;
        int denom;

    public:

        constexpr fraction() : num{}, denom{} {};
        constexpr fraction(int numer, int denomer) : num{}, denom{} {
            if(numer==0 || denomer==0) {
                numer = 0;
                denomer = 0;
            }
            else{
                if(numer<0&&denomer<0){
                    numer *= -1;
                    denomer *= -1;
                }
                else if(denomer<0) numer*=-1;
            }
            num = numer;
            denom = denomer;
        };
        constexpr fraction(double number):num{}, denom{} {
            if(number==0){
                num = 0;
                denom = 0;
            }
            else if (number == int(number)) {
                fraction(number, 1);
            }
        };

        constexpr fraction(const fraction &other) = default;
        constexpr fraction(fraction &&other) = default;

        fraction &operator=(const fraction &other) = default;

        fraction &operator=(fraction &&other) = default;

        constexpr int numerator() const { return num; }
        constexpr int denominator() const { return denom; }

        constexpr explicit operator bool() const { return denom && num; }
        constexpr operator double() const { return double(num) / denom; }

        constexpr fraction operator+(const fraction &other) const;
        constexpr fraction operator-(const fraction &other) const;
        constexpr fraction operator*(const fraction &other) const;
        constexpr fraction operator/(const fraction &other) const;

        constexpr fraction operator+() const { return *this; };
        constexpr fraction operator-() const;

        fraction& operator+=(const fraction &other);
        fraction& operator-=(const fraction &other);
        fraction& operator*=(const fraction &other);
        fraction& operator/=(const fraction &other);

        friend std::ostream &operator<<(std::ostream &os, const fraction& self) {
            if(!self) os<<0;
            else if(self.denom==1) os << self.num;
            else os << self.num << '/' << self.denom;
            return os;
        }
};

constexpr fraction make_fraction(double value) {
    return value;
}

template<typename T, std::enable_if_t<std::is_arithmetic_v<decltype(std::declval<T>().scalar())>>>
constexpr fraction make_fraction(const T& value) {
    return value.scalar();
}

} // namespace engunits::maths

#endif