#include "common.h"

/* localdecomp:start func_004DB708 */
extern s32 D_001D5600;
extern s32 D_001D5604;

typedef struct { u8 pad[0x150]; s16 h150; s16 h152; } S_1CFEC0;
extern S_1CFEC0 D_001CFEC0;
extern s32 D_001D5604;
extern s32 D_001D5600;
extern void func_004DA100();
extern void func_004DB5C0();
void func_004DB708(void) {
    S_1CFEC0 *p = &D_001CFEC0;
    D_001D5600 = p->h150;
    D_001D5604 = p->h152;
    func_004DA100();
    func_004DB5C0();
}
/* localdecomp:end func_004DB708 */
