#include "common.h"

/* localdecomp:start func_00510B50 */
typedef struct { u8 pad[0x10]; s32 a[16]; } S_3E06A0;
void func_00510B50(S_3E06A0 **p) {
    s32 i;
    for (i = 0; i < 16; i++) (*p)->a[i] = 0;
}
/* localdecomp:end func_00510B50 */
