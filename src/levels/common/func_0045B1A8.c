#include "common.h"

extern int D_0021E8E0[];
extern u8 *D_001E00A8;
extern u8 *D_001E009C;
extern void func_004389D8(u8 *);
extern void func_00439610(u8 *);

void func_0045B1A8(void) {
    u8 *obj;
    u8 *prev;
    u8 *o;
    void (*fn)(u8 *);

    D_0021E8E0[0] = 0;
    D_001E00A8 = 0;
    prev = 0;
    for (obj = D_001E009C; obj[0x20] != 0xFF; obj += 0x100) {
        if (obj[0x20] & 0x80) {
            continue;
        }
        if (*(u16 *)(obj + 0x34) & 2) {
            continue;
        }
        if (prev != 0) {
            *(u8 **)(prev + 0x28) = obj;
        } else {
            D_001E00A8 = obj;
        }
        prev = obj;
    }
    if (prev != 0) {
        *(u8 **)(prev + 0x28) = 0;
    }
    for (o = D_001E00A8; o != 0; o = *(u8 **)(o + 0x28)) {
        if ((s8)o[0x20] < 0) {
            continue;
        }
        if (!(*(u16 *)(o + 0x34) & 0x40)) {
            func_004389D8(o);
        }
        fn = *(void (**)(u8 *))(o + 0x64);
        if (fn != 0 && !(*(u16 *)(o + 0x34) & 2)) {
            fn(o);
        }
        if (!(*(u16 *)(o + 0x34) & 4)) {
            func_00439610(o);
        }
    }
}
