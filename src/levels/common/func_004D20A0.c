#include "common.h"

typedef struct { s32 x0; s32 x4; volatile s32 x8; volatile s32 xC; s32 x10; } S_3AD798;
s32 func_004D20A0(S_3AD798 *p) {
 if (func_004D2090(p)) return 0; return p->x4 + ((p->x8 - p->xC + p->x10) % p->x10) * 0x27E40;
}
