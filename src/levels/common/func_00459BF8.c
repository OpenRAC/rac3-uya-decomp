#include "common.h"

/* localdecomp:start func_00459BF8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_459BF8;
typedef struct {
    u8 pad0[0x80];
    s32 f80;
    u8 pad84[0x10];
    s32 f94;
    s32 f98;
    s32 f9C;
    V4_459BF8 fA0;
    u8 padB0[4];
    s32 fB4;
    u8 padB8[4];
    s32 fBC;
    u8 padC0[0x2A];
    u8 fEA;
} S_459BF8;
extern s32 D_001DFBC0;
extern S_459BF8 *func_00458650(void *, void *, void *);
extern void func_00458EC8(void);
extern void func_0040C8E0(void *, void *);
extern void func_0044DF40(void *, void *, s32);
extern void func_0044E358(void *, void *, void *);
extern void func_0040C2D0(void *, void *, void *);
extern void func_00458600(void *, void *);
extern void func_004585D0(void *, void *);
extern void func_00459A98(void *, void *);
extern void func_00459208(void *, void *, void *, void *, void *, void *, void *);
extern void func_004594A0(void *, void *, void *, void *);
extern void func_00459648(void *, void *, void *, void *);
s32 func_00459BF8(u8 *a0, void *a1, void *a2) {
    V4_459BF8 v0[4];
    V4_459BF8 v40;
    V4_459BF8 v50[3];
    V4_459BF8 v80;
    V4_459BF8 v90;
    V4_459BF8 *pv;
    S_459BF8 *s = func_00458650(a0, a1, a2);
    if (s == 0) {
        return 8;
    }
    if (D_001DFBC0 == s->fBC) {
        return s->f94;
    }
    func_00458EC8();
    func_0040C8E0(v0, a0 + 0xC0);
    pv = v0;
    func_0044DF40(a0 + 0x10, &v40, 0);
    func_0044E358(a0 + 0xC0, &v40, v50);
    func_0040C2D0(&s->fA0, &s->fA0, v50);
    s->f98 = s->f94;
    s->f94 = 0;
    func_00458600(a0, s);
    func_004585D0(a0, s);
    if (D_001DFBC0 - s->fBC > 1 || s->fBC == 0) {
        func_00459A98(a0, s);
        s->f80 = 0;
        s->f9C &= ~2;
        s->fEA = 0xFF;
        __asm__ __volatile__("sq $0, %0" : "=m"(s->fA0));
        s->fB4 = 0;
    }
    s->fBC = D_001DFBC0;
    func_00459208(a0, s, a1, a2, &v80, &v90, pv);
    func_004594A0(a0, s, &v90, pv);
    func_00459648(a0, s, a1, pv);
    return s->f94;
}
/* localdecomp:end func_00459BF8 */
