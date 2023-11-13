#include "vlint_lib.hpp"
#include <cstdlib>      // srand,rand
// �ő����(���[�N���b�h�ݏ��@)
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

// �ŏ����{��
VLInt lcm(VLInt a, VLInt b)
{
  return a*b/gcd(a,b);
}

// �o�C�i���[�E�B���h  
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


// �t�F���}�[�̏��藝�ɂ��f������(�����炭�f���Ȃ�1, �f���łȂ����0)
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

// �g�����[�N���b�h�ɂ��t���v�Z
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
