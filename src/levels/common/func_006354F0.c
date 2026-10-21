#include "common.h"

/* localdecomp:start func_006354F0 */
typedef int Q_6354F0 __attribute__((mode(TI)));
extern void func_0058EFB8(void *);
extern void func_006355C8(u8 *);

void func_006354F0(u8 *s) {
    s32 k;
    f32 m;

    *(f32 *)(s + 0x3E8) = *(f32 *)(s + 0xFD0);
    *(Q_6354F0 *)(s + 0x3D0) = *(Q_6354F0 *)(s + 0xFC0);
    func_0058EFB8(s + 0x3F8);
    func_0058EFB8(s + 0x3FA);
    k = s[0x3E7];
    m = 1.0f;
    if (k == 0) {
        *(s16 *)(s + 0x3FA) = 3;
        if (*(s16 *)(s + 0x3F8) != 0) {
            m = k / 3;
        }
    } else if (k == 1) {
        *(s16 *)(s + 0x3F8) = 3;
        if (*(s16 *)(s + 0x3FA) != 0) {
            m = (3 - *(s16 *)(s + 0x3FA)) / 3;
        }
    }
    *(f32 *)(s + 0xFB4) *= m;
    func_006355C8(s);
    *(s32 *)(s + 0xFD8) = 0;
    *(s32 *)(s + 0xFD4) = 0;
}
/* localdecomp:end func_006354F0 */
