#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/nonmatchings/text", func_003C79F0);

LINKER_REMNANT("asm/remnants", func_003C7AD8);

/* localdecomp:start func_003C7AE8 */
typedef struct N_3C7AE8 { u8 p0[0x20]; s8 f20; u8 p21[0x7]; struct N_3C7AE8 *f28; u8 p2C[0x8]; u16 h34; u8 p36[0x2E]; void (*f64)(struct N_3C7AE8 *); } N_3C7AE8;
extern N_3C7AE8 *func_003C1FE0();
extern void func_003C1A90();
extern void func_003C26C8();
extern u8 D_001DA52C[];
extern N_3C7AE8 *D_001DA528_003C7AE8;
void func_003C7AE8(void) {
    N_3C7AE8 *n;
    n = D_001DA528_003C7AE8 = func_003C1FE0(D_001DA52C);
    while (n != 0) {
        if (n->f20 >= 0) {
            if ((n->h34 & 0x40) == 0) {
                func_003C1A90(n);
            }
            if (n->f64 != 0 && (n->h34 & 2) == 0) {
                n->f64(n);
            }
            if ((n->h34 & 4) == 0) {
                func_003C26C8(n);
            }
        }
        n = n->f28;
    }
}
/* localdecomp:end func_003C7AE8 */

LINKER_REMNANT("asm/remnants", func_003C7B90);
