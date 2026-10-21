#include "common.h"

/* localdecomp:start func_004027B8 */
extern s32 D_001DFA38;
extern void (*D_001DFA18)(s32);
extern s32 D_001DFA28;
void func_004027B8(void) {
    s32 i;
    for (i = 0; i < D_001DFA38; i++) {
        (&D_001DFA18)[i]((&D_001DFA28)[i]);
    }
}
/* localdecomp:end func_004027B8 */
