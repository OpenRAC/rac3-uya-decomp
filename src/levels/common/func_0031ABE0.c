#include "common.h"

/* localdecomp:start func_0031ABE0 */
typedef struct { u8 pad[20]; s32 id; u8 pad2[8]; } E_31ABE0;
extern E_31ABE0 D_00274600[];
s32 func_0031ABE0(s32 a0) {
    s32 r = -1;
    s32 i;
    for (i = 0; i < 30; i++) {
        if (D_00274600[i].id == a0) {
            r = i;
            break;
        }
    }
    return r;
}
/* localdecomp:end func_0031ABE0 */
