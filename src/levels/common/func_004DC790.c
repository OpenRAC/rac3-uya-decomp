#include "common.h"
typedef struct { u8 pad[0xB0]; } S_4DC790;
extern S_4DC790 D_002F4580[];
void func_004DC480(S_4DC790 *);
void func_004DC790(void) {
    s32 i;
    for (i = 0; i < 43; i++) func_004DC480(&D_002F4580[i]);
}
