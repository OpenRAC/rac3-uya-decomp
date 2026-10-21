#include "common.h"

typedef struct {
    int id;
    int a;
    int b;
} Ent_0048D1A8;

typedef struct {
    u8 pad0[4];
    u8 f4;
    u8 f5;
    u8 f6;
    u8 pad7;
    int f8;
    u8 padC[0xA1];
    u8 fAD;
} Opt_0048D1A8;

extern Ent_0048D1A8 D_002EB078[];
extern int D_001D8D90;
extern int D_001D8D94;
extern int D_001D8D98;
extern int D_001D8DE4;
extern Opt_0048D1A8 D_00143950;
extern int D_001D5520[] __attribute__((section(".sdata")));
extern char D_001D8DE8[];
extern char D_001D8DF0[];
extern char D_001D8DF8[];
extern char D_001D8E00[];
extern void *func_00494DD0(int);
extern void *func_004950A8(void *, int, int);
extern char *func_004181A0(int);
extern void func_0011B2E8(void *, char *, ...);
extern void func_005131A0(int, int);
extern void func_00512D70(int, int);

/* localdecomp:start func_0048D1A8 */
void func_0048D1A8(void)
{
    int i;
    Ent_0048D1A8 *e;
    void *p;
    char *s;
    char *t;

    for (i = 0; i < D_001D8D90; i++) {
        __asm__("mtlo %1\n\tmadd %0, %2, %3" : "=r"(e) : "r"(D_002EB078), "r"(i), "r"(12));
        switch (e->id) {
        case 326: {
            char *fmt;
            func_0011B2E8(func_004950A8(func_00494DD0(0), 0, i), D_001D8DE8, func_004181A0(326));
            fmt = D_001D8DF0;
            func_0011B2E8(func_004950A8(func_00494DD0(0), 1, i), fmt, D_00143950.f8 ? func_004181A0(567) : func_004181A0(566));
            break;
        }
        case 328: {
            char *fmt;
            func_0011B2E8(func_004950A8(func_00494DD0(0), 0, i), D_001D8DE8, func_004181A0(328));
            fmt = D_001D8DF0;
            func_0011B2E8(func_004950A8(func_00494DD0(0), 1, i), fmt, D_00143950.f6 ? func_004181A0(373) : func_004181A0(374));
            break;
        }
        case 564:
            func_0011B2E8(func_004950A8(func_00494DD0(0), 0, i), D_001D8DE8, func_004181A0(564));
            func_0011B2E8(func_004950A8(func_00494DD0(0), 1, i), D_001D8DF8);
            break;
        case 563:
            func_0011B2E8(func_004950A8(func_00494DD0(0), 0, i), D_001D8DE8, func_004181A0(563));
            func_0011B2E8(func_004950A8(func_00494DD0(0), 1, i), D_001D8DF8);
            break;
        case 1288: {
            char *fmt;
            func_0011B2E8(func_004950A8(func_00494DD0(0), 0, i), D_001D8DE8, func_004181A0(1288));
            fmt = D_001D8DF0;
            func_0011B2E8(func_004950A8(func_00494DD0(0), 1, i), fmt, D_00143950.fAD ? func_004181A0(373) : func_004181A0(374));
            break;
        }
        case 1289: {
            char *fmt;
            func_0011B2E8(func_004950A8(func_00494DD0(0), 0, i), D_001D8DE8, func_004181A0(1289));
            fmt = D_001D8DF0;
            func_0011B2E8(func_004950A8(func_00494DD0(0), 1, i), fmt, D_001D5520[0] ? func_004181A0(373) : func_004181A0(374));
            break;
        }
        case 398: {
            char *fmt = D_001D8DF0;
            p = func_004950A8(func_00494DD0(0), 0, i);
            s = func_004181A0(322);
            t = func_004181A0(398);
            func_0011B2E8(p, D_001D8E00, s, t);
            func_0011B2E8(func_004950A8(func_00494DD0(0), 1, i), fmt, D_00143950.f5 ? func_004181A0(373) : func_004181A0(374));
            break;
        }
        case 397: {
            char *fmt = D_001D8DF0;
            p = func_004950A8(func_00494DD0(0), 0, i);
            s = func_004181A0(322);
            t = func_004181A0(397);
            func_0011B2E8(p, D_001D8E00, s, t);
            func_0011B2E8(func_004950A8(func_00494DD0(0), 1, i), fmt, D_00143950.f4 ? func_004181A0(373) : func_004181A0(374));
            break;
        }
        }
    }
    if (D_001D8D94 >= 0) {
        if (D_001D8D98 != D_001D8D94) {
            D_001D8DE4 = 30;
        }
        if (D_001D8DE4 != 0) {
            if (--D_001D8DE4 == 0) {
                func_005131A0(0x1E0003, D_002EB078[D_001D8D94].b);
                func_00512D70(0x1E0003, 1);
            }
        }
        D_001D8D98 = D_001D8D94;
    }
}
/* localdecomp:end func_0048D1A8 */
