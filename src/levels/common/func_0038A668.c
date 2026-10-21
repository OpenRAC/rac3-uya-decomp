#include "common.h"

/* localdecomp:start func_0038A668 */
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    s128 v0;
    s128 v10;
    s32 f20;
    s32 f24;
    f32 f28;
    s32 f2C;
    s32 f30;
    f32 f34;
    s32 f38;
    s32 f3C;
} Sub_0038A668;
typedef struct {
    u8 pad0[0x10];
    s128 v10;
    u8 b20;
    u8 pad21[0xF];
    u8 b30;
    u8 pad31;
    s16 h32;
    u8 pad34[0x34];
    Sub_0038A668 *sub;
} Obj_0038A668;
extern Obj_0038A668 *func_00435E70(s32, s32);
extern f32 func_00440978(void);
extern s32 D_001DDF74;
extern s32 D_001DDF78;
extern f32 D_001DDF70;
extern f32 D_001DDF88;
extern f32 D_001DDF84;
extern s32 D_001DDF8C[1];
extern s32 D_001E1F9C[];
extern f32 D_001E1FA0;
extern f32 D_001E1FA4;
extern f32 D_001E1FA8;
extern f32 D_001E1FAC;
extern f32 D_001E1FB0;
extern f32 D_001E1FB4;
extern f32 D_001E1FB8;
extern f32 D_001E1FBC;
extern f32 D_001E1FC0;
extern f32 D_001E1FC4;
extern f32 D_001E1FC8;
extern f32 D_001E1FCC[];
Obj_0038A668 *func_0038A668(s128 *a, s128 *b, s128 *c) {
    Obj_0038A668 *o;
    Sub_0038A668 *s;
    o = func_00435E70(0x1888, 0x80);
    if (o != 0) {
        o->v10 = *a;
        s = o->sub;
        o->b30 = 0xFF;
        o->h32 = 0xFF;
        o->b20 = 0;
        s->f24 = 0x69;
        s->f28 = 2.0f;
        s->f2C = 0x1E;
        s->f20 = 0;
        D_001DDF74 = 0;
        D_001DDF78 = 0;
        s->f30 = 0x50;
        s->f34 = 1.0f;
        D_001DDF70 = 1.0f;
        s->v10 = *b;
        s->f3C = 0x14;
        D_001DDF84 = 1.0f;
        D_001DDF88 = 1.0f;
        s->v0 = *c;
        D_001E1F9C[0] = D_001DDF8C[0];
        s->f38 = -1;
        D_001E1FA0 = func_00440978();
        D_001E1FA4 = func_00440978();
        D_001E1FA8 = func_00440978();
        D_001E1FAC = func_00440978();
        D_001E1FB0 = func_00440978();
        D_001E1FB4 = func_00440978();
        D_001E1FB8 = func_00440978();
        D_001E1FBC = func_00440978();
        D_001E1FC0 = func_00440978();
        D_001E1FC4 = func_00440978();
        D_001E1FC8 = func_00440978();
        D_001E1FCC[0] = func_00440978();
    }
    return o;
}
/* localdecomp:end func_0038A668 */
