/*
*
*
* Author: Miguel S�nchez Palomino (https://github.com/MiguelSanchezP)
* Date: 11-05-2018
* Description:
*   This file generates random configurations for the enigma machine, taking into account the quantity of rotors,
* the quantity of reflectors and the quantity of wires used on the plugboard, we assume that the alphabet used
* on the machine is the latin one
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

int main () {
	srand(time(0));
	int quantityRotors;
	int quantityOperatingRotors;
	int quantityReflectors;
	int quantityPairs;
	const int quantityDays = 31;
	cout << "The configuration is going to be valid for a month (31 days)" << endl;
	cout << "Assuming the alphabet of the machine is the latin one (26 letters)" << endl;
	cout << "Quantity of rotors (total): ";
	cin >> quantityRotors;
	cout << "Quantity of rotors (operating): ";
	cin >> quantityOperatingRotors;
	cout << "Quantity of reflectors: ";
	cin >> quantityReflectors;
	cout << "Pairs formed on the plugBoard: ";
	cin >> quantityPairs;
	while (quantityPairs > 13) {
		cout << "Impossible configuration, must be 13 pairs or less" << endl;
		cout << "Pairs formed on the plugBoard: ";
		cin >> quantityPairs;
	}
	cout <<"------------------------------------" << endl;
  alphabet [] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'Y', 'Z'};
	ofstream write;
	write.open("Configuration.txt");
	for (int d = 0; d <quantityDays; d++) {
		write << endl;
		for (int i = 0; i<quantityOperatingRotors; i++) {
			int v1 = rand() % quantityRotors + 1;
			write << v1 << "-";
		}
		write << "|||\t";
		int v2 = rand() % quantityReflectors + 1;
		write << v2 << "\t|||\t";
		bool firstLetter = true;
		for (int i = 0; i<(2*quantityPairs); i++) {
			int v3 = rand() % 25;
			if (firstLetter) {
				write << alphabet[v3];
				firstLetter = false;
			}else{
				write << alphabet[v3] << "-";
				firstLetter = true;
			}
		}
	}
	write.close();
	cout << "Configuration successfully exported" << endl;
	return 0;
}
