#ifndef CHAINE_HPP
#define CHAINE_HPP

#include <cstddef>

class Chaine {
public:
    Chaine(char const * str = nullptr);
    explicit Chaine(size_t capacite);
    Chaine(Chaine const & other);
    Chaine(Chaine && other);
    ~Chaine();

private:
    size_t _capacite;
    char * _tab;

public:
    size_t getCapacite(void) const;
    char const * c_str(void) const;
    void afficher(std::ostream & stream = std::cout) const;
private:
    void setStr(char const * str);

public:
    Chaine & operator=(Chaine str);
    friend void swap(Chaine & str1, Chaine & str2);
    char operator[](int i) const;
    char & operator[](int i);


    struct null_ptr : std::logic_error {
        using std::logic_error::logic_error;
        null_ptr(): logic_error{""} {}
    };
};


void afficherParValeur(Chaine const & str);
void afficherParValeur(Chaine const & str, std::ostream & stream);


std::ostream & operator<<(std::ostream & stream, Chaine const & str);
Chaine operator+(Chaine const & str1, Chaine const & str2);

#endif
