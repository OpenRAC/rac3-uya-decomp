#include "common.h"

/* localdecomp:start func_003254A8 */
typedef struct {
    u8 pad[12];
    void (*fn)(u8 *);
} Vt003254A8;
extern Vt003254A8 *func_00438488(s32 a0, s32 a1, s32 a2);
extern u8 *func_00445F18(u8 *a0);
void func_003254A8(s32 a0, u8 *a1) {
    Vt003254A8 *vt;
    u8 *m;
    u8 *n;
    vt = func_00438488(500, 1, 28);
    if (vt != 0) {
        m = *(u8 **)(a1 + 108);
        while (m != 0) {
            n = func_00445F18(m);
            if (m[32] != 7) {
                vt->fn(m);
            }
            m = *(u8 **)(n + 4);
        }
    }
}
/* localdecomp:end func_003254A8 */
