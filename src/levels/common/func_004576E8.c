#include "common.h"

/* localdecomp:start func_004576E8 */
typedef struct { u8 pad[16]; u8 sub[248 - 16]; f32 f; } S457;
extern void func_00457590(S457 *, void *, f32);
void func_004576E8(S457 *p) {
    func_00457590(p, p->sub, p->f);
}
/* localdecomp:end func_004576E8 */
