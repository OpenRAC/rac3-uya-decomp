#include "common.h"
typedef struct {
    s32 a;
    s16 b;
    s16 c;
    s32 id;
    s32 pad;
} Ent00449588;
extern Ent00449588 D_002580C0[];
extern s32 D_001D6D2C;
extern s32 D_001D6D18;
extern u16 D_001D6D14;
extern s32 func_00449450(s32 a0, s32 *a1, s16 *a2);
s32 func_00449588(s32 a0) {
    s32 id;
    if (func_00449450(a0, &D_002580C0[D_001D6D2C].a, &D_002580C0[D_001D6D2C].b) != 0) {
        D_002580C0[D_001D6D2C].c = 1;
        id = (s16)(D_001D6D14 | (*(u16 *)&D_001D6D18 << 6));
        D_002580C0[D_001D6D2C].id = id;
        D_001D6D18++;
        D_001D6D2C = (D_001D6D2C + 1) & 15;
        return id;
    }
    return 0;
}
