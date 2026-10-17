#include "common.h"

extern void func_004CB6E0(s32, s32);
extern u8 D_001A71C4[];

void func_004D0840(s32 a0) {
    s32 n = 1;
    if (a0 != 0) {
        n = 2;
    }
    switch (D_001A71C4[0]) {
    case 0:
        func_004CB6E0(0, n);
        break;
    case 3:
        func_004CB6E0(81, n);
        break;
    case 1:
        func_004CB6E0(63, n);
        break;
    case 5:
        func_004CB6E0(154, n);
        break;
    }
}
