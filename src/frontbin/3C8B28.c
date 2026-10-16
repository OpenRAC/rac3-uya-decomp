#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003C8CE0(void);
extern void func_003C8C40(void);
extern void func_003C8D50(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003C8B28 */
typedef struct { u8 pad[0x20]; s16 *arr[1]; } S_3C8B28;
extern S_3C8B28 *D_001DA670_003C8B28;
extern s32 D_001DA690[2];
extern void func_00388C10(void *, void *);
s32 func_003C8B28(s32 idx, s32 n) {
    f32 v[4] __attribute__((aligned(16)));
    s16 *p = D_001DA670_003C8B28->arr[idx];
    if (n > 0) {
        s32 dx = (u16)p[5], dy = (u16)p[6], dz = (u16)p[7];
        s32 a, b, c;
        s32 x = (u16)p[2], y = (u16)p[3], z = (u16)p[4];
        do {
            a = x + dx;
            b = y + dy;
            c = z + dz;
            x = a;
            y = b;
            z = c;
        } while (--n);
        p[4] = c;
        p[3] = b;
        p[2] = a;
    }
    __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(v));
    if (p[2] != 0) v[0] = p[2] * 9.58738019107841e-05f;
    if (p[3] != 0) v[1] = p[3] * 9.58738019107841e-05f;
    if (p[4] != 0) v[2] = p[4] * 9.58738019107841e-05f;
    func_00388C10(D_001DA690, v);
}
/* localdecomp:end func_003C8B28 */

/* localdecomp:start func_003C8C40 */
extern s32 func_003C8B28(s32, s32);
s32 func_003C8E70_003C8C40(s32);                         /* extern */
extern s32 D_001D9D80;
extern void *D_001DA670_003C8C40;
extern s32 D_001DA6D0;

void func_003C8C40(void) {
    s32 temp_s1;
    s32 temp_s1_2;
    s32 var_s0;

    var_s0 = 0;
    temp_s1 = D_001D9D80 - D_001DA6D0;
    temp_s1_2 = (temp_s1 >= 3) ? 2 : temp_s1;
    if ((*(s16 *)((u8 *)(D_001DA670_003C8C40) + 6)) > 0) {
        do {
            func_003C8B28(var_s0, temp_s1_2);
            func_003C8E70_003C8C40(var_s0);
            var_s0 += 1;
        } while (var_s0 < (*(s16 *)((u8 *)(D_001DA670_003C8C40) + 6)));
    }
    D_001DA6D0 = D_001D9D80;
}
/* localdecomp:end func_003C8C40 */

LINKER_REMNANT("asm/remnants", func_003C8CD8);

/* localdecomp:start func_003C8CE0 */
typedef struct Config_003C8CE0 {
    unsigned char padding[0xC];
    short count;
    unsigned char padding2[2];
    unsigned char *buffer;
} Config_003C8CE0;

extern int D_001DA0D0;
extern Config_003C8CE0 *D_001DA670_003C8CE0;
extern int D_001DA680;
extern int D_001D4BB4;
extern int D_001D4BB0;
extern int D_001D9C7C;
__asm__(".extern D_001D9C7C, 4");

void func_003C8CE0(void) {
    register int old __asm__("$2");
    register int index __asm__("$5");
    register Config_003C8CE0 *config __asm__("$6");
    register int saved __asm__("$3");
    register int count __asm__("$4");

    old = D_001DA0D0;
    index = 0;
    config = D_001DA670_003C8CE0;
    D_001DA680 = old;
    saved = D_001D4BB4;
    old += 0x10;
    count = config->count;
    D_001DA0D0 = old;
    D_001D4BB0 = saved;
    D_001D9C7C = 0;
    if (count > 0) {
        do {
            old = (int)config->buffer;
            saved = index * 0x10;
            index++;
            saved += old;
            __asm__ volatile("" : "+r"(saved));
            *(unsigned long *)saved = 0;
            old = config->count;
        } while (index < old);
    }
}
/* localdecomp:end func_003C8CE0 */

/* localdecomp:start func_003C8D50 */
extern u32 *D_001DA0D0_003C8D50;
extern u32 *D_001DA680_003C8D50;
extern u32 *D_001DA684_003C8D50;
extern s32 D_001D4BB0_003C8D50;
extern s32 D_001D4BB4_003C8D50;
__asm__(".extern D_001DA680_003C8D50, 16");
__asm__(".extern D_001DA0D0_003C8D50, 16");
__asm__(".extern D_001DA684_003C8D50, 16");
__asm__(".extern D_001D4BB0_003C8D50, 16");
__asm__(".extern D_001D4BB4_003C8D50, 16");
extern void func_0039B2E8();
extern s32 func_003A40C8();
void func_003C8D50(void) {
    D_001DA684_003C8D50 = D_001DA0D0_003C8D50;
    D_001DA0D0_003C8D50 += 4;
    D_001DA680_003C8D50[0] = 0x20000000;
    { u32 *q = D_001DA680_003C8D50; q[1] = (u32)D_001DA0D0_003C8D50; D_001DA680_003C8D50[2] = 0; D_001DA680_003C8D50[3] = 0; func_0039B2E8(q); }
    func_003A40C8();
    D_001DA0D0_003C8D50[0] = 0x20000000;
    D_001DA0D0_003C8D50[1] = (u32)(D_001DA680_003C8D50 + 4);
    D_001DA0D0_003C8D50[2] = 0;
    D_001DA0D0_003C8D50[3] = 0;
    D_001DA0D0_003C8D50 += 4;
    D_001DA684_003C8D50[0] = 0x20000000;
    D_001DA684_003C8D50[1] = (u32)D_001DA0D0_003C8D50;
    D_001DA684_003C8D50[2] = 0;
    D_001DA684_003C8D50[3] = 0;
    D_001D4BB0_003C8D50 = D_001D4BB4_003C8D50;
}
/* localdecomp:end func_003C8D50 */

LINKER_REMNANT("asm/remnants", func_003C8E68);

/* localdecomp:start func_003C8E70 */
typedef struct { u16 pad; u16 flags; } Q_3C8E70;
typedef struct { u8 pad[6]; s16 n; u8 pad2[0x18]; Q_3C8E70 *arr[1]; } P_3C8E70;
extern P_3C8E70 *D_001DA670[];
extern void func_003C9078(Q_3C8E70 *);
extern void func_003C8ED0(Q_3C8E70 *);
void func_003C8E70(s32 i) {
    P_3C8E70 *p = D_001DA670[0];
    if (i < p->n) {
        Q_3C8E70 *q = p->arr[i];
        if (q->flags & 1) func_003C9078(q);
        else func_003C8ED0(q);
    }
}
/* localdecomp:end func_003C8E70 */

INCLUDE_ASM("asm/nonmatchings/text", func_003C8ED0);

/* localdecomp:start func_003C9078 */
typedef struct { u8 pad[0x10]; u8 *base; s16 h14; s16 h16; s16 h18; s16 h1A; s16 h1C; s16 h1E; } E_3C9078;
typedef struct { s16 n; u16 flags; u8 pad[0xC]; E_3C9078 items[1]; } S_3C9078;
extern u32 *D_001DA0D0_003C9078;
extern u8 D_1422E0[];
extern s32 D_1A1ED0[];
extern void func_003C9798(E_3C9078 *, s32, u8 *);
extern void func_003C9210(void);
extern s32 func_003C92B8(u8 *, u8 *, s32);
extern void func_003C93B0(s32, u8 *, u8 *, u8 *);
extern void func_003A3EF0(s32, unsigned long);
void func_003C9078(Q_3C8E70 *arg) {
    S_3C9078 *q = (S_3C9078 *)arg;
    E_3C9078 *e;
    u8 *fl;
    s32 i;
    if (q->n != 0) {
        func_003C9798(q->items, q->n, (u8 *)0x70003F00);
        func_003C9210();
        fl = (u8 *)0x70003F00;
        e = q->items;
        D_001DA0D0_003C9078[0] = 0x30000007;
        D_001DA0D0_003C9078[1] = (u32)D_1422E0;
        D_001DA0D0_003C9078[2] = 0;
        D_001DA0D0_003C9078[3] = 0x50000007;
        D_001DA0D0_003C9078 += 4;
        for (i = 0; i < q->n; i++, e++, fl++) {
            if (*fl == 0) {
                u8 *b = e->base;
                u8 *c = b + e->h1C;
                u8 *a0 = b + e->h18;
                u8 *d = b + e->h1A;
                if (func_003C92B8(a0, (u8 *)0x70000000, e->h14) == 0) {
                    func_003C93B0(q->items[i].h16, c, d, (u8 *)0x70000000);
                }
            }
        }
        func_003A3EF0(0x47, 0x3180B);
        func_003A3EF0(0x4E, ((D_1A1ED0[2] >> 13) | 0x1000000) | 0x100000000L);
    }
}
/* localdecomp:end func_003C9078 */

LINKER_REMNANT("asm/remnants", func_003C9208);
