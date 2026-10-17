#include "common.h"
extern unsigned char D_001D67CC;
extern float D_001D67D0;
extern float D_001E6DF0[];
extern void func_003E7F48(void);
int func_00400008(void)
{
    int r;
    if (D_001D67CC != 0) {
        D_001E6DF0[0] = D_001D67D0;
        func_003E7F48();
        D_001D67CC = 0;
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
