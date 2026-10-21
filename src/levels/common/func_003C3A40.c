#include "common.h"

/* localdecomp:start func_003C3A40 */
typedef struct {
    u8 pad0[0x1C];
    u8 *p;
} E_3C3A40;
extern E_3C3A40 *D_001DE204;
extern s32 *D_0021C780[];
void func_003C3A40(s32 id) {
    u8 *o = D_001DE204[id].p;
    s32 n;
    s32 i;
    s32 *t;
    float *f;
    o[0x44] = 0;
    o[0x38] = 0;
    o[0x39] = 0;
    if (*(s16 *)(o + 0x3A) != 0) {
        *(s32 *)(o + 0x3C) = 0;
    }
    n = *(s32 *)(o + 0x20);
    if (n >= 0) {
        t = D_0021C780[n];
        i = 0;
        if (*t > 0) {
            f = (float *)((u8 *)t + 0x1C);
            do {
                *f = -1.0f;
                i++;
                f += 4;
            } while (i < *t);
        }
    }
    if (*(s32 *)(o + 0x4C) != -1) {
        func_003C3A40(*(s32 *)(o + 0x4C));
    }
}
/* localdecomp:end func_003C3A40 */
