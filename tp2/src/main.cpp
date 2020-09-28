#include <iostream>

class Bavarde {
    //
    // Mettre votre code ici
    //
} bizarre(1);

Bavarde globale(2);

void fonction(Bavarde b) {
    std::cout << "code de la fonction";
}

int main(int, char **) {
    Bavarde b;
    Bavarde * p = new Bavarde(3);
    // fonction(b);

    return 0;
}
