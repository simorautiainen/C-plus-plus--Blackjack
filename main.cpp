#include <iostream>
#include <string>
#include <time.h>
#include<algorithm>
#include"peli.cpp"
using namespace std;

/* tämä funktio jakaa yhden kortin haluttuihin listoihin ja paikka on
sitä varten että pysytään mukana että monessako indexissä on kortteja*/
void pelikortinjako(string kortit[],int arvot[], string korttinimet[],
                      int korttiarvot[],int& paikka){

                      string kortti1nimi;
                      int korttiarvo,arvo1;

                      bool tren = true;
                      srand(time(0));
                      while(tren){

                        arvo1 = rand() % 52;
                        if(kortit[arvo1]=="0"){

                          arvo1 = rand() % 52;
                        }
                        else{
                          kortti1nimi = kortit[arvo1];
                          kortit[arvo1] = "0";
                          korttiarvo = arvot[arvo1];
                          tren = false;

                      }

                      }

                      korttinimet[paikka] = kortti1nimi;
                      korttiarvot[paikka] = korttiarvo;
                      paikka++;


}

void alasconvertteri(string& stringinnimi){

  for(int i = 0;i<stringinnimi.length();i++){
    stringinnimi[i] = tolower(stringinnimi[i]);
  }
}



int main(){

  //Hain korttien nimet pythonilla wikipedian artikkelista "standard 52-card deck"

  string pelikortit[] = {
    "Ace of clubs", "2 of clubs", "3 of clubs", "4 of clubs",
    "5 of clubs", "6 of clubs", "7 of clubs", "8 of clubs",
    "9 of clubs", "10 of clubs", "Jack of clubs",
    "Queen of clubs", "King of clubs", "Ace of diamonds",
    "2 of diamonds", "3 of diamonds", "4 of diamonds", "5 of diamonds",
    "6 of diamonds", "7 of diamonds", "8 of diamonds", "9 of diamonds",
    "10 of diamonds", "Jack of diamonds", "Queen of diamonds",
    "King of diamonds", "Ace of hearts", "2 of hearts", "3 of hearts",
    "4 of hearts", "5 of hearts", "6 of hearts", "7 of hearts", "8 of hearts",
    "9 of hearts", "10 of hearts", "Jack of hearts", "Queen of hearts",
    "King of hearts", "Ace of spades", "2 of spades", "3 of spades",
    "8 of spades", "9 of spades", "10 of spades", "Jack of spades",
    "Queen of spades", "King of spades",
};


  int vihunpaikka = 0, pelaajanpaikka = 0,arvot[] =
    {11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,
    10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,
    8,9,10,10,10,10};
  const unsigned int tittels = 20;
  string pelaajankortit[tittels];
  int pelaajanarvot[tittels];

  string vihunkortit[tittels];
  int vihunarvot[tittels];

  bool onoff = true;
  int pelaajanyhteisarvo = 0;

  string yesno;
  cout << "Would you like to play some blackjack,(Yes or No)";

  while(onoff){

    cin >> yesno;
    alasconvertteri(yesno);
    if(yesno=="yes"){
      cout << "Lets deal the cards: " << endl;
      pelikortinjako(pelikortit,arvot,pelaajankortit,pelaajanarvot,pelaajanpaikka);
      pelikortinjako(pelikortit,arvot,pelaajankortit,pelaajanarvot,pelaajanpaikka);
      pelikortinjako(pelikortit,arvot,vihunkortit,vihunarvot,vihunpaikka);
      pelikortinjako(pelikortit,arvot,vihunkortit,vihunarvot,vihunpaikka);

      cout << "\nAnd your enemy has a folded card and " << vihunkortit[0]
      << endl << endl;

      for(int i = 0;i<pelaajanpaikka;i++){
        if(i==0){
          cout << "You have: " << pelaajankortit[i];
          pelaajanyhteisarvo += pelaajanarvot[i];
        }
        else{
        cout << " and " << pelaajankortit[i] << endl;
        pelaajanyhteisarvo += pelaajanarvot[i];
      }
    }

      cout << "And their sum is: " << pelaajanyhteisarvo << endl;
      if(pelaajanyhteisarvo == 21){
        cout << "You WON since you got 21!!!" << endl;
      }
      else{
        peli(pelikortit,arvot,pelaajankortit,pelaajanarvot,pelaajanpaikka,
        vihun)
      }
    //TÄSTÄ ALKAA ITSE PELI!

      cout << "Would you like to play again (yes or no): ";
    }
    else if(yesno=="no"){
      onoff = false;
    }

    else{
      cout << "Erh, thats not valid input, lets try again!" << endl;
      cout << "Would you like to play some blackjack,(Yes or No): ";
      continue;
    }

}


  // pelikortinjakoa ajetaan niin, että annetaan sille 5 parametriä
  // kaikki kortit, kaikki arvot, se mihin listaan halutaan kortin nimi,
  //sitten se mihin halutaan kortin arvo ja se että mihin kohtaan
  //halutaan ne listassa


  return 0;
}
