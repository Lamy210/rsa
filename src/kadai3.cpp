#include<stdio.h>
#include "vlint_lib.hpp"

int main()
{
  int i;
  VLInt result = 1;

  for (i =2; i <51;i++) {
	  result = lcm(result,i);
  }
  lprint(result);

}
