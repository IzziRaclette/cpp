#include <iostream>

class Exponent {
public:
    Exponent(int x) : _number(x) {}

private:
    int _number;

public:
    operator int() const { return _number; };
};

class Number {
public:
    Number(int x) : _number(x) {}

private:
    int _number;

public:
    operator int() const { return _number; };

    Exponent operator*() const { return Exponent(_number); };

    int operator*(Exponent const& exponent) const {
        int retval = 1;
        for(int i = 0; i < exponent; i++)
            retval *= _number;
        return retval;
    };
};


int main(int, char **) {
    Number x{3}, y{3};

    std::cout << x + y << std::endl;

    std::cout << x *(* y) << std::endl;

    return 0;
}
