#include "common.h"

/* localdecomp:start func_00496068 */
extern s32 func_004950C8(void *, s32, s32);
extern void func_00496068(void *);
typedef struct { u8 p0[0x40]; s32 f40; } Q_3B5708;
extern Q_3B5708 *func_004950A8();
extern s32 func_004950C8();

typedef struct { u8 p0[4]; s32 f4; u8 p8[4]; s32 fC; s32 f10; s32 f14; } O_3B57F8;
extern s32 func_00512AB0();
extern s32 func_00512FE8();
extern void func_00495AE8(s32 *);
void func_00496068(void *op) {
    O_3B57F8 *o = (O_3B57F8 *)op;
    s32 i;
    s32 a;
    s32 n;
    s32 j;
    s32 t;
    func_00495AE8((s32 *)o);
    for (i = 0; i < o->f14; i++) {
        {
            a = o->f4;
            t = a - 1;
            n = o->f10;
            if (t <= -1) t = 0;
            j = func_004950C8(o, i, 0);
            func_00512FE8(j, func_004950A8(o, i, t));
            func_00495F78(o, i, 0, t);
            if (a != 0) {
                func_00512AB0(func_004950C8(o, i, 0), 1, 1);
            } else {
                func_00512AB0(func_004950C8(o, i, 0), 1, 0);
            }
            j = 1;
            if (n > 0) {
                do {
                    if (a >= 0 && a < o->fC) {
                        func_00512AB0(func_004950C8(o, i, j), 1, 1);
                        t = func_004950C8(o, i, j);
                        func_00512FE8(t, func_004950A8(o, i, a));
                        func_00495F78(o, i, j, a);
                    } else {
                        func_00512AB0(func_004950C8(o, i, j), 1, 0);
                    }
                    j++;
                    n--;
                    a++;
                } while (n > 0);
            }
            if (a != o->fC) {
                func_00512AB0(func_004950C8(o, i, j), 1, 1);
                if (a >= o->fC) a--;
                t = func_004950C8(o, i, j);
                func_00512FE8(t, func_004950A8(o, i, a));
                func_00495F78(o, i, j, a);
            } else {
                func_00512AB0(func_004950C8(o, i, j), 1, 0);
            }
        }
    }
}
/* localdecomp:end func_00496068 */
