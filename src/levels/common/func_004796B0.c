#include "common.h"

/* localdecomp:start func_004796B0 */
extern s32 func_0045CA60(s32);
extern s32 func_0045CA60();
extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s32 D_001D545C;
extern u8 D_001D5571;
extern void func_004A56C0(void);
extern void func_0013BFE0(s32);
extern void func_004B5188(void);

extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s32 D_001D545C_gp_003AE120;
extern s32 D_001D545C;
extern u8 D_001D5571;
extern s32 D_001D6674;
extern s32 D_001DFBC4;
extern void func_004A56C0(void);
extern s32 func_0045CA60(s32);
extern void func_0013BFE0(s32);
extern void func_004B5188(void);
void func_004796B0(void) {
    s32 v;
    D_001425AC[0] = 1;
    func_004A56C0();
    func_0045CA60(1);
    func_0013BFE0(D_00143958[0] == 0);
    v = D_001D545C_gp_003AE120;
    if (D_001D545C < 2 && D_001D5571 == 0) {
        func_004B5188();
        return;
    }
    *(volatile s32 *)&D_001D6674 = 1;
    *(volatile s32 *)&D_001DFBC4 = v;
}
/* localdecomp:end func_004796B0 */
