#include "TestList.h"
#include "List.h"
#include "Colectie.h"
#include "RepoATM.h"
#include "Tranzactie.h"
#include <vector>
#include <assert.h>

void TestList::TestTot(){
    test_push_back();
    test_get_at();
    test_update();
    test_search();
    test_set_at();
    test_delete_at();
    test_adaugare_modificare_stergere();
    test_fisier();
    cout<<"Teste bune\n";
}
void TestList::test_push_back()
{
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    assert(newList.Size() == 4);
}

void TestList::test_get_at() {
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    assert (newList.get_at(0) == 1);
    assert (newList.get_at(1) == 2);
    assert (newList.get_at(2) == 3);
    assert (newList.get_at(3) == 4);
}

void TestList::test_update() {
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    newList.update(2, 17);
    assert (newList.get_at(0) == 1);
    assert (newList.get_at(1) == 2);
    assert (newList.get_at(2) == 17);
    assert (newList.get_at(3) == 4);
}

void TestList::test_search(){
  List <int> newList;
  newList.push_back(1);
  newList.push_back(2);
  newList.push_back(3);
  newList.push_back(4);
  assert(newList.search(3)==2);
  assert(newList.search(4)==3);
  assert(newList.search(100)==-1);
}

void TestList::test_set_at(){
  List <int> newList;
  newList.push_back(1);
  newList.push_back(2);
  newList.push_back(3);
  newList.push_back(4);
  newList.set_at(2,100);
  assert(newList.get_at(2)==100);
  newList.set_at(0,1000);
  assert(newList.get_at(0)==1000);
}
void TestList::test_delete_at(){
   List <int> newList;
  newList.push_back(1);
  newList.push_back(2);
  newList.push_back(3);
  newList.push_back(4);
  assert(newList.delete_at(3)==4);
  assert(newList.Size() == 3);
  assert(newList.get_at(2)==3);
  assert(newList.search(4)==-1);
}

void TestList::test_adaugare_modificare_stergere(){
  Colectie c;
  Repo r(c,"","");
  r.Adaugare(10,2);
  r.Adaugare(20,2);
  r.Adaugare(30,2);
  r.Adaugare(40,2);
  r.Modificare(0,100,100);
  r.Stergere(3);
  vector<int>l1=r.GetAllValori();
  assert(l1.size()==3);
  assert(l1[0]==100);
  assert(l1[1]==20);
  assert(l1[2]==30);
  Colectie test;
  test.Adauga(10,10);
  Tranzactie t(10,test);
  r.AdaugareTranzactie(t);
  vector<Tranzactie> lista=r.GetAllTranzactii();
  assert(lista.size()==1);
  assert(lista[0].GetSuma()==10);
}

void TestList::test_fisier(){
  Colectie c;
  Repo r(c,"TestB","");
  r.SetUPB();
  vector<int> val=r.GetAllValori();
  assert(val[0]==10);
  assert(val[1]==20);
  assert(val[2]==30);
  assert(val[3]==40);
}
