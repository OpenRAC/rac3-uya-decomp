#include "common.h"
extern s32 D_00244E84[];
extern void func_004BBD58(void);
extern void func_004BBAF0(void);
void func_004BBAB8(void) {
    if (D_00244E84[0] == 0) {
        func_004BBD58();
    } else {
        func_004BBAF0();
    }
}
