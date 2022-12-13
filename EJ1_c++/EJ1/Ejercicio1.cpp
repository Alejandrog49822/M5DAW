// Ejercicio1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <stdlib.h>
#include <ctime>//en c++
#include<time.h>
using namespace std;

//Atributos del enemigo
int enemyHP = 100;
string enemyName = "Bowser";
bool enemyIsAlive = true;
int enemyDamage;

//Atributos enemigo 2
int enemy2HP = 100;
string enemy2Name = "Waluigi";
bool enemy2IsAlive = true;
int enemy2Damage;


//Atributos de héroe
string heroName;
int heroDamage;
int heroHP = 500;
bool heroIsAlive = true;

//Ataques Heroe


int main()
{
    srand(time(NULL));
    cout << "Un " << enemyName << " acaba de aparecer y tiene " << enemyHP << " puntos de vida\n";

    cout << enemyName << "No esta solo! ha aparecido" << enemy2Name << "y tiene" << enemy2HP << "puntos de vida\n";

    cout << "Como se llama el heroe?\n";
    cin >> heroName;
    cout << "El nombre del heroe es " << heroName << "\n";
 
    while(enemyIsAlive && heroIsAlive){
        int enemyDamage = 1 + rand() % 80;
                cout << "Cuanto danyo quieres hacer al " << enemyName << "?\n";
                cin >> heroDamage;
                enemyHP = enemyHP - heroDamage;


                if (enemyHP <= 0)
                {
                    cout << "Has eliminado a " << enemyName << "\n";
                    enemyIsAlive = false;
                }

                else {
                    cout << "Al enemigo " << enemyName << " le quedan " << enemyHP << " puntos de vida\n";
                }

                if (enemyIsAlive) {
                    //ATACO AL HÉROE
                    heroHP = heroHP - enemyDamage;

                    if (heroHP <= 0) {
                        heroHP = 0;
                        cout << "El enemigo " << enemyName << " te ha dado matarile\n";
                    }
                    else {
                        cout << "El enemigo " << enemyName << " te ha hecho un ataque de " << enemyDamage << " puntos de danyo. Te quedan " << heroHP << "  puntos de vida\n";
                    }

                }
    }
}
