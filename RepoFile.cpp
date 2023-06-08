#include <iostream>
#include <fstream>
#include "RepoATM.h"
#include <vector>
#include <string.h>
#include "RepoFile.h"
using namespace std;


void RepoFile::SetUPB(){
    ifstream f(this->fisierB);
    int val,frv;
    while (f>>val){
      f>>frv;
      //this->Adaugare(val,frv);
    }
    f.close();
}

void RepoFile::SetUPT(){
    ifstream f(this->fisierT);
    int s,val,frv;
    while (f>>s){
     Colectie c;
     int suma=0;
     while( suma!=s)
      {
          f>>val;
          f>>frv;
          suma=suma+val*frv;
          c.Adauga(val,frv);
      }
    Tranzactie t(s,c);
     //this->AdaugareTranzactie(t);
    }
    f.close();
}

void RepoFile::SetINB(vector<int> valori,vector<int>frecvente){
  ofstream g(this->fisierB);
  for(int i=0;i<valori.size();i++){
        g<<valori[i]<<" "<<frecvente[i]<<endl;
  }
  g.close();
}

void RepoFile::SetINT(vector<Tranzactie> lista){
  ofstream g(this->fisierT);
  for(int i=0;i<lista.size();i++){
        g<<lista[i].GetSuma()<<" ";
        vector<int> l1=lista[i].GetTranzactieValori();
        vector<int> l2=lista[i].GetTranzactieFrecventa();
        cout<<l1.size();
        for(int j=0;j<l1.size();j++) cout<<l1[j]<<" "<<l2[j]<<" ";
        for(int j=0;j<l1.size();j++)
        {
          g<<l1[j]<<" "<<l2[j]<<" ";
        }
        g<<endl;
  }
  g.close();
}
