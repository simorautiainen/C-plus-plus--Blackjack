#include <iostream>
#include <string>
#include <time.h>
#include "Header.h"
using namespace std;


//koska pakasta loppuu kortit ennen pitkää on pakko olla funktio joka laittaa pakan takaisin kuntoon
void arvojen_pisteleminen(string alkuperäisetnimet[],string uudetnimet[],int alkuperäisetarvot[],
	int uudetarvot[]) {
	
	for (int i = 0; i < 52; i++) {
		uudetnimet[i] = alkuperäisetnimet[i];
		uudetarvot[i] = alkuperäisetarvot[i];
	}
}
/* tämä funktio jakaa yhden kortin haluttuihin listoihin ja paikka on
sitä varten että pysytään mukana että monessako indexissä on kortteja*/
void pelikortinjako(string kortit[], int arvot[], string korttinimet[],
	int korttiarvot[], int& paikka) {
	//ei oikeasti sekoita mutta kuuluu peliin
	bool pitääkösekottaa = false;
	string kortti1nimi;
	int korttiarvo, arvo1;

	bool tren = true;
	//tekee rand komennosta sellaisen, että se ei katso kellosta aikaa.
	srand(time(0));
	//Katsotaan että kaikki kortti paikat eivät ole nollia koska silloin pitää lisätä uusi pakka
	for (int i = 0; i < 52; i++) {
		if (kortit[i] != "0") {
			pitääkösekottaa = false;
			break;
		}
		pitääkösekottaa = true;

	}

	if (pitääkösekottaa == true) {
		viivojenprinttaus();
		cout << "Cards ran out" << endl;
		cout << "Shuffling the deck ..." << endl;
		viivojenprinttaus();
		arvojen_pisteleminen(muokkaamattomat, kortit, muokkaamattomatarvot, arvot);

	}
	//valitsee kortit ja laittaa nimen kohdalle nollan kun kortti on arvottu jotta
	//sitä ei voisi tulla uudelleen
	while (tren) {

		arvo1 = rand() % 52;
		if (kortit[arvo1] == "0") {

			arvo1 = rand() % 52;
		}
		else {
			kortti1nimi = kortit[arvo1];
			kortit[arvo1] = "0";
			korttiarvo = arvot[arvo1];
			tren = false;

		}

	}
	//laittaa kortin kutsuttuun taulukkoon.
	korttinimet[paikka] = kortti1nimi;
	korttiarvot[paikka] = korttiarvo;
	paikka++;


}

//muuntaa syötteen jokaisen merkin pieneksi
void alasconvertteri(string& stringinnimi) {

	for (int i = 0; i < stringinnimi.length(); i++) {
		stringinnimi[i] = tolower(stringinnimi[i]);
	}
}
//printtaa viivoja
void viivojenprinttaus(int mode) {
	if (mode == 0) {
		for (int i = 0; i <= 30; i++) {
			cout << '-';
		}
		cout << '\n';
	}
	else {
		for (int i = 0; i <= mode; i++) {
			cout << '-';
		}
		cout << '\n';
	}
}

//itse peli
void peli(string kortit[], int arvot[], string korttinimetpelaaja[],
	int korttiarvotpelaaja[], int& paikkapelaaja, string korttinimetvihu[],
	int korttiarvotvihu[], int& paikkavihu) {

	//muuuttujat
	bool onoff = true,vihunoff = true;
	string morecards;
	int pelaajanyhteisarvo = 0,vihunyhteisarvo=0;

	//koska parametreissä ei ollut pelaajan korttien yhteisarvoa on se laskettava nyt
	for (int i = 0; i < paikkapelaaja; i++) {
		pelaajanyhteisarvo += korttiarvotpelaaja[i];
	}

	while (onoff) {
		cout << "Do want more cards?(yes or no): ";
		cin >> morecards;
		alasconvertteri(morecards);
		
		if (morecards == "yes") {
			
			//Jakaa pelikortin ja summaa sen yhteisarvoon
			pelikortinjako(kortit, arvot, korttinimetpelaaja, korttiarvotpelaaja,
				paikkapelaaja);
			pelaajanyhteisarvo += korttiarvotpelaaja[(paikkapelaaja - 1)];

			//Printtaa pelikortit ja summan
			viivojenprinttaus();
			cout << "You just got " << korttinimetpelaaja[(paikkapelaaja - 1)] << endl;
			//Niinkuin blackjackiin kuuluu ässä muuttuu ykköseksi jos korttien arvot ylittää 21
			for (int i = 0; i < paikkapelaaja; i++) {
				if (pelaajanyhteisarvo > 21 and korttiarvotpelaaja[i] == 11) {
					korttiarvotpelaaja[i] = 1;
					pelaajanyhteisarvo -= 10;
				}
			}
			cout << "Now your cards sum is: " << pelaajanyhteisarvo << endl;
			viivojenprinttaus();

			
			if (pelaajanyhteisarvo > 21) {
				cout << "You just lost since you went over 21!" << endl;				
				return;
			}
			else {
				continue;
			}
		}

		else if (morecards == "no") {
			//tästä alkaa aina vihun
			//korttienjako ellei sit onnistu jotenki saamaa tätä leipomaa
			cout << endl;
			//koska pöydän molempia kortteja ei ole vielä kerrottu
			for (int i = 0; i < paikkavihu; i++) {
				if (i == 0) {

					cout << "Table has a " << korttinimetvihu[i];

				}
				vihunyhteisarvo += korttiarvotvihu[i];
				i++;
				vihunyhteisarvo += korttiarvotvihu[i];
				cout << " and " << korttinimetvihu[i];
			
			}
			cout << "\nTables sum is: " << vihunyhteisarvo << endl << endl;

			while (vihunoff) {
				if (vihunyhteisarvo > 21) {

					viivojenprinttaus(60);
					cout << "Table went over 21 and therefore you WON !!!!" << endl;
					viivojenprinttaus(60);

					return;
				}
				else if (vihunyhteisarvo <= pelaajanyhteisarvo and vihunyhteisarvo < 17) {
					cout << "Giving table card!" << endl;
					pelikortinjako(kortit, arvot, korttinimetvihu, korttiarvotvihu,
						paikkavihu);
					vihunyhteisarvo += korttiarvotvihu[(paikkavihu - 1)];
					//Niinkuin blackjackiin kuuluu ässä muuttuu ykköseksi jos korttien arvot ylittää 21
					for (int i = 0; i < paikkavihu; i++) {
						if (vihunyhteisarvo > 21 and korttiarvotvihu[i] == 11) {
							korttiarvotvihu[i] = 1;
							vihunyhteisarvo -= 10;
						}
					}
					viivojenprinttaus();
					cout << "Table just got " << korttinimetvihu[(paikkavihu - 1)] << endl;
					cout << "Tables sum is: " << vihunyhteisarvo << endl;
					viivojenprinttaus();
				}
				else {
					//lopulta poistutaan.
					vihunoff = false;
					onoff = false;
				}
			}

		}
		else {
			continue;
		}

	}
	
	if (vihunyhteisarvo >= pelaajanyhteisarvo) {
		viivojenprinttaus(60);
		cout << "Table won because your cards value is: " << pelaajanyhteisarvo <<
			" and tables is: " << vihunyhteisarvo << endl;
		viivojenprinttaus(60);
		return;

	}
	else {
		viivojenprinttaus(60);
		cout << "You just won beacause your cards value is: " << pelaajanyhteisarvo <<
			" and tables is: " << vihunyhteisarvo << endl;
		viivojenprinttaus(60);
		return;
	}


}

