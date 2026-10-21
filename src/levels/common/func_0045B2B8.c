#include "common.h"

/* localdecomp:start func_0045B2B8 */
extern void func_0045B2B8();

typedef struct N_3C7AE8 { u8 p0[0x20]; s8 f20; u8 p21[0x7]; struct N_3C7AE8 *f28; u8 p2C[0x8]; u16 h34; u8 p36[0x2E]; void (*f64)(struct N_3C7AE8 *); } N_3C7AE8;
extern N_3C7AE8 *func_00438F28();
extern void func_004389D8();
extern void func_00439610();
extern u8 D_001E00AC[];
extern N_3C7AE8 *D_001E00A8;
void func_0045B2B8(void) {
    N_3C7AE8 *n;
    n = D_001E00A8 = func_00438F28(D_001E00AC);
    while (n != 0) {
        if (n->f20 >= 0) {
            if ((n->h34 & 0x40) == 0) {
                func_004389D8(n);
            }
            if (n->f64 != 0 && (n->h34 & 2) == 0) {
                n->f64(n);
            }
            if ((n->h34 & 4) == 0) {
                func_00439610(n);
            }
        }
        n = n->f28;
    }
}
/* localdecomp:end func_0045B2B8 */
