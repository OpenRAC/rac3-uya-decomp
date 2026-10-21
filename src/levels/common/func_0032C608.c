#include "common.h"

/* localdecomp:start func_0032C608 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t a;
    u128_t b;
    f32 f;
    u8 *owner;
    u8 pad[8];
} Ent0032C608;
extern Ent0032C608 D_00277110[];
extern void func_00437698(u8 *a0, s32 a1, u128_t *a2);
void func_0032C608(u8 *a0, u128_t *a1) {
    u128_t v;
    u8 *s0 = *(u8 **)(a0 + 104);
    Ent0032C608 *e;
    s32 p;
    s32 end;
    f32 k;
    u128_t t0;
    u128_t t1;
    func_00437698(a0, 1, &v);
    k = 120.0f;
    p = (s32)D_00277110;
    end = p + 4800;
    for (; p < end; p += 48) {
        e = (Ent0032C608 *)p;
        if (e->owner == 0) {
            *(u16 *)(s0 + 102) += 1;
            e->owner = a0;
            e->f = k;
            t0 = v;
            t1 = *a1;
            e->a = t0;
            e->b = t1;
            break;
        }
    }
}
/* localdecomp:end func_0032C608 */
