#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00133BB8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00133C58);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00133DF8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00134110);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001343C0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00134460);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001345A8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001346E8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001347D0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001347E0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001347F0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001349D8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001349E8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001349F8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00134BC8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00134C00);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00134C08);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00134D60);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00134D68);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00134DB8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00134E48);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00134EE0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00134FD4);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00134FD8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001350A8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001352E0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001353A8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135560);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135818);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135988);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135B50);

/* localdecomp:start func_00135C00 */
s32 func_00135C00(void) {
    return 1;
}
/* localdecomp:end func_00135C00 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00135C08);

/* localdecomp:start func_00135C10 */
typedef struct { u8 pad[0xC4]; s32 xC4; u8 pad2[0x24]; s32 xEC; s32 xF0; s32 xF4; s32 xF8; } T_135C10;
typedef struct { u8 pad[0x40]; T_135C10 *x40; } S_135C10;
extern void func_001353A8(S_135C10 *);
void func_00135C10(S_135C10 *p, u32 a, s32 b) {
    T_135C10 *q = p->x40;
    q->xC4 = 1;
    q->xEC = (a & 0x0FFFFFFF) | 0x20000000;
    q->xF8 = b;
    q->xF4 = 0;
    q->xF0 = 0;
    func_001353A8(p);
}
/* localdecomp:end func_00135C10 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00135C58);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135C60);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135CE0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135CF0);

LINKER_REMNANT("asm/boot_elf/remnants", func_00135D00);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135D08);

LINKER_REMNANT("asm/boot_elf/remnants", func_00135D40);

LINKER_REMNANT("asm/boot_elf/remnants", func_00135D48);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135D50);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135DC8);

/* localdecomp:start func_00135E40 */
typedef struct { u8 pad[0x184]; s32 x184; } T_135E40;
typedef struct { u8 pad[0x40]; T_135E40 *x40; } S_135E40;
extern void func_00135818(S_135E40 *, s32, s32);
extern void func_00135988(S_135E40 *, s32, s32);
void func_00135E40(S_135E40 *p, s32 b, s32 c) {
    if (p->x40->x184 != 3) {
        func_00135988(p, b, c);
    } else {
        func_00135818(p, b, c);
    }
}
/* localdecomp:end func_00135E40 */

/* localdecomp:start func_00135E88 */
typedef struct { u8 pad[0x28]; s32 x28; } C_135E88;
typedef struct { u8 pad[0x1C8]; C_135E88 *a0; C_135E88 *b0; u8 p1[8]; C_135E88 *a1; C_135E88 *b1; u8 p2[8]; C_135E88 *a2; C_135E88 *b2; } T_135E88;
typedef struct { u8 pad[0x40]; T_135E88 *x40; } S_135E88;
s32 func_00135E88(S_135E88 *p) {
    T_135E88 *q = p->x40;
    if (q->a0 != 0) q->a0->x28 = 0;
    if (q->a1 != 0) q->a1->x28 = 0;
    if (q->a2 != 0) q->a2->x28 = 0;
    if (q->b0 != 0) q->b0->x28 = 0;
    if (q->b1 != 0) q->b1->x28 = 0;
    if (q->b2 != 0) q->b2->x28 = 0;
    return 1;
}
/* localdecomp:end func_00135E88 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00135EE0);

LINKER_REMNANT("asm/boot_elf/remnants", func_00135F00);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135F08);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135FD4);

/* localdecomp:start func_00135FD8 */
void func_00135FD8(s32 *p, s32 a, s32 b) {
    p[1] = b;
    p[0] = a;
    p[2] = a;
    p[3] = a;
}
/* localdecomp:end func_00135FD8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135FF0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00136000);

/* localdecomp:start func_00136010 */
typedef struct { u32 x0; u32 x4; u32 x8; } S_136010;
extern s32 func_0013A0F8();
extern char D_00152178[];
u32 func_00136010(s32 a, S_136010 *s, u32 c, u32 al) {
    u32 off = (s->x8 + al - 1) / al * al;
    if (s->x0 + s->x4 < off + c) {
        func_0013A0F8(a, D_00152178);
        return 0;
    }
    s->x8 = off + c;
    return off;
}
/* localdecomp:end func_00136010 */

/* localdecomp:start func_00136080 */
typedef struct { u8 pad[0x40]; u8 *x40; } S_136080;
extern void func_0013A280(u8 *);
s32 func_00136080(S_136080 *p) {
    func_0013A280(p->x40 + 0x68);
    return 1;
}
/* localdecomp:end func_00136080 */

/* localdecomp:start func_001360A8 */
typedef struct { u8 pad[0x40]; u8 *x40; } S_1360A8;
extern void func_0013A368(u8 *);
s32 func_001360A8(S_1360A8 *p) {
    func_0013A368(p->x40 + 0x68);
    return 1;
}
/* localdecomp:end func_001360A8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001360CC);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001360D0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00136360);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00136620);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00136A40);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00136B00);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00136B90);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00136D50);

ASM_FUNC("asm/boot_elf/handwritten", func_00137228);

ASM_FUNC("asm/boot_elf/handwritten", func_00137370);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00137444);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00137450);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00137620);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00137CC8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00139A70);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00139E50);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00139F80);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00139F90);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013A030);

/* localdecomp:start func_0013A0F8 */
typedef struct { u8 pad[0xC]; s32 xC; u8 pad2[0x858]; s32 x868; } S_13A0F8;
extern s32 func_00135D50(s32, s32 *);
extern s32 func_00139F80(s32);
s32 func_0013A0F8(S_13A0F8 *p, s32 b) {
    s32 q = p->x868;
    if (q != 0 && p != 0 && p->xC != 0) {
        s32 buf[2];
        buf[1] = b;
        buf[0] = 0;
        return func_00135D50(q, buf);
    }
    return func_00139F80(b);
}
/* localdecomp:end func_0013A0F8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013A150);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013A190);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013A208);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013A280);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013A368);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013A4B8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013A520);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013A598);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013A7D0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013A840);

/* localdecomp:start func_0013A880 */
extern s32 func_0013A840(void);
extern void func_0011EED0(u32 *);
extern u8 D_00141834[];
s32 func_0013A880(void) {
    u32 buf[4];
    s32 r;
    func_0011EED0(buf);
    if (func_0013A840() != 0) {
        r = D_00141834[0];
    } else {
        func_0011EED0(buf);
        if (((buf[0] >> 13) & 7) == 0) {
            r = (buf[0] >> 4) & 1;
        } else {
            r = (buf[0] >> 16) & 0x1F;
        }
    }
    return r;
}
/* localdecomp:end func_0013A880 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013A8E0);

/* localdecomp:start func_0013A8E8 */
extern s32 func_0013A840(void);
extern void func_0011EED0(u32 *);
extern u8 D_00141832[];
s32 func_0013A8E8(void) {
    u32 buf[4];
    if (func_0013A840() == 0) {
        func_0011EED0(buf);
        return (buf[0] >> 1) & 3;
    }
    return D_00141832[0];
}
/* localdecomp:end func_0013A8E8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013A928);

/* localdecomp:start func_0013A930 */
extern s16 D_00141830[];
extern s32 func_0013A840(void);
extern void func_0011EED0(u32 *);
s32 func_0013A930(void) {
 u32 buf[4];
s32 r; if (func_0013A840() != 0) { r = D_00141830[0]; } else { func_0011EED0(buf); r = (s32)buf[0] >> 21; if (((buf[0] >> 13) & 7) == 0) { r = 0x21C; } } return r;
}
/* localdecomp:end func_0013A930 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013A980);

/* localdecomp:start func_0013A988 */
extern s32 func_0013A840(void);
extern void func_0011EED0(u32 *);
extern s32 func_0011F130(u8 *, s32, s32);
extern u8 D_00141836[];
s32 func_0013A988(void) {
    u32 buf[4];
    s32 r;
    if (func_0013A840() != 0) {
        r = D_00141836[0];
    } else {
        func_0011EED0(buf);
        if (((buf[0] >> 13) & 7) == 0) {
            r = 0;
        } else {
            func_0011F130((u8 *)buf + 4, 1, 1);
            r = (((u8 *)buf)[4] >> 4) & 1;
        }
    }
    return r;
}
/* localdecomp:end func_0013A988 */

/* localdecomp:start func_0013A9F0 */
u8 func_0013A9F0(u8 a) {
    return (a / 10) * 6 + a;
}
/* localdecomp:end func_0013A9F0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013AA20);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013AA40);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013AAA8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013AB10);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013ABC8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013AC70);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013ACA0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013ACC8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013AD58);
TEXT_PADDING(2);

ASM_FUNC("asm/boot_elf/handwritten", func_0013ADA8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013AFE8);

ASM_FUNC("asm/boot_elf/handwritten", func_0013AFF0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013AFF8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013B0C8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013B208);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013B330);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013B3F8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013B620);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013B808);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013B810);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013B818);

/* localdecomp:start func_0013B8B0 */
extern s32 D_001D4DA4;
extern s32 *D_001D4DA0;
extern void func_0011F698(void *, void *);
void func_0013B8B0(s32 *p, s32 n) {
    D_001D4DA4 = n;
    D_001D4DA0 = p;
    p[n + 1] = 0;
    p[0] = 0;
    func_0011F698(p, (u8 *)p + 3);
    p = &p[n + 1];
    func_0011F698(p, (u8 *)p + 3);
}
/* localdecomp:end func_0013B8B0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013B910);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013B918);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013BAB8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013BC28);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013BC30);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013BD58);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013BEB0);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013BEC8);

/* localdecomp:start func_0013BED0 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013BED0(void) {
    return func_0013C578(0x8, 0, 0, 0, 0);
}
/* localdecomp:end func_0013BED0 */

/* localdecomp:start func_0013BF00 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013BF00(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x6, 4, buf, 0, 0);
}
/* localdecomp:end func_0013BF00 */

/* localdecomp:start func_0013BF30 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013BF30(s32 a, s32 b) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    return func_0013C578(0x9, 8, buf, 0, 0);
}
/* localdecomp:end func_0013BF30 */

/* localdecomp:start func_0013BF68 */
typedef struct { u8 b[0x18]; } V_13BF68;
typedef struct { s32 a; V_13BF68 v; } B_13BF68;
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013BF68(s32 a, V_13BF68 *p) {
    B_13BF68 buf;
    buf.a = a;
    if (p != 0) {
        buf.v = *p;
    } else {
        *(s32 *)&buf.v = -1;
    }
    return func_0013C578(0x60, 0x1C, &buf, 0, 0);
}
/* localdecomp:end func_0013BF68 */

/* localdecomp:start func_0013BFE0 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013BFE0(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0xB, 4, buf, 0, 0);
}
/* localdecomp:end func_0013BFE0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C010);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C020);

/* localdecomp:start func_0013C028 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013C028(s32 a, s32 b, s32 c) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    return func_0013C578(0x4E, 0xC, buf, 0, 0);
}
/* localdecomp:end func_0013C028 */

/* localdecomp:start func_0013C068 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013C068(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x64, 4, buf, 0, 0);
}
/* localdecomp:end func_0013C068 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C098);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C0B0);

/* localdecomp:start func_0013C0B8 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013C0B8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    s32 buf[6];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    buf[5] = f;
    return func_0013C578(0x11, 0x18, buf, g, h);
}
/* localdecomp:end func_0013C0B8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C100);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C110);

/* localdecomp:start func_0013C118 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013C118(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x15, 4, buf, 0, 0);
}
/* localdecomp:end func_0013C118 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C148);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C168);

/* localdecomp:start func_0013C170 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013C170(void) {
    return func_0013C578(0x18, 0, 0, 0, 0);
}
/* localdecomp:end func_0013C170 */

/* localdecomp:start func_0013C1A0 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013C1A0(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x16, 4, buf, 0, 0);
}
/* localdecomp:end func_0013C1A0 */

/* localdecomp:start func_0013C1D0 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013C1D0(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x17, 4, buf, 0, 0);
}
/* localdecomp:end func_0013C1D0 */

/* localdecomp:start func_0013C200 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013C200(s32 a, s32 b, s32 c) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x19, 4, buf, b, c);
}
/* localdecomp:end func_0013C200 */

/* localdecomp:start func_0013C230 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013C230(s32 a, s32 b, s32 c) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    return func_0013C578(0x1B, 0xC, buf, 0, 0);
}
/* localdecomp:end func_0013C230 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C270);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C298);

/* localdecomp:start func_0013C2A0 */
extern s32 func_0013C2C0(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_0013C2A0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    return func_0013C2C0(a, b, c, d, e, f, 0, 0);
}
/* localdecomp:end func_0013C2A0 */

/* localdecomp:start func_0013C2C0 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013C2C0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    s32 buf[6];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    buf[5] = f;
    return func_0013C578(0x21, 0x18, buf, g, h);
}
/* localdecomp:end func_0013C2C0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C308);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C340);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013C348);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013C578);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013C8D0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013C908);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013CA20);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013CA28);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013CA30);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CAD8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CAE0);

/* localdecomp:start func_0013CAE8 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013CAE8(void) {
    return func_0013C578(0x34, 0, 0, 0, 0);
}
/* localdecomp:end func_0013CAE8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CB18);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013CB20);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CC00);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CC08);

/* localdecomp:start func_0013CC10 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013CC10(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x2D, 4, buf, 0, 0);
}
/* localdecomp:end func_0013CC10 */

/* localdecomp:start func_0013CC40 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013CC40(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x2E, 4, buf, 0, 0);
}
/* localdecomp:end func_0013CC40 */

/* localdecomp:start func_0013CC70 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013CC70(s32 a, s32 b, s32 c) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x30, 4, buf, b, c);
}
/* localdecomp:end func_0013CC70 */

/* localdecomp:start func_0013CCA0 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013CCA0(s32 a, s32 b, s32 c) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x32, 4, buf, b, c);
}
/* localdecomp:end func_0013CCA0 */

/* localdecomp:start func_0013CCD0 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013CCD0(s32 a, s32 b, s32 c) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x4F, 4, buf, b, c);
}
/* localdecomp:end func_0013CCD0 */

/* localdecomp:start func_0013CD00 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013CD00(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C348(0x36, 4, buf);
}
/* localdecomp:end func_0013CD00 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013CD28);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013CDF0);

/* localdecomp:start func_0013CEB0 */
extern s32 D_001D4DAC;
extern s32 func_0013C578(s32, s32, void *, s32, s32);
extern s32 func_0012BC98(void);
s32 func_0013CEB0(void) {
    if (D_001D4DAC == 0) {
        return func_0012BC98();
    }
    func_0013C578(0x37, 0, 0, 0, 0);
    return 1;
}
/* localdecomp:end func_0013CEB0 */

/* localdecomp:start func_0013CEF8 */
extern s32 D_001D4DAC;
extern s32 D_1D4990[];
extern s32 func_0012BC00(void);
s32 func_0013CEF8(void) {
    if (D_001D4DAC == 0) {
        return func_0012BC00();
    }
    return D_1D4990[0];
}
/* localdecomp:end func_0013CEF8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CF30);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CF38);

/* localdecomp:start func_0013CF40 */
extern s32 D_001D4DAC;
extern s32 D_001D4DB0;
extern s32 func_0012AA78(s32);
s32 func_0013CF40(s32 a) {
    s32 old;
    if (D_001D4DAC == 0) {
        return func_0012AA78(a);
    }
    old = D_001D4DB0;
    D_001D4DB0 = a;
    return old;
}
/* localdecomp:end func_0013CF40 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CF70);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CF78);

/* localdecomp:start func_0013CF80 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013CF80(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 buf[5];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    return func_0013C578(0x50, 0x14, buf, 0, 0);
}
/* localdecomp:end func_0013CF80 */

/* localdecomp:start func_0013CFC0 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013CFC0(s32 a, s32 b) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    return func_0013C578(0x51, 8, buf, 0, 0);
}
/* localdecomp:end func_0013CFC0 */

/* localdecomp:start func_0013CFF8 */
extern s32 func_0013C578(s32, s32, void *, s32, s32);
s32 func_0013CFF8(s32 a, s32 b, s32 c, s32 d) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    return func_0013C578(0x10, 0x10, buf, 0, 0);
}
/* localdecomp:end func_0013CFF8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D038);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D078);

/* localdecomp:start func_0013D080 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D080(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 buf[6];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    buf[5] = f;
    return func_0013C348(0x3B, 0x18, buf);
}
/* localdecomp:end func_0013D080 */

/* localdecomp:start func_0013D0C0 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D0C0(void) {
    return func_0013C348(0x3D, 0, 0);
}
/* localdecomp:end func_0013D0C0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D0E8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D0F0);

/* localdecomp:start func_0013D0F8 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D0F8(void) {
    return func_0013C348(0x3C, 0, 0);
}
/* localdecomp:end func_0013D0F8 */

/* localdecomp:start func_0013D120 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D120(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 buf[5];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    return func_0013C348(0x3E, 0x14, buf);
}
/* localdecomp:end func_0013D120 */

/* localdecomp:start func_0013D158 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D158(void) {
    return func_0013C348(0x40, 0, 0);
}
/* localdecomp:end func_0013D158 */

/* localdecomp:start func_0013D180 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D180(s32 a, s32 b) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    return func_0013C348(0x5A, 8, buf);
}
/* localdecomp:end func_0013D180 */

/* localdecomp:start func_0013D1B0 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D1B0(void) {
    return func_0013C348(0x5B, 0, 0);
}
/* localdecomp:end func_0013D1B0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D1D8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D1E0);

/* localdecomp:start func_0013D1E8 */
s32 func_0013D1E8(s32 a) {
    return a * 0x5F4 / 0x2E5;
}
/* localdecomp:end func_0013D1E8 */

ASM_FUNC("asm/boot_elf/handwritten", func_0013D208);

/* localdecomp:start func_0013D258 */
void func_0013D258(u8 *d, u8 *s, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        d[i] = s[i];
    }
}
/* localdecomp:end func_0013D258 */

/* localdecomp:start func_0013D290 */
extern u8 D_001D52E0[];
extern void func_0013CD28(s32, s32, s32, u8 *);
extern void func_0013CA28(void);
extern s32 func_0013B620(void);
extern s32 func_0013CDF0(s32);
s32 func_0013D290(s32 a, s32 b, s32 c) {
    u8 buf[4];
    buf[0] = 0x20;
    buf[1] = D_001D52E0[0];
    buf[2] = 0;
    buf[3] = 0;
    func_0013CD28(a, b, c, buf);
    func_0013CA28();
    func_0013B620();
    return func_0013CDF0(0);
}
/* localdecomp:end func_0013D290 */

/* localdecomp:start func_0013D2E0 */
extern s32 func_0013D290(s32, s32, void *);
extern u8 D_160C40[];
s32 func_0013D2E0(void) {
    return func_0013D290(0x3E9, 0x10, D_160C40);
}
/* localdecomp:end func_0013D2E0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D308);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013D310);

/* localdecomp:start func_0013D3C0 */
extern s32 D_001D5458;
void func_0013D3C0(s32 a) {
    D_001D5458 = a;
}
/* localdecomp:end func_0013D3C0 */

/* localdecomp:start func_0013D3C8 */
extern s32 D_001D5458;
s32 func_0013D3C8(void) {
    return D_001D5458;
}
/* localdecomp:end func_0013D3C8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013D3D0);

ASM_FUNC("asm/boot_elf/handwritten", func_0013D3E0);
