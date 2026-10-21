#include "common.h"

/* localdecomp:start func_00301E88 */
typedef struct {
    f32 v[4];
} Vec16;

extern Vec16 D_0026ED10[];
extern Vec16 D_0026ED90[];
extern f32 D_001DC4A0;
extern f32 D_001DC4C8;
extern void func_0040CCA0(void *a0, void *a1, void *a2, f32 f);
extern void func_0040C0F0(void *a0, void *a1, f32 f);

void func_00301E88(void) {
    s32 i;
    for (i = 0; i < 8; i++) {
        func_0040CCA0(&D_0026ED10[i], &D_0026ED10[i], &D_0026ED90[i], D_001DC4A0);
        func_0040C0F0(&D_0026ED10[i], &D_0026ED10[i], D_001DC4C8);
    }
}
/* localdecomp:end func_00301E88 */
