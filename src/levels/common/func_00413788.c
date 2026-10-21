#include "common.h"

/* localdecomp:start func_00413788 */
typedef struct {
    u8 pad0[0x40];
    s32 f40;
    u8 pad44[0x54 - 0x44];
    s32 f54;
    s32 f58;
    s32 a5C[4];
    s32 a6C[4];
    u16 h7C;
    u16 h7E;
    s32 f80;
    s32 f84;
    s32 f88;
} S_413788;

extern s32 D_001D545C;
extern s32 D_001F3FC0[];
extern s32 D_001DFC10;
extern s32 D_001D655C;
extern s32 D_001425AC[];
extern S_413788 D_001EA740;
extern s32 D_001D6694;

extern void func_00413778(s32);
extern s32 func_004573E8(void);
extern void func_0013C1A0(s32);
extern s32 func_00416600(void);
extern void func_0045BF98(s32);
extern void func_004A7368(s32, s32, s32);
extern void func_00415FC8(void);

void func_00413788(s32 arg0, s32 arg1) {
    s32 v;
    s32 t;
    S_413788 *p;
    s32 i;

    if ((D_001D545C == 8 && D_001F3FC0[0] == 1) || (D_001D545C == 19 && D_001F3FC0[0] == 0)) {
        D_001DFC10 = 2;
        func_00413778(2);
    }
    if ((u32)(D_001D545C - 22) < 2) {
        D_001DFC10 = 3;
        func_00413778(3);
    }
    D_001D655C = arg0;
    if (arg0 == 5) {
        D_001EA740.f80 = D_001425AC[0];
    } else {
        D_001EA740.f80 = 0;
    }
    p = &D_001EA740;
    p->f54 = arg1;
    p->h7E = arg0 == 12;
    p->f40 = arg0;
    p->h7C = 0;
    p->f58 = 0;
    if (func_004573E8() == 3) goto zero;
    if (func_004573E8() == 18) goto zero;
    v = 1;
    goto done;
zero:
    v = 0;
done:
    p->f88 = v;
    if (D_001D6694 != 3) {
        func_0013C1A0(77);
        if (func_00416600() == 0 && arg0 != 12) {
            func_0045BF98(0);
        }
    }
    for (i = 0; i < 4; i++) {
        D_001EA740.a5C[i] = 0;
        D_001EA740.a6C[i] = 0;
    }
    if (arg0 == 10) {
        func_004A7368(18, 0, 0);
    }
    func_00415FC8();
}
/* localdecomp:end func_00413788 */
