#include "common.h"

/* localdecomp:start func_00479360 */
extern s32 func_00457288(s32, s32, s32, s32, u8 *);
extern s32 D_001D81F4;
extern void func_004799C0(void);

extern s32 D_001D81F4;
extern s8 D_001DFF98[];
void func_00479360(void) {
    s32 temp_3;

    temp_3 = D_001D81F4;
    switch (temp_3) {                               /* irregular */
    case 0:
        func_00430088();
        D_001DFF98[0] = 1;
        /* fallthrough */
    case 1:
        func_00457288(4, 1, 1, 0, 0);
        D_001D81F4 = (s32) (D_001D81F4 + 1);
        return;
    case 2:
        func_004799C0();
        break;
    }
}
/* localdecomp:end func_00479360 */
