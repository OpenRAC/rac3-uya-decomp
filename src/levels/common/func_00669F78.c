#include "common.h"

typedef struct {
    u8 pad0[52];
    u16 unk34;
} Src669F78;

typedef struct {
    u8 pad0[8];
    s32 unk8;
} Info669F78;

typedef struct {
    u8 pad0[24];
    Src669F78 *unk18;
    u16 unk1C;
    u8 pad1E[2];
    s32 unk20;
    u8 pad24[8];
    u8 unk2C;
} Obj669F78;

extern Obj669F78 *func_0061AB60(s32, s32, s32);
extern Info669F78 *func_005BF058(Src669F78 *);
extern void func_0061B080(Obj669F78 *, Src669F78 *);
extern u32 D_0024C060[];
extern s32 D_0024D858[];

Obj669F78 *func_00669F78(Src669F78 *src, s32 id, s32 b) {
    Obj669F78 *o;

    if ((u32)src >= D_0024C060[0]) {
        return 0;
    }
    {
        s32 t = D_0024D858[0];
        if (~id != 0) {
            t = id;
        }
        o = func_0061AB60(7, t, -1);
    }
    if (o != 0) {
        o->unk18 = src;
        o->unk1C = src->unk34;
        o->unk20 = func_005BF058(src)->unk8;
        func_0061B080(o, src);
        o->unk2C = b;
    }
    return o;
}
