#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00389158(void *, void *, void *, f32);
typedef int u128_t __attribute__((mode(TI)));
extern void func_00388B68();
extern void func_00388F08();
/* --- end of declarations from other files --- */

/* localdecomp:start func_00388B40 */
void func_00388B40(void) {
    __asm__ __volatile__(
        "vmulx.xyzw $vf1, $vf0, $vf0x\n"
        "vmulx.xyzw $vf2, $vf0, $vf0x\n"
        "vmr32.xyzw $vf3, $vf0\n"
        "vaddw.x $vf1, $vf1, $vf0w\n"
        "vaddw.y $vf2, $vf2, $vf0w\n"
        "sqc2 $vf1, 0($4)\n"
        "sqc2 $vf2, 16($4)\n"
        "sqc2 $vf3, 32($4)\n"
    );
}
/* localdecomp:end func_00388B40 */

/* localdecomp:start func_00388B68 */
void func_00388B68(void) {
    __asm__ __volatile__(
        "vmulx.xyzw $vf1, $vf0, $vf0x\n"
        "vmulx.xyzw $vf2, $vf0, $vf0x\n"
        "vmr32.xyzw $vf3, $vf0\n"
        "vmove.xyzw $vf4, $vf0\n"
        "vaddw.x $vf1, $vf1, $vf0w\n"
        "vaddw.y $vf2, $vf2, $vf0w\n"
        "sqc2 $vf1, 0($4)\n"
        "sqc2 $vf2, 16($4)\n"
        "sqc2 $vf3, 32($4)\n"
        "sqc2 $vf4, 48($4)\n"
    );
}
/* localdecomp:end func_00388B68 */

/* localdecomp:start func_00388B98 */
void func_00388B98(void) {
    __asm__ __volatile__(
        "mfc1 $at, $f12\n"
        "qmtc2.ni $at, $vf5\n"
        "vmulx.xyzw $vf1, $vf0, $vf0x\n"
        "vmulx.xyzw $vf2, $vf0, $vf0x\n"
        "vmulx.xyzw $vf3, $vf0, $vf0x\n"
        "vmove.xyzw $vf4, $vf0\n"
        "vaddx.x $vf1, $vf1, $vf5x\n"
        "vaddx.y $vf2, $vf2, $vf5x\n"
        "vaddx.z $vf3, $vf3, $vf5x\n"
        "sqc2 $vf1, 0($4)\n"
        "sqc2 $vf2, 16($4)\n"
        "sqc2 $vf3, 32($4)\n"
        "sqc2 $vf4, 48($4)\n"
    );
}
/* localdecomp:end func_00388B98 */

/* localdecomp:start func_00388BD0 */
void func_00388BD0(void) {
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2 $vf1, 0($5)\n"
        "vcallms 0xC80\n"
        "qmfc2.i $at, $vf20\n"
        "sqc2 $vf20, 0($4)\n"
        "sqc2 $vf21, 16($4)\n"
        "sqc2 $vf22, 32($4)\n"
        ".set reorder\n"
    );
}
/* localdecomp:end func_00388BD0 */

/* localdecomp:start func_00388BF0 */
void func_00388BF0(void) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0($5)\n"
        "vcallms 0xC80\n"
        "qmfc2.i $at, $vf20\n"
        "sqc2 $vf20, 0($4)\n"
        "sqc2 $vf21, 16($4)\n"
        "sqc2 $vf22, 32($4)\n"
        "sqc2 $vf23, 48($4)\n"
    );
}
/* localdecomp:end func_00388BF0 */

ASM_FUNC("asm/handwritten", func_00388C10);

ASM_FUNC("asm/handwritten", func_00388E38);

ASM_FUNC("asm/handwritten", func_00388E58);

/* localdecomp:start func_00388E78 */
void func_00388E78(p, b) u8 *p; void *b; {  /* K&R: later callers pass (M_3BFAF8 *, void *) */
    register u128_t v __asm__("$10");
    __asm__ __volatile__(
        "lq $8, 0($5)\n"
        "lq $9, 16($5)\n"
        "lq $10, 32($5)\n"
        "pextlw $12, $9, $8\n"
        "sqc2 $vf0, 48($4)\n"
        "pextuw $13, $9, $8\n"
        "pextlw $14, $0, $10\n"
        "pextuw $15, $0, $10\n"
        "pcpyld $8, $14, $12\n"
        "pcpyud $9, $12, $14\n"
        "sq $8, 0($4)\n"
        "pcpyld $10, $15, $13\n"
        "sq $9, 16($4)\n"
        "nop\n"
        : "=r"(v) : : "memory"
    );
    *(u128_t *)(p + 0x20) = v;
}
/* localdecomp:end func_00388E78 */

/* localdecomp:start func_00388EB8 */
void func_00388EB8(void) {
    __asm__ __volatile__(
        "lqc2 $vf4, 0($5)\n"
        "lqc2 $vf5, 16($5)\n"
        "lqc2 $vf6, 32($5)\n"
        "lqc2 $vf1, 0($6)\n"
        "lqc2 $vf2, 16($6)\n"
        "lqc2 $vf3, 32($6)\n"
        "vmulax.xyzw ACC, $vf4, $vf1x\n"
        "vmadday.xyzw ACC, $vf5, $vf1y\n"
        "vmaddz.xyzw $vf1, $vf6, $vf1z\n"
        "vmulax.xyzw ACC, $vf4, $vf2x\n"
        "vmadday.xyzw ACC, $vf5, $vf2y\n"
        "vmaddz.xyzw $vf2, $vf6, $vf2z\n"
        "vmulax.xyzw ACC, $vf4, $vf3x\n"
        "vmadday.xyzw ACC, $vf5, $vf3y\n"
        "vmaddz.xyzw $vf3, $vf6, $vf3z\n"
        "nop\n"
        "sqc2 $vf1, 0($4)\n"
        "sqc2 $vf2, 16($4)\n"
        "sqc2 $vf3, 32($4)\n"
    );
}
/* localdecomp:end func_00388EB8 */

ASM_FUNC("asm/handwritten", func_00388F08);

/* localdecomp:start func_00388F50 */
void func_00388F50(void) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0($5)\n"
        "lqc2 $vf2, 0($6)\n"
        "vaddw.xyz $vf9, $vf0, $vf0w\n"
        "vmul.w $vf3, $vf2, $vf1\n"
        "vmul.xyz $vf4, $vf2, $vf1\n"
        "vmulw.xyz $vf5, $vf2, $vf1w\n"
        "vmulw.xyz $vf6, $vf1, $vf2w\n"
        "vopmula.xyz ACC, $vf1, $vf2\n"
        "vopmsub.xyz $vf7, $vf2, $vf1\n"
        "vadday.x ACC, $vf4, $vf4y\n"
        "vmaddz.x $vf4, $vf9, $vf4z\n"
        "vadd.xyz $vf8, $vf5, $vf6\n"
        "vadd.xyz $vf8, $vf8, $vf7\n"
        "vsubx.w $vf8, $vf3, $vf4x\n"
        "sqc2 $vf8, 0($4)\n"
    );
}
/* localdecomp:end func_00388F50 */

/* localdecomp:start func_00388F90 */
void func_00388F90(void) {
    __asm__ __volatile__(
        ".set noreorder\n"
        "mfc1 $at, $f12\n"
        "qmtc2.ni $at, $vf3\n"
        "lqc2 $vf1, 0($5)\n"
        "lqc2 $vf2, 0($6)\n"
        "vsubx.w $vf3, $vf0, $vf3x\n"
        "vaddw.xyz $vf7, $vf0, $vf0w\n"
        "vmulw.xyzw $vf1, $vf1, $vf3w\n"
        "vmulx.xyzw $vf2, $vf2, $vf3x\n"
        "vadd.xyzw $vf4, $vf1, $vf2\n"
        "vmul.xyzw $vf6, $vf1, $vf2\n"
        "vmul.xyzw $vf5, $vf4, $vf4\n"
        "vaddax.y ACC, $vf6, $vf6x\n"
        "vmaddaz.y ACC, $vf7, $vf6z\n"
        "vmaddw.y $vf6, $vf7, $vf6w\n"
        "vadday.x ACC, $vf5, $vf5y\n"
        "vmaddaz.x ACC, $vf7, $vf5z\n"
        "vmaddw.x $vf5, $vf7, $vf5w\n"
        "qmfc2.ni $9, $vf6\n"
        "bgez $9, .L00388FF8_00388F90\n"
        "nop\n"
        "vsub.xyzw $vf4, $vf1, $vf2\n"
        "vmul.xyzw $vf5, $vf4, $vf4\n"
        "vadday.x ACC, $vf5, $vf5y\n"
        "vmaddaz.x ACC, $vf7, $vf5z\n"
        "vmaddw.x $vf5, $vf7, $vf5w\n"
        "nop\n"
        ".L00388FF8_00388F90:\n"
        "nop\n"
        "nop\n"
        "vrsqrt Q, $vf0w, $vf5x\n"
        "vwaitq\n"
        "vmulq.xyzw $vf1, $vf4, Q\n"
        "sqc2 $vf1, 0($4)\n"
        ".set reorder\n"
    );
}
/* localdecomp:end func_00388F90 */

ASM_FUNC("asm/handwritten", func_00389018);

/* localdecomp:start func_003890D8 */
void func_003890D8(void) {
    __asm__ __volatile__(
        "lqc2 $vf8, 0($4)\n"
        "vcallms 0xE98\n"
        "vnop\n"
        "sqc2 $vf14, 0($5)\n"
        "sqc2 $vf15, 16($5)\n"
        "sqc2 $vf16, 32($5)\n"
    );
}
/* localdecomp:end func_003890D8 */

/* localdecomp:start func_003890F8 */
void func_003890F8(void) {
    __asm__ __volatile__(
        "lqc2 $vf8, 0($4)\n"
        "vcallms 0xE98\n"
        "vnop\n"
        "sqc2 $vf14, 0($5)\n"
        "sqc2 $vf15, 16($5)\n"
        "sqc2 $vf16, 32($5)\n"
        "sqc2 $vf0, 48($5)\n"
    );
}
/* localdecomp:end func_003890F8 */

/* localdecomp:start func_00389118 */
void func_00389118(void) {
    __asm__ __volatile__(
        "lqc2 $vf4, 0($6)\n"
        "lui $8, 0x3fb5\n"
        "lqc2 $vf5, 0($5)\n"
        "ori $8, $8, 0x4f3\n"
        "qmtc2.ni $8, $vf6\n"
        "vmulx.xyzw $vf4, $vf4, $vf6x\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vmaddaw.xyz ACC, $vf5, $vf4w\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vopmula.xyz ACC, $vf4, $vf6\n"
        "vmaddaw.xyz ACC, $vf5, $vf0w\n"
        "vopmsub.xyz $vf5, $vf6, $vf4\n"
        "sqc2 $vf5, 0($4)\n"
    );
}
/* localdecomp:end func_00389118 */

LINKER_REMNANT("asm/remnants", func_00389150);

ASM_FUNC("asm/handwritten", func_00389158);

/* localdecomp:start func_00389240 */
void func_00389240(void) {
    __asm__ __volatile__(
        "lqc2 $vf8, 0($4)\n"
        "lqc2 $vf1, 0($5)\n"
        "vmulx.xyzw $vf14, $vf0, $vf0x\n"
        "vmulx.xyzw $vf15, $vf0, $vf0x\n"
        "vmr32.xyzw $vf16, $vf0\n"
        "lqc2 $vf17, 0($6)\n"
        "vaddw.x $vf14, $vf14, $vf0w\n"
        "vaddw.y $vf15, $vf15, $vf0w\n"
        "vadd.xyzw $vf9, $vf8, $vf8\n"
        "vmulw.xyz $vf10, $vf9, $vf8w\n"
        "vmulx.xyz $vf11, $vf9, $vf8x\n"
        "vmuly.yz $vf12, $vf9, $vf8y\n"
        "vmulz.z $vf13, $vf9, $vf8z\n"
        "vaddz.x $vf15, $vf0, $vf10z\n"
        "vsuby.x $vf16, $vf0, $vf10y\n"
        "vaddx.y $vf16, $vf0, $vf10x\n"
        "vsuby.x $vf14, $vf14, $vf12y\n"
        "vsubx.y $vf15, $vf15, $vf11x\n"
        "vsubx.z $vf16, $vf16, $vf11x\n"
        "vsubz.y $vf14, $vf11, $vf10z\n"
        "vaddy.z $vf14, $vf11, $vf10y\n"
        "vsubx.z $vf15, $vf12, $vf10x\n"
        "vaddy.x $vf15, $vf15, $vf11y\n"
        "vaddz.x $vf16, $vf16, $vf11z\n"
        "vaddz.y $vf16, $vf16, $vf12z\n"
        "vsubz.x $vf14, $vf14, $vf13z\n"
        "vsubz.y $vf15, $vf15, $vf13z\n"
        "vsuby.z $vf16, $vf16, $vf12y\n"
        "vmulx.xyz $vf14, $vf14, $vf1x\n"
        "vmuly.xyz $vf15, $vf15, $vf1y\n"
        "vmulz.xyz $vf16, $vf16, $vf1z\n"
        "vaddx.w $vf17, $vf0, $vf0x\n"
        "sqc2 $vf14, 0($7)\n"
        "sqc2 $vf15, 16($7)\n"
        "sqc2 $vf16, 32($7)\n"
        "sqc2 $vf17, 48($7)\n"
    );
}
/* localdecomp:end func_00389240 */

/* localdecomp:start func_003892D8 */
void func_003892D8(void) {
    __asm__ __volatile__(
        "ld $at, 0x0($4)\n"
        "nop\n"
        "ld $2, 0x8($4)\n"
        "pextlh $at, $at, $0\n"
        "ld $3, 0x10($4)\n"
        "psraw $at, $at, 16\n"
        "pextlh $2, $2, $0\n"
        "qmtc2.ni $at, $vf1\n"
        "psrlw $2, $2, 13\n"
        "qmtc2.ni $0, $vf0\n"
        "pextlh $3, $3, $0\n"
        "qmtc2.ni $2, $vf2\n"
        "psraw $3, $3, 16\n"
        "qmtc2.ni $3, $vf3\n"
        "vitof15.xyzw $vf1, $vf1\n"
        "vitof15.xyz $vf2, $vf2\n"
        "vitof0.xyz $vf3, $vf3\n"
        "sqc2 $vf1, 0($5)\n"
        "sqc2 $vf2, 16($5)\n"
        "nop\n"
        "sqc2 $vf3, 32($5)\n"
    );
}
/* localdecomp:end func_003892D8 */

/* localdecomp:start func_00389330 */
void func_00389330(void) {
    __asm__ __volatile__(
        "mfc1 $at, $f12\n"
        "qmtc2.ni $at, $vf7\n"
        "vsubx.w $vf7, $vf0, $vf7x\n"
        "nop\n"
        "lqc2 $vf1, 0($5)\n"
        "lqc2 $vf2, 16($5)\n"
        "lqc2 $vf3, 32($5)\n"
        "lqc2 $vf4, 0($6)\n"
        "lqc2 $vf5, 16($6)\n"
        "lqc2 $vf6, 32($6)\n"
        "vmulaw.xyzw ACC, $vf1, $vf7w\n"
        "vmaddx.xyzw $vf1, $vf4, $vf7x\n"
        "vmulaw.xyzw ACC, $vf2, $vf7w\n"
        "vmaddx.xyzw $vf2, $vf5, $vf7x\n"
        "vmulaw.xyzw ACC, $vf3, $vf7w\n"
        "vmaddx.xyzw $vf3, $vf6, $vf7x\n"
        "sqc2 $vf1, 0($4)\n"
        "sqc2 $vf2, 16($4)\n"
        "sqc2 $vf3, 32($4)\n"
    );
}
/* localdecomp:end func_00389330 */
