#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_0039D6C8(s32);
extern void func_00389920(s32);
extern s32 func_0037DF98(s32);
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern s32 func_0039D6C8();
extern void *func_003AED40();
extern s32 func_0037DF98();
extern s32 func_003B2AA0(void);
extern s32 func_003E3040();
extern s32 func_003E24B0(s32, s32);
extern s32 func_003B42D0(void);
extern s32 func_003B41F0(void);
extern s32 func_003B4220();
extern void func_003B41F8();
extern void func_003B43B0(void);
extern s32 func_0037DCE8(void);
extern void func_003B43C0();
extern void *func_003AED40(s32);
extern s32 func_003E24B0(s32 arg0, s32 arg1);
extern void func_00397380(void);
extern void func_003B3558(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B1518 */
extern void func_0038E728(s32);
extern void func_00399660(s32);
extern void func_003B5D10(s32);
extern s32 func_003B5EC8(s32);
extern s32 D_001D8AD0;
extern s32 D_001D8ACC;
extern s32 D_001D8ADC;
extern s32 D_001D8AE0;
extern s32 D_001D8AD4;
extern s32 D_001D8AD8;
extern u8 D_001D5BDC[];
extern u8 D_001D5BDC_003B1518[];
void func_003B1518(void) {
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_3;
    s32 temp_3_2;

    if (D_001D5BDC[0] != 0) {
        func_003B5D10(0);
    }
    temp_2 = func_003B5EC8(1);
    D_001D8AD0 = temp_2;
    D_001D8ACC = (s32) ((temp_2 + 0xF) & 0xFFFFFFF0);
    if (D_001D5BDC_003B1518[0] == 0) {
        temp_2_2 = func_003B5EC8(1);
        D_001D8ADC = temp_2_2;
        temp_3 = (temp_2_2 + 0xF) & 0xFFFFFFF0;
        D_001D8AE0 = temp_3;
        func_0038E728(temp_3);
        temp_2_3 = func_003B5EC8(1);
        D_001D8AD4 = temp_2_3;
        temp_3_2 = (temp_2_3 + 0xF) & 0xFFFFFFF0;
        D_001D8AD8 = temp_3_2;
        func_00399660(temp_3_2);
    }
}
/* localdecomp:end func_003B1518 */

/* localdecomp:start func_003B15B8 */
extern void func_0039FF28(s32, s32, s32);
 
void func_003B15B8(void) {
    func_0039FF28(5, 0, 0);
}
/* localdecomp:end func_003B15B8 */

/* localdecomp:start func_003B15E0 */
typedef struct { u8 on; u8 pad[7]; } F;
typedef struct { void (*fn)(); s32 pad; } T;
extern s32 D_001D8A48_003B15E0;
__asm__(".extern D_001D8A48_003B15E0, 4");
extern F D_001D8A78_003B15E0[1];
__asm__(".extern D_001D8A78_003B15E0, 8");
extern T D_001D8A7C[1];
__asm__(".extern D_001D8A7C, 16");
typedef struct { s32 a[7]; } R;
extern R D_142430[];
extern void func_003B1368();
extern void func_003B1430();
extern void func_003B1490();
extern void func_003B14D0();
extern void func_003B15B8();
void func_003B15E0(s32 unused) {
    s32 i;
    s32 m = D_001D8A48_003B15E0;
    for (i = 0; i < 4; i++) {
        D_001D8A78_003B15E0[i].on = 1;
        switch (m) {
        case 0: D_001D8A7C[i].fn = func_003B1490; break;
        case 1:
            D_001D8A7C[i].fn = func_003B1430;
            if (D_142430[i].a[12] == -1) D_001D8A7C[i].fn = func_003B15B8;
            break;
        case 2: D_001D8A7C[i].fn = func_003B1368; break;
        case 3: D_001D8A7C[i].fn = func_003B14D0; break;
        }
    }
}
/* localdecomp:end func_003B15E0 */

/* localdecomp:start func_003B16B0 */
__asm__(".extern D_001D8A98, 4");
__asm__(".extern D_001D8A9C, 4");
__asm__(".extern D_001D8AA0, 4");
__asm__(".extern D_001D8AA4, 4");
__asm__(".extern D_001D8AA8, 4");
__asm__(".extern D_001D8AAC, 4");
__asm__(".extern D_001D8AB0, 4");
__asm__(".extern D_001D8AB4, 4");
__asm__(".extern D_001D8AB8, 4");
__asm__(".extern D_001D8ABC, 4");
__asm__(".extern D_001D8AC0, 4");
__asm__(".extern D_001D8AC4, 4");
__asm__(".extern D_001D8AC8, 4");
__asm__(".extern D_001D8B00, 4");
__asm__(".extern D_001D8B04, 4");
__asm__(".extern D_001D8B08, 4");
__asm__(".extern D_001D8B0C, 4");
__asm__(".extern D_001D8B10, 4");
__asm__(".extern D_001D8AF0, 8");
extern f32 D_001D8A98;
extern f32 D_001D8A9C;
extern f32 D_001D8AA0;
extern f32 D_001D8AA4;
extern f32 D_001D8AA8;
extern f32 D_001D8AAC;
extern f32 D_001D8AB0;
extern f32 D_001D8AB4;
extern f32 D_001D8AB8;
extern f32 D_001D8ABC;
extern f32 D_001D8AC0;
extern f32 D_001D8AC4;
extern f32 D_001D8AC8;
extern f32 D_001D8B00;
extern f32 D_001D8B04;
extern f32 D_001D8B08;
extern f32 D_001D8B0C;
extern f32 D_001D8B10;
extern s32 D_001D8AF0[2];
extern void func_003B5CA0(void);
extern void func_003E3EE8();
extern s32 func_003B5C38(u32);
extern s32 func_003E3A80(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E29B8(s32, s32);
extern s32 func_003E2560(s32, s32);
extern s32 func_003E23C0(s32, s32, s32);
extern s32 func_003E3BD0_003B16B0(s32, s32, f32, f32, f32, f32, s32);
extern s32 func_003E22D0(s32, s32, s32);
extern s32 func_003E3D08(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E28E0(s32, s32);
extern s32 func_003E3700(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E34F0(s32, s32, s32, s32, s32);
extern s32 func_003E30C8(s32, s32);
extern s32 func_003E31A8(s32, s32);
extern s32 func_003E2DE0(s32, s32);

void func_003B16B0(void) {
    s32 i;
    s32 id4, id8, idC;
    s32 *tp;
    s32 off;
    f32 fi;
    s32 id23, id22, id21, id20, id18, idfp, id19, id17, id16;
    f32 w;
    f32 h;
    f32 *nv = &D_001D8AC4;
    s32 r;

    func_003B5CA0();
    func_003E3EE8(0x4C003C);
    i = 0;
    tp = D_001D8AF0;
    off = 0;
    for (; i < 4; i++) {
        fi = i;
        id4 = 0x4C0034 + i;
        func_003E3EE8(id4);
        id8 = 0x4C0010 + i;
        r = func_003B5C38(0);
        func_003E3A80(id8, r + off, 0x8066CCFF, D_001D8AA0, D_001D8AA4 + D_001D8A9C + D_001D8A98 * fi, 1.0f, 1.0f);
        func_003E29B8(id8, 1);
        func_003E2560(id8, 1);
        id23 = 0x4C0044 + i;
        func_003E3A80(id23, (s32)tp, 0x8066CCFF, 0.66f, D_001D8ABC + D_001D8A9C + D_001D8A98 * fi, 1.0f, 1.0f);
        func_003E29B8(id23, 1);
        func_003E2560(id23, 1);
        func_003E24B0(id23, 0);
        func_003E23C0(id23, 1, 3);
        idC = 0x4C0048 + i;
        func_003E3BD0_003B16B0(idC, 0x706EC8FF, 0.638f, D_001D8AC0 + D_001D8A98 * fi, 0.033203f, 0.04086523f, 0xEAA6);
        func_003E24B0(idC, 0);
        id22 = 0x4C0040 + i;
        r = func_0037DF98(0x238);
        func_003E3A80(id22, r, 0x8066CCFF, 0.3475f, D_001D8A9C + 0.2195f + D_001D8A98 * fi, 1.0f, 1.0f);
        func_003E29B8(id22, 1);
        func_003E2560(id22, 1);
        func_003E24B0(id22, 0);
        id21 = 0x4C0014 + i;
        r = func_003B5C38(1);
        func_003E3A80(id21, r + off, 0x8066CCFF, D_001D8AA8, D_001D8AAC + D_001D8A9C + D_001D8A98 * fi, 1.0f, 1.0f);
        func_003E29B8(id21, 1);
        func_003E2560(id21, 1);
        func_003E23C0(id21, 2, 3);
        id20 = 0x4C0018 + i;
        r = func_003B5C38(2);
        func_003E3A80(id20, r + off, 0x8066CCFF, D_001D8AB0, D_001D8AB4 + D_001D8A9C + D_001D8A98 * fi, 1.0f, 1.0f);
        func_003E29B8(id20, 1);
        func_003E2560(id20, 1);
        func_003E23C0(id20, 2, 3);
        id18 = 0x4C001C + i;
        r = func_003B5C38(3);
        func_003E3A80(id18, r + off, 0x8066CCFF, D_001D8AB8, D_001D8ABC + D_001D8A9C + D_001D8A98 * fi, 1.0f, 1.0f);
        func_003E29B8(id18, 1);
        func_003E2560(id18, 1);
        func_003E23C0(id18, 2, 3);
        idfp = 0x4C0008 + i;
        w = (D_001D8B00 + D_001D8B04) * 0.5f;
        h = D_001D8B0C - 0.007f;
        func_003E3BD0_003B16B0(idfp, 0, w, D_001D8A9C + D_001D8AC8 + D_001D8A98 * fi + 0.001953f, h, D_001D8B08 - 0.012f - 0.001953f, 0);
        func_003E22D0(idfp, 0x8000, 1);
        id19 = 0x4C0000 + i;
        func_003E3D08(id19, 0x331465B7, w, D_001D8A9C + D_001D8AC8 + D_001D8A98 * fi, D_001D8B0C, D_001D8B08, 0.0035f, 0.006f);
        id17 = 0x4C0004 + i;
        func_003E3D08(id17, 0x331465B7, 0.7618f, D_001D8A9C + D_001D8AC8 + D_001D8A98 * fi, D_001D8B10, D_001D8B08, 0.0035f, 0.006f);
        id16 = 0x4C0020 + i;
        func_003E3BD0_003B16B0(id16, 0x8066CCFF, 0.883907f, D_001D8AC0 + D_001D8A98 * fi, 0.033203f, 0.04086523f, 0);
        func_003E28E0(id16, 0xED26);
        func_003E3700(id4, id8, id21, id20, id18, idfp, id19, id17);
        func_003E34F0(id4, id16, id22, id23, idC);
        func_003E30C8(0x4C003C, id4);
        if (i < 4) {
            func_003E31A8(idfp, (s32)func_003AED40(i));
            func_003E28E0(idfp, 0);
        }
        tp++;
        off += 0x20;
    }
    func_003E3BD0_003B16B0(0x4C0038, 0x331465B7, *nv, D_001D8A9C + D_001D8AC8, 0.2925f, 0.16f, 0);
    func_003E30C8(0xD000B, 0x4C0038);
    func_003E2DE0(0x11, 0x4C003C);
}
/* localdecomp:end func_003B16B0 */

/* localdecomp:start func_003B1DA8 */
__asm__(".extern D_001D8A48_003B1DA8, 4");
extern s32 D_001D8A48_003B1DA8;
extern s32 func_0037DF98();
extern s32 func_003B3DB8(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);
void func_003B1DA8(void) {
    s32 a = 0;
    s32 b = 0;
    s32 c = 0;
    switch (D_001D8A48_003B1DA8) {
    case 0:
        a = 0x143;
        b = 0x124;
        c = 0x100;
        break;
    case 1:
        a = 0x144;
        b = 0x124;
        c = 0x100;
        break;
    case 2:
        a = 0x14E;
        b = 0x124;
        c = 0x100;
        break;
    case 3:
        a = 0x1750;
        b = 0x124;
        c = 0x100;
        break;
    }
    func_003B3DB8(0x10, 0xD000B, 0xD0002, 0xD0003, 0xD0004, 0xD0000, 0xD0001, 0xD0005, 8.7f, 0xD0008, func_0037DF98(a), 0xD0006, b, 0xD0007, c);
}
/* localdecomp:end func_003B1DA8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B1EB0);

/* localdecomp:start func_003B22C0 */
typedef struct { u8 p0[0x4954]; s32 f4954; u8 p4958[0x7080 - 0x4958]; u8 f7080[4]; } S_B22C0;
__asm__(".extern D_001D8A70, 4");
__asm__(".extern D_001D8A50, 8");
__asm__(".extern D_001D8A60, 8");
__asm__(".extern D_001D8B68, 8");
extern s32 D_001D8A50[2];
extern s32 D_001D8A60[2];
extern s32 D_001D8B68[2];
extern u8 D_001D5BDC_003B22C0;
extern S_B22C0 D_00160C40_003B22C0[];
extern s32 D_001D8A70;
extern s32 func_003B5EC8(s32);
extern void *func_003AFA90(s32);
extern s32 func_003AEF70(void *, s32, s32, s32, s32);
extern void *func_003AED40(s32);
extern void func_003B1518(void);
extern void func_003B1DA8(void);
extern void func_003B16B0(void);
extern void func_003B15E0();
void func_003B22C0(void) {
    s32 i;
    s32 x;
    s32 y;
    for (i = 0; i < 4; i++) {
        if (D_001D5BDC_003B22C0 != 0) {
            D_001D8A50[i] = (s32)func_003AFA90(i * 2);
            D_001D8A60[i] = (s32)func_003AFA90(i * 2 + 1);
        } else {
            x = func_003B5EC8(0);
            D_001D8B68[i] = x;
            y = (x + 15) & 0xFFFFFFF0;
            D_001D8A50[i] = y;
            y = x + 0x8D00;
            y = (y + 15) & 0xFFFFFFF0;
            D_001D8A60[i] = y;
        }
        func_003AEF70(func_003AED40(i), D_001D8A50[i], D_001D8A60[i], D_00160C40_003B22C0->f4954, (s32)D_00160C40_003B22C0->f7080);
    }
    func_003B1518();
    func_003B1DA8();
    func_003B16B0();
    func_003B15E0();
    D_001D8A70 = 0;
}
/* localdecomp:end func_003B22C0 */

/* localdecomp:start func_003B23F8 */
typedef struct { u8 p[0x1C4]; u32 f1C4; } P_3B23F8;
typedef struct { u8 on; u8 pad[7]; } F_3B23F8;
typedef struct { void (*fn)(); s32 pad; } T_3B23F8;
__asm__(".extern D_001D8AE4, 4");
__asm__(".extern D_001D8A78_003B23F8, 8");
__asm__(".extern D_001D5BDC_003B23F8, 1");
__asm__(".extern D_001D8A98, 4");
__asm__(".extern D_001D8A9C, 4");
__asm__(".extern D_001D8AC4, 4");
__asm__(".extern D_001D8AC8, 4");
extern P_3B23F8 *D_001D52FC_003B23F8;
extern F_3B23F8 D_001D8A78_003B23F8[1];
extern T_3B23F8 D_001D8A7C_003B23F8[1];
extern s32 D_001D8AE4;
extern u8 D_001D5BDC_003B23F8;
extern u8 D_001D5BDD;
extern s32 func_003AFA18_003B23F8(void);
extern s32 func_0037DCB0(s32);
extern s32 func_003AFA70(void);
extern s32 func_0037DC68_003B23F8(void);
extern void func_003E2E60_003B23F8(s32);
extern void func_003E1AA8_003B23F8(s32);
extern s32 func_003E1E50(s32, f32, f32);
extern void func_003B60F0();
extern void func_003B60B0(s32);
void func_003B23F8(s32 a0) {
    u32 b = D_001D52FC_003B23F8->f1C4;
    s32 i;
    s32 n = 0;
    if (b & 0x4000) {
        s32 found = 0;
        i = D_001D8AE4;
        do {
            i++;
            if (i >= 4) i = 0;
            if (D_001D8A78_003B23F8[i].on) found = 1;
            n++;
            if (found) break;
        } while (n < 4);
        D_001D8AE4 = i;
        ((s32 (*)(s32, s32, s32))func_0039FF28)(3, 0, 0);
    } else if (b & 0x1000) {
        s32 found = 0;
        i = D_001D8AE4;
        do {
            i--;
            { s32 lim = -1; if (i <= lim) i = 3; lim = 0; }
            if (D_001D8A78_003B23F8[i].on) found = 1;
            n++;
            if (found) break;
        } while (n < 4);
        D_001D8AE4 = i;
        ((s32 (*)(s32, s32, s32))func_0039FF28)(3, 0, 0);
    } else if (b & 0x40) {
        if (D_001D8A78_003B23F8[D_001D8AE4].on) {
            if (D_001D8A7C_003B23F8[D_001D8AE4].fn) {
                D_001D8A7C_003B23F8[D_001D8AE4].fn();
                ((s32 (*)(s32, s32, s32))func_0039FF28)(4, 0, 0);
            }
        }
    } else if (b & 0x10) {
        ((s32 (*)(s32, s32, s32))func_0039FF28)(4, 0, 0);
        if (D_001D5BDD) {
            func_003E2E60_003B23F8(func_003AFA70());
            func_003E1AA8_003B23F8(a0);
        } else if (D_001D5BDC_003B23F8) {
            func_003E2E60_003B23F8(func_003AFA18_003B23F8());
            func_003E1AA8_003B23F8(a0);
        } else {
            func_003E2E60_003B23F8(func_0037DCB0(0));
            func_003E1AA8_003B23F8(a0);
        }
    } else if (b & 0x900) {
        ((s32 (*)(s32, s32, s32))func_0039FF28)(4, 0, 0);
        if (D_001D5BDD) {
            func_003E2E60_003B23F8(func_003AFA70());
            func_003E1AA8_003B23F8(a0);
        } else if (!D_001D5BDC_003B23F8) {
            func_003E2E60_003B23F8(func_0037DC68_003B23F8());
            func_003E1AA8_003B23F8(a0);
        }
    }
    func_003E1E50(0x4C0038, D_001D8AC4, D_001D8A9C + D_001D8AC8 + (f32)D_001D8AE4 * D_001D8A98);
    func_003B60F0();
    func_003B60B0(0x4C0038);
}
/* localdecomp:end func_003B23F8 */

/* localdecomp:start func_003B2640 */
extern void func_003B13A8(void);
extern void func_003B13D0(void);
extern void func_003B1400(void);
extern s32 D_001D8A48;
extern s8 D_001DA020;
extern s32 D_001D8A70;
extern s32 D_001D4CE8[];
void func_003B2640(void) {
    s32 t5 = D_001D8A48;
    s32 t4 = D_001D4CE8[0];
    D_001DA020 = (t5 == 1);
    if (t4 == 0xB || ((u32)(t4 - 6) < 2U && t5 == 1)) {
        func_003B13A8();
    } else if ((u32)(t4 - 6) < 2U) {
        func_003B13D0();
    } else if (t4 == 0xE && t5 != 1 && (t5 == 0 || t5 == 3)) {
        func_003B1400();
    }
    D_001D8A70 = 2;
}
/* localdecomp:end func_003B2640 */

/* localdecomp:start func_003B26E8 */
extern void func_003B15E0(s32);
extern void func_003B1EB0(void);
extern void func_003B23F8(s32);
void func_003B26E8(s32 a) {
    func_003B15E0(a);
    func_003B1EB0();
    func_003B23F8(a);
}
/* localdecomp:end func_003B26E8 */

/* localdecomp:start func_003B2720 */
extern s32 D_001D8A70;
extern s32 D_001D4CE8[];
void func_003B2720(void) {
    s32 temp_3;

    if (D_001D8A70 == 0) {
        temp_3 = D_001D4CE8[0];
        switch (temp_3) {                           /* irregular */
        case 18:
            /* fallthrough */
        case 1:
            func_003E24B0(0x4C003C, 1);
            func_003E24B0(0xD000B, 1);
            return;
        default:
            func_003E24B0(0x4C003C, 0);
            func_003E24B0(0xD000B, 0);
            D_001D8A70 = 1;
            break;
        }
    }
}
/* localdecomp:end func_003B2720 */

/* localdecomp:start func_003B27A8 */
__asm__(".extern D_001D8A70, 4");
__asm__(".extern D_001D8AE8, 1");
__asm__(".extern D_001D4CE8, 4");
__asm__(".extern D_001D5B74, 4");
extern s32 D_001D8A70;
extern u8 D_001D8AE8;
extern s32 D_001D4CE8_003B27A8;
extern void func_003B2720(void);
extern void func_003B26E8(s32);
extern void func_003B2640_003B27A8();
extern void func_003B2F50(void);
extern void func_0037E058(void);
extern s32 D_001D5B74;
extern u8 D_001D5BDC_003B27A8;
extern u8 D_001D5BDD;
extern void func_0037E060(void);
extern void *func_003AFA18();
extern void *func_003AFA70_003B27A8();
extern s32 *func_0037DC68();
extern s32 func_0037DCB0_003B27A8();
extern s32 func_003B5C20(s32);
extern void func_0038E5B8(s32, s32);
extern s32 func_003E2E60();
extern void func_003E1AA8(void *);
extern s32 func_003B5BE0(void);
extern void func_003B5BE8(void);
void func_003B27A8(s32 a) {
    func_003B2720();
    func_0037E060();
    if (D_001D8A70 != 0) func_0037E058();
    switch (D_001D8A70) {
    case 0:
        func_003B26E8(a);
        break;
    case 1:
        func_003B2640_003B27A8(a);
        break;
    case 2:
    case 3:
        func_003B2F50();
        break;
    case 4:
    case 5:
        D_001D8A70 = 0;
        break;
    case 6:
        if (D_001D5BDD != 0) {
            if (D_001D8AE8 != 0 && D_001D4CE8_003B27A8 == 1) {
                func_0038E5B8(1, 1);
            } else {
                D_001D8A70 = 0;
                func_003E2E60(func_003AFA70_003B27A8());
                func_003E1AA8((void *)a);
            }
        } else if (D_001D5BDC_003B27A8 != 0) {
            func_003E2E60(func_003AFA18());
            func_003E1AA8((void *)a);
        } else {
            if (D_001D5B74 != 0 || func_003B5C20(1) != 0) {
                func_003E2E60(func_0037DC68());
            } else {
                func_003E2E60(func_0037DCB0_003B27A8(0));
            }
            func_003E1AA8((void *)a);
        }
        D_001D8AE8 = 0;
        break;
    }
    if (func_003B5BE0() != 0) {
        if (D_001D8A70 != 6) {
            func_003B5BE8();
            func_003E1AA8((void *)a);
            if (D_001D5BDC_003B27A8 == 0) {
                func_003E2E60(func_0037DC68());
            }
        }
    }
}
/* localdecomp:end func_003B27A8 */

/* localdecomp:start func_003B2958 */
typedef struct { s32 p0; void *vt; } O_B2958;
extern s32 D_001D8AD0;
extern s32 D_001D8AD4;
extern s32 D_001D8ADC;
extern s32 D_001D8B68[2];
extern u8 D_001D5BDC[];
void func_003B2958(void) {
    s32 i;
    s32 j;
    s32 *p;
    O_B2958 *o;
    func_003E3040(0x10);
    func_003E3040(0x11);
    for (i = 0; i < 4; i++) {
        o = (O_B2958 *)func_003AED40(i);
        (*(void (**)(O_B2958 *))((u8 *)o->vt + 0xC))(o);
    }
    func_0039D6C8(1);
    func_003B5F88(D_001D8AD0);
    for (j = 0; j < 4; j++) {
        func_003B5F88(D_001D8B68[j]);
    }
    if (D_001D5BDC[0] == 0) {
        func_003B5F88(D_001D8ADC);
        func_003B5F88(D_001D8AD4);
    }
    func_00389920(0);
    func_0038E728(0);
}
/* localdecomp:end func_003B2958 */

/* localdecomp:start func_003B2A28 */
extern u8 D_001D5BDC[];

void func_003B2A28(void) {
    if (D_001D5BDC[0] == 0) {
        func_0037DCE0();
    }
}
/* localdecomp:end func_003B2A28 */

/* localdecomp:start func_003B2A50 */
extern u8 D_001D5BDC[];
extern s32 D_001D8A70_g;
extern void func_003866E8(s32, s32, s32, s32);
extern void func_003B2AF8(void);
void func_003B2A50(void) {
    if (D_001D5BDC[0] == 0) func_0037DCE8();
    if (D_001D8A70_g != 0) {
        func_003866E8(0, 0, 0, 0x30);
        func_003B2AF8();
    }
}
/* localdecomp:end func_003B2A50 */

/* localdecomp:start func_003B2AA0 */
extern s32 func_003E1A50(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA220;
extern s32 D_001DA208[2];
extern void func_003B22C0();
extern void func_003B2958();
extern void func_003B27A8();
extern void func_003B2A28(void);
extern void func_003B2A50();
s32 func_003B2AA0(void) {
    if (D_001DA220 == 0) {
        func_003E1A50(D_001DA208, (s32)func_003B22C0, (s32)func_003B2958, (s32)func_003B27A8, (s32)func_003B2A28, (s32)func_003B2A50);
        D_001DA220 = 1;
    }
    return (s32)D_001DA208;
}
/* localdecomp:end func_003B2AA0 */

/* localdecomp:start func_003B2AF8 */
typedef struct {
    s16 f0;
    u16 f2;
    s16 f4, f6, f8, fA, fC, fE;
    s16 f10;
    u16 f12;
    s16 f14, f16, f18, f1A;
} T_3B2AF8;
extern s32 D_001D4CE8_003B2AF8;
extern u8 D_001DA020_003B2AF8;
extern u8 D_001D5BDC_003B2AF8;
extern u8 D_001D5BDD;
extern u16 D_001D4BC4;
extern char D_001D8B78[];
extern char D_001D8B80[];
extern char D_0027CB70[];
extern char *func_0037E030(s32);
extern s32 func_0011A264(void *, s32, s32);
extern void func_003A9E60(void *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
extern void func_11B2E8();
void func_003B2AF8(void) {
    T_3B2AF8 s10;
    T_3B2AF8 s30;
    char *a = 0;
    char *b = 0;
    char *c;
    s32 draw = 1;
    func_00389920(0);
    c = D_001D8B78;
    switch (D_001D4CE8_003B2AF8) {
    case 8:
        a = (char *)func_0037DF98(0x8E3);
        b = (char *)func_0037DF98(0x8DF);
        c = (char *)func_0037DF98(0x1A3);
        break;
    case 14:
        if (D_001DA020_003B2AF8 == 0) break;
        c = func_0037E030(0x195);
        a = (char *)func_0037DF98(0x197);
        break;
    case 15:
        a = (char *)func_0037DF98(0x8E3);
        b = (char *)func_0037DF98(0x8DF);
        c = func_0037E030(0x19F);
        break;
    case 33:
        a = (char *)func_0037DF98(0x8E3);
        b = (char *)func_0037DF98(0x8DF);
        c = func_0037E030(0x1A8);
        break;
    case 12: case 13: case 31: case 32:
        c = func_0037E030(0x1AF);
        break;
    case 9: case 10:
        c = func_0037E030(0x1AD);
        break;
    case 16: case 17:
        c = func_0037E030(0x1AE);
        break;
    case 25: case 29:
        c = func_0037E030(0x1AB);
        break;
    case 23: case 30:
        c = func_0037E030(0x1AC);
        break;
    case 19:
        c = func_0037E030(0x1B0);
        a = (char *)func_0037DF98(0x8DE);
        break;
    case 20:
        c = func_0037E030(0x1B2);
        a = (char *)func_0037DF98(0x8DE);
        break;
    case 3:
        c = func_0037E030(0x194);
        break;
    case 21:
        if (D_001DA020_003B2AF8 != 0) {
            c = func_0037E030(0x195);
            a = (char *)func_0037DF98(0x197);
        } else if (D_001D5BDC_003B2AF8 != 0) {
            char *buf, *fmt;
            s32 x;
            buf = D_0027CB70;
            fmt = D_001D8B80;
            x = func_0037DF98(0x198);
            func_11B2E8(buf, fmt, x, 1, 1, func_0037DF98(0x19A));
            c = buf;
            a = (char *)func_0037DF98(0x8E2);
            b = (char *)func_0037DF98(0x8DF);
        } else {
            char *buf, *fmt;
            s32 x;
            buf = D_0027CB70;
            fmt = D_001D8B80;
            x = func_0037DF98(0x198);
            func_11B2E8(buf, fmt, x, 1, 1, func_0037E030(0x19A));
            c = buf;
            a = (char *)func_0037DF98(0x8E2);
        }
        break;
    case 24:
        if (D_001D5BDC_003B2AF8) c = func_0037E030(0x1B2);
        else c = func_0037E030(0x1B3);
        a = (char *)func_0037DF98(0x8DE);
        break;
    case 22:
        c = func_0037E030(0x1B1);
        a = (char *)func_0037DF98(0x8DE);
        break;
    case 27: {
        char *buf, *fmt, *x;
        a = (char *)func_0037DF98(0x8E2);
        b = (char *)func_0037DF98(0x8DF);
        buf = D_0027CB70;
        fmt = D_001D8B80;
        x = func_0037E030(0x1A1);
        func_11B2E8(buf, fmt, x, 1, 1, func_0037E030(0x19A));
        c = buf;
        break;
    }
    case 26:
        a = (char *)func_0037DF98(0x8E2);
        b = (char *)func_0037DF98(0x8DF);
        c = func_0037E030(0x1A5);
        break;
    case 4: case 5: case 6:
        if (D_001D5BDC_003B2AF8 != 0 && D_001DA020_003B2AF8 == 0) {
            a = (char *)func_0037DF98(0x8E2);
            b = (char *)func_0037DF98(0x8DF);
            c = func_0037E030(0x19B);
        } else if (D_001D5BDD != 0) {
            a = (char *)func_0037DF98(0x8E3);
            c = func_0037E030(0x19B);
        } else if (D_001DA020_003B2AF8 == 0) {
            c = func_0037E030(0x19D);
            a = (char *)func_0037DF98(0x197);
        } else {
    case 7:
            c = func_0037E030(0x195);
            a = (char *)func_0037DF98(0x197);
        }
        break;
    case 11: case 18: case 28:
    default:
        draw = 0;
        break;
    }
    if (draw) {
        func_0011A264(&s30, 0, 0x1C);
        s30.f2 = D_001D4BC4;
        s30.f4 = 0x60;
        s30.f6 = 0x1A0;
        s30.f8 = 0x100;
        s30.fA = 0x68;
        s30.f10 = 0x10;
        s30.f12 = 1;
        s10 = s30;
        func_00389920(1);
        func_003A9E60(&s10, 0x8066CCFF, c, 1, 1, -1, 0, a, b, 0);
    }
}
/* localdecomp:end func_003B2AF8 */

/* localdecomp:start func_003B2F50 */
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, rest:21; } F_003B2F50;
typedef struct { u8 pad[0x1A4]; s32 f1A4; } P_003B2F50;
__asm__(".extern D_001D8A70, 4");
__asm__(".extern D_001D8A48, 4");
extern F_003B2F50 D_001D4CEC;
extern u8 D_001DA020_003B2F50;
extern s32 D_001D8AD8;
extern u8 D_001D5BDC_003B2F50;
extern s32 D_001D4CE8_003B2F50;
extern P_003B2F50 *D_001D52FC_003B2F50;
extern u8 D_001D5BDD;
extern void func_003971E8(void);
extern void func_00397200(void);
extern void func_003970A0(void);
extern void func_003972A0(s32);
extern void func_003BB7B0(void);
extern u8 func_003970B8(void);
extern void func_00397270(void);
extern s32 func_00396E80(s32, s32);
extern void func_003A3A00(void);
extern void func_003B1030();
extern s32 D_00142438[];

void func_003B2F50(void) {
    s32 t1, t2, t3, t4, t5, t6;

    if (D_001D52FC_003B2F50->f1A4 & 0x50) {
        func_0039FF28(4, 0, 0);
    }
    switch (D_001D4CE8_003B2F50) {
    case 3:
        if (D_001D52FC_003B2F50->f1A4 & 0x40) {
            D_001D4CEC.b0 = 0;
            D_001D8A70 = 5;
        }
        break;
    case 8:
        t1 = D_001D52FC_003B2F50->f1A4;
        if (t1 & 0x20) {
            D_001D4CEC.b3 = 1;
            break;
        }
        if (t1 & 0x10) {
            if (D_001D5BDD != 0) {
                func_003B3558(-1);
                func_003A3A00();
                return;
            }
            func_003971E8();
            func_00397200();
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            if (D_001D5BDC_003B2F50 != 0) {
                D_001D8A70 = 2;
            } else {
                D_001D8A70 = 6;
            }
        }
        break;
    case 15:
        t2 = D_001D52FC_003B2F50->f1A4;
        if (t2 & 0x20) {
            func_003970A0();
            return;
        }
        if (!(t2 & 0x10)) break;
        if (D_001D5BDD != 0) {
            if (D_00142438[0] != 2) {
                func_003B3558(-1);
                func_003A3A00();
                return;
            }
            D_001D8A70 = 6;
            break;
        }
        if (D_001D5BDC_003B2F50 != 0) {
            D_001D8A70 = 5;
        } else {
            D_001D8A70 = 6;
            func_00397200();
        }
        func_003971E8();
        return;
    case 33:
        t3 = D_001D52FC_003B2F50->f1A4;
        if (t3 & 0x20) {
            func_003970A0();
            return;
        }
        if (!(t3 & 0x10)) return;
        func_003971E8();
        func_00397200();
        if (D_001D5BDD != 0) {
            func_003972A0(D_001D8AD8);
            func_003BB7B0();
            func_003B13A8();
        }
        return;
    case 22:
        if (D_001D52FC_003B2F50->f1A4 & 0x40) {
            func_003971E8();
            func_00397200();
            func_003970B8();
            D_001D4CEC.b6 = 0;
            D_001D4CEC.b10 = 0;
            if (D_001D5BDC_003B2F50 != 0) {
                D_001D8A70 = D_001D8A70 + 1;
            }
        }
        break;
    case 19:
    case 20:
    case 24:
        if (!(D_001D52FC_003B2F50->f1A4 & 0x40)) break;
        if (D_001D5BDD != 0) return;
        if (D_001D5BDC_003B2F50 != 0) {
            D_001D8A70 = 6;
            func_00397200();
            func_00397270();
            return;
        }
        D_001D4CEC.b6 = 0;
        D_001D4CEC.b10 = 0;
        D_001D4CEC.b1 = 0;
        D_001D4CEC.b2 = 0;
        D_001D8A70 = 5;
        break;
    case 1:
        if (*(s32 *)&D_001D4CEC & 6) return;
        if (D_001D5BDD != 0) {
            D_001D8A70 = 6;
        } else {
            D_001D8A70 = 4;
        }
        break;
    case 18:
        if (*(s32 *)&D_001D4CEC & 6) return;
        if (D_001D5BDD != 0) {
            D_001D8A70 = 4;
        } else {
            D_001D8A70 = 4;
        }
        break;
    case 14:
        if (D_001D8A48 == 2) {
            func_00396E80(0, 0);
        } else if (D_001DA020_003B2F50 == 0) {
            D_001D8A70 = 4;
            break;
        }
    case 4:
    case 5:
    case 7:
        if (D_001D8A48 == 2 || D_001D8A48 == 0) {
            func_003B13D0();
        }
        if (!(D_001D52FC_003B2F50->f1A4 & 0x10)) return;
        func_003971E8();
        func_00397200();
        D_001D8A70 = 6;
        break;
    case 21:
        if (D_001D5BDC_003B2F50 != 0 && D_001DA020_003B2F50 == 0) {
            t4 = D_001D52FC_003B2F50->f1A4;
            if (t4 & 0x40) {
                func_00397380();
                func_003970A0();
                func_00397200();
                func_003A3A00();
                return;
            }
            if (t4 & 0x10) {
                D_001D4CEC.b1 = 0;
                D_001D4CEC.b2 = 0;
                func_003971E8();
                D_001D8A70 = 6;
            }
            break;
        }
        if (D_001D5BDD != 0) {
            if (D_001D52FC_003B2F50->f1A4 & 0x40) {
                func_003B3558(-1);
                func_003A3A00();
            }
            return;
        }
        t5 = D_001D52FC_003B2F50->f1A4;
        if (((t5 & 0x40) && D_001DA020_003B2F50 == 0) || ((t5 & 0x10) && D_001DA020_003B2F50 != 0)) {
            D_001D4CEC.b1 = 0;
            D_001D4CEC.b2 = 0;
            D_001D8A70 = 6;
        }
        break;
    case 26:
    case 27:
        t6 = D_001D52FC_003B2F50->f1A4;
        if (t6 & 0x40) {
            func_00397380();
            func_003970A0();
            func_00397200();
            func_003A3A00();
            return;
        }
        if (!(t6 & 0x10)) return;
        func_003971E8();
        func_00397200();
        D_001D8A70 = 6;
        break;
    case 6:
        if (D_001D5BDC_003B2F50 != 0) {
            if (D_001DA020_003B2F50 == 0) {
                if (D_001D52FC_003B2F50->f1A4 & 0x40) {
                    func_00397380();
                    D_001D4CEC.b1 = 0;
                    D_001D4CEC.b2 = 0;
                    func_003B1030();
                }
                if (!(D_001D52FC_003B2F50->f1A4 & 0x10)) return;
                func_003971E8();
                func_00397200();
                D_001D8A70 = 6;
                break;
            }
            if (!(D_001D52FC_003B2F50->f1A4 & 0x10)) return;
            func_003971E8();
            func_00397200();
            D_001D8A70 = 6;
            break;
        }
        if (D_001D5BDD != 0) {
            if (!(D_001D52FC_003B2F50->f1A4 & 0x20)) return;
            func_003B3558(-1);
            func_003A3A00();
            return;
        }
        if (!(D_001D52FC_003B2F50->f1A4 & 0x10)) return;
        func_003971E8();
        func_00397200();
        D_001D8A70 = 6;
        break;
    case 11:
        if (*(s32 *)&D_001D4CEC & 6) return;
        D_001D8A70 = 5;
        break;
    }
}
/* localdecomp:end func_003B2F50 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B3558);

/* localdecomp:start func_003B3DB8 */
/* MATCH */
__asm__(".extern D_001D8BD0, 4");
__asm__(".extern D_001D8BD4, 4");
__asm__(".extern D_001D8BD8, 4");
__asm__(".extern D_001D8BDC, 4");
__asm__(".extern D_001D8BE0, 4");
__asm__(".extern D_001D8BE4, 4");
__asm__(".extern D_001D8B90, 8");
extern f32 D_001D8BD0, D_001D8BD4, D_001D8BD8, D_001D8BDC, D_001D8BE0, D_001D8BE4;
extern f32 D_001D8B90[2];
extern f32 D_001D8B94[];
extern f32 D_001D8B98[];
extern f32 D_001D8B9C[];
extern void func_003B5AB0(s32, void *, void *);
extern s32 func_003AFAA8(s32);
extern s32 func_003E3988(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E3BD0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E3D08(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E3630(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E3A80(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E30C8(s32, s32);
extern s32 func_003E22D0(s32, s32, s32);
extern s32 func_003E28E0(s32, s32);
extern s32 func_003E2DE0(s32, s32);
s32 func_003B3DB8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 f, s32 a8, s32 a9,
                  s32 a10, s32 a11, s32 a12, s32 a13) {
    f32 hi;
    f32 lo;
    s32 ok, i;
    long base; s32 id;
    lo = f;
    func_00389920(0);
    hi = 1.0f;
    func_003B5AB0(a9, &hi, &lo);
    ok = func_003AFAA8(a1) != 0;
    { s32 t = func_003E3988(a4, 0x35, 0x331465B7, D_001D8BD0, D_001D8BD4, 1.0f, 1.0f, lo) != 0; ok = ok & t; }
    { s32 t = func_003E3988(a5, 0x36, 0x802299DE, D_001D8BD0, D_001D8BD4, 1.0f, 1.0f, lo) != 0; ok = ok & t; }
    { s32 t = func_003E3988(a2, 0x33, 0x332299DE, D_001D8BD0, D_001D8BD4, 1.0f, 1.0f, lo) != 0; ok = ok & t; }
    { s32 t = func_003E3988(a3, 0x34, 0x332299DE, D_001D8BD0, D_001D8BD4, 1.0f, 1.0f, lo) != 0; ok = ok & t; }
    { s32 t = func_003E3BD0(a6, 0x331465B7, 0, D_001D8BD0, D_001D8BD4, D_001D8BD8, D_001D8BDC) != 0; ok = ok & t; }
    { s32 t = func_003E3D08(a8, 0x332299DE, D_001D8BD0, D_001D8BD4, D_001D8BD8, D_001D8BDC, D_001D8BE0, D_001D8BE4) != 0; ok = ok & t; }
    { s32 t = func_003E3630(a1, a2, a3, a4, a5, a6, a8) != 0; ok = ok & t; }
    { s32 t = func_003E3A80(a7, a9, 0x8066CCFF, 0.5f, 0.0745f, hi, hi) != 0; ok = ok & t; }
    { s32 t = func_003E30C8(a1, a7) != 0; ok = ok & t; }
    { s32 t = func_003E22D0(a7, 0x40, 1) != 0; ok = ok & t; }
    if (a10 != 0) {
        { s32 t = func_003E3A80(a10, a11 ? func_0037DF98(a11) : 0, 0x8066CCFF, 0.1675f, 0.932f, 0.9f, 0.9f) != 0; ok = ok & t; }
        { s32 t = func_003E22D0(a10, 0x40, 1) != 0; ok = ok & t; }
        { s32 t = func_003E30C8(a1, a10) != 0; ok = ok & t; }
    }
    if (a12 != 0) {
        { s32 t = func_003E3A80(a12, a13 ? func_0037DF98(a13) : 0, 0x8066CCFF, 0.8325f, 0.932f, 0.9f, 0.9f) != 0; ok = ok & t; }
        { s32 t = func_003E22D0(a12, 0x40, 1) != 0; ok = ok & t; }
        { s32 t = func_003E30C8(a1, a12) != 0; ok = ok & t; }
    }
    base = 0x590000;
    for (i = 0; i < 4; i++) {
        id = i + (s32)base;
        { s32 t = func_003E3BD0(id, 0x332299DE, 0, D_001D8B90[i * 4], D_001D8B94[i * 4], D_001D8B98[i * 4], D_001D8B9C[i * 4]) != 0; ok = ok & t; }
        { s32 t = func_003E28E0(id, 0xED5A) != 0; ok = ok & t; }
        { s32 t = func_003E30C8(a1, id) != 0; ok = ok & t; }
    }
    {
        s32 t = func_003E2DE0(a0, a1) != 0;
        return ok & t;
    }
}
/* localdecomp:end func_003B3DB8 */

/* localdecomp:start func_003B41E8 */
extern s32 D_001D8BF0;
void func_003B41E8(void) {
    D_001D8BF0 = 0;
}
/* localdecomp:end func_003B41E8 */

/* localdecomp:start func_003B41F0 */
extern s32 D_001D8BF0;
s32 func_003B41F0(void) {
    return D_001D8BF0;
}
/* localdecomp:end func_003B41F0 */

/* localdecomp:start func_003B41F8 */
extern s32 D_001D8C04;
extern s32 D_001D8C08;
void func_003B41F8(s32 a0, s32 a1) {
    D_001D8C04 = 0x40;
    D_001D8C08 = 0x10;
    if (a0 != 0xFFFF) {
        D_001D8C04 = a0;
    }
    D_001D8C08 = a1;
}
/* localdecomp:end func_003B41F8 */

/* localdecomp:start func_003B4220 */
extern void func_003B41E8(void);
extern void func_003B41F8(s32, s32);
extern void func_003B42C0(s32, s32);
extern s32 D_001D8BEC;
extern s32 D_001D8BE8;
extern s32 D_001D8BF4;
extern s32 D_001D8BF8;
extern s32 D_001D8BFC;
extern s8 D_001D8C00;
s32 func_003B4220(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (D_001D8BEC != 1) {
        return 0;
    }
        D_001D8BEC = 0;
        func_003B41E8();
        D_001D8BE8 = arg0;
        D_001D8BF4 = arg1;
        D_001D8BF8 = arg2;
        D_001D8BFC = arg3;
        D_001D8C00 = arg4;
        func_003B42C0(0x60, 0x1A0);
        func_003B41F8(0xFFFF, 0xFFFF);
    return 1;
}
/* localdecomp:end func_003B4220 */

extern s32 D_001D8C0C;
extern s32 D_001D8C10;
/* localdecomp:start func_003B42C0 */
extern s32 D_001D8C0C;
extern s32 D_001D8C10;
void func_003B42C0(s32 a, s32 b) { D_001D8C0C = a; D_001D8C10 = b; }
/* localdecomp:end func_003B42C0 */

/* localdecomp:start func_003B42D0 */
extern void func_0037E058(void);
extern void func_0039FF28(s32, s32, s32);
extern s32 D_001D8BEC;
extern s32 D_001D8BE8;
extern void * D_001D52FC;
extern void *D_001D52FC_003B42D0[];
extern s32 D_001D8C04;
extern s32 D_001D8BF0;
extern s32 D_001D8C08;
s32 func_003B42D0(void) {
    s32 t;
    s32 m;
    if (D_001D8BEC == 1) {
        return 0;
    }
    func_0037E058();
    t = D_001D8BE8;
    switch (t) {
    case 0:
        m = *(s32 *)((u8 *)D_001D52FC + 0x1C4);
        if (m & D_001D8C04) {
            D_001D8BF0 = 1;
            D_001D8BEC = 1;
            func_0039FF28(4, 0, 0);
        } else if (m & D_001D8C08) {
            D_001D8BEC = 1;
            D_001D8BF0 = 2;
            func_0039FF28(4, 0, 0);
        }
        break;
    case 1:
        if (*(s32 *)((u8 *)D_001D52FC_003B42D0[0] + 0x1C4) & D_001D8C04) {
            D_001D8BF0 = t;
            func_0039FF28(0x12, 0, 0);
            D_001D8BEC = t;
        }
        break;
    }
    return 1;
}
/* localdecomp:end func_003B42D0 */

/* localdecomp:start func_003B43B0 */
extern s32 D_001D8BF0;
extern s32 D_001D8BEC;
void func_003B43B0(void) {
    D_001D8BF0 = 0;
    D_001D8BEC = 1;
}
/* localdecomp:end func_003B43B0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B43C0);

/* localdecomp:start func_003B45B0 */
typedef struct { u8 p0[0x20]; s32 x[4]; s32 y[4]; s32 z[4]; } O_B45B0;
extern void func_003B56D0(s32 *arg0, float float1, float float2, float float3, float float4, float float5);
extern void func_003B56F0(void *, f32, f32, f32, f32);
extern void func_003B5000(void *, s32, f32, f32, f32);
void *func_003B45B0(void *p) {
    s32 *a = (s32 *)p;
    O_B45B0 *o = (O_B45B0 *)p;
    s32 i;
    a[1] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 0;
    a[6] = 0;
    a[7] = 0;
    for (i = 0; i < 4; i++) {
        o->x[i] = 0;
        o->y[i] = 0;
        o->z[i] = 0;
    }
    *(f32 *)((u8 *)p + 0xA0) = 0.01f;
    a[0x14] = 0;
    a[0x15] = 0;
    *(s8 *)p = 0;
    a[0x16] = 0;
    *(f32 *)((u8 *)p + 0xA4) = 0.006667f;
    func_003B56F0(p, 0.5f, 0.6f, 1.0f, 0.41f);
    ((void (*)(void *, s32, f32, f32, f32, f32, f32))func_003B56D0)(p, 1, 0.5f, 0.99f, 0.045f, 0.48f, 0.35f);
    func_003B5000(p, 1, 0.0265f, 0.00666f, 0.01f);
    *(s8 *)((u8 *)p + 0xA9) = 0;
    a[0x1E] = 0;
    return p;
}
/* localdecomp:end func_003B45B0 */
