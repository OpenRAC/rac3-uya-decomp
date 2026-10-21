#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BB130);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BB5B0);

/* localdecomp:start func_003BBDC0 */
typedef struct { char pad[0x43]; unsigned char s43; char pad2[0x54]; int w98; char pad3[0xe]; short saa; char pad4[0x155]; } O_3BBDC0;
typedef struct { char pad[0x324]; int a; int b; } B_3BBDC0;
extern O_3BBDC0 *D_001E009C_3BBDC0;
extern int D_001E00D8_3BBDC0;
extern short *D_0021DEA0_3BBDC0[];
extern void func_00441C78_3BBDC0(O_3BBDC0 *, int, int, int);
extern void func_0044CB08_3BBDC0(void *, O_3BBDC0 *, int, int);
void func_003BBDC0(void *a, B_3BBDC0 *b) {
    O_3BBDC0 *o;
    short *s;
    int n;
    if (b->a != -1) {
        o = (O_3BBDC0 *)((char *)D_001E009C_3BBDC0 + (b->a << 8));
        if (o->s43 != 5) func_00441C78_3BBDC0(o, 5, 0, 7);
        func_0044CB08_3BBDC0(a, o, 1, 0);
        o->w98 = 0;
    }
    if (b->b != -1) {
        n = 0;
        s = D_0021DEA0_3BBDC0[b->b];
        while ((b->b & 0xff) != 0xff && b->b <= D_001E00D8_3BBDC0 && s && (s[-1] >= 0 || s == D_0021DEA0_3BBDC0[b->b])) {
            o = (O_3BBDC0 *)((char *)D_001E009C_3BBDC0 + ((*s & 0x7fff) << 8));
            if (!o) break;
            {
                switch (o->saa) {
                case 0x16bd:
                    if (o->s43 != 0) func_00441C78_3BBDC0(o, 0, 0, 7);
                    break;
                case 0x16e4:
                    if (o->s43 != 5) func_00441C78_3BBDC0(o, 5, 0, 7);
                    break;
                }
                if (o->saa == 0x16bd || o->saa == 0x16e4) {
                    func_0044CB08_3BBDC0(a, o, n + 2, 0);
                    n++;
                    o->w98 = 0;
                }
            }
            s++;
        }
    }
}
/* localdecomp:end func_003BBDC0 */

/* localdecomp:start func_003BBF90 */
typedef struct { char p0[0x18]; float f18; char p1[4]; unsigned char b20; char p2[0x47]; char *p68; char p3[0x29]; unsigned char b95; } A_3BBF90;
typedef struct { char p0[0x18]; float f18; } B_3BBF90;
typedef struct S_3BBF90 {
    char p0[0x30]; float f30; char p1[0xa]; unsigned char b3e; char p2[0x20]; unsigned char b5f; char p3[6]; short h66;
    char p4[0xf8]; char r160[0x190]; int w2f0; float f2f4; int w2f8; float f2fc; char p6[0x20]; int w320;
} S_3BBF90;
extern B_3BBF90 *D_0021F740_3BBF90[];
extern int func_003BC160_3BBF90(void);
extern int func_0044FCD0_3BBF90(A_3BBF90 *, void *, int, int, int);
extern void func_003BBDC0_3BBF90(A_3BBF90 *, S_3BBF90 *);
extern void func_003BC440_3BBF90(A_3BBF90 *, int);
extern void func_004538E0_3BBF90(A_3BBF90 *, int);
extern void func_004539A8_3BBF90(A_3BBF90 *, int, int, int, int, int, int, int, int, int, float, float, float);
int func_003BBF90(A_3BBF90 *a) {
    S_3BBF90 *s = (S_3BBF90 *)a->p68;
    if (a->b20 == 0 && func_003BC160_3BBF90()) return 1;
    if (func_0044FCD0_3BBF90(a, s->r160, 0, 0, 0)) {
        if (s->h66 < 3) s->h66++;
    }
    if (0.0f < s->f30) func_003BBDC0_3BBF90(a, s);
    if (s->b3e == 2) func_003BC440_3BBF90(a, 1);
    if (s->b5f) func_004538E0_3BBF90(a, 5); else func_004538E0_3BBF90(a, 3);
    if (s->w320 != -1) a->f18 = D_0021F740_3BBF90[s->w320]->f18;
    if (s->b5f) {
        if (a->b95 == 0) func_004539A8_3BBF90(a, s->w2f0, 0, 0, 0, 0, 3, 0, 0, 0, s->f2f4, 10.0f, 1.0f);
        else func_004539A8_3BBF90(a, s->w2f8, 0, 0, 0, 0, 3, 0, 0, 0, s->f2fc, 10.0f, 1.0f);
    } else {
        func_004539A8_3BBF90(a, s->w2f8, 0, 0, 0, 0, 1, 0, 0, 0, s->f2fc, 10.0f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_003BBF90 */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BC160);

/* localdecomp:start func_003BC440 */
typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
    char pad8[8];
    void (*f10)(void *);
} VT_3BC440;
typedef struct {
    char p0[0x240]; int w240; char p1[0xe0]; int w324; int w328;
} S_3BC440;
extern char *D_001E009C_3BC440;
extern int D_001E00D8_3BC440;
extern short *D_0021DEA0_3BC440[];
extern VT_3BC440 *func_00438468_3BC440(int, int);
extern int func_00438880_3BC440(int);
extern int func_00438850_3BC440(int);
extern void func_00436220_3BC440(void *);

void func_003BC440(A_3BBF90 *a, int arg1) {
    S_3BC440 *s = (S_3BC440 *)a->p68;
    short *p;
    char *obj;
    if (s->w240) {
        VT_3BC440 *vt = func_00438468_3BC440(0x19E1, 0x6C);
        if (s->w324 != -1) {
            vt->f10(D_001E009C_3BC440 + (s->w324 << 8));
            s->w324 = -1;
        }
        if (s->w328 != -1) {
            if (func_00438880_3BC440(s->w328)) {
                while (!func_00438850_3BC440(s->w328)) {
                    vt->f10(D_001E009C_3BC440 + ((*D_0021DEA0_3BC440[s->w328] & 0x7FFF) << 8));
                }
                s->w328 = -1;
            } else {
                p = D_0021DEA0_3BC440[s->w328];
                while ((s->w328 & 0xFF) != 0xFF && s->w328 <= D_001E00D8_3BC440 && p != 0
                       && (p[-1] >= 0 || p == D_0021DEA0_3BC440[s->w328])) {
                    obj = D_001E009C_3BC440 + ((*p & 0x7FFF) << 8);
                    if (obj == 0) break;
                    p++;
                    vt->f10(obj);
                }
                s->w328 = -1;
            }
        }
        vt->f0(a);
        if (arg1) vt->f4(a);
    } else {
        if (s->w324 != -1) func_00436220_3BC440(D_001E009C_3BC440 + (s->w324 << 8));
        if (s->w328 != -1) {
            p = D_0021DEA0_3BC440[s->w328];
            while ((s->w328 & 0xFF) != 0xFF && s->w328 <= D_001E00D8_3BC440 && p != 0
                   && (p[-1] >= 0 || p == D_0021DEA0_3BC440[s->w328])) {
                obj = D_001E009C_3BC440 + ((*p & 0x7FFF) << 8);
                if (obj == 0) break;
                p++;
                func_00436220_3BC440(obj);
            }
        }
        func_00436220_3BC440(a);
    }
}
/* localdecomp:end func_003BC440 */

LINKER_REMNANT("asm/veldin/remnants", func_003BC6C0);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BC6C8);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BC750);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BC850);

/* localdecomp:start func_003BC870 */
typedef struct { s32 w0; f32 f4; s32 w8; f32 fc; s32 w10; s32 w14; u8 pad18[0x60 - 0x18]; f32 f60; f32 f64; } SrcData_3BC870;
typedef struct {
    u8 pad0[0x2f0]; s32 w2f0; f32 f2f4; s32 w2f8;
    u8 pad2fc[0x320 - 0x2fc]; s32 w320;
    u8 pad324[0x334 - 0x324]; f32 f334; f32 f338;
} DstData_3BC870;
typedef struct { u8 pad0[0x43]; u8 b43; } X_3BC870;
extern void func_00441C78_3BC870(void *, s32, s32, s32);
void func_003BC870(void *a0, SrcData_3BC870 *a1) {
    SrcData_3BC870 *s;
    DstData_3BC870 *d;
    s = *(SrcData_3BC870 **)((u8 *)a1 + 0x68);
    d = *(DstData_3BC870 **)((u8 *)a0 + 0x68);
    d->w2f0 = s->w0;
    if (s->f4 > 0.0f) d->f2f4 = s->f4;
    d->w2f8 = s->w8;
    if (s->fc > 0.0f) d->f2f4 = s->fc;
    d->w320 = s->w14;
    if (s->f60 > 0.0f) d->f334 = s->f60;
    else d->f334 = 15.0f;
    if (s->f64 > 0.0f) d->f338 = s->f64;
    else d->f338 = 100.0f;
    if (((X_3BC870 *)a0)->b43 != 1) func_00441C78_3BC870(a0, 1, 0, 0);
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
extern P_3BCC68 D_001DEB80_3BCC68[1];
extern s32 D_001DEBB0_3BCC68[2];
extern f32 D_001DEB70_3BCC68[2];
extern f32 D_001DEB60_3BCC68[2];
extern void func_00437698_3BCC68(void *, s32, void *);
extern void func_00437600_3BCC68(void *, s32, void *);
extern void func_0040C2F8_3BCC68(void *, void *, void *);
extern void func_0044E620_3BCC68(void *, s32, f32, f32);
void func_003BCC68(void *o) {
    V4_3BCC68 v;
    M4_3BCC68 m;
    V4_3BCC68 w;
    s32 i;
    for (i = 0; i < 3; i++) {
        Q_3BCC68 qa, qb, qr;
        func_00437698_3BCC68(o, 8, &v);
        func_00437600_3BCC68(o, 8, &m);
        func_0040C2F8_3BCC68(&w, &D_001DEB80_3BCC68[i * 2], &m);
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(w));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(v) : "j"(qr));
        func_0044E620_3BCC68(&v, D_001DEBB0_3BCC68[i], D_001DEB70_3BCC68[i], D_001DEB60_3BCC68[i]);
    }
}
/* localdecomp:end func_003BCC68 */

LINKER_REMNANT("asm/veldin/remnants", func_003BCD50);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003BCD58);

LINKER_REMNANT("asm/veldin/remnants", func_003BD210);

