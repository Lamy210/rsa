#include<stdio.h>
#include "vlint_lib.hpp"

int main()
{
  VLInt result = 1;

  result = gcd(135632,44461);

  lprint(result);

  result = gcd(66584449, 46661543);

  lprint(result);

}
