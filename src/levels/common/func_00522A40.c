#include "common.h"

typedef struct {
    f32 v[4];
} Vec4;

typedef struct {
    Vec4 a;
    Vec4 b;
    u8 pad[0x20];
} Node;

typedef struct {
    u8 pad0[0x34];
    s32 field_34;
    s32 field_38;
    u8 pad3C[0x20];
    Node *nodes;
} Vars;

typedef struct {
    u8 pad0[0x68];
    Vars *pVar;
} Moby;

extern s32 func_0019D650(void);
extern void func_00523328(Moby *, Node *);
extern void func_005C6FE0(Vec4 *, Vec4 *, s32, f32, f32);

void func_00522A40(Moby *self) {
    Vars *v = self->pVar;
    s32 t = v->field_38 + 2;
    s32 i = t - v->field_34;

    if (i < 0) i += 35;
    if (func_0019D650() % 7 == 0) {
        func_00523328(self, &v->nodes[i]);
    }
    if (func_0019D650() % 22 == 0) {
        func_005C6FE0(&v->nodes[i].a, &v->nodes[i].b, 0, -1.0f, 0.0f);
    }
}
