#include "common.h"

typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x15C - 0x14];
    s32 f15C;
    u8 pad160[4];
    s32 f164;
    u8 pad168[4];
    s32 f16C;
    u8 pad170[0xC];
    s32 f17C;
} S_003EF2D8;
typedef struct { u8 pad[0x120]; u16 h120; } S_003EF2D8_B;

extern S_003EF2D8 D_00142430;
extern S_003EF2D8_B D_001A7E18;
extern u16 D_001A7F38[];
extern s32 D_001DF800;
extern s32 D_001D6694;
extern s32 D_001D4CE8;
extern s32 D_001D4CEC;
extern s32 D_001DF9C8;
extern void func_00457288(s32, s32, s32, s32, s32);
extern void func_00401978(s32);
extern void func_004C1FE8(s32, unsigned long);
extern s32 func_0041D880(s32, s32);
extern void func_0041DB78(s32, s32, s32, s32, s32, s32);
extern s32 func_0041D950(s32);
extern void func_0041EB48(f32, f32, f32, f32, f32, s32, s32, s32);
extern void func_00401AA8(void);

/* localdecomp:start func_003EF2D8 */
void func_003EF2D8(void) {
    s32 cur;
    f32 sz;
    f32 ang;
    s32 tex;
    s32 n;

    if (!((u32)(D_00142430.f15C - 15) < 2 || D_00142430.f164 == 15) && D_001DF800 == 0) return;
    if (D_00142430.f16C != 0 || D_00142430.f10 != 0) {
        D_00142430.f17C = 0;
        D_001D4CE8 = 24;
        D_001D4CEC = 64;
        D_001DF800 = 0;
        if (D_001D6694 == 0) func_00457288(4, 1, 1, 0, 0);
        else func_00457288(4, 2, 1, 0, 0);
        return;
    }
    cur = D_001DF800;
    if (cur == -1) {
        if (D_001D6694 != 0) return;
        if (D_001A7E18.h120 == 0) D_001A7E18.h120 = 1;
        D_001DF800 = 0;
        return;
    }
    if (D_001D6694 == 0 && D_001A7F38[0] == 0) {
        func_00457288(4, 1, 2, 0, 0);
        D_001DF800 = -1;
        return;
    }
    if ((u32)(D_00142430.f15C - 15) < 2 || D_00142430.f164 == 15) D_001DF800 = 30;
    else D_001DF800 = cur - 1;
    func_00401978(0);
    n = 55;
    sz = 272.0f;
    func_004C1FE8(71, 0x2004B);
    func_0041DB78(func_0041D880(30045, 0), 425, 250, 64, 64, 128);
    ang = (f32)(D_001DF9C8 % n) * -6.2831855f / (f32)n;
    tex = func_0041D950(func_0041D880(30045, 1));
    func_0041EB48(7312.0f, 4512.0f, sz, sz, ang, 64, 64, tex);
    func_00401AA8();
    if (D_001D4CE8 == 3) D_001DF800 = 0;
}
/* localdecomp:end func_003EF2D8 */
