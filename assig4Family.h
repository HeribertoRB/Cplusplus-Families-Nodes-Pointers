/****************************************
aasig4Family.h

A family can have a husband, a wife, and several children. 
****************************************/
#ifndef ASSIG4FAMILY_H
#define ASSIG4FAMILY_H

#include "assig4Husband.h"
#include "assig4Wife.h"
#include "assig4Child.h"
#include "assig4Person.h"
using namespace std;

class Family
{
 protected: 
  nextFamily top;
 public:
  Family();
  bool search(long s);
  void AddHusband(long SSN, string Fname, string Lname);
  void RemoveHusband(long SSN);
  void AddWife(long SSN, string Fname, string Lname, long husbandSSN);
  void RemoveWife(long husbandSSN);
  void AddAChild(long SSN, string Fname, string Lname, long fatherSSN);
  void RemoveAChild(long FatherSSN, long childSSN);
  void PrintAFamily(long fatherSSN);
  void PrintAllFamilies();
  void ReadTransactionFile();
};

#endif
