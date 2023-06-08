#include <iostream>
#include <string.h>
#include "UI.h"
#include "RepoATM.h"
#include "Tranzactie.h"
using namespace std;

///---------------------------------------------------------------------------------------------
///Validari optiuni
///---------------------------------------------------------------------------------------------
void UI::Optiune(char*& opt){
  cout<<"\nDati optiunea:";
  cin.getline(opt,29);
}

void UI::LitereMici(char*& opt){
  for(int i=0;i<strlen(opt);i++){
    if(opt[i]>='A' && opt[i]<='Z') opt[i]=opt[i]+32;
  }
}
bool UI::NumaiCifre(char* n){
  for(int i=0;i<strlen(n);i++){
    if(n[i]<'0' || n[i]>'9') return 0;
  }
  return 1;
}

///---------------------------------------------------------------------------------------------
///Operatii diverse
///---------------------------------------------------------------------------------------------
//Adaugare o bacnota
void UI::AdaugareUI(){
  try{
  char val[10];
  char frv[10];
  cout<<"Dati valoare bacnotei si numarul de exemplare:";
  cin>>val;
  cin>>frv;
  if(NumaiCifre(val)==0 || NumaiCifre(frv)==0) throw invalid_argument("Datele introduse trebuie sa fie numere!");
  this->Repository.Adaugare(atoi(val),atoi(frv));
  }
  catch (invalid_argument ex) {cout<<ex.what();}
  char d[1];
  cin.getline(d,NULL);
}

//Modificare o bancnota
void UI::ModificareUI(){
  try{
  char poz[10];
  char val[10];
  char frv[10];
  cout<<"Dati pozitia care sa se modifice:";
  cin>>poz;
  cout<<"Dati valoare bacnotei noi si numarul de exemplare:";
  cin>>val;
  cin>>frv;
  if(NumaiCifre(val)==0 || NumaiCifre(frv)==0 ||NumaiCifre(poz)==0) throw invalid_argument("Datele introduse trebuie sa fie numere!");
  this->Repository.Modificare(atoi(poz),atoi(val),atoi(frv));
  }
  catch (invalid_argument ex) {cout<<ex.what();}
  char d[1];
  cin.getline(d,NULL);
}

//Stergere o pozitie
void UI::StergereUI(){
try{
  char poz[10];
  cout<<"Dati pozitia care sa se stearga:";
  cin>>poz;
  if(NumaiCifre(poz)==0) throw invalid_argument("Datele introduse trebuie sa fie numere!");
  this->Repository.Stergere(atoi(poz));
  }
  catch (invalid_argument ex) {cout<<ex.what();}
  char d[1];
  cin.getline(d,NULL);
}

void UI::AdaugareTranzactieUI(){
  try{
  char suma[10];
  char* rasp=new char[30];
  int ok=1;
  cout<<"Dati suma tranzactiei:";
  cin>>suma;
  if(NumaiCifre(suma)==0) throw invalid_argument("Datele introduse trebuie sa fie numere!");
  if(atoi(suma)>5000) throw invalid_argument("Suma trebuie sa fie pana in 5000 RON!");
  Colectie lista=this->Repository.RealizareTranzactie(atoi(suma));
  if(lista.GetSize()==0) cout<<"Nu se poate realiza tranzactia!";
  else {
      Tranzactie t(atoi(suma),lista);
      cout<<"\nTranzactia se poate realiza astfel:";
      for(int i=0;i<lista.GetSize();i++){
        auto[a,b]=lista.GetAt(i);
        cout<<a<<" RON de "<<b<<" ori ";
        if(i!=lista.GetSize()-1) cout<<",";
      }
      cout<<"\nPentru a se realiza tranzactia apasati \"Y\" sau \"N\" pentru a o anula.\n";
      while(ok==1){
      cout<<"Dati optiunea:";
      cin>>rasp;
      LitereMici(rasp);
      if(strcmp(rasp,"y")==0) {
           this->Repository.FinalizareTranzactie(lista);
            this->Repository.AdaugareTranzactie(t);
            this->Repository.StergereNULL();
          cout<<"Tranzactie realizata cu succes!";
          ok=0;}
      else if(strcmp(rasp,"n")==0) {cout<<"Tranzactie a fost anulata!"; ok=0;}
                else cout<<"Optiune invalida!\n\n";
      }

  }
  }
  catch (invalid_argument ex) {cout<<ex.what();}
  char d[1];
  cin.getline(d,NULL);
}

///---------------------------------------------------------------------------------------------
///Afisare bancnote/tranzactii
///---------------------------------------------------------------------------------------------
//Afisare tranzactii
void UI::AfisareT(vector<Tranzactie>t){
  cout<<endl;
  if(t.size()==0) cout<<"Nu s-a realizat nicio tranzactie!";
  else{
    for(int i=0;i<t.size();i++) cout<<t[i]<<endl;
  }
}


//Afisare bancnote
void UI::AfisareUI(vector<int> l1,vector<int> l2){
  if(l1.size()==0) cout<<"Nu s-a introdus nicio bancnota!\n";
  else{
    for(int i=0;i<l1.size();i++) cout<<"Bancnota de "<<l1[i]<<" RON in "<<l2[i]<<" exemplare.\n";
  }
}
///---------------------------------------------------------------------------------------------
///Print Meniu Principal
///---------------------------------------------------------------------------------------------
void UI::printMeniu(){
  cout<<"\n_________________________\n";
  cout<<"1.Adaugare bancnota      |\n";
  cout<<"2.Modificare bancnota    |\n";
  cout<<"3.Stergere bancnota      |\n";
  cout<<"4.Afisare bancnote       |\n";
  cout<<"-------------------------|\n";
  cout<<"5.Adaugare tranzactie    |\n";
  cout<<"6.Afisare tranzactii     |\n";
  cout<<"-------------------------|\n";
  cout<<"x.Iesire                 |\n";
  cout<<"_________________________|\n";
}
void UI::meniu(){
  this->Repository.SetUPB();
  this->Repository.SetUPT();
  char* opt=new char[30];
  int ok=1;
  while(ok==1){
    int op=0; //conditie daca se face o operatie
    printMeniu();
    Optiune(opt);
    LitereMici(opt);
    char* p;
    p=strtok(opt," ");
    if(strcmp(p,"adaugare")==0){
      p=strtok(NULL," ");
      if (p!=NULL){
        if(strcmp(p,"bancnota")==0) AdaugareUI();
        else if(strcmp(p,"tranzactie")==0) AdaugareTranzactieUI();
                  else op=1;
      }
      else op=1;
    }
    else if(strcmp(p,"iesire")==0) ok=0;
              else if(strcmp(p,"afisare")==0){
                                  p=strtok(NULL," ");
                                  if (p!=NULL){
                                    if(strcmp(p,"bancnote")==0)AfisareUI(this->Repository.GetAllValori(),this->Repository.GetAllFrecvente());
                                    else if(strcmp(p,"tranzactii")==0)AfisareT(this->Repository.GetAllTranzactii());
                                              else op=1;
                                  }
                                  else op=1;
                        }
                        else if(strcmp(p,"modificare")==0){
                                      p=strtok(NULL," ");
                                          if (p!=NULL){
                                              if(strcmp(p,"bancnote")==0) ModificareUI();
                                              else op=1;
                                          }
                                          else op=1;
                                  }
                                  else if(strcmp(p,"stergere")==0){
                                              p=strtok(NULL," ");
                                                  if (p!=NULL){
                                                      if(strcmp(p,"bancnote")==0) StergereUI();
                                                      else op=1;
                                                  }
                                                  else op=1;
                                          }
                                          else op=1;
             //else cout<<"Optiune gresita!\n";
    if(op==1) cout<<"Optiune gresita!\n";

  }
  this->Repository.SetINB(this->Repository.GetAllValori(),this->Repository.GetAllFrecvente());
  this->Repository.SetINT(this->Repository.GetAllTranzactii());
  cout<<"La revedere.\n";
  delete [] opt;
  opt=NULL;
}
