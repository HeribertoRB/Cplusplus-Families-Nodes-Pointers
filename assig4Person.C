/*****************************************
assig4Person.C

This will set a person
*****************************************/

#include "assig4Person.h"
using namespace std;

Person::Person()
{
  SSN = 0;
  Fname = Lname = "Space";
}

Person::Person(long i, string f, string l)
{
  SSN = i;
  Fname = f;
  Lname = l;
}
