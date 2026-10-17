#include "common.h"

typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

extern int func_005BCBF0(void *, void *, Vec4 *);
extern int func_005BD008(void *, void *, Vec4 *);

int func_005BCB50(void *a, void *b, Vec4 *out) {
    Vec4 tmp;
    int r;
    if (out != 0) {
        r = func_005BCBF0(a, b, &tmp);
        r &= func_005BD008(a, &tmp, &tmp);
        *out = tmp;
        return r;
    }
    if (func_005BCBF0(a, b, 0) != 0) {
        int t = func_005BD008(a, b, 0);
        if (t != 0) {
            return 1;
        }
    }
    return 0;
}
