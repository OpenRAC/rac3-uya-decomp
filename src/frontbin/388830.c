#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00388830(s32 a, s32 b, f32 x);
extern void func_003888F0();
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_00388830 */
void func_00388830(s32 a, s32 b, f32 x) {
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
        "beqz $at, .L00388870_00388830\n"
        "nop\n"
        "vwaitq\n"
        "vmulq.xyz $vf1, $vf1, Q\n"
        "jr $31\n"
        "sqc2 $vf1, 0($4)\n"
        ".L00388870_00388830:\n"
        ".set reorder\n"
        "vadd.xyz $vf1, $vf0, $vf0\n"
        "nop\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_00388830 */

/* localdecomp:start func_00388880 */
void func_00388880(void) {
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
/* localdecomp:end func_00388880 */

/* localdecomp:start func_003888C8 */
void func_003888C8(void) {
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
/* localdecomp:end func_003888C8 */

/* localdecomp:start func_003888F0 */
void func_003888F0(void) {
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
/* localdecomp:end func_003888F0 */

ASM_FUNC("asm/handwritten", func_00388920);

/* localdecomp:start func_00388948 */
void func_00388948(void) {
    __asm__ __volatile__(
        "pextlh $5, $5, $0\n"
        "psraw $5, $5, 16\n"
        "qmtc2.ni $5, $vf1\n"
        "vitof0.xyzw $vf1, $vf1\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_00388948 */
