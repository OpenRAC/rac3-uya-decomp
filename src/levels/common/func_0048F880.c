#include "common.h"

/* localdecomp:start func_0048F880 */
typedef struct {
    s32 w0;
    u8 b4;
    u8 pad5[3];
    void (*fn)(void);
    s32 wC;
} S_48F880e;

typedef struct {
    u8 pad0[0x1C4];
    s32 w1C4;
} S_48F880;

extern s32 D_001D8E98;
extern S_48F880e D_002EB4E8[];
extern S_48F880 *D_001D52FC;
extern void func_004A7368(s32 a0, s32 a1, s32 a2);
extern s32 func_0047C5C8(void);
extern s32 func_0049D8C8(void);
extern void func_00513758(s32 a0);
extern void func_005120B8(s32 a0);

void func_0048F880(s32 a0, s32 flags) {
    S_48F880e *e;

    if (flags & 0x40) {
        e = &D_002EB4E8[D_001D8E98];
        if (e->b4 != 0 && D_002EB4E8[D_001D8E98].fn != 0) {
            e->fn();
        } else {
            func_004A7368(5, 0, 0);
        }
    }
    if (flags & 0x910) {
        func_00513758(func_0047C5C8());
        func_005120B8(a0);
    } else if (D_001D52FC->w1C4 & 1) {
        func_00513758(func_0049D8C8());
        func_005120B8(a0);
    }
}
/* localdecomp:end func_0048F880 */
