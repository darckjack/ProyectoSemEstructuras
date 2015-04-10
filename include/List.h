
#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <exception>
#include <iostream>
#include <string>

using namespace std;

class ListException : public exception {

protected:
  string msg;

public:
  explicit ListException(const char* message) : msg(message) {}

  explicit ListException(const string& message ) : msg(message) {}

  virtual~ListException() throw () {}

  virtual const char* what() const throw() {
    return msg.c_str();
  }

};


template<class T>
class List {
private:
  Node<T>* anchor;

  bool isAvalidPos(Node<T>*);

public:
  List();
  ~List();
  bool isEmpty();
  void insertData(Node<T>*, T&);
  void deleteData(Node<T>*);
  Node<T>* firstPos();
  Node<T>* lastPos();
  Node<T>* previousPos(Node<T>*);
  Node<T>* nextPos(Node<T>*);
  Node<T>* findData(T);
  T retrieve(Node<T>* );
  void print ();
  void deleteAll();
};

template<class T>
bool List<T>::isAvalidPos(Node<T>* p) {
  Node<T>* aux = anchor;

  while (aux != nullptr) {
    if (aux == p) {
      return true;
    }
    aux = aux->getNext();
  }
  return false;
}

////////////////////////////////////////////
template<class T>
List<T>::List() {
  anchor = nullptr;
}
template<class T>
List<T>::~List() {
  deleteAll();
}

template<class T>
bool List<T>::isEmpty() {
  return anchor == nullptr;
}

template<class T>
void List<T>::insertData(Node<T>* p, T& e) {
  if (p != nullptr and !isAvalidPos(p)) {
    throw ListException ("Posicion invalida al insertar");
  }

  Node<T>* aux = new Node<T> (e);
  if (aux == nullptr) {
    throw ListException("Memoria insufuciente al insertar");

    if (p == nullptr) {
      aux->setNext(anchor);
      anchor = aux;
    } else {
      aux->setNext(p->getNext());
      p->setNext(aux);
    }
  }
}

template<class T>
void List<T>::deleteData(Node<T>* p) {
  if (!isValidPos(p)) {
    throw ListException("Posicion es invalida al eliminar");
  }

  if (p == anchor) {
    anchor = p->getNext();
  } else {
    previousPos(p)->setNext(p->getNext());
  }
  delete p;
}

template<class T>
Node<T>* List<T>::firstPos() {
  return anchor;
}
template<class T>
Node<T>* List<T>::lastPos() {
  if (isEmpty()) {
    return nullptr;
  }

  Node<T>* aux = anchor;
  while (aux->getNext() != nullptr) {
    aux = aux->getNext();
  }

  return aux;
}
template<class T>
Node<T>* List<T>::previousPos(Node<T>* p) {
  Node<T>* aux = anchor;

  while (aux != nullptr and aux->getNext() != p) {
    aux = aux->getNext();
  }

  return aux;
}
template<class T>
Node<T>* List<T>::nextPos(Node<T>* p) {
  if (!isAvalidPos(p)) {
    return nullptr;
  }
  return p->getNext();
}

template<class T>
Node<T>* List<T>::findData(T e) {
  Node<T>* aux = anchor;

  while (aux != nullptr and aux->data != e) {
    aux = aux->getNext();
  }

  return aux;
}

template<class T>
T List<T>::retrieve(Node<T>* p) {
  if (!isAvalidPos(p)) {
    throw ListException("Error!, Posicion invalida");
  }

  return p->getData();
}

template<class T>
void List<T>::print() {
  Node<T>* aux = anchor;

  while (aux != nullptr) {
    cout << aux->getData() << endl;
    aux = aux->getNext();
  }

}

template<class T>
void List<T>::deleteAll() {
  Node<T>* aux;

  while (anchor != nullptr) {
    aux = anchor;
    anchor = anchor->getNext();
    delete aux;
  }
}

#endif // LIST_H_INCLUDED
