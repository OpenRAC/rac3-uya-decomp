#include "common.h"

/* localdecomp:start func_004BD808 */
typedef struct {
    s32 id;
    s32 f4;
    s32 kind;
    s32 color;
    u8 pad[32];
} Ent4BD808;

extern s32 func_0040D068(s32, s32);
extern void func_005130C8(s32, s32);
extern void func_00512AB0(s32, s32, s32);

void func_004BD808(s32 alpha, Ent4BD808 *list) {
    s32 i;

    for (i = 0; list[i].id != 0; i++) {
        if (list[i].kind != 0) {
            func_005130C8(list[i].id, func_0040D068(list[i].color, (alpha << 24) + 0x808080));
        }
        if (list[i].kind == 4) {
            func_00512AB0(list[i].id, 64, alpha > 64);
        }
    }
}
/* localdecomp:end func_004BD808 */
