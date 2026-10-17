#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3E4368;

extern S_3E4368 *func_004478A8(s32, s32);
extern void func_00445660(void *);

void func_003E4368(u8 *m, s32 b) {
    if (*(s32 *)(*(u8 **)(m + 0x68) + 0x150) != 0) {
        S_3E4368 *v = func_004478A8(6625, 108);
        v->f0(m);
        if (b) {
            v->f4(m);
        }
    } else {
        func_00445660(m);
    }
}
