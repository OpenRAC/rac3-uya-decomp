#include "common.h"

/* localdecomp:start func_0045CA60 */
extern void func_0045C240();
extern void func_0013CA28(void);
extern s32 func_0045CA60(s32);

typedef struct { u8 pad[4]; s16 s; u8 pad2[0x10]; } S_39D6C8;
extern S_39D6C8 D_001CCFD0_0039D6C8;
extern void func_0045C240();
extern void func_0013CA28();
extern s32 func_0013B620(void);
extern void func_0013CA20();
extern void func_0040BB80();
s32 func_0045CA60(s32 a) {
    if (a) {
        do {
            func_0045C240();
            func_0013CA28();
            func_0013B620();
            func_0013CA20();
            if (D_001CCFD0_0039D6C8.s == 0) break;
            func_0040BB80(0x2710);
        } while (D_001CCFD0_0039D6C8.s != 0);
    } else {
        func_0045C240();
        func_0013CA28();
        func_0013B620();
        func_0013CA20();
    }
    return D_001CCFD0_0039D6C8.s;
}
/* localdecomp:end func_0045CA60 */
