#include "common.h"

extern f32 D_001DD1B8;
extern f32 D_001DD1BC;

extern void func_00441FB8(u8 *, s32, s32);
extern void func_003407A0(u8 *);
extern void func_003405B0(u8 *);
extern void func_004450C0(f32 *, f32, f32);
extern void func_00340980();
extern void func_00402498(void (*)(), u8 *);
extern void func_0044B598(s32, s32);
extern void func_00436220(u8 *);

void func_00340458(u8 *a0) {
    u8 *s;
    f32 one;
    s32 i;
    s32 *pa;
    s32 *pb;
    s32 st;

    st = a0[32];
    s = *(u8 **)(a0 + 104);
    switch (st) {
    case 0:
        func_00441FB8(a0, 1, -1);
        break;
    case 1:
        one = 1.0f;
        if (*(f32 *)(s + 8) < one) {
            func_004450C0((f32 *)(s + 8), one, D_001DD1B8 * 0.016666668f);
        } else if (*(f32 *)(s + 12) < one) {
            if (*(s32 *)(s + 4) == 0) {
                *(s32 *)(s + 4) = st;
                func_003407A0(a0);
            }
            func_003405B0(a0);
            func_004450C0((f32 *)(s + 12), one, D_001DD1BC * 0.016666668f);
        } else {
            pb = (s32 *)(s + 48);
            pa = (s32 *)(s + 16);
            for (i = 3; i >= 0; i--) {
                if (*pa != 0) {
                    *(u16 *)(*pa + 52) = *(u16 *)((u8 *)pb - 16);
                    func_0044B598(*pa, *pb);
                }
                pb++;
                pa++;
            }
            func_00436220(a0);
            break;
        }
        func_00402498(func_00340980, a0);
        break;
    }
}
