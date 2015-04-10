
#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

class Categoria {
public:
  Categoria();
  ~Categoria();
  std::string getName() { return name; }
  int getElements() { return elements; }

  void setName(std::string val) { name = val; }
  void setElements(int val) { elements = val; }

  std::string print();
private:
  std::string name;
  int elements;
};

#endif // CATEGORIA_H
