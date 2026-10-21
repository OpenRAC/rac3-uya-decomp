#include "common.h"

/* localdecomp:start func_00466558 */
typedef struct { u8 pad[0xA]; s16 h; } S_466558;
extern s32 func_0040BAC0(s16 *);
extern void func_0045E580(S_466558 *);

void func_00466558(S_466558 *p) {
    if (p->h != -1 && func_0040BAC0(&p->h) != 0) {
        func_0045E580(p);
    }
}
/* localdecomp:end func_00466558 */
