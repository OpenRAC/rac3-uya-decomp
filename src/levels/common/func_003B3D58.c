#include "common.h"

typedef struct {
    u8 pad[8];
    s32 (*f8)(u8 *);
} Vt_003B3D58;

extern u8 *D_001E009C[];
extern void func_003B3EB8(u8 *, u8 *);
extern s32 func_0040BA90(u8 *);
extern s32 func_003B62A8(u8 *, u8 *);
extern void func_003B60F8(u8 *, u8 *, s32, f32);
extern void func_00441FB8(u8 *, s32, s32);
extern Vt_003B3D58 *func_00326898(void);

void func_003B3D58(u8 *self)
{
    u8 *v = *(u8 **)(self + 104);
    s32 r;

    if (self[32] == 0) {
        func_003B3EB8(self, v);
    }
    switch (self[32]) {
    case 1:
        *(u16 *)(self + 52) |= 2;
        break;
    case 2:
        if (*(s32 *)(v + 36) != 0) {
            if (func_0040BA90(v + 36) != 0) {
                r = func_003B62A8(self, v);
                if (r != 0) {
                    func_003B60F8(self, v, r, *(f32 *)(v + 12));
                }
            }
        } else {
            if (func_003B62A8(self, v) != 0) {
                *(s32 *)(v + 36) = *(s32 *)(v + 32);
            }
        }
        break;
    case 3:
        if (*(s32 *)(v + 196) == *(s32 *)(v + 192)) {
            func_00441FB8(self, 1, -1);
        }
        break;
    case 4:
        if (func_0040BA90(v + 36) != 0) {
            if (func_00326898()->f8(D_001E009C[0] + (*(s32 *)(v + 108) << 8)) != 0) {
                func_00441FB8(self, self[188], -1);
            }
        }
        break;
    }
}
