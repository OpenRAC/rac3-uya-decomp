#include "common.h"

typedef struct {
    u8 pad[96];
    s32 f60;
    u8 b64;
    u8 pad2[3];
    s32 f68;
    u8 b6C;
} Obj_00417C28;

extern u32 D_001D6694;
extern void func_00417A30(Obj_00417C28 *, s32 *, s32 *);
extern s32 func_00457288(s32, s32, s32, s32, s32);
extern void func_00417B48(Obj_00417C28 *);

s32 func_00417C28(Obj_00417C28 *obj) {
    s32 buf[2];
    s32 r;

    if (obj->f60 != 0) {
        obj->b64 = 0;
        obj->b6C = 1;
        buf[0] = 0;
        r = 0;
        buf[1] = 0;
        func_00417A30(obj, &buf[0], &buf[1]);
        obj->f68 = (D_001D6694 - 1 <= 1) ? 2 : 1;
        if (buf[1] == 0) {
            r = func_00457288(1, obj->f68, 0, buf[0], 0);
        } else if (buf[1] == 1) {
            r = func_00457288(2, obj->f68, buf[0], 0, 0);
        }
        if (r < 0) {
            func_00417B48(obj);
        }
        return r == 0;
    }
    return 0;
}
