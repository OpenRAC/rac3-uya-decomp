#include "common.h"

/* localdecomp:start func_0045C990 */
extern s32 func_0045C990();

typedef struct { u8 b[4]; } B4_0039D5F8;
extern B4_0039D5F8 D_001CD010[];
extern u8 D_001D52E0;
extern s32 D_001D4D00;
extern s32 D_001D4D04;
extern void func_0013CD28();
extern void func_0013CA28();
extern void func_0013B620();
s32 func_0045C990(s32 a, s32 b, s32 c) {
    B4_0039D5F8 buf;
    buf = D_001CD010[0];
    buf.b[1] = D_001D52E0;
    D_001D4D00 = 0;
    D_001D4D04 = 0;
    func_0013CD28(b, c, a, &buf);
    func_0013CA28();
    func_0013B620();
    return 1;
}
/* localdecomp:end func_0045C990 */
