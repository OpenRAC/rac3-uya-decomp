#include "common.h"
extern f32 D_001DC128;
extern f32 D_001DC12C;
extern void func_00512328(void);
void func_00512448(f32 a, f32 b) {
    D_001DC128 = a;
    D_001DC12C = b;
    func_00512328();
}
