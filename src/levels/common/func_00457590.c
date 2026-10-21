#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern int D_001DFBC0;
extern char *func_00458650(void *a);
extern void func_00458600(void *a, char *p);
extern void func_004583C0(void *a, char *p, float f);
extern void func_004585D0(void *a, char *p);
extern void func_004577D0(void *a, char *p, void *b, void *c, void *d, float f);
extern void func_00457C20(void *a, char *p);
extern void func_00457E08(void *a, char *p, void *b);
extern void func_00458858(void *a, char *p, float f);
extern void func_00458F38(void);

/* localdecomp:start func_00457590 */
int func_00457590(void *a, void *b, float f) {
    char *p;
    char buf[32];
    p = func_00458650(a);
    if (p == 0) {
        return 8;
    }
    if (D_001DFBC0 != *(int *)(p + 188)) {
        *(int *)(p + 152) = *(int *)(p + 148);
        *(int *)(p + 148) = 0;
        if (!(*(int *)(p + 56) & 0x100)) {
            func_00458600(a, p);
        }
        if (D_001DFBC0 - *(int *)(p + 188) >= 2 || *(int *)(p + 188) == 0) {
            func_004583C0(a, p, 0.0f);
            *(int *)(p + 156) &= ~2;
            *(float *)(p + 180) = 0.0f;
            *(unsigned char *)(p + 234) = 255;
            __asm__ __volatile__("sq $0,160(%0)" : : "r"(p));
            *(int *)(p + 128) = 0;
        }
        *(int *)(p + 188) = D_001DFBC0;
        func_004585D0(a, p);
        func_004577D0(a, p, b, buf, buf + 16, f);
        func_00457C20(a, p);
        func_00457E08(a, p, b);
        func_00458858(a, p, f);
        func_00458F38();
    }
    return *(int *)(p + 148);
}
/* localdecomp:end func_00457590 */
