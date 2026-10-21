#include "common.h"

/* localdecomp:start func_00486438 */
extern void *func_00484990(s32);
extern void *func_004849C0(s32);
extern void func_005130C8(void *, s32);
void func_00486438(s32 a0, s32 a1, s32 a2, s32 a3) {
    switch (a0) {
    case 0:
        func_005130C8(func_00484990(0x190039), a3);
        break;
    case 1:
        func_005130C8(func_004849C0(0x190069), a3);
        break;
    }
}
/* localdecomp:end func_00486438 */
