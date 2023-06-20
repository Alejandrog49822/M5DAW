#include "Enemigo.h"


using namespace std;


//Getters
int Enemigo::getVida() const {
    return vida;
}

int Enemigo::getAtaque() const {
    return ataque;
}

string Enemigo::getNombre() const {
    return nombre;
}

//Setters
void Enemigo::setVida(int pVida) {
    vida = pVida;
}

void Enemigo::setAtaque(int pAtaque) {
    ataque = pAtaque;
}

void Enemigo::setNombre(const string& pNombre) {
    nombre = pNombre;
}

//Constructor
Enemigo::Enemigo() {
    vida = 100;
    ataque = 20;
    nombre = "Enemigo";
}
