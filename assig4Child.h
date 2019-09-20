/**************************************
assig4Child.h

A child can have a sibling.
**************************************/
#ifndef ASSIG4CHILD_H
#define ASSIG4CHILD_H

#include "assig4Person.h"
using namespace std;

class Child;
typedef Child* mySibling;

class Child: public Person
{
  friend class Family;
 private:
  mySibling nextSibling;
 public:
  Child();
  Child(long i, string f, string l);
};

#endif
