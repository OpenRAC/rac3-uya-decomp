#include "common.h"

/* localdecomp:start func_003C2068 */
typedef struct {
    u8 pad[0x68];
    u8 *x68;
} O_003C2068;
extern s32 D_001A71A0[];
extern s32 D_001E2280[1];
extern s32 D_001E2290[1];
extern s32 D_001DD728;
extern void func_004C49E8(s32);
extern void func_003F3D38(s32);
extern void func_00436220(s32);
void func_003C2068(s32 x) {
    u8 *p;
    s32 i;
    s32 h;
    func_004C49E8(D_001A71A0[0]);
    p = ((O_003C2068 *)x)->x68;
    func_003F3D38(x);
    if (p != 0) {
        h = *(s16 *)(p + 0x15C);
        if (h != -1) D_001E2280[h] = 0;
    }
    for (i = 0; i < 8; i++) {
        if (D_001E2290[i] == x) {
            D_001E2290[i] = 0;
            break;
        }
    }
    D_001DD728 = D_001DD728 - 1;
    if (D_001DD728 < 0) D_001DD728 = 0;
    func_00436220(x);
}
/* localdecomp:end func_003C2068 */
