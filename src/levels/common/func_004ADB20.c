#include "common.h"
typedef struct { u32 w0; u8 pad0[31]; u8 type; u8 pad1[12]; u32 w48; u8 pad2[28]; } Item_004ADB20;
typedef struct { Item_004ADB20 *items; s32 count; } Node_004ADB20;
typedef struct { s16 a; s16 b; } Ent_004ADB20;
extern Node_004ADB20 D_0023BD80[];
extern Ent_004ADB20 D_0023BA80[];
void func_004ADB20(void) {
    Node_004ADB20 *n = D_0023BD80;
    while (n->items != 0) {
        Item_004ADB20 *it = n->items;
        s32 cnt = n->count;
        s32 i;
        for (i = 0; i < cnt; i++) {
            Ent_004ADB20 *e = &D_0023BA80[it->type];
            if (e->a != 0) it->w0 = (it->w0 & 0xFFFFC000) | e->a;
            if (e->b != 0) it->w48 = (it->w48 & 0xFFFFC000) | e->b;
            it++;
        }
        n++;
    }
}
