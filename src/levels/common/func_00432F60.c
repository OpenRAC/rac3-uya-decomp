#include "common.h"

/* localdecomp:start func_00432F60 */
extern void func_00432F60();

extern s32 D_001D4B60[];
extern s32 D_001D4B90[];
extern s32 D_001D4BA0[];
extern u8 D_0016C580[];
void func_00432F60(void)
{
  u8 *new_var;
 do { new_var = (u8 *) D_0016C580; D_001D4B60[0] = -1; *((s32 *) (new_var + 0x18)) = -1; D_001D4B90[0] = -1; D_001D4BA0[0] = -1; } while (0);
  *((s32 *) (new_var + 0x30)) = -1;
}
/* localdecomp:end func_00432F60 */
