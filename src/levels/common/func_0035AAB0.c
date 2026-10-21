#include "common.h"

/* localdecomp:start func_0035AAB0 */
typedef struct {
    s32 f0;
    s32 obj;
    s32 f8;
    s32 idA;
    s32 idB;
    s32 want;
    s32 state;
    s32 f1C;
    u8 pad20[0xC];
    s32 timer;
    u8 pad30[0x20];
    u8 items[4][0x30];
} S_35AAB0;

extern u8 *D_001DFE1C;
extern s32 D_001DF9C0;
extern s32 func_004626E8(void *);
extern s32 func_0041C368(void *);
extern s32 func_003782E0(s32);
extern void func_003782F0(s32);
extern void func_003782C8(s32);
extern void func_00359558(void *, void *);

s32 func_0035AAB0(void *unused, S_35AAB0 *s) {
    s32 on;
    s32 neg;
    s32 a;
    s32 i;
    u8 *item;
    u8 *ent;

    neg = -1;
    if (s->idA != neg || s->idB != neg) {
        on = 1;
        if (s->idA != neg) {
            if (func_004626E8(D_001DFE1C + (s->idA << 8)) == 0) {
                on = 0;
            }
        }
        a = s->idB;
        if (a != neg) {
            if (func_004626E8(D_001DFE1C + (a << 8)) == 0) {
                on = 0;
            }
        }
        if (on == s->want) {
            if (s->state != 0) {
                if (s->timer == 0) {
                    s->timer = 30;
                }
                if (func_0041C368(&s->timer) != 0) {
                    if (s->obj != 0) {
                        if (func_003782E0(s->obj) != 0) {
                            func_003782F0(s->obj);
                            s->obj = 0;
                        } else {
                            func_003782C8(s->obj);
                        }
                    }
                    item = s->items[0];
                    ent = (u8 *)s + 0x110;
                    i = 3;
                    do {
                        if (*(s32 *)(ent + 4) < D_001DF9C0) {
                            func_00359558(item, ent);
                        }
                        i--;
                        item += 0x30;
                        ent += 0x10;
                    } while (i >= 0);
                    s->state = 0;
                }
            } else {
                s->timer = 0;
                if (s->obj != 0 && func_003782E0(s->obj) != 0) {
                    func_003782F0(s->obj);
                    s->obj = 0;
                }
            }
        } else if (s->state == 0) {
            if (s->timer == 0) {
                s->timer = 30;
            }
            if (func_0041C368(&s->timer) != 0) {
                s->state = 1;
            }
        } else {
            s->timer = 0;
        }
        if (s->f1C != 0 && s->state != s->want) {
            s->idA = -1;
            s->idB = -1;
        }
    }
    return s->state;
}
/* localdecomp:end func_0035AAB0 */
