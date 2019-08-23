#ifndef __ENGUNITS_ABSTRACT_DISTANCE_H
#define __ENGUNITS_ABSTRACT_DISTANCE_H

#include "../../engunits/_abstract/abstract_base.h"
#include "../../engunits/_abstract/abstract_speed.h"
#include "../../engunits/_abstract/abstract_time.h"

namespace engunits::distance{
class meters; //forward declaration

//Child of this class is GrandChild of base class(PhysicalUnit)
template<typename Child=meters> //TODO: constrain to children of this class
class DistanceUnit: public abstract::PhysicalUnit<DistanceUnit, Child> {
    protected:
        using abstract::PhysicalUnit<DistanceUnit, Child>::PhysicalUnit;

    public:
        using si_t = meters;

        constexpr DistanceUnit<Child>(const DistanceUnit<Child> &other) : abstract::PhysicalUnit<DistanceUnit, Child>{other.val} {};
        constexpr DistanceUnit<Child>(DistanceUnit<Child> &&other) : abstract::PhysicalUnit<DistanceUnit, Child>{other.val} {};
        template <typename T>
        constexpr DistanceUnit<Child>(const DistanceUnit<T> &other) : abstract::PhysicalUnit<DistanceUnit, Child>{(convert<Child>(other))} {};
        template<typename T>
        constexpr DistanceUnit<Child>(DistanceUnit<T> &&other) : abstract::PhysicalUnit<DistanceUnit, Child>{(convert<Child>(other))} {};

        virtual const std::string symbol() const = 0;

        Child &operator=(const double &value) {this->val=value; return *static_cast<Child*>(this);}
        Child &operator=(const DistanceUnit<Child> &other) { this->val = other.val; return *static_cast<Child*>(this);}
        Child &operator=(DistanceUnit<Child> &&other) { this->val = other.val; return *static_cast<Child*>(this);}  
        
};

class meters : public DistanceUnit<meters> {
    public:
        using DistanceUnit<meters>::DistanceUnit;

        static constexpr double conversion = 1;

        const std::string symbol() const override { return "m"; }
};

}//namespace engunits::distance

#define SPEED typename engunits::speed::meters_per_second
#define TIME typename engunits::time::seconds
#define DISTANCE typename engunits::distance::meters

constexpr SPEED operator*(const DISTANCE& distance, const TIME& time) {
    return distance.scalar() * time.scalar();
}

#undef SPEED
#undef TIME
#undef DISTANCE

#endif