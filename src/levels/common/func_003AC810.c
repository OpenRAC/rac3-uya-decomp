#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3AC810;

extern S_3AC810 *func_00418C28(s32, s32);
extern void func_004169E0(void *);

void func_003AC810(u8 *m, s32 b) {
    if (*(s32 *)(*(u8 **)(m + 0x68) + 0x260) != 0) {
        S_3AC810 *v = func_00418C28(6625, 108);
        v->f0(m);
        if (b) {
            v->f4(m);
        }
    } else {
        func_004169E0(m);
    }
}
