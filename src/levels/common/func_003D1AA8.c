#include "common.h"
typedef struct {
    void (*f0)(u8 *);
    void (*f4)(u8 *);
} Vt003D1AA8;
extern void func_0044CA40(u8 *a0, u8 *a1);
extern Vt003D1AA8 *func_004395A8(s32 a0, s32 a1);
extern void func_00437360(u8 *a0);
void func_003D1AA8(u8 *a0, s32 a1) {
    u8 *s0 = *(u8 **)(a0 + 104);
    Vt003D1AA8 *vt;
    func_0044CA40(a0, s0 + 352);
    func_0044CA40(a0, s0 + 480);
    if (*(s32 *)(s0 + 336) != 0) {
        vt = func_004395A8(6625, 108);
        vt->f0(a0);
        if (a1 != 0) {
            vt->f4(a0);
        }
    } else {
        func_00437360(a0);
    }
}
