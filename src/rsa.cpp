#include<stdio.h>
#include "vlint_lib.hpp"

int main()
{
  VLInt p, q, n, e, l, d, m, c;

  m = 300; // 学籍番号をセット
  e = 65537;
  lprint(m);

  //素数 p, q の生成

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

  //公開鍵 n の導出(未完成)

  n = p * q;

  printf("N=");
  lprint(n);


  //Lの導出(未完成)

  l= (p - 1) * (q - 1);

  printf("L=");
  lprint(l);

  VLInt result = gcd(l, e);
  printf("gcd(l,e)=");
  lprint(result); /*L,eが互いに素かチェック*/

  
  //秘密鍵の導出(未完成)

  d=inverse_num(e, l);

  printf("d=");
  lprint(d);

  result = (d * e)%l;
  printf("d*e mod L=");
  lprint(result); /*dが秘密鍵として正しいかチェック*/
  
  //符号化処理(未完成)

  c= mod_exp(m, e, n);

  printf("c=");
  lprint(c);

  //復号処理(未完成)


  m= mod_exp(c, d, n);
  
  printf("m'=");
  lprint(m);

}
