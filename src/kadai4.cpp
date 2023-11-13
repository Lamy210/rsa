#include<stdio.h>
#include "vlint_lib.hpp"

int main()
{
  VLInt a, n, m, result;

  /*a = 81;
  n = 45;
  m = 221;

  result = mod_exp(a, n, m);

  lprint(result);

  */
  a = 987654321;
  n = 123456789;
  m = 97531;

  result = mod_exp(a, n, m);

  lprint(result);

}
