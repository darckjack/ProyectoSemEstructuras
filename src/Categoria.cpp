/*
* Nombre: Juan Jesus Gomez Barajas
* Codigo: 214519467
* Seccion: D01
*/
#include "../include/Categoria.h"
#include <cstring>

using namespace std;

Categoria::Categoria()
{
	name = "";
	elements = 0;
}

string Categoria::print()
{
  return name;
}

Categoria::~Categoria()
{
    //dtor
}
