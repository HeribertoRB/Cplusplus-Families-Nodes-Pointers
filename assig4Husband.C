/********************************************
assig4Husband.C

This will set a husband with Person class. It will not have a wife and it will not point to another family.
********************************************/
#include "assig4Husband.h"
using namespace std;

Husband::Husband():Person()
{
  family = NULL;
  wife = NULL;
}

Husband::Husband(long i, string f, string l):Person(i, f, l)
{
  family = NULL;
  wife = NULL;
}
