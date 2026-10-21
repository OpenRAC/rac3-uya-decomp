#include "common.h"

/* localdecomp:start func_0045B378 */
extern void func_0045B378(void);

extern s32 func_0045B360_0039C170();
extern void func_0013BAB8(s32, s32, void *, unsigned long, s32);
typedef struct { u8 p0[0x79A4]; s32 f79A4; u8 p1[0x10]; s32 f79B8; } S_C170a;
typedef struct { u8 p0[0x90]; u32 f90; } S_C170b;
extern S_C170a D_00160C40[];
extern S_C170b D_001A30B0_0039C170[];
void func_0045B378(void) {
    D_001A30B0_0039C170[0].f90 = 0xFFFFFFFF;
    func_0013BAB8(D_00160C40[0].f79B8 + D_00160C40[0].f79A4, 0, &func_0045B360_0039C170, (unsigned long) ((long) &D_001A30B0_0039C170[0].f90 << 0x20) >> 0x20, D_00160C40[0].f79A4);
}
/* localdecomp:end func_0045B378 */
