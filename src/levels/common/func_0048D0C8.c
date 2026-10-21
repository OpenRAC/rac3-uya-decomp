#include "common.h"

/* localdecomp:start func_0048D0C8 */
typedef struct {
    s32 w0;
    void (*fn)(u32);
    s32 w8;
} E_0048D0C8;

extern s32 D_001D8D94;
extern u8 D_001D672C;
extern E_0048D0C8 D_002EB078[];
extern void func_004A7368(s32, s32, s32);
extern void *func_00513698(void);
extern void *func_0048DCD8(void *);
extern void *func_0047B380(void);
extern void func_00513758(void *);
extern void func_005120B8(void *);

void func_0048D0C8(void *a0, u32 a1) {
    if (a1 & 0xA040) {
        if (D_002EB078[D_001D8D94].fn != 0) {
            (D_001D8D94)[D_002EB078].fn(a1);
        }
    } else if (a1 & 0x10) {
        func_004A7368(4, 0, 0);
        func_00513758(func_0048DCD8(func_00513698()));
        func_005120B8(a0);
    } else if (a1 & 0x900) {
        if (D_001D672C == 0) {
            func_004A7368(4, 0, 0);
            func_00513758(func_0047B380());
            func_005120B8(a0);
        }
    }
}
/* localdecomp:end func_0048D0C8 */
