#include "common.h"

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Ent_00669050;

extern s32 D_001DAB38;
extern Ent_00669050 D_00343290[30];

void func_00669050(void) {
    Ent_00669050 *p;

    if (D_001DAB38 == 0) {
        p = D_00343290;
        do {
            p->a = -1;
            p->b = -1;
            p->c = -1;
            p++;
        } while ((s32)p < (s32)&D_00343290[30]);
        D_001DAB38 = 1;
    }
}
