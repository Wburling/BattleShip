#include "Ship.h"
using namespace std;

void Ship::welcome() {
	cout << "    * * * * *    " << endl;
	cout << "  * * * * * * *  " << endl;
	cout << "-----------------" << endl;
	cout << endl;
}
void Ship::inti() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLLUMS; j++) {
			gameboard[i][j] = "# ";
		}
	}
}
void Ship::shipPlacement(int rows, int collums, string shipName) {
	system("cls"); 
	int ship = 0;
	int x, y;
	bool test = false;
	int ran = rand() % 2 + 1;
	switch (conversion(shipName))
	{
	case 'c':
		ship = 5;
		break;
	case 'b':
		ship = 4;
		break;
	case 'r':
		ship = 3;
		break;
	case 's':
		ship = 3;
		break;
	case 'd':
		ship = 2;
		break;
	default:
		throw std::exception("What?");
		break;
	}
	while (true) {
		bool breaks = false;
		y = rand() % rows;
		x = rand() % collums;
		ran = rand() % 2 + 1;
		verifyRotationLegal(ran, x, y, ship);
		switch (ran) {
		case 1:
			if (verifyRotationLegal(ran, x, y, ship) == false)
				break;
			for (int i = 0; i < ship; i++) {
				gameboard[x][i] = shipName + " ";
			}
			test = true;
			ran = rand() % 2 + 1;
			break;
		case 2:
			if (verifyRotationLegal(ran, x, y, ship) == false)
				break;
			for (int i = 0; i < ship; i++) {
				gameboard[i][y] = shipName + " ";
			}
			test = true;
			ran = rand() % 2 + 1;
			break;
		}
		if (test)
			break;
	}

}

char Ship::conversion(string ship) {
	return ship[0];
}

bool Ship::verifyRotationLegal(int cases, int x, int y, int ship) {
	if (cases == 1) {
		for (int i = 0; i < ship; i++) {
			if (gameboard[x][i] != "# ") {
				return false;
			}

		}
	}
	if (cases == 2) {
		for (int i = 0; i < ship; i++) {
			if (gameboard[i][y] != "# ") {
				return false;
			}
		}
	}
}
/// <summary>
/// Manually place a ship
/// </summary>
/// <param name="shipName"></param>
void Ship::manPlacement(string shipName) {
	char h; 
	int t; 
	bool procede = false; 
		int coord[2];
		auto shipLen = numberConversion(conversion(shipName));
		system("cls");
		cout << endl; 
		cout << "Place the " << shipName << "ship. it is " << numberConversion(conversion(shipName)) << " places" << endl;
		update();
		cout << "Pick your first place (Letter first, then Number)" << endl;
		cin >> h >> t; 
		coord[0] = t - 1; 
		coord[1] = tolower(h) - 'a';
		if (gameboard[coord[0]][coord[1]] != "# ") {
			out(coord, 0, shipName); 
			manPlacement(shipName); 
		}
		else {
			gameboard[coord[0]][coord[1]] = shipName;
			procede = true; 
		}
		if (procede) {
			system("cls");
			update();
			char answer;
			cout << "Is your ship going to be horizontal or vertical? (h/v)" << endl;
			cin >> answer;
			system("cls");

			if (answer == 'h' || answer == 'H') {
				if (outOfBounds(shipLen, coord, shipName, 1)) {
					for (int i = 1; i < shipLen; i++) {
						gameboard[coord[0]][coord[1] + i] = shipName;
					}
					update();
				}
				else {
					manPlacement(shipName);
				}
			}
			if (answer == 'v' || answer == 'V') {
				if (outOfBounds(shipLen, coord, shipName, 2)) {
					for (int i = 0; i < shipLen - 1; i++) {
						gameboard[coord[0] + i + 1][coord[1]] = shipName;
					}
					update();
				}
				else {
					manPlacement(shipName);
				}
			}
		}
	}


int Ship::numberConversion(char c) {
	if (c == 'c')
		return 5;
	if (c == 'b')
		return 4;
	if (c == 'r')
		return 3;
	if (c == 's') {
		return 3;
	}
	if (c == 'd') {
		return 2;
	}
	throw std::exception("Invalid character");
}
void Ship::update() {
	cout << "  A B C D E F G H I J" << endl;
	for (int i = 0; i < ROWS; i++) {
		if (i >= 9)
			cout << i + 1;
		else {
			cout << i + 1 << " ";
		}
		for (int j = 0; j < COLLUMS; j++) {
			if (gameboard[i][j] != "# ")
				cout << "\033[1;31m" << gameboard[i][j] << "\033[0m";
			else
				cout << gameboard[i][j];
			//cout << gameboard[i][j];
		}
		cout << endl;
	}
}

bool Ship::outOfBounds(int shipLen, int coord[], string shipName, int cases) {
	string k; 
	for (int i = 1; i < shipLen; i++) {
		
		if (cases == 1) {
			if (gameboard[coord[0]][coord[1] + i] != "# ") {
				out(coord, 1, shipName);
				return false;
			}
			if (coord[1] + i >= ROWS) {
				
				cout << "Collision Detected, either out of bounds or collided with another ship... Try again." << endl;
				gameboard[coord[0]][coord[1]] = "# ";
				getline(cin, k);
				cin.ignore();
				return false; 
			}
		}
		if (cases == 2) {
			if (gameboard[coord[0] + i][coord[1]] != "# ") {
				out(coord, 1, shipName);
				return false;
			}
			if (coord[0] + i >= COLLUMS) {
				cout << "Collision Detected, either out of bounds or collided with another ship... Try again." << endl;
				gameboard[coord[0]][coord[1]] = "# ";
				getline(cin, k);
				cin.ignore();
				return false; 
			}
		}

	}
	return true;
}

void Ship::out(int coord[], int cases, string shipName) {
	if (cases == 1) {
		system("cls");
		string k;
		cout << "Collision Detected, either out of bounds or collided with another ship... Try again." << endl;
		gameboard[coord[0]][coord[1]] = "# ";
		getline(cin, k);
		cin.ignore();
	}
	if (cases == 0) {
		system("cls");
		string k;
		cout << "Collision Detected, either out of bounds or collided with another ship... Try again." << endl;
		getline(cin, k);
		cin.ignore();
	}
}
