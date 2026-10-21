#include "common.h"

/* localdecomp:start func_00436410 */
typedef struct { u8 p0[0x24]; void *f24; u8 p28[0xC]; u16 h34; u8 p36[0x36]; u8 b6C; u8 b6D; u8 p6E[0xE]; u16 h7C; } S_3BD550;
extern u8 D_001A30B0[];
extern void func_004A6E88(u32);
extern s32 func_004A7200();
void func_00436410(S_3BD550 *p) {
    u8 *e;
    if (p->b6D != 0xFF) {
        e = D_001A30B0 + p->b6D * 128;
        if (*(S_3BD550 **)(e + 0xDC) != p) {
            p->b6D = 0xFF;
            return;
        }
        if (*(s16 *)(e + 0xCA) != p->b6C || (p->h34 & 0x40) || (p->h7C & 0x8000)) {
            func_004A6E88(p->b6D);
            p->b6D = 0xFF;
        }
    } else {
        if (p->b6C == 0xFF) return;
        if (p->h34 & 0x40) return;
        if (*(unsigned long *)((u8 *)p + 0x78) & 0x4800000000000UL) return;
        p->b6D = func_004A7200(p->b6C, 4, p);
    }
}
/* localdecomp:end func_00436410 */
