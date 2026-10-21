#include "common.h"

/* localdecomp:start func_00489D10 */
extern u8 *D_001D52FC[];
extern s32 D_001D8C10;
extern u8 D_001D672C[];
extern void func_0047B428(void);
extern s32 func_0047B380(void);
extern void func_004A7368(s32 a0, s32 a1, s32 a2);
extern s32 func_0047C5C8(void);
extern s32 func_00486758(void);
extern s32 func_0048DCD8(s32 a0);
extern void func_00513758(s32 a0);
extern void func_005120B8(void *a0);
extern void func_005130C8(s32 a0, s32 a1);
extern s32 func_00440BA8(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1);
extern void func_00488750(void);
extern s32 func_0047A250(void);
extern void func_0047A268(void);

void func_00489D10(void *a0) {
    u32 pad;
    s32 old;
    s32 r;
    s32 t;

    func_0047B428();
    pad = *(u32 *)(D_001D52FC[0] + 452);
    old = D_001D8C10;
    if (pad & 0x800) {
        func_00513758(func_0047B380());
        func_005120B8(a0);
    } else if (pad & 0x10) {
        func_004A7368(4, 0, 0);
        func_00513758(func_0047C5C8());
        func_005120B8(a0);
    } else if (pad & 0x1000) {
        func_004A7368(3, 0, 0);
        D_001D8C10 -= 5;
        if (D_001D8C10 < 0) {
            D_001D8C10 += 10;
        }
    } else if (pad & 0x4000) {
        func_004A7368(3, 0, 0);
        D_001D8C10 += 5;
        if (D_001D8C10 >= 10) {
            D_001D8C10 -= 10;
        }
    } else if (pad & 0x8000) {
        func_004A7368(3, 0, 0);
        t = D_001D8C10;
        t--;
        D_001D8C10 = t;
        if (t < 0) {
            D_001D8C10 = 4;
        } else if (t == 4) {
            D_001D8C10 = 9;
        }
    } else if (pad & 0x2000) {
        func_004A7368(3, 0, 0);
        t = D_001D8C10;
        t++;
        D_001D8C10 = t;
        if (t >= 10) {
            D_001D8C10 = 5;
        } else if (t == 5) {
            D_001D8C10 = 0;
        }
    } else if (pad & 0x1) {
        func_004A7368(4, 0, 0);
        func_00513758(func_00486758());
        func_005120B8(a0);
    } else if (pad & 0x2) {
        func_004A7368(4, 0, 0);
        func_00513758(func_0048DCD8(0));
        func_005120B8(a0);
    }
    if (D_001D8C10 != old) {
        func_005130C8(old + 37, 0x332299DE);
        func_00440BA8(0x332299DE, 0x8066CCFF, 40, 0, 1, 1);
    }
    r = func_00440BA8(0x332299DE, 0x8066CCFF, 40, 0, 0, 1);
    func_005130C8(D_001D8C10 + 37, r);
    func_00488750();
    if (func_0047A250() != 0) {
        func_0047A268();
        func_005120B8(a0);
        if (D_001D672C[0] == 0) {
            func_00513758(func_0047B380());
        }
    }
}
/* localdecomp:end func_00489D10 */
