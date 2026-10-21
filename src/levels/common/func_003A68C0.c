#include "common.h"

/* localdecomp:start func_003A68C0 */
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    u8 p10[0x30];
    s32 x40;
    s32 x44;
    s32 x48;
    s32 x4C;
    u8 p50[0x18];
    s32 x68;
    s32 x6C;
    u8 p70[0x64];
    s32 xD4;
} S_3A68C0;
typedef struct {
    u8 p0[0xB2];
    u16 xB2;
} O_3A68C0;
typedef struct {
    u8 p0[0x464];
    u8 x464[1];
} T_3A68C0;
extern s32 func_00452F60(void *);
extern s32 func_0040BA90(s32 *);
extern void func_004A73F8(s32, s32, void *, s32);
extern u8 *D_001E009C;
extern s32 D_001D545C;
extern s32 D_001DE3B0;
extern T_3A68C0 D_00237880;
extern u8 D_001BBE90[];

s32 func_003A68C0(O_3A68C0 *o, S_3A68C0 *p) {
    s32 ok = 1;
    if (p->x0 != -1) {
        if (!func_00452F60(D_001E009C + (p->x0 << 8))) ok = 0;
    }
    if (p->x4 != -1) {
        if (!func_00452F60(D_001E009C + (p->x4 << 8))) ok = 0;
    }
    if (p->xD4) {
        u16 h = o->xB2;
        s32 b;
        if (D_00237880.x464[(s16)h] || (b = D_001BBE90[((s16)h >> 1) + (D_001D545C << 10)], (h & 1) ? (b >> 4) & 7 : b & 7)) ok = 1;
    }
    if (p->x68 != ok) {
        if (p->x6C == 0) p->x6C = D_001DE3B0;
        if (func_0040BA90(&p->x6C)) {
            s32 a, f;
            p->x68 = ok;
            if (p->xC && ok) {
                p->x0 = -1;
                p->x4 = -1;
            }
            if (ok) {
                a = p->x40;
                if (a < 0) goto done;
                f = p->x48;
            } else {
                a = p->x44;
                if (a < 0) goto done;
                f = p->x4C;
            }
            if (f == 0) func_004A73F8(a, 0, D_001E009C + (p->x8 << 8), 0);
        }
    } else {
        p->x6C = 0;
    }
done:
    if (p->xD4 && ok) {
        u16 h = o->xB2;
        if (h & 1) {
            u8 *q = &D_001BBE90[((s16)h >> 1) + (D_001D545C << 10)];
            if (((*q >> 4) & 7) != 7) *q += 16;
        } else {
            u8 *q = &D_001BBE90[((s16)h >> 1) + (D_001D545C << 10)];
            if ((*q & 7) != 7) *q += 1;
        }
    }
    return p->x68;
}
/* localdecomp:end func_003A68C0 */
