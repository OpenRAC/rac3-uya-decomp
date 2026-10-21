#include "common.h"

/* localdecomp:start func_004C9C08 */
typedef struct {
    u8 b0;
    u8 b1;
    u8 pad[238];
} Entry240;

extern u8 D_001425C0[];
extern Entry240 D_002C5640[];
extern s32 D_001DB398[2];
extern s32 func_004166F8(s32);

void func_004C9C08(s32 idx, s32 *p1, s32 *p2, s32 *out) {
    *p1 = 0;
    *p2 = 0;
    *out = D_001DB398[(D_002C5640 + D_001425C0[idx])->b1];
    if (D_002C5640[D_001425C0[idx]].b0 != 0) {
        if (func_004166F8(idx) > 0) {
            *p1 = 0x706EC8FF;
            *p2 = 0x706EC8FF;
        }
    }
}
/* localdecomp:end func_004C9C08 */
