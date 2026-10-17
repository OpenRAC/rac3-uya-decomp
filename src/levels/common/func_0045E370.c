#include "common.h"

extern void func_0045E370(void);

typedef struct { u8 pad[0x5C0]; } S_39E8E0;
extern S_39E8E0 D_001CD0C0[];
void func_0045DF40(S_39E8E0 *);
void func_0045E370(void) {
    s32 i;
    for (i = 0; i < 8; i++) func_0045DF40(&D_001CD0C0[i]);
}
