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


void gamestart(string pPlayerName) {
	cout << "/////////////////////////////////////////////////\n";
	cout << "---------Bienvenidos a Street Fighter------------\n";
	cout << "/////////////////////////////////////////////////\n\n\n";
	cout << "Presiona cualquier tecla para continuar...";
	cin.get();
	system("cls");

	cout << "Introduce el nombre del Jugador: ";
	cin >> pPlayerName;
	cout << "El nombre del jugador es " << pPlayerName << "\n";

}


//Chequea si el enemigo 1 esta vivo
bool statusEnemy1(int& pHPenemy1, bool& pEnemy1IsAlive) {
	if (pHPenemy1 <= 0) {
		pHPenemy1 = 0;
		pEnemy1IsAlive = false;
		return pEnemy1IsAlive;
	}
	else {
		return pEnemy1IsAlive;
	}
}


//Chequea si el enemigo 2 esta vivo
bool statusEnemy2(int& pHPenemy2, bool& pEnemy2IsAlive) {
	if (pHPenemy2 <= 0) {
		pHPenemy2 = 0;
		pEnemy2IsAlive = false;
		return pEnemy2IsAlive;
	}
	else {
		return pEnemy2IsAlive;
	}
}
//Chequea si el jugador esta vivo
bool statusHero(int& pHPplayer, bool& pPlayerIsAlive) {
	if (pHPplayer <= 0) {
		pHPplayer = 0;
		pPlayerIsAlive = false;
		return pPlayerIsAlive;
	}
	else {
		return pPlayerIsAlive;
	}
}
int selectAtaque;
int selectEnemigo;

void seleccionAtaqueEnemy1(int pHaduken, int pShoryuken, int pUltimate, int pSelectataque, string pEnemyName1, int& pHpenemy1) {
	pHaduken = rand() % 25;
	pShoryuken = rand() % 40;
	do {
		cout << "Que ataque quieres hacer?\n[1] Haduken\n[2] Shoryuken\n[3] Ultimate\n";
		cin >> pSelectataque;
	} while (pSelectataque != 1 && pSelectataque != 2 && pSelectataque != 3);
	if (pSelectataque == 1) {
		pHpenemy1 -= pHaduken;
		statusEnemy1(HPenemy1, enemy1IsAlive);
		cout << "Le has hecho un Haduken a " << pEnemyName1 << " y le quedan " << pHpenemy1 << " puntos de vida.\n";
	}
	else if (pSelectataque == 2) {
		pHpenemy1 -= pShoryuken;
		statusEnemy1(HPenemy1,enemy1IsAlive);
		cout << "Le has hecho un Shoryuken a " << pEnemyName1 << " y le quedan " << pHpenemy1 << " puntos de vida.\n";
	}
	else if (pSelectataque == 3 && ultimateStatus) {
		pHpenemy1 -= pUltimate;
		statusEnemy1(HPenemy1, enemy1IsAlive);
		cout << "Le has tirado la Ultimate a " << pEnemyName1 << " y le quedan " << pHpenemy1 << " puntos de vida\n Ya no puedes usar mas la Ultimate durante la partida.\n";
		ultimateStatus = false;
	}
	else if (pSelectataque == 3 && !ultimateStatus) {
		cout << "Ya no te queda la Ultimate, has gastado un ataque.\n";
	}
}

void seleccionAtaqueEnemy2(int pHaduken, int pShoryuken, int pUltimate, int pSelectataque, string pEnemyName2, int& pHPenemy2, bool& pUltimateStatus) {
	pHaduken = rand() % 25;
	pShoryuken = rand() % 40;
	do {
		cout << "Que ataque quieres hacer?\n[1] Haduken\n[2] Shoryuken\n[3] Ultimate\n";
		cin >> pSelectataque;
	} while (pSelectataque != 1 && pSelectataque != 2 && pSelectataque != 3);
	if (pSelectataque == 1) {
		pHPenemy2 -= pHaduken;
		statusEnemy2(HPenemy2, enemy2IsAlive);
		cout << "Le has hecho un Haduken a " << pEnemyName2 << " y le quedan " << pHPenemy2 << " puntos de vida.\n";
	}
	else if (pSelectataque == 2) {
		pHPenemy2 -= pShoryuken;
		statusEnemy2(HPenemy2, enemy2IsAlive);
		cout << "Le has hecho un Shoryuken a " << pEnemyName2 << " y le quedan " << pHPenemy2 << " puntos de vida.\n";
	}
	else if (pSelectataque == 3 && pUltimateStatus) {
		pHPenemy2 -= pUltimate;
		statusEnemy2(HPenemy2, enemy2IsAlive);
		cout << "Le has tirado la Ultimate a " << pEnemyName2 << " y le quedan " << pHPenemy2 << " puntos de vida\n Ya no puedes usar mas la Ultimate durante la partida";
		pUltimateStatus = false;
	}
	else if (pSelectataque == 3 && !pUltimateStatus) {
		cout << "Ya no te queda la Ultimate, has gastado un ataque.\n";
	}
}

void ataqueEnemigo1AHero(int& pHpPlayer, int pEnemy1Damage, string pEnemyName1) {
	pEnemy1Damage = rand() % 20 + 1;
	if (statusEnemy1(HPenemy1, enemy1IsAlive)) {
		pHpPlayer -= pEnemy1Damage;
		cout << pEnemyName1 << " te ha quitado " << pEnemy1Damage << ". Te quedan " << pHpPlayer << " puntos de vida\n";
	}
}

void ataqueEnemigo2AHero(int& pHPplayer, int pEnemy2Damage, string pEnemyName2) {
	pEnemy2Damage = rand() % 20 + 1;
	if (statusEnemy2(HPenemy2, enemy2IsAlive)) {
		pHPplayer -= pEnemy2Damage;
		cout << pEnemyName2 << " te ha quitado " << pEnemy2Damage << ". Te quedan " << pHPplayer << " puntos de vida\n";
	}
}
//Selecciona el enemigo y el ataque
void bucleJuego(bool& pPlayerIsAlive, bool& pEnemy1IsAlive, bool& pEnemy2IsAlive, int pSelectEnemigo ) {
	while (pPlayerIsAlive && (pEnemy1IsAlive || pEnemy2IsAlive)) {
		cout << "A que enemigo quieres atacar?\n[1] Ryu\n[2] Chun Ly\n";
		cin >> pSelectEnemigo;
		if (pSelectEnemigo == 1) {
			seleccionAtaqueEnemy1(Haduken, Shoryuken, Ultimate, selectAtaque, enemyName1, HPenemy1);
		}
		else if (pSelectEnemigo == 2) {
			seleccionAtaqueEnemy2(Haduken, Shoryuken, Ultimate, selectAtaque, enemyName2, HPenemy2, ultimateStatus);
		}
		ataqueEnemigo1AHero(HPplayer, enemy1damage, enemyName1);
		ataqueEnemigo2AHero(HPplayer, enemy2damage, enemyName2);
		statusHero(HPplayer, playerIsAlive);
		statusEnemy1(HPenemy1, enemy1IsAlive);
		statusEnemy2(HPenemy2, enemy2IsAlive);
	}
}


void finalJuego(bool& pPlayerIsAlive) {
	if (pPlayerIsAlive) {
		cout << "ENHORABUENA, HAS GANADO!";
	}
	else {
		cout << "Vaya... Has perdido";
	}
}



int main()
{
	srand(time(NULL));
	gamestart(playername);
	bucleJuego(playerIsAlive,enemy1IsAlive,enemy2IsAlive,selectEnemigo);
	finalJuego(playerIsAlive);
}


