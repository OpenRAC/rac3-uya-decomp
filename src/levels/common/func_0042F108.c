#include "common.h"

/* localdecomp:start func_0042F108 */
typedef struct { 
    u8 pad[0x10]; 
    s32 f10; 
    u8 pad2[0x150]; 
    s32 f164; 
    s32 f168; 
    u8 pad3[0x10]; 
    s32 f17C; 
} S_142430x;

extern S_142430x D_00142430;
extern s32 D_001D4CE8_g;

void func_0042F108(void) {
    S_142430x *p = &D_00142430;
    D_001D4CE8_g = 4;
    p->f17C = 0;
    p->f10 = 0;
}
/* localdecomp:end func_0042F108 */
