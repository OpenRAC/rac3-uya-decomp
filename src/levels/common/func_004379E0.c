#include "common.h"

extern void func_004379E0(void);
extern void func_004379E0();

typedef struct { s16 a; s16 b; } T_BDC90;
typedef struct { u8 c[0xC]; s32 fC; } E_BDC90;
typedef struct { u8 p0[0x20]; E_BDC90 *f20; } O_BDC90;
extern s32 D_00200AB0[];
extern O_BDC90 *D_001FD200[];
extern T_BDC90 D_002002F0[];
void func_004379E0(void) {
    s32 *p;
    E_BDC90 *e;
    u8 *c;
    u8 *o;
    T_BDC90 *t;
    for (p = D_00200AB0; *p >= 0; p++) {
        e = D_001FD200[*p]->f20;
        for (;;) {
            o = (u8 *)(e->fC & 0x7FFFFFFF);
            c = e->c;
            if (*c != 0xFF) {
                do {
                    t = &D_002002F0[*c];
                    if (t->a != 0) { *(u32 *)(o + 0x30) = (*(u32 *)(o + 0x30) & 0xFFFFC000) | t->a; }
                    if (t->b != 0) { *(u32 *)(o + 0x40) = (*(u32 *)(o + 0x40) & 0xFFFFC000) | t->b; }
                    c++;
                    o += 0x40;
                } while (*c != 0xFF);
            }
            if (e->fC < 0) break;
            e++;
        }
    }
}
