#include "common.h"

extern s32 func_00457288(s32, s32, s32, s32, u8 *);
extern s32 func_0045CA60(s32);
extern s32 func_0045CA60();

extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s32 D_001D545C_gp_003AE098;
extern s32 D_001D545C;
extern u8 D_001D5571;
extern s32 func_00457288(s32, s32, s32, s32, u8 *);
extern void func_004A56C0(void);
extern void func_0013BFE0(s32);
extern void func_004B5188(void);
void func_00479628(void) {
    D_001425AC[0] = 1;
    func_004A56C0();
    ((s32 (*)(s32))func_0045CA60)(1);
    func_0013BFE0(D_00143958[0] == 0);
    {
    s32 v = D_001D545C_gp_003AE098;
    if (D_001D545C < 2 && D_001D5571 == 0) {
        func_004B5188();
        return;
    }
    func_00457288(6, 2, 5, v, 0);
    }
}
