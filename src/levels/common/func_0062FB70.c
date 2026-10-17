#include "common.h"
extern void func_0058F7B8(float *, void *, void *);
void func_0062FB70(u8 *p, float *v, void *m, float s) {
    switch (p[6662]) {
    case 0:
        v[0] *= s;
        v[1] *= s;
        break;
    case 1:
    case 2:
        func_0058F7B8(v, m, p + 96);
        v[0] *= s;
        v[1] *= s;
        func_0058F7B8(v, v, p + 32);
        break;
    }
}
