#include<iostream>
#include<cstdlib>
#include<cstring>

struct tosoba{
       int ai, bi, ci, di;
       char ime[30], prezime[30];
       int dan,mjesec,godina;
       long double stanje_tekuci, stanje_devizni;
       int br_godina;
};
tosoba *osoba;
#include "red_pokazivac.h"
//#include "red_polje.h"
using namespace std;



void cetvorke(int N, tosoba osoba[]){
     int a,b,c,d;
     int br_unosa=0;
     srand(time(0));
     for(int i=0;i<N;i++){
             
                          a=(rand()%400)+100;
                          c=(rand()%6)+1;
                          d=(rand()%4)+1;
                         
             if(br_unosa==0)
                            b=(rand()%400)+100;
             else{
                  do b=(rand()%400)+100;
                  while(osoba[i-1].bi>b);
                  }
             br_unosa++;
     osoba[i].ai=a;
     osoba[i].bi=b;
     osoba[i].ci=c;
     osoba[i].di=d;
     }                  
}

void unos(int N, tosoba osoba[]){
     for(int i=0;i<N;i++){
                          cout<<"Unesite ime "<<i+1<<". osobe: "; cin>>osoba[i].ime;
                          cout<<"Unesite prezime osobe: "; cin>>osoba[i].prezime;
                          int d,m,g;
                          do{
                              cout<<"\nDan 1-31; Mjesec 1-12; Godina 1900-2000\n";
                              cout<<"Unesite dan rodjenja: "; cin>>d;
                              cout<<"Unesite mjesec rodjenja: "; cin>>m;
                              cout<<"Unesite godinu rodjenja: "; cin>>g;
                              }while(d>31||m>12||g>2000||g<1900);
                          osoba[i].dan=d;
                          osoba[i].mjesec=m;
                          osoba[i].godina=g;
                          osoba[i].br_godina=(2012-osoba[i].godina);
                          cout<<"Unesite stanje na tekucem racunu (HRK): "; cin>>osoba[i].stanje_tekuci;
                          cout<<"Unesite stanje na deviznom racunu (USD): "; cin>>osoba[i].stanje_devizni;
                          cout<<endl<<endl;
                          }
}

void dodaj_klijenta(int N, queue* red, tosoba osoba[]){
      for (int i=0;i<N;i++)
               EnQueueQ(osoba[i],red);
}

void ispis(queue* red, tosoba osoba[],int i){ 
     cout <<"\n---------------\n";
     cout<< i+1 << ". u redu"<<endl<<"\nIme i prezime: "<<osoba[i].ime<<" "<<osoba[i].prezime<<endl;
     cout<<"Datum rodjenja: "<<osoba[i].dan<<"."<<osoba[i].mjesec<<"."<<osoba[i].godina<<endl;
     cout<<"Godina: "<<osoba[i].br_godina<<endl;
     cout<<"Stanje na tekucem racunu: "<<osoba[i].stanje_tekuci<<" HRK"<<endl;
     cout<<"Stanje na devitznom racunu: "<<osoba[i].stanje_devizni<<" USD"<<endl;
     cout<<"Vrijeme ulaza u red: "<<osoba[i].ai<<endl;
     cout<<"Vremensko trajanje transakcije: "<<osoba[i].bi<<endl;
     cout<<"Prioritet: "<<osoba[i].ci<<endl;
     cout<<"Vrsta transakcije: "<<osoba[i].di<<endl;
     cout<<"Vrijeme dolaska: "<<osoba[i].bi<<endl;
     cout<<"-------------\n";
     
 cout << endl; 
}

void prioriteti(queue* red, int N, tosoba osoba[]){
     for (int i = 1; i < N; i++) {
        int j = i-1;
        tosoba pom = osoba[i];
        while (j >= 0 && osoba[j].ci > pom.ci)
              osoba[j+1] = osoba[j--];
        osoba[j+1] = pom;
    }
    for (int i=0; i<N; i++)
        EnQueueQ(osoba[i],red);
}

void vise_od(queue* red, int N, tosoba osoba[]){
     tosoba *pomocni;
     pomocni=new tosoba[N];
     int br_osoba=0;
     for (int i=0; i<N; i++){
         if((osoba[i].stanje_devizni*5.4)>10000){
                                                 pomocni[br_osoba]=osoba[i];
                                                 br_osoba++;
                                                 }
                                                 }
     cout<<"\nKLIJENTI KOJI IMAJU VISE OD 10 000 HRK U STRANOJ VALUTI\n";
     for (int i=0; i<br_osoba; i++)
     ispis(red,pomocni,i);
                                                                
     
}

void brze_transakcije(queue*red, int N, tosoba osoba[]){
     int br_osoba=0, oduzmi=0;
     tosoba *pom;
     pom=new tosoba[N];
     for(int i=0;i<N; i++)
             if(osoba[i].di==3){
                                pom[br_osoba]=osoba[i];
                                DeQueueQ(red);
                                br_osoba++;
                                oduzmi++;
                                }
                                                  
     prioriteti(red,br_osoba,pom);
     cout<<"\n\nSTANJE BRZOG REDA\n-----------------\n";
     for(int i=0;i<br_osoba; i++)
             ispis(red,pom,i);
     N=N-oduzmi;
     prioriteti(red,N,osoba); 
     cout<<"\n\nSTANJE GLAVNOG REDA\n-------------------\n";
     for(int i=1;i<N+1;i++)
             ispis(red,osoba,i);   
}

void VIP(queue*red, int N, tosoba osoba[]){
     tosoba *pomocna;
     pomocna=new tosoba[N];
     int brojac=0;
     for(int i=0;i<N; i++)
             if(osoba[i].ci==4)
                               if(osoba[i].di==1)
                                                 if(osoba[i].br_godina<30)
                                                                          if(osoba[i].stanje_tekuci<100){
                                                                                                         osoba[i]=pomocna[brojac];
                                                                                                         brojac++;
                                                                                                         }
     for(int i=0;i<N; i++)
             if(osoba[i].ci==1)
                               if(osoba[i].di==2)
                                                 if(osoba[i].stanje_tekuci>5000){
                                                                                osoba[i]=pomocna[brojac];
                                                                                brojac++;
                                                                                }
     
    for(int i=0;i<N; i++)
            if(!(osoba[i].ci==4&&osoba[i].di==1&&osoba[i].stanje_tekuci<100||osoba[i].ci==1&&osoba[i].di==2&&osoba[i].stanje_tekuci>5000))
                    EnQueueQ(osoba[i],red);
    prioriteti(red,N,osoba);
    cout<<"\n--------------\nSTANJE NA REDU\n-------------";
    for(int i=0;i<N; i++)
    ispis(red,osoba,i);
     
}

int main(){
    int izbor, N=0;
    tosoba *osoba;
    queue* red = InitQ(red);
    cout<<"Generiranje niza od N cetvoriki\n";
    cout<<"Unesite koliko klijenata zelite unijeti: ";
    cin>>N;
    osoba=new tosoba[N];
    cetvorke(N, osoba);
   
    do{
           cout<<"\n-------------IZBORNIK-------------\n";
           cout<<"1) Dodavanje informacija o klijentu\n";
           cout<<"2) Ispis klijenata koji imaju preko 10 000 kn u stranoj valuti\n";
           cout<<"3) Red brzih transakcija\n";
           cout<<"4) Brisanje VIP klijenata\n";
           cout<<"9) Izlaz iz programa\n";
           cout<<"Vas izbor: ";
           cin>>izbor;
           switch(izbor){
                         case 1: 
                                 unos(N, osoba);
                                 dodaj_klijenta(N,red, osoba);
                                 break;
                         case 2: 
                                 cout<<"\nObrada transkacija u tijeku....\n";
                                 prioriteti(red,N,osoba);
                                 cout<<"\n-------------------------------------------------------\n";
                                 cout<<"Osobe sa iznosom na deviznom racunu vise od 10 000 HRK:\n";
                                 cout<<"---------------------------------------------------------\n";
                                 vise_od(red,N,osoba);
                                 break;
                         case 3: 
                                 cout<<"\nRed brzih transakcija je otvoren!\n";
                                 brze_transakcije(red,N,osoba);
                                 break;
                         case 4:
                                 VIP(red,N,osoba);
                                 break;
                         case 9: break;
                         default: cout<<"Pogresan unos!\n";
                                 
                         }
           
           }while(izbor!=9);

return 0;    
}
