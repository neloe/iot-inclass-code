#include "myfunctions.h"
#include <cstdlib>

int getNumber()
{
  return rand()%100;
}

void getTwoNumbers(int &a, int &b)
{
  a = getNumber();
  b = getNumber();
}