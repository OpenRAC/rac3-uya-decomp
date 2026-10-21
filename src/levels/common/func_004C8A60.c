#include "common.h"

/* localdecomp:start func_004C8A60 */
extern s32 D_001DB160[];
extern void func_004C87A0();

extern s32 D_001DB160[2];
extern void func_004C87A0();
void func_004C8A60(void **p, s32 f) {
    *p = D_001DB160;
    func_004C87A0(p, f);
}
/* localdecomp:end func_004C8A60 */
