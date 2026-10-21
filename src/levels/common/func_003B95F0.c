#include "common.h"

/* localdecomp:start func_003B95F0 */
typedef int Q_003B95F0 __attribute__((mode(TI)));
extern void func_0041C590(void *, void *, s32);
extern f32 func_0041C8F0(void *, void *);
extern void func_00451098(void *, s32, s32, s32);
extern void func_004536F0(void *);
extern u8 D_001E28C0[];

void func_003B95F0(u8 *o) {
    u8 *p;
    if (*(u16 *)(o + 0x34) & 0x80) {
        return;
    }
    p = *(u8 **)(o + 0xB8);
    *(Q_003B95F0 *)(o + 0x10) = *(Q_003B95F0 *)(p + 0x10);
    *(Q_003B95F0 *)(o + 0xF0) = *(Q_003B95F0 *)(p + 0xF0);
    func_0041C590(o + 0xC0, p + 0xC0, 0x30);
    if (*(s32 *)(*(u8 **)(*(u8 **)(o + 0xB8) + 0x68) + 0x18) != 0) {
        if (o[0x43] != 1) {
            func_00451098(o, 1, 0, 10);
        }
    } else if (o[0x43] != 0) {
        func_00451098(o, 0, 0, 10);
    }
    if (o[0x31] != 0 && func_0041C8F0(D_001E28C0, o + 0x10) < 576.0f) {
        func_004536F0(o);
        o[0x6F] = 0x16;
    }
}
/* localdecomp:end func_003B95F0 */
