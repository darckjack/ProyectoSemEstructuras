
#ifndef LISTO_H_INCLUDED
#define LISTO_H_INCLUDED
#include <exception>
#include <iostream>
#include <string>

#include "Fotografo.h"
#include "Obra.h"
#include "Node.h"

using namespace std;

class ListOException : public exception {

protected:
  string msg;

public:
  explicit ListOException(const char* message) : msg(message) {}

  explicit ListOException(const string& message ) : msg(message) {}

  virtual~ListOException() throw () {}

  virtual const char* what() const throw() {
    return msg.c_str();
  }

};


class ListO {
private:
  Node<Obra>* anchor;

  bool isAvalidPos(Node<Obra>*);

public:
  ListO();
  ~ListO();
  bool isEmpty();
  void insertData(Node<Obra>*, Obra&);
  void deleteData(Node<Obra>*);
  Node<Obra>* firstPos();
  Node<Obra>* lastPos();
  Node<Obra>* previousPos(Node<Obra>*);
  Node<Obra>* nextPos(Node<Obra>*);
  Node<Obra>* findData(Obra);
  Obra retrieve(Node<Obra>* );
  void print ();
  void deleteAll();
};

#endif // ListO_H_INCLUDED
