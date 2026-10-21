#include "common.h"

/* localdecomp:start func_003CA050 */
typedef struct {
    char pad0[1360];
    void *other;
} Data003CA050;

typedef struct {
    char pad0[16];
    f32 pos[4];
    char pad20[72];
    Data003CA050 *data;
    char pad6C[132];
    f32 col[4];
} Moby003CA050;

extern void func_00407180(void *, f32 *, f32 *, int, int, int, int, int, int, int);
extern void func_00437698(Moby003CA050 *, int, f32 *);

void func_003CA050(Moby003CA050 *m)
{
    f32 v[4] __attribute__((aligned(16)));
    Data003CA050 *d = m->data;

    func_00407180(m, m->pos, m->col, 0, 2, 3, 45, 45, 0xFF8040, 0x8F1010);
    if (d->other) {
        func_00437698(m, 0, v);
        func_00407180(d->other, v, m->col, 0, 2, 3, 45, 45, 0xFF8040, 0x8F1010);
    }
}
/* localdecomp:end func_003CA050 */
