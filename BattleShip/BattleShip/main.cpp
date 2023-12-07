#include <iostream> 
#include "Ship.h"
using namespace std;
int main() {
	srand(time(NULL));
	const int ROWSS = 10;
	const int COLLUMSS = 10;
	char ships = ' ';
	Ship myShip;
	Ship myComputer;
	myShip.welcome();
	cout << "Welcome to Battle ship:" << endl;
	cout << "Would you like your ships placed randomly? (y/n)\n";
	cin >> ships;
	myComputer.inti();
	myComputer.shipPlacement(ROWSS, COLLUMSS, "c");
	myComputer.shipPlacement(ROWSS, COLLUMSS, "b");
	myComputer.shipPlacement(ROWSS, COLLUMSS, "r");
	myComputer.shipPlacement(ROWSS, COLLUMSS, "s");
	myComputer.shipPlacement(ROWSS, COLLUMSS, "d");
	myShip.inti();
	if (ships == 'y' || ships == 'Y') {
		myShip.shipPlacement(ROWSS, COLLUMSS, "c");
		myShip.shipPlacement(ROWSS, COLLUMSS, "b");
		myShip.shipPlacement(ROWSS, COLLUMSS, "r");
		myShip.shipPlacement(ROWSS, COLLUMSS, "s");
		myShip.shipPlacement(ROWSS, COLLUMSS, "d");
		while (true) {
			cout << "  A B C D E F G H I J       A B C D E F G H I J" << endl;
			cout << "  -------------------       -------------------" << endl; 
			for (int i = 0; i < ROWS; i++) {
				if (i >= 9)
					cout << i + 1;
				else {
					cout << i + 1 << " ";
				}
				for (int j = 0; j < COLLUMS; j++) {
					if (myShip.gameboard[i][j] != "# ")
						cout << "\033[1;31m" << myShip.gameboard[i][j] << "\033[0m";
					else
						cout << myShip.gameboard[i][j];
					
				}
				cout << "      ";
				for (int j = 0; j < COLLUMS; j++) {
					if (myComputer.gameboard[i][j] != "# ")
						cout << "\033[1;31m" << myComputer.gameboard[i][j] << "\033[0m";
					else
						cout << myComputer.gameboard[i][j];
				}
				cout << endl;
			}
			break;
		}
	}
	if (ships == 'n' || ships == 'N') {
		myShip.manPlacement("c ");
		myShip.manPlacement("b ");
		myShip.manPlacement("r ");
		myShip.manPlacement("s ");
		myShip.manPlacement("d ");

		system("cls");
		cout << "  A B C D E F G H I J       A B C D E F G H I J" << endl;
		cout << "  -------------------       -------------------" << endl;
		for (int i = 0; i < ROWS; i++) {
			if (i >= 9)
				cout << i + 1;
			else {
				cout << i + 1 << " ";
			}
			for (int j = 0; j < COLLUMS; j++) {
				if (myShip.gameboard[i][j] != "# ")
					cout << "\033[1;31m" << myShip.gameboard[i][j] << "\033[0m";
				else
					cout << myShip.gameboard[i][j];

			}
			cout << "      ";
			for (int j = 0; j < COLLUMS; j++) {
				if (myComputer.gameboard[i][j] != "# ")
					cout << "\033[1;31m" << myComputer.gameboard[i][j] << "\033[0m";
				else
					cout << myComputer.gameboard[i][j];
			}
			cout << endl;
		}
		
	}

}