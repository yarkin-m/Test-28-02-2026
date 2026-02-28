#include "int_array.h"
#include <iostream>
#include <cassert> 

void print_array(const IntArray& arr, const char* name) {
    std::cout << name << ": [";
    for (std::size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << "]\n";
}

int main() {
    IntArray a(5, 7);        // [7 7 7 7 7]
    a[2] = 42;
    print_array(a, "a");
    assert(a.size() == 5);

    IntArray b = a;
    b[2] = 1;
    print_array(b, "b - copy");
    print_array(a, "a rn");
    assert(a[2] == 42); 
    assert(b[2] == 1);

    IntArray c = std::move(a);
    print_array(c, "c - move");
    print_array(a, "a rn");
    assert(a.size() == 0);
    assert(c.size() == 5);
    assert(c[2] == 42);

    b.resize(2, 9);
    print_array(b, "b resize(2, 9)");
    assert(b.size() == 2);

    c.resize(15, 1234);
    print_array(c, "c resize(15, 1234)");
    assert(c.size() == 15);

    return 0;
}