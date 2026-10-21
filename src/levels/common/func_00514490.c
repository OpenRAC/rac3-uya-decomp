#include "common.h"

/* localdecomp:start func_00514490 */
extern s32 func_005139B0(s32, s32);
s32 func_00514490(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i) {
    s32 r;
    s32 t;
    r = func_005139B0(a, b) != 0;
    t = func_005139B0(a, c) != 0;
    r = r & t;
    t = func_005139B0(a, d) != 0;
    r = r & t;
    t = func_005139B0(a, e) != 0;
    r = r & t;
    t = func_005139B0(a, f) != 0;
    r = r & t;
    t = func_005139B0(a, g) != 0;
    r = r & t;
    t = func_005139B0(a, h) != 0;
    r = r & t;
    t = func_005139B0(a, i) != 0;
    return r & t;
}
/* localdecomp:end func_00514490 */
