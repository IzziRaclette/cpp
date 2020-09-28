
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <iostream>

#include "producteur.hpp"
#include "statisticien.hpp"


TEST_CASE("Init producteur") {
    Producteur p;
    REQUIRE(p.getTravail() == 0);
}

TEST_CASE("Comptage travail producteur") {
    Producteur p;
    p.produire(10, "test01.txt");
    p.produire(10, "test01.txt");
    p.produire(10, "test01.txt");
    REQUIRE(p.getTravail() == 3);
}

TEST_CASE("Résultat travail producteur") {

    const int         DEMANDE    = 10;
    const std::string NOM_FICHIER("test01.txt");
    int               lecture, i;
    Producteur        p;


    p.produire(DEMANDE, NOM_FICHIER.c_str());

    std::ifstream fichier(NOM_FICHIER.c_str());

    REQUIRE(fichier.is_open());

    if (!fichier.eof()) {
        fichier >> lecture;
        REQUIRE(DEMANDE == lecture);
        for (i = 0; i < DEMANDE; ++i) {
            fichier >> lecture;
            REQUIRE(lecture == (i+1));
        }

        REQUIRE(i == DEMANDE);
        // CHECK(fichier.eof());
        fichier.close();

        REQUIRE(p.getTravail() == 1);
    }
}

TEST_CASE("Init statisticien") {
    Statisticien p;
    REQUIRE_FALSE(p.aCalcule());
}
