#include "common.h"

/* localdecomp:start func_003B72B8 */
extern s32 D_001D545C;
extern s32 D_001E6E30[];
extern s32 func_004B6C68(void);
extern void func_003B71D8(void *a0, s32 a1);

void func_003B72B8(void *a0, s32 a1, s32 a2) {
    if (D_001D545C == a1) {
        if (func_004B6C68() != 0) {
            if (D_001E6E30[0] == a2) {
                func_003B71D8(a0, 0);
            }
        } else {
            func_003B71D8(a0, 1);
        }
    }
}
/* localdecomp:end func_003B72B8 */
