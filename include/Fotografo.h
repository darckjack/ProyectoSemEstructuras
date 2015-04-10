
#ifndef FOTOGRAFO_H
#define FOTOGRAFO_H

#include <string>
#include <iostream>

using namespace std;

class Fotografo {

private:
  std::string name;
  std::string city;
  std::string phone;
  int age;
  int experience;

public:
  Fotografo();
  Fotografo(std::string, std::string, std::string, int, int);
  ~Fotografo();
  std::string getName() { return name; }
  std::string getCity() { return city; }
  std::string getPhone() { return phone; }
  int getAge() { return age; }
  int getExperience() { return experience; }
  void setName(std::string val) { name = val; }
  void setCity(std::string val) { city = val; }
  void setPhone(std::string val) { phone = val; }
  void setAge(int val) { age = val; }
  void setExperience(int val) { experience = val; }
  std::string to_s();
  std::string print();

  bool operator == (Fotografo&);
  bool operator != (Fotografo&);
  bool operator <  (Fotografo&);
  bool operator <= (Fotografo&);
  bool operator >  (Fotografo&);
  bool operator >= (Fotografo&);

  friend ostream& operator << (ostream&, const Fotografo&);
  friend istream& operator >> (istream&, const Fotografo&);

};

#endif // FOTOGRAFO_H
