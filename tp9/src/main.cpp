
#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>

#include "rand_0_100.hpp"
#include "zz.hpp"


int main() {
    std::vector<ZZ*> v;

    v.push_back(new ZZ("HABERT", "Eldred", 20));
    v.push_back(new ZZ("AMORIM", "Dylan", 17));
    v.push_back(new ZZ("JARILLON", "Bastien", 16));


    std::priority_queue<ZZ> names;
    std::priority_queue<ZZ, std::vector<ZZ>, ZZ::NoteComparator> notes;

    for(auto& zz : v) {
        names.push(*zz);
        notes.push(*zz);
    }

    for(; !names.empty(); names.pop())
        std::cout << names.top() << std::endl;
    std::cout << "~~~~~~~~~" << std::endl;
    for(; !notes.empty(); notes.pop())
        std::cout << notes.top() << std::endl;


    for(auto& zz : v) {
        std::cout << *zz << std::endl;
        delete zz;
    }
    v.clear();


    std::vector<int> rng;
    std::generate_n(back_inserter(rng), 50, Rand_0_100());

    std::copy(rng.begin(), rng.end(), std::ostream_iterator<int>(std::cout, ", "));

    return 0;
}
