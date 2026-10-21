#include "common.h"

/* localdecomp:start func_0048DA70 */
typedef struct {
    s32 pad[3];
    s32 val;
} S_48DA70;
extern S_48DA70 D_00143950;
extern void func_004A7368(s32 a0, s32 a1, s32 a2);
void func_0048DA70(s32 buttons) {
    s32 v;
    if (buttons & 0x8000) {
        S_48DA70 *p = &D_00143950;
        v = p->val - 30;
        p->val = (v < 0) ? 0 : v;
    } else if (buttons & 0x2000) {
        S_48DA70 *p = &D_00143950;
        v = p->val + 30;
        p->val = (v > 1024) ? 1024 : v;
    }
    func_004A7368(3, 0, 0);
}
/* localdecomp:end func_0048DA70 */
