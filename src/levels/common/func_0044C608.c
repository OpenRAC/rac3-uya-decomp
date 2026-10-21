#include "common.h"

/* localdecomp:start func_0044C608 */
typedef struct {
    u8 pad[64];
    s32 x40;
    u8 pad2[4];
    s16 x48;
    u8 x4A;
    u8 pad3;
    u8 x4C;
    u8 pad4[3];
} Entry0044C608;
void func_0044C608(Entry0044C608 *p, s32 a1, s32 a2, s32 a3, s32 t0) {
    if (p->x4A != 0) {
        do {
            if ((p->x4C & 3) == a1 && p->x48 == a2) {
                p->x40 = a3;
                p->x4C |= t0;
                return;
            }
        } while (p++->x4A != 1);
    }
}
/* localdecomp:end func_0044C608 */
