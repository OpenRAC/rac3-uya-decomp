#include "common.h"

typedef struct Ops_45E458 Ops_45E458;
typedef struct {
    s32 pad;
    Ops_45E458 *ops;
} Sub_45E458;
struct Ops_45E458 {
    s32 pad[5];
    void (*fn)(u8 *a0, Sub_45E458 *s);
};

extern s32 func_003F8C48(void *p);
extern void func_0044BCD8(u8 *a0);

void func_0045E458(u8 *a0)
{
    Sub_45E458 *s = (Sub_45E458 *)(a0 + 32);

    if (s != 0) {
        if (func_003F8C48(a0 + 10)) {
            func_0044BCD8(a0);
        } else if (s->ops != 0) {
            s->ops->fn(a0, s);
        }
    }
}
