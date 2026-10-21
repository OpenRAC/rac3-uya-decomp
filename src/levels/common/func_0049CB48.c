#include "common.h"

/* localdecomp:start func_0049CB48 */
typedef struct O_0049CB48 O_0049CB48;
typedef struct {
    u8 pad[12];
    void (*fn)(O_0049CB48 *);
} VT_0049CB48;
struct O_0049CB48 {
    u8 pad[4];
    VT_0049CB48 *vt;
};
extern s32 D_001E0D50;
extern s32 D_001E0D40;
extern u8 D_001439F4[];
extern s32 D_001D95C0;
extern void func_00510530(s32);
extern O_0049CB48 *func_00490968(s32);
extern void func_0047B7B8(s32);
void func_0049CB48(void) {
    s32 a = D_001E0D50;
    s32 v;
    O_0049CB48 *o;
    if (a != D_001E0D40) {
        v = 0;
        if (a != 1) {
            if (a >= 2) {
                v = (a == 2) ? 2 : 0;
            }
        } else {
            v = 1;
        }
        D_001439F4[0] = v;
        func_00510530(v);
    }
    o = func_00490968(0);
    o->vt->fn(o);
    func_0047B7B8(D_001D95C0);
}
/* localdecomp:end func_0049CB48 */
