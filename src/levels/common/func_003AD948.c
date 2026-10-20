#include "common.h"

typedef struct {
    int f0;
    f32 f4;
    f32 f8;
    int fC;
} V_3AD948;

extern u8 D_001A4C60[];
extern void func_003E6D50(int, int, f32, f32);
extern void func_003E6EC8(int, f32);
extern void func_003E7110(int, int);
extern void func_00441FB8(void *, int, int);
extern int func_00453210(void *, int);

void func_003AD948(u8 *m) {
    u8 st = m[0x20];
    V_3AD948 *pv = *(V_3AD948 **)(m + 0x68);

    switch (st) {
    case 0:
        m[0x30] = 0xFF;
        func_00441FB8(m, 1, -1);
    case 1:
        if (pv->f0 != -1 && func_00453210(D_001A4C60, pv->f0) != 0) {
            func_00441FB8(m, 2, -1);
        }
        break;
    case 2:
        func_003E6D50(0, 0, pv->f4, 0.003f);
        func_003E6EC8(0, pv->f8 * 0.017453292f);
        if (pv->fC != -1) {
            if (pv->fC == 1) {
                func_003E7110(0, -1);
            } else if (pv->fC == 2) {
                func_003E7110(0, 1);
            } else if (pv->fC == 3) {
                func_003E7110(0, 2);
            }
        }
        if (func_00453210(D_001A4C60, pv->f0) == 0) {
            func_00441FB8(m, 1, -1);
        }
        break;
    }
}
