#include "common.h"

typedef struct {
    u8 pad0[36];
    s32 f36;
    u8 pad1[200];
} Ent4B21A8;

extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern Ent4B21A8 D_002C3200[];
extern s32 func_004BA970(s32);
extern s32 func_004B2158(void);

s32 func_004B21A8(s32 a0) {
    if (D_001A4BE0[9700] == 3) {
        return 1;
    }
    if (a0 != 0 && D_001A4BE0[9707] != 0 && *(s16 *)(D_001A4BE0 + 10356) == 0) {
        s32 v = func_004BA970(0);
        return ((Ent4B21A8 *)(D_001425C0[v] * 240 + (u8 *)D_002C3200))->f36;
    }
    if (func_004B2158() != 0) {
        return 74;
    }
    if (D_001A4BE0[5236] != 0) {
        return 85;
    }
    return 0;
}
