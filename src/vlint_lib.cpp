#include "vlint_lib.hpp"

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
  VLInt s;
  int j;

  s = a;
  for (j = 1; (VLInt)j < n;j++) {
	  lprint(j);
	  s = (s * a) % m;
  }


  return s;
}


// �t�F���}�[�̏��藝�ɂ��f������(�����炭�f���Ȃ�1, �f���łȂ����0)
int fermat(VLInt r, int num)
{
  VLInt rm1;
  int i, j, result = 1;

  rm1 = r - 1;


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
