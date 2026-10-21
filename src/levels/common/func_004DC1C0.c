#include "common.h"

/* localdecomp:start func_004DC1C0 */
typedef struct {
    u8 p0[9700];
    u8 b9700;
    u8 p1[18];
    u8 b9719;
    u8 p2[600];
    s32 f10320;
} G_4DC1C0;

extern G_4DC1C0 D_001A4BE0;
extern s16 D_001426A0[];
extern s32 D_001D545C;
extern u8 D_001BBC40[][16];
extern s32 D_001C5290[][16];
extern float func_004DC1A8(s32);
extern s32 func_003FE420(s32, s32);
extern void func_00477B38(s32);

void func_004DC1C0(s32 amount) {
    float scale, f;
    s32 a, k, n, v;
    if (amount == 0) return;
    a = D_001426A0[0];
    if (a >= 5) a = 4;
    if (a < 0) a = 0;
    scale = func_004DC1A8(a);
    if (D_001A4BE0.b9700 == 0) {
        k = D_001A4BE0.b9719 & 0xF;
        n = D_001D545C;
        if (!(D_001BBC40[n][k] & 0x80)) {
            v = D_001C5290[n][k];
            if (func_003FE420(n, D_001A4BE0.b9719) >= 251 && v >= 7) {
                f = (float)(v - 6) * 0.07f;
                if (0.5f < f) f = 0.5f;
                f = 1.0f - f;
                scale *= f;
            }
        }
    }
    if (D_001A4BE0.b9700 == 0) {
        k = D_001A4BE0.b9719 & 0xF;
        n = D_001D545C;
        if (!(D_001BBC40[n][k] & 0x80)) {
            v = D_001C5290[n][k];
            if (func_003FE420(n, D_001A4BE0.b9719) < 50 && v < 2) {
                if (v == 0) scale *= 1.2f;
                else if (v == 1) scale *= 1.1f;
            }
        }
    }
    if (D_001A4BE0.b9700 == 0) {
        if (amount > 0) {
            amount = (float)amount * scale + 0.5f;
            if (amount <= 0) amount = 1;
        }
    }
    D_001A4BE0.f10320 -= amount;
    if (D_001A4BE0.f10320 < 0) D_001A4BE0.f10320 = 0;
    func_00477B38(360);
}
/* localdecomp:end func_004DC1C0 */
