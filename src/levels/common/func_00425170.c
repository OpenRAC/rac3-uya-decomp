#include "common.h"

typedef struct {
    f32 x;
    f32 y;
} P_00425170;

void func_00425170(s32 *a0, s32 n, s32 *a2) {
    P_00425170 arr[512];
    s32 cnt;
    s32 m;
    s32 i;
    s32 k;
    s32 l;
    s32 j;
    s32 sorted;
    f32 tx;
    f32 ty;

    cnt = 0;
    for (i = 0; i < n; i++) {
        if (a0[0] != 0) {
            arr[cnt].x = a0[1];
            arr[cnt].y = a0[0];
            cnt++;
        }
        a0 += 8;
    }
    for (l = 0; l < cnt - 1; l++) {
        arr[l].y = (arr[l + 1].y - arr[l].y) * 0.0009765625f;
    }
    m = cnt - 1;
    arr[m].y = (*a2 - arr[m].y) * 0.0009765625f;
    do {
        sorted = 1;
        for (j = 0; j < cnt - 1; j++) {
            if (arr[j].y < arr[j + 1].y) {
                tx = arr[j].x;
                ty = arr[j].y;
                arr[j].x = arr[j + 1].x;
                arr[j].y = arr[j + 1].y;
                arr[j + 1].x = tx;
                arr[j + 1].y = ty;
                sorted = 0;
            }
        }
    } while (sorted == 0);
    for (k = 0; k < cnt; k++) {
    }
}
