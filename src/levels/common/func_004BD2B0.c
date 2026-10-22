#include "common.h"

/* localdecomp:start func_004BD2B0 */
typedef s32 (*Fn_004BD2B0)(u8 *);
typedef struct {
    u8 pad0[4];
    Fn_004BD2B0 *a;
    u8 pad8[4];
    Fn_004BD2B0 *b;
    s32 n;
} T_004BD2B0;

s32 func_004BD2B0(u8 *o, T_004BD2B0 *t) {
    s32 i = 0;
    s32 r = 0;

    while (i < t->n) {
        if (t->a != 0 && t->a[o[0x95]] != 0) {
            while (i < t->n) {
                r = t->a[o[0x95]](o);
                switch (r) {
                case 5:
                    return 0;
                case 4:
                    return 1;
                case 2:
                    i++;
                    continue;
                }
                break;
            }
            if (r == 3) {
                i++;
                continue;
            }
        }
        if (t->b == 0 || t->b[o[0x20]] == 0) {
            return 1;
        }
        while (i < t->n) {
            r = t->b[o[0x20]](o);
            switch (r) {
            case 5:
                return 0;
            case 4:
                return 1;
            case 2:
                i++;
                continue;
            }
            break;
        }
        if (r != 3) {
            break;
        }
        i++;
    }
    return 1;
}
/* localdecomp:end func_004BD2B0 */
