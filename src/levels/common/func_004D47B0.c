#include "common.h"

/* localdecomp:start func_004D47B0 */
typedef struct { u8 p0[0x44]; s16 n; u8 p1[0x15A]; void *slot[1]; } S_B7288;
extern S_B7288 D_001E6E00;
extern void func_00436350();
extern void func_00429A70(s32);
extern void func_004D43A8(void);
extern s32 D_0016C5E4[];
extern void func_004D3000(s32);

extern void func_004D3000(s32);
extern void func_00429A70(s32);
extern void func_004D43A8(void);
extern void func_00436350();
void func_004D47B0(s32 a) {
    s32 i;
    func_004D3000(a);
    D_0016C5E4[0] = a;
    func_00429A70(0);
    func_004D43A8();
    for (i = 0; i < D_001E6E00.n; i++) {
        if (D_001E6E00.slot[i] != 0) {
            func_00436350(D_001E6E00.slot[i]);
        }
    }
}
/* localdecomp:end func_004D47B0 */
