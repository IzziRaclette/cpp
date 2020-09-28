#ifndef RAND_0_100_HPP
#define RAND_0_100_HPP


#include <random>


template<int min, int max>
class Rand {
private:
    std::minstd_rand _rng{};
    std::uniform_int_distribution<> _distrib{min, max};

public:
    int operator()() {
        return _distrib(_rng);
    }
};

using Rand_0_100 = Rand<0, 100>;


#endif
