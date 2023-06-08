#include <iostream>
#include "Colectie.h"
#include "List.h"
#include <tuple>
using namespace std;

void Colectie::Adauga(int numar,int frecv){
  this->valori.push_back(numar);
  this->frecvente.push_back(frecv);
}

void Colectie::Modifica(int poz, int nr, int fr){
  this->valori.update(poz,nr);
  this->frecvente.update(poz,fr);
}

tuple<int,int> Colectie::Sterge(int poz){
  int val=0,frecv=0;
  val=this->valori.delete_at(poz);
  frecv=this->frecvente.delete_at(poz);
  return {val,frecv};
}

tuple<int,int> Colectie::GetAt(int poz){
  int a=0;
  int b=0;
  a=this->valori.get_at(poz);
  b=this->frecvente.get_at(poz);
  return {a,b};
}
bool Colectie::Empty(){
  int nr=this->valori.Size();
  if (nr==0) return 0;
  return 1;
}

int Colectie::GetSize(){
  return this->frecvente.Size();
}

int Colectie::Cautare(int numar){
  return this->valori.search(numar); //-1 e false si altceva e ok
}
