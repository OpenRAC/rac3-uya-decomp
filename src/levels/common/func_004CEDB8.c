#include "common.h"

/* localdecomp:start func_004CEDB8 */
extern s32 D_001E1238_003AA2E8;
extern s32 D_001E1264_003AA2E8;
extern s32 D_001E1268_003AA2E8;
extern s32 D_001D4D40;
extern s32 func_004CEDB8();

typedef struct { u8 p0[0x1A0]; s32 f1A0; s32 f1A4; } P_3AA4B0;
extern P_3AA4B0 *D_001D52FC_003AA4B0;
extern s32 D_001D4D40;
extern volatile s32 D_001E127C; /* volatile: retail keeps every access out of delay slots (lui, not $gp) */
extern s32 D_001E1238_003AA2E8;
extern s32 D_001E1264_003AA2E8;
extern s32 D_001E1268_003AA2E8;
extern void func_0045E370(void);
extern void func_004CF490();
extern void func_004D1980(void *);
extern s32 func_004D0688(u8 *, void **);
extern s32 func_004D07A0();
extern void func_004D06B8(u8 *, s32);
extern void func_004CF0E8(void);
extern s32 func_004D06F8(u8 *, u8 **);
extern s32 func_00139A70(void *, u8 *, s32, u8 *, s32);
extern s32 func_004D0738();
extern void func_004CF3A8(void);
extern s32 func_004D1FC8(void *);
extern s32 func_004CF108_003AA4B0(void); /* defined void, but returns func_003AAE00's result */
extern void func_004D02F0(s32);
extern s32 func_004D1990(void *);
extern s32 func_004D1A10();
extern s32 func_004D1AE0(void *);
extern void func_004D0340(void);
extern void func_004CF530(s32 *);
s32 func_004CEDB8(void *a, u8 *b, s32 *c) {
    void *rd;
    u8 *wr;
    s32 started;
    s32 done;
    s32 left;
    s32 sent;
    s32 armed;
    s32 go;
    s32 flags;
    s32 n;
    s32 k;
    s32 m;

    done = 0;
    armed = 0;
    go = 0;
    left = *c;
    started = 0;
    sent = left;
    D_001E127C = 0;
    while (left >= 5 && func_004D1990(a) != 3) {
        func_0045E370();
        flags = 0;
        if (D_001D52FC_003AA4B0->f1A0 == 0 && done && go) armed = 1;
        if (armed && !(D_001D4D40 & 0x80)) {
            s32 st = D_001D4D40 & ~0xC0;
            if (st != 2) {
                if (st == 0 && D_001D52FC_003AA4B0->f1A0 != 0 && D_001D52FC_003AA4B0->f1A4 == 0) flags = 1;
                else if (D_001D52FC_003AA4B0->f1A4 & 0x800) flags = 1;
            }
        }
        if (!done && D_001E127C >= 10) {
            done = 1;
            func_004CF490(D_001E1268_003AA2E8);
        }
        if (flags && !started) {
            started = 1;
            func_004D1980((void *)D_001E1264_003AA2E8);
        }
        if (!done && D_001E127C >= 10) {
            done = 1;
            func_004CF490(D_001E1268_003AA2E8);
        }
        n = func_004D0688(b, &rd);
        if (sent > 0 && n > 0xFFFF) {
            m = func_004D07A0(c, rd, 0x10000);
            sent -= m;
            func_004D06B8(b, m);
        }
        func_004CF0E8();
        if (!done && D_001E127C >= 10) {
            done = 1;
            func_004CF490(D_001E1268_003AA2E8);
        }
        k = func_004D06F8(b, &wr);
        if (k > 0) {
            m = func_00139A70(a, wr, k, b, *(s32 *)(b + 0x50008));
            left -= m;
            func_004D0738(b, m);
        }
        func_004CF3A8();
        if (!done && D_001E127C >= 10) {
            done = 1;
            func_004CF490(D_001E1268_003AA2E8);
        }
        if (!go && func_004D1FC8((void *)D_001E1238_003AA2E8) && func_004CF108_003AA4B0()) {
            func_004D02F0(1);
            go = 1;
        }
    }
    while (func_004D1A10(a) == 0) {
        func_004CF3A8();
        func_004CF0E8();
    }
    while (func_004D1AE0(a) == 0 && func_004D1990(a) != 3) {
        func_004CF3A8();
        func_004CF0E8();
    }
    func_004D0340();
    func_004CF530((s32 *)D_001E1268_003AA2E8);
    return started;
}
/* localdecomp:end func_004CEDB8 */
