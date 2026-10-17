#include "common.h"

extern u8 D_002590C0[];
extern s32 D_001E15A0;
extern void *func_00511660();
extern void func_00116FD0();
extern void func_00510888();
void *func_00510928(s32 idx) {
    u8 *q;
    s32 *w;
    s32 n, j;
    if (D_001E15A0 == 0) {
        q = D_002590C0;
        n = 4;
        do {
            w = (s32 *)(q + 0x50);
            for (j = 0x22; j != -1; j--) *w++ = 0;
            func_00511660(q + 0x1C4);
            func_00511660(q + 0x21CC);
            q += 0x41DC;
            n--;
        } while (n != -1);
        D_001E15A0 = 1;
        func_00116FD0(func_00510888);
    }
    return D_002590C0 + idx * 0x41DC;
}
