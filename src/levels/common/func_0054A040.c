#include "common.h"

typedef struct {
    float pos[3];
    char pad0C[52];
    struct { char pad[728]; short h; } *p64;
    int p68;
} Src0054A040;

typedef struct {
    char pad0[104];
    Src0054A040 *src;
} Obj0054A040;

typedef struct {
    char pad0[2];
    unsigned char flags;
    unsigned char type;
    char pad4[4];
    unsigned int w8;
    float a[3];
    float b[3];
} Msg0054A040;

extern int func_0061B008(int);

void func_0054A040(Obj0054A040 *obj, Msg0054A040 *msg)
{
    Src0054A040 *s;
    float *d;
    float *p;

    if (msg->type != 8)
        return;
    s = obj->src;
    d = msg->b;
    p = (float *)((char *)s + 32);
    d[0] = p[0];
    d[1] = p[1];
    d[2] = p[2];
    if (s->p68) {
        msg->w8 = func_0061B008(s->p68);
    } else {
        if (s->p64 && s->p64->h) {
            msg->flags |= 0x80;
        }
        msg->w8 = 0xFFFFFFFF;
    }
    {
        float *dd = msg->a;
        float *pp = s->pos;
        dd[0] = pp[0];
        dd[1] = pp[1];
        dd[2] = pp[2];
    }
}
