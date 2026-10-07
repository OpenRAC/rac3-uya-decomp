#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003E7528();
extern void func_003E73F8();
extern void func_003E7450(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003E73F8 */
extern f32 D_00225980[];
extern f32 D_001DA9C0;
extern s32 D_001DA9C4;
extern s32 D_001D55E8;
extern void func_00387778();
extern void func_003A96B0(s32, unsigned long);
void func_003E73F8(void) {
    D_001DA9C0 = D_00225980[0xB0/4];
    D_00225980[0xB0/4] = 0.62f;
    func_00387778();
    func_003A96B0(0x47, 0x33001);
    D_001DA9C4 = D_001D55E8;
}
/* localdecomp:end func_003E73F8 */

/* localdecomp:start func_003E7450 */
extern s32 D_001DA9C4;
extern f32 D_001DA9C0;
extern f32 D_00225A30[];
extern void func_0038E478();
extern void func_00387778();
void func_003E7450(void) {
    func_0038E478(D_001DA9C4);
    D_00225A30[0] = D_001DA9C0;
    func_00387778();
}
/* localdecomp:end func_003E7450 */

/* localdecomp:start func_003E7488 */
extern void func_003895C8();
 
void func_003E7488(void) {
    func_003895C8(0);
}
/* localdecomp:end func_003E7488 */

/* localdecomp:start func_003E74A8 */
extern void func_003896F8();
 
void func_003E74A8(void) {
    func_003896F8();
}
/* localdecomp:end func_003E74A8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E74C8);

/* localdecomp:start func_003E74D8 */
extern f32 D_001D96D8;
extern f32 D_001D96DC;
extern f32 D_001D96E0;
extern f32 D_001D96E4;
extern f32 D_001D96E8;
extern f32 D_001D96EC;
void func_003E74D8(void) {
    D_001D96E8 = D_001D96D8 / D_001D96E0;
    D_001D96EC = D_001D96DC / D_001D96E4;
}
/* localdecomp:end func_003E74D8 */

/* localdecomp:start func_003E7510 */
extern f32 D_001D96E8;
extern f32 D_001D96EC;
void func_003E7510(f32 *a, f32 *b) { *a = D_001D96E8; *b = D_001D96EC; }
/* localdecomp:end func_003E7510 */

/* localdecomp:start func_003E7528 */
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
extern void func_003E74D8();
extern void func_00390FA8(f32 *, f32 *, s32);
void func_003E7528(s32 mode) {
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
    func_003E74D8();
    v[1] = v[0] = 0.0f;
    func_00390FA8(v, v + 1, 1);
    D_001D96F0 = v[0] / D_001D96DC;
    D_001D96F4 = (v[1] + v[0] * 0.5f) / D_001D96DC;
}
/* localdecomp:end func_003E7528 */
