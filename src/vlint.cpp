#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "vlint.hpp"


VLInt::VLInt(): sign(0), len(MAX_DIGIT_NUM){}

VLInt::VLInt(int i){ *this = i; }

// 10進数として標準出力
void VLInt::lprint(VLInt a)
{
  int i;
  VLInt base, base10, digit;

  if (a.sign){
    fprintf(stdout, "-");
    a.sign = 0;
  }

  base = 1;
  i = 0;
  while (1){
    base10 = base * 10;
    if (a < base10)
      break;
    base = base10;
    i++;
  }

  while (1){
    digit = a / base;
    printf("%d", digit.num[0]);
    if (i == 0)
      break;
    a = a - (digit * base);
    base /= 10;
    i--;
  }
  printf("\n");

}

void VLInt::lprint2(VLInt a)
{
  printf("%d\n", (a.num[1]<<16)|a.num[0]);

}

// 絶対値の加算
void VLInt::abs_add(unsigned short ans[], unsigned short a[], unsigned short b[], int len)
{
  int i, result, carry = 0;

  for (i = 0; i < len; i++){
    if ((result = ((int)a[i] + (int)b[i] + carry)) >= BASE_VALUE){
      result -= BASE_VALUE;
      carry = 1;
    }
    else{
      carry = 0;
    }
    ans[i] = (unsigned short)result;
  }
}

// 絶対値の減算(必ず大きい数から小さい数を引くこと)
void VLInt::abs_sub(unsigned short ans[], unsigned short a[], unsigned short b[], int len)
{
  int i, result, borrow = 0;

  for (i = 0; i < len; i++){
    if ((result = ((int)a[i] - (int)b[i] - borrow)) < 0){
      result += BASE_VALUE;
      borrow = 1;
    }
    else{
      borrow = 0;
    }
    ans[i] = (unsigned short)result;
  }
}

// 絶対値の比較(-1:a<b, 0:a=b, +1:a>b)
int VLInt::abs_cmp(unsigned short a[], unsigned short b[], int len)
{
  while (--len >= 0){
    if (a[len] != b[len]){
      return (a[len] < b[len]) ? -1 : +1; // 大小値
    }
  }
  return 0; // 一致
}


// 比較(符号対応)(-1:a<b, 0:a=b, +1:a>b)
int VLInt::cmp(VLInt a, VLInt b)
{
  if (a.sign == b.sign){ // 符号が同じ
    return (1 - 2 * a.sign)*abs_cmp(a.num, b.num, a.len);
  }
  else if (a.sign){
    return -1;
  }
  else {
    return 1;
  }
}

// 多倍長整数の加算(符号対応)
VLInt VLInt::add(VLInt a, VLInt b)
{
  VLInt ans;

  ans = 0;

  if (a.sign == b.sign){ // 符号が同じ
    abs_add(ans.num, a.num, b.num, ans.len);
    ans.sign = a.sign;
  }
  else if (abs_cmp(a.num, b.num, ans.len) > 0){ // a が大きい
    abs_sub(ans.num, a.num, b.num, ans.len);
    ans.sign = a.sign;
  }
  else{ // b が大きい
    abs_sub(ans.num, b.num, a.num, ans.len);
    ans.sign = b.sign;
  }
  return ans;
}

// 多倍長整数の減算(符号対応)
VLInt VLInt::sub(VLInt a, VLInt b)
{
  VLInt ans;

  ans = 0;

  if (a.sign != b.sign){ // 符号が異なる
    abs_add(ans.num, a.num, b.num, ans.len);
    ans.sign = a.sign;
  }
  else if (abs_cmp(a.num, b.num, ans.len) >= 0){ // a が大きい
    abs_sub(ans.num, a.num, b.num, ans.len);
    ans.sign = a.sign;
  }
  else{ // b が大きい
    abs_sub(ans.num, b.num, a.num, ans.len);
    ans.sign = (b.sign) ? 0 : 1;
  }
  return ans;
}

// 多倍長整数の乗算
VLInt VLInt::mult(VLInt a, VLInt b)
{
  VLInt ans;
  int i, j, result, c0, c1;
  unsigned int la, lb, lc;

  ans = 0;

  for (i = 0; i<a.len; i++){
    c0 = 0;
    c1 = 0;
    for (j = 0; j<a.len; j++){
      la = a.num[i];
      lb = b.num[j];
      lc = la * lb;
      if ((i + j) >= a.len){
        if (lc != 0)
          fprintf(stderr, "over flow have happned\n");
      }
      else {
        result = (int)ans.num[i + j] + (lc % BASE_VALUE);
        if (result > BASE_VALUE){
          result -= BASE_VALUE;
          c0 = 1;
        }
        ans.num[i + j] = (unsigned short)result;
        result = (int)ans.num[i + j + 1] + c0 + c1 + (lc / BASE_VALUE);
        c0 = c1 = 0;
        if (result > BASE_VALUE){
          result -= BASE_VALUE;
          c1 = 1;
        }
        ans.num[i + j + 1] = (unsigned short)result;
      }
    }
    ans.sign = (a.sign == b.sign) ? 0 : 1;
  }
  return ans;
}

// 多倍長整数の除算（負の数は非対応）
VLInt VLInt::l_div(VLInt a, VLInt b)
{
  VLInt org_b, next_b, result;
  int i, j, k;
  VLInt base, base16, tmp;

  result = 0;

  org_b = b;

  for (i = 0;; i++){
    b = org_b;
    base = 1;
    for (j = 0;; j++){
      next_b = b * 16;
      base16 = base * 16;
//      next_b = b << 4; // シフト演算中で除算しているためシフトは使用禁止
      if (abs_cmp(a.num, next_b.num, a.len) == -1)
        break;
      b = next_b;
      base = base16;
    }
    for (k = 0; k<16; k++){
      a = a - b;
      if (a.sign)
        break;
    }
    result += base * k;
    a = a + b;
    if (abs_cmp(b.num, org_b.num, b.len) == 0)
      break;
  }

  return result;
}

// 多倍長整数の剰余
VLInt VLInt::mod(VLInt a, VLInt b)
{
  VLInt org_b, prev_b;
  int i, j;

  org_b = b;

  for (i = 0;; i++){
    b = org_b;
    prev_b = b;
    for (j = 0;; j++){
      if (abs_cmp(a.num, b.num, a.len) == -1)
        break;
      prev_b = b;
      b = b * 10;
    }
    for (j = 0; j<10; j++){
      a = sub(a, prev_b);
      if (a.sign)
        break;
    }
    a = add(a, prev_b);
    if (abs_cmp(prev_b.num, org_b.num, b.len) == 0)
      break;
  }

  return a;
}

// AND 演算
VLInt VLInt::and(VLInt a, VLInt b)
{
  VLInt ans;
  for (int i = 0; i < len; i++){
    ans.num[i] = a.num[i] & b.num[i];
  }
  ans.len = len;
  return ans;
}

// OR 演算
VLInt VLInt::or(VLInt a, VLInt b)
{
  VLInt ans;
  for (int i = 0; i < len; i++){
    ans.num[i] = a.num[i] | b.num[i];
  }
  ans.len = len;
  return ans;
}

// 算術左シフト 演算
VLInt VLInt::la_sft(VLInt a, VLInt b)
{
  VLInt tmp, result;
  int b1, b2;
  int i;
  int resi, presi;
  int mask;

  result = a;
  tmp = b / BASE_LEN;
  b1 = tmp.num[0];
  tmp = b % BASE_LEN;
  b2 = tmp.num[0];
  mask = (1 << BASE_LEN) - 1;

//  fprintf(stderr, "%d %d\n", b1, b2);

  for (i = 0; i < a.len; i++){
    if ((i - b1) >= 0){
      result.num[i] = a.num[i - b1];
    }
    else {
      result.num[i] = 0;
    }
  }
  presi = 0;
  for (i = 0; i < a.len; i++){
    resi = result.num[i] >> (BASE_LEN - b2);
    result.num[i] = ((result.num[i] << b2)&mask) | presi;
    presi = resi;
  }

  return result;
}

// 算術右シフト 演算
VLInt VLInt::ra_sft(VLInt a, VLInt b)
{
  VLInt tmp, result;
  int b1, b2;
  int i;
  int resi, presi;
  int mask;

  result = a;
  tmp = b / BASE_LEN;
  b1 = tmp.num[0];
  tmp = b % BASE_LEN;
  b2 = tmp.num[0];
  mask = (1 << BASE_LEN) - 1;

  for (i = 0; i < a.len; i++){
    if ((i + b1) < a.len){
      result.num[i] = a.num[i + b1];
    } else {
      result.num[i] = 0;
    }
  }
  presi = 0;
  for (i = a.len-1; i >= 0; i--){
    resi = (result.num[i] << (BASE_LEN - b2)) & mask;
    result.num[i] = presi | (result.num[i] >> b2);
    presi = resi;
  }

  return result;
}


// EXOR 演算
VLInt VLInt::exor(VLInt a, VLInt b)
{
	VLInt result;
	int i;

	result = a;

	for (i = 0; i < a.len; i++) {
		result.num[i] = a.num[i] ^ b.num[i];
	}

	return result;
}

// 疑似乱数発生
VLInt VLInt::lrand(int len)
{
  int i;
  VLInt result;
  static int prev_time = 0;

  result = 0;

  if (prev_time != time(NULL)){
    srand((unsigned)(prev_time = (int)time(NULL)));
  }

  while (1){
    result.num[0] = rand() % BASE_VALUE;
    if (result.num[0] != 0)
      break;
  }
  for (i = 1; i<len; i++){
    result.num[i] = rand() % BASE_VALUE;
  }

  return result;
}

// 10進数として標準出力
void lprint(VLInt a)
{
  a.lprint(a);
}

// 疑似乱数発生
VLInt lrand(int len)
{
  VLInt a;
  return a.lrand(len);
}
