#include "common.h"

/* localdecomp:start func_00432968 */
extern s32 func_00432810();
extern void func_00432968();

typedef struct { u8 b[8]; } V8_399948;
typedef struct { s32 f0, f4, f8, fC; V8_399948 f10; s32 f18; } E_399948;
typedef struct { u8 p0[0x30]; E_399948 e[4]; } R_399948;
extern R_399948 D_00142430_00399948[];
extern s32 func_00432810();
void func_00432968(u8 *a, s32 i, s32 j) {
    s32 r = func_00432810(a) == 0;
    a += 0x10;
    D_00142430_00399948[i].e[j].f18 = r;
    D_00142430_00399948[i].e[j].f0 = *(s32 *)a;
    a += 0xC;
    D_00142430_00399948[i].e[j].f4 = *(s32 *)a;
    D_00142430_00399948[i].e[j].f8 = a[0x32];
    a += 0x88;
    D_00142430_00399948[i].e[j].fC = *(s32 *)a;
    *(V8_399948 *)((u8 *)D_00142430_00399948 + 0x40 + j * 0x1C + i * 0xA0) = *(V8_399948 *)(a + 0xC);
}
/* localdecomp:end func_00432968 */
