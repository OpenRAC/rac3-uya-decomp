#include "common.h"
typedef struct {
    s32 w0;
    u8 pad4[24];
    s32 w28;
    u8 pad32[17];
    u8 b49;
    u8 pad50[18];
} E_0053CC58;
extern E_0053CC58 D_0033F460[];
extern void func_0053CEE8(s32);
s32 func_0053CC58(s32 a0) {
    E_0053CC58 *e;
    s32 i;
    for (i = 0; i < 50; i++) {
        e = &D_0033F460[i];
        if (e->b49 == 1 && e->w28 == a0) {
            e->b49 = 0;
            func_0053CEE8(e->w0);
            return e->w0;
        }
    }
    return -1;
}
