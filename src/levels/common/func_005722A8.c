#include "common.h"

/* localdecomp:start func_005722A8 */
typedef struct { u8 pad[0x1C]; u8 *f1C; u8 pad2[0x20 - 0x1C - 4]; } T_5722A8;
typedef struct { u8 pad[0x20]; s32 a20[8]; } U_5722A8;
typedef struct { u8 pad[0x460]; } E_5722A8;
extern T_5722A8 *D_0024B950;
extern E_5722A8 D_0024DF80[];
extern u8 *func_006197C0(s32);
extern void func_00577A68(s32, s32, s32, f32, f32, f32, f32);

void func_005722A8(u8 *o) {
    s32 id = *(s32 *)(o + 0x94);
    u8 *pl = func_006197C0(id);
    U_5722A8 *t = (U_5722A8 *)D_0024B950[*(s16 *)(o + 0x84)].f1C;
    u8 *e;

    if (*(s32 *)(pl + 0x2528) != 0) {
        if (*(s32 *)(pl + 0x254C) == 5) {
            return;
        }
        if (*(s32 *)(pl + 0x254C) == 3) {
            return;
        }
    }
    e = D_0024DF80[id].pad;
    e[0x2A3] = 0;
    *(s16 *)(o + 0x7E) = 2;
    *(s32 *)(e + 0x24C) = 0;
    *(f32 *)(e + 0x2C8) = 0.018f;
    *(f32 *)(e + 0x2B8) = 0.018f;
    *(s32 *)(pl + 0x2450) = 0;
    t->a20[id] = 0;
    func_00577A68(id, 30, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
}
/* localdecomp:end func_005722A8 */
