
#include "../include/Fotografo.h"
#include <string>

using namespace std;

Fotografo::Fotografo()
{
	name  = "";
	city  = "";
	phone = "";
	age = 0;
	experience = 0;
}

Fotografo::Fotografo(string name, string city, string phone, \
                    int age, int experience) {
  this->name = name;
  this->city = city;
  this->phone = phone;
  this->age = age;
  this->experience = experience;
}

Fotografo::~Fotografo()
{

}

string Fotografo::to_s() {
  return getName();
}

string Fotografo::print() {
  return getName();
}

bool Fotografo::operator == (Fotografo& a){
  return getName() == a.getName();
}

bool Fotografo::operator != (Fotografo& a){
  return getName() != a.getName();
}

bool Fotografo::operator < (Fotografo& a){
  return getName() < a.getName();
}

bool Fotografo::operator <= (Fotografo& a){
  return getName() <= a.getName();
}

bool Fotografo::operator > (Fotografo& a){
  return getName() > a.getName();
}

bool Fotografo::operator >= (Fotografo& a){
  return getName() >= a.getName();
}

ostream& operator << (ostream& os, Fotografo& a){
  os << a.to_s();
  return os;
}

