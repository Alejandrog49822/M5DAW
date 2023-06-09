#ifndef LANCHAACUATICA_H
#define LANCHAACUATICA_H
#include <iostream>
#include <string>
using namespace std;

class LanchaAcuatica {

private:
    // Atributos
    string nombre;
    int velocidad;
    int distanciaRecorrida;
    int nitroDisponible;

public:
    //Getters
    string getNombre() ;
    int getVelocidad() ;
    int getDistanciaRecorrida();
    int getNitroDisponible();

    //Seters
    string setNombre(string pNombre);
    int setVelocidad(int pVelocidad) ;
    int setDistanciaRecorrida(int pDistanciaRecorrida) ;
    int setNitroDisponible(int pNitroDisponible);

    // Métodos
    void lanzarDado();
    bool puedeUsarNitro() ;
    void usarNitro();
    void calcularDistanciaRecorrida();    

    // Constructor
    LanchaAcuatica(string pNombre, int pVelocidad, int pDistanciaRecorrida, int pNitroDisponible);
};

#endif
