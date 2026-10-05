#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003B62D0(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern s32 func_12C908(s32);
extern s32 func_13B620(void);
void func_0039B760(u8 *, u32);
extern void func_0039B760();
extern void func_003B5BF8(void);
extern void func_003B5C08(s32);
extern void func_003B5D10(s32);
extern s32 func_003B5EC8(s32);
extern void func_003B60F0();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B5BF8 */
extern s32 D_0037BA94[];
 
void func_003B5BF8(void) {
    D_0037BA94[0] = 7;
}
/* localdecomp:end func_003B5BF8 */

/* localdecomp:start func_003B5C08 */
typedef struct {
    char pad_0[0x74];
    s32 field_74;      
    s32 field_78;       
} TargetStruct_0037BA20;

extern TargetStruct_0037BA20 D_0037BA20;

void func_003B5C08(s32 arg_a0) {
    D_0037BA20.field_74 = 1;
    D_0037BA20.field_78 = arg_a0;
}
/* localdecomp:end func_003B5C08 */

/* localdecomp:start func_003B5C20 */
extern s32 D_0037BA94[];
s32 func_003B5C20(s32 a0) {
    return D_0037BA94[0] == a0;
}
/* localdecomp:end func_003B5C20 */

/* localdecomp:start func_003B5C38 */
s32 func_003B5C38(u32 i) {
    if (i < 4) {
        return ((struct { s32 pad[3]; s32 arr[4]; } *)&D_0037BA20)->arr[i];
    }
    return 0;
}
/* localdecomp:end func_003B5C38 */

LINKER_REMNANT("asm/remnants", func_003B5C60);

/* localdecomp:start func_003B5C68 */
extern s8 D_001D8C20[1];
s32 func_003B5C68(s32 i) {
    if (i >= 60) return -1;
    return D_001D8C20[i];
}
/* localdecomp:end func_003B5C68 */

LINKER_REMNANT("asm/remnants", func_003B5C90);

/* localdecomp:start func_003B5CA0 */
typedef struct { u8 pad[0xC]; u8 *buf[4]; } S_3B5CA0;
extern S_3B5CA0 D_0037BA20_003B5CA0[];
extern u8 D_002CC040[];
extern void func_00388440();
void func_003B5CA0(void) {
    s32 i;
    u8 *p = D_002CC040;
    for (i = 0; i < 4; i++) { u8 *q = p + i * 0x800; D_0037BA20_003B5CA0[0].buf[i] = q; func_00388440(q, 0, 0x800); }
}
/* localdecomp:end func_003B5CA0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B5D10);

/* localdecomp:start func_003B5EC8 */
extern void *D_001DA230[];
extern u32 D_001DA234[];
extern s32 func_003B6050(s32);
extern void func_00388440();

s32 func_003B5EC8(s32 mode) {
    register u32 *flags_base __asm__("$8") = D_001DA234;
    register s32 index __asm__("$6") = 0;
    register void **pointer __asm__("$16") = D_001DA230;
    register u32 *flags __asm__("$7") = flags_base;

    do {
        register u32 check_state __asm__("$2");
        register u32 entry_state __asm__("$3");
        register u32 updated_state __asm__("$2");
        register u32 *selected_flags __asm__("$5");
        register s32 offset __asm__("$3") = index << 3;

        if (mode != 0) {
            check_state = *(u8 *)flags ^ 1;
        } else {
            check_state = *flags;
        }
        if ((check_state & 1) == 0 && *pointer != 0) {
            selected_flags = (u32 *)((u8 *)offset + (s32)flags_base);
            entry_state = *selected_flags;
            if ((entry_state & 2) == 0) {
                updated_state = entry_state | 2;
                *selected_flags = updated_state;
                func_00388440(*pointer, 0xDEADBEEF, func_003B6050((s32)*pointer));
                return (s32)*pointer;
            }
        }
        index++;
        pointer = (void **)((u8 *)pointer + 8);
        flags += 2;
    } while (index < 7);
    return 0;
}
/* localdecomp:end func_003B5EC8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B5F88);

/* localdecomp:start func_003B6050 */
extern s32 D_001DA230_003B6050[];
extern s32 D_001DA234_003B6050[];
s32 func_003B6050(s32 arg0) {
    s32 i = 0;
    s32 c1 = 0x4F000;
    s32 *q = D_001DA234_003B6050;
    s32 *p = D_001DA230_003B6050;
    do {
        i++;
        if (p[0] == arg0) return (q[0] & 1) ? c1 : 0x12C00;
        q += 2;
        p += 2;
    } while (i < 7);
    return -1;
}
/* localdecomp:end func_003B6050 */

/* localdecomp:start func_003B60B0 */
extern f32 D_001D8C5C;
extern s32 func_003894A0(f32, s32, s32);
extern s32 func_003E2808(s32, s32);
void func_003B60B0(s32 a) {
    func_003E2808(a, ((s32 (*)(s32, s32, f32))func_003894A0)(0x20000000, 0x402299DE, D_001D8C5C));
}
/* localdecomp:end func_003B60B0 */

/* localdecomp:start func_003B60F0 */
__asm__(".extern D_001D8C60, 4");
__asm__(".extern D_001D8C5C, 4");
extern f32 D_001D8C60;
extern f32 D_001D8C5C;
void func_003B60F0(void) {
    f32 x, a;
    D_001D8C5C += D_001D8C60 * 0.05f; a = D_001D8C60;
    if (D_001D8C5C > 1.0f || D_001D8C5C < 0.0f) a = -a;
    D_001D8C60 = a;
    x = (D_001D8C5C > 1.0f) ? 1.0f : D_001D8C5C;
    D_001D8C5C = x;
    { f32 z = 0.0f; if (!(x < z)) z = x; D_001D8C5C = z; }
}
/* localdecomp:end func_003B60F0 */

LINKER_REMNANT("asm/remnants", func_003B6190);

/* localdecomp:start func_003B6198 */
s32 func_003B6198(void) {
    return 0;
}
/* localdecomp:end func_003B6198 */

/* localdecomp:start func_003B61A0 */
typedef struct { s32 f0; s32 f4; } E_3B61A0;
extern E_3B61A0 D_0037BAA8[];
extern s32 D_0037BAB4[];
extern char D_001D8C70[];
extern char D_001D8C78[];
extern s32 func_0037DF98();
extern void func_11B2E8();
char *func_003B61A0(char *buf, s32 n) {
    s32 r;
    s32 x;
    s32 y;
    char *fmt2;
    char *fmt;
    switch (n) {
    case 2:
    case 5:
    case 10:
    case 23:
    case 24:
    case 25:
    case 26:
        r = 0;
        break;
    default:
        r = 1;
        break;
    }
    if (r != 0) {
        fmt = D_001D8C70;
        x = func_0037DF98(0xE2);
        y = func_0037DF98(n > 0 ? D_0037BAA8[n % 60].f4 : D_0037BAB4[0]);
        func_11B2E8(buf, fmt, x, y);
    } else {
        fmt2 = D_001D8C78;
        y = func_0037DF98(n > 0 ? D_0037BAA8[n % 60].f4 : D_0037BAB4[0]);
        func_11B2E8(buf, fmt2, y);
    }
    return buf;
}
/* localdecomp:end func_003B61A0 */
/* localdecomp:start func_003B62D0 */
extern u8 D_001D8CE0;
void func_003B62D0(s32 a) {
    D_001D8CE0 = a;
}
/* localdecomp:end func_003B62D0 */

/* localdecomp:start func_003B62D8 */
extern s32 D_001D8D1C;
s32 func_003B62D8(void) {
    return D_001D8D1C;
}
/* localdecomp:end func_003B62D8 */

/* localdecomp:start func_003B62E0 */
extern s32 D_001D8D18;
s32 func_003B62E0(void) {
    return D_001D8D18;
}
/* localdecomp:end func_003B62E0 */

/* localdecomp:start func_003B62E8 */
extern void func_13BC30(s32, void *, unsigned long);
extern void func_003A00D0();
extern void func_11F0A0();
void func_003B62E8(s32 a, s32 *p) {
    s32 m;
    *p = -1;
    func_13BC30(a, func_003A00D0, (u32)p);
    m = -1;
    do {
        func_11F0A0(0);
        func_12C908(0);
        ((s32 (*)(void))func_13B620)();
    } while (*p == m);
}
/* localdecomp:end func_003B62E8 */

/* localdecomp:start func_003B6358 */
void func_003B6358(s32 a0, long a1) {
    *(s32 *)a1 = a0;
}
/* localdecomp:end func_003B6358 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B6368);

/* localdecomp:start func_003B6410 */
extern int D_001D8D10_003B6410;
extern int D_001DA298[];
extern int D_001DA2C0[];
extern void func_13C230(int, int, int);

void func_003B6410(float volume, int index) {
    int sound;
    register int offset __asm__("$3");
    register int *indices __asm__("$2");
    register int *sounds __asm__("$4");
    register int invalid __asm__("$5");

    if (index >= 0 && index < D_001D8D10_003B6410) {
        offset = index * 4;
        __asm__ volatile("" : "+r"(offset));
        indices = D_001DA298;
        offset += (int)indices;
        __asm__ volatile("" : "+r"(offset));
        sounds = D_001DA2C0;
        __asm__ volatile("" : "+r"(sounds));
        sound = sounds[*(int *)offset];
        invalid = -1;
        if (sound != invalid) {
            func_13C230(sound, (int)(volume * 1024.0f), 0);
        }
    }
}
/* localdecomp:end func_003B6410 */

/* localdecomp:start func_003B6488 */
extern void func_0013CA20(void);
extern void func_0013BF00(s32);
extern void func_0013CA28(void);
extern s32 func_0013B620(void);
extern void func_0013BED0(void);
extern u32 D_001D8D10;
extern s32 D_001DA274[];
extern s32 D_001D4B4C[];
void func_003B6488(void) {
    u32 i;
    s32 r;
    func_0013CA20();
    for (i = 1; i < D_001D8D10; i++) {
        func_0013BF00(D_001DA274[i - 1]);
    }
    func_0013CA28();
    do { r = func_0013B620(); __asm__ volatile("nop
	nop
	nop"); } while (r);
    func_0013BED0();
    D_001D4B4C[0] = 0;
}
/* localdecomp:end func_003B6488 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B6528);

INCLUDE_ASM("asm/nonmatchings/text", func_003B6F28);

/* localdecomp:start func_003B70A8 */
typedef struct { u8 p0[0xC]; s32 fC; } P_3B70A8;
extern P_3B70A8 *D_00227618[];
extern s32 D_0037C038[];
extern void func_11F0A0();
void func_003B70A8(s32 a, s32 *out, s32 c) {
    u8 *base;
    s32 n;
    s32 *tbl;
    s32 idx;
    base = (u8 *)D_00227618[0] + D_00227618[0]->fC;
    n = *(s32 *)base;
    tbl = (s32 *)(base + 0x10);
    if (a < 0x1E && (idx = D_0037C038[a]) != -1 && idx < n && tbl[idx] != 0) {
    } else {
        a = 0;
    }
    func_11F0A0(0);
    *out = ((s32 (*)(u8 *, u32))func_0039B760)(base + tbl[D_0037C038[a]], c);
    func_11F0A0(0);
}
/* localdecomp:end func_003B70A8 */

/* localdecomp:start func_003B7190 */
extern unsigned long func_00395EB8(s32);
void func_003B7190(s32 a, unsigned long *out) {
    *out = func_00395EB8(a);
}
/* localdecomp:end func_003B7190 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B71B8);

/* localdecomp:start func_003B7288 */
extern void func_003BD360(s32 p);
typedef struct { u8 p0[0x44]; s16 n; u8 p1[0x15A]; void *slot[1]; } S_B7288;
typedef struct { u8 p0[0xC]; u8 c; u8 p1[0x3B]; s32 q[1]; } I_B7288;
typedef struct { u8 p0[0x24]; I_B7288 *in; } O_B7288;
extern S_B7288 D_00225780;
void func_003B7288(void) {
    s32 i;
    for (i = 0; i < D_00225780.n; i++) {
        O_B7288 *o = D_00225780.slot[i];
        if (o != 0) {
            o->in->c--;
            *(s32 *)((u8 *)o->in + (o->in->c << 2) + 0x48) = 0;
            func_003BD360((s32)o);
            D_00225780.slot[i] = 0;
        }
    }
}
/* localdecomp:end func_003B7288 */

/* localdecomp:start func_003B7320 */
extern void func_00381F18(void);
extern void func_003BD8A0(void);
extern void func_003838C0(void);
extern void func_003B7378(void);
extern void func_0038DEB0(void);
extern s32 D_001D9D9C;
extern void (*D_001D8CF0)(void);
void func_003B7320(void) {
    void (*fn)(void);
    func_00381F18();
    func_003BD8A0();
    func_003838C0();
    fn = D_001D8CF0;
    D_001D9D9C = -1;
    if (fn != 0) fn();
    func_003B7378();
    func_0038DEB0();
}
/* localdecomp:end func_003B7320 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B7378);

/* localdecomp:start func_003B7568 */
typedef struct { u8 pad[0x22]; u16 f22; } S_16C580c;
extern S_16C580c D_16C580_003B7568;
__asm__(".extern D_001D8CE8, 4");
__asm__(".extern D_001D8D04, 4");
__asm__(".extern D_001D8CEC, 4");
extern s32 (*D_001D8CE8)();
extern s32 D_001D8D04;
extern void (*D_001D8CEC)(s32);
extern s32 D_001D5B94;
extern s32 D_001D9D80;
extern void func_003C7AE8();
extern void func_003C7DE0();
s32 func_003B7568(s32 a) {
    s32 r;
    D_001D5B94 = 6;
    D_16C580_003B7568.f22++;
    r = D_001D8CE8(a);
    if (D_001D8D04 & 4) { func_003C7AE8(); }
    if (D_001D8D04 & 0x10) { func_003C7DE0(); }
    if (D_001D8CEC != 0) { D_001D8CEC(a); }
    D_001D9D80++;
    return r;
}
/* localdecomp:end func_003B7568 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B7618);

/* localdecomp:start func_003B7870 */
extern void func_003C8CE0(void);
extern void func_003C8C40(void);
extern void func_003C8D50(void);
extern void func_003A3EF0(s32, unsigned long);
extern s32 D_001A1ED8[];
void func_003B7870(void) {
    func_003C8CE0();
    func_003C8C40();
    func_003C8D50();
    func_003A3EF0(0x47, 0x5360B);
    func_003A3EF0(0x4E, (D_001A1ED8[0] >> 13) | 0x1000000);
}
/* localdecomp:end func_003B7870 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B78C8);

/* localdecomp:start func_003B7AA0 */
extern u8 D_001D5571;
s32 func_003A21C0_003B7AA0(s32);                         /* extern */
extern s32 D_001D9D84;
typedef struct { u8 pad0[0x7]; s8 f7; } S_001CCFD0_003B7AA0_003B7AA0;
extern S_001CCFD0_003B7AA0_003B7AA0 D_001CCFD0[];

void func_003B7AA0(void) {
    if (D_001D9D84 == 1) {
        if (D_001D5571 == 0) {
            D_001CCFD0->f7 = 0;
            if ((func_003A21C0_003B7AA0(1) == 0) && (func_003A21C0_003B7AA0(2) == 0) && (func_003A21C0_003B7AA0(3) == 0) && (func_003A21C0_003B7AA0(4) == 0) && (func_003A21C0_003B7AA0(5) == 0)) {
                func_003A21C0_003B7AA0(6);
            }
            D_001CCFD0->f7 = 1;
        }
    }
}
/* localdecomp:end func_003B7AA0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B7B50);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7EB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7FD8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8168);

/* localdecomp:start func_003B8280 */
extern u8 D_001DA320[];
extern s32 D_001DA330[];
extern f32 D_001DA334[];
extern f32 D_001DA338[];
extern void func_003BFEF0(void *, s32, f32, f32);
void func_003B8280(void) {
    func_003BFEF0(D_001DA320, D_001DA330[0], D_001DA334[0], D_001DA338[0]);
}
/* localdecomp:end func_003B8280 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B82C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8440);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8560);

/* localdecomp:start func_003B8700 */
extern void func_003958A0(s32);
extern void func_003B6368(s32);
extern void func_003B8168(void);
extern void func_003B8560(void);
extern s32 D_001D8D0C;
extern s32 D_0016C5E4[];
typedef struct { u8 pad0[0x34]; s32 f34; s32 f38; s32 f3C; s16 f40; } S_003B8700;
extern S_003B8700 D_00225780_003B8700[];
s32 func_003B8700(void) {
    S_003B8700 *p = D_00225780_003B8700;
    s32 temp_3;
    s32 temp_4;
    s32 var_17;

    var_17 = 0;
        p->f38 = p->f38 + 1;
        temp_3 = p->f34 + 1;
        p->f34 = temp_3;
    if (temp_3 == 1) {
        func_003B6368(D_0016C5E4[0]);
    }
    if (p->f40 >= p->f34) {
        if (p->f38 >= 0x60) {
            temp_4 = p->f3C + 1;
            p->f3C = temp_4;
            func_003958A0(temp_4);
        }
        func_003B8168();
        func_003B8560();
    } else {
        var_17 = 1;
        D_001D8D0C = D_001D8D0C + 1;
    }
    return var_17;
}
/* localdecomp:end func_003B8700 */

/* localdecomp:start func_003B87B8 */
extern s32 D_001D8D2C;
extern s32 D_001D8D28;
extern s32 D_001DA2E8[];
extern s8 D_001DA310[];
void func_003B87B8(s32 n, s32 *p, s32 v) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (i < n) D_001DA2E8[i] = p[i];
        else D_001DA2E8[i] = -1;
        D_001DA310[i] = 0;
        }
    D_001D8D2C = v;
    D_001D8D28 = n;
}
/* localdecomp:end func_003B87B8 */

/* localdecomp:start func_003B8810 */
extern s8 D_001DA319[];

void func_003B8810(void) {
    s32 var_v1;
    s8 *var_v0;

    var_v1 = 9;
    var_v0 = D_001DA319;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
}
/* localdecomp:end func_003B8810 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B8840);

/* localdecomp:start func_003B8928 */
typedef struct { u8 pad[0x64]; s32 f64; s32 f68; } S_16C580b;
extern S_16C580b D_16C580;
extern void func_003B71B8(s32);
extern void func_003958A0(s32);
void func_003B8928(s32 a) {
    func_003B71B8(a);
    D_16C580.f64 = a;
    D_16C580.f68 = 0;
    func_003958A0(0);
}
/* localdecomp:end func_003B8928 */

/* localdecomp:start func_003B8968 */
extern void func_003B71B8(s32);
extern void func_003958A0(s32);
extern void func_003B8560(void);
extern void func_003BD490();
void func_003B8968(s32 a) {
    s32 i;
    func_003B71B8(a);
    D_16C580.f64 = a;
    func_003958A0(0);
    func_003B8560();
    for (i = 0; i < D_00225780.n; i++) {
        if (D_00225780.slot[i] != 0) {
            func_003BD490(D_00225780.slot[i]);
        }
    }
}
/* localdecomp:end func_003B8968 */

/* localdecomp:start func_003B89F8 */
extern s32 D_0016C5E4[];
 
s32 func_003B89F8(void) {
    return D_0016C5E4[0];
}
/* localdecomp:end func_003B89F8 */

/* localdecomp:start func_003B8A08 */
extern s32 D_002257B4[];
s32 func_003B8A08(void) {
    return D_002257B4[0];
}
/* localdecomp:end func_003B8A08 */

/* localdecomp:start func_003B8A18 */
extern s32 D_001D8D0C;
s32 func_003B8A18(void) { return D_001D8D0C; }
/* localdecomp:end func_003B8A18 */

/* localdecomp:start func_003B8A20 */
extern s32 D_001D4B4C[];
extern s32 D_001D4B48;
s32 func_003B8A20(void) {
    if (D_001D4B4C[0] != 0 && D_001D4B48 >= 2) return 1;
    return 0;
}
/* localdecomp:end func_003B8A20 */

/* localdecomp:start func_003B8A48 */
extern s32 D_001DA644[];
extern s32 D_001DA648[];
extern s32 D_001DA64C;
void func_003B8A48(void) {
    D_001DA644[0] = 0;
    D_001DA648[0] = -1;
    D_001DA64C = 0;
}
/* localdecomp:end func_003B8A48 */

/* localdecomp:start func_003B8A68 */
extern f32 D_001D8D20;
void func_003B8A68(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
  arg1 = arg1 - 1;
  if (arg0 <= 0 || arg0 >= arg1) {
    D_001D8D20 = 0.0f;
  } else if (arg2 >= arg0) {
    D_001D8D20 = (f32)arg0 / (f32)arg2;
  } else if (arg1 - arg3 < arg0) {
    D_001D8D20 = (f32)(arg1 - arg0) / (f32)arg3;
  } else {
    D_001D8D20 = 1.0f;
  }
  D_001D8D20 = 1.0f - D_001D8D20;
}
/* localdecomp:end func_003B8A68 */

/* localdecomp:start func_003B8B10 */
extern f32 D_001D8D20;
void func_003B8B10(f32 a) {
    D_001D8D20 = a;
}
/* localdecomp:end func_003B8B10 */

/* localdecomp:start func_003B8B18 */
extern u32 D_00142BA0[];
extern s32 D_001D6E90;
extern s32 func_003B62E0();
extern s32 func_003B62D8();
s32 func_003B8B18(s32 a, s32 b, u32 c) {
    u32 w;
    if (a == -1 || func_003B62E0() == a) {
        if (b == -1 || func_003B62D8() == b) {
            w = c >> 2;
            if (!(D_00142BA0[w] & (1 << (c & 0x1F)))) {
                D_001D6E90 = c;
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_003B8B18 */

/* localdecomp:start func_003B8BC8 */
extern s32 func_003B8B18(s32, s32, s32);
extern u8 D_001D558C[];
void func_003B8BC8(void) {
    if (func_003B8B18(0x1C, 8, 0)) return;
    if (func_003B8B18(8, 8, 0)) return;
    if (func_003B8B18(8, 0x1B, 0)) return;
    if (func_003B8B18(8, 0x1C, 0)) return;
    if (func_003B8B18(-1, 8, 0x11)) return;
    if (D_001D558C[0] != 0) func_003B8B18(8, -1, 0x12);
}
/* localdecomp:end func_003B8BC8 */

/* localdecomp:start func_003B8C70 */
void func_003A2028(s32);
void func_003A21C0(s32);
extern s32 D_001D5B94;
extern s32 D_001D6E90;
typedef struct { u8 pad0[0x7]; s8 f7; } S_001CCFD0_003B8C70_003B8C70;
extern S_001CCFD0_003B8C70_003B8C70 D_001CCFD0_003B8C70[];

void func_003B8C70(void) {
    if (D_001D6E90 != 0) {
        D_001CCFD0_003B8C70->f7 = 0;
        switch (D_001D6E90) {                       /* irregular */
        case 17:
            func_003A2028(0x11);
            break;
        case 18:
            func_003A21C0(0x12);
            break;
        }
        D_001CCFD0_003B8C70->f7 = 1;
        D_001D5B94 = 6;
        D_001D6E90 = 0;
    }
}
/* localdecomp:end func_003B8C70 */

/* localdecomp:start func_003B8D00 */
extern u8 D_001D8D24;
void func_003B8D00(s32 a) {
    D_001D8D24 = a;
}
/* localdecomp:end func_003B8D00 */

/* localdecomp:start func_003B8D08 */
__asm__(".extern D_001D8D30, 4");
extern u32 *D_001DA0D0;
extern u8 D_001D02D0[];
extern u8 D_001D7300[];
extern s32 D_001D8D30;
void func_003B8D08(void) {
    D_001DA0D0[0] = 0x30000002;
    D_001DA0D0[1] = (u32)&D_001D8D30;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0x50000002;
    D_001DA0D0 += 4;
    D_001DA0D0[0] = 0x30000029;
    D_001DA0D0[1] = (u32)D_001D02D0;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0x50000029;
    D_001DA0D0 += 4;
    D_001DA0D0[0] = 0x30000003;
    D_001DA0D0[1] = (u32)D_001D7300;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0x50000003;
    D_001DA0D0 += 4;
}
/* localdecomp:end func_003B8D08 */

/* localdecomp:start func_003B8E08 */
extern u8 D_001D8D01;
u8 func_003B8E08(void) {
    return D_001D8D01;
}
/* localdecomp:end func_003B8E08 */

/* localdecomp:start func_003B8E10 */
extern u32 D_001DA51C;
extern u32 D_001DA520;
void func_003B8E10(void (*cb)(u32)) {
    u32 p;
    s32 i;
    for (p = D_001DA51C; p != D_001DA520; p += 0x100) {
        cb(p);
    }
    for (i = 0; i < D_00225780.n; i++) {
        if (D_00225780.slot[i] != 0) {
            ((void (*)(void *))cb)(D_00225780.slot[i]);
        }
    }
}
/* localdecomp:end func_003B8E10 */

/* localdecomp:start func_003B8EC0 */
extern void func_003B6528(s32, s32);
extern void func_00385B60(s32);
extern s32 D_001DA340[];
s32 func_003B8EC0(void) {
    func_003B6528(0, 0);
    func_00385B60(6);
    D_001DA340[0] = 300;
    return 1;
}
/* localdecomp:end func_003B8EC0 */

/* localdecomp:start func_003B8EF8 */
extern s16 D_0016C5A2[];
extern s32 func_00388398(s32 *);
void func_003B8A68(s16, s32, s32, s32);
extern u8 D_001DA340_003B8EF8;

s32 func_003B8EF8(void) {
    s32 temp_s0;

    temp_s0 = func_00388398(&D_001DA340_003B8EF8) != 0;
    func_003B8A68(D_0016C5A2[0], 0x12C, 0xF, 0xF);
    return temp_s0;
}
/* localdecomp:end func_003B8EF8 */

/* localdecomp:start func_003B8F48 */
s32 func_003B8F48(void) {
}
/* localdecomp:end func_003B8F48 */
