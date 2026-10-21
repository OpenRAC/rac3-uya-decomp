#include "common.h"

typedef struct Obj4CB Obj4CB;
typedef struct {
    int pad[3];
    void (*fn)(Obj4CB *, void *, float *, float *, float);
} ObjVt4CB;
struct Obj4CB {
    ObjVt4CB *vt;
};

typedef struct {
    float a;
    float pad4[2];
    float b;
    float pad10[2];
    float t;
    int dir;
    int mode;
    float speed;
    unsigned char active;
    void *cb;
    float keys[4][4];
    float times[4];
    Obj4CB *obj;
    int count;
} Anim4CB;

extern float func_004CEB08(float, float, float, float, float);
extern void func_004CB788(Anim4CB *, int);

/* localdecomp:start func_004CB7D8 */
void func_004CB7D8(Anim4CB *s, int step) {
    int i0;
    int i1;
    int j;
    int k;
    float t;
    float t2;
    int act;
    float r;

    if (!s->active) return;
    i0 = 0;
    i1 = 0;
    if (s->dir == 1) {
        t = s->t;
        if (step) t += s->speed;
        s->t = t;
        act = 1;
        if (t > 1.0f) act = 0;
        s->active = act;
        t2 = !(t > 1.0f) ? t : 1.0f;
        s->t = t2;
        for (j = 0; j < s->count; j++) {
            if (i1 + 1 < s->count && s->times[i1] <= s->t) {
                i0 = i1;
                i1 = i1 + 1;
            } else {
                break;
            }
        }
    } else {
        t = s->t;
        if (step) t -= s->speed;
        s->t = t;
        act = 1;
        if (t < 0.0f) act = 0;
        s->active = act;
        t2 = !(t < 0.0f) ? t : 0.0f;
        s->t = t2;
        i1 = s->count - 1;
        i0 = i1;
        for (k = i1; k > 0; k--) {
            if (i0 - 1 >= 0 && s->t <= s->times[i0]) {
                i1 = i0;
                i0 = i0 - 1;
            } else {
                break;
            }
        }
    }
    r = func_004CEB08((s->t - s->times[i0]) / (s->times[i1] - s->times[i0]), 0.0f, s->a, s->b, 1.0f);
    if (s->cb) {
        s->obj->vt->fn(s->obj, s->cb, s->keys[i0], s->keys[i1], r);
    }
    if (!s->active) {
        switch (s->mode) {
        case 0:
            break;
        case 1:
            func_004CB788(s, s->dir);
            break;
        case 2:
            s->dir = (s->dir != 1) ? 1 : -1;
            func_004CB788(s, s->dir);
            break;
        }
    }
}
/* localdecomp:end func_004CB7D8 */
