#include "common.h"

/* localdecomp:start func_003E6F38 */
typedef struct { u8 pad[80]; u8 *obj; u8 pad2[1036]; } E_3E6F38;
extern E_3E6F38 D_001E2AC0[];
void func_003E6F38(s32 i, f32 a, f32 b) {
    u8 *v = (&D_001E2AC0[0] + i)->obj;
    if (*(s16 *)(v + 134) == 0) {
        u8 *p = *(u8 **)(v + 112) + 96;
        if (a != 0.0f) {
            *(f32 *)(p + 252) = a;
        }
        if (b != 0.0f) {
            *(f32 *)(p + 256) = b;
        }
    }
}
/* localdecomp:end func_003E6F38 */
