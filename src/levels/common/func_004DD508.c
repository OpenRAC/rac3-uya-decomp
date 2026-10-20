#include "common.h"

extern u8 D_001A4BE0[];
extern s32 func_004EAA20(f32);
extern void func_004DD4B0(s32, s32, s32, s32);

void func_004DD508(void) {
    u8 *g = D_001A4BE0;
    s32 kind;
    s32 id;

    if (*(s32 *)(g + 9668) == 2 && *(s32 *)(g + 440) < 15) {
        return;
    }
    kind = (*(u8 **)(g + 9664))[67];
    id = g[5247];
    switch (kind) {
    case 3:
        if (*(s32 *)(g + 3084) == 0) {
            if (func_004EAA20(49.5f)) {
                func_004DD4B0(id, 0, 1, 30);
            }
            if (func_004EAA20(17.0f)) {
                func_004DD4B0(id, 1, 1, 30);
            }
        }
        break;
    case 4:
        if (*(s32 *)(g + 3084) == 0) {
            if (func_004EAA20(12.5f)) {
                func_004DD4B0(id, 0, 1, 30);
            }
            if (func_004EAA20(1.0f)) {
                func_004DD4B0(id, 1, 1, 30);
            }
        }
        break;
    case 20:
        if (*(s32 *)(g + 3084) == 0) {
            if (func_004EAA20(8.0f)) {
                func_004DD4B0(id, 0, 1, 30);
            }
            if (func_004EAA20(21.0f)) {
                func_004DD4B0(id, 1, 1, 30);
            }
        }
        break;
    }
}
