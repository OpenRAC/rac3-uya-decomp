#include "common.h"

extern u8 D_001CCFD0[];

void func_0045BFF0(s32 a0) {
    u8 *p = D_001CCFD0;
    if (*(s16 *)(p + 80) & 0x8000) {
        *(s16 *)(p + 82) = a0;
    }
    if (*(s16 *)(p + 200) & 0x8000) {
        *(s16 *)(p + 202) = a0;
    }
    if (*(s16 *)(p + 120) & 0x8000) {
        *(s16 *)(p + 122) = a0;
    }
}
