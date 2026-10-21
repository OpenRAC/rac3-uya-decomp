#include "common.h"

/* localdecomp:start func_0049A188 */
extern s32 D_001D94F0;
extern s32 D_001D94FC;
extern s32 D_001D9500;
extern s32 D_001D9504;
extern void func_0049A9C8(void);
extern void func_0049AB20(void);
extern s32 func_0049ABA8(void);
extern s32 func_0049AC50(void);
extern void func_0049ACF8(void);

void func_0049A188(void) {
    s32 t;

    switch (D_001D94F0) {
    case 0:
        func_0049A9C8();
        func_0049AB20();
        break;
    case 1:
        if (func_0049ABA8() == 0) {
            t = D_001D9500;
            D_001D9500 = D_001D94FC;
            D_001D94FC = D_001D9504;
            D_001D9504 = t;
            D_001D94F0 = 0;
            func_0049ACF8();
        }
        break;
    case 2:
        if (func_0049AC50() == 0) {
            t = D_001D9504;
            D_001D9504 = D_001D94FC;
            D_001D94FC = D_001D9500;
            D_001D9500 = t;
            D_001D94F0 = 0;
            func_0049ACF8();
        }
        break;
    }
}
/* localdecomp:end func_0049A188 */
