// BlackJack_Alejandro.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//



#include <iostream>
#include <stdlib.h>
#include <random>



using namespace std;



void menu() {
	cout << "Bienvenidos a BlackJack \n";
	system("pause");
	system("cls");
}



int cartas[4][13] = { { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 },
					{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 },
					{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 },
					{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 } };



int repartir, palo, nuevaCarta;
int puntosCroupier = 0, puntosJugador = 0;
bool esJQKAS = true;
string mostrarJQKAS;



bool isAs() {
	if (nuevaCarta == 1) {
		return true;
	}
	else
		return false;
}
bool llegaA21() {
	if ((puntosJugador >= 21) || (puntosCroupier >= 21)) {
		return false;
	}
	else
		true;
}



void repartirCarta() {
	do {
		repartir = rand() % (13);
		palo = rand() % (4);
	} while (cartas[palo][repartir] == 0);

	nuevaCarta = cartas[palo][repartir];
	cartas[palo][repartir] = 0;
}

string mostrarTextoJQKAS() {
	return mostrarJQKAS;
}


void valorJQKAS() {
	
		if (nuevaCarta == 11) {
			nuevaCarta -= 1;
			mostrarJQKAS = "J";
		}
		else if (nuevaCarta == 12) {
			nuevaCarta -= 2;
			mostrarJQKAS = "Q";
		}
		else if (nuevaCarta == 13) {
			nuevaCarta -= 3;
			mostrarJQKAS = "K";
		}
		else if (nuevaCarta == 1) {
			mostrarJQKAS = "AS";
		}
		else {
			esJQKAS = false;
		}
}





string quePalo() {
	string palos[] = { "Corazones", "Picas", "Rombos", "Treboles" };
	string nombreDelPalo = palos[palo];
	return nombreDelPalo;
}


void decisionAs() {
	int opcion;
	if (nuevaCarta == 1) {
		cout << "Que valor quieres para tu AS? \n[1] 1\n[2] 11\n";
		do {
			cin >> opcion;
		} while ((opcion != 1) && (opcion != 2));

		switch (opcion) {
		case 1:
			nuevaCarta = 1;
			break;
		case 2:
			nuevaCarta = 11;
			break;
		}
	}
}


void decisionAsCroupier() {
	if(puntosCroupier >= 12){
		nuevaCarta = 1;
	}
	else {
		nuevaCarta = 11;
	}
}




void inicioJuego() {
	cout << "Empieza el juego...\n";
	cout << "El crupier te reparte 2 cartas...\n\n";
	//Reparticion de las 2 cartas al jugador
	for (int i = 0; i < 2; i++) {
		//turno jugador
		cout << "\n\033[34m" << "Turno player" << "\033[0m\n";
		repartirCarta();
		valorJQKAS();
		if (esJQKAS) {
			if (isAs()) {
				cout << "Te ha tocado un " << mostrarTextoJQKAS() << " de " << quePalo() << "\n";
				decisionAs();
				puntosJugador += nuevaCarta;
				cout << "Tienes un total de: " << puntosJugador << " puntos \n\n";
			}
			else {
				cout << "Te ha tocado una " << mostrarTextoJQKAS() << " de " << quePalo() << "\n";
				puntosJugador += nuevaCarta;
				cout << "Tienes un total de: " << puntosJugador << " puntos \n\n";
			}
		}
		else {
			cout << "Te ha tocado un " << nuevaCarta << " de " << quePalo() << "\n";
			puntosJugador += nuevaCarta;
			cout << "Tienes un total de: " << puntosJugador << " puntos \n\n";
		}
	}
	//turno croupier
	cout << "\n\033[31m" << "Turno Croupier" << "\033[0m\n";
	repartirCarta();
	valorJQKAS();
	if (esJQKAS) {
		if (isAs()) {
			cout << "Al Croupier le ha tocado un " << mostrarTextoJQKAS() << " de " << quePalo() << "\n";
			decisionAsCroupier();
			puntosCroupier += nuevaCarta;
			cout << "El Croupier tiene un total de " << puntosCroupier << " puntos \n\n";
		}
		else {
			cout << "Al Croupier le ha tocado una " << mostrarTextoJQKAS() << " de " << quePalo() << "\n";
			puntosCroupier += nuevaCarta;
			cout << "El Croupier tiene un total de " << puntosCroupier << " puntos \n\n";
		}
	}
	else {
		cout << "Al Croupier le ha tocado un " << nuevaCarta << " de " << quePalo() << "\n";
		puntosCroupier += nuevaCarta;
		cout << "El Croupier tiene un total de " << puntosCroupier << " puntos \n\n";
	}
}


void bucleJuego() {

	while (puntosJugador <= 21 && puntosCroupier <= 21) {
		//turno jugador
		cout << "\n\033[34m" << "Turno player" << "\033[0m\n";
		repartirCarta();
		valorJQKAS();
		if (esJQKAS) {
			if (isAs()) {
				cout << "Te ha tocado un " << mostrarTextoJQKAS() << " de " << quePalo() << "\n";
				decisionAs();
				puntosJugador += nuevaCarta;
				cout << "Tienes un total de: " << puntosJugador << " puntos \n\n";
			}
			else {
				cout << "Te ha tocado una " << mostrarTextoJQKAS() << " de " << quePalo() << "\n";
				puntosJugador += nuevaCarta;
				cout << "Tienes un total de: " << puntosJugador << " puntos \n\n";
			}
		}
		else {
			cout << "Te ha tocado una " << nuevaCarta << " de " << quePalo() << "\n";
			puntosJugador += nuevaCarta;
			cout << "Tienes un total de: " << puntosJugador << " puntos \n\n";
		}
		//turno croupier
		cout << "\n\033[31m" << "Turno Croupier" << "\033[0m\n";
		repartirCarta();
		valorJQKAS();
		if (esJQKAS) {
			if (isAs()) {
				cout << "Al Croupier le ha tocado un " << mostrarTextoJQKAS() << " de " << quePalo() << "\n";
				decisionAsCroupier();
				puntosCroupier += nuevaCarta;
				cout << "El Croupier tiene un total de " << puntosCroupier << " puntos \n\n";
			}
			else {
				cout << "Al Croupier le ha tocado una " << mostrarTextoJQKAS() << " de " << quePalo() << "\n";
				puntosCroupier += nuevaCarta;
				cout << "El Croupier tiene un total de " << puntosCroupier << " puntos \n\n";
			}
		}
		else {
			cout << "Al Croupier le ha tocado un " << nuevaCarta << " de " << quePalo() << "\n";
			puntosCroupier += nuevaCarta;
			cout << "El Croupier tiene un total de " << puntosCroupier << " puntos \n\n";
		}
	}
}


void finalJuego() {
	if (puntosJugador == 21 && (puntosCroupier < 21 || puntosCroupier > 21)) {
		cout << "Enhorabuena, has ganado la partida";
	}
	else if (puntosJugador == 21 && puntosCroupier == 21) {
		cout << "Has empatado con el Croupier";
	}
	else if (puntosCroupier == 21 && (puntosJugador < 21 || puntosJugador > 21)) {
		cout << "Vaya... El Croupier te ha ganado :(";
	}
	else if (puntosJugador > 21){
		cout << "Vaya... El Croupier te ha ganado :(";
	}
	else if (puntosCroupier > 21 && puntosJugador <= 21)
		cout << "Enhorabuena, has ganado la partida";
}








int main()
{
	srand(time(NULL));
	menu();
	inicioJuego();
	bucleJuego();
	finalJuego();
}