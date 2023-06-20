#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <string>
using namespace std;

class Enemigo {
private:
    int vida;
    int ataque;
    string nombre;

public:
    // Constructor
    Enemigo();

    // Getters
    int getVida() const;
    int getAtaque() const;
    string getNombre() const;

    // Setters
    void setVida(int pVida);
    void setAtaque(int pAtaque);
    void setNombre(const string& pNombre);
};

#endif
