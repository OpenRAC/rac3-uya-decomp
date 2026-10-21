#include "common.h"

/* localdecomp:start func_0039CB90 */
typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    char pad0[0xA];
    unsigned char count;
} Vars;

typedef struct {
    char pad0[0x68];
    Vars *vars;
} Obj;

extern Vec4 D_001E2100[];
extern Vec4 D_001E2130[];
extern float D_001DE140;
extern float D_001DE168;
extern void func_0040CCA0(Vec4 *, Vec4 *, Vec4 *, float);
extern void func_0040C0F0(Vec4 *, Vec4 *, float);

void func_0039CB90(Obj *obj) {
    Vars *v = obj->vars;
    int i;

    for (i = 0; i < v->count; i++) {
        func_0040CCA0(&D_001E2100[i], &D_001E2100[i], &D_001E2130[i], D_001DE140);
        func_0040C0F0(&D_001E2100[i], &D_001E2100[i], D_001DE168);
    }
}
/* localdecomp:end func_0039CB90 */
