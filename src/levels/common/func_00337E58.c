#include "common.h"

typedef struct {
    u8 pad[0x25C0];
    int f25C0;
} S_337E58;

extern u8 D_00142CBA[];
extern u8 *D_001E00A8;
extern S_337E58 D_001A4BE0;
extern f32 func_0040BFB0(void *, void *);
extern f32 func_004408C0(f32, f32);
extern int func_002F8D80(void *, int, int, f32, f32);
extern int func_00447CF0(void *);
extern int func_0030F1F8(void *);

void func_00337E58(u8 *a0) {
    f32 r = 2.7f;
    u8 *p;

    if (D_00142CBA[0] != 0) {
        r = 10.0f;
    }
    p = D_001E00A8;
    if (p == 0) {
        return;
    }
    do {
        if (p[0x20] == 0xFE) {
            break;
        }
        if (p[0x20] == 0xFD) {
            break;
        }
        if (p != 0 && *(u8 **)(p + 0x24) != 0 && (*(u8 **)(p + 0x24))[0x46] == 0x13) {
            if (func_0040BFB0(p + 0x10, a0 + 0x10) < r) {
                if (func_002F8D80(p, D_001A4BE0.f25C0, 0, func_004408C0(-30.0f, 30.0f) * 0.017453292f, 0.0f) != 0) {
                    break;
                }
            }
        } else if (func_00447CF0(p) != 0 && func_0040BFB0(p + 0x10, a0 + 0x10) < r) {
            if (func_0030F1F8(p) != 0) {
                break;
            }
        }
    } while ((p = *(u8 **)(p + 0x28)) != 0);
}
