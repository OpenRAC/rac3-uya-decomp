#include "common.h"

/* localdecomp:start func_003A0AC8 */
typedef int Q_3A0AC8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3A0AC8;
typedef struct { u8 pad0[0x98]; s32 f98; } S_3A0AC8;
typedef struct { u8 pad0[0x10]; u8 f10[0x10]; u8 f20; u8 pad21[0x47]; S_3A0AC8 *f68; } O_3A0AC8;
typedef struct { u8 pad0[0x80]; V_3A0AC8 f80; u8 pad90[0x25C0 - 0x90]; u8 *f25C0; s32 f25C4; } G_3A0AC8;
typedef struct { u8 pad0[0xAA]; s16 fAA; } M_3A0AC8;
extern V_3A0AC8 D_001A4C60;
extern M_3A0AC8 *D_001E80D8[];
extern s32 func_004205C0(void *p);
extern void func_003A0BF0(O_3A0AC8 *o, S_3A0AC8 *s);
extern void func_003A0EB8(O_3A0AC8 *o, S_3A0AC8 *s);
extern s32 func_003A1A98(S_3A0AC8 *s);
extern void func_003A10E8(void);
extern void func_003DB440(void (*f)(void), O_3A0AC8 *o);
extern void func_003DB378(void (*f)(void), O_3A0AC8 *o);
extern void func_003E4858(V_3A0AC8 *out, void *in, f32 s);
extern s32 func_003D23D8(V_3A0AC8 *v, s32 a, u8 *b, f32 s);
extern void func_004CF3B8(s32 a, s32 b);

void func_003A0AC8(O_3A0AC8 *o) {
    S_3A0AC8 *s = o->f68;
    V_3A0AC8 pos;
    V_3A0AC8 off;
    Q_3A0AC8 a, b;
    G_3A0AC8 *g;
    if (func_004205C0(o->f10) == 0) {
        return;
    }
    if (o->f20 == 0) {
        func_003A0BF0(o, s);
    }
    func_003A0EB8(o, s);
    if (func_003A1A98(s) != 0) {
        func_003DB440(func_003A10E8, o);
    } else {
        func_003DB378(func_003A10E8, o);
    }
    if (s->f98 == -1) {
        return;
    }
    *(Q_3A0AC8 *)&pos = *(Q_3A0AC8 *)&D_001A4C60;
    g = (G_3A0AC8 *)((u8 *)&D_001A4C60 - 0x80);
    func_003E4858(&off, g->f25C0 + 0xE0, 0.75f);
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(off));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(pos));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(a));
    if (func_003D23D8(&pos, 0, g->f25C0, 0.5f) == 0) {
        return;
    }
    if (D_001E80D8[0] == 0) {
        return;
    }
    if (D_001E80D8[0]->fAA != 0x1C7A) {
        return;
    }
    if (g->f25C4 != 0x7D) {
        func_004CF3B8(0x7D, 1);
    }
}
/* localdecomp:end func_003A0AC8 */
