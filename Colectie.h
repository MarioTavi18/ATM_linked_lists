#ifndef COLECTIE_H_INCLUDED
#define COLECTIE_H_INCLUDED
#include "List.h"
#include <tuple>
#pragma once

#endif // COLECTIE_H_INCLUDED
class Colectie{
private:
  List<int> valori;
  List<int> frecvente;
public:
  Colectie(){
  }
  ~Colectie(){
  }
  void Adauga(int numar, int frecv);
  void Modifica(int poz, int numar, int frecv);
  tuple<int,int> Sterge(int poz);
  bool Empty();
  tuple<int,int> GetAt(int poz);
  int GetSize();
  int Cautare(int numar);
};
