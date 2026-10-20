#include "common.h"

extern void func_00436220(u8 *);
extern void func_00441FB8(u8 *, int, int);
extern void func_003D34B8(u8 *, int);
extern void func_004026A0(void (*)(u8 *), u8 *);
extern void func_003D33F8(u8 *);

void func_003D3708(u8 *m) {
    u8 *pv = *(u8 **)(m + 0x68);
    u8 *e;
    u8 *t;
    int i;

    if (m[0x20] == 0) {
        for (i = 0; i < *(int *)(pv + 676); i++) {
            e = pv + i * 224;
            t = *(u8 **)(e + 208);
            if (t == 0) {
                goto kill;
            }
            if (t[0x20] == 254) {
                goto kill;
            }
            if (t[0x20] == 253) {
                goto kill;
            }
            if (*(u16 *)(t + 0x34) & 2) {
                goto kill;
            }
            t = *(u8 **)(e + 200);
            if (t == 0) {
                goto ok;
            }
            if (t[0x20] == 254) {
                goto kill;
            }
            if (t[0x20] == 253) {
                goto kill;
            }
            if (!(*(u16 *)(t + 0x34) & 2)) {
                goto ok;
            }
        kill:
            func_00441FB8(m, 1, -1);
            continue;
        ok:
            func_003D34B8(m, i);
            func_004026A0(func_003D33F8, m);
        }
    } else {
        func_00436220(m);
    }
}
