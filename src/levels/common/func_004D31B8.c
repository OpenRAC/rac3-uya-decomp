#include "common.h"
extern u8 D_001A71C4[];
extern void func_004CF3B8(s32, s32);
void func_004D31B8(s32 a0) {
    s32 m = 1;
    if (a0 != 0) {
        m = 2;
    }
    switch (D_001A71C4[0]) {
    case 0:
        func_004CF3B8(0, m);
        break;
    case 3:
        func_004CF3B8(81, m);
        break;
    }
}
