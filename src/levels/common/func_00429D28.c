#include "common.h"

typedef struct { s32 k; u8 pad[0x10]; } E_395BC0;
typedef struct { u8 pad[0x4590]; E_395BC0 e[0x30]; } S_395BC0;
typedef struct { u8 d[0xC800]; } B_395BC0;
typedef struct { u8 pad[0x34]; s32 f34[3]; B_395BC0 blk[1]; } S_395BC0b;
extern S_395BC0 D_00160C40_00395BC0;
extern S_395BC0b D_0016C690_00395BC0;
void func_00429D28(s32 a, s32 b) {
    s32 i;
    for (i = 0; i < 0x30; i++) {
        if (D_00160C40_00395BC0.e[i].k == a) break;
    }
    if (i == 0x30) return;
    if (D_0016C690_00395BC0.f34[b] == i) return;
    func_00429C30(i, b, &D_0016C690_00395BC0.blk[b], 0);
}
