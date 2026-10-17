#include "common.h"

extern s32 *func_006699B0(void);
extern s32 func_00669978(s32, s32, s32, s32, s32 *);
extern s32 D_001A5F78[];

void func_00669B68(s32 a) {
    s32 *n = func_006699B0();
    if (n != 0) {
        *n = func_00669978(2, a, D_001A5F78[0], a, n);
    }
}
