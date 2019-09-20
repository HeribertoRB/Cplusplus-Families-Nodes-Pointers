/********************************************************
Heriberto Bernal
ASSIGNMENT 4
berna052@cougars.csusm.edu
12/10/15
Professor A. Hadaegh

This program will open a transaction file and will create families. Each family can have a husband, a wife, and several children. Then, the program will print out families several times. 
 *******************************************************/

#include "assig4Family.h"
using namespace std;

int main()
{
  Family USAFamilies;
  USAFamilies.ReadTransactionFile();
  return 0;
}
