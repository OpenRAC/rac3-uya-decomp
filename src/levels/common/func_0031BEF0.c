#include "common.h"

typedef struct {
    u8 pad[104];
    s32 f68;
} Moby_0031BEF0;

extern s32 func_0040BA90(s32);
extern void func_00436220(Moby_0031BEF0 *);
extern void func_004026A0(void *, Moby_0031BEF0 *);
extern void func_0031BF40();

void func_0031BEF0(Moby_0031BEF0 *m) {
    if (func_0040BA90(m->f68)) {
        func_00436220(m);
    } else {
        func_004026A0(func_0031BF40, m);
    }
}
