#include<stdio.h>
#include "vlint_lib.hpp"

int main()
{
  VLInt r;
  
  r = 31;
  if(fermat(r, 2)){
    lprint(r);
    fprintf(stdout,"�͂��Ԃ�f��\n");
  } else {
    lprint(r);
    fprintf(stdout,"�͍�����\n");
  }

  /* �f���ɂȂ�܂ŌJ��Ԃ��ꍇ�̃R�[�h��
  while(1){
    r = lrand(4);
    if(fermat(r, 2))
      break;
  }
  lprint(r);
  */

}
