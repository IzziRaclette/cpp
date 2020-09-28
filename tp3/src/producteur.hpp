#ifndef PRODUCTEUR_HPP
#define PRODUCTEUR_HPP

class Producteur {
private:
    int _travail;

public:
    Producteur(void);

public:
    int getTravail(void) const;
    void produire(unsigned nbNombres, char const * fileName);
};

#endif
