#include "common.h"
extern char D_001A4C60[];
extern char *func_003252E8(void);
extern void func_00453210(void *, s32);
void func_003276D8(void) {
    char *v = func_003252E8();
    func_00453210(D_001A4C60, *(s32 *)(*(char **)(v + 104) + 36));
}
