#include "common.h"

/* localdecomp:start func_004051B8 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_0040BE90(f32 *, void *, f32);
extern u128_t D_001E2A40[];
extern void func_0040C9B0();
/* .sdata: bare references the assembler expands with lui (size unknown). */
extern s32 D_001DFBDC;
extern s32 D_001E10E8;

typedef struct { u8 p0[0x190]; u128_t q190; u128_t q1A0; u8 p1B0[0x70]; f32 f220; u8 p224[0x14]; f32 f238; f32 f23C; s32 f240; s32 f244; s32 f248; s32 f24C; } S_388018;
extern f32 D_001D60F0;
extern S_388018 D_001E7600_00388018;
extern long D_001D5330[];
extern u8 D_0010F500[];
extern void func_0040C600_00388018(f32 *, f32);
extern u16 D_0010F4F0[];
extern void func_004C1E98(s32, u32);
extern void func_004C22E8(void);
void func_004051B8(void) {
    f32 m[12];
    f32 v[4];
    u8 *p;
    u8 *q;
    u8 *d;
    S_388018 *s;
    func_0040C600_00388018(m, 1024.0f);
    func_0040BE90(v, D_001E2A40, -1024.0f);
    v[3] = 1.0f;
    if (D_001DFBDC != 8) {
        func_004C1E98((s32)D_0010F500, D_0010F4F0[0]);
        D_001DFBDC = 8;
    }
    *(s32 *)(D_001E10E8 + 0) = 0x10000000;
    *(s32 *)(D_001E10E8 + 4) = 0;
    *(s32 *)(D_001E10E8 + 8) = 0x11000000;
    *(s32 *)(D_001E10E8 + 0xC) = 0x1000404;
    p = (u8 *)D_001E10E8;
    *(s32 *)(p + 0x10) = 0;
    *(s32 *)(p + 0x14) = 0;
    *(s32 *)(p + 0x18) = 0;
    *(s32 *)(p + 0x1C) = 0x6C0C43A4;
    q = p + 0x20;
    func_0040C9B0(q, (u8 *)D_001E2A40 - 0x100, m);
    *(f32 *)(q + 0x38) += D_001D60F0;
    q = p + 0x60;
    func_0040C9B0(q, (u8 *)D_001E2A40 - 0x80, m);
    *(f32 *)(q + 0x38) += D_001D60F0;
    s = &D_001E7600_00388018;
    *(s32 *)(p + 0xA0) = 0x8000;
    *(s32 *)(p + 0xA4) = 0x303EC000;
    *(s32 *)(p + 0xA8) = 0x412;
    *(f32 *)(p + 0xAC) = s->f220;
    *(u128_t *)(p + 0xB0) = s->q190;
    *(u128_t *)(p + 0xC0) = s->q1A0;
    *(f32 *)(p + 0xD0) = s->f23C;
    *(f32 *)(p + 0xD4) = s->f238;
    *(s32 *)(p + 0xE0) = 0x3000000;
    *(s32 *)(p + 0xE4) = 0x20001D2;
    *(s32 *)(p + 0xE8) = 0x15000000;
    *(s32 *)(p + 0xD8) = 0;
    *(s32 *)(p + 0xDC) = 0;
    *(s32 *)(p + 0xEC) = 0;
    q = p + 0xF0;
    d = (u8 *)D_001E10E8;
    *(s32 *)d |= ((q - d) >> 4) - 1;
    D_001E10E8 = (s32)q;
    D_001D5330[2] = (long)s->f240 | ((long)s->f244 << 16) | ((long)s->f248 << 32) | ((long)s->f24C << 48);
    D_001D5330[4] = (long)s->f240 | ((long)s->f244 << 16) | ((long)s->f248 << 32) | ((long)s->f24C << 48);
    func_004C22E8();
}
/* localdecomp:end func_004051B8 */
