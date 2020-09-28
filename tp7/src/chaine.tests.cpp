
#include <catch2/catch.hpp>

#include <iostream>
#include <sstream>
#include <cstring>

#include "chaine.hpp"


TEST_CASE("Constructeur par defaut") {
    Chaine c;
    REQUIRE(c.getCapacite() == -1);
    REQUIRE(c.c_str() == nullptr);
}

TEST_CASE("Verification des const sur les accesseurs") {
    const Chaine c;
    CHECK(c.getCapacite() == -1);
    CHECK(c.c_str() == nullptr);
}

TEST_CASE("Constructeur par chaine C") {
    char source[] = "rien";
    Chaine c1(source);
    CHECK(strlen(source) == c1.getCapacite());
    CHECK(strcmp(source, c1.c_str()) == 0);

    Chaine c2("");
    CHECK(c2.getCapacite() == 0);
    CHECK(strcmp("", c2.c_str()) == 0);

    // Verifier que la liberation memoire est bien faite
}

TEST_CASE("Constructeur avec capacite") {
    Chaine c1(6);
    CHECK(c1.getCapacite() == 6);
    CHECK(strlen(c1.c_str()) == 0);

    // Verifier que la liberation memoire est bien faite
}

TEST_CASE("Constructeur de copie") {
    Chaine s1(10);   // une chaine vide
    Chaine s2 = s1;  // une autre chaine vide

    CHECK(s1.getCapacite() == s2.getCapacite());
    // tous les problemes vont venir de la
    // j'ai converti en void * uniquement pour l'affichage de catch
    CHECK((void *)s1.c_str() != (void *)s2.c_str());
    CHECK(strcmp(s1.c_str(), s2.c_str()) == 0);
}

TEST_CASE("methode afficher") {
    const char * original("une chaine a tester");
    const Chaine c1(original);
    std::stringstream ss;

    c1.afficher(); // on verifie juste que ca compile
    c1.afficher(ss);

    CHECK(ss.str() == original); //  test de std::string :-)
}

TEST_CASE("operateur d'affectation") {
    Chaine s1("une premiere chaine");
    Chaine s2("une deuxieme chaine plus longue que la premiere");

    s1 = s2;

    CHECK(s1.getCapacite() == s2.getCapacite());
    CHECK((void *)s1.c_str() != (void *)s2.c_str());
    CHECK(strcmp(s1.c_str(), s2.c_str()) == 0);

    s1 = s1; // est ce que cela va survivre a l execution ?
}

TEST_CASE("Surcharge <<") {
    const char * chaine = "une nouvelle surcharge";
    Chaine s(chaine);
    std::stringstream ss;
    ss << s;

    CHECK(ss.str() == chaine); //  test de std::string, again :-))
}

TEST_CASE("Operateur subscript") {
    Chaine s("Parce que X");

    CHECK(s[10] == 'X');

    s[10] = '4';
    CHECK(s[10] == '4');
}

TEST_CASE("Operateur subscript const") {
    Chaine const s = "21 est-il premier ?"; // Oui

    CHECK(s[18] == '?');
}

TEST_CASE("Operateur concatenation") {
    Chaine s1("La réponse");
    Chaine s2(" est oui !");

    CHECK(strcmp((s1 + s2).c_str(), "La réponse est oui !") == 0);
}

TEST_CASE("exceptions aux bornes") {
  Chaine s(10);

  REQUIRE_THROWS_AS(s[-1] == 0, std::out_of_range);
  REQUIRE_THROWS_AS(s[12] == 0, std::out_of_range);
}

TEST_CASE("exception sur pointeur null") {
  Chaine s = nullptr;

  // verification que l'heritage est bien fait
  std::logic_error * pe = new Chaine::null_ptr;
  delete pe;

  REQUIRE_THROWS_AS(s[1] == 0, Chaine::null_ptr);
}
