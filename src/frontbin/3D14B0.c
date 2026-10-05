#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003D47A0(void);
extern void func_003D30D0(void);
extern void func_003D46E0(void);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
typedef struct { u8 pad0[0x24]; f32 f24; f32 f28; u8 pad2C[4]; s32 f30; u8 pad34[4]; s32 f38; s32 f3C; u8 pad40[8]; s32 f48; s32 f4C; } E_3A3028;
extern void func_003D3FA0(E_3A3028 *, s32, s32, s32, f32, f32, f32);
extern void func_003D4858();
extern void func_003D3EE0();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003D14B0 */
void func_003D14B0(s32 *p, s32 n) { s32 t = *p; t = (t + 0x1FFF) & -0x2000; *p = t + n; }
/* localdecomp:end func_003D14B0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003D14D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1570);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1650);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1978);

LINKER_REMNANT("asm/remnants", func_003D1B08);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1B10);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1D40);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1E68);

LINKER_REMNANT("asm/remnants", func_003D22D8);

/* localdecomp:start func_003D22E0 */
extern void func_003D1E68(s32, s32, s32, s32, s32);
 
void func_003D22E0(s32 a0, s32 a1, s32 a2) {
    func_003D1E68(a0, a1, 0x100, 0x100, a2);
}
/* localdecomp:end func_003D22E0 */

/* localdecomp:start func_003D2308 */
extern void func_003D1E68(s32, s32, s32, s32, s32);
 
void func_003D2308(s32 a0, s32 a1, s32 a2) {
    func_003D1E68(a0, a1, 0x80, 0x80, a2);
}
/* localdecomp:end func_003D2308 */

/* localdecomp:start func_003D2330 */
extern void func_003D1E68(s32, s32, s32, s32, s32);
 
void func_003D2330(s32 a0, s32 a1, s32 a2) {
    func_003D1E68(a0, a1, 0x40, 0x40, a2);
}
/* localdecomp:end func_003D2330 */

LINKER_REMNANT("asm/remnants", func_003D2358);

INCLUDE_ASM("asm/nonmatchings/text", func_003D2370);

/* localdecomp:start func_003D27C0 */
extern s32 func_003D14B0(s32 *, s32);
extern void func_003D2878(void);
extern void func_003D2F90(void);
__asm__(".extern D_001D5608, 4");
__asm__(".extern D_001D5610, 4");
__asm__(".extern D_001D5614, 4");
__asm__(".extern D_001D561C, 4");
extern s32 D_001D5608, D_001D5610, D_001D5614, D_001D561C;
extern s32 D_001D5624, D_001D560C, D_001D5620, D_001D55EC;
extern s32 D_001A1ED4[];
void func_003D27C0(void) {
    s32 p, r1, r2, r3;
    D_001D5608 = 0x3FA000;
    D_001D560C = 0x3FE000;
    D_001D5624 = 0x400000;
    p = 0x379000;
    r1 = func_003D14B0(&p, 0x40000);
    p = 0x379000;
    D_001D5614 = r1;
    r2 = func_003D14B0(&p, 0x40000);
    D_001D561C = r2;
    r3 = func_003D14B0(&p, 0x40000);
    D_001D5620 = r3;
    D_001D5610 = D_001A1ED4[0];
    func_003D2878();
    func_003D2F90();
    D_001D55EC = D_001D55EC | 1;
}
/* localdecomp:end func_003D27C0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003D2878);

/* localdecomp:start func_003D2F90 */
__asm__(".extern D_001D93A0, 4");
extern s32 D_001D5608, D_001D5620, D_001D561C, D_001D93A0, D_001D55F4;
extern u8 D_001D2A50[];
extern void func_003D1D40(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_003D22E0();
extern void func_003D1650(u8 **, s32, s32, s32, s32, s32, s32);
void func_003D2F90(void) {
    u8 *p = D_001D2A50;
    func_003D1D40(&p, D_001D5608, 0x40, 0x40, D_001D5620, 0x80, 0x80);
    func_003D1D40(&p, D_001D5620, 0x80, 0x80, D_001D561C, 0x100, 0x100);
    func_003D22E0(&p, D_001D561C, D_001D5620);
    func_003D1650(&p, D_001D561C, 0x100, 0x100, 1, 0, D_001D93A0);
    D_001D55F4 = p - D_001D2A50;
}
/* localdecomp:end func_003D2F90 */

/* localdecomp:start func_003D3050 */
extern s32 D_001D55F0;
extern u32 *D_001DA0D0;
__asm__(".extern D_001D938C, 4");
extern s32 D_001D938C;
extern s32 D_001D0A50[];
void func_003D3050(void) {
    D_001D938C = 0x6000;
    D_001DA0D0[0] = (D_001D55F0 >> 4) | 0x30000000;
    D_001DA0D0[1] = (u32)D_001D0A50;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = (D_001D55F0 >> 4) | 0x50000000;
    D_001DA0D0 += 4;
}
/* localdecomp:end func_003D3050 */

/* localdecomp:start func_003D30D0 */
__asm__(".extern D_001D938C, 4");
extern u32 *D_001DA0D0;
extern s32 D_001D55F4;
extern u8 D_001D2A50[];
extern s32 D_001D938C;
void func_003D30D0(void) {
    D_001DA0D0[0] = (D_001D55F4 >> 4) | 0x30000000;
    D_001DA0D0[1] = (u32)D_001D2A50;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = (D_001D55F4 >> 4) | 0x50000000;
    D_001D938C = 0;
    D_001DA0D0 += 4;
}
/* localdecomp:end func_003D30D0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003D3148);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3428);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3780);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3A50);

/* localdecomp:start func_003D3B90 */
extern s32 D_001D5600_003D3B90;
__asm__(".extern D_001D5600_003D3B90, 16");
extern s32 D_001D5604_003D3B90;
__asm__(".extern D_001D5604_003D3B90, 16");
extern s32 D_001D5628_003D3B90;
__asm__(".extern D_001D5628_003D3B90, 16");
extern s32 D_001D55FC_003D3B90;
__asm__(".extern D_001D55FC_003D3B90, 16");
extern u8 D_001D3EF0[];
extern s32 func_003D3148();
extern s32 func_003D3428();
extern s32 func_003D3780();
extern void func_003D1650(u8 **, s32, s32, s32, s32, s32, s32);
void func_003D3B90(void) {
    u8 *p;
    p = D_001D3EF0;
    func_003D3148(&p, D_001D5600_003D3B90, D_001D5604_003D3B90, D_001D5600_003D3B90 >> 6, 0, 0, (D_001D5600_003D3B90 + 1) << 4, (D_001D5604_003D3B90 + 1) << 4);
    func_003D3428(&p, 1);
    func_003D3780(&p, D_001D5600_003D3B90, D_001D5604_003D3B90, D_001D5600_003D3B90 >> 6, 0, 0, (D_001D5600_003D3B90 + 1) << 4, (D_001D5604_003D3B90 + 1) << 4, 0xFF82FF);
    func_003D1650(&p, D_001D5628_003D3B90, 0x100, 0x100, 0, 1, 0x80);
    D_001D55FC_003D3B90 = (s32)p - (s32)D_001D3EF0;
}
/* localdecomp:end func_003D3B90 */

/* localdecomp:start func_003D3C80 */
__asm__(".extern D_001D5634, 4");
__asm__(".extern D_001D5630, 4");
extern s32 func_003D14B0();
extern void func_003D3A50(void);
extern void func_003D3B90(void);
extern s32 D_001D5634;
extern s32 D_001D5630;
extern s32 D_001D5628;
extern s32 D_001A1ED4[];
extern s32 D_001D55EC;
void func_003D3C80(void) {
    s32 spv[4];
    spv[0] = 0x37C000;
    D_001D5634 = func_003D14B0(spv, 0x40000);
    D_001D5628 = func_003D14B0(spv, 0x40000);
    D_001D5630 = D_001A1ED4[0];
    func_003D3A50();
    func_003D3B90();
    D_001D55EC |= 2;
}
/* localdecomp:end func_003D3C80 */

/* localdecomp:start func_003D3CF0 */
extern u32 *D_001DA0D0;
extern s32 D_001D55F8;
extern s32 D_001D55FC;
extern u8 D_001D3650[];
extern u8 D_001D3EF0[];
void func_003D3CF0(void) {
    D_001DA0D0[0] = (D_001D55F8 >> 4) | 0x30000000;
    D_001DA0D0[1] = (u32)D_001D3650;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = (D_001D55F8 >> 4) | 0x50000000;
    D_001DA0D0 += 4;
    D_001DA0D0[0] = (D_001D55FC >> 4) | 0x30000000;
    D_001DA0D0[1] = (u32)D_001D3EF0;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = (D_001D55FC >> 4) | 0x50000000;
    D_001DA0D0 += 4;
}
/* localdecomp:end func_003D3CF0 */

/* localdecomp:start func_003D3DC8 */
typedef struct { u8 pad[0x150]; s16 h150; s16 h152; } S_1CFEC0;
extern S_1CFEC0 D_1CFEC0;
extern s32 D_001D5604;
extern s32 D_001D5600;
extern void func_003D27C0();
extern void func_003D3C80();
void func_003D3DC8(void) {
    S_1CFEC0 *p = &D_1CFEC0;
    D_001D5600 = p->h150;
    D_001D5604 = p->h152;
    func_003D27C0();
    func_003D3C80();
}
/* localdecomp:end func_003D3DC8 */

LINKER_REMNANT("asm/remnants", func_003D3E08);

/* localdecomp:start func_003D3E40 */
extern long func_00384EC0(s32);
extern u8 D_0037CEB0[];

void func_003D3E40(void *arg0, s32 arg1, s32 arg2, long arg3) {
    void *temp_s0;

    (*(long *)((u8 *)(arg0) + 0x78)) = func_00384EC0(arg1);
    (*(long *)((u8 *)(arg0) + 0x80)) = (long) (0xFF9000000000 | 0x260);
    (*(long *)((u8 *)(arg0) + 0x70)) = 0;
    temp_s0 = (arg2 * 0x14) + D_0037CEB0;
    (*(long *)((u8 *)(arg0) + 0x88)) = (long) ((*(s32 *)((u8 *)(temp_s0) + 0)) | ((long) (*(s32 *)((u8 *)(temp_s0) + 4)) * 4) | ((long) (*(s32 *)((u8 *)(temp_s0) + 8)) * 0x10) | ((long) (*(s32 *)((u8 *)(temp_s0) + 0xC)) << 6) | (arg3 << 0x20));
}
/* localdecomp:end func_003D3E40 */

INCLUDE_ASM("asm/nonmatchings/text", func_003D3EE0);

LINKER_REMNANT("asm/remnants", func_003D3F78);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3FA0);

LINKER_REMNANT("asm/remnants", func_003D4198);

INCLUDE_ASM("asm/nonmatchings/text", func_003D41E0);

LINKER_REMNANT("asm/remnants", func_003D4680);

/* localdecomp:start func_003D46B0 */
extern s32 D_001D4BB0[];
extern void func_003D76A0(s32);
extern void func_003A40C8(void);
void func_003D46B0(void) {
    func_003D76A0(D_001D4BB0[0]);
    func_003A40C8();
}
/* localdecomp:end func_003D46B0 */

/* localdecomp:start func_003D46E0 */
typedef struct { s16 a; s16 b; } T_D46E0;
typedef struct { u8 p0[0x33]; u8 f33; } E_D46E0;
typedef struct { u8 p0[0xF]; u8 cnt; u8 q[0xC]; E_D46E0 *ent; } O_D46E0;
extern s32 D_00300F40[];
extern O_D46E0 *D_002FBB40[];
extern T_D46E0 D_00300940[];
void func_003D46E0(void) {
    s32 *p;
    s32 i;
    O_D46E0 *o;
    u8 *e;
    for (p = D_00300F40; *p >= 0; p++) {
        o = D_002FBB40[*p];
        e = (u8 *)o->ent;
        for (i = 0; i < o->cnt; i++) {
            T_D46E0 *t = &D_00300940[e[0x33]];
            if (t->a != 0) { *(u32 *)e = (*(u32 *)e & 0xFFFFC000) | t->a; }
            if (t->b != 0) { *(u32 *)(e + 0x20) = (*(u32 *)(e + 0x20) & 0xFFFFC000) | t->b; }
            e += 0x50;
        }
    }
}
/* localdecomp:end func_003D46E0 */

/* localdecomp:start func_003D47A0 */
extern s32 D_001D4BB4;
void func_003885F0(s32, s32 *, s32);
void func_003A3A40(s32 *);
extern void func_003A3EF0(s32, unsigned long);
void func_003D48D8();
void func_003D5840();
void func_003D6C10();
void func_003D7950();
void func_11F0A0(s32);
extern s32 D_001D4BB0_003D47A0;
extern u8 D_001D7960[];
extern s32 D_001DA0D0_003D47A0;
extern u8 D_100AE0[];
extern u8 D_1159B0[];

void func_003D47A0(void) {
    func_003A3EF0(0x47, 0x5340B);
    D_001D4BB0_003D47A0 = D_001D4BB4;
    func_11F0A0(0);
    func_003D48D8();
    func_003D46B0();
    func_11F0A0(0);
    func_003D7950();
    func_003A3A40(D_1159B0);
    func_003D5840();
    func_003D6C10();
    func_003A3A40(D_100AE0);
    func_003885F0(D_001DA0D0_003D47A0, D_001D7960, 0x20);
    D_001DA0D0_003D47A0 += 0x20;
}
/* localdecomp:end func_003D47A0 */

LINKER_REMNANT("asm/remnants", func_003D4850);

/* localdecomp:start func_003D4858 */
typedef struct {
    u8 pad[0x7614];
    s32 value;
} SourceBlock_003D4858;
extern u8 *D_001DA784;
extern u8 *D_001DA788;
extern s32 D_001DA790;
extern s32 D_001DA7A8;
extern s32 D_001DA7AC;
extern s32 D_001DA7B0;
extern u8 *D_001DA7B4;
__asm__(".extern D_001DA784, 16");
__asm__(".extern D_001DA788, 16");
__asm__(".extern D_001DA790, 16");
__asm__(".extern D_001DA7A8, 16");
__asm__(".extern D_001DA7AC, 16");
__asm__(".extern D_001DA7B4, 16");
void func_003D4858(void) {
    register SourceBlock_003D4858 *source_block __asm__("$3") = (SourceBlock_003D4858 *)0x220000;
    register u8 *buffer __asm__("$2") = (u8 *)0x300000;
    s32 source;
    register u8 *entry __asm__("$5");
    register u8 *end __asm__("$3");
    __asm__ volatile("" : "+r"(source_block), "+r"(buffer));
    source = source_block->value;
    buffer -= 0x42C0;
    entry = D_001DA784;
    end = D_001DA788;
    D_001DA790 = source;
    D_001DA7B4 = buffer;
    D_001DA7A8 = 0;
    D_001DA7AC = 0;
    D_001DA7B0 = 0;
    if (entry != end) {
        register u16 empty __asm__("$4") = 0xFFFF;
        register u8 marker __asm__("$3") = 0xFF;
        do {
            entry[0x1F] = marker;
            *(s16 *)(entry + 0x16) = 0;
            *(u16 *)(entry + 0x14) = empty;
            buffer = D_001DA788;
            __asm__ volatile("" : "+r"(buffer));
            entry += 0x20;
        } while (entry != buffer);
    }
}
/* localdecomp:end func_003D4858 */
