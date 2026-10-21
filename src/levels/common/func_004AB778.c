#include "common.h"

/* localdecomp:start func_004AB778 */
typedef struct { u8 pad[0x30]; s32 f30; u8 pad2[0x38]; s32 f6C; } S_225780;
typedef struct { s32 v[0x53]; } E_160C40;
typedef struct { u8 pad[0x1284]; s32 f1284; u8 pad2[0xB0]; E_160C40 e[1]; } S_160C40;
extern S_225780 D_001E6E00_003A13B0;
extern S_160C40 D_00160C40;
extern s32 func_0045C8A8(s32, s32, s32);
extern s32 func_0045CA60(s32);
s32 func_004AB778(s32 a) {
    s32 idx = D_001E6E00_003A13B0.f30;
    s32 h = D_001E6E00_003A13B0.f6C;
    s32 lo = D_00160C40.e[idx].v[a];
    s32 d = D_00160C40.e[idx].v[a + 1] - lo;
    if (d > 0) {
        func_0045C8A8(h, lo + D_00160C40.f1284, d);
        func_0045CA60(0);
    }
    return 1;
}
/* localdecomp:end func_004AB778 */
