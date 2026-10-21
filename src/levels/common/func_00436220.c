#include "common.h"

/* localdecomp:start func_00436220 */
typedef struct {
    u8 pad[32];
    u8 b20;
    u8 pad2[51];
    s32 f54;
    u8 pad3[16];
    s32 f68;
    u8 pad4[52];
    s32 fA0;
} Obj_00436220;

extern u32 D_001E00A0;
extern s32 D_001E00B0;
extern s32 D_001E00B4;
extern s32 D_001DFBC0;
extern void func_00438E58(s32);
extern void func_004373D8(Obj_00436220 *, s32);
extern void func_00439330(Obj_00436220 *, u32);

void func_00436220(Obj_00436220 *obj) {
    if ((u32)obj < D_001E00A0) {
        obj->b20 = 253;
    } else {
        obj->b20 = 254;
        if (obj->f68 != 0) {
            if (obj->f68 >= D_001E00B0 && obj->f68 < D_001E00B0 + D_001E00B4 * 64) {
                func_00438E58(obj->f68);
                obj->f68 = 0;
            }
        }
        while (obj->f54 != 0) {
            func_004373D8(obj, obj->f54);
        }
    }
    obj->fA0 = D_001DFBC0 + 2;
    func_00439330(obj, 0x80807F7F);
}
/* localdecomp:end func_00436220 */
