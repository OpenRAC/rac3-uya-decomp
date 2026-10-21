#include "common.h"

/* localdecomp:start func_0047D330 */
typedef struct { u8 b[8]; } B8_3B10A8;
typedef struct { s32 f0, f4, f8, fC; B8_3B10A8 f10; s32 f18; } E_3B10A8;
typedef struct { u8 p0[0x30]; E_3B10A8 e[11]; u8 p1[0x17C - 0x30 - 11 * 0x1C]; s32 f17C; } S_3B10A8;
typedef struct { s32 f0; u8 p[0x2E]; u8 f32; } T_3B10A8;
extern S_3B10A8 D_00142430_003B10A8;
extern T_3B10A8 D_00142660_003B10A8;
extern B8_3B10A8 D_001D4BE0;
extern s32 D_001D545C;
extern s32 D_001D5528;
extern s32 D_001D841C;
extern s32 D_001D8434;
extern u8 D_001D8438;
extern void func_00430120(s32, s32);
void func_0047D330(void) {
    s32 h = D_001D841C;
    s32 i;
    if (h != 0) {
        i = D_001D8434;
        D_00142430_003B10A8.f17C = 1;
        D_00142430_003B10A8.e[i].f4 = D_00142660_003B10A8.f0;
        D_00142430_003B10A8.e[i].f0 = D_001D545C;
        D_00142430_003B10A8.e[i].fC = D_001D5528;
        { B8_3B10A8 *q = &D_00142430_003B10A8.e[i].f10; *q = D_001D4BE0; }
        D_00142430_003B10A8.e[i].f8 = D_00142660_003B10A8.f32;
        func_00430120(h, -1);
        D_001D8438 = 1;
    }
}
/* localdecomp:end func_0047D330 */
