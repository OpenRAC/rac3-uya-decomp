#include "common.h"

/* localdecomp:start func_004B51C0 */
extern u8 D_001A71C4[];
extern s32 D_001DFA08;
extern s32 D_001DFA0C;
extern s32 D_001DFA10;
extern s32 D_001DFA14;
extern s32 D_001DFA38;
extern s32 D_001DFA60;
extern u8 *D_001D52FC;
extern s32 D_001D6690;
extern s32 D_001D6694;
extern s16 D_001DFDAC;
extern s16 D_001DFDAE;
extern s16 D_001DFDB0;
extern s16 D_001DFDB2;
extern s16 D_001DFDB4;
void func_004B51C0(void) {
    D_001DFA08 = 0;
    D_001DFA10 = 0;
    D_001DFA14 = 0;
    D_001DFA0C = 0;
    D_001DFA38 = 0;
    D_001DFA60 = 0;
    if (D_001A71C4[0] == 1) {
        if (!(*(s32 *)(D_001D52FC + 416) & 0x10)) {
            if (D_001D6694 != 4 && D_001D6690 != 4) {
                D_001DFDAC = 0;
                D_001DFDAE = 0;
                D_001DFDB0 = 0;
                D_001DFDB2 = 0;
                D_001DFDB4 = 0;
            }
        }
    }
}
/* localdecomp:end func_004B51C0 */
