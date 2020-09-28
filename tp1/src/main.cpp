#include <iostream>
#include "point.hpp"
#include "vector.hpp"

int main(int, char **) {
    Point A{2, 0};
    Point B{2, 1};
    Point C{1, 2};

    std::cout << "A: " << A << std::endl;
    std::cout << "B: " << B << std::endl;
    std::cout << "C: " << C << std::endl;

    Vector AB = B - A;
    Vector BC = C - B;
    Vector AO = 2 *(BC - AB);

    std::cout << "AB: " << AB << std::endl;
    std::cout << "BC: " << BC << std::endl;
    std::cout << "AO: " << AO << std::endl;

    Point O = A + AO;

    std::cout << "O: " << O << std::endl;

    return 0;
}
