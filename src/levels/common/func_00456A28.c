#include "common.h"

/* localdecomp:start func_00456A28 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[14];
    s128 rest[14];
} E_00456A28;

extern E_00456A28 D_002C5640[];
extern u8 D_00142CA0[];
extern u8 D_001425C0[];

s32 func_00456A28(void) {
    E_00456A28 e;
    s32 i;

    for (i = 0; i < 156; i++) {
        e = D_002C5640[i];
        if (e.b0 != 0 && e.b1 == 0 && D_00142CA0[i] != 0) {
            e = D_002C5640[D_001425C0[i]];
            if (i == 151) {
                if (e.b1 < 4) {
                    return 0;
                }
            } else if (e.b1 < 7) {
                return 0;
            }
        }
    }
    return 1;
}
/* localdecomp:end func_00456A28 */
