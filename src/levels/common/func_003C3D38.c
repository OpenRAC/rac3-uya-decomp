#include "common.h"
typedef struct { char pad[28]; unsigned char b; char pad2[3]; } S_003C3D38;
extern unsigned short **D_001D6764[];
extern S_003C3D38 *D_001E0F54[];
int func_003C3D38(int a, char *b)
{
    S_003C3D38 *t;
    unsigned short *e = D_001D6764[0][*(int *)(b + 32)];
    t = D_001E0F54[0];
    t += *e & 0x7fff;
    return t->b != 0;
}
