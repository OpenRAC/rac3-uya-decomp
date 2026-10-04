#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_003C0E08);

INCLUDE_ASM("asm/nonmatchings/text", func_003C0E10);

LINKER_REMNANT("asm/remnants", func_003C1070);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1130);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1440);

LINKER_REMNANT("asm/remnants", func_003C18F8);

/* localdecomp:start func_003C1950 */
typedef struct { u16 id; u16 t; } E_C1950;
typedef struct { u8 p0[0x10]; u8 k; u8 p11; u8 n; u8 p13[9]; E_C1950 e[1]; } Y_C1950;
typedef struct { u8 p0[0xC]; u8 cnt; u8 pD[0x3B]; Y_C1950 *y[1]; } X_C1950;
typedef struct { u8 p0[0x24]; X_C1950 *x; } O_C1950;
void func_003C1950(O_C1950 *o, s32 idx, u16 t) {
    X_C1950 *x = o->x;
    Y_C1950 *y;
    E_C1950 *e;
    s32 i;
    if (x != 0 && idx < x->cnt) {
        y = x->y[idx];
        if (y->n != 0) {
            e = (E_C1950 *)((u8 *)y + (y->k * 4 + 0x1C));
            for (i = 0; i < y->n && (t << 4) >= e[i].t; i++) {
                func_0039FE80(e[i].id, 0, o);
            }
        }
    }
}
/* localdecomp:end func_003C1950 */

LINKER_REMNANT("asm/remnants", func_003C1A28);

/* localdecomp:start func_003C1A40 */
unsigned long func_003C1A40(u8 *p, unsigned long a, unsigned long b, unsigned long c, unsigned long d) {
    register unsigned long shifted __asm__("$5") = a << 32;
    __asm__ volatile("" : "+r"(shifted));
    c <<= 8;
    d <<= 16;
    __asm__ volatile("" : "+r"(d));
    return *(unsigned long *)(p + 0x38) = shifted | b | c | d;
}
/* localdecomp:end func_003C1A40 */
