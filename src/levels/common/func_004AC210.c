#include "common.h"

extern s32 func_004A57D8(void);
extern s32 func_0012C908(s32);
extern void func_00436220(s32 p);
extern void func_00402A10(s32);

typedef struct { u8 p0[0x24]; s32 f24; u8 p28[0x44]; s32 f6C; u8 p70[6]; u16 f76; u8 p78[0x1C]; s32 f94; u8 p98[6]; u16 f9E; } S_3A1E48a;
typedef struct { u8 p0[0xC]; u8 bC; u8 pD[0x3B]; s32 f48[1]; } S_3A1E48c;
typedef struct { u8 p0[0x24]; S_3A1E48c *f24; } S_3A1E48d;
typedef struct { u8 p0[0x44]; s16 n44; u8 p46[0x15A]; S_3A1E48d *e[1]; } S_3A1E48b;
typedef struct { u8 p0[0x34]; u16 h34; } S_3A1E48e;
extern S_3A1E48a D_001CCFD0_003A1E48;
extern u8 D_001E7600_003A1E48[];
extern S_3A1E48b D_001E6E00_003A1E48;
extern u8 D_001A4BE0_003A1E48[];
extern S_3A1E48e *D_001DFC98;
extern s32 D_001DF9DC;
extern s32 D_001DF9E0;
extern s32 D_001DF9D0[1];
extern void func_00402A10(s32);
extern s32 func_004A57D8(void);
extern s32 func_0012C908(s32);
extern void func_0013B620_003A1E48(void);
extern void func_003FFAC8();
extern void func_00436220(s32 p);
void func_004AC210(void) {
    s32 i;
    if ((u16)(D_001CCFD0_003A1E48.f76 - 6) >= 2) D_001CCFD0_003A1E48.f76 = 5;
    if ((u16)(D_001CCFD0_003A1E48.f9E - 6) >= 2) D_001CCFD0_003A1E48.f9E = 5;
    func_00402A10(0xC);
    while (D_001CCFD0_003A1E48.f6C != 0 || D_001CCFD0_003A1E48.f24 != -1 || D_001CCFD0_003A1E48.f94 != 0) {
        func_004A57D8();
        func_0012C908(0);
    }
    while (((s32 (*)(void))func_0013B620_003A1E48)() != 0) {
    }
    {
    s32 j;
    j = 0;
    D_001DF9DC = 0;
    D_001DF9E0 = 0;
    for (; j >= 0; j--) D_001DF9D0[j] = 0;
    }
    { u8 *q = D_001E7600_003A1E48; *(f32 *)(q + 0xB0) = 0.63f; }
    func_003FFAC8();
    for (i = 0; i < D_001E6E00_003A1E48.n44; i++) {
        S_3A1E48d *p = D_001E6E00_003A1E48.e[i];
        if (p) {
            p->f24->bC--;
            p->f24->f48[p->f24->bC] = 0;
            func_00436220((s32)p);
            D_001E6E00_003A1E48.e[i] = 0;
        }
    }
    {
        u8 *q = D_001A4BE0_003A1E48;
        if (*(s32 *)(q + 0x12A0)) {
            func_00436220(*(s32 *)(q + 0x12A0));
            *(s32 *)(q + 0x12A0) = 0;
        }
    }
    {
        S_3A1E48e *e = *(S_3A1E48e * volatile *)&D_001DFC98;
        if (e) e->h34 &= ~1;
    }
}
