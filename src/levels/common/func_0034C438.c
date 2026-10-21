#include "common.h"

/* localdecomp:start func_0034C438 */
typedef struct {
    u8 pad0[24];
    s32 unk18;
    u8 pad1C[20];
} S_34C438a;

typedef struct {
    f32 x;
    f32 y;
    s32 z;
    f32 w;
} S_34C438e;

typedef struct {
    S_34C438e a[204];
    S_34C438e b[204];
} S_34C438b;

extern S_34C438a D_0027F600[];
extern s32 D_001DD418;
extern S_34C438b D_002822A0;

extern void func_0034C3F0(s32 a0);

void func_0034C438(void) {
    s32 i;
    S_34C438a *a = D_0027F600;
    S_34C438b *b;

    for (i = 29; i >= 0; i--) {
        a[i].unk18 = 0;
    }
    D_001DD418 = 0;
    func_0034C3F0(0);
    for (i = 0; i < 204; i++) {
        D_002822A0.a[i].w = 1.0f;
        D_002822A0.b[i].w = 1.0f;
    }
    b = &D_002822A0;
    b->a[21].x = 1.0f;
    b->a[21].y = 2.0f;
    b->a[21].z = 3;
    b->a[162].x = 1.0f;
    b->a[162].y = 2.0f;
    b->a[162].z = 3;
    b->b[21].x = 2.0f;
    b->b[21].y = 4.0f;
    b->b[21].z = 3;
    b->b[162].x = 2.0f;
    b->b[162].y = 4.0f;
    b->b[162].z = 3;
}
/* localdecomp:end func_0034C438 */
