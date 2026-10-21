#include "common.h"

/* localdecomp:start func_00416790 */
typedef struct {
    u8 pad[0x46];
    s16 h46;
    s16 h48;
    u8 pad4A[0xF0 - 0x4A];
} E_416790;
extern E_416790 D_002C5640[];
extern u8 D_001425C0[];
extern s32 func_004166F8(s32);
s32 func_00416790(s32 root, s32 n) {
    s32 cur = root;
    s32 r = 0;
    s32 i;
    if (func_004166F8(cur) >= n) {
        while (((E_416790 *)(cur * 240 + (s32)D_002C5640))->h48 != 0) {
            cur = ((E_416790 *)(cur * 240 + (s32)D_002C5640))->h48;
            root = cur;
        }
        for (i = 0; i < n; i++) {
            cur = ((E_416790 *)(cur * 240 + (s32)D_002C5640))->h46;
        }
        D_001425C0[root] = cur;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_00416790 */
