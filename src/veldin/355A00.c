#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00355A00);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00355A58);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00355AE0);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00355BC0);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00355C90);

/* localdecomp:start func_00355E08 */
void func_00355E08(char *a0) {
    *(int *)(*(char **)(a0 + 0x68) + 0x354) = 0;
}
/* localdecomp:end func_00355E08 */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00355E18);

/* localdecomp:start func_00355F10 */
typedef struct { s32 w0; f32 f4; s32 w8; f32 fc; s32 w10; s32 w14; s32 w18; } SrcData;
typedef struct {
    u8 pad0[0x2e0]; s32 w2e0; f32 f2e4; s32 w2e8; f32 f2ec;
    u8 pad2f0[0x344 - 0x2f0]; s32 w344; s32 w348; s32 w34c; s32 w350;
} DstData;
typedef struct { s32 id; u8 pad4[0x74]; s32 w78; u8 pad7c[0x118 - 0x7c]; s32 w118; } Inner;
typedef struct { u8 pad0[8]; Inner *pad8; } Mid;
typedef struct { u8 pad0[8]; Inner *f8; u8 pad[0x68 - 0xc]; void *d68; } Obj;
typedef struct { u8 pad0[0x43]; u8 b43; } X;
extern struct { u8 pad0[8]; struct { u8 pad0[0x68]; Inner *i68; } *w8; } *func_00445F18(void *);
extern void func_00441C78(void *, s32, s32, s32);
void func_00355F10(void *a0, void *a1) {
    DstData *d = *(DstData **)((u8 *)a0 + 0x68);
    Inner *in = func_00445F18(a0)->w8->i68;
    SrcData *s = *(SrcData **)((u8 *)a1 + 0x68);
    d->w2e0 = s->w0;
    if (s->f4 > 0.0f) d->f2e4 = s->f4;
    d->w2e8 = s->w8;
    if (s->fc > 0.0f) d->f2ec = s->fc;
    d->w348 = s->w10;
    d->w34c = s->w18;
    if (in->id == 0x1ab4) d->w344 = in->w118;
    else d->w344 = -1;
    d->w350 = in->w78;
    if (((X *)a0)->b43 != 5) func_00441C78(a0, 5, 0, 0);
}
/* localdecomp:end func_00355F10 */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00355FE8);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00356000);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00356020);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00356100);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00356108);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00356110);
