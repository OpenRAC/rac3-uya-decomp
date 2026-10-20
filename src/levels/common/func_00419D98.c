#include "common.h"

typedef struct {
    u8 pad[0x14];
    int a[8];
    int b[16];
    int c[8];
} S_419D98;

extern int D_001DFD98[];
extern int D_001DFDA4[];
extern int D_001DFDA8[];

void func_00419D98(int n) {
    int off = ((S_419D98 *)D_001DFD98[0])->c[n];
    int i;
    int end;
    int start;
    int j;

    if (n == 0) {
        for (j = 0; j < ((S_419D98 *)D_001DFD98[0])->b[0]; j++) {
            *(s16 *)(j * 8 + D_001DFDA4[0] + 4) = 0;
        }
    }
    start = n != 0 ? ((S_419D98 *)D_001DFD98[0])->a[n - 1] : 0;
    end = ((S_419D98 *)D_001DFD98[0])->a[n];
    for (i = start; i < end; i++) {
        *(int *)(i * 8 + D_001DFDA8[0]) -= off;
        *(int *)(i * 8 + D_001DFDA8[0]) |= 0x80000000;
    }
    start = n != 0 ? ((S_419D98 *)D_001DFD98[0])->b[n - 1] : 0;
    end = ((S_419D98 *)D_001DFD98[0])->b[n];
    for (i = start; i < end; i++) {
        *(int *)(i * 8 + D_001DFDA4[0]) -= off;
        *(int *)(i * 8 + D_001DFDA4[0]) |= 0x80000000;
    }
    ((S_419D98 *)D_001DFD98[0])->c[n] = 0;
}
