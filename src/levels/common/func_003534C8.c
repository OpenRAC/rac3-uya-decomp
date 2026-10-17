#include "common.h"

typedef struct {
    u8 pad0[832];
    s32 unk340;
    u8 pad344[856 - 836];
    s32 *unk358;
} O3534C8;

typedef struct {
    s32 unk0;
    O3534C8 *unk4;
    s32 unk8;
    s32 unkC;
} S3534C8;

typedef struct {
    u8 pad0[16];
    s32 unk10;
    f32 unk14;
} T3534C8;

extern void func_00353418(S3534C8 *, s32);

s32 func_003534C8(s32 flags, S3534C8 *s, s32 arg, T3534C8 *a, T3534C8 *b, f32 f) {
    if (flags == 0) {
        func_00353418(s, arg);
        return 0;
    }
    if (s->unk4->unk340 != 0) {
        if ((flags ^ 1) & 1) {
            a->unk10 = s->unkC;
            a->unk14 = f;
        }
        if (!(flags & 2)) {
            b->unk10 = s->unkC;
            b->unk14 = f;
        }
    } else {
        if ((flags ^ 1) & 1) {
            a->unk10 = 0;
            a->unk14 = 0.0f;
        }
        if (!(flags & 2)) {
            b->unk10 = s->unk4->unk358[0] - 1;
            b->unk14 = 0.0f;
        }
    }
    return 1;
}
