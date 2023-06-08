#ifndef REPOATM_H_INCLUDED
#define REPOATM_H_INCLUDED
#include "Colectie.h"
#include "List.h"
#include "Tranzactie.h"
#include <vector>
#include<string.h>
#pragma once

#endif // REPOATM_H_INCLUDED
class Repo{
private:
  Colectie Bancnote;
  vector<Tranzactie> Tranzactii;
  char fisierB[20];
  char fisierT[20];
public:
  Repo(){
  this->Bancnote= Colectie();
    strcpy(this->fisierB,"");
   strcpy(this->fisierT,"");
  }

  Repo(char*b,char*t){
  this->Bancnote=Colectie();
  strcpy(this->fisierB,b);
    strcpy(this->fisierT,t);
  }

  Repo(const Colectie& c,char*b,char*t){
  this->Bancnote=c;
  strcpy(this->fisierB,b);
    strcpy(this->fisierT,t);
  }
  ~Repo(){}

  void Adaugare(int val,int fr);
  void Modificare(int poz,int val,int fr);
  void Stergere(int poz);
  int Search(int val);
  vector<int> GetAllValori();
  vector<int> GetAllFrecvente();

  vector<Tranzactie>GetAllTranzactii();
  void AdaugareTranzactie(Tranzactie t);
  void StergereNULL();

  void FinalizareTranzactie(Colectie lista);
  Colectie RealizareTranzactie(int suma);
  Colectie BackTrack(int suma,int sum[],int n,int x[],int* val,int* nr,int&nrsol);
  int Valid(int k, int S, int sum[], int* val, int x[], int n);
  Colectie Rezultat(int x[],int* val,int& nrsol,int  n,int& k,int S);


  void SetUPB();
  void SetUPT();
  void SetINB(vector<int> lista1, vector<int> lista2);
  void SetINT(vector<Tranzactie> lista);
};
