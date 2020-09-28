#ifndef ZZ_HPP
#define ZZ_HPP


#include <string>
#include <ostream>


class ZZ {
private:
    std::string _name, _firstname;
    double _note;

public:
    ZZ(std::string name, std::string firstname, double note);

    bool operator<(ZZ const & right) const;
    friend std::ostream & operator<<(std::ostream & stream, ZZ const & zz);

    class NoteComparator {
    public:
        bool operator()(ZZ const & left, ZZ const & right) const;
    };
};

//std::ostream & operator<<(std::ostream & stream, ZZ const & zz);


#endif
