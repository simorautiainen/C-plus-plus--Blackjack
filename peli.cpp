#include <iostream>
using namespace std;

void pelikortinjako(string,int,string,int,int);

void peli(string kortit[],int arvot[], string korttinimetpelaaja[],
          int korttiarvotpelaaja[],int& paikkapelaaja,string korttinimetvihu[],
          int korttiarvotvihu[],int& paikkavihu){

            bool onoff = true;
            bool voittaja;
            string morecards;
            int pelaajanyhteisarvo = 0;

            while(onoff){
              cout << "Do want more cards?(yes or no): ";
              cin >> morecards;

              if (morecards == "yes"){
                pelikortinjako(kortit,arvot,korttinimetpelaaja,korttiarvotpelaaja,
                paikkapelaaja);
                cout << "You just got" << korttinimetpelaaja[(paikkapelaaja-1)]
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
          }
              else if(morecards == "no"){

                onoff = false;

          }
            else{
              continue;
            }

        }



}
