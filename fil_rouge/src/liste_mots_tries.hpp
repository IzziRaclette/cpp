#ifndef LISTE_MOTS_TRIES_HPP
#define LISTE_MOTS_TRIES_HPP

#include <list>
#include <string>


class ListeMotsTries {
public:
    using List = std::list<std::string>;
    using const_iterator = List::const_iterator;

private:
    List _liste;

public:
    void ajouterMot(std::string const & mot);
    void retirerMot(std::string const & mot);
    void inserer(const_iterator const & debut, const_iterator const & fin);
    int getNbMots() const;
    const_iterator debut() const;
    const_iterator fin() const;
};

std::ostream & operator<<(std::ostream & stream, ListeMotsTries const & liste);


#endif
