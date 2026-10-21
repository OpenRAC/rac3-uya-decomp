#include "common.h"

/* localdecomp:start func_002F9858 */
typedef struct {
    u8 pad[20];
    s32 f20;
} Vars_002F9858;

extern void func_002F9F48(void *);
extern void func_002F9B30(void *);
extern f32 func_0040CEC8(f32, f32);
extern void func_002F9A40(void *);
extern void func_004C6EC8(void *, void *);
extern void func_004C6FD8(void *, void *);
extern void func_002FB230(void *);

void func_002F9858(u8 *obj) {
    Vars_002F9858 *v = *(Vars_002F9858 **)(obj + 104);

    switch (obj[32]) {
    case 0:
        if (v->f20 != 0) {
            func_002F9F48(obj);
        } else {
            func_002F9B30(obj);
        }
        *(f32 *)(obj + 240) = func_0040CEC8(*(f32 *)(obj + 240), 0.034906588f);
        *(f32 *)(obj + 244) = func_0040CEC8(*(f32 *)(obj + 244), 0.13089970f);
        func_002F9A40(obj);
        break;
    case 1:
        func_004C6EC8(obj + 16, obj + 16);
        func_004C6FD8(v, v);
        func_002FB230(obj);
        break;
    }
}
/* localdecomp:end func_002F9858 */
