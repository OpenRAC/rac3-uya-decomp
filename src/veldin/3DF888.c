#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003DF888);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003DFC48);

/* localdecomp:start func_003DFD90 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_00435E70(s32, s32);
extern void func_00439610(u8 *);
extern void func_0040C658(f32 *, u8 *);
extern s32 func_00440878(s32, s32);
extern void func_0040CCA0(f32 *, f32 *, f32 *, f32);
extern void func_00447748(f32 *, u8 *);

u8 *func_003DFD90(u8 *src, s32 id, s32 type) {
    u8 *m;
    long t;
    f32 v[16];
    f32 r;

    m = func_00435E70(id, 128);
    if (m != 0) {
        *(s16 *)(m + 50) = 255;
        m[49] = 1;
        *(f32 *)(m + 44) *= *(f32 *)(src + 44) / *(f32 *)(*(u8 **)(src + 36) + 36);
        *(u128_t *)(m + 16) = *(u128_t *)(src + 16);
        func_0040C658(v, src + 240);
        r = (f32)func_00440878(0, 7) * 3.1415927f * 0.25f;
        func_0040CCA0(v + 4, v + 4, v, r);
        func_0040CCA0(v + 8, v + 8, v, r);
        func_00447748(v, m + 240);
        t = *(long *)(src + 56);
        m[48] = type;
        *(s16 *)(m + 52) = 0;
        *(long *)(m + 56) = t;
        func_00439610(m);
        *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 36) + 16);
        return m;
    }
    return 0;
}
/* localdecomp:end func_003DFD90 */

/* localdecomp:start func_003DFEB8 */
extern u8 D_001D66B0[];
extern s32 func_00444358(void *, s32, s32);
extern void func_004A7200(s32, s32, void *);
extern void func_0044ED60(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003DFD90(void *, s32, s32);
extern void func_0044EBF8(void *, s32, f32);
extern void func_00436220(void *);
void func_003DFEB8(void *o) {
    if (func_00444358(o, -1, 0) != 0) {
        func_004A7200(0, 0, o);
        func_0044ED60(o, 15, D_001D66B0, 255, 180, 0, 0, 35, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_003DFD90(o, 0x1e3d, 0);
        func_0044EBF8(o, 1, 0.0f);
        func_00436220(o);
    }
}
/* localdecomp:end func_003DFEB8 */

/* localdecomp:start func_003DFF88 */
extern void func_003E0020(void *);
extern s32 func_0040BA90(void *);
extern void func_003E01C0(void *);
extern void func_003E0078();
void func_003DFF88(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);

    switch (m[0x20]) {
    case 0:
        func_003E0020(m);
        break;
    case 1:
        break;
    case 2:
        if (func_0040BA90(v + 8)) {
            func_003E01C0(m);
        }
        break;
    case 3:
        func_003E0078(m);
        break;
    case 4:
        func_00436220(m);
        break;
    }
}
/* localdecomp:end func_003DFF88 */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003E0020);

/* localdecomp:start func_003E0078 */
typedef int s128 __attribute__((mode(TI)));
extern void func_0032FE90(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 *func_003AFF80(u8 *, s128 *, s128 *, s32, s32, s32, s32, f32, f32);
void func_003E0078(u8 *o, s32 *p) {
    s128 v[2];
    switch (*p) {
    case 0x13A1:
        func_0032FE90(o + 16, 1, 25, 20, 20, 20, 45, 2, 1.0f, 0.0f, 0.0f, 2.0f,
                      1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        break;
    case 0x19C5:
        v[0] = *(s128 *)(o + 16);
        v[1] = *(s128 *)(o + 192);
        func_003AFF80(o, &v[0], &v[1], 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, 0.0f, 0.65f);
        break;
    }
}
/* localdecomp:end func_003E0078 */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003E01C0);

LINKER_REMNANT("asm/veldin/remnants", func_003E01F0);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003E0200);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_003E0220);

