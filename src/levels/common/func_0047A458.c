#include "common.h"

typedef int s128 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[32];
    s32 src;
    u8 pad36[96];
    s32 mode;
} S_47A458;

extern S_47A458 D_002E9FD8;
extern s32 D_001DF9C8;
extern s32 D_001D4BC4;
extern s32 D_001D4BB4;
extern void func_004C1E50(s32);
extern void func_0012C908(s32);
extern void func_0012CB88(void *, s16, s32, s32, s32, s32, s32, s32);
extern void func_0011F0A0(s32);
extern void func_0012CE48(void *, s32);
extern void func_0012A9F0(s32, s32);

void func_0047A458(void) {
    s128 buf[7];
    s32 size;
    s32 dst;
    s32 src;

    func_004C1E50(1);
    func_0012C908(0);
    D_001DF9C8++;
    size = D_001D4BC4 * 1536;
    src = D_002E9FD8.src;
    dst = D_001D4BB4;
    if (D_002E9FD8.mode >= 2) {
        dst = 0x3FB000 - size;
    }
    for (; size >= 0; size -= 16384) {
        func_0012CB88(buf, dst >> 8, 1, 0, 0, 0, 64, 64);
        dst += 16384;
        func_0011F0A0(0);
        func_0012CE48(buf, src);
        src += 16384;
        func_0012A9F0(0, 0);
    }
    D_002E9FD8.mode = 0;
}
