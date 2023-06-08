#ifndef REPOFILE_H_INCLUDED
#define REPOFILE_H_INCLUDED

#include <iostream>
#include <fstream>
#include "RepoATM.h"
#include <vector>
#include <string.h>
using namespace std;

#endif // REPOFILE_H_INCLUDED

class RepoFile{
private:
  char fisierB[20];
  char fisierT[20];
public:
   RepoFile(){
   strcpy(this->fisierB,"");
   strcpy(this->fisierT,"");
   }

   RepoFile(char* b, char*t){
    strcpy(this->fisierB,b);
    strcpy(this->fisierT,t);
  }
  ~RepoFile(){};
  void SetUPB();
  void SetUPT();
  void SetINB(vector<int> lista1, vector<int> lista2);
  void SetINT(vector<Tranzactie> lista);
};
