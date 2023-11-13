#include "vlint_lib.hpp"
#include <cstdlib>      // srand,rand
// 最大公約数(ユークリッド互除法)
VLInt gcd(VLInt a, VLInt b)
{
  VLInt r;


  while (b != 0) {
	  r = a;
	  a = b;
	  b = r % b;
  }

  return a;
}

// 最小公倍数
VLInt lcm(VLInt a, VLInt b)
{
  return a*b/gcd(a,b);
}

// バイナリーウィンド  
VLInt mod_exp(VLInt a, VLInt n, VLInt m)
{
  VLInt s=1;
  while (n>0) {
	  if (n%2==1) {
		  s = (s * a)%m;
	  }
	  n = n / 2;
	  a = (a * a) % m;
	}


  return s;
}


// フェルマーの小定理による素数判定(おそらく素数なら1, 素数でなければ0)
int fermat(VLInt r, int num)
{
  VLInt rm1;
  bool result;

  rm1 = mod_exp(r, ((VLInt)rand() % r+1), num);
  if (rm1==1) {
	  result=true;
  }else {
	  result =false;
  }
  return result;
}

// 拡張ユークリッドによる逆数計算
VLInt inverse_num(VLInt e, VLInt l)
{
  VLInt d0, d1, d2, r0, r1, r2, q;
  int j;

  d0 = 1;
  d1 = 0;
  r0 = e;
  r1 = l;
  j = 0;



  return d0;
}
