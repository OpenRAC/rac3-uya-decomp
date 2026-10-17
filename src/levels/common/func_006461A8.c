#include "common.h"

typedef struct {
    u8 pad[164];
    u8 arr[1];
} D_001A5990_t;

extern D_001A5990_t D_001A5990;
extern void func_006460E8(void *a0, s32 a1);
extern void func_00646070(void *a0, s32 a1);

void func_006461A8(u8 *a0, s32 a1, s32 a2) {
    if (D_001A5990.arr[*(s32 *)(a0 + 9540)] != 0) {
        func_006460E8(a0, a2);
    } else {
        func_006460E8(a0, a1);
    }
    func_00646070(a0, a1);
}
