#include<stdio.h>
#include "vlint_lib.hpp"

int main()
{
  VLInt r;
  
  r = 31;
  if(fermat(r, 2)){
    lprint(r);
    fprintf(stdout,"‚Í‚½‚Ô‚ñ‘f”\n");
  } else {
    lprint(r);
    fprintf(stdout,"‚Í‡¬”\n");
  }

  /* ‘f”‚É‚È‚é‚Ü‚ÅŒJ‚è•Ô‚·ê‡‚ÌƒR[ƒh—á
  while(1){
    r = lrand(4);
    if(fermat(r, 2))
      break;
  }
  lprint(r);
  */

}
