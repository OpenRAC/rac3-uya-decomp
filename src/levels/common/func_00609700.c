#include "common.h"
extern s32 D_0024BC40[];
extern u8 D_000FA120;
extern u8 D_000FA121;
extern s32 D_00100404;
extern s32 D_0024BAC8[];
extern s32 D_00100238;
extern s32 D_00244000[];
extern s32 D_00240408[];
extern u8 D_000FA144;
extern f32 D_000FA140;
extern s32 func_00195AE8(void);
extern void func_00609050(void);
extern void func_00609248(void);
extern void func_00586CC8(void);
extern void func_005C2050(void);
extern s32 func_00608DC8(s32);
extern void func_005863C0(void);
extern void func_00608D28(void);
extern void func_005A43D8(void);
extern void func_005A33A0(void);
extern void func_005FA780(s32);
extern s32 func_00139E08();
extern s32 func_005A23F0(void);
extern void func_005FA660(void);
extern void func_005FA5E0(void);
extern void func_00596CB8(void);
extern void func_00609AF0(void);
extern void func_00597030(s32);
extern void func_00596BA0(void);
extern void func_00596C38(s32);
extern void func_00589460(s32);
extern void func_006095C0(void);
s32 func_00609700(void) {
    s32 r;
    func_00195AE8();
    if (D_0024BC40[0] < 0) {
        func_00609050();
        return 1;
    }
    r = 0;
    func_00195AE8();
    func_00609248();
    func_00195AE8();
    D_000FA120 = 0;
    D_000FA121 = 0;
    for (;;) {
        func_005FA660();
        func_005FA5E0();
        func_00596CB8();
        if (D_000FA144 != 0) func_00609AF0();
        else func_00597030(1);
        func_00596BA0();
        func_00596C38(0);
        if (r != 0) break;
        func_00586CC8();
        func_005C2050();
        func_00195AE8();
        r = func_00608DC8(D_000FA120);
        D_00100404 = 0;
        func_005863C0();
        func_00608D28();
        func_005A43D8();
        func_005A33A0();
        func_005FA780(1);
        func_00139E08(0);
        D_00100238 = D_0024BAC8[0] + 1;
        if (D_00244000[0] == 0) D_000FA121 = func_005A23F0() != 0;
        D_000FA120 = D_00240408[0] >= 2;
    }
    func_005FA780(1);
    func_00139E08(0);
    if (D_000FA140 > 0.0f) func_00589460(2);
    func_006095C0();
    return 1;
}
