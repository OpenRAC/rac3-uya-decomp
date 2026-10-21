#include "common.h"

/* localdecomp:start func_004388A8 */
extern int func_004388A8();
extern s32 D_001E009C;

extern int D_001E009C;
extern int D_001E00A4;
int func_004388A8(void) {
    unsigned char *current = (unsigned char *)(*(volatile int *)&D_001E009C);
    unsigned char *end = (unsigned char *)(*(volatile int *)&D_001E00A4);
    int result = (int)end;

    if (current != end) {
        do {
            result = *(int *)(current + 0x24);
            current += 0x100;
        } while (current != end);
    }
    return result;
}
/* localdecomp:end func_004388A8 */
