#include "Vector.h"
#include <iostream>

int main() {
    Vector v1;
    std::cout << "Empty vector: " << v1 << std::endl;

    Vector v2(3);
    std::cout << "Vector of size 3: " << v2 << std::endl;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    std::cout << "v1 after push_back: " << v1 << std::endl;

    v1.push_front(0);
    std::cout << "v1 after push_front: " << v1 << std::endl;

    v1.insert(2, 10);
    std::cout << "v1 after insert at 2: " << v1 << std::endl;

    v1.erase(1);
    std::cout << "v1 after erase at 1: " << v1 << std::endl;

    Vector v3 = v1;
    std::cout << "v3 (copy of v1): " << v3 << std::endl;

    std::cout << "v1 == v3: " << (v1 == v3 ? "true" : "false") << std::endl;
    v3.push_back(4);
    std::cout << "v1 == v3 after change: " << (v1 == v3 ? "true" : "false") << std::endl;

    Vector v4(4);
    v4[0] = 1; v4[1] = 2; v4[2] = 3; v4[3] = 4;
    Vector v5(4);
    v5[0] = 5; v5[1] = 6; v5[2] = 7; v5[3] = 8;

    Vector sum = v4 + v5;
    std::cout << "v4 + v5: " << sum << std::endl;

    Vector prod = v4 * v5;
    std::cout << "v4 * v5: " << prod << std::endl;

    Vector v6(3);
    Vector invalid_sum = v4 + v6;
    std::cout << "Invalid sum (different sizes): " << invalid_sum << std::endl;

    return 0;
}