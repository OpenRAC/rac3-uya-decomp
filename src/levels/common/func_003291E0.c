#include "common.h"

/* localdecomp:start func_003291E0 */
typedef struct {
    u8 pad[24];
    s32 (*f24)(u8 *);
    s32 (*f28)(u8 *);
} Vt003291E0;
extern Vt003291E0 *func_00438488(s32 a0, s32 a1, s32 a2);
extern u8 *D_001D52FC[];
extern u8 *D_001E009C[];
extern s32 D_001D545C;
s32 func_003291E0(s32 a0, u8 *a1) {
    Vt003291E0 *vt;
    u8 *e;
    s32 lvl;
    if (*(s32 *)(a1 + 20) != -1) {
        vt = func_00438488(6877, 0, 104);
        e = D_001E009C[0] + *(s32 *)(a1 + 20) * 256;
        if (*(s32 *)(D_001D52FC[0] + 452) & 0x10) {
            if (vt->f24(e) || vt->f28(e)) {
                lvl = D_001D545C;
                if (lvl != 12 && lvl != 18 && lvl != 20 && lvl != 26 && lvl != 29) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_003291E0 */
