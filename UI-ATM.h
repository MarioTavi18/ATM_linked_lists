#ifndef UI-ATM_H_INCLUDED
#define UI-ATM_H_INCLUDED
#include "RepoATM.h"


#endif // UI-ATM_H_INCLUDED
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

  void meniu(){
    cout<<"da";
  }
};
