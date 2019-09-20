/******************************************************
assig4Person.h

Each person has a SSN, first name, and last name
******************************************************/
#ifndef ASSIG4PERSON_H
#define ASSIG4PERSON_H

#include <string>
using namespace std;

class Person
{
  friend class Family;
 protected:
  long SSN;
  string Fname;
  string Lname;
 public:
  Person();
  Person(long i, string f, string l);
};

#endif
