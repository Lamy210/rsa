#include <cstdlib>

#define MAX_DIGIT_NUM 64

#define BASE_LEN   (16L)
#define BASE_VALUE (65536L) //2^BASE_LEN

class VLInt
{

private:
  int sign;
  int len;
  unsigned short num[MAX_DIGIT_NUM + 1];
  int abs_cmp(unsigned short a[], unsigned short b[], int len);
  void abs_add(unsigned short ans[], unsigned short a[], unsigned short b[], int len);
  void abs_sub(unsigned short ans[], unsigned short a[], unsigned short b[], int len);

public:
  VLInt();
  VLInt(int i);
  void lprint(VLInt a);
  void lprint2(VLInt a);
  int cmp(VLInt a, VLInt b);
  VLInt add(VLInt a, VLInt b);
  VLInt sub(VLInt a, VLInt b);
  VLInt mult(VLInt a, VLInt b);
  VLInt l_div(VLInt a, VLInt b);
  VLInt mod(VLInt a, VLInt b);
  VLInt and(VLInt a, VLInt b);
  VLInt or(VLInt a, VLInt b);
  VLInt exor(VLInt a, VLInt b);
  VLInt la_sft(VLInt a, VLInt b);
  VLInt ra_sft(VLInt a, VLInt b);
  VLInt lrand(int len);

  VLInt operator = (const int& a) {
    this->sign = (a < 0) ? 1 : 0;
    this->len = MAX_DIGIT_NUM;
    this->num[0] = (unsigned short)(abs(a) % BASE_VALUE);
    this->num[1] = (unsigned short)(abs(a) / BASE_VALUE);
    for (int i = 2; i <= this->len; i++)
      this->num[i] = 0;
    return *this;
  }
  VLInt operator = (const VLInt& a) {
    this->sign = a.sign;
    this->len = a.len;
    for (int i = 0; i <= a.len; i++)
      this->num[i] = a.num[i];
    return *this;
  }

  VLInt operator +  (const VLInt& a) { return add(*this, a); }
  VLInt operator -  (const VLInt& a) { return sub(*this, a); }
  VLInt operator *  (const VLInt& a) { return mult(*this, a); }
  VLInt operator /  (const VLInt& a) { return l_div(*this, a); }
  bool  operator == (const VLInt& a) { return (cmp(*this, a) == 0) ? true : false; }
  bool  operator != (const VLInt& a) { return (cmp(*this, a) != 0) ? true : false; }
  bool  operator <  (const VLInt& a) { return (cmp(*this, a) == -1) ? true : false; }
  bool  operator >  (const VLInt& a) { return (cmp(*this, a) == 1)  ? true : false; }
  bool  operator <= (const VLInt& a) { return (cmp(*this, a) != 1)  ? true : false; }
  bool  operator >= (const VLInt& a) { return (cmp(*this, a) != -1) ? true : false; }
  VLInt operator %  (const VLInt& a) { return mod(*this, a); }
  VLInt operator += (const VLInt& a) { *this = *this + a;  return *this; }
  VLInt operator -= (const VLInt& a) { *this = *this - a;  return *this; }
  VLInt operator *= (const VLInt& a) { *this = *this * a;  return *this; }
  VLInt operator /= (const VLInt& a) { *this = *this / a;  return *this; }
  VLInt operator ++()                { return *this+=1; }
  VLInt operator --()                { return *this-=1; }
//        operator int()         const { return (this->sign*2-1)*(int)this->num[0]; }
  VLInt operator >> (const VLInt& a) { return ra_sft(*this, a); }
  VLInt operator << (const VLInt& a) { return la_sft(*this, a); }
  VLInt operator >>= (const VLInt& a) { *this = *this >> a;  return *this; }
  VLInt operator <<= (const VLInt& a) { *this = *this << a;  return *this; }
  VLInt operator &   (const VLInt& a) { return and(*this, a); }
  VLInt operator |   (const VLInt& a) { return or(*this, a); }
  VLInt operator ^   (const VLInt& a) { return exor(*this, a); }
  VLInt operator &=   (const VLInt& a) { *this = *this & a; return *this; }
  VLInt operator |=   (const VLInt& a) { *this = *this | a; return *this; }
  bool operator &&  (const VLInt& a) { return (and(*this, a) == 0)? false : true; }
  bool operator ||  (const VLInt& a) { return (or(*this, a) == 0) ? false : true; }

};

void lprint(VLInt a);
VLInt lrand(int len);
