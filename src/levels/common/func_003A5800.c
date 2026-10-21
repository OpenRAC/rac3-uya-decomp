#include "common.h"

/* localdecomp:start func_003A5800 */
typedef struct {
    f32 f0;
    s16 h4;
} A_3A5800;
typedef struct {
    u8 pad0[7];
    u8 b7;
    u8 b8;
    u8 b9;
    u8 padA[0x2E];
    s16 h38;
} B_3A5800;
typedef struct {
    u8 pad0[0x34];
    u16 h34;
    u8 pad36[0x49];
    u8 b7F;
    u8 pad80[0x18];
    s32 i98;
    u8 pad9C[0xC];
    u8 bA8;
} O_3A5800;
extern A_3A5800 *func_00440728(O_3A5800 *);
extern B_3A5800 *func_00445EB8(O_3A5800 *);
extern s32 func_004539A8(O_3A5800 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_004A6DF8(O_3A5800 *, s32);
extern s32 func_004A6D20(O_3A5800 *, s32);
extern void func_004A6E88(s32);
extern void func_00441FB8(O_3A5800 *, s32, s32);

void func_003A5800(O_3A5800 *obj) {
    s32 i = 0;
    A_3A5800 *a;
    B_3A5800 *b;

    obj->b7F = 0;
    a = func_00440728(obj);
    a->f0 = (f32)a->h4;
    b = func_00445EB8(obj);
    b->h38 = 0;
    b->b7 = 0;
    b->b9 = 0;
    b->b8 = 0;
    func_004539A8(obj, -1, 0, 0, 0, 0, 3, 0, 0, 0, 0.0f, 0.0f, 1.0f);
    obj->i98 = 0;
    obj->bA8 = 0xFF;
    obj->h34 = (obj->h34 | 0x43) & 0xEFFF;
    func_004A6DF8(obj, 1);
    do {
        if (func_004A6D20(obj, i)) {
            func_004A6E88(i);
        }
        i++;
    } while (i < 0x34);
    func_00441FB8(obj, 0x10, 6);
}
/* localdecomp:end func_003A5800 */
