#include "common.h"

extern void func_0013CB20(long,long,s32,s32,s16,s32,s32,s32,s32,s32,void*,unsigned long);

typedef struct { u8 p0[0x44]; u32 f44; s16 f48; s16 f4A; s16 f4C; s16 f4E; u8 p50[4]; s16 f54; u8 p56[2]; s32 f58; s32 f5C; } S_1CCFD0_39C9A0;
typedef struct { u8 p0[0x7A04]; s32 base; struct { s32 a; s32 b; } e[1]; } S_160C40_39C9A0;
extern S_1CCFD0_39C9A0 D_001CCFD0_0039C9A0;
extern S_160C40_39C9A0 D_00160C40_0039C9A0;
extern void func_0045CD08();
extern void func_0013CB20(long,long,s32,s32,s16,s32,s32,s32,s32,s32,void*,unsigned long);
void func_0045BC58(s32 a0, s32 a1, s32 a2) {
    u32 t; long x, y;
    if (D_001CCFD0_0039C9A0.f4E != 9) {
        t = D_001CCFD0_0039C9A0.f44;
        if (t != 0) {
          if (t != 0xFFFFFFFFu) {
            if (D_00160C40_0039C9A0.e[a0 + 1].a != 0) {
                D_001CCFD0_0039C9A0.f48 = a0;
                y = D_00160C40_0039C9A0.e[a0 + 2].a + D_00160C40_0039C9A0.base;
                D_001CCFD0_0039C9A0.f4E = 9;
                x = D_00160C40_0039C9A0.e[a0 + 3].a + D_00160C40_0039C9A0.base;
                D_001CCFD0_0039C9A0.f58 = 10;
                D_001CCFD0_0039C9A0.f5C = 0xBB80;
                D_001CCFD0_0039C9A0.f4A = a2;
                D_001CCFD0_0039C9A0.f4C = a1;
                D_001CCFD0_0039C9A0.f54 = 0;
                func_0013CB20((s32)x, (s32)y, 0, 0, (s16)a2, 0, 1, t, 0, (a1 & 1) << 2, func_0045CD08, (u32)&D_001CCFD0_0039C9A0.f44);
            }
          }
        }
    }
}
