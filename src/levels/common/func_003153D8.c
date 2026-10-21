#include "common.h"

/* localdecomp:start func_003153D8 */
typedef struct {
    u8 *obj;
    s32 col;
    s32 pad8;
    f32 t;
    u8 pad10[16];
} Ent_003153D8;

extern Ent_003153D8 D_00271BC0[];
extern u8 **func_00445E80(u8 *);
extern s32 func_0040D020(s32, s32, f32);
extern void func_00438908(u8 *, s32, s32, s32);

void func_003153D8(s32 i, s32 a1) {
    s32 a;
    u8 **v;
    s32 c;
    s32 g;
    s32 b;

    a = (s32)(D_00271BC0[i].t * 96.0f);
    D_00271BC0[i].obj[35] = a;
    v = func_00445E80(D_00271BC0[i].obj);
    if (v != 0 && *v != 0) {
        (*v)[35] = a;
    }
    c = func_0040D020(a1, D_00271BC0[i].col, D_00271BC0[i].t);
    b = (c >> 16) & 0xFF;
    g = (c >> 8) & 0xFF;
    func_00438908(D_00271BC0[i].obj, c & 0xFF, g, b);
}
/* localdecomp:end func_003153D8 */
