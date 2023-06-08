#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#pragma once

#endif // LIST_H_INCLUDED
#include "Node.h"
#include <iostream>
using namespace std;
template <class T>
class List {
private:
    /* definiti o reprezentare dublu inlantuita pe elementele din lista */
    Node<T>* first;

public:
    /// constructor implicit
    List () {
        this->first=nullptr;
    }

    /// \return dimensiunea listei
    int Size() const;

    ///  verifica daca lista e vida
    /// \return true, daca lista e vida, altfel returneaza false
    bool is_empty() const;

    /// adaugare element la sfarsit
    /// \param e - elementul adaugat
    void push_back(T e);

    ///
    /// \param i - pozitia unui elem in lista , 0<=i<size()
    /// \return  elementul de pe pozitia i
    /// \raise   exceptie daca i nu e valid
    T get_at(int i) const;

    // modifica element de pe pozitia i si returneaza vechea valoare
    //arunca exceptie daca i nu e valid
    T update(int i, T e);

    // adaugare element pe o pozitie i
    //arunca exceptie daca i nu e valid
    void set_at(int i, T e);

    // sterge element de pe o pozitie i si returneaza elementul sters
    //arunca exceptie daca i nu e valid
    T delete_at(int i);

    // cauta element si returneaza prima pozitie pe care apare (sau -1)
    int search(T e)  const;

    // returnare iterator
//    Iterator iterator() const;

    ///
    /// destructor
    ~List();

};

template<class T>
T List<T>::update(int i, T e) {
    if(i < 0 || i >= Size())
        throw invalid_argument("pozitia nu e valida");
    Node<T>* crt = first;
    int noE = 0;
    while (noE < i){
        crt = crt->next;
        noE++;
    }
    T old_value = crt->info;
    crt->info = e;

    return old_value;
}

template<class T>
T List<T>::get_at(int i) const {
    if(i < 0 || i >= Size())
        throw invalid_argument("pozitia nu e valida");
    Node<T>* crt = first;
    int noE = 0;
    while (noE < i){
        crt = crt->next;
        noE++;
    }
    return crt->info;
}

template<class T>
void List<T>::push_back(T e) {
    Node<T>* newNode = new Node<T>(e,nullptr, nullptr);
    if(first == nullptr){
        first = newNode;
    }
    else{
        Node<T>* last=first;
        while (last->next != nullptr){
            last= last->next;
        }
        //last->next = newNode;
        newNode->prev=last;
        last->next = newNode;
    }

}

template<class T>
bool List<T>::is_empty() const {
    return first == nullptr;
}

template<class T>
int List<T>::Size() const {
    int contor = 0;
    Node<T>* last = first;
    while(last != nullptr)
    {
        contor++;
        last = last->next;
    }
    return contor;
}

template<class T>
int List<T>::search(T e)  const{
  Node<T>* elem=first;
  int nrE=0;
  while(elem !=nullptr){
    if (e == elem->info){
     return nrE;
    }
    nrE++;
    elem = elem->next;
  }
  return -1;
}

template<class T>
void List<T>::set_at(int i, T e){
  Node<T>* elem=first;
  int nrE=0;
  if(i>Size() || i<0){
    throw invalid_argument("pozitia nu e valida");
  }
  if(i==0){
    Node<T>* newNode = new Node<T>(e,nullptr,first);
    first=newNode;
  }
  else{
  while(nrE<i-1){
        elem=elem->next;
        nrE++;
  }
  Node<T>* newNode = new Node<T>(e,elem->next->prev, elem->next);
  elem->next->prev=newNode;
  elem->next=newNode;
  }
}

template <class T>
T List<T>::delete_at(int i){
  Node <T>* elem=first;
  int nrE;
  T vechi;
  if(i>Size() || i<0){
    throw invalid_argument("pozitia nu e valida");
  }
  if(i==0){
    first=elem->next;
    first->prev=elem->prev;
    vechi = elem->info;
    delete elem;
  }
  else{
  while(nrE<i-1){
    elem=elem->next;
    nrE++;
  }
  Node <T>* temp=elem->next;

  elem->next=temp->next;
  vechi=temp->info;
  if(i!=Size()) (temp->next)->prev=temp->prev;
  delete temp;
  //delete elem;
  }
   return vechi;
}

template <class T>
List<T>::~List(){
  while(first!=nullptr){
      Node <T>* elem=first;
      first=first->next;
      delete elem;
  }
}
