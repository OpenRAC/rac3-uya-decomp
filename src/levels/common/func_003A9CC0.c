#include "common.h"

/* localdecomp:start func_003A9CC0 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

void func_003A9CC0(u8 *obj, Vec4 a, Vec4 b) {
    *(Vec4 *)(obj + 128) = a;
    *(Vec4 *)(obj + 144) = b;
}
/* localdecomp:end func_003A9CC0 */
