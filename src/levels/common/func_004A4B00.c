#include "common.h"

/* localdecomp:start func_004A4B00 */
typedef struct { u16 pad; u16 flags; } Q_3C8E70;
extern void func_004A4B00(Q_3C8E70 *);
typedef struct { u8 pad[0x10]; u8 *base; s16 h14; s16 h16; s16 h18; s16 h1A; s16 h1C; s16 h1E; } E_3C8ED0;
extern void func_004A5220(E_3C8ED0 *, s32, u8 *);
extern void func_004A4C98(void);
extern s32 func_004A4D40(u8 *, u8 *, s32);

typedef E_3C8ED0 E_3C9078;
typedef struct { s16 n; u16 flags; u8 pad[0xC]; E_3C9078 items[1]; } S_3C9078;
extern u32 *D_001E10E8_003C9078;
extern u8 D_001422E0[];
extern s32 D_001A1ED0[];
extern void func_004A5220(E_3C9078 *, s32, u8 *);
extern void func_004A4C98(void);
extern s32 func_004A4D40(u8 *, u8 *, s32);
extern void func_004A4E38(s32, u8 *, u8 *, u8 *);
extern void func_004C1FE8(s32, unsigned long);
void func_004A4B00(Q_3C8E70 *arg) {
    S_3C9078 *q = (S_3C9078 *)arg;
    E_3C9078 *e;
    u8 *fl;
    s32 i;
    if (q->n != 0) {
        func_004A5220(q->items, q->n, (u8 *)0x70003F00);
        func_004A4C98();
        fl = (u8 *)0x70003F00;
        e = q->items;
        D_001E10E8_003C9078[0] = 0x30000007;
        D_001E10E8_003C9078[1] = (u32)D_001422E0;
        D_001E10E8_003C9078[2] = 0;
        D_001E10E8_003C9078[3] = 0x50000007;
        D_001E10E8_003C9078 += 4;
        for (i = 0; i < q->n; i++, e++, fl++) {
            if (*fl == 0) {
                u8 *b = e->base;
                u8 *c = b + e->h1C;
                u8 *a0 = b + e->h18;
                u8 *d = b + e->h1A;
                if (func_004A4D40(a0, (u8 *)0x70000000, e->h14) == 0) {
                    func_004A4E38(q->items[i].h16, c, d, (u8 *)0x70000000);
                }
            }
        }
        func_004C1FE8(0x47, 0x3180B);
        func_004C1FE8(0x4E, ((D_001A1ED0[2] >> 13) | 0x1000000) | 0x100000000L);
    }
}
/* localdecomp:end func_004A4B00 */
