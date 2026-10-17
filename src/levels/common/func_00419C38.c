#include "common.h"

typedef struct { u8 p0[0x14]; s32 a[8]; s32 b[16]; s32 c[1]; } S_0038E798;
typedef struct { u32 w; u32 x; } E_0038E798;
extern S_0038E798 *D_001DFD98_0038E798[];
extern E_0038E798 *D_001DFDA4_0038E798[];
extern E_0038E798 *D_001DFDA8_0038E798[];
void func_00419C38(s32 n, s32 size) {
    s32 i;
    s32 j;
    s32 end;
    if (D_001DFD98_0038E798[0]->c[n] == 0) {
        size = (size + 0xF) & 0xFFFFFFF0;
        D_001DFD98_0038E798[0]->c[n] = size;
        i = (n != 0) ? D_001DFD98_0038E798[0]->a[n - 1] : 0;
        end = D_001DFD98_0038E798[0]->a[n];
        for (j = i; j < end; j++) {
            D_001DFDA8_0038E798[0][j].w &= 0x7FFFFFFF;
            D_001DFDA8_0038E798[0][j].w += size;
        }
        i = (n != 0) ? D_001DFD98_0038E798[0]->b[n - 1] : 0;
        end = D_001DFD98_0038E798[0]->b[n];
        for (j = i; j < end; j++) {
            D_001DFDA4_0038E798[0][j].w &= 0x7FFFFFFF;
            D_001DFDA4_0038E798[0][j].w += size;
        }
    }
}
