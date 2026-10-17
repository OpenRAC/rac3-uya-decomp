#include "common.h"

extern void *D_002497C0[];
extern void func_00494A60(void *);
extern void func_00474F30(void *);

void func_003DAE40(u8 *m) {
    void **p = (void **)(*(u8 **)(m + 0x68) + 0x30);
    s32 i;

    for (i = 3; i >= 0; i--, p++) {
        if (*p != 0) {
            func_00494A60(*p);
            *p = 0;
        }
    }
    if (D_002497C0[0] == m) {
        m[0x20] = 4;
    } else {
        func_00474F30(m);
    }
}
