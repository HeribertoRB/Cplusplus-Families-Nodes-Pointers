/*********************************
assig4Husband.h

A husand can have a wife and point to another family.
*********************************/
#ifndef ASSIG4HUSBAND_H
#define ASSIG4HUSBAND_H

#include "assig4Person.h"
#include "assig4Wife.h"
using namespace std;

class Husband;
typedef Husband* nextFamily;
typedef Wife* myWife;

class Husband: public Person
{
  friend class Family;
 private:
  nextFamily family;
  myWife wife;
 public:
  Husband();
  Husband(long i, string f, string l);
};

#endif
