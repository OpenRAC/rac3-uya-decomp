#include "common.h"

extern s32 func_00430278(void);
extern void func_004302C0(s32);
extern void func_0047A288(void);
extern void func_0047A2A8(s32);
extern void func_004A56C0(void);
extern s32 func_0045CA60(s32);
extern void func_0013BFE0(s32);
extern s32 D_001D841C;
extern s32 D_001D83C0;
extern u8 D_001D8439;
extern s32 D_001D545C;
extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s8 D_001D5638[16] __attribute__((section(".sdata")));
extern s32 D_001F4030[];

void func_0047D550(void) {
    if (func_00430278() != 0) {
        func_004302C0(D_001D841C);
        D_001D83C0 = 5;
        return;
    }
    D_001425AC[0] = 1;
    func_004A56C0();
    func_0045CA60(1);
    func_0013BFE0(D_00143958[0] == 0);
    if (D_001D8439 != 0) {
        func_0047A288();
    } else {
        func_0047A2A8(D_001D545C);
    }
    D_001D83C0 = 6;
    D_001D5638[0] = 1;
    D_001F4030[0] = 0;
}
