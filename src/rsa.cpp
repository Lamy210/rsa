#include<stdio.h>
#include "vlint_lib.hpp"

int main()
{
  VLInt p, q, n, e, l, d, m, c;

  m = 300; // �w�Дԍ����Z�b�g
  e = 65537;
  lprint(m);

  //�f�� p, q �̐���

  while (1){
    p = lrand(4);
    if (fermat(p, 2) == 1)
      break;
  }
  while (1){
    q = lrand(4);
    if (fermat(q, 2) == 1)
      break;
  }

  lprint(p);
  lprint(q);

  //���J�� n �̓��o(������)

  n = p * q;

  printf("N=");
  lprint(n);


  //L�̓��o(������)

  l= (p - 1) * (q - 1);

  printf("L=");
  lprint(l);

  VLInt result = gcd(l, e);
  printf("gcd(l,e)=");
  lprint(result); /*L,e���݂��ɑf���`�F�b�N*/

  
  //�閧���̓��o(������)

  d=inverse_num(e, l);

  printf("d=");
  lprint(d);

  result = (d * e)%l;
  printf("d*e mod L=");
  lprint(result); /*d���閧���Ƃ��Đ��������`�F�b�N*/
  
  //����������(������)

  c= mod_exp(m, e, n);

  printf("c=");
  lprint(c);

  //��������(������)


  m= mod_exp(c, d, n);
  
  printf("m'=");
  lprint(m);

}
