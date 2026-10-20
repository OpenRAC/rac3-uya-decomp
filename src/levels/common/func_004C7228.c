#include "common.h"

typedef struct {
    int a[64];
    int b[64];
    int c[8];
    int n220;
    int n224;
    int n228;
} S_4C7228;

extern u8 D_001A4C60[];
extern f32 func_0040C018(void *, void *);

void func_004C7228(S_4C7228 *s) {
    f32 d[64];
    int cnt;
    int i;

    if (s->n224 == 0) {
        return;
    }
    cnt = 0;
    for (i = 0; i < 64; i++) {
        if (s->a[i] != 0) {
            s->b[i] = 0;
            cnt++;
            d[i] = func_0040C018(D_001A4C60, (u8 *)s->a[i] + 16);
        }
        if (cnt == s->n220) {
            break;
        }
    }
    for (i = 0; i < s->n228 && i < s->n220; i++) {
        f32 best = 9999.0f;
        int bi = -1;
        int j;

        for (j = 0; j < 64; j++) {
            if (d[j] < best && s->b[j] == 0 && s->a[j] != 0) {
                best = d[j];
                bi = j;
            }
        }
        s->c[i] = s->a[bi];
        s->b[bi] = 1;
    }
}
