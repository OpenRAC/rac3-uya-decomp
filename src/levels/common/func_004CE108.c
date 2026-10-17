#include "common.h"

u8 *func_004CE108(u8 *p) {
    u8 *q; u8 *base; s32 i, j, k;
    base = p;
    for (j = 3; j != -1; j--) {
        q = base;
        for (k = 25; k != -1; k--) { func_004C9090(q); q += 0x3C; }
        base += 0x618;
    }
    func_004C9090(p + 0x1860);
    q = p + 0x18A0;
    for (i = 3; i != -1; i--) { func_004CBAB0(q); q += 0xB50; }
    func_004C93D0(p + 0x45E0);
    q = p + 0x4610;
    for (i = 3; i != -1; i--) { func_004C9CB0(q); q += 0x230; }
    func_004C9CB0(p + 0x4ED0);
    return p;
}
