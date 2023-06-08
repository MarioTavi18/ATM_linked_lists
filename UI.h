#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED
#include "RepoATM.h"
#include "RepoFile.h"
#include <vector>


#endif // UI_H_INCLUDED
class UI{
private:
  Repo Repository;

public:
  UI(){
  this->Repository=Repo();
  }
  UI(const Repo& r){
  this->Repository=r;
  }
  ~UI(){};
  void Optiune(char*& y);
  void LitereMici(char*& y);
  bool NumaiCifre(char* n);
  void printMeniu();
  void meniu();

  void AdaugareUI();
  void ModificareUI();
  void StergereUI();
  void AfisareUI(vector<int> l1,vector<int> l2);
  void AfisareT(vector<Tranzactie> t);

  void AdaugareTranzactieUI();
};
