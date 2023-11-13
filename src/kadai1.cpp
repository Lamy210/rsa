#include<stdio.h>
#include "vlint_lib.hpp"

int main()
{
  VLInt result = 1;

  int i;

  for (i = 46; i > 0; i--) {
	  result = result * i;
	}
  result = result - 1;



  lprint(result);

}
