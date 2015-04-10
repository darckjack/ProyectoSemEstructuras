

#include "../include/ListF.h"

bool ListF::isAvalidPos(Node<Fotografo>* p) {
  Node<Fotografo>* aux = anchor;

  while (aux != nullptr) {
    if (aux == p) {
      return true;
    }
    aux = aux->getNext();
  }
  return false;
}

////////////////////////////////////////////

ListF::ListF() {
  anchor = nullptr;
}

ListF::~ListF() {
  deleteAll();
}

bool ListF::isEmpty() {
  return anchor == nullptr;
}

void ListF::insertData(Node<Fotografo>* p, Fotografo& e) {
  if (p != nullptr and !isAvalidPos(p)) {
    throw ListFException ("Posicion invalida al insertar");
  }

  Node<Fotografo>* aux = new Node<Fotografo> (e);
  if (aux == nullptr) {
    throw ListFException("Memoria insufuciente al insertar");

    if (p == nullptr) {
      aux->setNext(anchor);
      anchor = aux;
    } else {
      aux->setNext(p->getNext());
      p->setNext(aux);
    }
  }
}

void ListF::deleteData(Node<Fotografo>* p) {
  if (!isAvalidPos(p)) {
    throw ListFException("Posicion es invalida al eliminar");
  }

  if (p == anchor) {
    anchor = p->getNext();
  } else {
    previousPos(p)->setNext(p->getNext());
  }
  delete p;
}

Node<Fotografo>* ListF::firstPos() {
  return anchor;
}

Node<Fotografo>* ListF::lastPos() {
  if (isEmpty()) {
    return nullptr;
  }

  Node<Fotografo>* aux = anchor;
  while (aux->getNext() != nullptr) {
    aux = aux->getNext();
  }

  return aux;
}

Node<Fotografo>* ListF::previousPos(Node<Fotografo>* p) {
  Node<Fotografo>* aux = anchor;

  while (aux != nullptr and aux->getNext() != p) {
    aux = aux->getNext();
  }

  return aux;
}

Node<Fotografo>* ListF::nextPos(Node<Fotografo>* p) {
  if (!isAvalidPos(p)) {
    return nullptr;
  }
  return p->getNext();
}

Node<Fotografo>* ListF::findData(Fotografo e) {
  Node<Fotografo>* aux = anchor;

  while (aux != nullptr and aux->getData() != e) {
    aux = aux->getNext();
  }

  return aux;
}

Fotografo ListF::retrieve(Node<Fotografo>* p) {
  if (!isAvalidPos(p)) {
    throw ListFException("Error!, Posicion invalida");
  }

  return p->getData();
}

void ListF::print() {
  Node<Fotografo>* aux = anchor;

  while (aux != nullptr) {
    cout << aux->getDataPtr()->print() << endl;
    aux = aux->getNext();
  }

}

void ListF::deleteAll() {
  Node<Fotografo>* aux;

  while (anchor != nullptr) {
    aux = anchor;
    anchor = anchor->getNext();
    delete aux;
  }
}
