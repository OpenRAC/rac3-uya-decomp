#include "common.h"
typedef struct { unsigned char b; char pad[15]; } S_003F0080;
extern S_003F0080 D_001E2500[][8];
int func_003F0080(int a, unsigned char *p)
{
    int i = 0;
    if (p != 0) {
        i = p[1356] * 4 + p[1367];
    }
    return D_001E2500[i][a].b != 0;
}
