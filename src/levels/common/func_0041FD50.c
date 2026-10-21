#include "common.h"

/* localdecomp:start func_0041FD50 */
extern s32 D_001D6A40;
extern s32 D_001D6A44;
extern s32 D_001DFD78;
extern u8 *D_001D52FC;
extern s32 func_0041FD10(void);
extern void func_0041FD18(void);
extern void func_0041FD20(void);

void func_0041FD50(void) {
    switch (D_001D6A40) {
    case 0:
        break;
    case 1:
        D_001D6A40 = 2;
        D_001DFD78 = D_001D6A44;
        break;
    case 2:
        D_001DFD78--;
        if (func_0041FD10() != 0) {
            func_0041FD18();
            func_0041FD20();
        } else if (D_001DFD78 == 0) {
            if (*(s32 *)(D_001D52FC + 416) & 0x10) {
                D_001D6A40++;
            } else {
                D_001D6A40 = 0;
            }
        } else if (!(*(s32 *)(D_001D52FC + 416) & 0x10)) {
            D_001D6A40 = 0;
        }
        break;
    }
}
/* localdecomp:end func_0041FD50 */
