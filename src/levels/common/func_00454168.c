#include "common.h"

typedef struct {
    int f0;
    int f4;
    char pad[42024];
} S_002D1710;
extern S_002D1710 D_002D1710[];

int func_00454168(int a0, int a1)
{
    return D_002D1710[a1].f4 == a0;
}
