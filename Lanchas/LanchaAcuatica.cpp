#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LanchaAcuatica.h"

LanchaAcuatica::LanchaAcuatica(string pNombre, int pVelocidad, int pDistanciaRecorrida, int pNitroDisponible)  {
    nombre = pNombre;
    velocidad = pVelocidad;
    distanciaRecorrida = pDistanciaRecorrida;
    nitroDisponible = pNitroDisponible;
}

string LanchaAcuatica::getNombre()  {
    return nombre;
}

int LanchaAcuatica::getVelocidad()  {
    return velocidad;
}

int LanchaAcuatica::getDistanciaRecorrida()  {
    return distanciaRecorrida;
}

int LanchaAcuatica::getNitroDisponible() {
    return nitroDisponible;
}


string LanchaAcuatica::setNombre(string pName)  {
	nombre = pName;
    return nombre;
}

int LanchaAcuatica::setVelocidad(int pVelocidad)  {
	velocidad = pVelocidad;
	return velocidad;
}

int LanchaAcuatica::setDistanciaRecorrida(int pDistanciaRecorrida)  {
	distanciaRecorrida = pDistanciaRecorrida;
	return distanciaRecorrida;
}

int LanchaAcuatica::setNitroDisponible(int pNitroDisponible) {
	nitroDisponible = pNitroDisponible;
	return nitroDisponible;
}


void LanchaAcuatica::lanzarDado() {
    int puntosDado = rand() % 6 + 1;
    velocidad += puntosDado;
}

bool LanchaAcuatica::puedeUsarNitro()  {
    return nitroDisponible > 0;
}

void LanchaAcuatica::usarNitro() {
    nitroDisponible--;
    int aleatorio = rand() % 2;
    if (aleatorio == 0) {
        velocidad /= 2;
        cout << nombre << " ha usado el nitro pero ha fallado. Velocidad reducida a la mitad." << endl;
    }
    else {
        velocidad *= 2;
        cout << nombre << " ha usado el nitro y ha tenido Exito. Velocidad duplicada." << endl;
    }
}

void LanchaAcuatica::calcularDistanciaRecorrida() {
    distanciaRecorrida += velocidad * 100;
}
