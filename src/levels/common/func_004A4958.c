#include "common.h"

/* localdecomp:start func_004A4958 */
typedef struct { u16 pad; u16 flags; } Q_3C8E70;
extern void func_004A4958(Q_3C8E70 *);

typedef struct { u8 pad[0x10]; u8 *base; s16 h14; s16 h16; s16 h18; s16 h1A; s16 h1C; s16 h1E; } E_3C8ED0;
typedef struct { s16 n; u16 flags; u8 pad[0xC]; E_3C8ED0 items[1]; } S_3C8ED0;
extern u32 *D_001E10E8_003C8ED0;
extern s32 D_001DBCE0;
extern u8 D_001423C0[];
extern u8 D_00142350[];
extern void func_004A5220(E_3C8ED0 *, s32, u8 *);
extern void func_004A4C98(void);
extern s32 func_004A4D40(u8 *, u8 *, s32);
extern s32 func_004A4F38(s32, u8 *, u8 *, u8 *, s32);
void func_004A4958(Q_3C8E70 *arg) {
    S_3C8ED0 *q = (S_3C8ED0 *)arg;
    E_3C8ED0 *e;
    u8 *fl;
    s32 i;
    s32 alt;
    s32 drawn;
    s32 prev;
    if (q->n != 0) {
        func_004A5220(q->items, q->n, (u8 *)0x70003F00);
        func_004A4C98();
        fl = (u8 *)0x70003F00;
        alt = (q->flags >> 1) & 1;
        D_001E10E8_003C8ED0[0] = 0x30000007;
        drawn = 0;
        D_001E10E8_003C8ED0[2] = 0;
        D_001E10E8_003C8ED0[3] = 0x50000007;
        if (alt) D_001E10E8_003C8ED0[1] = (u32)D_001423C0;
        else D_001E10E8_003C8ED0[1] = (u32)D_00142350;
        prev = -1;
        D_001E10E8_003C8ED0 += 4;
        for (i = 0, e = q->items; i < q->n; i++, e++, fl++) {
            if (*fl == 0) {
                u8 *b = e->base;
                u8 *c = b + e->h1C;
                u8 *a0 = b + e->h18;
                u8 *d = b + e->h1A;
                if (func_004A4D40(a0, (u8 *)0x70000000, e->h14) == 0) {
                    drawn = 1;
                    prev = func_004A4F38(e->h16, c, d, (u8 *)0x70000000, prev);
                }
            }
        }
        if (alt && drawn) D_001DBCE0 |= 4;
    }
}
/* localdecomp:end func_004A4958 */
