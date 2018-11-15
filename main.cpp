#include <iostream>
#include <string>
#include <time.h>
#include<algorithm>
using namespace std;


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
      "4 of hearts", "5 of hearts", "6 of hearts", "7 of hearts", "8 of hearts", "9 of hearts", "10 of hearts", "Jack of hearts", "Queen of hearts", "King of hearts", "Ace of spades", "2 of spades", "3 of spades", "4 of spades", "5 of spades", "6 of spades", "7 of spades", "8 of spades", "9 of spades", "10 of spades", "Jack of spades", "Queen of spades", "King of spades",
  };


  int vihunpaikka = 0, pelaajanpaikka = 0,arvot[] =
    {11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,
    10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,
    8,9,10,10,10,10};

  string pelaajankortit[20];
  int pelaajanarvot[20];

  string vihunkortit[20];
  int vihunarvot[20];

  bool onoff = true;

  string yesno;

  while(onoff){
    cout << "Would you like to play some blackjack,(Yes or No)";
    cin >> yesno;
    alasconvertteri(yesno);
    if(yesno=="yes"){
      cout << "Jaetaan kortit: " << endl;
      pelikortinjako(pelikortit,arvot,pelaajankortit,pelaajanarvot,pelaajanpaikka);
      pelaajanpaikka++;
      pelikortinjako(pelikortit,arvot,pelaajankortit,pelaajanarvot,pelaajanpaikka);
      pelaajanpaikka++;
      pelikortinjako(pelikortit,arvot,vihunkortit,vihunarvot,vihunpaikka);
      vihunpaikka++;
      pelikortinjako(pelikortit,arvot,vihunkortit,vihunarvot,vihunpaikka);
      vihunpaikka++;
      for(int i= 0;i<pelaajanpaikka;i++){
        cout << pelaajankortit[i];
        cout << pelaajanarvot[i];

      }

    }
    else if(yesno=="no"){
      onoff = false;
    }

    else{
      continue;
    }

}


  // pelikortinjakoa ajetaan niin, että annetaan sille 5 parametriä
  // kaikki kortit, kaikki arvot, se mihin listaan halutaan kortin nimi,
  //sitten se mihin halutaan kortin arvo ja se että mihin kohtaan
  //halutaan ne listassa

  
  return 0;
}
