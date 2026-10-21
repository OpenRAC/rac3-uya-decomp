#include "common.h"

/* localdecomp:start func_00325CE8 */
typedef void (*Func00325CE8Cb)(void *, s32, s32);

extern void func_00329180(void *, u8 *);
extern void func_003B1130(void *);
extern void func_00327F28(void *, u8 *);
extern void func_003252F0(void *, u8 *);
extern void func_003254A8(void *, u8 *);
extern void func_00325578(void *, u8 *);
extern s32 func_00326340(void *, u8 *);
extern void func_004FC518(s32, s32);
extern void func_00441FB8(void *, s32, s32);
extern f32 D_001DF9D0 __attribute__((section(".sdata")));
extern s32 D_001A71A4[];
extern u8 D_001A71D7[];

void func_00325CE8(void *arg0, u8 *arg1, void *arg2, u8 *arg3) {
    u8 *s2;

    s2 = *(u8 **)(*(u8 **)(arg1 + 48) + 104);
    func_00329180(arg0, arg1);
    func_003B1130(*(void **)(arg1 + 48));
    func_00327F28(arg0, arg1);
    func_003252F0(arg0, arg1);
    func_003254A8(arg0, arg1);
    func_00325578(arg0, arg1);
    if (*(s32 *)(arg1 + 64) == 0 && func_00326340(arg0, arg1) != 0) {
        func_004FC518(116, 1);
        func_00441FB8(arg0, 3, -1);
        D_001DF9D0 = 2.0f;
        if (arg2 != 0) {
            (*(Func00325CE8Cb *)(arg3 + 40))(arg2, *(s32 *)(arg1 + 24), 0);
        }
    } else {
        if (*(s32 *)(s2 + 48) == 0 || *(f32 *)(s2 + 44) == 0.0f) {
            if (D_001A71A4[0] != 176) {
                func_004FC518(0, 1);
            }
        }
        func_00441FB8(arg0, 1, -1);
    }
    *(s32 *)(arg1 + 48) = 0;
    if (*(s32 *)(s2 + 48) == 0) {
        D_001A71D7[0] = arg1[128];
    }
}
/* localdecomp:end func_00325CE8 */
