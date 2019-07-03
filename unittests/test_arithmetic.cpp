#include<iostream>
#include<cassert>

#include "../engunits/length.h"

void almost_equal(double self, double other) {
    if (self==0 || other==0) {
        assert(self==other);
        return;
    }
    assert(self * 0.99 < other && other < self * 1.01);
}

int main() {
    using namespace std;
    using namespace EngUnits::length;

    cout << "---Testing Arithmetic Operations with Doubles---" << endl;
    cout << "Addition: ";
    meters mp{10};
    feet fp{20};
    inches ip{100.55};
    mp += 10;
    assert(mp.abs_val() == 20);
    fp += 20;
    assert(fp.abs_val() == 40);
    assert((meters{} + 5).abs_val() == 5);
    auto mpres = mp + 10;
    assert(mpres.abs_val() == 30);
    auto fpres = fp + 20;
    assert(fp.abs_val() == 60);

    cout << "success" << endl;

    cout << endl;
    cout << "All Tests Successfully Completed" << endl;

    return 0;
}