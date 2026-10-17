#include "common.h"
typedef struct {
    s32 id;
    float val;
} Key_00352460;
typedef struct {
    u8 pad[628];
    s32 n;
    u8 pad1[640 - 632];
    Key_00352460 keys[1];
} Track_00352460;
float func_00352460(Track_00352460 *t, s32 id) {
    s32 j;
    s32 n = t->n;
    if (n == 0 || id < t->keys[0].id) return 0.0f;
    for (; id >= 0; id--) {
        for (j = n - 1; j >= 0; j--) {
            if (t->keys[j].id == id) break;
        }
        if (j >= 0) return t->keys[j].val;
    }
    return 0.0f;
}
