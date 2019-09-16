#include<iostream>

#include <engunits/engunits.h>

template<typename C>
struct DummyTemplate{
};

int main() {
    using namespace engunits;
    using namespace traits;

    static_assert(is_unit_v<distance::feet>);
    static_assert(is_unit_v<mass::kilograms>);
    static_assert(!is_unit_v<int>);
    static_assert(!is_unit_v<double>);
    static_assert(is_unit_of_type_v<distance::feet, distance::DistanceUnit>);
    static_assert(!is_unit_of_type_v<distance::feet, mass::MassUnit>);
    static_assert(!is_unit_of_type_v<int, distance::DistanceUnit>);
    static_assert(!is_unit_of_type_v<distance::feet, DummyTemplate>);

    std::cout << "All trait tests passed" << '\n';

    return 0;
}