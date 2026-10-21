#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BB130);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BB5B0);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BBDC0);

/* localdecomp:start func_003BBF90 */
typedef struct { char p0[0x18]; float f18; char p1[4]; unsigned char b20; char p2[0x47]; char *p68; char p3[0x29]; unsigned char b95; } A;
typedef struct { char p0[0x18]; float f18; } B;
typedef struct S {
    char p0[0x30]; float f30; char p1[0xa]; unsigned char b3e; char p2[0x20]; unsigned char b5f; char p3[6]; short h66;
    char p4[0xf8]; char r160[0x190]; int w2f0; float f2f4; int w2f8; float f2fc; char p6[0x20]; int w320;
} S;
extern B *D_0021F740[];
extern int func_003BC160(void);
extern int func_0044FCD0(A *, void *, int, int, int);
extern void func_003BBDC0(A *, S *);
extern void func_003BC440(A *, int);
extern void func_004538E0(A *, int);
extern void func_004539A8(A *, int, int, int, int, int, int, int, int, int, float, float, float);
int func_003BBF90(A *a) {
    S *s = (S *)a->p68;
    if (a->b20 == 0 && func_003BC160()) return 1;
    if (func_0044FCD0(a, s->r160, 0, 0, 0)) {
        if (s->h66 < 3) s->h66++;
    }
    if (0.0f < s->f30) func_003BBDC0(a, s);
    if (s->b3e == 2) func_003BC440(a, 1);
    if (s->b5f) func_004538E0(a, 5); else func_004538E0(a, 3);
    if (s->w320 != -1) a->f18 = D_0021F740[s->w320]->f18;
    if (s->b5f) {
        if (a->b95 == 0) func_004539A8(a, s->w2f0, 0, 0, 0, 0, 3, 0, 0, 0, s->f2f4, 10.0f, 1.0f);
        else func_004539A8(a, s->w2f8, 0, 0, 0, 0, 3, 0, 0, 0, s->f2fc, 10.0f, 1.0f);
    } else {
        func_004539A8(a, s->w2f8, 0, 0, 0, 0, 1, 0, 0, 0, s->f2fc, 10.0f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_003BBF90 */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BC160);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BC440);

LINKER_REMNANT("asm/veldin/remnants", func_003BC6C0);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BC6C8);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BC750);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BC850);

/* localdecomp:start func_003BC870 */
typedef struct { s32 w0; f32 f4; s32 w8; f32 fc; s32 w10; s32 w14; u8 pad18[0x60 - 0x18]; f32 f60; f32 f64; } SrcData;
typedef struct {
    u8 pad0[0x2f0]; s32 w2f0; f32 f2f4; s32 w2f8;
    u8 pad2fc[0x320 - 0x2fc]; s32 w320;
    u8 pad324[0x334 - 0x324]; f32 f334; f32 f338;
} DstData;
typedef struct { u8 pad0[0x43]; u8 b43; } X;
extern void func_00441C78(void *, s32, s32, s32);
void func_003BC870(void *a0, SrcData *a1) {
    SrcData *s;
    DstData *d;
    s = *(SrcData **)((u8 *)a1 + 0x68);
    d = *(DstData **)((u8 *)a0 + 0x68);
    d->w2f0 = s->w0;
    if (s->f4 > 0.0f) d->f2f4 = s->f4;
    d->w2f8 = s->w8;
    if (s->fc > 0.0f) d->f2f4 = s->fc;
    d->w320 = s->w14;
    if (s->f60 > 0.0f) d->f334 = s->f60;
    else d->f334 = 15.0f;
    if (s->f64 > 0.0f) d->f338 = s->f64;
    else d->f338 = 100.0f;
    if (((X *)a0)->b43 != 1) func_00441C78(a0, 1, 0, 0);
}
/* localdecomp:end func_003BC870 */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BC948);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BC960);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BC980);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BCA68);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BCB58);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BCB88);

/* localdecomp:start func_003BCC68 */
typedef int Q_3BCC68 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BCC68;
typedef struct { V4_3BCC68 r[4]; } M4_3BCC68;
typedef struct { f32 a, b; } P_3BCC68;
extern P_3BCC68 D_001DEB80[1];
extern s32 D_001DEBB0[2];
extern f32 D_001DEB70[2];
extern f32 D_001DEB60[2];
extern void func_00437698(void *, s32, void *);
extern void func_00437600(void *, s32, void *);
extern void func_0040C2F8(void *, void *, void *);
extern void func_0044E620(void *, s32, f32, f32);
void func_003BCC68(void *o) {
    V4_3BCC68 v;
    M4_3BCC68 m;
    V4_3BCC68 w;
    s32 i;
    for (i = 0; i < 3; i++) {
        Q_3BCC68 qa, qb, qr;
        func_00437698(o, 8, &v);
        func_00437600(o, 8, &m);
        func_0040C2F8(&w, &D_001DEB80[i * 2], &m);
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(w));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(v) : "j"(qr));
        func_0044E620(&v, D_001DEBB0[i], D_001DEB70[i], D_001DEB60[i]);
    }
}
/* localdecomp:end func_003BCC68 */

LINKER_REMNANT("asm/veldin/remnants", func_003BCD50);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BCD58);

LINKER_REMNANT("asm/veldin/remnants", func_003BD210);

