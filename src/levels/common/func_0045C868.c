#include "common.h"

/* localdecomp:start func_0045C868 */
extern void func_0045C868(void);

typedef struct { u8 pad0[4]; s16 h4; u8 b6; } S_39D4D0;
extern S_39D4D0 D_001CCFD0_0039D4D0[];
extern s32 func_0013CEB0(void);
void func_0045C868(void) {
    if (D_001CCFD0_0039D4D0->h4 != 0) {
        func_0013CEB0();
        D_001CCFD0_0039D4D0->b6 = 1;
    }
}
/* localdecomp:end func_0045C868 */
