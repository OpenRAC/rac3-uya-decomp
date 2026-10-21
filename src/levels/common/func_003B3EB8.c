#include "common.h"

/* localdecomp:start func_003B3EB8 */
typedef struct {
    u8 pad0[4];
    s32 i4;
    s32 i8;
    f32 f12;
    s32 i16;
    f32 f20;
    u8 pad24[48 - 24];
    s32 i48;
    u8 pad52[84 - 52];
    s32 i84;
    s32 i88;
    u8 pad92[120 - 92];
    s32 i120;
    u8 pad124[176 - 124];
    s32 i176;
    s32 i180;
    s32 i184;
    s32 i188;
    u8 pad192[200 - 192];
    s32 i200;
    s32 i204;
    s32 ids[4];
    s32 ids2[4];
    u8 pad240[256 - 240];
    s32 cnt[4];
} S_3B3EB8;
extern s16 *D_0021DEA0[];
extern u8 *D_001E009C;
extern s32 D_001E00D8;
extern void func_00441FB8(void *, s32, s32);

#define VALID_3B3EB8(id, p) (((id) & 0xFF) != 0xFF && (id) <= D_001E00D8 && (p) != 0 && ((p)[-1] >= 0 || (p) == D_0021DEA0[id]))
#define GET_3B3EB8(p) (D_001E009C + ((*(p) & 0x7FFF) << 8))

void func_003B3EB8(u8 *a, S_3B3EB8 *o) {
    s16 *p;
    u8 *e;
    s32 n;
    s32 total;
    s32 i;

    a[48] = 255;
    o->i188 = o->i16;
    if (o->i48 < 0) {
        o->i188 = -1;
    } else {
        o->i188 += o->i48;
    }
    n = 0;
    if (o->i4 != -1) {
        for (p = D_0021DEA0[o->i4]; VALID_3B3EB8(o->i4, p); p++) {
            e = GET_3B3EB8(p);
            if (e == 0) {
                break;
            }
            n++;
        }
    }
    o->i176 = n;
    if (o->i8 != -1) {
        n++;
    }
    o->i180 = n;
    total = 0;
    o->i200 = 0;
    o->i204 = 0;
    for (i = 0; i < 4; i++) {
        o->cnt[i] = 0;
        if (o->ids[i] != -1) {
            for (p = D_0021DEA0[o->ids[i]]; VALID_3B3EB8(o->ids[i], p); p++) {
                e = GET_3B3EB8(p);
            if (e == 0) {
                    break;
                }
                o->cnt[i]++;
            }
            total += o->cnt[i];
            if (o->i200 < i) {
                o->ids[o->i200] = o->ids[i];
                o->ids[i] = -1;
                o->cnt[o->i200] = o->cnt[i];
                o->cnt[i] = 0;
            }
            o->i200++;
        }
        if (o->ids2[i] != -1) {
            total++;
            if (o->i204 < i) {
                o->ids2[o->i204] = o->ids2[i];
                o->ids2[i] = -1;
            }
            o->i204++;
        }
    }
    o->i184 = total;
    if (o->f12 < 0.0f) {
        if (total == 0) {
            o->f12 = 1.0f;
        } else {
            o->f12 = (f32)n / (f32)(n + total);
            if (o->f12 > 1.0f) {
                o->f12 = 1.0f;
            } else if (o->f12 < 0.0f) {
                o->f12 = 0.0f;
            }
        }
    } else if (o->f12 > 1.0f) {
        o->f12 = 1.0f;
    }
    if (o->f20 < 0.0f) {
        if (total == 0) {
            o->f20 = 1.0f;
        } else {
            o->f20 = (f32)n / (f32)(n + total);
            if (o->f20 > 1.0f) {
                o->f20 = 1.0f;
            } else if (o->f20 < 0.0f) {
                o->f20 = 0.0f;
            }
        }
    } else if (o->f20 > 1.0f) {
        o->f20 = 1.0f;
    }
    o->i84 = 0;
    o->i88 = 0;
    o->i120 = 0;
    func_00441FB8(a, 1, -1);
}
/* localdecomp:end func_003B3EB8 */
