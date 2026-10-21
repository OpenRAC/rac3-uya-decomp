#include "common.h"

/* localdecomp:start func_005B2A90 */
extern u8 *D_0024C204[7];

void func_005B2A90(u8 *o) {
    s32 i;

    if (*(s16 *)(o + 0xB2) >= 0 && !(o[0xB1] & 0x80)) {
        o[0x7F]++;
        for (i = 1; i >= 0; i--) { if (o == D_0024C204[i - 1]) break; }
    }
}
/* localdecomp:end func_005B2A90 */
