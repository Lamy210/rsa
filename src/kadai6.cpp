#include<stdio.h>
#include "vlint_lib.hpp"

int main()
{
  VLInt e, l, d;

  e = 79;
  l = 176;

  d = inverse_num(e, l);

  lprint(d);

}
