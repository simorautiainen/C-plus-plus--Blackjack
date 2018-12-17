#include <iostream>
#include <string>
#include <time.h>
#include "Header.h"

using namespace std;


int main() {
	
	
	//********************KAIKKI MUUTTUJAT*******************

	//nämä ovat erillisessä filussa nimeltään pelikortit.cpp

	string pelikortit[52];
	int arvot[52];
	
	//koska käytän paikka muuttujia, minun ei ole pakko nollata pelaajien taulukoita
	//koska pysyn aina mukana, että kuinka monta korttia on kunkin taulukossa ja
	//missäkin kohdalla
	int vihunpaikka = 0, pelaajanpaikka = 0;

	const int tittels = 20;
	string pelaajankortit[tittels];
	int pelaajanarvot[tittels];

	string vihunkortit[tittels];
	int vihunarvot[tittels];


	bool onoff = true;
	int pelaajanyhteisarvo = 0;

	string yesno;
	//*******************************************************
	//Aloitetaan sillä että laitetaan taulukot kuntoon

	arvojen_pisteleminen(muokkaamattomat,pelikortit,muokkaamattomatarvot,arvot);

	viivojenprinttaus(80);
	
	cout << "Would you like to play some blackjack(Yes or No) or read the rules(rules): ";
	
	while (onoff) {
		
		cin >> yesno;
		viivojenprinttaus(80);
		alasconvertteri(yesno);
		if (yesno == "yes") {
			cout << "Lets deal the cards: " << endl;
			//jaetaan molemmille 2 korttia
			pelikortinjako(pelikortit, arvot, pelaajankortit, pelaajanarvot, pelaajanpaikka);
			pelikortinjako(pelikortit, arvot, pelaajankortit, pelaajanarvot, pelaajanpaikka);
			pelikortinjako(pelikortit, arvot, vihunkortit, vihunarvot, vihunpaikka);
			pelikortinjako(pelikortit, arvot, vihunkortit, vihunarvot, vihunpaikka);

			cout << "\nTable has a folded card and " << vihunkortit[0]
				<< endl << endl;
			//printataan kortit ja katsotaan että onko pelaajalla suoraan 21
			for (int i = 0; i < pelaajanpaikka; i++) {
				if (i == 0) {
					cout << "You have: " << pelaajankortit[i];
					pelaajanyhteisarvo += pelaajanarvot[i];
				}
				else {
					cout << " and " << pelaajankortit[i] << endl;
					pelaajanyhteisarvo += pelaajanarvot[i];
				}
			}

			cout << "And their sum is: " << pelaajanyhteisarvo << endl;

			if (pelaajanyhteisarvo == 21) {
				cout << "You WON since you got 21!!!" << endl;
			}
			else {
				peli(pelikortit, arvot, pelaajankortit, pelaajanarvot, pelaajanpaikka,
					vihunkortit,vihunarvot,vihunpaikka);
			}
			
			//tähän päättyy aina peli joten on nollattava paikat joidenka kortit otetaan mukaan
			pelaajanyhteisarvo = 0;
			pelaajanpaikka = 0;
			vihunpaikka = 0;
			viivojenprinttaus(80);
			cout << "Would you like to play some blackjack(Yes or No) or read the rules(rules): ";
		}

		else if (yesno == "no") {

			onoff = false;
		}

		else if (yesno == "rules") {
			viivojenprinttaus(80);
			cout << "Main point of blackjack is to get as close to 21 as you can.\n" <<
				"But if you get over 21 you lose instantly, and you battle against table\n" <<
				"You get to see table's one card at the start of the round.\n" <<
				"Table must stay at 17 or over it and if you get tie table always wins.\n" <<
				"Every card is valued as they should like 2 of clubs is valued as 2\n" <<
				",but all the face cards are valued as 10 and aces are valued as 11,\n" <<
				"unless overall value of the cards get over 21, your ace's value become 1.\n";
			viivojenprinttaus(80);
			cout << "Would you like to play some blackjack(Yes or No) or read the rules(rules): ";
				
		}
		else {
			cout << "Erh, thats not valid input, lets try again!" << endl;
			cout << "Would you like to play some blackjack(Yes or No) or read the rules(rules): ";
			continue;
		}

	}


	return 0;
}
