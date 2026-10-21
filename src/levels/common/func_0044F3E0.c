#include "common.h"

/* localdecomp:start func_0044F3E0 */
typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d[4];
} S_0044F3E0;
extern S_0044F3E0 D_002D1630[];
extern void func_004336A8(void);
s32 func_0044F3E0(s32 i, s32 v) {
    S_0044F3E0 *p = &D_002D1630[i];
    if (p->a == v) {
        p->c = 0;
        p->a = 0;
        func_004336A8();
        return 1;
    }
    return 0;
}
/* localdecomp:end func_0044F3E0 */
