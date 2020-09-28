#ifndef DICTIONNAIRE_HPP
#define DICTIONNAIRE_HPP


class ListeMotsTries;

#include <map>
#include <ostream>

#include "liste_mots_tries.hpp"


class Dictionnaire
{
private:
    std::map<char, ListeMotsTries> _dict;

public:
    Dictionnaire();

public:
    void ajouterMot(std::string const & mot);
    void retirerMot(std::string const & mot);
    int getNbMots() const;
    ListeMotsTries rechercherMots(std::string const & mot);

    friend std::ostream & operator<<(std::ostream & stream, Dictionnaire const & dict);
};

std::ostream & operator<<(std::ostream & stream, Dictionnaire const & dict);


#endif
