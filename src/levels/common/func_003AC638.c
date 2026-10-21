#include "common.h"

/* localdecomp:start func_003AC638 */
typedef int s128_3AC638 __attribute__((mode(TI)));

#define W(p, o) (*(int *)((p) + (o)))
#define F(p, o) (*(f32 *)((p) + (o)))
#define Q(p, o) (*(s128_3AC638 *)((p) + (o)))

typedef struct { u8 pad[3184]; int a[4]; int b[4]; int c[4]; int d[4]; int e[4]; int f[4]; int g[4]; } S_3AC638;

void func_003AC638(u8 *a, u8 *b) {
    u8 *src = *(u8 **)(b + 0x68);
    u8 *dst = *(u8 **)(a + 0x68);
    int i;

    Q(dst, 3376) = Q(src, 3376);
    Q(dst, 3392) = Q(src, 3392);
    W(dst, 96) = W(src, 96);
    W(dst, 108) = W(src, 108);
    W(dst, 3104) = W(src, 3104);
    W(dst, 3108) = W(src, 3108);
    W(dst, 3112) = W(src, 3112);
    W(dst, 3116) = W(src, 3116);
    W(dst, 3120) = W(src, 3120);
    F(dst, 3124) = F(src, 3124);
    W(dst, 3152) = W(src, 3152);
    W(dst, 3156) = W(src, 3156);
    W(dst, 3160) = W(src, 3160);
    W(dst, 3164) = W(src, 3164);
    F(dst, 3172) = F(src, 3172);
    F(dst, 3176) = F(src, 3176);
    for (i = 0; i < 4; i++) {
        ((S_3AC638 *)dst)->a[i] = ((S_3AC638 *)src)->a[i];
        ((S_3AC638 *)dst)->b[i] = ((S_3AC638 *)src)->b[i];
        ((S_3AC638 *)dst)->c[i] = -1;
        ((S_3AC638 *)dst)->d[i] = ((S_3AC638 *)src)->d[i];
        ((S_3AC638 *)dst)->e[i] = ((S_3AC638 *)src)->e[i];
        ((S_3AC638 *)dst)->f[i] = ((S_3AC638 *)src)->f[i];
        ((S_3AC638 *)dst)->g[i] = ((S_3AC638 *)src)->g[i];
    }
    W(dst, 3296) = W(src, 3296);
    W(dst, 3300) = W(src, 3300);
    W(dst, 3304) = W(src, 3304);
    F(dst, 3312) = F(src, 3312);
    W(dst, 3148) = W(src, 3148);
}
/* localdecomp:end func_003AC638 */
