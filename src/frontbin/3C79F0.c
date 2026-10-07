#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003C79F0();
extern void func_003C7AE8();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003C79F0 */
typedef struct { u8 p[0x24]; } T36_3C79F0;
typedef struct { s32 k; s32 f4; T36_3C79F0 *f8; } E12_3C79F0;
extern E12_3C79F0 D_0037CF80[];
extern T36_3C79F0 D_0037CF8C[];
extern s32 D_001DA500;
extern s32 D_001DA504;
extern s32 D_002D9210[];
extern u8 D_002D9410[];
extern s32 D_002D6B80[];
extern u8 D_002D6F40[];
void func_003C79F0(s32 key, s32 flag) {
    s32 i = 0;
    while (D_0037CF80[i].k != -1 && D_0037CF80[i].k != key) i++;
    if (flag) {
        D_002D9210[D_001DA504] = D_0037CF80[i].f4;
        D_002D9410[D_001DA504] = D_0037CF80[i].f8 - D_0037CF8C;
    } else {
        D_002D6B80[D_001DA500] = D_0037CF80[i].f4;
        D_002D6F40[D_001DA500] = D_0037CF80[i].f8 - D_0037CF8C;
    }
}
/* localdecomp:end func_003C79F0 */

LINKER_REMNANT("asm/remnants", func_003C7AD8);

/* localdecomp:start func_003C7AE8 */
typedef struct N_3C7AE8 { u8 p0[0x20]; s8 f20; u8 p21[0x7]; struct N_3C7AE8 *f28; u8 p2C[0x8]; u16 h34; u8 p36[0x2E]; void (*f64)(struct N_3C7AE8 *); } N_3C7AE8;
extern N_3C7AE8 *func_003C1FE0();
extern void func_003C1A90();
extern void func_003C26C8();
extern u8 D_001DA52C[];
extern N_3C7AE8 *D_001DA528;
void func_003C7AE8(void) {
    N_3C7AE8 *n;
    n = D_001DA528 = func_003C1FE0(D_001DA52C);
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
