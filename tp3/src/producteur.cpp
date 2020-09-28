
#include <string>
#include <fstream>

#include "producteur.hpp"


Producteur::Producteur(void) : _travail(0) {}

int Producteur::getTravail(void) const {
    return _travail;
}

void Producteur::produire(unsigned nbNombres, char const * fileName) {
    _travail++;

    std::ofstream output(fileName);
    output << nbNombres << std::endl;
    for(unsigned i = 1; i <= nbNombres; i++) {
        output << i << std::endl;
    }
    output.close();
}
