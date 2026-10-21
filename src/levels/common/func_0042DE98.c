#include "common.h"

/* localdecomp:start func_0042DE98 */
extern void func_0040BD58(u8 *, u32 *, s32);

void func_0042DE98(u8 *dst, u8 *src) {
    u32 table[256];
    u32 buf[16];
    s32 k;
    s32 i;
    s32 j;

    for (i = 0; i < 256; i++) {
        table[i] = 0;
        if (i & 1) table[i] = 0xF;
        if (i & 2) table[i] |= 0xF0;
        if (i & 4) table[i] |= 0xF00;
        if (i & 8) table[i] |= 0xF000;
        if (i & 0x10) table[i] |= 0xF0000;
        if (i & 0x20) table[i] |= 0xF00000;
        if (i & 0x40) table[i] |= 0xF000000;
        if (i & 0x80) table[i] |= 0xF0000000;
    }
    for (k = 0; k < 128; k++) {
        u32 *q = buf;
        for (j = 0; j < 16; j++) {
            *q++ = table[*src++];
        }
        func_0040BD58(dst, buf, 64);
        dst += 64;
        func_0040BD58(dst, buf, 64);
        dst += 64;
        func_0040BD58(dst, buf, 64);
        dst += 64;
        func_0040BD58(dst, buf, 64);
        dst += 64;
    }
}
/* localdecomp:end func_0042DE98 */
