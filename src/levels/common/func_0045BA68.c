#include "common.h"

typedef struct { u8 pad0[0x44]; u32 f44; s16 f48; s16 f4A; s16 f4C; s16 f4E; u8 pad50[4]; s16 f54; u8 pad56[2]; s32 f58; s32 f5C; } S_1CCFD0_0039C7B0;
typedef struct { u8 pad[0x7A04]; s32 base; struct { s32 a; s32 b; } e[1]; } S_160C40_0039C7B0;
extern S_1CCFD0_0039C7B0 D_001CCFD0_0039C7B0;
extern S_160C40_0039C7B0 D_00160C40_0039C7B0;
extern void func_0045CC48(s32, long);
extern void func_0013CB20(long,long,s32,s32,s16,s32,s32,s32,s32,s32,void*,unsigned long);
void func_0045BA68(s32 a0, s32 a1, s32 a2) {
 long y4, y5;
 if (D_001CCFD0_0039C7B0.f44 == 0) {
 if (D_00160C40_0039C7B0.e[a0].a != 0) {
D_001CCFD0_0039C7B0.f44 = 0xFFFFFFFF;
D_001CCFD0_0039C7B0.f4E = 1;
D_001CCFD0_0039C7B0.f48 = a0;
D_001CCFD0_0039C7B0.f4A = a2;
y5 = D_00160C40_0039C7B0.e[a0 + 1].a + D_00160C40_0039C7B0.base;
y4 = D_00160C40_0039C7B0.e[a0].a + D_00160C40_0039C7B0.base;
D_001CCFD0_0039C7B0.f4C = a1;
D_001CCFD0_0039C7B0.f58 = 10;
D_001CCFD0_0039C7B0.f5C = 0xBB80;
D_001CCFD0_0039C7B0.f54 = 0;
func_0013CB20((s32)y4, (s32)y5, 0, 0, (s16)a2, 0, 1, 0, 0, 1, func_0045CC48, (u32)&D_001CCFD0_0039C7B0.f44);
}}}
