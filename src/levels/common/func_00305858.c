#include "common.h"

/* localdecomp:start func_00305858 */
typedef struct {
    u8 b0;
    u8 b1;
    u8 pad[238];
} S_2C5640;

extern u8 D_001425C0[];
extern S_2C5640 D_002C5640[];
extern void func_004C1FE8(s32, unsigned long);
extern void func_00305CA0(u8 *, s32, s32, f32);
extern void func_00305AD0(u8 *, u8 *, s32, f32);
extern void func_00306838(u8 *);

void func_00305858(u8 *a0) {
    u8 *p;

    p = *(u8 **)(a0 + 104);
    func_004C1FE8(71, 0x53001);
    if ((D_002C5640 + D_001425C0[17])->b1 >= 4) {
        func_00305CA0(a0, 0x7F7F7F7F, 75, 0.1f);
    } else {
        func_00305CA0(a0, 0x7F7F7F7F, 75, 0.05f);
    }
    if (*(f32 *)(p + 80) != 0.0f) {
        p += 16;
        if ((D_002C5640 + D_001425C0[17])->b1 >= 4) {
            func_00305AD0(a0, p, 0x7F7F3010, 0.25f);
            func_00305AD0(a0, p, 0x3F3F1808, 0.5f);
        } else {
            func_00305AD0(a0, p, 0x7F10307F, 0.25f);
            func_00305AD0(a0, p, 0x3F08183F, 0.5f);
        }
    }
    func_00306838(a0);
    func_004C1FE8(71, 0x5360B);
}
/* localdecomp:end func_00305858 */
