#include "common.h"

typedef struct {
    u8 pad0[150];
    u16 timer;
} Obj003AE278;

/* The target split places this symbol 0x18 bytes before the callback. */
extern void func_003ADE18(void);
extern void func_0041BDF0(void (*)(Obj003AE278 *), Obj003AE278 *);
extern void func_0044F860(Obj003AE278 *);

void func_003AE278(Obj003AE278 *obj) {
    obj->timer++;
    func_0041BDF0((void (*)(Obj003AE278 *))((u8 *)func_003ADE18 + 0x18), obj);
    if (obj->timer >= 7) {
        func_0044F860(obj);
    }
}
