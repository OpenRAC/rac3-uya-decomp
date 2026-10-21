#include "common.h"

typedef struct {
    u8 pad0[0x1C4];
    s32 f1C4;
} P_4840D0;

typedef struct {
    u8 pad0[8];
    s32 f8;
    u8 pad[0xF0 - 0xC];
} E_4840D0;

extern P_4840D0 *D_001D52FC[] __attribute__((section(".sdata")));
extern u8 D_001D672C[] __attribute__((section(".sdata")));
extern s32 D_001D8718;
extern s32 D_001D871C;
extern s32 D_001D8720[1];
extern s16 D_001A7464[];
extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern E_4840D0 D_002C5640[];
extern void func_0047B428(void);
extern void func_00483FE0(void);
extern void func_0047B920(void);
extern void func_0047B8E0(s32);
extern void func_00483E10(void);
extern s32 func_0047B380(void);
extern void func_004A7368(s32, s32, s32);
extern s32 func_0047C5C8(void);
extern void func_005130C8(s32, s32);
extern s32 func_00483CA8(s32, s32);
extern s32 func_00483CC8(s32, s32);
extern s32 func_0047A310(s32);
extern void func_0047B3D8(s32);
extern s32 func_00483120(void);
extern s32 func_00486758(void);
extern void func_00513758(s32);
extern void func_005120B8(s32);
extern void func_0047B550(s32, s32);
extern void func_00483D98(void);
extern void func_00512D70(s32, s32);
extern void func_00484070(void);
extern s32 func_0047A250(void);
extern void func_0047A268(void);

/* localdecomp:start func_004840D0 */
void func_004840D0(s32 arg) {
    s32 pad;
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s32 avail;

    func_0047B428();
    func_00483FE0();
    func_0047B920();
    func_0047B8E0(0xF0002);
    func_00483E10();
    pad = D_001D52FC[0]->f1C4;
    if (pad & 0x800) {
        func_00513758(func_0047B380());
        func_005120B8(arg);
    } else if (pad & 0x10) {
        func_004A7368(4, 0, 0);
        func_00513758(func_0047C5C8());
        func_005120B8(arg);
    } else if (pad & 0x1000) {
        func_004A7368(3, 0, 0);
        if (D_001D8718 == 4 && D_001D871C == 0) {
            D_001D871C = 1;
            D_001D8718 = 3;
        } else {
            D_001D871C = (D_001D871C + 1) % 2;
        }
        func_005130C8(0xF0002, 0x402299DE);
    } else if (pad & 0x4000) {
        func_004A7368(3, 0, 0);
        if (D_001D8718 == 4 && D_001D871C == 0) {
            D_001D871C = 1;
            D_001D8718 = 3;
        } else {
            D_001D871C = (D_001D871C + 1) % 2;
        }
        func_005130C8(0xF0002, 0x402299DE);
    } else if (pad & 0x8000) {
        func_004A7368(3, 0, 0);
        b = D_001D871C;
        if (b > 0) {
            D_001D8718 = (D_001D8718 + 3) % 4;
        } else {
            D_001D8718 = (D_001D8718 + 4) % 5;
        }
        func_005130C8(0xF0002, 0x402299DE);
    } else if (pad & 0x2000) {
        func_004A7368(3, 0, 0);
        b = D_001D871C;
        if (b > 0) {
            D_001D8718 = (D_001D8718 + 1) % 4;
        } else {
            D_001D8718 = (D_001D8718 + 1) % 5;
        }
        func_005130C8(0xF0002, 0x402299DE);
    } else if (pad & 0x40) {
        s32 k = func_00483CA8(D_001D8718, D_001D871C);
        a = D_00142CA0[k] && !(k == 2 || k == 3);
        b = (k == 2 || k == 3) && D_001A7464[0] == 0;
        if (a | b) {
            s32 sel;
            E_4840D0 *e;
            func_004A7368(4, 0, 0);
            sel = func_00483CA8(D_001D8718, D_001D871C);
            e = &D_002C5640[D_001425C0[sel]];
            if (e->f8 == 1 && func_0047A310(1) == sel) {
                func_0047B3D8(28);
            } else {
                func_0047B3D8(sel);
            }
        } else {
            func_004A7368(5, 0, 0);
        }
    } else if (pad & 0x1) {
        func_004A7368(4, 0, 0);
        func_00513758(func_00483120());
        func_005120B8(arg);
    } else if (pad & 0x2) {
        func_004A7368(4, 0, 0);
        func_00513758(func_00486758());
        func_005120B8(arg);
    }
    func_0047B550(func_00483CA8(D_001D8718, D_001D871C), D_001D52FC[0]->f1C4);
    func_00483D98();
    for (i = 0; i < 9; i++) {
        avail = 1;
        for (j = 0; avail && j < 4; j++) {
            if (func_0047A310(j) == D_001D8720[i]) avail = 0;
        }
        if (avail) {
            func_005130C8(i + 0xF001B, 0x8066CCFF);
            func_00512D70(i + 0xF0026, 0);
        } else {
            func_00512D70(i + 0xF0026, 1);
        }
    }
    func_005130C8(func_00483CC8(D_001D8718, D_001D871C) + 0xF001B, 0x80FFFFFF);
    func_00484070();
    if (func_0047A250()) {
        func_0047A268();
        func_005120B8(arg);
        if (D_001D672C[0] == 0) {
            func_00513758(func_0047B380());
        }
    }
}
/* localdecomp:end func_004840D0 */
