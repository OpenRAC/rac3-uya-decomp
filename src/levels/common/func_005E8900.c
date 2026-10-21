#include "common.h"

/* localdecomp:start func_005E8900 */
extern s32 func_0060F870(void);
extern u8 *func_006197C0(s32);
extern s32 D_0024C980[4];
extern s32 D_0024C990[4];
extern s32 D_00241278[8];

void func_005E8900(void) {
    s32 id = func_0060F870();
    u8 *p = func_006197C0(id);
    s32 v;
    s32 st;

    st = D_0024C990[id];
    if (st != D_0024C980[id]) {
        v = 0;
        if (st != 1) {
            if (st >= 2) {
                v = (st == 2) ? 2 : 0;
            }
        } else {
            v = 1;
        }
        D_00241278[*(s32 *)(p + 0x2544)] = v;
    }
}
/* localdecomp:end func_005E8900 */
