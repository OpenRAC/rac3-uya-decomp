#include "common.h"

/* localdecomp:start func_004432C0 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec_004432C0;

s32 func_004432C0(Vec_004432C0 *p, Vec_004432C0 *v, s32 n) {
    s32 i;
    s32 j = 0;
    s32 inside = 0;

    for (i = 0; i < n; i++) {
        j++;
        if (j == n) {
            j = 0;
        }
        if ((v[i].y < p->y && p->y <= v[j].y) || (v[j].y < p->y && p->y <= v[i].y)) {
            if (v[i].x + (p->y - v[i].y) / (v[j].y - v[i].y) * (v[j].x - v[i].x) < p->x) {
                inside = !inside;
            }
        }
    }
    return inside;
}
/* localdecomp:end func_004432C0 */
