#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void func_0038D290(s32 a, s32 b, f32 x);
extern void func_0038D350();
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_0038D290 */
/* func_0038D2DC (4 bytes, the sqc2 in this function's jr delay slot) was a split artifact. */
void func_0038D290(s32 a, s32 b, f32 x) {
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2 $vf1, 0($5)\n"
        "vaddw.xyz $vf3, $vf0, $vf0w\n"
        "vmul.xyz $vf2, $vf1, $vf1\n"
        "vadday.x ACC, $vf2, $vf2y\n"
        "vmaddz.x $vf2, $vf3, $vf2z\n"
        "mfc1 $at, $f12\n"
        "qmtc2.ni $at, $vf3\n"
        "vrsqrt Q, $vf3x, $vf2x\n"
        "qmfc2.ni $at, $vf2\n"
        "dsll32 $at, $at, 0\n"
        "beqz $at, .L00388870_0038D290\n"
        "nop\n"
        "vwaitq\n"
        "vmulq.xyz $vf1, $vf1, Q\n"
        "jr $31\n"
        "sqc2 $vf1, 0($4)\n"
        ".L00388870_0038D290:\n"
        ".set reorder\n"
        "vadd.xyz $vf1, $vf0, $vf0\n"
        "nop\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_0038D290 */

/* localdecomp:start func_0038D2E0 */
void func_0038D2E0(void) {
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2 $vf1, 0($5)\n"
        "vmul.xy $vf2, $vf1, $vf1\n"
        "vaddy.x $vf2, $vf2, $vf2y\n"
        "mfc1 $at, $f12\n"
        "qmtc2.ni $at, $vf3\n"
        "vrsqrt Q, $vf3x, $vf2x\n"
        "qmfc2.ni $at, $vf2\n"
        "dsll32 $at, $at, 0\n"
        "beqz $at, .L003888B8_00388880\n"
        "nop\n"
        "vwaitq\n"
        "vmulq.xy $vf1, $vf1, Q\n"
        "jr $31\n"
        "sqc2 $vf1, 0($4)\n"
        ".L003888B8_00388880:\n"
        ".set reorder\n"
        "vadd.xy $vf1, $vf0, $vf0\n"
        "nop\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_0038D2E0 */

/* localdecomp:start func_0038D328 */
void func_0038D328(void) {
    __asm__ __volatile__(
        "lqc2 $vf5, 0($5)\n"
        "lqc2 $vf1, 0($6)\n"
        "lqc2 $vf2, 16($6)\n"
        "lqc2 $vf3, 32($6)\n"
        "vmulax.xyzw ACC, $vf1, $vf5x\n"
        "vmadday.xyzw ACC, $vf2, $vf5y\n"
        "vmaddaz.xyzw ACC, $vf3, $vf5z\n"
        "vmaddw.xyzw $vf6, $vf0, $vf5w\n"
        "sqc2 $vf6, 0($4)\n"
    );
}
/* localdecomp:end func_0038D328 */

/* localdecomp:start func_0038D350 */
void func_0038D350(void) {
    __asm__ __volatile__(
        "lqc2 $vf5, 0($5)\n"
        "lqc2 $vf1, 0($6)\n"
        "lqc2 $vf2, 16($6)\n"
        "lqc2 $vf3, 32($6)\n"
        "lqc2 $vf4, 48($6)\n"
        "nop\n"
        "vmulax.xyzw ACC, $vf1, $vf5x\n"
        "vmadday.xyzw ACC, $vf2, $vf5y\n"
        "vmaddaz.xyzw ACC, $vf3, $vf5z\n"
        "vmaddw.xyzw $vf6, $vf4, $vf5w\n"
        "sqc2 $vf6, 0($4)\n"
    );
}
/* localdecomp:end func_0038D350 */


ASM_FUNC("asm/boot_elf/handwritten", func_0038D380);

/* localdecomp:start func_0038D3A8 */
void func_0038D3A8(void) {
    __asm__ __volatile__(
        "pextlh $5, $5, $0\n"
        "psraw $5, $5, 16\n"
        "qmtc2.ni $5, $vf1\n"
        "vitof0.xyzw $vf1, $vf1\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_0038D3A8 */

