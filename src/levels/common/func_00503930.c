#include "common.h"

/* localdecomp:start func_00503930 */
typedef struct {
    u8 p0[0x10];
    s32 x10[8];
} L_503930;
typedef struct {
    u8 x0;
    u8 p1[0x89];
    u16 x8A;
    u8 p8C[0x64];
} T_503930;
extern s32 func_00416920(s32);
extern u8 D_001425C0[];
extern T_503930 D_002C5640[];
extern L_503930 D_00142660;
extern s32 D_001427F0[];

void func_00503930(s32 id) {
    s32 pos;
    s32 i;
    if (id == 9 || id == 30 || id == 22 || id == 35) return;
    if (D_002C5640[D_001425C0[id]].x0 == 0 && !func_00416920(id)) return;
    pos = -1;
    for (i = 0; i < 8; i++) {
        if (D_00142660.x10[i] == id) {
            pos = i;
            break;
        }
    }
    if (pos == 0) return;
    if (pos >= 3 || pos == -1) {
        s32 found = -1;
        s32 j;
        for (j = 2; j >= 0; j--) {
            s32 n = D_00142660.x10[j];
            if (n != 0 && D_001427F0[n] == 0 && (D_002C5640 + D_001425C0[n])->x8A != 0) {
                found = j;
                break;
            }
        }
        if (found != -1) {
            for (j = found; j < 7; j++) {
                D_00142660.x10[j] = D_00142660.x10[j + 1];
                if (pos == j + 1) pos--;
            }
            D_00142660.x10[7] = 0;
        }
    }
    if (pos != -1) {
        for (i = pos; i < 7; i++) {
            D_00142660.x10[i] = D_00142660.x10[i + 1];
        }
        D_00142660.x10[7] = 0;
    }
    {
        s32 k;
        for (k = 7; k > 0; k--) {
            D_00142660.x10[k] = D_00142660.x10[k - 1];
        }
    }
    D_00142660.x10[0] = id;
}
/* localdecomp:end func_00503930 */
