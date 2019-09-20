/***************************************
assig4Wife.C

This will set a wife with Person Class. She will not have any children.
**************************************/
#include "assig4Wife.h"
using namespace std;

Wife::Wife():Person()
{
  nextChild = NULL;
}

Wife::Wife(long i, string f, string l):Person(i, f, l)
{
  nextChild = NULL;
}
