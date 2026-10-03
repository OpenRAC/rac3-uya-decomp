#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_003CC838 */
void func_003CC838(void) {
    __asm__ __volatile__(
        "vcallms 0xDA0\n"
        "qmfc2.i $at, $vf1\n"
        "vmuly.xyz $vf29, $vf30, $vf1y\n"
        "vaddaw.xyz ACC, $vf0, $vf0w\n"
        "vmsubx.xyz $vf5, $vf30, $vf1x\n"
        "vaddax.z ACC, $vf0, $vf1x\n"
        "vsubay.x ACC, $vf0, $vf29y\n"
        "vaddax.y ACC, $vf0, $vf29x\n"
        "vmaddz.xyz $vf3, $vf5, $vf30z\n"
        "vaddax.y ACC, $vf0, $vf1x\n"
        "vaddaz.x ACC, $vf0, $vf29z\n"
        "vsubax.z ACC, $vf0, $vf29x\n"
        "vmaddy.xyz $vf2, $vf5, $vf30y\n"
        "vaddax.x ACC, $vf0, $vf1x\n"
        "vsubaz.y ACC, $vf0, $vf29z\n"
        "vadday.z ACC, $vf0, $vf29y\n"
        "vmaddx.xyz $vf1, $vf5, $vf30x\n"
    );
}
/* localdecomp:end func_003CC838 */
