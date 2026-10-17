#include "common.h"

typedef struct {
    char pad0[0x34];
    unsigned short h34;
} Unk66A0F0Obj;

typedef struct {
    char pad0[0x18];
    Unk66A0F0Obj *obj;
    unsigned short h1C;
    int w20;
    char pad24[0x8];
    unsigned char b2C;
} Unk66A0F0;

extern Unk66A0F0 *func_0061ACF8(int, int);
extern Unk66A0F0Obj *func_005A8280(int, int);
extern void func_005BC388(Unk66A0F0Obj *, int);
extern int *func_005BF058(Unk66A0F0Obj *);
extern void func_0061B080(Unk66A0F0 *, Unk66A0F0Obj *);

Unk66A0F0 *func_0066A0F0(int a0, int a1, int a2, int a3) {
    Unk66A0F0 *s = func_0061ACF8(a1, -1);
    if (s != 0) {
        s->obj = func_005A8280(a0, 128);
        func_005BC388(s->obj, a2);
        s->h1C = s->obj->h34;
        s->w20 = func_005BF058(s->obj)[2];
        func_0061B080(s, s->obj);
        s->b2C = a3;
    }
    return s;
}
