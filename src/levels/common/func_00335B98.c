#include "common.h"

/* localdecomp:start func_00335B98 */
typedef struct {
    u8 pad[148];
    u8 *(*fn)(u8 *);
} Vt00335B98;
extern Vt00335B98 *func_00438488(s32 a0, s32 a1, s32 a2);
extern void func_004A6DF8(u8 *a0, s32 a1);
extern void func_00436220(u8 *a0);
void func_00335B98(u8 *a0) {
    u8 *s0 = *(u8 **)(*(u8 **)(a0 + 184) + 104);
    u8 *r;
    r = func_00438488(*(s32 *)(s0 + 64), 4, 156)->fn(a0);
    *(s32 *)(r + 1136) = 0;
    *(s32 *)(s0 + 80) = -1;
    *(s32 *)(a0 + 152) = 0;
    *(u16 *)(a0 + 52) = (*(u16 *)(a0 + 52) | 0x43) & 0xEFFF;
    func_004A6DF8(a0, 1);
    if (*(s32 *)(s0 + 72) == -1) {
        func_00436220(a0);
    }
}
/* localdecomp:end func_00335B98 */
