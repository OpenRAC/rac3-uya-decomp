#include "common.h"

extern u8 *D_001DFCB4;
extern void func_0045E580(u8 *);
extern void func_00436220(u8 *);

void func_00303440(u8 *m) {
    u8 **p;
    s32 i;

    p = (u8 **)(*(u8 **)(m + 104) + 48);
    for (i = 0; i < 8; i++) {
        if (p[i] != 0) {
            func_0045E580(p[i]);
            p[i] = 0;
        }
    }
    if (D_001DFCB4 == m) {
        m[32] = 4;
    } else {
        func_00436220(m);
    }
}
