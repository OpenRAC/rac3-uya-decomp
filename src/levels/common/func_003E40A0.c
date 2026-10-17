#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3E40A0;

extern S_3E40A0 *func_004395A8(s32, s32);
extern void func_00437360(void *);

void func_003E40A0(u8 *m, s32 b) {
    if (*(s32 *)(*(u8 **)(m + 0x68) + 0x30) != 0) {
        S_3E40A0 *v = func_004395A8(6625, 108);
        v->f0(m);
        if (b) {
            v->f4(m);
        }
    } else {
        func_00437360(m);
    }
}
