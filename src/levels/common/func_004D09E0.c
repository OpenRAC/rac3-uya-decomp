#include "common.h"

/* localdecomp:start func_004D09E0 */
typedef struct { s32 f0; s32 f4; s32 f8; u8 pC[0xC]; s32 f18; u8 p1C[0x24]; s32 f40; u8 p44[4]; long f48; s32 f50; s32 f54; } O_3AC0D8;
typedef struct { s32 w0; s32 w4; s32 w8; s32 pad[5]; } St_3AC0D8;
extern s32 func_0011EE20();
extern s32 func_004D0A58();
s32 func_004D09E0(O_3AC0D8 *o, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{  St_3AC0D8 *new_var;
  St_3AC0D8 st;
  o->f0 = a1;
  o->f8 = a3;
  o->f50 = a4;
  o->f54 = a5;
  st.w8 = 1;
  o->f4 = (a2 & 0xFFFFFFF) | 0x20000000;
  st.w4 = 1;
  new_var = &st;
  o->f18 = a3 << 11;
  o->f40 = func_0011EE20(new_var);
  ((s32 (*)(void *))func_004D0A58)(o);
  o->f48 = 0;
  return 1;
}
/* localdecomp:end func_004D09E0 */
