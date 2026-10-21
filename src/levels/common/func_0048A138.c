#include "common.h"

/* localdecomp:start func_0048A138 */
extern void func_0048A0F8(void);
extern s32 D_001D8CA8;
extern s32 D_001D8CAC;

void func_0048A138(void) {
    func_0048A0F8();
    if (D_001D8CAC >= D_001D8CA8) {
        D_001D8CAC = D_001D8CA8 - 1;
    }
}
/* localdecomp:end func_0048A138 */
