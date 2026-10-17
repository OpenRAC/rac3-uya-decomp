#include "common.h"

extern s32 func_00430278(void);
extern void func_004302C0(s32);
extern s32 D_001D841C;

extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s32 D_001D545C_gp_003B1210;
extern s32 D_001D545C_003B1210;
extern u8 D_001D5571_003B1210;
extern s32 D_001D6674;
extern s32 D_001DFBC4;
extern u8 D_001D5638;
extern s32 D_001F4030[];
extern s32 D_001D841C;
extern s32 D_001D83C0_003B1210;
extern s32 func_00430278();
extern void func_004302C0();
extern void func_004A56C0(void);
extern s32 func_0045CA60(s32);
extern void func_0013BFE0(s32);
extern void func_004B5188(void);
void func_0047D498(void) {
    s32 v;
    if (func_00430278()) {
        func_004302C0(D_001D841C);
        D_001D83C0_003B1210 = 5;
        return;
    }
    D_001425AC[0] = 1;
    func_004A56C0();
    func_0045CA60(1);
    func_0013BFE0(D_00143958[0] == 0);
    v = D_001D545C_gp_003B1210;
    if (D_001D545C_003B1210 < 2 && D_001D5571_003B1210 == 0) {
        func_004B5188();
    } else {
        *(volatile s32 *)&D_001D6674 = 1;
        *(volatile s32 *)&D_001DFBC4 = v;
    }
    D_001D5638 = 1;
    D_001F4030[0] = 0;
}
