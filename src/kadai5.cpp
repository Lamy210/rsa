#include<stdio.h>
#include "vlint_lib.hpp"

int main()
{
  VLInt r;
  


  r = 31;
  if(fermat(r, 2)){
    lprint(r);
    fprintf(stdout,"はたぶん素数\n");
  } else {
    lprint(r);
    fprintf(stdout,"は合成数\n");
  }

  /* 素数になるまで繰り返す場合のコード例
  while(1){
    r = lrand(4);
    if(fermat(r, 2))
      break;
  }
  lprint(r);
  */

}
