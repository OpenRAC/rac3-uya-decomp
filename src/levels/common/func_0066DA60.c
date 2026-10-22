#include "common.h"

/* localdecomp:start func_0066DA60 */
typedef struct { u8 b[0x30]; } S_66DA60;

extern s32 D_0024D0A0;
extern s32 D_0024D080[8];
extern S_66DA60 D_00352C58[];
extern char *func_00599618(s32);
extern int func_00120048(char *, char *, ...);

void func_0066DA60(s32 arg) {
    func_00120048(D_00352C58[D_0024D0A0].b, func_00599618(0x1877), arg);
    D_0024D080[D_0024D0A0] = 0x708;
    D_0024D0A0++;
}
/* localdecomp:end func_0066DA60 */
