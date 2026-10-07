#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003E1D68();
extern void func_003E1C38();
extern void func_003E1C90(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003E1C38 */
extern f32 D_00225980[];
extern f32 D_001DA9C0;
extern s32 D_001DA9C4;
extern s32 D_001D55E8;
extern void func_003830E8();
extern void func_003A3EF0(s32, unsigned long);
void func_003E1C38(void) {
    D_001DA9C0 = D_00225980[0xB0/4];
    D_00225980[0xB0/4] = 0.62f;
    func_003830E8();
    func_003A3EF0(0x47, 0x33001);
    D_001DA9C4 = D_001D55E8;
}
/* localdecomp:end func_003E1C38 */

/* localdecomp:start func_003E1C90 */
extern s32 D_001DA9C4;
extern f32 D_001DA9C0;
extern f32 D_00225A30[];
extern void func_00389920();
extern void func_003830E8();
void func_003E1C90(void) {
    func_00389920(D_001DA9C4);
    D_00225A30[0] = D_001DA9C0;
    func_003830E8();
}
/* localdecomp:end func_003E1C90 */

/* localdecomp:start func_003E1CC8 */
extern void func_00384B68();
 
void func_003E1CC8(void) {
    func_00384B68(0);
}
/* localdecomp:end func_003E1CC8 */

/* localdecomp:start func_003E1CE8 */
extern void func_00384C98();
 
void func_003E1CE8(void) {
    func_00384C98();
}
/* localdecomp:end func_003E1CE8 */

LINKER_REMNANT("asm/remnants", func_003E1D08);

/* localdecomp:start func_003E1D18 */
extern f32 D_001D96D8;
extern f32 D_001D96DC;
extern f32 D_001D96E0;
extern f32 D_001D96E4;
extern f32 D_001D96E8;
extern f32 D_001D96EC;
void func_003E1D18(void) {
    D_001D96E8 = D_001D96D8 / D_001D96E0;
    D_001D96EC = D_001D96DC / D_001D96E4;
}
/* localdecomp:end func_003E1D18 */

/* localdecomp:start func_003E1D50 */
extern f32 D_001D96E8;
extern f32 D_001D96EC;
void func_003E1D50(f32 *a, f32 *b) { *a = D_001D96E8; *b = D_001D96EC; }
/* localdecomp:end func_003E1D50 */

/* localdecomp:start func_003E1D68 */
__asm__(".extern D_001D96C8, 4");
__asm__(".extern D_001D96CC, 4");
__asm__(".extern D_001D96D0, 4");
__asm__(".extern D_001D96D4, 4");
__asm__(".extern D_001D96D8, 4");
__asm__(".extern D_001D96DC, 4");
__asm__(".extern D_001D96E0, 4");
__asm__(".extern D_001D96E4, 4");
__asm__(".extern D_001D96F0, 4");
__asm__(".extern D_001D96F4, 4");
extern f32 D_001D96C8;
extern f32 D_001D96CC;
extern s32 D_001D96D0;
extern s32 D_001D96D4;
extern f32 D_001D96D8;
extern f32 D_001D96DC;
extern f32 D_001D96E0;
extern f32 D_001D96E4;
extern f32 D_001D96F0;
extern f32 D_001D96F4;
extern void func_003E1D18();
extern void func_0038C450(f32 *, f32 *, s32);
void func_003E1D68(s32 mode) {
    f32 v[2];
    f32 w;
    D_001D96C8 = 1.0f;
    D_001D96CC = 1.0f;
    D_001D96D0 = 0;
    D_001D96D4 = 0;
    D_001D96D8 = 512.0f;
    switch (mode) {
    case 0:
        w = 416.0f;
        D_001D96E0 = 512.0f;
        break;
    case 1:
        w = 448.0f;
        D_001D96E0 = 512.0f;
        break;
    default:
        goto skip;
    }
    D_001D96DC = w;
    D_001D96E4 = w;
skip:
    func_003E1D18();
    v[1] = v[0] = 0.0f;
    func_0038C450(v, v + 1, 1);
    D_001D96F0 = v[0] / D_001D96DC;
    D_001D96F4 = (v[1] + v[0] * 0.5f) / D_001D96DC;
}
/* localdecomp:end func_003E1D68 */
