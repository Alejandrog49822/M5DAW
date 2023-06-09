#ifndef LANCHAACUATICA_H
#define LANCHAACUATICA_H
#include <iostream>
#include <string>
using namespace std;

class LanchaAcuatica {

private:
    
    string nombre;
    int velocidad;
    int distanciaRecorrida;
    int nitroDisponible;

public:
    
    string getNombre() ;
    int getVelocidad() ;
    int getDistanciaRecorrida();
    int getNitroDisponible();

    
    string setNombre(string pNombre);
    int setVelocidad(int pVelocidad) ;
    int setDistanciaRecorrida(int pDistanciaRecorrida) ;
    int setNitroDisponible(int pNitroDisponible);

    
    void lanzarDado();
    bool puedeUsarNitro() ;
    void usarNitro();
    void calcularDistanciaRecorrida();    

   
    LanchaAcuatica(string pNombre, int pVelocidad, int pDistanciaRecorrida, int pNitroDisponible);
};

#endif
