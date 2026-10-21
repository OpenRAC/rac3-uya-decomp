#include "common.h"

/* localdecomp:start func_00352C58 */
typedef struct {
    void (*f0)(u8 *);
    void (*f4)(u8 *);
} Cls_00352C58;

extern Cls_00352C58 *func_00438468(s32, s32);
extern void func_00441C78(u8 *, s32, s32, s32);
extern void func_00441FB8(u8 *, s32, s32);
extern void func_004A6DF8(u8 *, s32);
extern void func_00436220(u8 *);

void func_00352C58(u8 *a0, s32 a1) {
    u8 *v = *(u8 **)(a0 + 104);
    if (*(s32 *)(v + 576) != 0) {
        Cls_00352C58 *c = func_00438468(6625, 108);
        c->f0(a0);
        if (a1 != 0) {
            c->f4(a0);
        }
    } else if (*(s32 *)(v + 1148) != 0) {
        if (a0[67] != 0) {
            func_00441C78(a0, 0, 0, 0);
        }
        func_00441FB8(a0, 18, 7);
        *(s32 *)(a0 + 152) = 0;
        *(u16 *)(a0 + 52) = (*(u16 *)(a0 + 52) | 0x41) & 0xEFFF;
        func_004A6DF8(a0, 1);
    } else {
        func_00436220(a0);
    }
}
/* localdecomp:end func_00352C58 */
