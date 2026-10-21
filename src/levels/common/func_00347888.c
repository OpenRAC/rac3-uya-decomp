#include "common.h"

/* localdecomp:start func_00347888 */
typedef struct { u8 pad[0x1A]; s16 x1A; } V_347888;
typedef struct { u8 pad[0x68]; V_347888 *x68; } O_347888;
extern s32 func_00454168(s32, s32);
extern void func_00436220(O_347888 *);
extern void func_00347CA8(O_347888 *);
extern void func_003484A0(O_347888 *);
extern void func_00348C48(O_347888 *);
void func_00347888(O_347888 *o) {
    if (func_00454168(3076, o->x68->x1A) == 0) {
        func_00436220(o);
    } else {
        func_00347CA8(o);
        func_003484A0(o);
        func_00348C48(o);
    }
}
/* localdecomp:end func_00347888 */
