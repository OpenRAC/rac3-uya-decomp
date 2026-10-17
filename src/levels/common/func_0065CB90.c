#include "common.h"

typedef struct {
    u8 pad0[20];
    void *fn;
    u8 pad1[6652];
    u8 flag;
    u8 pad2[10970];
    u8 state;
} S_0065CB90;

extern void func_0058F0A0(S_0065CB90 *p, int v, int n);
extern void func_0065FC38(S_0065CB90 *p);
extern void func_0047B3A0(void);

void func_0065CB90(S_0065CB90 *a0)
{
    func_0058F0A0(a0, 0, 17664);
    func_0065FC38(a0);
    a0->fn = func_0047B3A0;
    a0->flag = 1;
    a0->state = 5;
}
