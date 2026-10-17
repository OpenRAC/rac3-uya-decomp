#include "common.h"

typedef struct {
    u8 pad[0x68];
    u8 *w68;
} Moby_0039FAB0;

extern void func_00346CF8(void *);
extern void func_0040CD60(Moby_0039FAB0 *);

void func_0039FAB0(Moby_0039FAB0 *m) {
    u8 *p = m->w68;
    if (*(s32 *)(p + 60)) func_00346CF8(p + 84);
    func_0040CD60(m);
}
