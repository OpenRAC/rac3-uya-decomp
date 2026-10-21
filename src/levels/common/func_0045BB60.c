#include "common.h"

/* localdecomp:start func_0045BB60 */
extern void func_0013CB20(long,long,s32,s32,s16,s32,s32,s32,s32,s32,void*,unsigned long);

typedef struct { u8 p0[0x44]; u32 f44; s16 f48; s16 f4A; s16 f4C; s16 f4E; u8 p50[4]; s16 f54; u8 p56[2]; s32 f58; s32 f5C; } S_CFD0_8A8;
typedef struct { u8 p0[0x7A04]; s32 f7A04; s32 t[1]; } S_160_8A8;
extern S_CFD0_8A8 D_001CCFD0_0039C8A8;
extern S_160_8A8 D_00160C40_0039C8A8;
extern void func_0045CD60();
extern void func_0013CB20(long,long,s32,s32,s16,s32,s32,s32,s32,s32,void*,unsigned long);
void func_0045BB60(s32 a, s32 b, s32 c) {
 long x, y; s32 t;
 if (a >= 0) { if (D_001CCFD0_0039C8A8.f44 == 0) { t = D_00160C40_0039C8A8.t[a*2]; if (t != 0) {
D_001CCFD0_0039C8A8.f48 = a;
x = t + D_00160C40_0039C8A8.f7A04;
D_001CCFD0_0039C8A8.f44 = 0xFFFFFFFF;
D_001CCFD0_0039C8A8.f4E = 1;
D_001CCFD0_0039C8A8.f4C = b;
D_001CCFD0_0039C8A8.f58 = 10;
D_001CCFD0_0039C8A8.f4A = c;
D_001CCFD0_0039C8A8.f5C = 0xBB80;
D_001CCFD0_0039C8A8.f54 = 0;
y = D_00160C40_0039C8A8.t[(a+1)*2] + D_00160C40_0039C8A8.f7A04;
func_0013CB20((s32)x, (s32)y, 0, 0, c, 0, 1, 0, 0, 0, func_0045CD60, (unsigned long)((long)&D_001CCFD0_0039C8A8.f44 << 0x20) >> 0x20);
}}}}
/* localdecomp:end func_0045BB60 */
