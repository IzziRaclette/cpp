
#include <catch2/catch.hpp>
#include <iostream>

#include "cercle.hpp"
#include "dictionnaire.hpp"
#include "forme.hpp"
#include "liste.hpp"
#include "liste_mots_tries.hpp"
#include "point.hpp"
#include "rectangle.hpp"


TEST_CASE("Instanciation", "[Point]") {
    Point p1;
    REQUIRE(p1.getX() == 0);
    REQUIRE(p1.getY() == 0);

    p1.setX(11);
    p1.setY(21);

    REQUIRE(p1.getX() == 11);
    REQUIRE(p1.getY() == 21);

    Point p2(12, 22);

    REQUIRE(p2.getX() == 12);
    REQUIRE(p2.getY() == 22);
}

TEST_CASE("Point::origine", "[Point]") {
    REQUIRE(Point::origine.getX() == 0);
    REQUIRE(Point::origine.getY() == 0);
}


TEST_CASE("Polymorphisme", "[Forme]") {
    Forme * f1 = new Cercle;
    Forme * f2 = new Rectangle;

    REQUIRE(f1->toString() == "Cercle((0, 0), BLEU, 0)");
    REQUIRE(f2->toString() == "Rectangle(0, 0, 0, 0)");

    delete f1;
    delete f2;
}


TEST_CASE("Cercle", "[Cercle]") {
    int compteur = Forme::prochainID();
    Cercle c1;
    Cercle c2(Point(1, 2), Couleur::BLEU, 3);

    REQUIRE(c1.toString() == "Cercle((0, 0), BLEU, 0)");
    REQUIRE(c2.toString() == "Cercle((-2, -1), BLEU, 3)");

    c2.setRayon(4);
    REQUIRE(c2.getRayon()   == 4);
    REQUIRE(c2.toString()   == "Cercle((-3, -2), BLEU, 4)");
    REQUIRE(c2.getLargeur() == 8);
    REQUIRE(c2.getHauteur() == 8);

    REQUIRE(Forme::prochainID() == (compteur+2) );
}

TEST_CASE ( "ListeMT1" ) {
    ListeMotsTries liste;

    REQUIRE( 0 == liste.getNbMots() );
    liste.ajouterMot("effacer");
    REQUIRE( 1 == liste.getNbMots() );
    liste.ajouterMot("inserer");
    REQUIRE( 2 == liste.getNbMots() );
    liste.ajouterMot("ajout");
    REQUIRE( 3 == liste.getNbMots() );


    ListeMotsTries::const_iterator it = liste.debut();

    REQUIRE( *it == "ajout" );
    ++it;
    REQUIRE( *it == "effacer" );
    ++it;
    REQUIRE( *it ==  "inserer" );
    ++it;
    REQUIRE( it == liste.fin() );

    liste.retirerMot("effacer");
    REQUIRE( 2 == liste.getNbMots() );
    liste.retirerMot("inserer");
    REQUIRE( 1 == liste.getNbMots() );
    liste.retirerMot("ajout");
    REQUIRE( 0 == liste.getNbMots() );

    REQUIRE( liste.debut() == liste.fin() );
}

TEST_CASE ( "ListeMT2" ) {
    ListeMotsTries liste1, liste2;

    liste1.ajouterMot("essai 1 a");
    liste1.ajouterMot("essai 1 b");
    liste2.inserer(liste1.debut(), liste1.fin());

    ListeMotsTries liste3;
    liste3.ajouterMot("essai 1 b");
    liste3.ajouterMot("essai 2 a");
    liste3.ajouterMot("essai 2 c");
    liste2.inserer(liste3.debut(), liste3.fin());

    std::cout << liste2 << std::endl;
}

TEST_CASE("Dictionnaire") {
    Dictionnaire dict;

    std::cout << dict << std::endl;
}
