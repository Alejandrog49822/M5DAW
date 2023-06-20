#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
using namespace std;


class Personaje {
    private:
        int vida;
        int ataque;
        string nombre;
        int posicionX;
        int posicionY;
        // Constructor
    public:
        Personaje(int pVida, int pAtaque, string pNombre, int pPosicionX, int pPosicionY);


        // Getters
        int getVida() const;
        int getAtaque() const;
        string getNombre() const;
        int getPosicionX() const;
        int getPosicionY() const;

        // Setters
        void setVida(int pVida);
        void setAtaque(int pAtaque);
        void setNombre(const string& pNombre);
        void setPosicionX(int pPosicionX);
        void setPosicionY(int pPosicionY);
};

#endif
