#include <vector>
#include <ctime>
#include "Personaje.h"
#include "Enemigo.h"
#include "EnemigoFinal.h"
#include <iostream>

using namespace std;

// Función para imprimir el nivel resaltando la posición actual en verde
void imprimirNivel(vector<vector<string>>& nivel, int posX, int posY) {
    for (int i = 0; i < nivel.size(); ++i) {
        for (int j = 0; j < nivel[i].size(); ++j) {
            if (i == posY && j == posX) {

                // Imprimir la posición actual en verde
                cout << "\033[32m" << nivel[i][j] << "\033[0m\t";
            }
            else {
                cout << nivel[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));

    vector<vector<string>> nivel = {
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " ", " ", " ", " "}
    };
    
    int salidaX = rand() % 8;
    nivel[7][salidaX] = "SALIDA";

    int numEnemigos = 5;
    for (int i = 0; i < numEnemigos; ++i) {
        int posX = rand() % 8;
        int posY = rand() % 8;
        nivel[posY][posX] = "ENEMIGO";
    }
    
    int guaridaX = rand() % 8;
    nivel[0][guaridaX] = "GUARIDA";
    
    int posX = 0;
    int posY = 7;
    Personaje jugador(500, 20, "Jugador", posX, posY);
    
    bool gameOver = false;
    bool ganado = false;
    
    cout << "=== Bienvenido al juego ===" << endl;
    cout << "El objetivo es llegar a la GUARIDA y derrotar al enemigo final." << endl;
    cout << "Buena suerte!" << endl;

    while (!gameOver && !ganado) {
        // Mostrar nivel resaltando la posición actual
        imprimirNivel(nivel, posX, posY);

        cout << "Vida del jugador: " << jugador.getVida() << endl;
       

        // Mover jugador
        char movimiento;
        cout << "Ingresa una direccion (W/A/S/D): ";
        cin >> movimiento;
        cin.ignore();
       
        switch (movimiento) {
        case 'w':
            if (jugador.getPosicionY() > 0) {
                jugador.setPosicionY(jugador.getPosicionY() - 1);
            }
            break;
        case 'a':
            if (jugador.getPosicionX() > 0) {
                jugador.setPosicionX(jugador.getPosicionX() - 1);
            }
            break;
        case 's':
            if (jugador.getPosicionY() < 7) {
                jugador.setPosicionY(jugador.getPosicionY() + 1);
            }
            break;
        case 'd':
            if (jugador.getPosicionX() < 7) {
                jugador.setPosicionX(jugador.getPosicionX() + 1);
            }
            break;
        default:
            cout << "Movimiento invalido. Intentalo de nuevo." << endl;
            continue;
        }
        
        // Verificar colisiones
        if (nivel[jugador.getPosicionY()][jugador.getPosicionX()] == "ENEMIGO") {
            Enemigo enemigo;
            cout << "Enemigo encontrado! Preparate para la batalla!" << endl;
            cout << "Jugador: " << jugador.getNombre() << " VS " << enemigo.getNombre() << endl;

            while (jugador.getVida() > 0 && enemigo.getVida() > 0) {
                // Turno del jugador
                cout << "Turno del jugador:" << endl;
                cout << "1. Atacar" << endl;
                cout << "2. Huir" << endl;
                
                int opcion;
                cin >> opcion;
                


                // Atacar
                if (opcion == 1) {
                    enemigo.setVida(enemigo.getVida() - jugador.getAtaque());
                    cout << "Has causado " << jugador.getAtaque() << " puntos de dano." << endl;
                }
                else if (opcion == 2) {
                    cout << "Has huido de la batalla." << endl;
                    jugador.setPosicionX(posX);
                    jugador.setPosicionY(posY);
                    break;
                }
                else {
                    cout << "Opcion invalida. Intentalo de nuevo." << endl;
                    continue;
                }

                // Turno del enemigo
                cout << "Turno del enemigo:" << endl;
                jugador.setVida(jugador.getVida() - enemigo.getAtaque());
                cout << "El enemigo te ha causado " << enemigo.getAtaque() << " puntos de dano." << endl;
            }

            // Verifica si el jugador ha perdido
            if (jugador.getVida() <= 0) {
                gameOver = true;
                cout << "Has sido derrotado! Fin del juego." << endl;
            }
            else {
                nivel[jugador.getPosicionY()][jugador.getPosicionX()] = " ";
                nivel[posY][posX] = " ";
            }
        }
        // Verifica si el jugador a llegado a la guarida 
        else if (nivel[jugador.getPosicionY()][jugador.getPosicionX()] == "GUARIDA") {
            EnemigoFinal enemigoFinal;
            cout << "Has llegado a la GUARIDA! Preparate para enfrentar al enemigo final!" << endl;
            cout << "Jugador: " << jugador.getNombre() << " VS " << enemigoFinal.getNombre() << endl;

            while (jugador.getVida() > 0 && enemigoFinal.getVida() > 0) {
                // Turno del jugador
                cout << "Turno del jugador:" << endl;
                cout << "1. Atacar" << endl;
                

                int opcion;
                cin >> opcion;
                
                // Atacar
                if (opcion == 1) {
                    enemigoFinal.setVida(enemigoFinal.getVida() - jugador.getAtaque());
                    cout << "Has causado " << jugador.getAtaque() << " puntos de dano." << endl;
                }
                else {
                    cout << "Opcion invalida. Intentalo de nuevo." << endl;
                    continue;
                }

                // Turno del enemigo final
                cout << "Turno del enemigo final:" << endl;
                jugador.setVida(jugador.getVida() - enemigoFinal.getAtaque());
                cout << "El enemigo final te ha causado " << enemigoFinal.getAtaque() << " puntos de dano." << endl;
            }
            // Verifica si el jugador ha perdido
            if (jugador.getVida() <= 0) {
                gameOver = true;
                cout << "Has sido derrotado! Fin del juego." << endl;
            }
            // Verifica si el jugador ha ganado
            else {
                ganado = true;
                nivel[jugador.getPosicionY()][jugador.getPosicionX()] = "JUGADOR";
                nivel[posY][posX] = " ";
                imprimirNivel(nivel, jugador.getPosicionX(), jugador.getPosicionY());
                cout << "Felicidades! Has derrotado al enemigo final y ganado el juego!" << endl;
            }
        }
        
        else if (nivel[jugador.getPosicionY()][jugador.getPosicionX()] == "SALIDA" && ganado) {
            gameOver = true;
            cout << "Has escapado con vida de la GUARIDA! Felicidades, has ganado el juego!" << endl;
        }
        else {
            nivel[jugador.getPosicionY()][jugador.getPosicionX()] = "JUGADOR";
            nivel[posY][posX] = " ";
            posX = jugador.getPosicionX();
            posY = jugador.getPosicionY();
        }
    }

    return 0;
}
