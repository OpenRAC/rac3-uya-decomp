#include "common.h"

/* localdecomp:start func_004D30D0 */
extern void func_00436220(s32 p);
typedef struct { u8 p0[0x44]; s16 n; u8 p1[0x15A]; void *slot[1]; } S_B7288;
typedef struct { u8 p0[0xC]; u8 c; u8 p1[0x3B]; s32 q[1]; } I_B7288;
typedef struct { u8 p0[0x24]; I_B7288 *in; } O_B7288;
extern S_B7288 D_001E6E00;
void func_004D30D0(void) {
    s32 i;
    for (i = 0; i < D_001E6E00.n; i++) {
        O_B7288 *o = D_001E6E00.slot[i];
        if (o != 0) {
            o->in->c--;
            *(s32 *)((u8 *)o->in + (o->in->c << 2) + 0x48) = 0;
            func_00436220((s32)o);
            D_001E6E00.slot[i] = 0;
        }
    }
}
/* localdecomp:end func_004D30D0 */
