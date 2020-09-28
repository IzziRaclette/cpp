#ifndef ZZ_HPP
#define ZZ_HPP


#include <string>
#include <ostream>


class ZZ {
private:
    std::string _nom, _prenom;
    double _note;

public:
    ZZ(std::string nom, std::string prenom, double note);

    bool operator<(ZZ const & right) const;
    friend std::ostream & operator<<(std::ostream & stream, ZZ const & zz);
};

std::ostream & operator<<(std::ostream & stream, ZZ const & zz);


#endif
