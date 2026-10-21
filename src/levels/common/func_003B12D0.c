#include "common.h"

/* localdecomp:start func_003B12D0 */
typedef struct {
    void *pad0[5];
    void (*f14)(s32);
    void *pad18;
    s32 (*f1C)(void);
    void (*f24_pad)(void);
    void (*f24)(s32, s32);
    void (*f28)(s32);
    void (*f2C)(f32, void *);
} S_3B12D0_ops;
typedef struct {
    u8 pad0[0x10];
    s32 h10;
    u8 pad14[4];
    s32 h18;
    u8 pad1C[0x10];
    f32 h2C;
    s32 h30;
    s32 h34;
    s32 h38;
    u8 pad3C[4];
    s32 h40;
    u8 pad44[4];
    s32 h48;
    u8 pad4C[4];
    u8 h50;
    u8 pad51[0xB];
    s32 h5C;
    s32 h60;
} S_3B12D0;
typedef struct { u8 pad[0x25C4]; s32 h25C4; } S_1A4BE0;
extern S_3B12D0_ops *func_00438468(s32, s32);
extern void func_00417DA0(s32, s32);
extern void func_00441FB8(s32, s32, s32);
extern void func_004FC518(s32, s32);
extern s32 func_0050DAC0(void);
extern void func_00500F10(s32);
extern void func_003B11D8(s32);
extern void func_003B18A0(u8 *);
extern void func_0045BE58(s32, s32);
extern s32 D_001DFBC0;
extern s32 D_001D545C;
extern u8 D_001BBC40[][16];
extern u8 D_001426E0[];
extern S_1A4BE0 D_001A4BE0;
extern s32 D_001A71A4[];
extern u8 *D_001E009C;

void func_003B12D0(s32 a0, S_3B12D0 *s) {
    S_3B12D0_ops *ops;
    s32 m1 = -1;
    s32 flag = 0;
    s32 idx;
    ops = func_00438468(6625, 108);
    do { idx = s->h5C; } while (0);
    s->h60 = D_001DFBC0;
    if (idx != m1) {
        s32 t = D_001BBC40[D_001D545C][idx] & 0x80;
        flag = t == 0;
    }
    if (s->h30 != 0) {
        s32 b = s->h50;
        if ((u8)b != 0) {
            s32 id = -1;
            if ((u8)b != 255) {
                u32 v = s->h40;
                if (v != 0) {
                    v = (v & 0x7FF) | ((b & 0x1F) << 11);
                    D_001426E0[0x72] = v;
                    D_001426E0[0x71] = v >> 8;
                }
                id = s->h50;
            }
            func_00417DA0(id, 1);
            return;
        } else {
            ops->f24(s->h34, flag);
            func_00441FB8(a0, 11, -1);
            if (s->h10 == -1 || flag) {
                if (D_001A4BE0.h25C4 != 176) {
                    ops->f28(flag);
                    if (flag || s->h2C != 0.0f) {
                        ops->f2C(-100.0f, &D_001A4BE0);
                    } else if (s->h2C == 0.0f) {
                        func_004FC518(0, 1);
                    }
                }
            }
        }
    } else {
        if (ops->f1C() != 0) {
            ops->f24(-2, flag);
            if (s->h10 == -1 || flag) {
                if (D_001A71A4[0] != 176) {
                    ops->f28(flag);
                    ops->f2C(-100.0f, 0);
                }
            }
        }
        if (flag) {
            func_00441FB8(a0, 5, -1);
        } else {
            func_00441FB8(a0, 7, -1);
        }
    }
    if (s->h10 != -1 && !flag) {
        ops->f14(s->h38);
        func_003B11D8(a0);
        if (s->h30 != 0 && ops->f1C() != 0 && s->h2C != 0.0f) {
            ops->f2C(-100.0f, &D_001A4BE0);
        }
    } else {
        if (D_001A71A4[0] != 176 && func_0050DAC0() == 0) {
            func_00500F10(0);
        }
    }
    if (s->h30 == 0) {
        { s32 o = s->h18 * 256; func_003B18A0(D_001E009C + o); }
    }
    if (s->h48 != -1) {
        func_0045BE58(s->h48, -1);
    }
}
/* localdecomp:end func_003B12D0 */
