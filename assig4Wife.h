/***********************************
assig4Wife.h

A wife can have several children.
**********************************/
#ifndef ASSIG4WIFE_H
#define ASSIG4WIFE_H

#include "assig4Person.h"
#include "assig4Child.h"
using namespace std;

class Wife;
typedef Child* myChildren;

class Wife: public Person
{
  friend class Family;
 private:
  myChildren nextChild;
 public:
  Wife();
  Wife(long i, string f, string l);
};

#endif
