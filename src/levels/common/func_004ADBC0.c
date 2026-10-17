#include "common.h"

extern void func_0040C5D0();
extern void func_004ADBC0(void);
extern void func_004ADBC0();
extern u32 *D_001E10E8;
extern u32 *D_001E0F3C;
extern s32 D_001D4BB0;

extern s32 D_001D4BB4;
extern u8 D_001E2A40[];
extern u8 D_0023C180[];
extern void func_0040BE90(f32 *, void *, f32);
extern void func_0040C9B0();
extern void func_0040BDE0();
extern void func_0011F0A0(s32);
extern void func_004ADC98();
void func_004ADBC0(void) {
    u8 v[0x40];
    u32 *o = D_001E10E8;
    s32 t = D_001D4BB4;
    D_001E0F3C = o;
    o += 4;
    D_001D4BB0 = t;
    D_001E10E8 = o;
    func_0040C5D0(v);
    func_0040BE90((f32 *)(v + 0x30), D_001E2A40, -1024.0f);
    *(f32 *)(v + 0x3C) = 1.0f;
    func_0040C9B0(v, D_001E2A40 - 0x100, v);
    func_004C1EF0(5, (s32)v, 4);
    func_004C1EF0(0x14D, (s32)v, 4);
    func_0011F0A0(0);
    func_004ADC98();
    func_004ADA10();
    func_0040BDE0(D_0023C180, 0x3000, 0x40);
}
