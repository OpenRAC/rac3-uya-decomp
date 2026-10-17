#include "common.h"

typedef struct {
    char pad0[452];
    int a;
    int b;
} Pad006396F8;

typedef struct {
    char pad0[996];
    unsigned short count;
    char pad3E6[9524 - 998];
    Pad006396F8 *pad;
} Obj006396F8;

extern int func_00637548(Obj006396F8 *);
extern void func_0058EFB8(unsigned short *);

void func_006396F8(Obj006396F8 *o)
{
    if (func_00637548(o)) {
        func_0058EFB8(&o->count);
        return;
    }
    if (o->pad->a & 3) {
        if (o->pad->a & 2)
            o->count++;
        if (o->pad->a & 1)
            o->count++;
    }
    if (o->pad->b & 3) {
        if (o->pad->b & 2)
            func_0058EFB8(&o->count);
        if (o->pad->b & 1)
            func_0058EFB8(&o->count);
    }
}
