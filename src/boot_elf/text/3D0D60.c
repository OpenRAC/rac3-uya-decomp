#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003D0D70(void);
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/boot_elf/remnants", func_003D0D60);

/* localdecomp:start func_003D0D70 */
typedef int u128_3CB5B0 __attribute__((mode(TI)));
typedef struct { u8 p0[0x350]; f32 f350, f354, f358; s32 x35C; } L_3CB5B0;
typedef struct { u8 p0[0x10]; u128_3CB5B0 q10; } B_3CB5B0;
typedef struct { u8 p0[0x10]; s32 state; u8 p1[0xC]; u128_3CB5B0 q20; } E_3CB5B0;
__asm__(".extern D_001D9350, 8");
extern s32 D_001D9350[2];
extern f32 D_00222498[];
extern u8 D_002FF280[];
extern B_3CB5B0 D_002FF680[];
extern E_3CB5B0 D_002FF780[];
extern void func_0038DDE0(f32, f32);
extern f32 func_0038D3C0(f32);
extern f32 func_0038D3D8(f32);
extern f32 func_0038D228(void *, void *);
extern void func_003D0F08(void *);
extern void func_003D1020(void *);
void func_003D0D70(void) {
    L_3CB5B0 *l;
    f32 r;
    s32 i;
    *(u128_3CB5B0 *)(D_002FF280 + 0x340) = *(u128_3CB5B0 *)D_001D9350;
    r = ((f32 (*)(f32, f32))func_0038DDE0)(D_00222498[0], -0.8f);
    l = (L_3CB5B0 *)D_002FF280;
    l->f350 = func_0038D3C0(r) * 0.866f;
    l->f354 = func_0038D3D8(r) * 0.866f;
    l->f358 = -0.5f;
    l->x35C = 0;
    for (i = 0; i < 8; i++) {
        B_3CB5B0 *b = &D_002FF680[i];
        E_3CB5B0 *e = &D_002FF780[i];
        if (e->state != 0) {
            if (1.0f < func_0038D228(&b->q10, &e->q20) ||
                1.0f < fabsf(*(f32 *)((u8 *)b + 0x1C) - *(f32 *)((u8 *)e + 0x2C))) {
                e->q20 = b->q10;
                if (e->state == 1) {
                    func_003D0F08((void *)i);
                    e->state = 2;
                } else if (e->state == 2) {
                    func_003D1020((void *)i);
                }
            }
        }
    }
}
/* localdecomp:end func_003D0D70 */

/* localdecomp:start func_003D0F08 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3CB748;
typedef struct { s16 h0, h2, h4, h6, h8, hA; u32 w; u8 pad[0x20]; } S_3CB748;
extern u32 func_003DEAF0(u32, u32, s32, void *);
extern u32 func_003E1330(u32, u32, s32, void *);
extern u32 func_003D0AD0(u32, u32, s32, void *);
void func_003D0F08(void *arg) {
    s32 idx = (s32)arg;
    S_3CB748 *s = (S_3CB748 *)&D_002FF780[idx];
    u8 *b = (u8 *)&D_002FF680[idx];
    u8 *q = b + 0x10;
    u32 cur = s->w;
    u32 end = cur + 0x400;
    s32 x;
    V_3CB748 v = *(V_3CB748 *)(b + 0x10);
    if (cur < end) {
        s->h0 = 0;
        cur = func_003DEAF0(cur, end, idx, q);
        x = (s32)(cur - s->w) >> 1;
        s->h2 = x;
        if (cur < end) {
            s->h4 = x;
            cur = func_003E1330(cur, end, idx, q);
            x = (s32)(cur - s->w) >> 1;
            s->h6 = x - (u16)s->h4;
            if (cur < end) {
                s->h8 = x;
                s->hA = ((s32)(func_003D0AD0(cur, end, idx, q) - s->w) >> 1) - (u16)s->h8;
            }
        }
    }
}
/* localdecomp:end func_003D0F08 */

/* localdecomp:start func_003D1020 */
extern void func_003D1050();
extern void func_003D0F08(void *);
void func_003D1020(void *p) {
    func_003D1050(p);
    func_003D0F08(p);
}
/* localdecomp:end func_003D1020 */
