#include "common.h"
typedef struct { u8 pad[0x1C]; void (*fn)(s32, s32); } V_66AA40;
typedef struct { u8 pad[0x18]; s32 x18; } A_66AA40;
extern A_66AA40 *D_001DAC20;
extern void func_0066AC78(void);
extern V_66AA40 *func_005BF058(s32);
void func_0066AA40(A_66AA40 *a, s32 b) {
    if (a == D_001DAC20) {
        func_0066AC78();
    } else {
        func_005BF058(a->x18)->fn(a->x18, b);
    }
}
