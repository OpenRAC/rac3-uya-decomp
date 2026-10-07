#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void func_003DF198(void);
extern void func_003DF090(void);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003DEF88 */
extern u32 *D_001DA0D0;
extern u32 *D_001DA7E0_003DEF88;
extern s32 D_001DA7E4;
extern s32 D_001D4BB0;
extern s32 func_003E0AD8(s32);
extern void func_003A9888(void);
void func_003DEF88(void) {
    u32 *save = D_001DA0D0;
    s32 r;
    D_001DA0D0 += 4;
    D_001DA7E0_003DEF88[0] = 0x20000000;
    D_001DA7E0_003DEF88[1] = (u32)D_001DA0D0;
    D_001DA7E0_003DEF88[2] = 0;
    D_001DA7E0_003DEF88[3] = 0;
    r = func_003E0AD8(D_001D4BB0);
    func_003A9888();
    if (D_001DA7E4 < r) { D_001DA7E4 = r; }
    D_001DA0D0[0] = 0x20000000;
    D_001DA0D0[1] = (u32)(D_001DA7E0_003DEF88 + 4);
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0;
    D_001DA0D0 += 4;
    save[0] = 0x20000000;
    save[1] = (u32)D_001DA0D0;
    save[2] = 0;
    save[3] = 0;
}
/* localdecomp:end func_003DEF88 */

/* localdecomp:start func_003DF090 */
typedef struct { s16 h0; s16 h2; } S_98T;
extern s32 D_00306440_003DF090[];
extern u8 *D_00305A40_003DF090[];
extern S_98T D_00305F40_003DF090[];
void func_003DF090(void) {
    s32 *ip = D_00306440_003DF090;
    u8 *obj;
    u8 *sub;
    u8 *e;
    u8 *q; u8 *tab;
    s32 j, k, off;
    S_98T *t;
    while (*ip >= 0) {
        obj = D_00305A40_003DF090[*ip];
        j = 0;
        if (*(s16 *)(obj + 0x28) > 0) {
            tab = obj + 0x40;
            do {
                off = j * 8;
                sub = *(u8 **)(tab + off);
                e = sub + 0x10;
                q = e + *(s32 *)(e + 4) * 16 + 0x10;
                for (k = 0; k < *(s32 *)e; k++, q += 0x40) {
                    t = &D_00305F40_003DF090[q[0x13]];
                    if (t->h0 != 0) *(u32 *)(q + 0x30) = (*(u32 *)(q + 0x30) & 0xFFFFC000) | t->h0;
                    if (t->h2 != 0) *(u32 *)(q + 0x20) = (*(u32 *)(q + 0x20) & 0xFFFFC000) | t->h2;
                }
                j++;
            } while (j < *(s16 *)(obj + 0x28));
        }
        ip++;
    }
}
/* localdecomp:end func_003DF090 */

/* localdecomp:start func_003DF198 */
extern s32 D_001D4BB0;
extern s32 D_001D4BB4;
void func_0038D0A8(s32 *, s32, s32);
void func_003DF200();
void func_11F0A0(s32);
extern s32 D_001DA0D0_003DF198;
extern s32 D_001DA7E0;
extern u8 D_00306540[];

void func_003DF198(void) {
    s32 t = D_001DA0D0_003DF198;
    D_001DA7E0 = t;
    t += 0x10;
    D_001D4BB0 = D_001D4BB4;
    D_001DA0D0_003DF198 = t;
    func_11F0A0(0);
    func_003DF200();
    func_0038D0A8(D_00306540, 0x3200, 0x40);
    func_003DEF88();
}
/* localdecomp:end func_003DF198 */
