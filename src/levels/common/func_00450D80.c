#include "common.h"

/* localdecomp:start func_00450D80 */
extern f32 func_004408C0(f32, f32);
extern s32 func_00450D80();

typedef struct { u8 key; u8 b1; u8 pad[2]; f32 f4, f8, fC, f10, f14, f18, f1C; } E3C;
typedef struct { u8 pad[0x14]; E3C *e; } P3C;
typedef struct { u8 pad[0xC]; u8 n; u8 pad2[0x3B]; P3C *arr[1]; } S3C;
typedef struct { u8 pad[0x24]; S3C *set; } O3C;
extern s32 func_00440848();
extern f32 func_004408C0(f32, f32);
s32 func_00450D80(O3C *obj, s32 key, s32 *idx, f32 *o1, f32 *o2, f32 *o3, f32 *o4, f32 *o5, f32 *o6, f32 *o7, u8 *o8) {
    E3C *e;
    s32 cnt = 0;
    s32 r;
    s32 i;
    s32 j;
    for (j = 0; j < obj->set->n; j++) {
        if (obj->set->arr[j]->e) {
            if (obj->set->arr[j]->e->key == key) cnt++;
        }
    }
    if (cnt == 0) return 0;
    r = func_00440848(cnt);
    for (i = 0; i < obj->set->n; i++) {
        e = obj->set->arr[i]->e;
        if (e && e->key == key) {
            if (r != 0) {
                r--;
            } else {
                *o1 = e->f8 * 0.016666668f;
                *o2 = e->fC * 0.016666668f;
                *o3 = e->f10 * 0.00027777778f;
                *o4 = e->f14 * 0.00027777778f;
                *o7 = e->f4 * 0.00027777778f;
                *o5 = e->f18;
                *o6 = e->f1C;
                if (e->b1) *o8 = e->b1;
                *o1 = func_004408C0(*o1 * 0.87f, *o1 * 1.13f);
                *o2 = func_004408C0(*o2 * 0.85f, *o2 * 1.15f);
                *o3 = func_004408C0(*o3 * 0.85f, *o3 * 1.15f);
                *o7 = func_004408C0(*o7 * 0.9f, *o7 * 1.1f);
                *idx = i;
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_00450D80 */
