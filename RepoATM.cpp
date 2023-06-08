#include <iostream>
#include "RepoATM.h"
#include "Colectie.h"
#include "List.h"
#include <vector>
#include <fstream>
using namespace std;

///---------------------------------------------------------------------------------------------
///Bancnote aka Colectie
///---------------------------------------------------------------------------------------------
void Repo::Adaugare(int val,int fr){
  int nr=this->Bancnote.Cautare(val);
  if(nr==-1) this->Bancnote.Adauga(val,fr);
  else{
      auto[a,b]=this->Bancnote.GetAt(nr);
      this->Bancnote.Modifica(nr,val,fr+b);
  }
}

void Repo::Modificare(int poz,int val,int fr){
  if(poz<0 || poz>=this->Bancnote.GetSize()) throw invalid_argument("Pozitie incorecta!");
  this->Bancnote.Modifica(poz,val,fr);
}
void Repo::Stergere(int poz){
  if(poz<0 || poz>=this->Bancnote.GetSize()) throw invalid_argument("Pozitie incorecta!");
  auto[a,b]=this->Bancnote.Sterge(poz);
}

int Repo::Search(int val){
  return this->Bancnote.Cautare(val);
}
///---------------------------------------------------------------------------------------------
///Tranzactie
///---------------------------------------------------------------------------------------------
void Repo::FinalizareTranzactie(Colectie lista){
  for(int i=0;i<lista.GetSize();i++){
        auto[a,b]=lista.GetAt(i);
        int poz=Search(a);
        auto[c,d]=this->Bancnote.GetAt(poz);
        Modificare(poz,a,d-b);
      }
}
void Repo::AdaugareTranzactie(Tranzactie t){
  this->Tranzactii.push_back(t);
}

void Repo::StergereNULL(){
  vector<int> lista=GetAllFrecvente();
  int nr=lista.size();
  int j=0;
  while(j<nr){
    if(lista[j]==0){
      Stergere(j);
      lista=GetAllFrecvente();
      nr=lista.size();
    }
    else j++;
  }
}

Colectie Repo::RealizareTranzactie(int suma){
    int x[20],n=this->Bancnote.GetSize(),nrsol=0,sum[20]={0};
    int size = this->Bancnote.GetSize();
    int *val = new int[size+1];
    val[0] = 0;
    int *nr = new int[size+1];
    nr[0] = 0;
    val[0]=0;
    nr[0]=0;
    for (int i=0;i<size;i++)
    {
        auto[a,b]=this->Bancnote.GetAt(i);
        val[i+1] = a;
        nr[i+1] = b;
    }
  //BackTrack(valori,frecvente,suma,Raspuns, sumC);
   return BackTrack(suma, sum, n, x, val, nr,nrsol);
}

Colectie Repo::BackTrack(int S,int sum[],int n,int x[],int* val,int* nr,int&nrsol){
  int k=1, cand;
    x[1]=-1;
    while (k>0)
    {
        cand=0;
        while (cand==0 && x[k]<nr[k]) {x[k]++; cand = Valid(k, S, sum, val, x, n);}
        if (cand==0) k--;
        else if (k==n) return Rezultat(x, val, nrsol, n, k, S);
        else {k++; x[k]=-1;}
    }
    if(nrsol==0) {Colectie r; return r;}
}

int Repo::Valid(int k, int S, int sum[], int* val, int x[], int n)
{

    sum[k] = sum[k-1] + val[k] * x[k];
    if (sum[k] > S) return 0;
    if (k==n && sum[k]!=S) return 0;
    return 1;
}

Colectie Repo::Rezultat(int x[],int* val,int& nrsol,int  n,int& k,int S){
  nrsol++;
  Colectie Raspuns;
  for(int i=1;i<=n;i++)
            if (x[i]!=0)
            {
                Raspuns.Adauga(val[i],x[i]);
            }
  return Raspuns;
}
///---------------------------------------------------------------------------------------------
///GetAll-uri
///---------------------------------------------------------------------------------------------
vector<Tranzactie> Repo::GetAllTranzactii(){
    return this->Tranzactii;
}

vector<int> Repo::GetAllValori(){
  int nr=this->Bancnote.GetSize();
  vector<int> valori;
  for(int i=0;i<nr;i++){
    auto[a,b]=this->Bancnote.GetAt(i);
    valori.push_back(a);
  }
  return valori;
}

vector<int> Repo::GetAllFrecvente(){
  int nr=this->Bancnote.GetSize();
  vector<int> frecv;
  for(int i=0;i<nr;i++){
    auto[a,b]=this->Bancnote.GetAt(i);
    frecv.push_back(b);
  }
  return frecv;
}
///

void Repo::SetUPB(){
    ifstream f(this->fisierB);
    int val,frv;
    while (f>>val){
      f>>frv;
      Adaugare(val,frv);
    }
    f.close();
}

void Repo::SetUPT(){
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
    this->Tranzactii.push_back(t);
    }
    f.close();
}

void Repo::SetINB(vector<int> valori,vector<int>frecvente){
  ofstream g(this->fisierB);
  for(int i=0;i<valori.size();i++){
        g<<valori[i]<<" "<<frecvente[i]<<endl;
  }
  g.close();
}

void Repo::SetINT(vector<Tranzactie> lista){
  ofstream g(this->fisierT);
  for(int i=0;i<lista.size();i++){
        g<<lista[i].GetSuma()<<" ";
        vector<int> l1=lista[i].GetTranzactieValori();
        vector<int> l2=lista[i].GetTranzactieFrecventa();

        for(int j=0;j<l1.size();j++) {g<<l1[j]<<" "<<l2[j]<<" ";}
        g<<endl;
  }
  g.close();
}
