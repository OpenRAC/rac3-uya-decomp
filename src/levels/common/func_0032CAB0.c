#include "common.h"

/* localdecomp:start func_0032CAB0 */
typedef struct { u8 p0[0x68]; u8 *w68; } M_32CAB0;
extern s32 func_0040BA90(u8 *);
extern void func_0032CEB0(M_32CAB0 *);
extern void func_0032C980(M_32CAB0 *);

void func_0032CAB0(M_32CAB0 *m) {
    if (func_0040BA90(m->w68 + 68) == 0) {
        func_0032CEB0(m);
    }
    func_0032C980(m);
}
/* localdecomp:end func_0032CAB0 */
