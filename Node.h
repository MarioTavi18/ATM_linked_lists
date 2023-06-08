#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#pragma once

#endif // NODE_H_INCLUDED

template <typename T>
class List;

template <class T>
class Node {
private:
    T info;
    Node <T>* prev;
    Node<T>* next;
public:
    Node(T info,Node<T>*prev, Node<T>* next) : info(info), prev(prev), next(next){}
    Node(T info) : info(info){
      prev=nullptr;
      next= nullptr;
      }
    friend class List<T>;
};



