#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00355A00);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00355A58);

/* localdecomp:start func_00355AE0 */
typedef struct {
    u8 pad0[0x2E8];
    s32 x2E8;
    u8 pad2EC[0x2F8 - 0x2EC];
    s32 x2F8;
} V_355AE0;
typedef struct {
    u8 pad0[33];
    u8 x21;
    u8 pad22[104 - 34];
    V_355AE0 *x68;
    u8 pad6C[170 - 108];
    s16 xAA;
} M_355AE0;
extern u16 *D_0021DEA0_355AE0[];
extern u8 *D_001E009C_355AE0;
extern s32 D_001E00D8_355AE0;

void func_00355AE0(M_355AE0 *o) {
    u16 *p;
    M_355AE0 *m;
    if (o->x21 == 255) return;
    p = D_0021DEA0_355AE0[o->x21];
    while (o->x21 != 255 && o->x21 <= D_001E00D8_355AE0 && p != 0
           && ((s16)p[-1] >= 0 || p == D_0021DEA0_355AE0[o->x21])) {
        m = (M_355AE0 *)(D_001E009C_355AE0 + ((*p & 0x7FFF) << 8));
        if (m == 0) return;
        if (m->xAA == o->xAA) {
            m->x68->x2F8 = 1;
        } else if (m->xAA == 5861) {
            m->x68->x2F8 = 1;
        } else if (m->xAA == 5821) {
            m->x68->x2E8 = 1;
        }
        p++;
    }
}
/* localdecomp:end func_00355AE0 */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00355BC0);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00355C90);

/* localdecomp:start func_00355E08 */
void func_00355E08(char *a0) {
    *(int *)(*(char **)(a0 + 0x68) + 0x354) = 0;
}
/* localdecomp:end func_00355E08 */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00355E18);

/* localdecomp:start func_00355F10 */
typedef struct { s32 w0; f32 f4; s32 w8; f32 fc; s32 w10; s32 w14; s32 w18; } SrcData_355F10;
typedef struct {
    u8 pad0[0x2e0]; s32 w2e0; f32 f2e4; s32 w2e8; f32 f2ec;
    u8 pad2f0[0x344 - 0x2f0]; s32 w344; s32 w348; s32 w34c; s32 w350;
} DstData_355F10;
typedef struct { s32 id; u8 pad4[0x74]; s32 w78; u8 pad7c[0x118 - 0x7c]; s32 w118; } Inner_355F10;
typedef struct { u8 pad0[8]; Inner_355F10 *pad8; } Mid_355F10;
typedef struct { u8 pad0[8]; Inner_355F10 *f8; u8 pad[0x68 - 0xc]; void *d68; } Obj_355F10;
typedef struct { u8 pad0[0x43]; u8 b43; } X_355F10;
extern struct { u8 pad0[8]; struct { u8 pad0[0x68]; Inner_355F10 *i68; } *w8; } *func_00445F18_355F10(void *);
extern void func_00441C78_355F10(void *, s32, s32, s32);
void func_00355F10(void *a0, void *a1) {
    DstData_355F10 *d = *(DstData_355F10 **)((u8 *)a0 + 0x68);
    Inner_355F10 *in = func_00445F18_355F10(a0)->w8->i68;
    SrcData_355F10 *s = *(SrcData_355F10 **)((u8 *)a1 + 0x68);
    d->w2e0 = s->w0;
    if (s->f4 > 0.0f) d->f2e4 = s->f4;
    d->w2e8 = s->w8;
    if (s->fc > 0.0f) d->f2ec = s->fc;
    d->w348 = s->w10;
    d->w34c = s->w18;
    if (in->id == 0x1ab4) d->w344 = in->w118;
    else d->w344 = -1;
    d->w350 = in->w78;
    if (((X_355F10 *)a0)->b43 != 5) func_00441C78_355F10(a0, 5, 0, 0);
}
/* localdecomp:end func_00355F10 */

/* localdecomp:start func_00355FE8 */
float func_00355FE8(void) {
    return 0.45f;
}
/* localdecomp:end func_00355FE8 */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00356000);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00356020);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00356100);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00356108);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00356110);
