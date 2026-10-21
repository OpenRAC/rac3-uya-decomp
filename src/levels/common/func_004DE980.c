#include "common.h"

/* localdecomp:start func_004DE980 */
typedef struct {
    u8 pad[0x1200];
    u8 *a;
    u8 *b;
    u8 *c;
} E_4DE980;

typedef struct {
    u8 pad[0x25C0];
    u8 *src;
} S_4DE980;

extern S_4DE980 D_001A4BE0;

void func_004DE980(void) {
    S_4DE980 *s;
    E_4DE980 *e;
    s32 j;
    s32 i;
    u8 *x;

    s = &D_001A4BE0;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 3; j++) {
            e = (E_4DE980 *)((u8 *)s + i * 80);
            x = e->a;
            if (j == 1) {
                x = e->b;
            } else if (j == 2) {
                x = e->c;
            }
            if (x != 0) {
                *(unsigned long *)(x + 56) = *(unsigned long *)(s->src + 56);
            }
        }
    }
}
/* localdecomp:end func_004DE980 */
