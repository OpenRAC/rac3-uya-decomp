#include "common.h"

/* localdecomp:start func_004A4768 */
typedef int s128_004A4768 __attribute__((mode(TI)));
typedef struct { long a; long b; } E_004A4768;
typedef struct { u8 pad[12]; s16 n; s16 pad2; E_004A4768 *e; } T_004A4768;
extern s128_004A4768 *D_001E10E8;
extern T_004A4768 *D_001E0E70;
extern s128_004A4768 *D_001E0E80;
extern s32 D_001D4BB4;
extern s32 D_001D4BB0;
extern s32 D_001DF9FC;
void func_004A4768(void) {
    s32 i;
    T_004A4768 *t;
    D_001E0E80 = D_001E10E8++;
    t = D_001E0E70;
    D_001D4BB0 = D_001D4BB4;
    D_001DF9FC = 0;
    for (i = 0; i < t->n; i++) {
        t->e[i].a = 0;
    }
}
/* localdecomp:end func_004A4768 */
