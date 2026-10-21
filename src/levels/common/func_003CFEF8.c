#include "common.h"

/* localdecomp:start func_003CFEF8 */
typedef struct {
    s32 a;
    s32 b;
    float f8;
    float fC;
    u8 pad[0x20];
    float f30;
    u8 pad2[0x20];
    float f54;
    u8 pad3[0xE8];
    u8 x140[1];
} S_003CFEF8;
extern u8 *D_001E0180;
extern u8 D_001A4C60[];
extern float func_004434F8(void *, void *, void *, void *);
void func_003CFEF8(void *unused, S_003CFEF8 *p) {
    float t = func_004434F8(p->x140, D_001E0180 + p->a * 128 + 0x30, D_001E0180 + p->b * 128 + 0x30, D_001A4C60);
    p->f30 = t;
    p->f54 = p->f8 + (p->fC - p->f8) * t;
}
/* localdecomp:end func_003CFEF8 */
