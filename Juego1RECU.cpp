#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Atributos player
string playername;
int HPplayer = 100;
int Haduken;
int Shoryuken;
int Ultimate = 65;
bool ultimateStatus = true;
bool playerIsAlive = true;


//Enemigo 1
string enemyName1 = "Ryu";
int HPenemy1 = 100;
int enemy1damage;
bool enemy1IsAlive = true;


//Enemigo 2
string enemyName2 = "Chun Li";
int HPenemy2 = 100;
int enemy2damage;
bool enemy2IsAlive = true;


void gamestart() {
	cout << "/////////////////////////////////////////////////\n";
	cout << "---------Bienvenidos a Street Fighter------------\n";
	cout << "/////////////////////////////////////////////////\n\n\n";
	cout << "Presiona cualquier tecla para continuar...";
	cin.get();
	system("cls");

	cout << "Introduce el nombre del Jugador: ";
	cin >> playername;
	cout << "El nombre del jugador es " << playername << "\n";

}


//Chequea si el enemigo 1 esta vivo
bool statusEnemy1() {
	if (HPenemy1 <= 0) {
		HPenemy1 = 0;
		enemy1IsAlive = false;
		return enemy1IsAlive;
	}
	else {
		return enemy1IsAlive;
	}
}


//Chequea si el enemigo 2 esta vivo
bool statusEnemy2() {
	if (HPenemy2 <= 0) {
		HPenemy2 = 0;
		enemy2IsAlive = false;
		return enemy2IsAlive;
	}
	else {
		return enemy2IsAlive;
	}
}
//Chequea si el jugador esta vivo
bool statusHero() {
	if (HPplayer <= 0){
		HPplayer = 0;
		playerIsAlive = false;
		return playerIsAlive;
	}
	else {
		return playerIsAlive;
	}
}
int selectAtaque;
int selectEnemigo;

void seleccionAtaqueEnemy1() {
	Haduken = rand() % 25;
	Shoryuken = rand() % 40;
	do {
		cout << "Que ataque quieres hacer?\n[1] Haduken\n[2] Shoryuken\n[3] Ultimate\n";
		cin >> selectAtaque;
	} while (selectAtaque != 1 && selectAtaque != 2 && selectAtaque !=3);
	if (selectAtaque== 1) {
		HPenemy1 -= Haduken;
		statusEnemy1();
		cout << "Le has hecho un Haduken a " << enemyName1 << " y le quedan " << HPenemy1 << " puntos de vida.\n";
	}
	else if (selectAtaque == 2) {
		HPenemy1 -= Shoryuken;
		statusEnemy1();
		cout << "Le has hecho un Shoryuken a "<< enemyName1 <<" y le quedan " << HPenemy1 << " puntos de vida.\n";
	}
	else if (selectAtaque == 3 && ultimateStatus) {
		HPenemy1 -= Ultimate;
		statusEnemy1();
		cout << "Le has tirado la Ultimate a " << enemyName1 << " y le quedan " << HPenemy1 << " puntos de vida\n Ya no puedes usar mas la Ultimate durante la partida.\n";
		ultimateStatus = false;
	}
	else if (selectAtaque == 3 && !ultimateStatus) {
		cout << "Ya no te queda la Ultimate, has gastado un ataque.\n";
	}
}

void seleccionAtaqueEnemy2() {
	Haduken = rand() % 25;
	Shoryuken = rand() % 40;
	do {
		cout << "Que ataque quieres hacer?\n[1] Haduken\n[2] Shoryuken\n[3] Ultimate\n";
		cin >> selectAtaque;
	} while (selectAtaque != 1 && selectAtaque != 2 && selectAtaque != 3);
	if (selectAtaque == 1) {
		HPenemy2 -= Haduken;
		statusEnemy2();
		cout << "Le has hecho un Haduken a " << enemyName2 << " y le quedan " << HPenemy2 << " puntos de vida.\n";
	}
	else if (selectAtaque == 2) {
		HPenemy2 -= Shoryuken;
		statusEnemy2();
		cout << "Le has hecho un Shoryuken a " << enemyName2 << " y le quedan " << HPenemy2 << " puntos de vida.\n";
	}
	else if (selectAtaque == 3 && ultimateStatus) {
		HPenemy2 -= Ultimate;
		statusEnemy2();
		cout << "Le has tirado la Ultimate a "<< enemyName2 <<" y le quedan " << HPenemy2 << " puntos de vida\n Ya no puedes usar mas la Ultimate durante la partida";
		ultimateStatus = false;
	}
	else if (selectAtaque == 3 && !ultimateStatus) {
		cout << "Ya no te queda la Ultimate, has gastado un ataque.\n";
	}
}

void ataqueEnemigo1AHero() {
	enemy1damage = rand() % 30 + 1;
	if (statusEnemy1()){
	HPplayer -= enemy1damage;
	cout << enemyName1 << " te ha quitado " << enemy1damage << ". Te quedan " << HPplayer << " puntos de vida\n";
	}
}

void ataqueEnemigo2AHero() {
	enemy2damage = rand() % 30 + 1;
	if (statusEnemy2()){
	HPplayer -= enemy2damage;
	cout << enemyName2 << " te ha quitado " << enemy2damage << ". Te quedan " << HPplayer << " puntos de vida\n";
	}
}
//Selecciona el enemigo y el ataque
void bucleJuego() {
	while (playerIsAlive && (enemy1IsAlive || enemy2IsAlive)){
	cout << "A que enemigo quieres atacar?\n[1] Ryu\n[2] Chun Ly\n";
	cin >> selectEnemigo;
	if (selectEnemigo == 1) {
		seleccionAtaqueEnemy1();
	}
	else if (selectEnemigo == 2) {
		seleccionAtaqueEnemy2();
	}
	ataqueEnemigo1AHero();
	ataqueEnemigo2AHero();
	statusHero();
	statusEnemy1();
	statusEnemy2();
	}
}


void finalJuego() {
	if (playerIsAlive) {
		cout << "ENHORABUENA, HAS GANADO!";
	}
	else {
		cout << "Vaya... Has perdido";
	}
}



int main()
{
	srand(time(NULL));
	gamestart();
	bucleJuego();
	finalJuego();
}


