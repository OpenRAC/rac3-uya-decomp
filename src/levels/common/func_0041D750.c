#include "common.h"

/* localdecomp:start func_0041D750 */
extern void func_0041D750(void);
extern s32 D_001D6694;

typedef struct { u8 p0[0x18]; void (*f18)(void *); u8 p1c[0x74]; } S_391FD8;
extern S_391FD8 D_002E6110_00391FD8[];
extern s32 D_001DFDB8;
extern s32 D_001DF9DC;
extern s32 D_001DFD8C;
extern s32 D_001DFCB8;
extern s32 D_001DFCBC;
extern s32 D_001DFCC0;
extern s32 D_001D6694;
void func_0041D750(void) {
    S_391FD8 *p;
    s32 i;
    if (D_001DFDB8 || D_001DF9DC) {
        *(volatile s32 *)&D_001DFDB8 = 0;
        return;
    }
    D_001DFD8C = 0xFFFFF0;
    p = D_002E6110_00391FD8;
    for (i = 12; i >= 0; i--) {
        if (p->f18) p->f18(p);
        p++;
    }
    if (D_001DFCB8 || D_001DFCBC) {
        if (D_001D6694 == 0) {
            if (D_001DFCB8) {
                D_001DFCBC += 0x10;
                if (D_001DFCBC > 0x80) D_001DFCBC = 0x80;
            } else {
                D_001DFCBC -= 0x10;
                if (D_001DFCBC < 0) D_001DFCBC = 0;
            }
            if (D_001DFCB8) D_001DFCB8--;
            if (D_001DFCB8 == 1000) D_001DFCB8 = 0;
            return;
        }
    }
    D_001DFCC0 = 100;
}
/* localdecomp:end func_0041D750 */
