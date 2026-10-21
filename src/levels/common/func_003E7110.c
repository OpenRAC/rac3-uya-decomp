#include "common.h"

/* localdecomp:start func_003E7110 */
typedef struct { u8 pad[80]; u8 *obj; u8 pad2[1036]; } E_3E7110;
extern E_3E7110 D_001E2AC0[];
void func_003E7110(s32 i, s32 f) {
    u8 *v = (&D_001E2AC0[0] + i)->obj;
    if (*(s16 *)(v + 134) == 0) {
        u8 *p = *(u8 **)(v + 112) + 480;
        if (f == -1) {
            *(s32 *)(p + 16) |= 3;
        } else {
            *(s32 *)(p + 16) |= f;
        }
    }
}
/* localdecomp:end func_003E7110 */
