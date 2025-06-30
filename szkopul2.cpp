#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Data
{
public:
	string slowkoPoPl;
	string slowkoPoAng;
	string znak;

	int odczytaj_plik(string plik);
};

int Data::odczytaj_plik(string plik) {
	string linia;
	vector <Data> dane;

	ifstream plik_odczyt(plik);
	if (!plik_odczyt.is_open()) {
		cout << "Nie mo�na otworzy� pliku" << endl;
		return 1;
	}

	while (getline(plik_odczyt, linia))
	{
		stringstream ss(linia);
		
		if (ss >> slowkoPoAng >> znak >> slowkoPoPl) {
			if (znak != "-") {
				cerr << "B��d: oczekiwano znaku '-'. " << endl;
				return 1;
			}
			//temp
			cout << "Po ang: " << slowkoPoAng << ", Znak: " << znak << ", S�owko po Polsku: " << slowkoPoPl << endl;
		}
		else {
			cerr << "B��d: Nie prawid�owy format w linii: " << linia << endl;
		}
	}
	plik_odczyt.close();

	return 0;
}

int main()
{



	return 0;
}
