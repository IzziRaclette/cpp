
#include <queue>
#include <iterator>
#include <iostream>

#include "zz.hpp"


int main() {
    std::vector<ZZ*> v;

    v.push_back(new ZZ("JARILLON", "Bastien", 16));
    v.push_back(new ZZ("HABERT", "Eldred", 20));


    std::priority_queue<ZZ> pq;

    for(auto& zz : v)
        pq.push(*zz);

    for(; !pq.empty(); pq.pop())
        std::cout << pq.top() << std::endl;


    for(auto& zz : v)
        delete zz;
    v.clear();


    return 0;
}
