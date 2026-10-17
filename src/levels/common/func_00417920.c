#include "common.h"
typedef struct { unsigned char a; unsigned char b; char pad[238]; } S_00417920;
extern unsigned char D_001425C9[];
extern S_00417920 D_002C5640[];
int func_00417920(void)
{
    int r = 1;
    int v = (D_002C5640 + D_001425C9[0])->b;
    if (v >= 4) {
        return 2;
    }
    return r < v;
}
