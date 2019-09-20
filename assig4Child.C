/*********************************
assig4Child.C

This will set a child with Person class. It will not have a sibling.
*********************************/
#include "assig4Child.h"
using namespace std;

Child::Child():Person()
{
  nextSibling = NULL;
}

Child::Child(long i, string f, string l):Person(i, f, l)
{
  nextSibling = NULL;
}
