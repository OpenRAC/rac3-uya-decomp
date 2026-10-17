#include "common.h"

typedef struct {
    u8 pad0[16];
    u8 pos[33];
    u8 b49;
    u8 pad32[61];
    u8 b111;
    u8 pad70[38];
    u16 h150;
} Moby_3A1DD8;

extern u8 D_001E1D40[];

extern void func_003EECD0(void *p);
extern void func_003EED00(void *p);
extern void func_004318C8(void *moby, void *p, s32 a, s32 b, f32 f);
extern f32 func_003EF288(void *a, void *b);
extern void func_00426470(void *moby);

void func_003A1DD8(Moby_3A1DD8 *moby) {
    u8 *pvars = *(u8 **)((u8 *)moby + 104);
    func_003EECD0(pvars + 780);
    func_003EED00(pvars + 796);
    if (moby->h150 < 0xFFFF) {
        moby->h150++;
    }
    func_004318C8(moby, pvars + 576, 3, 1, 2.5f);
    if (moby->b49 != 0) {
        if (func_003EF288(D_001E1D40, moby->pos) < 1024.0f) {
            func_00426470(moby);
            moby->b111 = 30;
        }
    }
}
