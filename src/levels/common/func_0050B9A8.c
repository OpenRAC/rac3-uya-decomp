#include "common.h"

/* localdecomp:start func_0050B9A8 */
typedef struct {
    u8 pad0[0x1C];
    s32 entries[1];
} S_50B9A8_Hdr;

typedef struct {
    u8 pad0[0x48];
    S_50B9A8_Hdr *hdrs[1];
} S_50B9A8_Tbl;

typedef struct {
    u8 pad0[0x24];
    S_50B9A8_Tbl *tbl;
    u8 pad28[0x18];
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    f32 f44;
    u8 pad48[4];
    f32 f4C;
    u8 pad50[8];
    s32 w58;
    s32 w5C;
} S_50B9A8_Obj;

typedef struct {
    u8 pad0[0x40];
    u8 b40;
    u8 b41;
    u8 pad42[2];
    f32 f44;
} S_50B9A8_Src;

typedef struct {
    u8 pad0[0xC04];
    f32 fC04;
    u8 padC08[0x19B8];
    S_50B9A8_Src *src;
    u8 pad25C4[0x23C];
    S_50B9A8_Obj *obj;
} S_50B9A8;

extern S_50B9A8 D_001A4BE0;

void func_0050B9A8(void) {
    S_50B9A8 *s = &D_001A4BE0;
    S_50B9A8_Obj *o = s->obj;
    S_50B9A8_Hdr **h1;
    S_50B9A8_Hdr **h2;
    S_50B9A8_Hdr **hdrs;
    if (o == 0) {
        return;
    }
    hdrs = o->tbl->hdrs;
    o->f4C = s->fC04;
    h1 = &hdrs[o->b42];
    h2 = &hdrs[o->b43];
    o->f44 = s->src->f44;
    o->b40 = s->src->b41;
    o->b41 = s->src->b41;
    o->w58 = (*h1)->entries[o->b40];
    o->w5C = (*h2)->entries[o->b41];
}
/* localdecomp:end func_0050B9A8 */
