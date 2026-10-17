#include "common.h"

typedef struct {
    u8 pad0[0x14];
    s32 w14;
    u8 pad18[0x44 - 0x18];
    s32 w44;
} S_30D410b;

typedef struct {
    u8 pad0[0x68];
    S_30D410b *p68;
} S_30D410;

typedef struct {
    s32 w0;
    s32 pad[3];
} S_30D410c;

extern s32 D_001DC690;
extern S_30D410c D_00271B70[];
extern void func_0030CFB8(S_30D410 *a0);
extern void func_004C4AB8(s32 a0);
extern void func_00436220(S_30D410 *a0);

void func_0030D410(S_30D410 *a0) {
    S_30D410b *t = a0->p68;
    D_001DC690--;
    D_00271B70[t->w14].w0 = 0;
    func_0030CFB8(a0);
    func_004C4AB8(t->w44);
    func_00436220(a0);
}
