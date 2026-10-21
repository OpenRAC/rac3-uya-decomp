#include "common.h"

/* localdecomp:start func_00493080 */
typedef struct {
    s32 x0;
    s32 x4;
    s16 x8;
    s16 xA;
    u16 xC;
    u16 xE;
    s16 x10;
    u16 x12;
    s32 x14;
    s16 x18;
    s16 x1A;
    s32 x1C;
} T_00493080;

extern void func_004035F8(s32, s32, s32, s32);
extern char *func_004181A0(s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern void func_004105D8(T_00493080 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0040EE10(T_00493080 *, long, char *, s32, unsigned long, f32, f32);
extern void func_00404E18(s32, s32, s32, s32, s32, s32);
extern void func_00432FE8(s32, s32, f32, f32, f32, f32);
extern s32 D_001E1220;
extern f32 D_001E1224;
extern s32 D_001D4BC8;
extern char D_001D91D0[];

void func_00493080(s32 a) {
    char buf[1024];
    T_00493080 s;
    s32 w, h;
    s32 c;
    s32 x, y;

    func_004035F8(0, 0, 0, 96);
    func_0011B2E8(buf, D_001D91D0, func_004181A0(a), func_004181A0(3285));
    s.x18 = 2;
    s.x1A = 2;
    {
        f32 v = 256.0f;
        f32 z0 = 0.0f, z1 = 0.0f;
        x = (s32)(v * D_001E1224 + 0.5f + (D_001E1220 == 1 ? z0 : z1));
    }
    {
        f32 v = 384.0f;
        f32 z0 = 0.0f, z1 = 0.0f;
        y = (s32)(v * D_001E1224 + 0.5f + (D_001E1220 == 1 ? z0 : z1));
    }
    c = D_001D4BC8;
    func_004105D8(&s,
        x,
        y,
        c - 144, c + 144, c, 320, 16, 39);
    func_0040EE10(&s, 0x8066CCFF, buf, -1, 0x80000000, 1.0f, 1.0f);
    w = ((s16)s.xC >> 1) + 8;
    h = ((s16)s.xE >> 1) + 8;
    func_00404E18(s.xA - h, s.xA + h, s.x8 - w, s.x8 + w, 51, 0x331465B7);
    func_00432FE8(51, 0x332299DE, s.xA - h, s.xA + h, s.x8 - w, s.x8 + w);
    s.x12 &= 0xFFFB;
    func_0040EE10(&s, 0x8066CCFF, buf, -1, 0x80000000, 1.0f, 1.0f);
}
/* localdecomp:end func_00493080 */
