#include "common.h"

/* localdecomp:start func_00365518 */
typedef int Q_00365518 __attribute__((mode(TI)));
extern f32 func_0041C8C0(void *, void *);
extern void func_00451098(void *, s32, s32, s32);
extern void func_004513D8(void *, s32, s32);
extern s32 func_00462650(void *);
extern void func_00465410(void *, void *, s32, s32);
extern void func_00465650(void *, Q_00365518 *, void *);
extern void func_00466BC8(void *, void *);
extern void func_00468218(void *, f32, f32, f32, f32);

s32 func_00365518(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    Q_00365518 t;
    if (func_00462650(o) != 0) {
        if (o[0x43] != 2) {
            func_00451098(o, 2, 0, 10);
        }
        func_00468218(o, 0.0016666667f, 0.033333335f, 0.0069813174f, 0.20943953f);
        t = *(Q_00365518 *)(v + 0x490);
        func_00465650(o, &t, v + 0x410);
    }
    if (*(s32 *)(v + 0x4E4) == 0) {
        func_00465410(o, v + 0x410, 0, 0);
        func_00466BC8(o, v + 0x410);
    }
    if (func_0041C8C0(o + 0x10, v + 0x490) < 0.5f) {
        func_004513D8(o, 8, -1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00365518 */
