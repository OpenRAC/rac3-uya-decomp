#include "common.h"

typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; void *w68; } M_3D5548;
extern void func_003D5590(M_3D5548 *, void *);
extern void func_003D5620(void);
extern void func_00403DD8(void (*)(void), M_3D5548 *);

void func_003D5548(M_3D5548 *m) {
    void *p = m->w68;
    if (m->b20 == 0) {
        func_003D5590(m, p);
    }
    func_00403DD8(func_003D5620, m);
}
