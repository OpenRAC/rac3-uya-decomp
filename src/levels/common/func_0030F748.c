#include "common.h"

/* localdecomp:start func_0030F748 */
extern void func_003100F0(u8 *m);
extern void func_003DB440(void (*f)(), u8 *m);
extern s32 func_004181C8(void *t, s32 id, s32 c);
extern s16 D_001A4DDE[];
extern u8 D_001E1300[];
extern s32 D_001F1600[];
extern void func_00310500();

void func_0030F748(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 id = *(s32 *)(v + 0x5C);

    if (id != -1 && func_004181C8(D_001E1300, id, 0) == 0) {
        return;
    }
    D_001A4DDE[0] = 3;
    if (m[0x20] == 0) {
        func_003100F0(m);
    }
    if (D_001F1600[0] != *(s32 *)(v + 0x50)) {
        return;
    }
    if (func_004181C8(D_001E1300, *(s32 *)(v + 0x54), 0) != 0) {
        return;
    }
    if (func_004181C8(D_001E1300, *(s32 *)(v + 0x58), 0) != 0) {
        return;
    }
    func_003DB440(func_00310500, m);
}
/* localdecomp:end func_0030F748 */
