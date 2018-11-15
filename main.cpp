#include <iostream>
#include <string>
using namespace std;


void pelikorttienjako(string kortit[],int arvot[], string pelaaja[],
                      int pelaajarvot[]){

                      string kortti1nimi,kortti1nimi2;
                      int korttiarvo,korttiarvo2,arvo1,arvo2;

                      bool tren = true;

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
                      while(tren){

                        arvo2 = rand() % 52;
                        if(kortit[arvo2]=="0"){

                          arvo2 = rand() % 52;
                        }
                        else{
                          kortti1nimi2 = kortit[arvo2];
                          kortit[arvo2] = "0";
                          korttiarvo2 = arvot[arvo2];
                          tren = false;

                    }
                      pelaaja[0] = kortti1nimi;
                      pelaajarvot[0] = korttiarvo;
                      pelaaja[1] = kortti1nimi2;
                      pelaajarvot[1] = korttiarvo2;

}
}

int main(){


  string pelikortit[] = {
    "hertta ässä", "hertta kaksi", "hertta kolme", "hertta neljä",
    "hertta viisi", "hertta kuusi", "hertta seitsemän",
    "hertta kahdeksan", "hertta yhdeksän", "hertta kymppi",
    "hertta jätkä", "hertta akka", "hertta kunkku",
    "pata ässä", "pata kaksi", "pata kolme", "pata neljä",
    "pata viisi", "pata kuusi", "pata seitsemän",
    "pata kahdeksan", "pata yhdeksän", "pata kymppi",
    "pata jätkä", "pata akka", "pata kunkku",
    "ruutu ässä", "ruutu kaksi", "ruutu kolme", "ruutu neljä",
    "ruutu viisi", "ruutu kuusi", "ruutu seitsemän",
    "ruutu kahdeksan", "ruutu yhdeksän", "ruutu kymppi",
    "ruutu jätkä", "ruutu akka", "ruutu kunkku",
    "risti ässä", "risti kaksi", "risti kolme", "risti neljä",
    "risti viisi", "risti kuusi", "risti seitsemän",
    "risti kahdeksan", "risti yhdeksän", "risti kymppi",
    "risti jätkä", "risti akka", "risti kunkku"};


  int arvot[] =
    {11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,
    10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,
    8,9,10,10,10,10};

  string pelaajankortit[2];
  int pelaajanarvot[2];

  string vihunkortit[2];
  int vihunarvot[2];




  return 0;
}
