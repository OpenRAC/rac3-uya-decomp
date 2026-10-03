#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003ECDC0(s32, s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern s32 func_003ECDB8();
extern char D_001D8160[];
extern void func_003A53B0();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003A5478 */
extern char D_001D8160[];
extern void func_003A53B0();
void func_003A5478(u8 *p) {
    *(void **)(p + 4) = D_001D8160;
    func_003A53B0(p);
}
/* localdecomp:end func_003A5478 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A54A0);

/* localdecomp:start func_003A5608 */
extern u8 D_001D8178[];

void func_003A5608(void *a0) {
    register void *dest __asm__("$2");    // $v0 ($2)
    register s32 val __asm__("$3");       // $v1 ($3)

    // Force the exact 64-bit move instruction (daddu) at offset 0.
    // This generates the exact machine code bytes for 0x0080102d.
    __asm__ volatile("daddu %0, %1, $0" : "=r"(dest) : "r"(a0));

    val = (s32)&D_001D8178;

    __asm__ volatile("" : : "r"(dest), "r"(val));

    *(s32 *)dest = val;
}
/* localdecomp:end func_003A5608 */

/* localdecomp:start func_003A5620 */
extern u8 D_001D8178[];
extern s32 func_003ECDB8();
void func_003A5620(void **p, s32 f) { *p = D_001D8178; if (f & 1) func_003ECDB8(p); }
/* localdecomp:end func_003A5620 */

/* localdecomp:start func_003A5650 */
void func_003A5650(s32 unused, f32 *out, f32 *a, f32 *b, f32 t) {
    f32 s = 1.0f - t;
    out[0] = s * a[0] + t * b[0];
    out[1] = s * a[1] + t * b[1];
    out[2] = s * a[2] + t * b[2];
    out[3] = s * a[3] + t * b[3];
}
/* localdecomp:end func_003A5650 */

/* localdecomp:start func_003A56C0 */
extern s32 func_003894A0(f32, s32, s32);
void func_003A56C0(f32 f, s32 x, s32 *out, s32 *a, s32 *b) {
    out[0] = func_003894A0(f, a[0], b[0]);
    out[1] = func_003894A0(f, a[1], b[1]);
    out[2] = func_003894A0(f, a[2], b[2]);
    out[3] = func_003894A0(f, a[3], b[3]);
}
/* localdecomp:end func_003A56C0 */

LINKER_REMNANT("asm/remnants", func_003A5750);

/* localdecomp:start func_003A5760 */
extern f32 func_003A9CF8(f32, f32, f32, f32, f32);
void func_003A5760(u8 *p, f32 *out, f32 t) {
    *out = func_003A9CF8(t, 0.0f, *(f32 *)(p + 8), *(f32 *)(p + 0xC), 1.0f);
}
/* localdecomp:end func_003A5760 */

LINKER_REMNANT("asm/remnants", func_003A57A0);

/* localdecomp:start func_003A57B0 */
extern u8 D_001D80E8[];
extern void func_003A69A0();
extern void func_003A53B0();
void func_003A57B0(u8 *p, s32 f) {
    *(void **)(p + 4) = D_001D80E8;
    func_003A69A0(*(void **)(p + 0x2C), *(s32 *)(p + 0x28));
    func_003A53B0(p, f);
}
/* localdecomp:end func_003A57B0 */

/* localdecomp:start func_003A5800 */
void func_003A5800(f32 *a, f32 *out, f32 t) {
    f32 s = 1.0f - t;
    out[0] = s * a[2] + t * a[3];
    out[1] = s * a[4] + t * a[5];
    out[2] = s * a[6] + t * a[7];
    out[3] = s * a[8] + t * a[9];
}
/* localdecomp:end func_003A5800 */

LINKER_REMNANT("asm/remnants", func_003A5870);

/* localdecomp:start func_003A5880 */
extern void func_003A53B0();
void func_003A5880(void) {
    func_003A53B0();
}
/* localdecomp:end func_003A5880 */

/* localdecomp:start func_003A58A0 */
extern void func_003A53B0();
void func_003A58A0(void) {
    func_003A53B0();
}
/* localdecomp:end func_003A58A0 */

extern s32 D_001D8118[];
extern void func_003A5620();
/* localdecomp:start func_003A58C0 */
extern s32 D_001D8118[2];
extern void func_003A5620();
void func_003A58C0(void **p, s32 f) {
    *p = D_001D8118;
    func_003A5620(p, f);
}
/* localdecomp:end func_003A58C0 */

extern s32 D_001D8100[];
extern void func_003A5620();
/* localdecomp:start func_003A58E0 */
extern s32 D_001D8100[2];
extern void func_003A5620();
void func_003A58E0(void **p, s32 f) {
    *p = D_001D8100;
    func_003A5620(p, f);
}
/* localdecomp:end func_003A58E0 */

/* localdecomp:start func_003A5900 */
extern s32 D_001DA0F0;
s32 func_003A5900(void) {
    return D_001DA0F0;
}
/* localdecomp:end func_003A5900 */

/* localdecomp:start func_003A5908 */
s32 func_003A5908(void *p) {
    return *(s32 *)((u8 *)p + 0x4);
}
/* localdecomp:end func_003A5908 */

/* localdecomp:start func_003A5910 */
s32 func_003A5910(void *p) {
    return *(s32 *)((u8 *)p + 0xC);
}
/* localdecomp:end func_003A5910 */

LINKER_REMNANT("asm/remnants", func_003A5918);

/* localdecomp:start func_003A5928 */
void func_003A5928(void *a0, f32 a1, f32 a2, f32 a3, f32 a4) {
    *(f32 *)((u8 *)(*(void **)a0) + 0) = a1;
    *(f32 *)((u8 *)(*(void **)a0) + 4) = a2;
    *(f32 *)((u8 *)(*(void **)a0) + 8) = a3;
    *(f32 *)((u8 *)(*(void **)a0) + 0xc) = a4;
}
/* localdecomp:end func_003A5928 */

LINKER_REMNANT("asm/remnants", func_003A5950);

/* localdecomp:start func_003A5958 */
void func_003A5958(void *a0, s32 a1) {
    s32 *v0 = *(s32 **)((u8 *)a0 + 0x10);
    if (a1 != 0) {
        *(f32 *)v0 = 1.0f;
    } else {
        *v0 = 0;
    }
}
/* localdecomp:end func_003A5958 */

/* localdecomp:start func_003A5978 */
typedef struct { s32 x0; s32 x4; u8 pad[0xD]; u8 b15; u8 pad2[0xA]; s32 x20; } S_3A5978;
extern void func_003A69A0();
void func_003A5978(S_3A5978 *p, s32 v) {
    if (v != p->x4) {
        if (p->x20 && !p->b15) {
            func_003A69A0(p->x20, p->x4);
            p->b15 = 1;
        }
        p->x4 = v;
    }
}
/* localdecomp:end func_003A5978 */

LINKER_REMNANT("asm/remnants", func_003A59E0);

/* localdecomp:start func_003A59E8 */
typedef struct { u8 pad[0x10]; s32 f10; u8 pad2[4]; u8 f18; u8 pad3[7]; s32 f20; } S_3A59E8;
extern void func_003A69A0();
void func_003A59E8(S_3A59E8 *s, s32 v) {
    if (v == s->f10) return;
    if (s->f20 != 0 && s->f18 == 0) {
        func_003A69A0(s->f20, s->f10);
        s->f18 = 1;
    }
    s->f10 = v;
}
/* localdecomp:end func_003A59E8 */

/* localdecomp:start func_003A5A50 */
void func_003A5A50(void *a0, f32 a1, f32 a2, f32 a3, f32 a4) {
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 0) = a1;
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 4) = a2;
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 8) = a3;
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 0xc) = a4;
}
/* localdecomp:end func_003A5A50 */

extern s32 D_001D8218[];
/* localdecomp:start func_003A5A78 */
extern s32 D_001D8218[];
u8 *func_003A5A78(u8 *p) { *(s32 **)(p + 0x24) = D_001D8218; return p; }
/* localdecomp:end func_003A5A78 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A5A90);

LINKER_REMNANT("asm/remnants", func_003A5BB8);

/* localdecomp:start func_003A5BC0 */
extern void func_003A69A0();
extern s32 func_003ECDB8();
extern s32 D_001D8218[];
void func_003A5BC0(u8 *p, s32 f) {
    *(s32 **)(p + 0x24) = D_001D8218;
    if (*(s32 *)(p + 0x20) != 0) {
        if (p[0x14] == 0) func_003A69A0(*(s32 *)(p + 0x20), *(s32 *)(p + 0));
        if (p[0x16] == 0) func_003A69A0(*(s32 *)(p + 0x20), *(s32 *)(p + 8));
        if (p[0x15] == 0) func_003A69A0(*(s32 *)(p + 0x20), *(s32 *)(p + 4));
        if (p[0x17] == 0) func_003A69A0(*(s32 *)(p + 0x20), *(s32 *)(p + 0xC));
    }
    if (f & 1) func_003ECDB8(p);
}
/* localdecomp:end func_003A5BC0 */

/* localdecomp:start func_003A5C70 */
extern u8 *func_003A5A78(u8 *);
extern u8 D_001D8200[];
u8 *func_003A5C70(u8 *p) {
    func_003A5A78(p);
    *(u8 **)(p + 0x24) = D_001D8200;
    return p;
}
/* localdecomp:end func_003A5C70 */

/* localdecomp:start func_003A5CA8 */
typedef struct {
    u8 pad0[4];
    f32 *values;
    u8 pad8[0x18];
    s32 source;
    u8 pad24[4];
    s32 *first;
    s32 *second;
    u8 pad30[8];
    u8 flag38;
    u8 flag39;
    u8 flag3A;
} Object_003A5CA8;

extern void func_003A5A90();
extern void *func_003A6910();
extern s32 func_003ECDC0(s32, s32);

void func_003A5CA8(Object_003A5CA8 *object) {
    s32 *allocation;
    s32 source;
    register f32 *values __asm__("$3");

    func_003A5A90(object);
    if (object->source != 0) {
        allocation = (s32 *)func_003ECDC0(0x10, (s32)func_003A6910(object->source));
        source = object->source;
        object->first = allocation;
        allocation[1] = 0;
        allocation[2] = 0;
        allocation[3] = 0;
        allocation[0] = 0;

        allocation = (s32 *)func_003ECDC0(0x10, (s32)func_003A6910(source));
        values = object->values;
        object->second = allocation;
        allocation[1] = 0;
        allocation[2] = 0;
        allocation[3] = 0;
        allocation[0] = 0;

        values[0] = 1.0f;
        object->values[1] = 1.0f;
        object->values[2] = 1.0f;
        object->flag3A = 0;
    } else {
        object->flag3A = 0;
    }
    object->flag39 = 0;
    object->flag38 = 0;
}
/* localdecomp:end func_003A5CA8 */

LINKER_REMNANT("asm/remnants", func_003A5D58);

/* localdecomp:start func_003A5D60 */
extern void func_003A5BC0();
extern void func_003A69A0();
extern s32 D_001D8200_003A5BC0;

void func_003A5D60(void *arg0, s32 arg1) {
    s32 temp_a0;

    (*(s32 **)((u8 *)(arg0) + 0x24)) = &D_001D8200_003A5BC0;
    temp_a0 = (*(s32 *)((u8 *)(arg0) + 0x20));
    if (temp_a0 != 0) {
        if ((*(u8 *)((u8 *)(arg0) + 0x38)) == 0) {
            func_003A69A0(temp_a0, (*(s32 *)((u8 *)(arg0) + 0x28)));
        }
        if ((*(u8 *)((u8 *)(arg0) + 0x39)) == 0) {
            func_003A69A0((*(s32 *)((u8 *)(arg0) + 0x20)), (*(s32 *)((u8 *)(arg0) + 0x2C)));
        }
    }
    func_003A5BC0(arg0, arg1);
}
/* localdecomp:end func_003A5D60 */

LINKER_REMNANT("asm/remnants", func_003A5DD8);

/* localdecomp:start func_003A5DE8 */
s32 func_003A5DE8(void *p) {
    return *(s32 *)((u8 *)p + 0x2C);
}
/* localdecomp:end func_003A5DE8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A5DF0);

/* localdecomp:start func_003A5E80 */
extern s32 func_003A6830(u8 *, s32);
void func_003A5E80(u8 *p, u8 *a, s32 b) {
    *(s32 *)(p + 0x34) = func_003A6830(a, b);
}
/* localdecomp:end func_003A5E80 */

/* localdecomp:start func_003A5EB0 */
void func_003A5EB0(void *p, f32 value) {
    **(f32 **)((u8 *)p + 0x2C) = value;
}
/* localdecomp:end func_003A5EB0 */

/* localdecomp:start func_003A5EC0 */
extern u8 *func_003A5A78(u8 *);
extern u8 D_001D81B8[];
u8 *func_003A5EC0(u8 *p) {
    func_003A5A78(p);
    *(u8 **)(p + 0x24) = D_001D81B8;
    return p;
}
/* localdecomp:end func_003A5EC0 */

/* localdecomp:start func_003A5EF8 */
typedef struct { u8 pad[0x28]; u8 b; u8 pad2[7]; s32 a; s32 c; s32 d; } S_3A5EF8;
extern void func_003A5A90();
void func_003A5EF8(S_3A5EF8 *s, s32 a, s32 b, s32 c, s32 d) {
    func_003A5A90(s, c, d);
    s->a = a;
    s->b = b;
    s->c = 100;
    s->d = 0x80000000;
}
/* localdecomp:end func_003A5EF8 */

LINKER_REMNANT("asm/remnants", func_003A5F58);

/* localdecomp:start func_003A5F60 */
extern u8 D_001D81B8[];
extern void func_003A5BC0();
void func_003A5F60(u8 *p) {
    *(void **)(p + 0x24) = D_001D81B8;
    func_003A5BC0(p);
}
/* localdecomp:end func_003A5F60 */

/* localdecomp:start func_003A5F88 */
void func_003A5F88(void *a0, s32 a1, s32 a2) {
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 0) = a1;
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 4) = a2;
}
/* localdecomp:end func_003A5F88 */

/* localdecomp:start func_003A5FA0 */
void func_003A5FA0(void *a0, s32 a1, s32 a2) {
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 8) = a1;
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 0xc) = a2;
}
/* localdecomp:end func_003A5FA0 */

LINKER_REMNANT("asm/remnants", func_003A5FB8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5FC8);

/* localdecomp:start func_003A6190 */
extern u8 *func_003A5A78(u8 *);
extern u8 D_001D81E8[];
u8 *func_003A6190(u8 *p) {
    func_003A5A78(p);
    *(u8 **)(p + 0x24) = D_001D81E8;
    return p;
}
/* localdecomp:end func_003A6190 */

LINKER_REMNANT("asm/remnants", func_003A61C8);

/* localdecomp:start func_003A61D0 */
void func_003A5A90();
void *func_003ECDC0_003A61D0(s32, void *);                  /* extern */

void func_003A61D0(void *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    func_003A5A90();
    if (arg2 != 0) {
        temp_v0 = func_003ECDC0_003A61D0(0x10, func_003A6910((*(s32 *)((u8 *)(arg0) + 0x20))));
        (*(void **)((u8 *)(arg0) + 0x28)) = temp_v0;
        (*(s32 *)((u8 *)(temp_v0) + 4)) = 0;
        (*(s32 *)((u8 *)(temp_v0) + 8)) = 0;
        (*(s32 *)((u8 *)(temp_v0) + 0xC)) = 0;
        (*(s32 *)((u8 *)(temp_v0) + 0)) = 0;
    }
    (*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x28))) + 0)) = 0;
    (*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x28))) + 4)) = 0;
    (*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0))) + 0)) = 100.0f;
    (*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0))) + 4)) = 100.0f;
    (*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 4))) + 0)) = 64.0f;
    (*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 4))) + 4)) = 64.0f;
    (*(s8 *)((u8 *)(arg0) + 0x2C)) = 0;
}
/* localdecomp:end func_003A61D0 */

/* localdecomp:start func_003A6278 */
s32 func_003A6278(void *p) {
    return *(s32 *)((u8 *)p + 0x28);
}
/* localdecomp:end func_003A6278 */

LINKER_REMNANT("asm/remnants", func_003A6280);

/* localdecomp:start func_003A6288 */
extern void func_003A5BC0();
extern void func_003A69A0();
extern s32 D_001D81E8_003A5BC0;

void func_003A6288(void *arg0, s32 arg1) {
    s32 temp_a0;

    (*(s32 **)((u8 *)(arg0) + 0x24)) = &D_001D81E8_003A5BC0;
    temp_a0 = (*(s32 *)((u8 *)(arg0) + 0x20));
    if ((temp_a0 != 0) && ((*(u8 *)((u8 *)(arg0) + 0x2C)) == 0)) {
        func_003A69A0(temp_a0, (*(s32 *)((u8 *)(arg0) + 0x28)));
    }
    func_003A5BC0(arg0, arg1);
}
/* localdecomp:end func_003A6288 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A62E8);

/* localdecomp:start func_003A63E0 */
void func_003A63E0(u8 *p, s32 a, s32 b) {
    (*(f32 **)(p + 0x28))[0] = a;
    (*(f32 **)(p + 0x28))[1] = b;
}
/* localdecomp:end func_003A63E0 */

/* localdecomp:start func_003A6410 */
extern u8 *func_003A5A78(u8 *);
extern s32 D_001D81D0[];
u8 *func_003A6410(u8 *p) {
    func_003A5A78(p);
    *(u8 **)(p + 0x24) = (u8 *)D_001D81D0;
    return p;
}
/* localdecomp:end func_003A6410 */

LINKER_REMNANT("asm/remnants", func_003A6448);

/* localdecomp:start func_003A6450 */
extern s32 D_00331820[];
extern void func_003A5A90();
typedef struct { u8 pad[4]; f32 *v; u8 p2[0x28-8]; void *p28; u8 p3[4]; long l30; s32 w38; s32 w3C; } S_3A6450;
void func_003A6450(S_3A6450 *p) {
    func_003A5A90(p);
    p->p28 = D_00331820;
    p->l30 = 1;
    p->w38 = 0;
    p->v[0] = 1.0f;
    p->v[1] = 1.0f;
    p->w3C = 1;
}
/* localdecomp:end func_003A6450 */

extern s32 D_001D81D0[];
extern void func_003A5BC0(void *);
/* localdecomp:start func_003A64B0 */
extern s32 D_001D81D0[];
extern void func_003A5BC0(void *);

void func_003A64B0(void *p) {
    *(s32 **)((u8 *)p + 0x24) = &D_001D81D0[0];
    func_003A5BC0(p);
}
/* localdecomp:end func_003A64B0 */

/* localdecomp:start func_003A64D8 */
void func_003A64D8(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x3C) = value;
}
/* localdecomp:end func_003A64D8 */

/* localdecomp:start func_003A64E0 */
void func_003A64E0(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x38) = value;
}
/* localdecomp:end func_003A64E0 */

/* localdecomp:start func_003A64E8 */
extern void func_0038C538(s32, s32, s32, f32);
void func_003A64E8(u8 *p) {
    func_0038C538(*(s32 *)(p + 0x38), -1, *(s32 *)(p + 0x28), **(f32 **)(p + 4));
}
/* localdecomp:end func_003A64E8 */

LINKER_REMNANT("asm/remnants", func_003A6518);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6520);

/* localdecomp:start func_003A6638 */
void func_003A6638(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x34) = value;
}
/* localdecomp:end func_003A6638 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A6640);

/* localdecomp:start func_003A6768 */
void func_003A6768(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x2C) = value;
}
/* localdecomp:end func_003A6768 */

/* localdecomp:start func_003A6770 */
void func_003A6770(void *a0, s32 a1) {
    f32 result;
    void *p;
    __asm__ volatile (
        "mtc1 %2, %0\n"
        "nop\n"
        "cvt.s.w %0, %0\n"
        "lw %1, 4(%3)\n"
        : "=f"(result), "=r"(p)
        : "r"(a1), "r"(a0)
    );
    *(f32 *)((u8 *)p + 4) = result;
}
/* localdecomp:end func_003A6770 */

/* localdecomp:start func_003A6788 */
void func_003A6788(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x38) = value;
}
/* localdecomp:end func_003A6788 */
