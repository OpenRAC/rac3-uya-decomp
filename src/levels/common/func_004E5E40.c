#include "common.h"

/* localdecomp:start func_004E5E40 */
typedef struct Obj {
    u8 pad0[5];
    u8 flags;
    u8 pad1[2];
    u8 pos[0x20];
    s32 f28;
    u8 pad2[8];
    s32 f34;
} Obj;
typedef struct Ent {
    Obj *obj;
    s32 f4;
    f32 f8;
    f32 fC;
} Ent;
extern u8 D_001A4BE0[];
extern f32 func_004450C0(void *, f32, f32);
extern void func_00436C90(s32, Ent *);
extern void func_00436D30(s32, Obj *);
extern f32 func_004365E0(Obj *);
void func_004E5E40(Ent *a0, s32 n) {
    Ent *e;
    s32 i;
    u8 *g;
    Obj *o;
    i = 0;
    if (n > i) {
        g = D_001A4BE0;
        e = a0;
        do {
            o = e->obj;
            if (o != 0) {
                if (o->f34 != 0) {
                    if (func_004450C0(o->pos, 0.0f, 0.1f) == 0.0f) {
                        func_00436C90(*(s32 *)(g + 0x25C0), e);
                    }
                }
            }
            if (e->obj != 0) {
                if (o->f34 == 0) {
                    func_004450C0(o->pos, e->f8, 0.25f);
                }
                func_00436D30(*(s32 *)(g + 0x25C0), o);
                e->fC = func_004365E0(o);
                if (e->f4 == 0) {
                    if (o->flags & 2) {
                        o->f34 = 1;
                        o->f28 = 0;
                    }
                }
            }
            i++;
            e++;
        } while (i < n);
    }
}
/* localdecomp:end func_004E5E40 */
