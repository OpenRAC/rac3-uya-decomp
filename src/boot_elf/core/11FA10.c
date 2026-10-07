#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011FA10);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011FAE8);

ASM_FUNC("asm/boot_elf/handwritten", func_0011FBD8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0011FC70);

ASM_FUNC("asm/boot_elf/handwritten", func_0011FC78);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011FD40);

ASM_FUNC("asm/boot_elf/handwritten", func_0011FEB8);

/* localdecomp:start func_0011FEE0 */
extern s32 func_0011F250(s32, s32 *);
extern u8 D_152C10[];
s32 func_0011FEE0(u16 a, s32 b, s32 c) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = (s32)D_152C10 | 0x20000000;
    return func_0011F250(1, buf);
}
/* localdecomp:end func_0011FEE0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0011FF28);

/* localdecomp:start func_0011FF30 */
extern s32 func_0011F250(s32, s32 *);
s32 func_0011FF30(s32 a, s8 b) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    return func_0011F250(3, buf);
}
/* localdecomp:end func_0011FF30 */

/* localdecomp:start func_0011FF60 */
extern s32 func_0011F250(s32, s32 *);
s32 func_0011FF60(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0011F250(4, buf);
}
/* localdecomp:end func_0011FF60 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0011FF88);

/* localdecomp:start func_0011FF90 */
extern s32 func_0011F250(s32, s32 *);
s32 func_0011FF90(s32 a, s32 b, u16 c) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    return func_0011F250(-5, buf);
}
/* localdecomp:end func_0011FF90 */

/* localdecomp:start func_0011FFC8 */
extern s32 func_0011F250(s32, s32 *);
s32 func_0011FFC8(s32 a, s32 b, u16 c) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    return func_0011F250(-6, buf);
}
/* localdecomp:end func_0011FFC8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00120000);

LINKER_REMNANT("asm/boot_elf/remnants", func_00120008);

/* localdecomp:start func_00120010 */
extern s32 func_0011F250(s32, s32 *);
s32 func_00120010(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0011F250(0x10, buf);
}
/* localdecomp:end func_00120010 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00120034);

/* localdecomp:start func_00120038 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; u8 x10[0x10]; } S_120038;
extern S_120038 D_152C40;
S_120038 *func_00120038(s32 a) {
    D_152C40.x0 = a;
    D_152C40.x4 = 0;
    D_152C40.xC = (s32)D_152C40.x10;
    D_152C40.x8 = (s32)D_152C40.x10;
    return &D_152C40;
}
/* localdecomp:end func_00120038 */

/* localdecomp:start func_00120060 */
typedef struct { s32 size; s32 count; u8 *rd; u8 *wr; u8 buf[1]; } R_120060;
void func_00120060(R_120060 *p) {
    p->count++;
    p->wr++;
    if (p->wr == p->buf + p->size) {
        p->wr = p->buf;
    }
}
/* localdecomp:end func_00120060 */

/* localdecomp:start func_001200A0 */
typedef struct { s32 size; s32 count; u8 *rd; u8 *wr; u8 buf[1]; } R_1200A0;
void func_001200A0(R_1200A0 *p) {
    p->count--;
    p->rd++;
    if (p->rd == p->buf + p->size) {
        p->rd = p->buf;
    }
}
/* localdecomp:end func_001200A0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001200E0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00120278);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001203F0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001204C0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012057C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00120580);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001205B8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00120668);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001206A0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00120730);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00120908);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00121620);

/* localdecomp:start func_00121678 */
extern void func_001205B8(s32);
s32 func_00121678(s32 a, s32 b, s32 c) {
    if (c != 0) {
        func_001205B8(c);
    }
    return 1;
}
/* localdecomp:end func_00121678 */

/* localdecomp:start func_001216A0 */
extern void func_00120668(s32);
s32 func_001216A0(s32 a, s32 b, s32 c) {
    if (c != 0) {
        func_00120668(c);
    }
    return 1;
}
/* localdecomp:end func_001216A0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001216C8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00121718);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00121760);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001217E0);

/* localdecomp:start func_00121860 */
typedef struct { u8 pad[0x10]; s32 x10; s32 x14; } A_121860;
typedef struct { u8 pad[0x1C]; s32 *x1C; } B_121860;
void func_00121860(A_121860 *a, B_121860 *b) {
    b->x1C[a->x10] = a->x14;
}
/* localdecomp:end func_00121860 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00121880);

/* localdecomp:start func_00121890 */
extern s32 D_153300[];
s32 func_00121890(s32 i) {
    return D_153300[i];
}
/* localdecomp:end func_00121890 */

LINKER_REMNANT("asm/boot_elf/remnants", func_001218A8);

LINKER_REMNANT("asm/boot_elf/remnants", func_001218B0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001218B8);

/* localdecomp:start func_00121B38 */
extern s32 func_0011F940(s32);
extern s32 func_0011EB50(s32, s32);
extern s32 D_153154[];
extern s32 D_0013DBF8[];
void func_00121B38(void) {
    func_0011F940(5);
    func_0011EB50(5, D_153154[0]);
    D_0013DBF8[0] = 0;
}
/* localdecomp:end func_00121B38 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00121B70);

/* localdecomp:start func_00121BE8 */
typedef struct { s32 a; s32 b; s32 c; } E_121BE8;
extern E_121BE8 *D_153164[];
extern E_121BE8 *D_15316C[];
void func_00121BE8(s32 i) {
    if (i < 0) {
        D_153164[0][i & 0x7FFFFFFF].a = 0;
    } else {
        D_15316C[0][i].a = 0;
    }
}
/* localdecomp:end func_00121BE8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00121C38);

/* localdecomp:start func_00121D70 */
extern s32 func_00121C38(s32, s32, s32, s32, s32, s32, s32);
s32 func_00121D70(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 r;
    r = func_00121C38(a, 0, b, c, d, e, f);
    do {
    } while (0);
    return r;
}
/* localdecomp:end func_00121D70 */

/* localdecomp:start func_00121DB0 */
extern s32 func_00121C38(s32, s32, s32, s32, s32, s32, s32);
s32 func_00121DB0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 r;
    r = func_00121C38(a, 1, b, c, d, e, f);
    do {
    } while (0);
    return r;
}
/* localdecomp:end func_00121DB0 */

ASM_FUNC("asm/boot_elf/handwritten", func_00121DF0);

ASM_FUNC("asm/boot_elf/handwritten", func_00121F38);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00121FE4);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00121FE8);

/* localdecomp:start func_00122188 */
extern void func_00121B38(void);
extern s32 D_0013DBFC[];
void func_00122188(void) {
    func_00121B38();
    D_0013DBFC[0] = 0;
}
/* localdecomp:end func_00122188 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001221B0);

/* localdecomp:start func_00122258 */
typedef struct { u8 pad[0x10]; u32 x10; s32 x14; s32 x18; } S_122258;
void func_00122258(S_122258 *p) {
    p->x18 = 0;
    p->x10 &= ~1;
}
/* localdecomp:end func_00122258 */

/* localdecomp:start func_00122278 */
typedef struct { u8 pad[0x14]; s32 x14; s32 x18; u8 pad2[8]; s32 x24; } S_122278;
s32 func_00122278(S_122278 *p) {
    s32 i = p->x24 % p->x18;
    s32 r = p->x14 + i * 64;
    p->x24 = i + 1;
    return r;
}
/* localdecomp:end func_00122278 */

/* localdecomp:start func_001222A8 */
typedef struct { u8 pad[0x1C]; u8 *x1C; s32 x20; } S_1222A8;
s32 func_001222A8(S_1222A8 *p, s32 i) {
    if (i < 0 || i >= p->x20) {
        return func_00122278((S_122278 *)p);
    }
    return (s32)(p->x1C + (i << 6));
}
/* localdecomp:end func_001222A8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001222E8);

/* localdecomp:start func_001223B8 */
typedef struct { u8 pad[0x24]; s32 x24; s32 x28; s32 x2C; } S_1223B8;
extern s32 func_00121DB0(s32, s32, s32, s32, s32, s32);
s32 func_001223B8(s32 a, s32 b, s32 c, S_1223B8 *d) {
    s32 r;
    if (func_00121DB0(0x80000008, (s32)d, 0x40, d->x24, d->x28, d->x2C) != 0) {
        r = 0;
    } else {
        r = 0x800;
    }
    return r;
}
/* localdecomp:end func_001223B8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001223F8);

LINKER_REMNANT("asm/boot_elf/remnants", func_001224C8);

/* localdecomp:start func_001224D0 */
typedef struct U_1224D0 { s32 x0; u8 pad[0x34]; struct U_1224D0 *x38; } U_1224D0;
typedef struct T_1224D0 { u8 pad[8]; U_1224D0 *x8; u8 pad2[8]; struct T_1224D0 *x14; } T_1224D0;
typedef struct { u8 pad[0x28]; T_1224D0 *x28; } S_1224D0;
U_1224D0 *func_001224D0(s32 key, S_1224D0 *p) {
    T_1224D0 *t;
    U_1224D0 *u;
    for (t = p->x28; t != 0; t = t->x14) {
        for (u = t->x8; u != 0; u = u->x38) {
            if (u->x0 == key) {
                return u;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_001224D0 */

/* localdecomp:start func_00122520 */
extern s32 func_00121DB0(s32, s32, s32, s32, s32, s32);
s32 func_00122520(s32 a, s32 b, s32 c, s32 d) {
    s32 r;
    if (func_00121DB0(0x80000008, d, 0x40, 0, 0, 0) != 0) {
        r = 0;
    } else {
        r = 0x800;
    }
    return r;
}
/* localdecomp:end func_00122520 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00122560);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00122630);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00122780);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00122810);

/* localdecomp:start func_00122A10 */
typedef struct { u8 pad[0x10]; s32 x10; u8 pad2[4]; s32 x18; } T_122A10;
typedef struct { T_122A10 *x0; s32 x4; } S_122A10;
s32 func_00122A10(S_122A10 *p) {
    T_122A10 *q = p->x0;
    if (q == 0 || p->x4 != q->x18 || !(q->x10 & 1)) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_00122A10 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00122A50);

LINKER_REMNANT("asm/boot_elf/remnants", func_00122A60);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00122A68);

LINKER_REMNANT("asm/boot_elf/remnants", func_00122AD8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00122AE0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00122B68);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00122C58);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00122CC8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123080);

/* localdecomp:start func_001230D8 */
extern void func_00123080(void);
extern void func_0011EE60(s32);
extern s32 D_0013DC8C[];
s32 func_001230D8(void) {
    func_00123080();
    func_0011EE60(D_0013DC8C[0]);
    return 0;
}
/* localdecomp:end func_001230D8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123108);

ASM_FUNC("asm/boot_elf/handwritten", func_00123118);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123160);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123368);

/* localdecomp:start func_001233F8 */
extern s32 func_0011A264(s32, s32, s32);
extern s32 D_0013DC84[];
extern u8 D_156328[];
s32 func_001233F8(void) {
    D_0013DC84[0] = 0;
    ((void (*)(void *, s32, s32))func_0011A264)(D_156328, 0, 4);
    return 0;
}
/* localdecomp:end func_001233F8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123430);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001236C0);

LINKER_REMNANT("asm/boot_elf/remnants", func_00123838);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123840);

LINKER_REMNANT("asm/boot_elf/remnants", func_00123AB0);

LINKER_REMNANT("asm/boot_elf/remnants", func_00123B08);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123B10);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123B98);

LINKER_REMNANT("asm/boot_elf/remnants", func_00123C18);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123C20);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123C90);

LINKER_REMNANT("asm/boot_elf/remnants", func_00123D00);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123D08);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123D10);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123E10);

/* localdecomp:start func_00123EA0 */
extern s32 func_0011A264(s32, s32, s32);
extern s32 D_0013DCA0[];
extern u8 D_1567E8[];
s32 func_00123EA0(void) {
    D_0013DCA0[0] = -1;
    ((void (*)(void *, s32, s32))func_0011A264)(D_1567E8, 0, 4);
    return 0;
}
/* localdecomp:end func_00123EA0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123ED8);

/* localdecomp:start func_001240E0 */
extern s32 func_00123ED8(s32, s32, s32, s32 *);
s32 func_001240E0(s32 a, s32 b, s32 c) {
    s32 buf[4];
    return func_00123ED8(a, b, c, buf);
}
/* localdecomp:end func_001240E0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00124100);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124130);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124138);

/* localdecomp:start func_00124290 */
extern u32 func_0011F230(s32);
s32 func_00124290(void) {
    u32 r = func_0011F230(4) & 0x10000;
    return r != 0;
}
/* localdecomp:end func_00124290 */

/* localdecomp:start func_001242B8 */
extern u32 func_0011F230(s32);
extern void func_0011F2A0(void);
extern void func_00125F70(s32, s32);
s32 func_001242B8(void) {
    if (func_0011F230(4) & 0x40000) {
        func_0011F2A0();
        func_00125F70(1, 1);
        func_00125F70(0, 1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_001242B8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124308);

LINKER_REMNANT("asm/boot_elf/remnants", func_00124418);

ASM_FUNC("asm/boot_elf/handwritten", func_00124420);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124430);

ASM_FUNC("asm/boot_elf/handwritten", func_00124468);

ASM_FUNC("asm/boot_elf/handwritten", func_00124478);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124488);

ASM_FUNC("asm/boot_elf/handwritten", func_00124550);

/* localdecomp:start func_00124560 */
extern s32 func_0011F280(void);
extern void func_001245A0(void);
extern void func_0011F290(void);
void func_00124560(void) {
    if (func_0011F280() == 0x2000000) {
        func_001245A0();
    } else {
        func_0011F290();
    }
}
/* localdecomp:end func_00124560 */
