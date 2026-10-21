#include "common.h"

/* localdecomp:start func_00510888 */
typedef struct { u8 p0[0x50]; s32 *arr[35]; u8 pad[0x41DC - 0xDC]; } O_3E03D8;
extern O_3E03D8 D_002590C0_003E03D8[];
extern O_3E03D8 D_0026DA0C[];
extern s32 func_005121D8();
void func_00510888(void) {
    O_3E03D8 *s = D_002590C0_003E03D8;
    O_3E03D8 *p;
    s32 **q;
    if (s != 0) {
        p = D_0026DA0C;
        if (p != s) {
            do {
                p--;
                if (p->arr != 0) {
                    q = p->arr + 35;
                    if (p->arr != q) {
                        do {
                            q--;
                            if (*q) func_005121D8(*q);
                            *q = 0;
                        } while (p->arr != q);
                    }
                }
            } while (p != D_002590C0_003E03D8);
        }
    }
}
/* localdecomp:end func_00510888 */
