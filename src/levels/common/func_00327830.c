#include "common.h"

/* localdecomp:start func_00327830 */
extern u8 *func_003252E8(void);
extern s32 func_00328AA8(u8 *);
extern s32 func_00328EE0(u8 *);
extern s32 *func_00494DD0(s32);
extern char *func_004950A8(s32 *, s32, s32);
extern void func_00495108(s32 *, s32, s32);
extern char *func_004181A0(s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern char D_001DCA58[];
extern char D_001DCA60[];

void func_00327830(void) {
    u8 *obj;
    u8 *vars;
    s32 i;
    char *buf;

    i = 0;
    obj = *(u8 **)(*(u8 **)(func_003252E8() + 104) + 4);
    while (obj != 0) {
        vars = *(u8 **)(obj + 104);
        if (func_00328AA8(obj) == 0) {
            obj = *(u8 **)(vars + 108);
            continue;
        }
        if (*(s32 *)(vars + 28) != 0) {
            buf = func_004950A8(func_00494DD0(0), 0, i);
            func_0011B2E8(buf, D_001DCA58, func_004181A0(*(s32 *)(vars + 28)));
        } else {
            func_0011B2E8(func_004950A8(func_00494DD0(0), 0, i), D_001DCA60);
        }
        if (func_00328EE0(obj) != 0) {
            func_00495108(func_00494DD0(0), i, 4);
        } else {
            func_00495108(func_00494DD0(0), i, 0);
        }
        obj = *(u8 **)(vars + 108);
        i++;
    }
}
/* localdecomp:end func_00327830 */
