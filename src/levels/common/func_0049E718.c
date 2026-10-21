#include "common.h"

/* localdecomp:start func_0049E718 */
typedef struct {
    s32 w0;
    u8 pad4[16];
    u8 b14;
    u8 pad15[3];
} E_0049E718;

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    f32 f34;
    s32 w38;
    s32 w3C;
    s32 w40;
    s32 w44;
    s32 w48;
    s32 w4C;
    s32 w50;
} P_0049E718;

extern E_0049E718 D_002ED8A0[];
extern char D_001D96E8[];
extern s32 func_0047A280(void);
extern s32 func_0047A2D8(s32);
extern s32 func_00494DD0(s32);
extern void func_00494EE0(s32, P_0049E718 *);
extern void func_00495F40(s32, s32, f32, f32, f32, f32, f32);
extern void func_00495F60(s32, f32, f32, f32, f32);
extern void func_00495850(s32, s32, f32, f32, f32);
extern void func_00495108(s32, s32, s32);
extern s32 func_004950A8(s32, s32, s32);
extern s32 func_004181A0(s32);
extern void func_0011B2E8(s32, char *, s32);

void func_0049E718(void) {
    s32 n;
    s32 i;
    s32 h;
    E_0049E718 *e;
    P_0049E718 p;

    for (n = 0; D_002ED8A0[n].w0 > 0; n++) {
    }
    p.w0 = func_0047A280();
    p.w4 = func_0047A2D8(0);
    p.w8 = 20;
    p.wC = n;
    p.w10 = n < 6 ? n : 5;
    p.w14 = 1;
    p.f18 = 1.0f;
    p.f20 = 0.09534f;
    p.f1C = 0.722955f;
    p.f24 = 0.5f;
    p.f28 = 1.0f;
    p.f2C = 1.0f;
    p.f30 = 1.0f;
    p.f34 = 0.795206f;
    p.w38 = 0;
    p.w3C = 0;
    p.w40 = 0;
    p.w44 = 0;
    p.w48 = 0;
    p.w4C = 0;
    p.w50 = 0;
    func_00494EE0(func_00494DD0(0), &p);
    func_00495F40(func_00494DD0(0), 0, 0.5f, 0.816536f, 0.045f, 0.0425f, 0.35f);
    func_00495F60(func_00494DD0(0), 0.500369f, 0.764263f, 0.816536f, 0.165586f);
    func_00495850(func_00494DD0(0), 1, 0.04767f, 0.00666f, 0.03f);
    for (i = 0; i < n; i++) {
        e = &D_002ED8A0[i];
        if (e->b14) {
            func_00495108(func_00494DD0(0), i, 0);
            h = func_004950A8(func_00494DD0(0), 0, i);
            func_0011B2E8(h, D_001D96E8, func_004181A0(e->w0));
        } else {
            func_00495108(func_00494DD0(0), i, 1);
            h = func_004950A8(func_00494DD0(0), 0, i);
            func_0011B2E8(h, D_001D96E8, func_004181A0(456));
        }
    }
}
/* localdecomp:end func_0049E718 */
