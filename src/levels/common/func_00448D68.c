#include "common.h"
extern s32 D_001D6D24;
extern void *D_001A6C00[];
extern s32 func_0047EE90(s32 a0);
void *func_00448D68(void) {
    s32 n = func_0047EE90(D_001D6D24);
    s32 i;
    for (i = 0; i < 192; i++) {
        void *e = D_001A6C00[i + 3];
        if (e != 0) {
            if (--n == 0) {
                return e;
            }
        }
    }
    return 0;
}
