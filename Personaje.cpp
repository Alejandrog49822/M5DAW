#include "Personaje.h"
using namespace std;

//Constructor
Personaje::Personaje(int pVida, int pAtaque, string pNombre, int pPosicionX, int pPosicionY)
    : vida(pVida), ataque(pAtaque), nombre(pNombre), posicionX(pPosicionX), posicionY(pPosicionY) {}


//Getters
int Personaje::getVida() const {
    return vida;
}

string Personaje::getNombre() const {
    return nombre;
}

int Personaje::getPosicionY() const {
    return posicionY;
}

int Personaje::getAtaque() const {
    return ataque;
}

int Personaje::getPosicionX() const {
    return posicionX;
}



//Setters
void Personaje::setVida(int pVida) {
    vida = pVida;
}
void Personaje::setAtaque(int pAtaque) {
    ataque = pAtaque;
}
void Personaje::setPosicionX(int pPosicionX) {
    posicionX = pPosicionX;
}
void Personaje::setNombre(const string& pNombre) {
    nombre = pNombre;
}
void Personaje::setPosicionY(int pPosicionY) {
    posicionY = pPosicionY;
}
