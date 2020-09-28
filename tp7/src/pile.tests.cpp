
#include <catch2/catch.hpp>

#include <iostream>
#include <sstream>
#include <cstring>

#include "pile.hpp"

TEST_CASE("Pile: Constructeur par defaut") {
    Pile<int> p; // cela implique que par defaut la capacite de la pile n'est pas nulle => pas d exception

    CHECK(p.empty());
    CHECK(0 == p.size());
}

TEST_CASE("Pile: Exceptions de mauvaise construction") {

    REQUIRE_THROWS_AS(Pile<int>(-1).empty(), std::invalid_argument);
    REQUIRE_THROWS_AS(Pile<int>( 0).empty(), std::invalid_argument);

}

TEST_CASE("Pile: Exception pile vide") {
    REQUIRE_THROWS_AS(Pile<int>().pop(), std::out_of_range);
}

TEST_CASE("Pile: Live pile") {
    Pile<int> p(10);

    CHECK(p.empty());
    CHECK(0 == p.size());

    p.push(5);

    CHECK(!p.empty());
    CHECK(1 == p.size());
    CHECK(5 == p.top());

    p.push(2);
    p.push(1);

    CHECK(3 == p.size());
    CHECK(1 == p.top());

    p.pop();

    CHECK(2 == p.size());
    CHECK(2 == p.top());

    p.pop();
    p.pop();

    CHECK(0 == p.size());
}
