#include "common.h"

/* localdecomp:start func_00326E30 */
typedef struct {
    char pad[8];
    int (*func)(void *);
} Fn326E30;

extern void *func_003252E8(void);
extern void *func_00445F18(void *);

int func_00326E30(void) {
    int i;
    char *base;
    void *p;
    void *q;
    Fn326E30 *f;

    base = (char *)(*(int *)((char *)func_003252E8() + 104) + 352);
    for (i = 0; i < 16; i++, base += 4) {
        q = *(void **)(base + 320);
        if (q == 0) continue;
        p = q;
        if (*(void **)((char *)q + 36) == 0) continue;
        if (*(unsigned char *)(*(char **)((char *)q + 36) + 70) != 5) continue;
        f = *(Fn326E30 **)base;
        do {
            if (!f->func(p)) return 1;
            p = *(void **)((char *)func_00445F18(p) + 4);
        } while (p);
    }
    return 0;
}
/* localdecomp:end func_00326E30 */
