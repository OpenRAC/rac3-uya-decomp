#include "common.h"

/* localdecomp:start func_00479738 */
extern s32 func_00457288(s32, s32, s32, s32, u8 *);
extern s32 D_001D81F4;
extern void func_004799C0(void);

extern void func_0042FFD8();
extern void func_004795F8();
extern void func_00479628();
extern s32 D_001D81F4;
void func_00479738(void)
{
  s32 (*new_var)();
  s32 *new_var2;
  s32 temp_3;
  temp_3 = D_001D81F4;
  new_var2 = &D_001D81F4;
  switch (*new_var2)
  {
    case 0:
      new_var = &func_004795F8;
      func_0042FFD8(new_var, 0, &func_00479628);

    case 1:
      func_00457288(4, 1, 1, 0, 0);
 do { } while (0);
      temp_3 = *new_var2;
      temp_3 = (s32) (temp_3 + 1);
      D_001D81F4 = temp_3;
      return;

    case 2:
      func_004799C0();
      break;

  }

}
/* localdecomp:end func_00479738 */
