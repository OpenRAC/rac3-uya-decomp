#include "common.h"

extern s32 D_001D841C;
extern s32 D_001D8434;

extern s32 D_001D841C;
extern s32 D_001D8434;
extern u8 D_001D8439;
extern s32 D_001D545C[];
extern u8 D_001D5571[];
extern void func_00432680(s32);
extern void func_004300F0(s16);
void func_0047D448(void)
{
  unsigned long new_var;
  u8 v;
  new_var = 0;
  func_00432680(D_001D841C);
  v = new_var;
  if (D_001D545C[new_var] < 2)
  {
    new_var = D_001D5571[0] == new_var;
    v = new_var;
  }
  D_001D8439 = v;
  ((void (*)(s32)) func_004300F0)(D_001D8434);
}
