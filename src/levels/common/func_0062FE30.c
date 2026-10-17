#include "common.h"
extern void func_0058F790(f32 *, f32 *, u8 *);
f32 func_0062FE30(u8 *a, f32 *b) {
    f32 tmp[4];
    switch (a[6662]) {
    case 0:
        return b[2];
    case 1:
    case 2:
        func_0058F790(tmp, b, a + 96);
        return tmp[2];
    }
    return 0.0f;
}
