#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_0011A264(s32, s32, s32);
extern void func_00392580(s32, long, long);
extern void func_003925D8(void);
extern void func_00392670(s32);
extern void func_003925B0(void);
extern void func_003926F0(void);
extern void func_00392A68(s32);
extern s32 func_00392E40();
extern s32 func_00392F98();
extern void func_0038E478(s32);
extern void func_003913E0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_00397FB8();
extern void (*D_001D9AC0[2])(s32);
extern void func_00392760(s32, s32, s32, s32);
extern void func_00392B88(s32, s32);
extern void func_00392A08(void);
extern void func_00396B30(void);
extern void func_0038E460(void);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_0038E1F8 */
__asm__(".extern D_001D5B34, 4");
__asm__(".extern D_001D5B38, 4");
__asm__(".extern D_001D5B3C, 4");
__asm__(".extern D_001D5B30, 4");
__asm__(".extern D_001D55E8, 4");
typedef struct { s16 x; s16 y; } P_3896E8;
typedef struct {
    u8 n0; u8 n1; u8 p2[0x2E];
    u8 k30[0x10];
    u8 k40[0x10];
    P_3896E8 pt[0x10];
    s32 o90[0x10];
    s32 oD0[0x10];
} T_3896E8;
extern T_3896E8 *D_001D55D0_0038E1F8[2];
extern s32 D_001D9C48_0038E1F8;
extern s32 D_001D5B34;
extern u8 *D_001D5B38;
extern u8 *D_001D5B3C;
extern s32 D_001D5B30;
extern s32 D_001D55E8;
extern s32 D_0031D050_0038E1F8[][16];
extern s32 D_0031CFD0_0038E1F8[][16];
extern s32 func_00389FD0(s32 a, s32 b);
extern s32 func_00389E98(s32, s32, s32, s32);
void func_0038E1F8(void) {
    s32 i, j;
    s32 o = D_001D5B34;
    s32 v = D_001D9C48_0038E1F8;
    if (o == v && D_001D5B38 && D_001D5B3C && D_001D5B30 == 0) return;
    D_001D5B34 = v;
    D_001D5B30 = 0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < D_001D55D0_0038E1F8[i]->n0; j++) {
            D_0031D050_0038E1F8[i][j] = func_00389FD0((s32)D_001D55D0_0038E1F8[i] + D_001D55D0_0038E1F8[i]->o90[j],
                (D_001D55D0_0038E1F8[i]->k30[j] == 0x14) ? 0x14 : 0x13);
        }
        for (j = 0; j < D_001D55D0_0038E1F8[i]->n1; j++) {
            D_0031CFD0_0038E1F8[i][j] = func_00389E98((s32)D_001D55D0_0038E1F8[i] + D_001D55D0_0038E1F8[i]->oD0[j],
                D_001D55D0_0038E1F8[i]->pt[j].x, D_001D55D0_0038E1F8[i]->pt[j].y,
                (D_001D55D0_0038E1F8[i]->k40[j] == 0x14) ? 0x14 : 0x13);
        }
    }
    func_0038E478(D_001D55E8);
}
/* localdecomp:end func_0038E1F8 */

/* localdecomp:start func_0038E3D0 */
s32 func_0038E3D0(u8 *p, s32 off, s32 *out) {
    u8 *q = p + off;
    s32 r = 0;
    s32 b = q[0];
    *out = b;
    if (b & 0x80) {
        r = 1;
        *out = (((b & 0x7F) << 8) | q[1]) + 0x7F;
    }
    return r;
}
/* localdecomp:end func_0038E3D0 */

/* localdecomp:start func_0038E410 */
/* func_0038E458 (filed as a linker remnant) is this function's jr delay slot and alignment nop. */
extern u8 D_00144440[];
extern u8 D_00143E40[];
extern u8 D_0014A840[];
extern u8 D_0014A240[];
extern void func_0038E140(s32, void *, void *);
void func_0038E410(void) {
    func_0038E140(0, D_00144440, D_00143E40);
    func_0038E140(1, D_0014A840, D_0014A240);
    func_0038E478(0);
}
/* localdecomp:end func_0038E410 */

extern s32 D_001D9C48[];

/* localdecomp:start func_0038E460 */
extern s32 D_001D9C48[];
extern s32 D_001D5B34;
void func_0038E460(void) { D_001D5B34 = D_001D9C48[0] - 1; }
/* localdecomp:end func_0038E460 */

/* localdecomp:start func_0038E478 */
extern s32 D_001D55D0[];
extern s32 D_001D55D8[];
extern s32 D_001D55E0[];
extern s32 D_001D55C0;
extern s32 D_001D55C4_0038E478;
extern s32 D_001D55C8;
extern u8 D_0031CFD0[];
extern u8 D_0031D050[];
extern u8 *D_001D5B38;
extern u8 *D_001D5B3C;
extern s32 D_001D55E8;
__asm__(".extern D_001D55D0, 16");
__asm__(".extern D_001D55D8, 16");
__asm__(".extern D_001D55E0, 16");
__asm__(".extern D_001D55C0, 16");
__asm__(".extern D_001D55C4_0038E478, 16");
__asm__(".extern D_001D55C8, 16");
__asm__(".extern D_0031CFD0, 16");
__asm__(".extern D_0031D050, 16");
void func_0038E478(s32 index) {
    register s32 offset __asm__("$2") = index << 2;
    register s32 *table0 __asm__("$7");
    register s32 *table2 __asm__("$8");
    register s32 *table1 __asm__("$3");
    register s32 *ptr1 __asm__("$2");
    register s32 offset64 __asm__("$5");
    register u8 *out1 __asm__("$3");
    register u8 *out0 __asm__("$6");
    register s32 value1 __asm__("$10");
    register s32 value0 __asm__("$9");
    register s32 value2 __asm__("$2");
    __asm__ volatile("" : "+r"(offset));
    table0 = D_001D55D0;
    __asm__ volatile("" : "+r"(table0));
    table2 = D_001D55E0;
    __asm__ volatile("" : "+r"(table2));
    table1 = D_001D55D8;
    __asm__ volatile("" : "+r"(table1));
    table0 = (s32 *)(offset + (s32)table0);
    __asm__ volatile("" : "+r"(table0));
    table2 = (s32 *)(offset + (s32)table2);
    __asm__ volatile("" : "+r"(table2));
    ptr1 = (s32 *)(offset + (s32)table1);
    __asm__ volatile("" : "+r"(ptr1));
    offset64 = index << 6;
    __asm__ volatile("" : "+r"(offset64));
    out1 = (u8 *)0x320000;
    __asm__ volatile("" : "+r"(out1));
    value1 = *ptr1;
    __asm__ volatile("" : "+r"(value1));
    out0 = (u8 *)0x320000;
    __asm__ volatile("" : "+r"(out0));
    out1 -= 0x2FB0;
    value0 = *table0;
    out1 = (u8 *)(offset64 + (s32)out1);
    __asm__ volatile("" : "+r"(out1));
    value2 = *table2;
    __asm__ volatile("" : "+r"(value2));
    out0 -= 0x3030;
    offset64 += (s32)out0;
    __asm__ volatile("" : "+r"(offset64));
    D_001D55C0 = value0;
    D_001D55C4_0038E478 = value1;
    D_001D55C8 = value2;
    D_001D5B38 = (u8 *)offset64;
    D_001D5B3C = out1;
    D_001D55E8 = index;
}
/* localdecomp:end func_0038E478 */

/* localdecomp:start func_0038E4F0 */
extern s32 *D_001D55C4[];
s32 func_0038E4F0(void) {
    s32 *p = D_001D55C4[0];
    s32 r = -1;
    if (p) r = p[-1];
    return r;
}
/* localdecomp:end func_0038E4F0 */

/* localdecomp:start func_0038E510 */
typedef struct { u32 w0; u32 w4; } E_3899B8;
extern E_3899B8 *D_001D55C4_0038E510;
s32 func_0038E510(f32 *w, f32 *h, s32 mode) {
    s32 r;
    *w = 0.0f;
    *h = 0.0f;
    r = 0;
    if (D_001D55C4_0038E510 != 0) {
        if (mode != 0) {
            *w = (f32)((D_001D55C4_0038E510[0x41].w4 >> 17) & 0x3F);
            *h = (f32)((D_001D55C4_0038E510[0x41].w4 >> 9) & 0xFF) * 0.25f;
            r = 1;
        } else {
            s32 n = func_0038E4F0();
            if (n > 0) {
                s32 i;
                u32 mx = 0;
                for (i = 0; i < n; i++) {
                    u32 a = (D_001D55C4_0038E510[i].w4 >> 17) & 0x3F;
                    if (mx < a) {
                        mx = a;
                        *h = (f32)((D_001D55C4_0038E510[i].w4 >> 9) & 0xFF) * 0.25f;
                    }
                }
                *w = (f32)mx;
                r = 1;
            }
        }
    }
    return r;
}
/* localdecomp:end func_0038E510 */

/* localdecomp:start func_0038E6E8 */
extern u8 D_001D5B42;
void func_0038E6E8(s32 a) { D_001D5B42 = a; }
/* localdecomp:end func_0038E6E8 */

/* localdecomp:start func_0038E6F0 */
typedef struct { u32 w0; u32 w4; } E_389B98;
s32 func_0038E6F0(u8 *str, s32 len, f32 scale) {
    s32 i = 0;
    s32 ok = 1;
    f32 max = 0.0f;
    s32 idx = 0;
    for (; ok && i != len; i++) {
        if (str[i] == 0) {
            ok = 0;
        } else {
            f32 w, h, v;
            i += func_0038E3D0(str, i, &idx);
            w = (f32)((((E_389B98 *)D_001D55C4[0])[idx].w4 >> 17) & 0x3F) * scale;
            h = (f32)((((E_389B98 *)D_001D55C4[0])[idx].w4 >> 9) & 0xFF) * scale;
            v = w + h * 0.25f;
            if (max < v) max = v;
        }
    }
    return (s32)max;
}
/* localdecomp:end func_0038E6F0 */

/* localdecomp:start func_0038E870 */
extern s32 D_001D55C8;
__asm__(".extern D_001D55C8, 16");
extern s32 *D_001D55C4[];
extern s32 func_0038E3D0(u8 *p, s32 off, s32 *out);
typedef struct { u32 w0; u32 w4; } E_389D18;
typedef struct { s16 ch; s8 adj; u8 end; } K_389D18;
s32 func_0038E870(u8 *str, s32 len, f32 scale) {
    s32 idx[2];
    f32 q = scale * 0.25f;
    s32 i;
    s32 ok;
    f32 kern;
    f32 x;
    f32 first;
    idx[0] = 0;
    idx[1] = 0;
    func_0038E3D0(str, 0, &idx[0]);
    kern = 0.0f;
    first = (f32)(-(s32)(((E_389D18 *)D_001D55C4[0])[idx[0]].w0 >> 25)) * q;
    x = 0.0f;
    ok = 1;
    i = 0;
    for (; ok && i != len; i++) {
        if (str[i] == 0) {
            ok = 0;
        } else {
            E_389D18 *e;
            f32 w, b, c, adv;
            i += func_0038E3D0(str, i, &idx[0]);
            e = &((E_389D18 *)D_001D55C4[0])[idx[0]];
            w = (f32)((e->w4 >> 23) & 0x3F) * scale;
            b = (f32)(s32)(((e->w0 >> 25) + 2) & 0xFC) * q;
            c = (f32)(((e->w4 >> 29) + 2) & 0xFC);
            x += w - b;
            adv = (kern + c) * q;
            if (i != len - 1) {
                s32 nx;
                func_0038E3D0(str, i + 1, &idx[1]);
                nx = idx[1];
                if (nx >= 0x10) {
                    f32 t;
                    if (e->w0 & 0xFFF0) {
                        K_389D18 *k = (K_389D18 *)((u8 *)D_001D55C8 + ((e->w0 >> 2) & 0x3FFC));
                        s32 r;
                        t = x + adv;
                        if (k != 0) {
                            s32 j;
                            for (j = 0; k[j].end == 0; j++) {
                                if (k[j].ch == nx) { r = k[j].adj; goto done; }
                            }
                        }
                        r = 0;
                    done:
                        kern = (f32)r;
                        kern = kern * q;
                    } else {
                        t = x + adv;
                        kern = 0.0f;
                    }
                    x = t;
                }
            }
        }
    }
    return (s32)(x - first);
}
/* localdecomp:end func_0038E870 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038EB10);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C0F0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038F3A0);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C120);

/* localdecomp:start func_0038FD08 */
void func_0038FD08(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    p[4] = e;
    p[5] = f;
    p[8] = g;
    p[9] = h;
    p[6] = 0;
    p[7] = 0;
    p[10] = 0;
    p[11] = 0;
}
/* localdecomp:end func_0038FD08 */

/* localdecomp:start func_0038FD40 */
typedef struct { s16 h0, h2, h4, h6, h8, hA, hC, hE, h10; u16 fl; s16 h14, h16, h18, h1A; } O_0038B1E8;
typedef struct { s16 key; s8 val; u8 end; } K_0038B1E8;
__asm__(".extern D_001D5B41, 1");
__asm__(".extern D_001D5B42, 1");
__asm__(".extern D_001D5B40, 1");
__asm__(".extern D_001D5B68, 4");
__asm__(".extern D_001D5B48, 8");
extern s32 D_001D5B94;
extern u8 D_001D5B41, D_001D5B42, D_001D5B40;
extern s32 D_001D5B68;
extern s32 D_001D5B48[2];
extern s32 D_001D9D00;
extern u16 D_001D9D08[4], D_001D9D20[4], D_001D9D38[4], D_001D9D50[4];
extern s32 D_001D55C4_0038FD40;
extern s32 D_001D55C8_0038FD40;
extern s32 D_001D4BC0_0038FD40, D_001D4BC4_0038FD40;
extern void func_003A9770(s32, s32, s32, s32);
extern s32 func_0038E3D0(u8 *, s32, s32 *);
extern s32 func_0038E870_0038FD40(u8 *, s32, f32);
extern void func_0038EB10_0038FD40(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
static __inline__ s32 kern_0038B1E8(K_0038B1E8 *k, s32 c) {
    if (k != 0) {
        for (; k->end == 0; k++) {
            if (k->key == c) return k->val;
        }
    }
    return 0;
}
void func_0038FD40(s32 a0, long a1, s32 a2, s32 len, unsigned long a4, s32 a5, f32 scale, f32 scale2) {
    O_0038B1E8 *o = (O_0038B1E8 *)a0;
    u8 *text = (u8 *)a2;
    s16 st[0x50], en[0x50], sty[0x50];
    s32 code, code2, c2;
    s32 sp1F8, sp1FC, sp200, sp204;
    s32 nl, pos, w, i, n, y;
    s32 bp;
    u8 first, cont, retry;
    s32 style, idx;
    f32 f1, f20, f21, f22, f23, f24, f25;
    first = 1;
    f25 = scale * 0.25f;
    f24 = 0.0f;
    code = 0;
    if (D_001D5B94 != 1) {
        if (!(o->fl & 0x10)) func_003A9770(o->h4, o->h6 - 1, o->h0, o->h2 + 3);
    }
    D_001D5B41 = 1;
    if ((((u8 *)o)[0x12] ^ 1) & 1) {
        w = o->h6 - o->h8;
    } else {
        s32 p = o->h6 - o->h8;
        s32 q = o->h8 - o->h4;
        if (p < q) q = p;
        w = q * 2;
    }
    nl = 0;
    style = 0;
    sp1F8 = 0;
    sp1FC = 0;
    f1 = 0.0f;
    sp200 = w;
    if (D_001D5B68 != 2) {
        do {
            nl = 0;
            cont = 1;
            first = 1;
            pos = 0;
            if (len != 0) {
                do {
                    if (text[pos] == 0 || nl >= 0x4F) {
                        cont = 0;
                    } else {
                        s32 go;
                        f22 = 0.0f;
                        idx = nl;
                        st[idx] = pos;
                        sp204 = nl + 1;
                        sty[idx] = style;
                        bp = pos;
                        go = 1;
                        if (f22 < (f32)w) {
                            do {
                                if (text[pos] == 0x20 || text[pos] < 0x10) bp = pos;
                                if (D_001D5B42 != 0 && (u32)(((volatile u8 *)text)[pos] - 8) < 8) style = ((volatile u8 *)text)[pos] - 8;
                                if (text[pos] == 0) {
                                    cont = 0;
                                    go = 0;
                                    pos--;
                                } else if (text[pos] == 1) {
                                    go = 0;
                                    pos--;
                                } else {
                                    u32 *g;
                                    pos += func_0038E3D0(text, pos, &code);
                                    g = (u32 *)((code << 3) + D_001D55C4_0038FD40);
                                    if (g[1] & 0x1F800000) {
                                        f32 f2 = (f32)(s32)(((g[0] >> 25) + 2) & 0xFC) * f25;
                                        f21 = (f24 + (f32)(((g[1] >> 29) + 2) & 0xFC)) * f25 + (f32)((g[1] >> 23) & 0x3F) * scale;
                                        f20 = (f32)((g[1] >> 23) & 0x3F) * scale;
                                        if (first) first = 0;
                                        else f22 -= f2;
                                        if (pos != len && (func_0038E3D0(text, pos + 1, &code2), c2 = code2, c2 != 0)) {
                                            u32 e0 = g[0];
                                            f22 += f21 + f24;
                                            if (e0 & 0xFFF0) {
                                                K_0038B1E8 *k = (K_0038B1E8 *)(D_001D55C8_0038FD40 + ((e0 >> 2) & 0x3FFC));
                                                f24 = (f32)kern_0038B1E8(k, c2);
                                                f24 *= f25;
                                            } else {
                                                f24 = 0.0f;
                                            }
                                        } else {
                                            f22 += f20;
                                        }
                                    }
                                }
                                pos++;
                            } while (go != 0 && f22 < (f32)w);
                        }
                        if (D_001D5B42 != 0 && (f32)w <= f22) {
                            if (code >= 8) { if (code <= 15) style = code - 8; }
                        }
                        en[idx] = bp;
                        if ((s16)bp == st[idx]) {
                            if (f22 < (f32)w) en[idx] = pos;
                            else if ((s16)bp + 1 < pos) en[idx] = pos - 2;
                            else if ((s16)bp < pos) en[idx] = pos - 1;
                            else en[idx] = pos;
                        }
                        pos = en[idx];
                        if (text[pos] == 0x20 || text[pos] < 0x10) en[idx] = (u16)en[idx] - 1;
                        nl = sp204;
                        f1 = f22;
                    }
                    pos++;
                } while (cont != 0 && pos != len);
            }
            retry = 0;
            if (sp1F8 == 0 && nl >= 2) {
                if (sp1FC == 0) {
                    f32 q = (f32)(w >> 2);
                    if (f1 < q) {
                        sp1FC = nl;
                        retry = 1;
                        w = w - (w - (s32)f1) / (nl + 1);
                    }
                } else if (sp1FC < nl) {
                    retry = 1;
                    w = sp200;
                    sp1F8 = 1;
                }
            }
            if (retry == 0) break;
            if (D_001D5B68 == 2) break;
        } while (1);
    }
    if (D_001D5B68 != 0) {
        if (D_001D5B68 == 1) {
            s32 i;
            D_001D9D00 = nl;
            for (i = 0; i < nl && i < 12; i++) {
                D_001D9D08[i] = st[i];
                D_001D9D20[i] = en[i];
                D_001D9D38[i] = sty[i];
            }
        } else {
            s32 i;
            nl = D_001D9D00;
            for (i = 0; i < nl && i < 12; i++) {
                st[i] = D_001D9D08[i];
                en[i] = D_001D9D20[i];
                sty[i] = D_001D9D38[i];
            }
        }
    }
    {
    s32 i, n, w, y;
    o->hC = 0;
    y = o->hA;
    o->hE = nl * o->h10;
    if (o->fl & 2) y -= (s16)o->hE >> 1;
    i = 0;
    if (i < nl) {
        for (; i < nl; i++, y += o->h10) {
            if (y + o->h10 < o->h0) continue;
            if (o->h2 < y) break;
            n = en[i] - st[i] + 1;
            if (len > 0) n = len < n ? len : n;
            w = 0;
            if (D_001D5B68 != 2) w = func_0038E870_0038FD40(text + st[i], n, scale);
            if (D_001D5B68 != 0) {
                if (D_001D5B68 == 1) D_001D9D50[i] = w;
                else w = (s16)D_001D9D50[i];
            }
            if (o->hC < w) o->hC = w;
            if (!(o->fl & 4)) {
                f32 fx, fy;
                u8 save;
                D_001D5B48[0] = (s32)a1;
                fy = (f32)y;
                fx = (f32)o->h8;
                if (o->fl & 1) fx -= (f32)(w >> 1);
                save = D_001D5B40;
                if (o->fl & 8) {
                    fx += (f32)o->h14 * 0.0625f;
                    fy += (f32)o->h16 * 0.0625f;
                    D_001D5B40 = 0;
                }
                func_0038EB10_0038FD40(fx, fy, D_001D5B48[sty[i]], text + st[i], n, scale, scale2, 0, (o->fl >> 5) & 1, a4, (f32)o->h18, (f32)o->h1A);
                D_001D5B40 = save;
            }
            if (len > 0) {
                len -= n;
                if (len <= 0) goto done;
            }
        }
    }
    }
    if (0) {
done:
        ;
    }
    D_001D5B41 = 0;
    if (D_001D5B94 != 1) {
        if (!(o->fl & 0x10)) func_003A9770(0, D_001D4BC0_0038FD40 - 1, 0, D_001D4BC4_0038FD40 - 1);
    }
    D_001D5B68 = 0;
}
/* localdecomp:end func_0038FD40 */

/* localdecomp:start func_003906A8 */
typedef struct { s16 h0, h2, h4, h6, h8, hA, hC, hE, h10; u16 h12; s16 h14, h16; } B_38BB50;
typedef struct { u32 w0, w1; } G_38BB50;
extern s32 D_001D5B94;
extern u8 D_001D5B41;
__asm__(".extern D_001D5B41, 1");
extern s32 D_001D5B48[2];
__asm__(".extern D_001D5B48, 8");
extern s32 D_001D5B5C[];
extern s32 D_001D4BC0[];
extern s32 D_001D4BC4[];
extern void func_003A9770(s32, s32, s32, s32);
extern s32 func_0038E3D0(u8 *p, s32 off, s32 *out);
extern s32 func_0038E870_003906A8(u8 *, s32, f32);
extern void func_0038EB10_003906A8(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
void func_003906A8(B_38BB50 *b, long ca, u8 **strs, s32 n, s16 sel, long cb, s32 *outx, s32 *outy, f32 scale) {
    s16 starts[80];
    s16 ends[80];
    s16 colors[80];
    u8 *lines[80];
    s32 c1, c2;
    s32 lim;
    s32 first;
    s32 nlines;
    s32 j;
    f32 quarter, width;

    if (D_001D5B94 != 1 && !(b->h12 & 0x10)) {
        func_003A9770(b->h4, b->h6 - 1, b->h0, b->h2 - 1);
    }
    first = 1;
    D_001D5B41 = 1;
    lim = -1;
    quarter = scale * 0.25f;
    if ((*(u8 *)&b->h12 ^ 1) & 1) {
        width = (f32)(b->h6 - b->h8);
    } else {
        s32 r = b->h6 - b->h8;
        s32 l = b->h8 - b->h4;
        if (r < l) l = r;
        width = (f32)l;
        width *= 2.0f;
    }
    j = 0;
    do {
        nlines = 0;
        for (; j < n; j++) {
            u8 *s = strs[j];
            s32 pos = 0;
            while (s[pos] != 0 && nlines < 0x4F) {
                s32 k = nlines;
                s32 brk;
                f32 w;
                lines[k] = s;
                starts[k] = pos;
                {
                    s16 *cp = colors + k;
                    if (sel < 0) *cp = 0;
                    else if (sel != j) *cp = 0;
                    else *cp = 5;
                }
                w = 0.0f;
                brk = pos;
                while (w < width) {
                    u8 c = s[pos];
                    if (c == 0x20 || c < 0x10 || c == 0x2F) brk = pos;
                    if (s[pos] < 2) break;
                    pos += func_0038E3D0(s, pos, &c1);
                    {
                        G_38BB50 *g = (G_38BB50 *)(c1 * 8 + *(u32 *)0x1D55C4);
                        if (g->w1 & 0x1F800000) {
                            f32 f = (f32)(s32)(((g->w0 >> 25) + 2) & 0xFC) * quarter;
                            if (first) first = 0;
                            else w -= f;
                            w += (f32)(((*(G_38BB50 **)0x1D55C4)[c1].w1 >> 23) & 0x3F) * scale;
                            func_0038E3D0(s, pos + 1, &c2);
                            if (c2 >= 0x10) {
                                w += (f32)((((*(G_38BB50 **)0x1D55C4)[c1].w1 >> 29) + 2) & 0xFC) * 0.25f * scale;
                            }
                        }
                    }
                    pos++;
                }
                ends[k] = brk;
                if ((s16)brk == starts[k]) ends[k] = pos;
                pos = ends[k];
                if (s[pos] == 0x20 || s[pos] < 0x10) ends[k]--;
                nlines++;
                if (s[pos] == 0) break;
                pos++;
                if (pos == lim) break;
            }
        }
    } while (0);
    {
        s32 y, i;
        {
            s32 t = nlines * b->h10;
            b->hC = 0;
            b->hE = t;
            y = b->hA;
            if (b->h12 & 2) y -= t >> 1;
        }
        for (i = 0; i < nlines; i++) {
            if (y + b->h10 >= b->h0 && b->h2 >= y) {
                s32 len = ends[i] - starts[i] + 1;
                s32 wpx;
                if (lim > 0 && lim < len) len = lim;
                wpx = func_0038E870_003906A8(lines[i] + starts[i], len, 1.0f);
                if (b->hC < wpx) b->hC = wpx;
                if (!(b->h12 & 4)) {
                    u16 fl;
                    D_001D5B48[0] = ca;
                    D_001D5B5C[0] = cb;
                    fl = b->h12;
                    if (fl & 8) {
                        f32 x, yy;
                        u16 hx;
                        if (fl & 1) {
                            x = (f32)(b->h8 - (wpx >> 1)) + (f32)b->h14 * 0.0625f;
                            hx = b->h8;
                        } else {
                            x = (f32)b->h8 + (f32)b->h14 * 0.0625f;
                            hx = b->h8;
                        }
                        yy = (f32)y + (f32)b->h16 * 0.0625f;
                        if (colors[i] == 5) {
                            *outx = (s16)hx;
                            *outy = (s32)yy + (s32)((f32)b->h10 * 0.5f - 0.5f);
                        }
                        func_0038EB10_003906A8(x, yy, D_001D5B48[colors[i]], lines[i] + starts[i], len, scale, scale, 0, 0, 0x80000000UL, 0.0f, 0.0f);
                    } else {
                        if (fl & 1) {
                            func_0038EB10_003906A8((f32)(b->h8 - (wpx >> 1)), (f32)y, D_001D5B48[colors[i]], lines[i] + starts[i], len, scale, scale, 0, 0, 0x80000000UL, 0.0f, 0.0f);
                        } else {
                            func_0038EB10_003906A8((f32)b->h8, (f32)y, D_001D5B48[colors[i]], lines[i] + starts[i], len, scale, scale, 0, 0, 0x80000000UL, 0.0f, 0.0f);
                        }
                        if (colors[i] == 5) {
                            *outx = b->h8;
                            *outy = y + (s32)((f32)b->h10 * 0.5f - 0.5f);
                        }
                    }
                }
                if (lim > 0) {
                    lim -= len;
                    if (lim <= 0) break;
                }
            }
            y += b->h10;
        }
    }
    D_001D5B41 = 0;
    if (D_001D5B94 != 1 && !(b->h12 & 0x10)) {
        func_003A9770(0, D_001D4BC0[0] - 1, 0, D_001D4BC4[0] - 1);
    }
}
/* localdecomp:end func_003906A8 */

/* localdecomp:start func_00390F18 */
extern void func_0038E870();
f32 func_00390F18(s32 a, s32 unused, s32 c, f32 f) {
    f32 r = 1.0f;
    s32 t;
    if (a) t = ((s32 (*)(f32))func_0038E870)(1.0f); else t = 0;
    if (c < t) {
        r = (f32)c / (f32)t;
        if (r < f) r = f;
    }
    return r;
}
/* localdecomp:end func_00390F18 */

/* localdecomp:start func_00390FA8 */
extern void func_0038E510(void);

void func_00390FA8(void) {
    func_0038E510();
}
/* localdecomp:end func_00390FA8 */

/* localdecomp:start func_00390FC8 */
extern void func_0038E6E8();

void func_00390FC8(void) {
    func_0038E6E8(1);
}
/* localdecomp:end func_00390FC8 */

/* localdecomp:start func_00390FE8 */
extern void func_0038E6E8();
 
void func_00390FE8(void) {
    func_0038E6E8(0);
}
/* localdecomp:end func_00390FE8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00391008);

/* localdecomp:start func_00391040 */
extern void func_0038E870();

void func_00391040(void) {
    func_0038E870();
}
/* localdecomp:end func_00391040 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00391060);

/* localdecomp:start func_00391068 */
extern void func_0038E870();
 
void func_00391068(void) {
    func_0038E870();
}
/* localdecomp:end func_00391068 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00391088);

/* localdecomp:start func_00391090 */
extern void func_0038E870();
 
void func_00391090(s32 a, s32 b, s32 c, f32 d) {
    func_0038E870();
}
/* localdecomp:end func_00391090 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003910B0);

/* localdecomp:start func_003910D8 */
extern void func_0038EB10(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
extern void func_0038E870();
s32 func_003910D8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    ((void (*)(float, float, float, float, float, float, s32, s32, s32, s32, s32, unsigned long))func_0038EB10)((float)a0, (float)a1, 1.0f, 1.0f, 0.0f, 0.0f, a2, a3, a4, 1, 0, 0x80000000UL);
    return a0 - (((s32 (*)(s32, s32, float))func_0038E870)(a3, a4, 1.0f) >> 1);
}
/* localdecomp:end func_003910D8 */

/* localdecomp:start func_00391180 */
extern s32 D_001D55E8;
extern void func_0038E478(s32);
extern void func_0038EB10_00391180(s32, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32);
extern s32 func_0038E870_00391180(s32, s32, f32);
s32 func_00391180(s32 x, s32 y, s32 a, s32 b, s32 c) {
    s32 saved;
    saved = D_001D55E8;
    func_0038E478(1);
    func_0038EB10_00391180(a, b, c, 1, 0, 0x80000000UL, (f32)x, (f32)y, 1.0f, 1.0f, 0.0f, 0.0f);
    x -= func_0038E870_00391180(b, c, 1.0f) >> 1;
    func_0038E478(saved);
    return x;
}
/* localdecomp:end func_00391180 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00391260);

/* localdecomp:start func_00391270 */
extern void func_0038EB10(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
void func_00391270(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, f32 p) {
    func_0038EB10((f32)a0, (f32)a1, p, p, a2, a3, a4, 1, 0, 0x80000000, 0.0f, 0.0f);
}
/* localdecomp:end func_00391270 */

/* localdecomp:start func_003912D0 */
__asm__(".extern D_001D55E8, 4");
extern s32 D_001D55E8;
extern void func_0038E478(s32);
void func_003912D0(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 save;
    save = D_001D55E8;
    func_0038E478(1);
    ((void (*)(s32, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32))func_0038EB10)(c, d, e, 0, 0, 0x80000000, (f32)a, (f32)b, 1.0f, 1.0f, 0.0f, 0.0f);
    func_0038E478(save);
}
/* localdecomp:end func_003912D0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00391388);

/* localdecomp:start func_00391398 */
extern void func_0038EB10(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
void func_00391398(s32 a0, s32 a1, s32 a2, f32 x, f32 y, f32 z) {
    func_0038EB10(x, y, z, z, a0, a1, a2, 0, 0, 0x80000000, 0.0f, 0.0f);
}
/* localdecomp:end func_00391398 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003913D0);

/* localdecomp:start func_003913E0 */
void func_003913E0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    func_0038FD08(p, a, b, c, d, e, f, g, h);
}
/* localdecomp:end func_003913E0 */

/* localdecomp:start func_00391400 */
extern void func_0038FD40(s32, s32, s32, s32, unsigned long, s32, f32, f32);
void func_00391400(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g) {
    func_0038FD40(a, b, c, d, 0x80000000, g, 1.0f, 1.0f);
}
/* localdecomp:end func_00391400 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00391430);

/* localdecomp:start func_00391450 */
extern s32 D_001D55E8;
extern void func_0038E478(s32);
extern void func_0038FD40(s32, s32, s32, s32, unsigned long, s32, f32, f32);
void func_00391450(s32 a, s32 b, s32 c, s32 d) {
    s32 old = D_001D55E8;
    func_0038E478(1);
    ((void (*)(s32, s32, s32, s32, f32, f32, unsigned long))func_0038FD40)(a, b, c, d, 1.0f, 1.0f, 0x80000000UL);
    func_0038E478(old);
}
/* localdecomp:end func_00391450 */

/* localdecomp:start func_003914D8 */
extern void func_0038FD40(s32, s32, s32, s32, unsigned long, s32, f32, f32);
void func_003914D8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g) {
    func_0038FD40(a, b, c, d, 0x80000000, g, 1.0f, 1.0f);
}
/* localdecomp:end func_003914D8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00391508);

/* localdecomp:start func_00391510 */
extern void func_0038FD40(s32, s32, s32, s32, unsigned long, s32, f32, f32);
void func_00391510(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g, s32 h, f32 x) {
    func_0038FD40(a, b, c, d, h, g, x, x);
}
/* localdecomp:end func_00391510 */

/* localdecomp:start func_00391530 */
extern void func_003906A8();
void func_00391530(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s16 g, long h, s32 x, s32 y) {
    func_003906A8(a, b, c, d, g, h, x, y);
}
/* localdecomp:end func_00391530 */

/* localdecomp:start func_00391560 */
extern f32 func_00390F18(s32, s32, s32, f32);
extern void func_0038EB10_00391560(s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, unsigned long, f32);
void func_00391560(s32 x, s32 y, s32 a, s32 b, s32 c, s32 d, f32 p) {
    f32 r = func_00390F18(b, c, d, p);
    func_0038EB10_00391560(a, b, c, (f32)x, (f32)y, r, r, 0.0f, 1, 0, 0x80000000UL, 0.0f);
}
/* localdecomp:end func_00391560 */

/* localdecomp:start func_00391608 */
extern void func_0038E1F8();
 
void func_00391608(void) {
    func_0038E1F8();
}
/* localdecomp:end func_00391608 */

/* localdecomp:start func_00391628 */
extern f32 func_00390F18();
 
void func_00391628(void) {
    func_00390F18();
}
/* localdecomp:end func_00391628 */

/* localdecomp:start func_00391648 */
extern s32 D_00143950[];
extern s32 D_001D5520;
extern void func_12A950(void);
extern void func_12BEE8(s32, s32, s32, s32);
void func_00391648(void) {
    func_12A950();
    if (D_00143950[0]) D_001D5520 = 0;
    if (D_001D5520) func_12BEE8(0, 0, 0x50, 1);
    else func_12BEE8(0, 1, D_00143950[0] ? 3 : 2, 0);
}
/* localdecomp:end func_00391648 */

/* localdecomp:start func_003916B8 */
extern s32 D_001D4D08[];
extern s32 D_001D4D0C[];
extern s32 D_001D4D10[];
extern s32 D_001D4D14[];
extern s32 D_001D4D18[];
extern s32 D_001D4D1C[];
extern s32 D_001D4CF8[];
void func_003916B8(void) {
    *(unsigned long *)((u8 *)D_001D4CF8[0] + 0x18) = (long)D_001D4D08[0] | ((long)D_001D4D0C[0] << 12) | ((long)D_001D4D10[0] << 23) | ((long)D_001D4D14[0] << 27) | ((long)D_001D4D18[0] << 32) | ((long)D_001D4D1C[0] << 44);
}
/* localdecomp:end func_003916B8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00391720);

/* localdecomp:start func_00391728 */
extern s32 D_001D4D08_00391728;
extern s32 D_001D4D0C_00391728;
extern void func_003916B8(void);
void func_00391728(s32 dx, s32 dy, s32 clamp) {
    D_001D4D08_00391728 += dx; D_001D4D0C_00391728 += dy; if (clamp) { s32 x = D_001D4D08_00391728 >= 0 ? D_001D4D08_00391728 : 0; s32 y = D_001D4D0C_00391728 >= 0 ? D_001D4D0C_00391728 : 0; D_001D4D08_00391728 = x <= 3000 ? x : 3000; D_001D4D0C_00391728 = y <= 450 ? y : 450; }
    func_003916B8();
}
/* localdecomp:end func_00391728 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003917B0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003917C0);

/* localdecomp:start func_00391998 */
typedef int Q_38CE40 __attribute__((mode(TI)));
typedef struct { unsigned long v : 9; unsigned long r : 55; } FB_38CE40;
typedef struct {
    unsigned long dx : 12;
    unsigned long dy : 11;
    unsigned long magh : 4;
    unsigned long magv : 2;
    unsigned long p0 : 3;
    unsigned long dw : 12;
    unsigned long dh : 11;
    unsigned long p1 : 9;
} DI_38CE40;
typedef struct {
    unsigned long nloop : 15;
    unsigned long eop : 1;
    unsigned long p0 : 16;
    unsigned long id : 14;
    unsigned long pre : 1;
    unsigned long prim : 11;
    unsigned long flg : 2;
    unsigned long nreg : 4;
    unsigned long regs0 : 4;
    unsigned long regs : 60;
} GT_38CE40;
typedef struct {
    u8 p0[0x10];
    FB_38CE40 q10;
    DI_38CE40 q18;
    u8 p20[0x10];
    GT_38CE40 t30;
    FB_38CE40 q40;
    unsigned long q48;
    unsigned long q50;
    u8 p58[0x68];
    GT_38CE40 tC0;
    FB_38CE40 qD0;
    unsigned long qD8;
    unsigned long qE0;
    u8 pE8[0x68];
    s16 h150, h152, h154, h156, h158, h15A, h15C, h15E;
    s16 h160, h162, h164, h166, h168, h16A, h16C, h16E;
    s32 w170;
} E_38CE40;

extern E_38CE40 D_001CFEC0_00391998[];
extern E_38CE40 *D_001D4CF8_00391998;
extern s32 D_001A1ED0_00391998[];
extern s32 D_001D5520;
extern u8 D_001D551D;
extern s32 D_001D4D08_00391998;
extern s32 D_001D4D0C_00391998;
extern s32 D_001D4D10_00391998;
extern s32 D_001D4D14_00391998;
extern s32 D_001D4D18_00391998;
extern s32 D_001D4D1C_00391998;
extern s32 D_001D4D20_00391998;
extern s32 D_001D4D24_00391998;
extern s32 D_001D4D28_00391998;
extern s32 D_001D4D2C_00391998;
extern s32 D_001D4D30_00391998;
extern s32 D_001D4D34_00391998;
extern unsigned long D_001D02D0_00391998[];
extern unsigned long D_001D0070_00391998[];
extern unsigned long D_001D07B0_00391998[];
extern unsigned long D_001D0900_00391998[];
extern unsigned long D_00141850_00391998[];
extern unsigned long D_00141990_00391998[];
extern unsigned long D_00141AD0_00391998[];
extern unsigned long D_00141DC0_00391998[];
extern unsigned long D_001420B0_00391998[];
extern void func_0012C138(void *, s32, s16, s16, s16, s16);
extern void func_0012C638(s32, s32, s32, s32, s32, s32);
extern void func_003916B8(void);
extern void func_003917C0(s32, s32);
extern void func_0038CFB0();
extern void func_11F0A0(s32);
void func_00391998(s32 w, s32 h, s32 a2, s32 a3, s32 a4, s32 a5) {
    unsigned long *b;
    s32 r0 = D_001A1ED0_00391998[0] >> 13;
    D_001CFEC0_00391998->h150 = w;
    D_001CFEC0_00391998->h152 = h;
    D_001CFEC0_00391998->h15C = 1;
    D_001CFEC0_00391998->h16C = 0x31;
    D_001CFEC0_00391998->h15E = r0;
    D_001CFEC0_00391998->h156 = D_001A1ED0_00391998[1] >> 13;
    D_001CFEC0_00391998->h16E = D_001A1ED0_00391998[2] >> 13;
    D_001D4CF8_00391998 = D_001CFEC0_00391998;
    D_001CFEC0_00391998->w170 = 0;
    D_001CFEC0_00391998->h158 = a2;
    D_001CFEC0_00391998->h15A = a3;
    D_001CFEC0_00391998->h168 = a4;
    D_001CFEC0_00391998->h16A = a5;
    D_001CFEC0_00391998->h154 = 0;
    D_001CFEC0_00391998->h164 = 0;
    func_0012C138(D_001CFEC0_00391998, 1, a2, a3, a4, a5);
    D_001D4CF8_00391998->q10.v = D_001CFEC0_00391998->h15E;
    if (D_001D5520 != 0) {
        *(unsigned long *)&D_001D4CF8_00391998->q18 = 0x1BF4FF00834140UL;
    }
    if (D_001D551D == 0) {
        D_001D4D08_00391998 = *(unsigned long *)((u8 *)D_001D4CF8_00391998 + 0x18) & 0xFFF;
        D_001D4D0C_00391998 = (*(unsigned long *)((u8 *)D_001D4CF8_00391998 + 0x18) >> 12) & 0x7FF;
    }
    D_001D4D10_00391998 = (*(unsigned long *)((u8 *)D_001D4CF8_00391998 + 0x18) >> 23) & 0xF;
    D_001D4D14_00391998 = (*(unsigned long *)((u8 *)D_001D4CF8_00391998 + 0x18) >> 27) & 0x3;
    D_001D4D18_00391998 = (*(unsigned long *)((u8 *)D_001D4CF8_00391998 + 0x18) >> 32) & 0xFFF;
    D_001D4D1C_00391998 = (*(unsigned long *)((u8 *)D_001D4CF8_00391998 + 0x18) >> 44) & 0x7FF;
    D_001D4D20_00391998 = D_001D4D08_00391998;
    D_001D4D24_00391998 = D_001D4D0C_00391998;
    D_001D4D28_00391998 = D_001D4D10_00391998;
    D_001D4D2C_00391998 = D_001D4D14_00391998;
    D_001D4D30_00391998 = D_001D4D18_00391998;
    D_001D4D34_00391998 = D_001D4D1C_00391998;
    if (D_001D551D != 0) {
        func_003916B8();
    }
    func_0012C638((s32)&D_001D4CF8_00391998->q40, D_001CFEC0_00391998->h154, D_001CFEC0_00391998->h150, D_001CFEC0_00391998->h152, 3, D_001CFEC0_00391998->h16C);
    D_001D4CF8_00391998->q40.v = D_001CFEC0_00391998->h156;
    *(unsigned long *)((u8 *)D_001D4CF8_00391998 + 0x50) = D_001CFEC0_00391998->h16E | ((long)(D_001CFEC0_00391998->h16C & 0xF) << 24);
    *(Q_38CE40 *)((u8 *)D_001D4CF8_00391998 + 0x30) = 0;
    {
        E_38CE40 *p = D_001D4CF8_00391998;
        p->t30.nloop = 8;
        p->t30.eop = 1;
        p->t30.nreg = 1;
        p->t30.regs0 = 0xE;
        func_0012C638((s32)&p->qD0, D_001CFEC0_00391998->h15C, D_001CFEC0_00391998->h158, D_001CFEC0_00391998->h15A, 0, 0);
    }
    {
        E_38CE40 *p = D_001D4CF8_00391998;
        p->qD0.v = D_001CFEC0_00391998->h15E;
        *(unsigned long *)((u8 *)p + 0xE0) = 0x8000UL << 17;
    }
    *(Q_38CE40 *)((u8 *)D_001D4CF8_00391998 + 0xC0) = 0;
    {
        E_38CE40 *p = D_001D4CF8_00391998;
        p->tC0.nloop = 8;
        p->tC0.eop = 1;
        p->tC0.nreg = 1;
        p->tC0.regs0 = 0xE;
    }
    b = D_001D02D0_00391998;
    b[0] = (((0x8156UL << 16) | 0x8000) << 31) | 1;
    b[1] = 0xEEEE;
    b[2] = 0x30000;
    b[3] = 0x47;
    b[4] = 5;
    b[5] = 8;
    b[6] = (0x8000UL << 17) | 0x261;
    b[7] = 0x14;
    b[8] = ((long)D_001D4CF8_00391998->h156 << 5) | ((long)(((u16)D_001D4CF8_00391998->h150 >> 6) & 0x3F) << 14) | ((long)D_001D4CF8_00391998->h154 << 20) | (0xEA80UL << 20);
    b[9] = 6;
    b[10] = (0x8800UL << 47) | 0x8010;
    b[11] = 0x5353;
    if (D_001D5520 != 0) {
        s32 n = 12;
        s32 i;
        for (i = 0; i < 16; i++) {
            s32 xa = i * 0x280 + 0x7FF8;
            s32 xb = (i + 1) * 0x280 + 0x7FF8;
            b[n++] = i * D_001D4CF8_00391998->h150;
            b[n++] = (xa - (D_001D4CF8_00391998->h158 << 3)) | ((long)(0x7FF8 - (D_001D4CF8_00391998->h15A << 3)) << 16);
            b[n++] = ((i + 1) * D_001D4CF8_00391998->h150) | ((long)D_001D4CF8_00391998->h152 << 20);
            b[n++] = (xb - (D_001D4CF8_00391998->h158 << 3)) | ((long)((D_001D4CF8_00391998->h15A << 3) + 0x7FF8) << 16);
        }
    } else {
        s32 n = 12;
        s32 i;
        for (i = 0; i < 16; i++) {
            b[n++] = i * D_001D4CF8_00391998->h150;
            {
                s32 w = D_001D4CF8_00391998->h158;
                s32 t = i * w + 0x7FF8;
                b[n++] = (t - (w << 3)) | ((long)(0x7FF8 - (D_001D4CF8_00391998->h15A << 3)) << 16);
            }
            b[n++] = ((i + 1) * D_001D4CF8_00391998->h150) | ((long)D_001D4CF8_00391998->h152 << 20);
            {
                s32 w = D_001D4CF8_00391998->h158;
                s32 t = (i + 1) * w + 0x7FF8;
                b[n++] = (t - (w << 3)) | ((long)((D_001D4CF8_00391998->h15A << 3) + 0x7FF8) << 16);
            }
        }
    }
    b[0x4C] = (0x8800UL << 47) | 0x8001;
    b[0x4D] = 0x4410;
    b[0x4E] = 0x181;
    b[0x4F] = 0x8000UL << 16;
    b[0x50] = (0x7FF8 - (D_001D4CF8_00391998->h158 << 3)) | ((long)(0x7FF8 - (D_001D4CF8_00391998->h15A << 3)) << 16);
    b[0x51] = (0x7FF8 - (D_001D4CF8_00391998->h158 << 3)) | ((long)((D_001D4CF8_00391998->h15A << 3) + 0x7FF8) << 16);
    func_003917C0(0, 0);
    b = D_001D0070_00391998;
    b[0] = (((0x8116UL << 16) | 0x8000) << 31) | 1;
    b[1] = 0xEEEE;
    b[2] = 0x31001;
    b[3] = 0x47;
    b[4] = 5;
    b[5] = 8;
    b[6] = (0x8000UL << 17) | 0x261;
    b[7] = 0x14;
    b[8] = ((long)D_001D4CF8_00391998->h156 << 5) | ((long)(((u16)D_001D4CF8_00391998->h150 >> 6) & 0x3F) << 14) | ((long)D_001D4CF8_00391998->h154 << 20) | (0xEA80UL << 20);
    b[9] = 6;
    b[10] = (0x8800UL << 47) | 0x8010;
    b[11] = 0x5353;
    {
        s32 n = 12;
        s32 i;
        for (i = 0; i < 16; i++) {
            b[n++] = i << 9;
            b[n++] = (0x6FFC + i * 0x200) | ((long)(0x7FFC - (D_001D4CF8_00391998->h152 << 3)) << 16);
            b[n++] = (0x200 + i * 0x200) | ((long)D_001D4CF8_00391998->h152 << 20);
            b[n++] = (0x71FC + i * 0x200) | ((long)((D_001D4CF8_00391998->h152 << 3) + 0x7FFC) << 16);
        }
    }
    b = D_001D07B0_00391998;
    b[0] = (0x8000UL << 45) | 1;
    b[1] = 0xE;
    b[2] = 0x30000;
    b[3] = 0x47;
    b[4] = (0x9000UL << 46) | 0x8001;
    b[5] = 0x10;
    b[6] = 0x106;
    b[7] = 0x8000UL << 16;
    b[8] = (0x9000UL << 46) | 0x8010;
    b[9] = 0x44;
    {
        s32 n = 10;
        s32 i;
        for (i = 0; i < 16; i++) {
            b[n++] = (0x6FF8 + i * 0x200) | ((long)(0x7FF8 - (D_001D4CF8_00391998->h152 << 3)) << 16);
            b[n++] = (0x71F8 + i * 0x200) | ((long)((D_001D4CF8_00391998->h152 << 3) + 0x7FF8) << 16);
        }
    }
    func_0038CFB0(D_001D0900_00391998, D_001D07B0_00391998, 0x150);
    b = D_00141850_00391998;
    {
        s32 n = 8;
        s32 i;
        for (i = 0; i < 16; i++) {
            b[n++] = (0x6FF8 + i * 0x200) | ((long)(0x7FF8 - (D_001D4CF8_00391998->h152 << 3)) << 16);
            b[n++] = (0x71F8 + i * 0x200) | ((long)((D_001D4CF8_00391998->h152 << 3) + 0x7FF8) << 16);
        }
    }
    b = D_00141990_00391998;
    {
        s32 n = 8;
        s32 i;
        for (i = 0; i < 16; i++) {
            if (D_001D5520 != 0) {
                b[n++] = (i * 0x280 + 0x6BF8) | ((long)(0x7FF8 - (D_001D4CF8_00391998->h15A << 3)) << 16);
                b[n++] = ((i + 1) * 0x280 + 0x6BF8) | ((long)((D_001D4CF8_00391998->h15A << 3) + 0x7FF8) << 16);
            } else {
                b[n++] = ((i << 9) + 0x6FF8) | ((long)(0x7FF8 - (D_001D4CF8_00391998->h15A << 3)) << 16);
                b[n++] = (((i + 1) << 9) + 0x6FF8) | ((long)((D_001D4CF8_00391998->h15A << 3) + 0x7FF8) << 16);
            }
        }
    }
    b = D_00141AD0_00391998;
    {
        s32 n = 0x18;
        s32 i;
        u32 u, v;
        v = 0;
        u = 0;
        for (i = 0; i < 16; i++) {
            b[n++] = u;
            b[n++] = v;
            u += 0x200;
            b[n++] = u | ((long)D_001D4CF8_00391998->h152 << 20);
            v += 0x100;
            b[n++] = v | 0x10000000;
        }
    }
    b = D_00141DC0_00391998;
    {
        s32 n = 0x18;
        s32 i;
        u32 u, v;
        v = 0;
        u = 0;
        for (i = 0; i < 16; i++) {
            b[n++] = u;
            b[n++] = v;
            u += 0x200;
            b[n++] = u | ((long)D_001D4CF8_00391998->h152 << 20);
            v += 0x40;
            b[n++] = v | 0x4000000;
        }
    }
    {
        s32 x = D_001A1ED0_00391998[1];
        D_001420B0_00391998[2] = ((long)x >> 13) | (((((0xFFFFUL << 16) | 0xFF00) << 20) | 0x8000) << 4);
        D_001420B0_00391998[10] = (long)((x >> 8) | 0x24020000) | (0xC800UL << 19);
    }
    func_11F0A0(0);
}
/* localdecomp:end func_00391998 */

/* localdecomp:start func_00392580 */
extern unsigned long D_001D07E8[];
void func_00392580(s32 arg0, long arg1, long arg2) {
    D_001D07E8[0] = arg0 | (arg1 << 8) | (arg2 << 0x10) | (unsigned long)0x80000000;
}
/* localdecomp:end func_00392580 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003925A8);

/* localdecomp:start func_003925B0 */
extern void func_12C4B0(s32);
extern s32 D_001D4CF8[];

void func_003925B0(void) {
    func_12C4B0(D_001D4CF8[0]);
}
/* localdecomp:end func_003925B0 */

/* localdecomp:start func_003925D8 */
extern u32 *D_001DA0D0;
extern s32 D_001D4CF8_003925D8; 
extern void func_12C820(s32);

void func_003925D8(void) {
    if (D_001DA0D0 != 0) {
        D_001DA0D0[0] = 0x30000009;
        D_001DA0D0[1] = (D_001D4CF8_003925D8 + 0x30) & 0xFFFFFFF;
        D_001DA0D0[2] = 0;
        D_001DA0D0[3] = 0x50000009;
        D_001DA0D0 += 4;
    } else {
        func_12C820(D_001D4CF8_003925D8 + 0x30);
    }
}
/* localdecomp:end func_003925D8 */

/* localdecomp:start func_00392670 */
extern u32 *D_001DA0D0;
extern u8 D_1D07B0[], D_1D0900[];
void func_00392670(s32 a) {
    if (D_001DA0D0 != 0) {
        D_001DA0D0[0] = 0x30000015;
        if (a == 0) D_001DA0D0[1] = (u32)D_1D07B0;
        else D_001DA0D0[1] = (u32)D_1D0900;
        D_001DA0D0[2] = 0;
        D_001DA0D0[3] = 0x50000015;
        D_001DA0D0 += 4;
    }
}
/* localdecomp:end func_00392670 */

/* localdecomp:start func_003926F0 */
extern u32 *D_001DA0D0;
extern s32 D_001D4CF8_003926F0;
void func_003926F0(void) {
    D_001DA0D0[0] = 0x30000009;
    D_001DA0D0[1] = (D_001D4CF8_003926F0 + 0xC0) & 0xFFFFFFF;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0x50000009;
    D_001DA0D0 += 4;
}
/* localdecomp:end func_003926F0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00392760);

/* localdecomp:start func_00392A08 */
extern u32 *D_001DA0D0;
extern u8 D_001D0070[];
void func_00392A08(void) {
    D_001DA0D0[0] = 0x30000026;
    D_001DA0D0[1] = (u32)D_001D0070;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0x50000026;
    D_001DA0D0 += 4;
}
/* localdecomp:end func_00392A08 */

/* localdecomp:start func_00392A68 */
extern u32 *D_001DA0D0;
extern u8 D_001D7370[];
extern u8 D_001D7390[];
extern u8 D_001D02D0[];
extern u8 D_001D7300[];
void func_00392A68(s32 a0) {
    D_001DA0D0[0] = 0x30000002;
    if (a0 != 0) {
        D_001DA0D0[1] = (u32)D_001D7370;
    } else {
        D_001DA0D0[1] = (u32)D_001D7390;
    }
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
/* localdecomp:end func_00392A68 */

/* localdecomp:start func_00392B88 */
extern u32 *D_001DA0D0_00392B88;
extern void func_003A96B0(s32, unsigned long);
void func_00392B88(s32 x, s32 y) {
    s32 n = x / 32;
    unsigned long *p, *q, *r;
    s32 i, a, b, lo, hi;
    func_003A96B0(0x42, (0x8000UL << 24) | 0x4A);
    D_001DA0D0_00392B88[0] = (n + 5) | 0x10000000;
    D_001DA0D0_00392B88[1] = 0;
    D_001DA0D0_00392B88[2] = 0;
    D_001DA0D0_00392B88[3] = (n + 5) | 0x50000000;
    p = (unsigned long *)D_001DA0D0_00392B88;
    r = p + 2;
    D_001DA0D0_00392B88 = (u32 *)r;
    p[2] = (0x8000UL << 45) | 1;
    r[1] = 0xE;
    r[2] = 0x32003;
    r[3] = 0x47;
    r[4] = (0x9000UL << 46) | 1;
    r[5] = 0x10;
    r[6] = 0x146;
    r[7] = (0x8000UL << 16) | 0x8080;
    r[8] = n | 0x8000 | (0x9000UL << 46);
    r[9] = 0x44;
    i = 0;
    if (n > i) {
        unsigned long t0, t1;
        a = y * 8;
        t0 = (unsigned long)(0x8000 - a) << 16;
        t1 = (unsigned long)(a + 0x7FF0) << 16;
        b = -(x * 8);
        lo = b + 0x8000;
        hi = b + 0x8200;
        q = p + 12;
        do {
            *q++ = lo | t0;
            *q++ = hi | t1;
            hi += 0x200;
            lo += 0x200;
            i++;
        } while (i < n);
    }
    D_001DA0D0_00392B88 += n * 4 + 0x14;
}
/* localdecomp:end func_00392B88 */

/* localdecomp:start func_00392D38 */
extern s32 D_001D5C78;
s32 func_00392D38(void) { s32 v = D_001D5C78; if (v != 0) return v + 0x7090; return 0; }
/* localdecomp:end func_00392D38 */

/* localdecomp:start func_00392D58 */
void *func_00392D58(p) u8 *p; {  /* K&R: a later caller uses an unprototyped call */
    void *r;
    *(s32 *)(p + 0x58) = 0; *(s32 *)(p + 0x5C) = 0; *(s32 *)(p + 0x60) = 0;
    r = ((void *(*)(void *, s32, s32))func_0011A264)(p + 8, 0xCD, 0x50);
    p[0x6C] = 0; *(s32 *)(p + 0x68) = 1;
    return r;
}
/* localdecomp:end func_00392D58 */

/* localdecomp:start func_00392DA0 */
typedef struct { s32 a, b; } E_38E;
typedef struct { u8 pad[8]; E_38E e[10]; s32 f58, f5C, f60, f64, f68; u8 f6C; } S_38E;
s32 func_00392DA0(S_38E *p, s32 *a, s32 *b) {
    s32 i;
    if (p->f60 == 0) return 0;
    if (--p->f60 == 0) p->f6C = 0;
    *a = p->e[p->f5C].a;
    *b = p->e[p->f5C].b;
    p->e[p->f5C].a = -1;
    p->e[p->f5C].b = -1;
    i = p->f5C + 1;
    if (i == 10) i = 0;
    p->f5C = i;
    return 1;
}
/* localdecomp:end func_00392DA0 */

/* localdecomp:start func_00392E40 */
s32 func_00392E40(S_38E *p, s32 v) {
    s32 i, n;
    if (p->f60 == 10 || p->f6C != 0) return 0;
    p->e[p->f58].a = v;
    p->e[p->f58].b = v >= 100;
    i = p->f58 + 1;
    n = p->f60 + 1;
    if (i == 10) i = 0;
    p->f60 = n;
    p->f58 = i;
    return 1;
}
/* localdecomp:end func_00392E40 */

/* localdecomp:start func_00392EB8 */
extern void *func_00392D58();
 
void func_00392EB8(s32 *p) {
    func_00392D58();
}
/* localdecomp:end func_00392EB8 */

/* localdecomp:start func_00392ED8 */
extern s32 func_0039F1F0();
typedef struct { u8 p0[8]; struct { s32 id; s32 x; } e[10]; s32 head; s32 tail; } S_E380;
extern u8 D_00142BA0[];
void func_00392ED8(S_E380 *s) {
    s32 i = s->tail;
    if (i != s->head) {
        do {
            s32 v = s->e[i].id;
            if (v >= 0) {
                u32 *p = (u32 *)(D_00142BA0 + (((u32)v >> 2) << 2));
                *p |= 1 << (v & 0x1F);
            }
            i = (i + 1 != 10) ? i + 1 : 0;
        } while (i != s->head);
    }
    func_0039F1F0();
}
/* localdecomp:end func_00392ED8 */

/* localdecomp:start func_00392F68 */
extern void func_00392ED8(s32 *);
extern void func_00392EB8(s32 *);
void func_00392F68(s32 *p) {
    func_00392ED8(p);
    *p = 0;
    func_00392EB8(p);
}
/* localdecomp:end func_00392F68 */

/* localdecomp:start func_00392F98 */
typedef struct {
    u8 pad0[0x60];
    s32 active;
    u8 flag64;
    u8 pad65[3];
    s32 mode68;
    u8 flag6C;
} Object_0038E440;

extern s32 D_001D5B94;
extern void func_00392DA0(Object_0038E440 *, s32 *, s32 *);
extern s32 func_003A1180(s32, s32, s32, s32, u8 *);
extern void func_00392EB8(s32 *);

s32 func_00392F98(Object_0038E440 *object) {
    register s32 result __asm__("$17");
    s32 values[2];
    s32 mode;

    if (object->active == 0) {
        goto inactive;
    }
    object->flag64 = 0;
    object->flag6C = 1;
    values[0] = 0;
    result = 0;
    values[1] = 0;
    func_00392DA0(object, &values[0], &values[1]);

    mode = 1;
    if ((u32)(D_001D5B94 - 1) < 2) {
        mode = 2;
    }
    object->mode68 = mode;

    if (values[1] == 0) {
        result = func_003A1180(1, mode, 0, values[0], 0);
    } else if (values[1] == 1) {
        result = func_003A1180(2, mode, values[0], 0, 0);
    }
    if (result < 0) {
        func_00392EB8((s32 *)object);
    }
    return result == 0;
inactive:
    return 0;
}
/* localdecomp:end func_00392F98 */

/* localdecomp:start func_00393060 */
extern s32 func_0039F1F0();

void func_00393060(s32 *input_ptr) {
    s32 *value_ptr = input_ptr;
    register u8 *page_temp __asm__("$2") = (u8 *)0x140000;
    register u8 *page __asm__("$17");
    register u8 *late_base __asm__("$3");
    register s32 output __asm__("$2");
    u8 *base;
    u8 flags;
    s32 value;

    __asm__ volatile("" : "+r"(page_temp));
    base = page_temp + 0x26E0;
    page = page_temp;
    flags = base[0x82];

    if ((flags & 1) == 0) {
        value = *value_ptr;
    } else {
        if (base[0x14] != 0) {
            value = *value_ptr;
            if (value == 3) {
                goto evaluate;
            }
            base[0x82] = flags & 0xFE;
            func_0039F1F0();
        }
        value = *value_ptr;
    }

evaluate:
    if (value == 0xD && *(u8 *)0x1D5587 == 0) {
        output = 0x17;
    } else {
        if (value != 3) {
            return;
        }
        late_base = page + 0x26E0;
        __asm__ volatile("" : "+r"(late_base));
        if ((late_base[0x82] & 1) == 0) {
            return;
        }
        output = 6;
    }
    *value_ptr = output;
}
/* localdecomp:end func_00393060 */

/* localdecomp:start func_00393110 */
__asm__(".extern D_001D5B74, 4");
__asm__(".extern D_001D9D84, 4");
typedef struct { u8 pad[0x18]; s16 h18; u8 pad2[0x17C - 0x1A]; s32 x17C; } S_38E5B8;
extern S_38E5B8 D_00142430_00393110[];
extern s32 D_001D5B74;
extern s32 D_001D9D84;
extern s32 D_001D545C;
extern s32 D_001D4CF0;
extern s32 D_001D4CEC_00393110;
extern void func_00393060(s32 *);
extern void func_00393210(void);
extern void func_0039EEF0(s32, s32);
void func_00393110(s32 a, s32 b) {
    s32 x = a;
    s32 y;
    S_38E5B8 *p;
    func_00393060(&x);
    y = x;
    D_001D5B74 = 1;
    D_001D4CF0 = D_001D545C;
    D_001D9D84 = y;
    if (y == -1) {
        p = D_00142430_00393110;
        if (p->x17C != 0) p->x17C = 0;
        if (p->h18 >= 0) p->h18 = y;
        D_001D4CEC_00393110 &= ~0x200;
    }
    if (b != 0) {
        func_00393210();
        if (x != 0x18) func_0039EEF0(0, D_001D9D84);
        else func_0039EEF0(0, D_001D4CF0);
    }
}
/* localdecomp:end func_00393110 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003931E0);

/* localdecomp:start func_00393210 */
extern u8 D_001D551C;
void func_00393210(void) {
    D_001D551C = 0;
}
/* localdecomp:end func_00393210 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00393218);

/* localdecomp:start func_00393228 */
extern u8 D_001D5BDC;
extern s32 D_001D5C90;
extern s32 D_0022760C;
extern s32 D_001DA0D8;
__asm__(".extern D_0022760C, 16");
__asm__(".extern D_001DA0D8, 16");
s32 func_00393228(u32 value, s32 *result) {
    register u32 amount __asm__("$6") = value;
    register s32 page __asm__("$2");
    register s32 base __asm__("$4");
    register s32 total __asm__("$3");
    if (amount > 0x40000) {
        *result = 0;
        return -1;
    }
    page = D_001D5BDC;
    if (page != 0) {
        page = 0x220000;
        goto calculate;
    }
    page = D_001D5C90;
    if (page != 0) {
        goto cached;
    }
    page = 0x220000;
calculate:
    base = D_001DA0D8;
    __asm__ volatile("" : "+r"(base));
    total = *(s32 *)(page + 0x760C);
    total += base;
    total -= amount;
    *result = total;
    goto done;
cached:
    *result = page;
done:
    return 0;
}
/* localdecomp:end func_00393228 */

/* localdecomp:start func_00393280 */
extern s32 D_001D5C90;
void func_00393280(s32 a) {
    D_001D5C90 = a;
}
/* localdecomp:end func_00393280 */

/* localdecomp:start func_00393288 */
typedef struct LookupEntry_38E730 {
    u16 key;
    u8 reserved[6];
} LookupEntry_38E730;
extern LookupEntry_38E730 *D_001D9F24_00393288[];
s32 func_00393288(s32 key) {
    LookupEntry_38E730 *entry = *D_001D9F24_00393288;
    s32 index = 0;
    if (entry->key != 0xFFFF && entry->key != key) {
        LookupEntry_38E730 *cursor = entry;
        s32 current;
        for (;;) {
            cursor++;
            current = cursor->key;
            index++;
            if (current == 0xFFFF || current == key) break;
        }
    }
    return index <= 0x3FF ? index : -1;
}
/* localdecomp:end func_00393288 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003932E0);

/* localdecomp:start func_003932F0 */
typedef struct { u8 p0[0x14]; s32 a[8]; s32 b[16]; s32 c[1]; } S_0038E798;
typedef struct { u32 w; u32 x; } E_0038E798;
extern S_0038E798 *D_001D9F20_003932F0[];
extern E_0038E798 *D_001D9F2C_003932F0[];
extern E_0038E798 *D_001D9F30_003932F0[];
void func_003932F0(s32 n, s32 size) {
    s32 i;
    s32 j;
    s32 end;
    if (D_001D9F20_003932F0[0]->c[n] == 0) {
        size = (size + 0xF) & 0xFFFFFFF0;
        D_001D9F20_003932F0[0]->c[n] = size;
        i = (n != 0) ? D_001D9F20_003932F0[0]->a[n - 1] : 0;
        end = D_001D9F20_003932F0[0]->a[n];
        for (j = i; j < end; j++) {
            D_001D9F30_003932F0[0][j].w &= 0x7FFFFFFF;
            D_001D9F30_003932F0[0][j].w += size;
        }
        i = (n != 0) ? D_001D9F20_003932F0[0]->b[n - 1] : 0;
        end = D_001D9F20_003932F0[0]->b[n];
        for (j = i; j < end; j++) {
            D_001D9F2C_003932F0[0][j].w &= 0x7FFFFFFF;
            D_001D9F2C_003932F0[0][j].w += size;
        }
    }
}
/* localdecomp:end func_003932F0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00393450);

/* localdecomp:start func_00393458 */
extern u32 D_001D5D50;
u32 func_00393458(void) {
    u32 v = D_001D5D50;
    u32 r = 0;
    if (v <= 0x1CFFFF) r = (0x1D0000 - v) >> 2;
    return r;
}
/* localdecomp:end func_00393458 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00393488);

/* localdecomp:start func_003935B0 */
extern s32 D_00227680[];
extern s32 D_001D9F18;
extern s32 D_001D9F1C;
void func_003935B0(void) {
    s32 a = D_00227680[0];
    D_001D9F18 = a;
    *(volatile s32 *)&D_001D9F1C = a + 0x64000;
}
/* localdecomp:end func_003935B0 */

/* localdecomp:start func_003935E0 */
__asm__(".extern D_001D9F18, 16");
__asm__(".extern D_001D9F1C, 16");
s32 func_003935E0(s32 size) {
    register s32 amount __asm__("$16") = size;
    register s32 current __asm__("$4");
    register s32 result __asm__("$2");
    if (D_001D9F18 == 0) {
        func_003935B0();
    }
    result = D_001D9F1C;
    current = D_001D9F18;
    if (amount > result - current) {
        goto failure;
    }
    {
        register u32 mask __asm__("$3") = 0xfffffff0U;
        register s32 rounded __asm__("$5") = amount + 0xF;
        result = current;
        amount = rounded & mask;
        current += amount;
        D_001D9F18 = current;
        __asm__ volatile("" : : : "memory");
    }
    goto done;
failure:
    result = 0;
    __asm__ volatile("");
done:
    return result;
}
/* localdecomp:end func_003935E0 */
TEXT_PADDING(2);

/* localdecomp:start func_00393668 */
typedef struct { s32 f0; s32 f4; u8 p8[0x18]; s32 f20; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; u8 p3C[0x28]; s32 f64; s32 f68; u8 p6C[4]; s32 f70; u8 p74[8]; s32 f7C; u8 p80[0x10]; } S_EB;
extern S_EB D_00331B60_00393668[];
extern s32 D_001D5B94_00393668;
extern s32 D_001D9F08_00393668;
extern void func_00393770();
s32 func_00393668(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g) {
    S_EB *s = &D_00331B60_00393668[a & 0xF];
    s32 m = a & 0xFFF0;
    if (D_001D5B94_00393668 == 5 && (a & 0xF) != 2 && (a & 0xF) != 0) return 0;
    if (s->f2C != f || s->f28 != g || s->f20 != b || s->f24 != m || s->f30 != c || s->f34 != d || s->f38 != e) {
        s->f2C = f;
        s->f28 = g;
        s->f20 = b;
        s->f30 = c;
        s->f34 = d;
        s->f38 = e;
        s->f64 = D_001D9F08_00393668++;
        s->f68 = 1;
        s->f24 = m;
        s->f7C = 0;
        s->f70 = 0;
        if (m & s->f4 & 0x20) func_00393770(s);
    }
    return s->f64;
}
/* localdecomp:end func_00393668 */

/* localdecomp:start func_00393770 */
typedef struct S_38EC18 {
    s32 pad0;
    s32 v4, v8, vC;
    void (*f10)(struct S_38EC18 *);
    s32 v14, v18, pad1C;
    s32 a20, a24, a28, a2C;
    void (*a30)(struct S_38EC18 *);
    s32 a34, a38;
    s32 pad3C[11];
    s32 x68;
} S_38EC18;
extern void func_00393858();
void func_00393770(S_38EC18 *p) {
    func_00393858(p, p->a20);
    p->v4 = p->a24;
    p->v14 = p->a34;
    p->v18 = p->a38;
    p->vC = p->a2C;
    p->v8 = p->a28;
    p->f10 = p->a30;
    if (p->f10) p->f10(p);
    p->x68 = 0;
}
/* localdecomp:end func_00393770 */

/* localdecomp:start func_003937D8 */
typedef struct { s32 pad0; s32 f4; s32 pad8[7]; s32 f24; s32 pad28[15]; s32 id; s32 f68; s32 pad6C[9]; } S_38ED78;
extern S_38ED78 D_00331B60[];
extern void func_00393668();
s32 func_003937D8(s32 id) {
    s32 i;
    for (i = 0; i < 13; i++) {
        if (D_00331B60[i].id == id) break;
    }
    if (i < 13) {
        func_00393668(i, 0xFFFF, 0, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003937D8 */

/* localdecomp:start func_00393858 */
typedef struct { u16 x0; u16 x2; u16 x4; u8 x6; u8 x7; } E_38ED00;
typedef struct { s32 x0; u8 pad[0x3C]; s16 x40; u8 x42; u8 x43; s32 x44; } S_38ED00;
extern E_38ED00 *D_001D9F24[];
s32 func_00393288(s32);
void func_00393858(S_38ED00 *d, s32 a) {
    s32 i = func_00393288(a);
    if (i < 0) i = 0;
    d->x0 = D_001D9F24[0][i].x0;
    d->x40 = i;
    d->x42 = D_001D9F24[0][i].x6;
    d->x44 = D_001D9F24[0][i].x4;

}
/* localdecomp:end func_00393858 */

/* localdecomp:start func_003938D0 */
void func_003938D0(s32 id, s32 v) {
    s32 i;
    for (i = 0; i < 13; i++) {
        if (D_00331B60[i].id == id) break;
    }
    if (i < 13) {
        D_00331B60[i].f24 = v;
        if (!D_00331B60[i].f68) D_00331B60[i].f4 = v;
    }
}
/* localdecomp:end func_003938D0 */

/* localdecomp:start func_00393940 */
typedef struct { u8 pad[0x58]; s32 w; s32 h; union { s32 flags; u8 c; } u; } S_38EDE8;
s32 func_00393940(S_38EDE8 *p, s32 *x, s32 *y) {
    s32 w = p->w;
    s32 h = p->h;
    if ((p->u.c ^ 1) & 1) {
        if (!(p->u.flags & 2)) *y -= h >> 1;
    }
    if (!(p->u.flags & 4)) {
        if (p->u.flags & 8) *x -= w;
        else *x -= w >> 1;
    }
    return 0;
}
/* localdecomp:end func_00393940 */

/* localdecomp:start func_003939B0 */
typedef struct { u8 p0[0x58]; s32 f58; s32 f5C; u32 f60; u8 p64[0x18]; s32 f7C; } S_38EE58;
extern f32 D_003322B0[];
extern f32 D_00332310[];
void func_003939B0(S_38EE58 *o, s32 *px, s32 *py, s32 v, s32 d) {
    s32 dx = 0;
    s32 dy = 0;
    f32 sc;
    u32 fl;
    if (o->f7C) v -= d; else v += d;
    if (v < 0) v = 0;
    if (v >= 0x18) v = 0x17;
    if (o->f7C) sc = D_003322B0[v]; else sc = D_00332310[v];
    fl = o->f60;
    if (fl & 1) dy = -(s32)(sc * ((f32)o->f5C + 52.0f) + 0.5f);
    else if (fl & 2) dy = (s32)(sc * ((f32)o->f5C + 52.0f) + 0.5f);
    else if (fl & 4) dx = -(s32)(sc * ((f32)o->f58 + 20.0f) + 0.5f);
    else if (fl & 8) dx = (s32)(sc * ((f32)o->f58 + 20.0f) + 0.5f);
    *px += dx;
    *py += dy;
}
/* localdecomp:end func_003939B0 */

/* localdecomp:start func_00393B28 */
typedef struct { u8 p0[8]; s32 f8; s32 *fC; u8 p1[0x48]; s32 f58; s32 f5C; s32 f60; u8 p2[0x10]; s32 f74; s32 f78; } S;
void func_00393B28(void *arg) {
    S *s = (S *)arg;
    s32 *q;
    s32 n, x, a, t;
    q = s->fC;
    if (q != 0 && ((s32)q & 3) == 0) {
        s->f78 = *q;
        if (s->f8 < s->f78) s->f78 = s->f8;
        s->f74 = s->f78;
    } else {
        s->f78 = 99999;
        s->f74 = 99999;
    }
    n = 0;
    x = s->f8;
    a = s->f60;
    t = s->f5C;
    if (x >= 10) {
        do { x /= 10; n++; } while (x >= 10);
    }
    if ((a & 3) == 0 && (a & 0xC) != 0) {
        s->f5C = t + (n + 1) * 12;
        if (s->f58 < 0xE) s->f58 = 0xE;
    } else {
        if (t < 12) s->f5C = 12;
        s->f58 = s->f58 + (n + 1) * 14;
    }
}
/* localdecomp:end func_00393B28 */

/* localdecomp:start func_00393C18 */
extern void func_00393B28(void *);
 
void func_00393C18(void *p) {
    *(s32 *)((u8 *)p + 0x7C) = 0xD2;
    *(s16 *)((u8 *)p + 0x48) = 0;
    *(s16 *)((u8 *)p + 0x4A) = 0;
    func_00393B28(p);
}
/* localdecomp:end func_00393C18 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00393C48);

/* localdecomp:start func_00393C50 */
typedef struct { u8 p0[8]; s32 f8; s32 *fC; u8 p10[0x5C]; s32 f6C; u8 b70[4]; s32 f74; s32 f78; s32 f7C; } S_38F0F8;
extern s32 func_003966C8();
void func_00393C50(S_38F0F8 *p) {
    u8 *b = p->b70;
    if (p->fC) {
        s32 t = *p->fC;
        if (t < 0) t = 0;
        p->f78 = t;
        if (p->f8 < t) p->f78 = p->f8;
    }
    if (p->f74 != p->f78) {
        p->f7C = 180;
        if (p->f6C >= 24) {
            s32 d = __builtin_abs(p->f74 - p->f78);
            if (d != 0) {
                f32 f = (f32)d / 25.0f;
                s32 n = d / 5;
                s32 v;
                f32 r;
                __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(f));
                v = r * 5.0f;
                if (v < n) v = n;
                if (v >= 0x7A) v = 0x79;
                else if (v <= 0) v = 1;
                b[3] += v;
                if (b[3] >= 3) {
                    u8 c = b[3];
                    v = c >> 1;
                    if (p->f78 < p->f74) p->f74 -= v;
                    else p->f74 += v;
                    b[3] -= v * 2;
                }
            }
        }
    }
    if (p->f7C >= 5) {
        if (b[0] < 8) b[0]++;
        else if (b[1] < 8) b[1]++;
    } else {
        if (b[1] != 0 || b[0] != 0) p->f6C = 1;
        if (b[1]) b[1]--;
        else if (b[0]) b[0]--;
    }
    func_003966C8((u8 *)p + 0x40);
}
/* localdecomp:end func_00393C50 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00393E00);

/* localdecomp:start func_00393E68 */
typedef struct { u8 pad[0x38]; u16 h38; u8 pad2[0xF0 - 0x3A]; } S_38F310;
typedef struct { s32 w0; u8 pad[0x14]; s32 w18; } D_393E68;
__asm__(".extern D_001D5D40, 4");
__asm__(".extern D_001D5CAC, 4");
extern s32 D_001D9F68_00393E68;
extern s32 *D_001D9F70_00393E68;
extern s32 D_001D5D40;
extern s32 D_001D5CAC;
extern s32 D_1D4C60[2];
extern s32 D_1D4C80[2];
extern u8 D_001425C0[];
extern S_38F310 D_001DAAC0_00393E68[];
extern D_393E68 D_00331A10[];
void func_00393E68(s32 a) {
    s32 *p;
    s32 i;
    s32 v;
    s32 k;
    S_38F310 *t;
    D_001D9F68_00393E68 = 8;
    D_001D9F70_00393E68 = &D_001D5D40;
    D_001D5CAC = 0;
    p = a ? D_1D4C80 : D_1D4C60;
    for (i = 0; i < 8; i++) {
        k = D_001425C0[p[i]];
        t = D_001DAAC0_00393E68;
        v = t[k].h38;
        D_00331A10[i].w0 = v;
        D_00331A10[i].w18 = p[i];
    }
}
/* localdecomp:end func_00393E68 */

/* localdecomp:start func_00393EF8 */
typedef struct { u8 pad[0x48]; s16 h48; s16 h4A; u8 p2[0x58-0x4C]; s32 w58; s32 w5C; u8 p3[0x70-0x60]; s32 w70; s32 w74; s32 w78; } S_38F3A0;
extern void func_00393E68(s32);
void func_00393EF8(S_38F3A0 *p) {
    func_00393E68(0);
    p->w58 = 0xD2; p->w5C = 0xC8; p->w74 = -2; p->w78 = 30; p->h48 = 0; p->h4A = 0; p->w70 = 0;
}
/* localdecomp:end func_00393EF8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00393F50);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00394918);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C150);

/* localdecomp:start func_00395240 */
extern s32 D_001D9F68[];
extern s32 D_001D9F70[];
extern s32 D_001D5D38;
extern s32 D_001D5CAC;
void func_00395240(u8 *p) {
    D_001D9F68[0] = 4;
    D_001D9F70[0] = (s32)&D_001D5D38;
    *(s32 *)(p + 0x58) = 0xD2;
    *(s32 *)(p + 0x5C) = 0xC8;
    *(s32 *)(p + 0x74) = -2;
    *(s16 *)(p + 0x48) = 0;
    *(s16 *)(p + 0x4A) = 0;
    *(s32 *)(p + 0x78) = 0x1E;
    D_001D5CAC = 0;
}
/* localdecomp:end func_00395240 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00395288);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00395770);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C170);

LINKER_REMNANT("asm/boot_elf/remnants", func_00396538);

/* localdecomp:start func_00396570 */
typedef struct { u8 p0[8]; s32 w8; u8 pC[0x44]; s32 w50; s32 w54; s32 w58; s32 w5C; u8 p60[0xC]; s32 w6C; u8 p70[4]; s32 w74; } O_91A18;
extern s32 func_00396C60();
extern void func_00396F58();
extern void func_003973D0();
extern void func_003939B0();
extern s16 D_001A666A[];
s32 func_00396570(O_91A18 *o) {
    s32 x, y, h;
    x = o->w50;
    y = o->w54;
    o->w58 = 0x100;
    o->w5C = 0x40;
    func_00393940(o, &x, &y);
    func_003939B0(o, &x, &y, o->w6C, 0);
    h = o->w74 * 0xDD / o->w8 + 0x1B;
    func_003973D0(func_00396C60(0x7558, 1), x, y, h, 0x40, 0x80);
    func_00396F58(func_00396C60(0x7558, 0), x, y, 0x100, 0x40, 0x80);
    func_00396F58(func_00396C60(0x7558, 2), x, y, 0x20, 0x20, D_001A666A[0] == 0 ? 0 : 0x80);
    return o->w58;
}
/* localdecomp:end func_00396570 */

/* localdecomp:start func_00396688 */
extern void func_00393B28(void *);
 
void func_00396688(void *p) {
    *(s32 *)((u8 *)p + 0x7C) = 0x96;
    *(s32 *)((u8 *)p + 0x58) = 0x20;
    *(s32 *)((u8 *)p + 0x5C) = 0x20;
    func_00393B28(p);
}
/* localdecomp:end func_00396688 */

/* localdecomp:start func_003966B8 */
s32 func_003966B8(void) {
    return 0;
}
/* localdecomp:end func_003966B8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003966C0);

/* localdecomp:start func_003966C8 */
typedef struct { s16 f0; u8 b2; u8 p3[9]; s32 fC; } O_391B70;
typedef struct { u16 h0; u16 h2; u16 h4; u8 b6; u8 b7; } E_391B70;
extern u8 *D_001D9F24_003966C8;
extern s32 D_001D9D80_003966C8;
extern s32 func_00382868(s32, s32);
s32 func_003966C8(O_391B70 *o) {
    E_391B70 *e = (E_391B70 *)(D_001D9F24_003966C8 + o->f0 * 8);
    s32 r = 0;
    if (e->h0 != 0xFFFF) {
        switch (o->b2) {
        case 0:
            r = e->h4;
            break;
        case 1:
            r = e->h4 + ((D_001D9D80_003966C8 - o->fC) / e->b7) % e->h2;
            break;
        case 2: {
            s32 n = e->h2 * 2;
            r = ((D_001D9D80_003966C8 - o->fC) / e->b7) % (n - 2);
            if (r >= e->h2) {
                s32 u = r + 2;
                r = n - u;
            }
            goto add;
        }
        case 3: {
            s32 t = o->fC;
            do {
                if (t < D_001D9D80_003966C8) {
                    s32 n;
                    r = (D_001D9D80_003966C8 - t) / e->b7;
                    n = e->h2 * 2;
                    if (r < n - 2) {
                        if (r >= e->h2) {
                            s32 u = r + 2;
                            r = n - u;
                        }
                    add:
                        r += e->h4;
                    } else {
                        s32 k;
                        r = e->h4;
                        k = func_00382868(0x1E, t) + 10;
                        o->fC = e->h2 * 2 + k;
                    }
                } else {
                    r = *(s32 *)((u8 *)o + 4);
                }
            } while (0);
        }
        }
    }
    *(s32 *)((u8 *)o + 4) = r;
    return r;
}
/* localdecomp:end func_003966C8 */

/* localdecomp:start func_00396860 */
// near miss: 17 diff, N mode default flags; only regalloc: retail s3=end,s4=-6,s5=10 and lui/addiu of D_00331B60 after the jal; mine s3=10,s4=-6,s5=end and base before jal
typedef struct S_391D08 {
    s32 f0;
    s32 f4;
    u8 p8[0xC];
    void (*f14)(struct S_391D08 *);
    u8 p18[0x50];
    s32 f68;
    s32 f6C;
    u8 p70[0xC];
    s32 f7C;
    u8 p80[0x10];
} S_391D08;
extern S_391D08 D_00331B60_00396860[];
extern s32 D_001D9F0C_00396860;
extern void func_003969D0();
extern void func_00393770();
s32 func_00396860(s32 a0) {
    S_391D08 *s;
    s32 i;
    s32 cnt = 0;
    s32 t;
    s32 ten = 10;
    s32 m6 = -6;
    func_003969D0();
    for (i = 0; i < 13; i++) {
        s = &D_00331B60_00396860[i];
        if ((s->f4 & 0x10) || D_001D9F0C_00396860) {
            if (s->f7C < 10) {
                s->f7C = ten;
            }
        }
        t = s->f7C;
        if (t > 0) {
            t--;
            s->f7C = t;
            if (t > 0) {
                cnt++;
                if (s->f6C < 30) {
                    s->f6C = s->f6C + 1;
                }
                goto skip;
            }
        }
        if (s->f6C >= -5) {
            s->f6C = s->f6C - 1;
        }
skip:
        if (s->f68 != 0 && s->f6C == m6) {
            func_00393770(s);
        }
        if (a0 != 0 && s->f14 != 0) {
            s->f14(s);
        }
    }
    return cnt;
}
/* localdecomp:end func_00396860 */

/* localdecomp:start func_00396988 */
typedef struct {
    u8 pad[0x84];
    u16 f84;
    u8 pad2[0xF0 - 0x86];
} S_391E30;
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern S_391E30 D_001DAAC0[];
s32 func_00396988(void) {
    u8 *b = D_001A4BE0;
    s32 r = *(s32 *)(b + 0x1228);
    u8 f = b[0x25E4];
    u8 *q = (u8 *)D_001425C0 + r;
    S_391E30 *t = D_001DAAC0;
    if (t[*q].f84 == 0) {
        r = 0;
    }
    if (f != 0) {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_00396988 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003969D0);

/* localdecomp:start func_00396B30 */
__asm__(".extern D_001D5B94, 4");
typedef struct { u8 p0[0x18]; void (*f18)(void *); u8 p1c[0x74]; } S_391FD8;
extern S_391FD8 D_00331B60_00396B30[];
extern s32 D_001D9F40;
extern s32 D_001D9C5C;
extern s32 D_001D9F14;
extern s32 D_001D9E78;
extern s32 D_001D9E7C;
extern s32 D_001D9E80;
extern s32 D_001D5B94;
void func_00396B30(void) {
    S_391FD8 *p;
    s32 i;
    if (D_001D9F40 || D_001D9C5C) {
        *(volatile s32 *)&D_001D9F40 = 0;
        return;
    }
    D_001D9F14 = 0xFFFFF0;
    p = D_00331B60_00396B30;
    for (i = 12; i >= 0; i--) {
        if (p->f18) p->f18(p);
        p++;
    }
    if (D_001D9E78 || D_001D9E7C) {
        if (D_001D5B94 == 0) {
            if (D_001D9E78) {
                D_001D9E7C += 0x10;
                if (D_001D9E7C > 0x80) D_001D9E7C = 0x80;
            } else {
                D_001D9E7C -= 0x10;
                if (D_001D9E7C < 0) D_001D9E7C = 0;
            }
            if (D_001D9E78) D_001D9E78--;
            if (D_001D9E78 == 1000) D_001D9E78 = 0;
            return;
        }
    }
    D_001D9E80 = 100;
}
/* localdecomp:end func_00396B30 */

/* localdecomp:start func_00396C60 */
typedef struct { s16 a; s16 b; } P_392108;
typedef struct { s32 w; s32 pad; } W_392108;
extern u8 D_001D5EA5;
extern P_392108 *D_001D9F28[];
extern W_392108 *D_001D9F2C[];
extern W_392108 *D_001D9F30[];
s32 func_00396C60(s32 key, s32 n) {
    s32 r;
    s32 idx;
    u32 mask;
    E_38ED00 *e;
    P_392108 *p;
    if (D_001D5EA5 == 0) {
        r = func_00393288(key);
        D_001D5EA5 = (u32)r >> 31;
        e = (E_38ED00 *)((r << 3) + (s32)D_001D9F24[0]);
        if (e->x0 != 0xFFFF && n < e->x2) {
            idx = e->x4 + n;
            p = (P_392108 *)((idx << 2) + (s32)D_001D9F28[0]);
            if ((D_001D9F30[0][p->a].w & 0x80000000) == 0) {
                return (D_001D9F2C[0][p->b].w & 0x80000000) ? 0 : idx;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_00396C60 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00396D30);

/* localdecomp:start func_00396F58 */
typedef struct { s32 w; u8 pad[2]; u8 b6; u8 b7; } W_392400;
extern P_392108 *D_001D9F28_00396F58;
extern W_392400 *D_001D9F2C_00396F58;
extern u32 *D_001DA0D0;
extern s32 func_00396D30_00396F58();
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern s32 D_001D9F14;
void func_00396F58(s32 idx, s32 x, s32 y, s32 w, s32 h, s32 col) {
    unsigned long *q;
    P_392108 *p = (P_392108 *)((idx << 2) + (s32)D_001D9F28_00396F58);
    W_392400 *e = &D_001D9F2C_00396F58[p->b];
    s32 tw = 1 << e->b6;
    s32 th = 1 << e->b7;
    D_001DA0D0[0] = 0x10000005;
    D_001DA0D0[1] = 0;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0x50000005;
    q = (unsigned long *)(D_001DA0D0 + 4);
    D_001DA0D0 = (u32 *)q;
    q[0] = 0xE800UL << 47 | 0x8001;
    q[1] = 0x5353106;
    q[2] = func_00396D30_00396F58(idx);
    q[3] = 0x156;
    q[4] = ((long)col << 24) | 0x7F7F7F;
    q[5] = 0;
    q[6] = (unsigned long)((x * 16 + D_001D4BD0 - 8) | ((long)(y * 16 + D_001D4BD4 - 8) << 16)) | ((long)D_001D9F14 << 32);
    q[7] = (th << 20) + (tw << 4);
    q[8] = (unsigned long)(((x + w) * 16 + D_001D4BD0 - 8) | ((long)((y + h) * 16 + D_001D4BD4 - 8) << 16)) | ((long)D_001D9F14 << 32);
    q[9] = 0;
    D_001DA0D0 += 0x14;
}
/* localdecomp:end func_00396F58 */

/* localdecomp:start func_00397148 */
typedef int u128_3925F0 __attribute__((mode(TI)));
extern u8 D_001D76F0[];
extern P_392108 *D_001D9F28_00397148;
extern W_392108 *D_001D9F2C_00397148;
extern s32 D_001DA0D0_00397148;
extern s32 D_001D9F14;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern unsigned long func_00396D30(s32);
void func_00397148(s32 idx, s32 x, s32 y, s32 w, s32 h, s32 *uv) {
    P_392108 *p = (P_392108 *)((idx << 2) + (s32)D_001D9F28_00397148);
    u8 *e = (u8 *)&D_001D9F2C_00397148[p->b];
    s32 tw = 1 << e[6];
    s32 th = 1 << e[7];
    u8 *r;
    u8 *pk;
    u8 *q;
    *(s32 *)(D_001DA0D0_00397148 + 0) = 0x10000008;
    *(s32 *)(D_001DA0D0_00397148 + 4) = 0;
    *(s32 *)(D_001DA0D0_00397148 + 8) = 0;
    *(s32 *)(D_001DA0D0_00397148 + 0xC) = 0x50000008;
    r = (u8 *)D_001DA0D0_00397148;
    D_001DA0D0_00397148 = (s32)r + 0x10;
    *(u128_3925F0 *)(r + 0x10) = *(u128_3925F0 *)D_001D76F0;
    pk = (u8 *)D_001DA0D0_00397148;
    q = pk + 0x10;
    D_001DA0D0_00397148 = (s32)q;
    *(unsigned long *)(pk + 0x10) = func_00396D30(idx);
    *(unsigned long *)(q + 8) = 0x15C;
    *(unsigned long *)(q + 0x10) = uv[0];
    *(unsigned long *)(q + 0x18) = 0;
    *(unsigned long *)(q + 0x20) = (unsigned long)((x << 4) + D_001D4BD0 - 8) | ((unsigned long)((y << 4) + D_001D4BD4 - 8) << 16) | ((unsigned long)D_001D9F14 << 32);
    *(unsigned long *)(q + 0x28) = uv[1];
    *(unsigned long *)(q + 0x30) = tw << 4;
    *(unsigned long *)(q + 0x38) = (unsigned long)(((x + w) << 4) + D_001D4BD0 - 8) | ((unsigned long)((y << 4) + D_001D4BD4 - 8) << 16) | ((unsigned long)D_001D9F14 << 32);
    *(unsigned long *)(q + 0x40) = uv[2];
    *(unsigned long *)(q + 0x48) = th << 20;
    *(unsigned long *)(q + 0x50) = (unsigned long)((x << 4) + D_001D4BD0 - 8) | ((unsigned long)(((y + h) << 4) + D_001D4BD4 - 8) << 16) | ((unsigned long)D_001D9F14 << 32);
    *(unsigned long *)(q + 0x58) = uv[3];
    *(unsigned long *)(q + 0x60) = (th << 20) + (tw << 4);
    *(unsigned long *)(q + 0x68) = (unsigned long)(((x + w) << 4) + D_001D4BD0 - 8) | ((unsigned long)(((y + h) << 4) + D_001D4BD4 - 8) << 16) | ((unsigned long)D_001D9F14 << 32);
    D_001DA0D0_00397148 = D_001DA0D0_00397148 + 0x70;
}
/* localdecomp:end func_00397148 */

/* localdecomp:start func_003973D0 */
extern u32 *D_001DA0D0;
extern s32 func_00396D30_003973D0();
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern s32 D_001D9F14;
void func_003973D0(s32 tex, s32 x, s32 y, s32 w, s32 h, s32 alpha) {
    unsigned long *q;
    D_001DA0D0[0] = 0x10000005;
    D_001DA0D0[1] = 0;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0x50000005;
    q = (unsigned long *)(D_001DA0D0 + 4);
    D_001DA0D0 = (u32 *)q;
    q[0] = 0xE800UL << 47 | 0x8001;
    q[1] = 0x5353106;
    q[2] = func_00396D30_003973D0(tex);
    q[3] = 0x156;
    q[4] = ((long)alpha << 24) | 0x7F7F7F;
    q[5] = 0;
    q[6] = (unsigned long)((x * 16 + D_001D4BD0 - 8) | ((long)(y * 16 + D_001D4BD4 - 8) << 16)) | ((long)D_001D9F14 << 32);
    q[7] = (h << 20) + (w << 4);
    q[8] = (unsigned long)(((x + w) * 16 + D_001D4BD0 - 8) | ((long)((y + h) * 16 + D_001D4BD4 - 8) << 16)) | ((long)D_001D9F14 << 32);
    q[9] = 0;
    D_001DA0D0 += 0x14;
}
/* localdecomp:end func_003973D0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00397578);

/* localdecomp:start func_00397598 */
typedef struct { u32 w0; u16 h4; u8 b6; u8 b7; } E_392A40;
extern P_392108 *D_001D9F28_00397598;
extern E_392A40 *D_001D9F2C_00397598;
typedef int Q_392A40 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } V4_392A40;
extern u32 *D_001DA0D0;
extern s32 func_00396D30_00397598();
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern Q_392A40 D_001D76F0_00397598[];
extern f32 func_0038D3C0(f32);
extern f32 func_0038D3D8(f32);
void func_00397598(s32 tex, s32 *col, f32 x, f32 y, f32 w, f32 h, f32 ang) {
    V4_392A40 a, b, c, p0, p1, p2, p3;
    unsigned long *q;
    P_392108 *k = (P_392108 *)((tex << 2) + (s32)D_001D9F28_00397598);
    E_392A40 *e = D_001D9F2C_00397598 + k->b;
    s32 tw = 1 << e->b6;
    s32 th = 1 << e->b7;
    c.x = x;
    c.y = y;
    a.x = h * func_0038D3D8(ang);
    a.y = h * func_0038D3C0(ang);
    b.x = -w * func_0038D3C0(ang);
    b.y = w * func_0038D3D8(ang);
    {
        Q_392A40 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(c));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p3) : "j"(va));
    }
    {
        Q_392A40 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(p3));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p3) : "j"(va));
    }
    {
        Q_392A40 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(c));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(a));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p2) : "j"(va));
    }
    {
        Q_392A40 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(p2));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p2) : "j"(va));
    }
    {
        Q_392A40 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(c));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(a));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p1) : "j"(va));
    }
    {
        Q_392A40 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(p1));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p1) : "j"(va));
    }
    {
        Q_392A40 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(c));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(a));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p0) : "j"(va));
    }
    {
        Q_392A40 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(p0));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(b));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p0) : "j"(va));
    }
    D_001DA0D0[0] = 0x10000008;
    D_001DA0D0[1] = 0;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0x50000008;
    {
        u32 *p = D_001DA0D0;
        Q_392A40 *g = D_001D76F0_00397598;
        D_001DA0D0 = p + 4;
        *(Q_392A40 *)(p + 4) = *g;
    }
    q = (unsigned long *)(D_001DA0D0 + 4);
    D_001DA0D0 = (u32 *)q;
    q[0] = func_00396D30_00397598(tex);
    q[1] = 0x15C;
    q[2] = col[0];
    q[3] = 0;
    q[4] = (unsigned long)(((s32)(p0.x) * 16 + D_001D4BD0 - 8) | ((long)((s32)(p0.y) * 16 + D_001D4BD4 - 8) << 16)) | (0xFFFFF0UL << 32);
    q[5] = col[1];
    q[6] = tw << 4;
    q[7] = (unsigned long)(((s32)(p1.x) * 16 + D_001D4BD0 - 8) | ((long)((s32)(p1.y) * 16 + D_001D4BD4 - 8) << 16)) | (0xFFFFF0UL << 32);
    q[8] = col[2];
    q[9] = th << 20;
    q[10] = (unsigned long)(((s32)(p2.x) * 16 + D_001D4BD0 - 8) | ((long)((s32)(p2.y) * 16 + D_001D4BD4 - 8) << 16)) | (0xFFFFF0UL << 32);
    q[11] = col[3];
    q[12] = (th << 20) + (tw << 4);
    q[13] = (unsigned long)(((s32)(p3.x) * 16 + D_001D4BD0 - 8) | ((long)((s32)(p3.y) * 16 + D_001D4BD4 - 8) << 16)) | (0xFFFFF0UL << 32);
    D_001DA0D0 += 0x1C;
}
/* localdecomp:end func_00397598 */

/* localdecomp:start func_00397930 */
typedef int Q_392DD8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } V4_392DD8;
extern u32 *D_001DA0D0;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern s32 D_001D9F14;
extern f32 func_0038D3C0(f32);
extern f32 func_0038D3D8(f32);
void func_00397930(f32 x, f32 y, f32 w, f32 h, f32 ang, s32 tw, s32 th, s32 tex) {
    V4_392DD8 a, b, c, p0, p1, p2, p3;
    unsigned long *q;
    c.x = x;
    c.y = y;
    a.x = h * func_0038D3D8(ang);
    a.y = h * func_0038D3C0(ang);
    b.x = -w * func_0038D3C0(ang);
    b.y = w * func_0038D3D8(ang);
    {
        Q_392DD8 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(c));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p0) : "j"(va));
    }
    {
        Q_392DD8 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(p0));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p0) : "j"(va));
    }
    {
        Q_392DD8 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(c));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p1) : "j"(va));
    }
    {
        Q_392DD8 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(p1));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p1) : "j"(va));
    }
    {
        Q_392DD8 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(c));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(a));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p2) : "j"(va));
    }
    {
        Q_392DD8 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(p2));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p2) : "j"(va));
    }
    {
        Q_392DD8 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(c));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(a));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p3) : "j"(va));
    }
    {
        Q_392DD8 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(p3));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(b));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p3) : "j"(va));
    }
    D_001DA0D0[0] = 0x10000007;
    D_001DA0D0[1] = 0;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0x50000007;
    q = (unsigned long *)(D_001DA0D0 + 4);
    D_001DA0D0 = (u32 *)q;
    q[0] = 0xB400000000008001UL;
    q[1] = 0x53535353106UL;
    q[2] = tex;
    q[3] = 0x154;
    q[4] = 0x807F7F7F;
    q[5] = tw << 4;
    q[6] = (unsigned long)(((s32)p0.x + D_001D4BD0 - 8) | ((long)((s32)p0.y + D_001D4BD4 - 8) << 16)) | ((long)D_001D9F14 << 32);
    q[7] = (th << 20) + (tw << 4);
    q[8] = (unsigned long)(((s32)p1.x + D_001D4BD0 - 8) | ((long)((s32)p1.y + D_001D4BD4 - 8) << 16)) | ((long)D_001D9F14 << 32);
    q[9] = 0;
    q[10] = (unsigned long)(((s32)p2.x + D_001D4BD0 - 8) | ((long)((s32)p2.y + D_001D4BD4 - 8) << 16)) | ((long)D_001D9F14 << 32);
    q[11] = th << 20;
    q[12] = (unsigned long)(((s32)p3.x + D_001D4BD0 - 8) | ((long)((s32)p3.y + D_001D4BD4 - 8) << 16)) | ((long)D_001D9F14 << 32);
    q[13] = 0;
    D_001DA0D0 += 0x1C;
}
/* localdecomp:end func_00397930 */

/* localdecomp:start func_00397C78 */
extern u32 *D_001DA0D0_00397C78;
extern void func_12C9A0(void *, s16, s16, s16, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, s32);
void func_00397C78(s32 a0, s32 a1, s32 a2, s32 d, s32 e, s32 f) {
    u32 tmp[24];
    u32 *buf;
    s32 c, m;
    c = (1 << d) >> 6;
    m = 1 << (d + e - 4);
    if (c <= 0) c = 1;
    if (f == 0) {
        D_001DA0D0_00397C78[0] = 0x10000006;
        D_001DA0D0_00397C78[1] = 0;
        D_001DA0D0_00397C78[2] = 0;
        D_001DA0D0_00397C78[3] = 0x50000006;
        buf = D_001DA0D0_00397C78 + 4;
        D_001DA0D0_00397C78 = (u32 *)((u8 *)D_001DA0D0_00397C78 + 0x70);
    } else {
        buf = tmp;
    }
    func_12C9A0(buf, a1, c, a2, 0, 0, 1 << d, 1 << e);
    if (f == 0) {
        D_001DA0D0_00397C78[0] = m | 0x30000000;
        D_001DA0D0_00397C78[1] = a0;
        D_001DA0D0_00397C78[2] = 0;
        D_001DA0D0_00397C78[3] = m | 0x50000000;
        D_001DA0D0_00397C78 += 4;
    } else {
        func_11F0A0(0);
        func_12CCC8(buf, a0);
    }
}
/* localdecomp:end func_00397C78 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00397DE8);

/* localdecomp:start func_00397E08 */
typedef struct {
    u8 pad0[8]; s32 f8; s32 *fC; u8 pad10[0x5C]; s32 f6C; u8 b[2]; u8 pad72[2]; s32 f74; u8 pad78[4]; s32 f7C;
} S_3932B0;
void func_00397E08(S_3932B0 *p) {
    u8 *b = p->b;
    s32 t = *p->fC;
    s32 a = p->f8;
    p->f74 = t;
    if (a < t) {
        p->f74 = a;
    } else if (t < 0) {
        p->f74 = 0;
    }
    if (p->f7C >= 5) {
        p->f7C = 5;
        if (b[0] < 8) {
            b[0]++;
        } else if (b[1] < 8) {
            b[1]++;
        }
    } else {
        p->f6C = 1;
        if (b[1] != 0) {
            b[1]--;
        } else if (b[0] != 0) {
            b[0]--;
        } else {
            p->f6C = -6;
        }
    }
}
/* localdecomp:end func_00397E08 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00397EB8);

/* localdecomp:start func_00397EC8 */
extern u8 D_001D5EDC;
void func_00397EC8(void) { D_001D5EDC = 1; }
/* localdecomp:end func_00397EC8 */

/* localdecomp:start func_00397ED8 */
__asm__(".extern D_001D5EDC, 1");
__asm__(".extern D_001D5ED8, 4");
extern u8 D_001D5EDC;
extern s32 D_001D5ED8;
extern void func_0038B148();
void func_00397ED8(void) {
    s32 v;
    f32 t;
    if (D_001D5EDC) {
        D_001D5EDC = 0;
        D_001D5ED8 = D_001D5ED8 + 1;
        if (D_001D5ED8 > 10) D_001D5ED8 = 10;
    } else {
        D_001D5ED8 = D_001D5ED8 - 1;
        if (D_001D5ED8 < 0) D_001D5ED8 = 0;
    }
    t = (f32)D_001D5ED8;
    t = t / 10.0f;
    t = t * 48.0f;
    v = (s32)t;
    if (v) func_0038B148(0, 0, 0, v);
}
/* localdecomp:end func_00397ED8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00397F70);

/* localdecomp:start func_00397F78 */
extern u8 D_001D5EDD;
void func_00397F78(void) {
    D_001D5EDD = 0;
}
/* localdecomp:end func_00397F78 */

/* localdecomp:start func_00397F80 */
extern s32 D_001D5EE0;
void func_00397F80(void) {
    D_001D5EE0 = 0;
}
/* localdecomp:end func_00397F80 */

/* localdecomp:start func_00397F88 */
extern s32 D_001D5EE0;
void func_00397F88(void) {
    if (D_001D5EE0 == 0) D_001D5EE0 = 1;
}
/* localdecomp:end func_00397F88 */

/* localdecomp:start func_00397FA0 */
extern s32 D_001D5EE0;
s32 func_00397FA0(void) {
    return D_001D5EE0 == 3;
}
/* localdecomp:end func_00397FA0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00397FB0);

/* localdecomp:start func_00397FB8 */
extern void func_0038A5C0(s32);
extern void func_13CA28(void);
extern s32 func_13B620(void);
extern void func_003A56F0(void);
extern void func_003A2818(void);
extern void func_003A1EE8(void);
extern void func_12EF10(void);
extern void func_121B38(void);
extern void func_124ED8(s32, s32, s32);
void func_00397FB8(s32 a, s32 b, s32 c) {
    func_0038A5C0(5);
    func_13CA28();
    func_13B620();
    func_003A56F0();
    func_003A2818();
    func_003A1EE8();
    func_12EF10();
    func_121B38();
    func_124ED8(a, b, c);
}
/* localdecomp:end func_00397FB8 */
