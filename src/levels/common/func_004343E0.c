#include "common.h"

void func_004343E0(void) {
    __asm__ volatile (
        "sync.p\n"
        "mfc0 $8, $24\n"
        "lui $9, 0x7fff\n"
        "ori $9, $9, 0xffff\n"
        "and $8, $8, $9\n"
        "mtc0 $8, $24\n"
        "sync.p\n"
    );
}
