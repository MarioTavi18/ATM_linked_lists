#ifndef TRANZACTIE_H_INCLUDED
#define TRANZACTIE_H_INCLUDED
#include "Colectie.h"
#include <iostream>
#include <vector>
#pragma once

#endif // TRANZACTIE_H_INCLUDED
class Tranzactie{
private:
  int suma;
  Colectie BaniPlatiti;
public:
  Tranzactie(){
    this->suma=0;
  }
  ~Tranzactie(){}

  Tranzactie(int s,Colectie& c){
  this->suma=s;
  for(int i=0;i<c.GetSize();i++){
    auto[a,b]=c.GetAt(i);
    this->BaniPlatiti.Adauga(a,b);
  }
  }

  int GetSuma(){
    return this->suma;
  }
  int GetSizeTranzactie(){
    return this->BaniPlatiti.GetSize();
  }

  vector<int> GetTranzactieValori(){
    vector<int> lista;
    for(int i=0; i<GetSizeTranzactie();i++){
      auto[a,b]=this->BaniPlatiti.GetAt(i);
      lista.push_back(a);
    }
    return lista;
  }

  vector<int> GetTranzactieFrecventa(){
    vector<int> lista;
    for(int i=0; i<GetSizeTranzactie();i++){
      auto[a,b]=this->BaniPlatiti.GetAt(i);
      lista.push_back(b);
    }
    return lista;
  }

  friend ostream& operator<<(ostream& afis, Tranzactie t){
    afis<<"Tranzactie in valoare de "<<t.GetSuma()<<" RON platita cu:\n";
    vector<int> frecv=t.GetTranzactieFrecventa();
    vector<int> valori=t.GetTranzactieValori();
    for(int i=0;i<valori.size();i++) {
      cout<<valori[i]<<" RON de "<<frecv[i]<<" ori ";
      if(i!=valori.size()-1) cout<<",";
    }
    cout<<endl;
    return afis;
  }
};
