#include "common.h"

extern void func_00121760();
extern void func_004C78E8();
extern char D_001DB290[];
extern char D_001DB2D0[];
extern char D_001DB300[];
extern s32 D_001D67D4;
void func_004C99D0(s32 *arg0)
{
  s32 *p;
  s32 n;
  s32 *new_var;
  new_var = arg0 + 7;
  func_00121760(D_001DB290);
  p = new_var;
  n = arg0[6];
  func_00121760(D_001DB2D0, p, n);
  if (n > 0)
  {
    do
    {
      p[1] += (s32) arg0;
      func_004C78E8(p[1]);
      p += 2;
      D_001D67D4 = D_001D67D4 + 1;
      n--;
    }
    while (n != 0);
  }
  func_00121760(D_001DB300);
}
