#include "common.h"

/* localdecomp:start func_004AC828 */
extern void func_004AC828(void);
extern void func_004A7810(void);
extern u8 D_001A30B0[];
extern void func_0013CA28(void);
extern s32 func_0012C908(s32);
extern void func_0011F0A0(s32);
extern void func_00402A10(s32);
extern void func_004304B0();
extern void func_0045BEC8(void);
extern void func_0013CF80(s32, s32, s32, s32, s32);

typedef struct { u8 p0[0x15C]; s32 f15C; u8 p160[4]; s32 f164; } S_142430_3A2460;
typedef struct { u8 p0[0x228]; f32 f228; f32 f22C; u8 p230[8]; f32 f238; f32 f23C; u8 p240[0x10]; s32 f250; s32 f254; s32 f258; } S_225980_3A2460;
extern S_142430_3A2460 D_00142430_003A2460;
extern u8 D_001CCFD0_003A2460[];
extern u8 D_001A30B0[];
extern S_225980_3A2460 D_001E7600_003A2460;
extern s32 D_001DFBC4;
extern u32 D_001D545C;
extern s32 D_001D4B48;
extern s32 D_001DFBEC;
extern u8 D_001DFA64, D_001DFA65, D_001DFA66;
extern f32 D_001DFA68, D_001DFA6C, D_001DFA70, D_001DFA74;
extern u8 D_001F4BC0[];
extern s32 func_004D3E20();
extern void func_00402A10(s32);
extern void func_0011F0A0(s32);
extern void func_0013CF80();
extern void func_0013CA28(void);
extern void func_0013B620_003A2460(void);
extern void func_004A7810(void);
extern void func_0045BEC8(void);
extern void func_0013BF00();
extern void func_0013BED0();
extern void func_00412C70(s32, long, long);
extern void func_0013D310();
extern s32 func_0012C908(s32);
extern void func_004304B0(void);
extern void func_0042EFF8(void);
extern s32 func_00428518();
extern void func_0013CF40();
extern void func_0013CDF0(s32);
extern void func_004C2898();
void func_004AC828(void) {
    s32 i;
    s32 *p;
    u8 *b;
    S_225980_3A2460 *q;
    if (func_004D3E20() != 0) return;
    func_00402A10(6);
    D_001D4B48 = 0;
    D_001D545C = D_001DFBC4;
    func_0011F0A0(0);
    func_0013CF80(2, 0, 0, 0, 0);
    func_0013CA28();
    func_0013B620_003A2460();
    func_004A7810();
    func_0045BEC8();
    b = D_001CCFD0_003A2460;
    b[7] = 1;
    { u8 *t = D_001A30B0; p = (s32 *)(t + 0x90); }
    for (i = 0; i < 6; i++) {
        if (*p) {
            func_0013BF00(*p);
            func_0013BED0();
            D_001DFBEC = 0;
            *p = 0;
        }
        p++;
    }
    q = &D_001E7600_003A2460;
    q->f258 = 0x10;
    q->f250 = 0;
    q->f254 = 0;
    q->f228 = 0;
    q->f22C = 524288.0f;
    q->f238 = 255.0f;
    q->f23C = 128.0f;
    D_001DFA64 = q->f250;
    D_001DFA65 = q->f254;
    D_001DFA66 = q->f258;
    D_001DFA68 = q->f228;
    D_001DFA6C = q->f22C;
    D_001DFA70 = q->f238;
    D_001DFA74 = q->f23C;
    func_00412C70(0, 0, 0);
    func_0013D310(D_001D545C, D_001F4BC0);
    b = D_001CCFD0_003A2460;
    b[7] = 1;
    do {
        func_0011F0A0(0);
        func_0012C908(0);
        func_004304B0();
        func_0042EFF8();
    } while (func_00428518() == 0);
    while (D_00142430_003A2460.f15C != 2 || D_00142430_003A2460.f164 >= 0) {
        func_0011F0A0(0);
        func_0012C908(0);
        func_004304B0();
        func_0042EFF8();
    }
    while (((s32 (*)(void))func_0013B620_003A2460)() != 0) {
    }
    func_0013BED0();
    func_0013CF40(0);
    func_0013CDF0(0);
    func_0013CDF0(0);
    b = D_001CCFD0_003A2460;
    b[7] = 0;
    func_004C2898();
}
/* localdecomp:end func_004AC828 */
