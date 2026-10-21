#include "common.h"

/* localdecomp:start func_003A7510 */
typedef struct {
    u8 pad0[150];
    u16 timer;
} Obj003A7510;

extern void func_003A70C8(Obj003A7510 *);
extern void func_00402498(void (*)(Obj003A7510 *), Obj003A7510 *);
extern void func_00436220(Obj003A7510 *);

void func_003A7510(Obj003A7510 *obj) {
    obj->timer++;
    func_00402498(func_003A70C8, obj);
    if (obj->timer >= 7) {
        func_00436220(obj);
    }
}
/* localdecomp:end func_003A7510 */
