#include "common.h"

typedef struct {
    u8 pad0[148];
    u8 unk94;
} P351B10;

typedef struct {
    u8 pad0[816];
    s32 unk330;
    u8 pad334[860 - 820];
    s32 unk35C;
    u8 pad360[896 - 864];
    s32 unk380;
} O351B10;

extern s32 func_003F0638(s32 *);
extern void func_00351950(P351B10 *, O351B10 *, s32);

s32 func_00351B10(P351B10 *p, O351B10 *o) {
    if (o->unk35C != 0) {
        if (func_003F0638(&o->unk330) == 0) {
            return 0;
        }
        if (o->unk380 == 0) {
            func_00351950(p, o, 1);
            o->unk380 = 1;
        } else {
            func_00351950(p, o, 0);
            o->unk380 = 0;
        }
        if (p->unk94 == 24) {
            o->unk330 = 12;
        } else {
            o->unk330 = 20;
        }
        o->unk35C--;
        return 1;
    }
    return 0;
}
