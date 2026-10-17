#include "common.h"

extern s32 func_00429FC8(s32);

typedef struct { s32 id; s32 pad[4]; } E_395E18;
typedef struct { u8 pad[0x4590]; E_395E18 e[0x30]; } S_395E18;
typedef struct { u8 pad[0x34]; s32 v[3]; } T_395E18;
extern S_395E18 D_00160C40[];
extern T_395E18 D_0016C690[];
s32 func_00429FC8(s32 id) {
    s32 i, j;
    for (i = 0; i < 0x30; i++) if (D_00160C40[0].e[i].id == id) break;
    if (i == 0x30) return 1;
    for (j = 0; j < 3; j++) if (D_0016C690[0].v[j] == i) break;
    return j != 3;
}
