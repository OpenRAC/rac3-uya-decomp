#include "common.h"

/* localdecomp:start func_004233F8 */
extern void func_004233F8(void);
extern void func_0011F0A0(s32);
extern void func_0040BD58();

typedef struct { s32 off; s32 size; } E_94060;
typedef struct { u8 p0[0x18]; s32 f18; s32 f1C; E_94060 e[5]; } B_94060;
typedef struct { u8 p0[4]; s32 f4; s32 f8; s32 fC; s32 f10; u8 p14[0x40]; s32 f54; s32 f58; s32 f5C; s32 f60; s32 f64; u8 p68[0x2C]; s32 f94; u8 p98[4]; s32 f9C; s32 fA0; s32 fA4; } G_94060;
typedef struct { u8 p0[0x10]; s32 f10; } Q_94060;
extern B_94060 *D_001D4B50_00394060;
extern int D_001DFD98_00394060;
extern s32 D_001DFDC0[5];
extern u8 D_001D6D30[];
extern u8 D_001D6D40[];
extern u8 D_001D6D50[];
extern u8 D_001D6D60[];
extern u8 D_001D6D70[];
extern s32 D_001DFD9C;
extern s32 D_001DFDA0;
extern s32 D_001DFDA4;
extern s32 D_001DFDA8;
extern Q_94060 D_001EA9C0[];
extern s32 func_0041A098();
extern void func_0040BD58();
extern void func_00423698();
extern s32 func_004AD500();
extern void func_00419F40();
extern void func_0011F0A0();
extern void func_00419C38();
extern void func_00419F10();
void func_004233F8(void) {
    B_94060 *b;
    s32 *h;
    s32 *q;
    s32 i;
    s32 r, x, t;
    b = D_001D4B50_00394060;
    for (i = 0; i < 5; i++) {
        D_001DFDC0[i] = (b->e[i].size + 0x3F) & 0xFFFFFFC0;
    }
    r = (b->f1C + 0x3F) & 0xFFFFFFC0;
    q = (s32 *)D_001EA9C0;
    h = (s32 *)func_0041A098(r, 0, D_001D6D30, 0x39E);
    func_0040BD58(h, (void *)(b->f18 + (s32)b), r);
    x = q[4] + 0x30000;
    D_001DFD98_00394060 = (int)h;
    D_001DFD9C = (s32)h + h[1];
    D_001DFDA0 = (s32)h + h[2];
    D_001DFDA8 = (s32)h + h[3];
    D_001DFDA4 = (s32)h + h[4];
    if (h[0x15]) {
        u32 s = (u32)((b->e[0].size + 0x3F) & 0xFFFFFFC0) >> 4;
        func_00423698(0, x);
        *(s32 *)(D_001DFD98_00394060 + 0x94) = func_004AD500((void *)(b->e[0].off + (s32)b), s, s, D_001D6D40);
        func_00419F40(0, x, 1);
    }
    if (*(s32 *)(D_001DFD98_00394060 + 0x58)) {
        t = func_0041A098(*(s32 *)(D_001DFD98_00394060 + 0x58), 0, D_001D6D30, 0x3CE);
        func_00423698(1, t);
        func_0011F0A0(0);
        func_00419C38(1, t);
    }
    if (*(s32 *)(D_001DFD98_00394060 + 0x5C)) {
        s32 s = ((b->e[2].size + 0x3F) & 0xFFFFFFC0);
        s = (u32)s >> 4;
        *(s32 *)(D_001DFD98_00394060 + 0x9C) = func_004AD500((void *)(b->e[2].off + (s32)b), s, s, D_001D6D50);
    }
    if (*(s32 *)(D_001DFD98_00394060 + 0x60)) {
        s32 s = ((b->e[3].size + 0x3F) & 0xFFFFFFC0);
        s = (u32)s >> 4;
        *(s32 *)(D_001DFD98_00394060 + 0xA0) = func_004AD500((void *)(b->e[3].off + (s32)b), s, s, D_001D6D60);
    }
    if (*(s32 *)(D_001DFD98_00394060 + 0x64)) {
        s32 s = ((b->e[4].size + 0x3F) & 0xFFFFFFC0);
        s = (u32)s >> 4;
        *(s32 *)(D_001DFD98_00394060 + 0xA4) = func_004AD500((void *)(b->e[4].off + (s32)b), s, s, D_001D6D70);
    }
    func_00419F10();
}
/* localdecomp:end func_004233F8 */
