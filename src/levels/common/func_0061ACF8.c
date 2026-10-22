#include "common.h"

/* localdecomp:start func_0061ACF8 */
typedef struct VT_61ACF8 {
    void *f0;
    void *f4;
    void (*init)(struct O_61ACF8 *);
} VT_61ACF8;

typedef struct O_61ACF8 {
    u32 id;
    s32 owner;
    s32 active;
    struct O_61ACF8 *next;
    struct O_61ACF8 *prev;
    VT_61ACF8 *vt;
} O_61ACF8;

extern O_61ACF8 *D_0024CF40[8];
extern O_61ACF8 *D_0024CF60[8];
extern s32 D_0024D85C;
extern void func_0061BA40(O_61ACF8 *, s32);

O_61ACF8 *func_0061ACF8(u32 id, s32 owner) {
    u32 k;
    O_61ACF8 **used;
    O_61ACF8 **freel;
    O_61ACF8 *o;
    O_61ACF8 *n;

    k = (id >> 24) & 0xF;
    freel = &D_0024CF60[k];
    used = &D_0024CF40[k];
    o = *freel;

    if (o != 0) {
        n = o->next;
        *freel = n;
        n->prev = 0;
        o->prev = 0;
        o->next = *used;
        if (*used != 0) {
            (*used)->prev = o;
        }
        *used = o;
        o->active = 1;
        o->id = id;
        o->owner = owner;
        o->vt->init(o);
        if (D_0024D85C != -1 && owner == D_0024D85C) {
            func_0061BA40(o, 1);
        }
        return o;
    }
    return 0;
}
/* localdecomp:end func_0061ACF8 */
