#include "common.h"

extern void func_004F9920(s32 a0, f32 f);
extern u8 D_001A4BE0[];
extern s32 D_001D545C;
extern volatile f32 D_001DBCD8;

void func_004F9C78(void) {
    u8 *p;
    func_004F9920(0, 1.0f);
    p = D_001A4BE0;
    if (*(f32 *)(p + 0x1B0) > 0.0f) {
        *(f32 *)(p + 0x1B0) = D_001DBCD8 * 0.016666668f * *(f32 *)(p + 0x2838);
    }
    if (D_001D545C == 0x15 && p[0x1479] != 0) {
        *(f32 *)(p + 0x1B0) = *(f32 *)(p + 0x1B0) * 0.85f;
    }
}
