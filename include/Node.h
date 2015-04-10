
#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <class T>
class Node {
public:
  Node();
  Node(T);
  ~Node();

  T* getDataPtr();
  void setDataPtr(T*);

  T getData();
  void setData(T);

  Node* getNext();
  void setNext(Node*);

  Node* getPrev();
  void setPrev(Node*);

  T* dataptr;

private:
  Node *next;
  Node *prev;


};

// Constructor por defecto
template<class T>
Node<T>::Node() {
  dataptr = nullptr;
  next = nullptr;
  prev = nullptr;
}

// Constructor por parámetro
template<class T>
Node<T>::Node(T data_) {
  *dataptr = data_;
  next = nullptr;
  prev = nullptr;
}

template<class T>
T Node<T>::getData() {
  return *dataptr;
}

template<class T>
T* Node<T>::getDataPtr() {
  return dataptr;
}

template<class T>
Node<T>* Node<T>::getNext() {
  return next;
}

template<class T>
Node<T>* Node<T>::getPrev() {
  return prev;
}

template<class T>
void Node<T>::setData(T data_) {
  *dataptr = data_;
}

template<class T>
void Node<T>::setNext(Node* next_) {
  next = next_;
}

template<class T>
void Node<T>::setPrev(Node* prev_) {
  prev = prev_;
}

template<class T>
Node<T>::~Node() {}

#endif // NODE_H
