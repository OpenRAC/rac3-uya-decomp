#include "common.h"

typedef struct { unsigned long a, b; s32 c, d; } S_3AD0A0;
extern u8 *D_001E1264[];
extern void func_004D1538(u8 *, S_3AD0A0 *);
void func_004D19A8(u8 *p, unsigned long a, unsigned long b, s32 c, s32 d) {
    S_3AD0A0 s;
    s.a = a;
    s.b = b;
    s.c = c - *(s32 *)(p + 0x48);
    s.d = d;
    func_004D1538(D_001E1264[0] + 0x48, &s);
}
