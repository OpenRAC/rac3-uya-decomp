#include "common.h"
typedef struct { s32 v[83]; } Row004296B0;
typedef struct {
    u8 pad[37404];
    s32 base;
    u8 pad2[56];
    Row004296B0 rows[1];
} Big004296B0;
typedef struct {
    u8 pad[48];
    s32 n;
    u8 pad2[56];
    s32 h;
} Cur004296B0;
extern Cur004296B0 D_001E6E00;
extern Big004296B0 D_00160C40;
extern void func_0045C8A8(s32, s32, s32);
extern void func_0045CA60(s32);
s32 func_004296B0(s32 i) {
    Cur004296B0 *c = &D_001E6E00;
    Big004296B0 *b = &D_00160C40;
    s32 h = c->h;
    s32 cur = b->rows[c->n].v[i];
    s32 len = b->rows[c->n].v[i + 1] - cur;
    if (len > 0) {
        func_0045C8A8(h, cur + b->base, len);
        func_0045CA60(0);
    }
    return 1;
}
