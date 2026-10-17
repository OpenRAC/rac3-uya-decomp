#include "common.h"

extern s32 func_004D1DE0();
extern u8 *D_001E1264[];

typedef struct { unsigned long a, b, c; } Q_3AD4D8;
extern u8 *D_001E1264[];
extern void func_004D1640(u8 *, Q_3AD4D8 *);
s32 func_004D1DE0(s32 unused, u8 *out) {
    Q_3AD4D8 t;
    func_004D1640(D_001E1264[0] + 0x48, &t);
    *(unsigned long *)(out + 8) = t.a;
    *(unsigned long *)(out + 0x10) = t.b;
    return 1;
}
