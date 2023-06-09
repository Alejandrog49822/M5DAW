#include <iostream>
#include <vector>
#include <ctime>
#include "LanchaAcuatica.h"
using namespace std;

int main() {
    srand(time(0));

    int numLanchas;
    cout << "Ingrese el numero de lanchas: ";
    cin >> numLanchas;
    cin.ignore();

    vector<LanchaAcuatica> lanchas;
    for (int i = 0; i < numLanchas; ++i) {
        string nombre;
        cout << "Ingrese el nombre de la lancha " << i + 1 << ": ";
        getline(cin, nombre);
        LanchaAcuatica lancha(nombre, 0, 0, 1);
        lanchas.push_back(lancha);
    }

    cout << "\nComienza la carrera!" << endl;

    for (int turno = 1; turno <= 5; ++turno) {
        cout << "\n\033[32m=== Turno " << turno << " ===\033[0m" << endl;

        for (LanchaAcuatica& lancha : lanchas) {
            cout << "\nTurno de " << lancha.getNombre() << endl;
            lancha.lanzarDado();

            cout << "Velocidad actual: " << lancha.getVelocidad() << endl;

            if (lancha.puedeUsarNitro()) {
                char opcion;
                cout << "Desea usar el nitro? (s/n): ";
                cin >> opcion;
                opcion = tolower(opcion);
                cin.ignore();

                if (opcion == 's') {
                    lancha.usarNitro();
                }
            }

            lancha.calcularDistanciaRecorrida();
            cout << "Distancia recorrida: " << lancha.getDistanciaRecorrida() << endl;
        }
    }

    
    int maxDistancia = 0;
    vector<string> ganadores;

    for (LanchaAcuatica& lancha : lanchas) {
        if (lancha.getDistanciaRecorrida() > maxDistancia) {
            maxDistancia = lancha.getDistanciaRecorrida();
            ganadores.clear();
            ganadores.push_back(lancha.getNombre());
        }
        else if (lancha.getDistanciaRecorrida() == maxDistancia) {
            ganadores.push_back(lancha.getNombre());
        }
    }

    cout << "\n=== Resultados ===" << endl;
    cout << "Distancia maxima recorrida: " << maxDistancia << endl;
    if (ganadores.size() == 1) {
        cout << "El ganador es: " << ganadores[0] << "!" << endl;
    }
    else {
        cout << "Ha habido un empate entre los siguientes corredores:" << endl;
        for (string& ganador : ganadores) {
            cout << "- " << ganador << endl;
        }
    }
}
