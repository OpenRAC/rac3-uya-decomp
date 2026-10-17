#include "common.h"
extern f32 func_003F9600(void *a0, void *a1);
extern void func_003FA240(void *a0, void *a1, f32 a2);
void func_0043BF68(void *a0, void *a1) {
    func_003FA240(a0, a1, func_003F9600(a0, a1) * 0.5f + 0.5f);
}
