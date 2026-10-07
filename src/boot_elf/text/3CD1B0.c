#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003CD1B0();
extern void func_003CD2A8();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003CD1B0 */
typedef struct { u8 p[0x24]; } T36_3C79F0;
typedef struct { s32 k; s32 f4; T36_3C79F0 *f8; } E12_3C79F0;
extern E12_3C79F0 D_00381000[];
extern T36_3C79F0 D_0038100C[];
extern s32 D_001DA500;
extern s32 D_001DA504;
extern s32 D_002DD210[];
extern u8 D_002DD410[];
extern s32 D_002DAB80[];
extern u8 D_002DAF40[];
void func_003CD1B0(s32 key, s32 flag) {
    s32 i = 0;
    while (D_00381000[i].k != -1 && D_00381000[i].k != key) i++;
    if (flag) {
        D_002DD210[D_001DA504] = D_00381000[i].f4;
        D_002DD410[D_001DA504] = D_00381000[i].f8 - D_0038100C;
    } else {
        D_002DAB80[D_001DA500] = D_00381000[i].f4;
        D_002DAF40[D_001DA500] = D_00381000[i].f8 - D_0038100C;
    }
}
/* localdecomp:end func_003CD1B0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003CD298);

/* localdecomp:start func_003CD2A8 */
typedef struct N_3C7AE8 { u8 p0[0x20]; s8 f20; u8 p21[0x7]; struct N_3C7AE8 *f28; u8 p2C[0x8]; u16 h34; u8 p36[0x2E]; void (*f64)(struct N_3C7AE8 *); } N_3C7AE8;
extern N_3C7AE8 *func_003C77A0();
extern void func_003C7250();
extern void func_003C7E88();
extern u8 D_001DA52C[];
extern N_3C7AE8 *D_001DA528;
void func_003CD2A8(void) {
    N_3C7AE8 *n;
    n = D_001DA528 = func_003C77A0(D_001DA52C);
    while (n != 0) {
        if (n->f20 >= 0) {
            if ((n->h34 & 0x40) == 0) {
                func_003C7250(n);
            }
            if (n->f64 != 0 && (n->h34 & 2) == 0) {
                n->f64(n);
            }
            if ((n->h34 & 4) == 0) {
                func_003C7E88(n);
            }
        }
        n = n->f28;
    }
}
/* localdecomp:end func_003CD2A8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003CD350);
