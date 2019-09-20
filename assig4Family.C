/***************************************
assig4Family.C

This will set a family by open a transaction file. It can add or remove a person, and it can pprint a or all families..
**************************************/
#include "assig4Family.h"
#include <iostream>
#include <fstream>
using namespace std;

Family::Family()
{
  top = NULL;
}

//This function will add a husband if it does not exist
void Family::AddHusband(long SSN, string Fname, string Lname)
{
  if(search(SSN) == true)
    {
      cout << "Husband with " << SSN << " id already exist" << endl;
      cout << "********************************************" << endl;
      return;
    }
  nextFamily p = new Husband(SSN, Fname, Lname);
  p -> family = top;
  top = p;
}

//This function will search for a family, and it will return true if it exist, otherwise false
bool Family::search(long s)
{
  nextFamily p = top;
  while(p != NULL)
    {
      if(p -> SSN == s)
        return true;
      p = p -> family;
    }
  return false;
}

//This function will add a wife to a husband if the husband exist and does not have a wife
void Family::AddWife(long SSN, string Fname, string Lname, long husbandSSN)
{
  if(search(husbandSSN) == false)
    {
      cout << "Husband with " << husbandSSN << " id does not exist" << endl;
      cout << "********************************************" << endl;
      return;
    }
  nextFamily p = top;
  while(p != NULL)
    {
      if(p -> SSN == husbandSSN)
	{
	  if(p -> wife != NULL)
	    {
	      cout << "This husband has another wife already" << endl;
	      cout << "********************************************" << endl;
	      return;
	    }
	  p -> wife = new Wife(SSN, Fname, Lname);
	}
      p = p -> family;
    }
}

//This function will add a child to a wife if she and her husband exist and do not have a child
void Family::AddAChild(long SSN, string Fname, string Lname, long fatherSSN)
{
  if(search(fatherSSN) == false)
    {
      cout << "Husband with " << fatherSSN << " id does not exist" << endl;
      cout << "********************************************" << endl;
      return;
    }
  nextFamily p = top;
  while(p != NULL)
    {
      if(p -> SSN == fatherSSN)
	{
	  if(p -> wife == NULL)
	    {
	      cout << "This father does not have a wife" << endl;
	      cout << "********************************************" << endl;
	      return;
	    }
	  else
	    {
	      myWife q = p -> wife;
	      if(q -> nextChild == NULL)
		{
		  q -> nextChild = new Child(SSN, Fname, Lname);
		  return;
		}
	      else
		{
		  myChildren c = new Child(SSN, Fname, Lname);
		  c -> nextSibling = q -> nextChild;
		  q -> nextChild = c;
		}
	    }
	}
      p = p -> family;
    }
}

//This function will remove a family if exist
void Family::RemoveHusband(long SSN)
{
  if(search(SSN) == false)
    {
      cout << "Husband with " << SSN << " id does not exist" << endl;
      cout << "********************************************" << endl;
      return;
    }
  nextFamily p = top;
  nextFamily f = top;
  while(p != NULL)
    {
      if(top -> SSN == SSN)
	{
	  if(p -> wife == NULL)
            {
	      top = p -> family;
	      delete p;
              return;
            }
	  else
	    {
	      RemoveWife(SSN);
	      top = p -> family;
              delete p;
              return;
	    }
	}
      p = p -> family;
      if(p -> SSN == SSN)
	{
	  if(p -> wife == NULL)
	    {
	      f -> family = p -> family;
	      delete p;
	      return;
	    }
	  else
	    {
	      RemoveWife(SSN);
	      f -> family = p -> family;
              delete p;
              return;
	    }
	}
      f = p;
    }
}

//This function will remove a wife and her children
void Family::RemoveWife(long husbandSSN)
{
  if(search(husbandSSN) == false)
    {
      cout << "Husband with " << husbandSSN << " id does not exist" << endl;
      cout << "********************************************" << endl;
      return;
    }
  nextFamily p = top;
  while(p != NULL)
    {
      if(p -> SSN == husbandSSN)
	{
	  if(p -> wife == NULL)
	    {
	      cout << "This father does not have a wife" << endl;
	      cout << "********************************************" << endl;
	      return;
	    }
	  else
	    {
	      myWife q = p -> wife;
	       if(q -> nextChild != NULL)
	         {
		   myChildren c = q -> nextChild;
		   while(c != NULL)
		     {
		       long childID = c -> SSN;
		       c = c -> nextSibling;
		       RemoveAChild(husbandSSN, childID);
		     }
	         }
	       delete q;
	    }
	}
      p = p -> family;
    }
}

//This function will remove a child
void Family::RemoveAChild(long FatherSSN, long childSSN)
{
  if(search(FatherSSN) == false)
    {
      cout << "Father with " << FatherSSN << " id does not exist" << endl;
      cout << "********************************************" << endl;
      return;
    }
  nextFamily p = top;
  while(p != NULL)
    {
      if(p -> SSN == FatherSSN)
	{
	  if(p -> wife == NULL)
            {
              cout << "This father does not have a wife" << endl;
              cout << "********************************************" << endl;
              return;
            }
	  else
	    {
	      myWife q = p -> wife;
	      if(q -> nextChild == NULL)
		{
		  cout << "This mother does not have children" << endl;
                  cout << "********************************************" << endl;
                  return;
		}
	      else
		{
		  myChildren c = q -> nextChild;
		  if(c -> SSN == childSSN)
		    {
		      q -> nextChild = c -> nextSibling;
		      delete c;
		      return;
		    }
		  myChildren d = c;
		  while(c != NULL)
		    {		  
		      if(c -> SSN == childSSN)
			{
			  d -> nextSibling = c -> nextSibling;
			  delete c;
			  return;
			}
		      d = c;
                      c = c -> nextSibling;
		    }
		}
	    }
	}
      p = p -> family;
    }
}

//This function will print a family if it exist
void Family::PrintAFamily(long fatherSSN)
{
  if(search(fatherSSN) == false)
    {
      cout << "Family with " << fatherSSN << " id does not exist" << endl;
      cout << "********************************************" << endl;
      return;
    }
  nextFamily p = top;
  while(p != NULL)
    {
      if(p -> SSN == fatherSSN)
	{
	  cout << p -> Fname << " ";
	  cout << p -> Lname << endl;
	  if(p -> wife == NULL)
            {
              cout << "This father does not have a wife" << endl;
            }
	  else
	    {
	      myWife q = p -> wife;
	      cout << q -> Fname << " ";
	      cout << q -> Lname << endl;
	      if(q -> nextChild == NULL)
		{
		  cout << "This mother does not have children" << endl;
		}
	      else
		{
		  myChildren c = q -> nextChild;
		  cout << c -> Fname << " ";
		  cout << c -> Lname << endl;
		  while(c -> nextSibling != NULL)
		    {
		      c = c  -> nextSibling;
		      cout << c -> Fname << " ";
		      cout << c -> Lname << endl;
		    }
		}
	    }
	}
      p = p -> family;
    }
  cout << "********************************************" << endl;
}

//This function will print all families
void Family::PrintAllFamilies()
{
  nextFamily p = top;
  while(p != NULL)
    {
          cout << p -> Fname << " ";
          cout << p -> Lname << endl;
          if(p -> wife == NULL)
            {
              cout << "This father does not have a wife" << endl;
            }
          else
            {
              myWife q = p -> wife;
              cout << q -> Fname << " ";
              cout << q -> Lname << endl;
              if(q -> nextChild == NULL)
                {
                  cout << "This mother does not have children" << endl;
                }
              else
                {
                  myChildren c = q -> nextChild;
                  cout << c -> Fname << " ";
                  cout << c -> Lname << endl;
                  while(c -> nextSibling != NULL)
                    {
                      c = c  -> nextSibling;
                      cout << c -> Fname << " ";
                      cout << c -> Lname << endl;
                    }
                }
            }
      p = p -> family;
      cout << "********************************************" << endl;
    }
}

//This function will open a file and call other functions to do something if the file exist
void Family::ReadTransactionFile()
{
  ifstream fin;
  string name;
  string word;
  long SSN;
  long ssn;
  string fname;
  string lname;

  cout << "Enter data File: ";
  cin >> name;

  fin.open(name.data());

  if(!fin)
    {
      cout << name << " file does not exist" << endl;
      return;
    }
  else
    {
      fin >> word;

      while(fin)
	{

	  if(word == "AddHusband")
	    {
	      fin >> SSN;
	      fin >> fname;
	      fin >> lname;
	      AddHusband(SSN, fname, lname);
	    }
	  else if(word == "RemoveHusband")
	    {
	      fin >> SSN;
	      RemoveHusband(SSN);
	    }
	  else if(word == "AddWife")
	    {
	      fin >> SSN;
	      fin >> fname;
	      fin >> lname;
	      fin >> ssn;
	      AddWife(SSN, fname, lname, ssn);
	    }
	  else if(word == "RemoveWife")
	    {
	      fin >> SSN;
	      RemoveWife(SSN);
	    }
	  else if(word == "AddAchild")
	    {
	      fin >> SSN;
	      fin >> fname;
	      fin >> lname;
	      fin >> ssn;
	      AddAChild(SSN, fname, lname, ssn);
	    }
	  else if(word == "RemoveAchild")
	    {
	      fin >> SSN;
	      fin >> ssn;
	      RemoveAChild(SSN, ssn);
	      }
	  else if(word == "PrintAFamily")
	    {
	      fin >> SSN;
	      PrintAFamily(SSN);
	    }
	  else if(word == "PrintAllFamilies")
	    {
	      PrintAllFamilies();
	    }
	  fin >> word;
	}
    }
}
