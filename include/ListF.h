
#ifndef LISTF_H_INCLUDED
#define LISTF_H_INCLUDED
#include <exception>
#include <iostream>
#include <string>

#include "Fotografo.h"
#include "Node.h"

using namespace std;

class ListFException : public exception {

protected:
  string msg;

public:
  explicit ListFException(const char* message) : msg(message) {}

  explicit ListFException(const string& message ) : msg(message) {}

  virtual~ListFException() throw () {}

  virtual const char* what() const throw() {
    return msg.c_str();
  }

};


class ListF {
private:
  Node<Fotografo>* anchor;

  bool isAvalidPos(Node<Fotografo>*);

public:
  ListF();
  ~ListF();
  bool isEmpty();
  void insertData(Node<Fotografo>*, Fotografo&);
  void deleteData(Node<Fotografo>*);
  Node<Fotografo>* firstPos();
  Node<Fotografo>* lastPos();
  Node<Fotografo>* previousPos(Node<Fotografo>*);
  Node<Fotografo>* nextPos(Node<Fotografo>*);
  Node<Fotografo>* findData(Fotografo);
  Fotografo retrieve(Node<Fotografo>* );
  void print ();
  void deleteAll();
};

#endif // LISTF_H_INCLUDED
