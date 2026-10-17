#include "common.h"

typedef struct {
    int f0;
    char pad[64];
} S_002EA318;
extern S_002EA318 D_002EA318[];

int func_004821D8(int a0, int a1)
{
    return D_002EA318[a0 * 2 + a1].f0;
}
