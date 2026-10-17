#include "common.h"
extern unsigned char D_001426E0[];
void func_00432FB8(int a) {
    D_001426E0[(a >> 3) + 195] |= 1 << (a & 7);
}
