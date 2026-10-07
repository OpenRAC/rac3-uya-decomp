#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_0038DEC8 */
float func_0038DEC8(float first, float second) {
    register float difference __asm__("$f0");
    register float pi __asm__("$f14");
    register float doubled __asm__("$f1");

    difference = first - second;
    pi = 3.1415927f;
    __asm__ volatile(".word 0" : "+f"(pi));
    difference = __builtin_fabsf(difference);
    if (difference < pi) {
        goto done;
    }
    doubled = pi + pi;
    difference = doubled - difference;
done:
    return difference;
}
/* localdecomp:end func_0038DEC8 */
