#include "common.h"
typedef int s128 __attribute__((mode(TI)));
extern s32 D_001E2F44[];
extern f32 D_001E2F48[];
extern s32 D_001E1A8C;
extern s32 D_001D545C;
extern s128 D_002B2B30[];
extern void func_0034EF20(u8 *);
extern f32 func_0034EE28(u8 *);
extern void func_0034F148(void);
extern void func_00402498(void (*)(void), u8 *);
void func_0034ED10(u8 *m) {
    s128 *v = *(s128 **)(m + 104);
    s32 t;
    s32 i;
    switch (m[32]) {
    case 0:
        m[48] = 255;
        m[32] = 1;
        D_001E2F44[0] = 0;
        t = D_001D545C;
        i = 0;
        if (t == 1) {
            D_001E1A8C = 100;
        } else if (t == 2) {
            D_001E1A8C = 101;
            i = 1;
        } else if (t == 5) {
            D_001E1A8C = 105;
            i = 2;
        } else if (t == 16) {
            D_001E1A8C = 100;
            i = 3;
        } else if (t == 26) {
            D_001E1A8C = 100;
            i = 5;
        }
        *v = D_002B2B30[i];
        func_0034EF20(m);
        break;
    case 1:
        D_001E2F48[0] = func_0034EE28(m);
        func_00402498(func_0034F148, m);
        break;
    }
}
