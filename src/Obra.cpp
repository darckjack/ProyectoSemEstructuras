
#include "../include/Obra.h"

Obra::Obra()
{
    name      = "";
    locaNeed  = false;
    modelNeed = false;
    priceNeed = false;
}

Obra::Obra(string name, string camera, string lens, string diaphragm, \
          int technique, int shutter, bool locaNeed, bool modelNeed, \
          bool priceNeed, string location, string model, float price)
{
  this->name = name;
  this->camera = camera;
  this->lens = lens;
  this->diaphragm = diaphragm;
  this->technique = technique;
  this->shutter = shutter;
  this->locaNeed = locaNeed;
  this->modelNeed = modelNeed;
  this->priceNeed = priceNeed;
  this->location = location;
  this->model = model;
  this->price = price;
}

Obra::~Obra()
{
    //dtor
}

string Obra::getInfo(){
  return "Nombre: " + name + ", Autor: " + author.to_s() + ", Camara: " + camera + \
      ".";
}

string Obra::print(){
  return getInfo();
}

bool Obra::operator == (Obra& a){
  return getName() == a.getName();
}

bool Obra::operator != (Obra& a){
  return getName() != a.getName();
}

bool Obra::operator < (Obra& a){
  return getName() < a.getName();
}

bool Obra::operator <= (Obra& a){
  return getName() <= a.getName();
}

bool Obra::operator > (Obra& a){
  return getName() > a.getName();
}

bool Obra::operator >= (Obra& a){
  return getName() >= a.getName();
}

ostream& operator << (ostream& os, Obra& a){
  os << a.getInfo();
  return os;
}

istream& operator >> (istream&, const Obra&){

}

