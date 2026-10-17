#include "common.h"

typedef struct {
    void (*fn0)(void *);
} Iface;

typedef struct {
    char pad0[0x30];
    int timer;
    char pad34[0x3E - 0x34];
    unsigned char b62;
    char pad3F[0x40 - 0x3F];
    float f64;
} Vars;

typedef struct {
    char pad0[0x30];
    unsigned char b48;
    char pad31[0x32 - 0x31];
    short h50;
} Obj;

extern Iface *func_004395A8(int, int);
extern void func_004430D8(Obj *, int, int);

void func_003D5590(Obj *obj, Vars *v) {
    Iface *it;

    obj->b48 = 255;
    obj->h50 = 511;
    v->f64 = 1.0f;
    if (v->timer > 0) {
        it = func_004395A8(6625, 108);
        v->timer = -1;
        v->b62 = 2;
        it->fn0(obj);
    } else {
        func_004430D8(obj, 1, -1);
    }
}
