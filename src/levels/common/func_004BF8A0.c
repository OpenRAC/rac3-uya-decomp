#include "common.h"

typedef struct {
    s32 w0;
    u8 b4;
    u8 pad5[15];
} E_004BF8A0;

typedef struct {
    u8 pad0[92];
    s32 w92;
    u8 pad96[32];
    s32 w128;
    s32 w132;
    u8 pad136[184];
    E_004BF8A0 e[1];
} G_004BF8A0;

typedef struct {
    u8 pad0[132];
    u16 h132;
    u16 h134;
    u8 pad136[104];
} M_004BF8A0;

extern G_004BF8A0 D_00244740;
extern char D_0024DF50[];
extern char D_001DAE58[];
extern s32 D_001E1014;
extern char D_001E1088[8];
extern char D_001E1089;
extern u8 D_001425C0[];
extern M_004BF8A0 D_002C5640[];
extern s32 D_00142660[];
extern char *func_004181A0(s32);
extern void func_00512FE8(s32, char *);
extern void func_00512828(s32, f32);
extern void func_00512480(s32, f32, f32);
extern void func_00514680(s32, s32, s32);
extern s32 func_00512AB0(s32, s32, s32);
extern void func_0011B2E8(char *, char *, char *, s32);
extern void func_004BB0F0(char *, s32);
extern s32 func_0011B868(char *);
extern void func_00512ED8(s32, f32 *, f32 *, f32 *, f32 *);
extern s32 func_004B6C98(void);

void func_004BF8A0(void)
{
    f32 v[2];
    s32 i;

    if (D_00244740.w132 == 0) {
        func_00512FE8(0x480029, func_004181A0(2252));
        func_00512FE8(0x48002A, func_004181A0(256));
        func_00512828(0x480026, 1.0f);
        func_00512480(0x480026, 0.3025f, 0.325f);
        func_00514680(0x480026, 0, 0);
        func_00512AB0(0x48002D, 1, 0);
        func_00512AB0(0x480022, 1, 0);
        return;
    }
    if (D_00244740.e[D_00244740.w128].b4 == 1) {
        func_0011B2E8(D_0024DF50, D_001DAE58, func_004181A0(2254), D_001E1014);
        func_00512FE8(0x480026, D_0024DF50);
        func_00512828(0x480026, 1.0f);
        func_00514680(0x480026, 1, 1);
        func_00512480(0x480026, 0.3f, 0.27f);
        func_00512FE8(0x48002A, func_004181A0(2251));
        func_00512AB0(0x48002D, 1, 1);
        func_00512AB0(0x480022, 1, 1);
        if (D_00244740.w92 == 0) {
            func_004BB0F0(D_001E1088, D_001E1014 * ((M_004BF8A0 *)((u8 *)D_002C5640 + D_001425C0[D_00244740.e[D_00244740.w128].w0] * 240))->h132);
        } else {
            func_004BB0F0(D_001E1088, D_001E1014 * ((M_004BF8A0 *)((u8 *)D_002C5640 + D_001425C0[D_00244740.e[D_00244740.w128].w0] * 240))->h134);
        }
        for (i = func_0011B868(D_001E1088); i >= 0; i--) {
            D_001E1088[i + 2] = D_001E1088[i];
        }
        D_001E1089 = ' ';
        D_001E1088[0] = ' ';
        func_00512ED8(0x48002D, &v[0], &v[1], &v[1], &v[1]);
        func_00512480(0x480022, v[0], 0.33f);
    } else if (func_004B6C98() <= D_00142660[0]) {
        func_00512FE8(0x480026, func_004181A0(2256));
        func_00512828(0x480026, 1.0f);
        func_00514680(0x480026, 1, 1);
        func_00512480(0x480026, 0.3f, 0.25f);
        func_00512FE8(0x480029, func_004181A0(2274));
        func_00512FE8(0x48002A, func_004181A0(2271));
        func_00512AB0(0x48002D, 1, 0);
        func_00512AB0(0x480022, 1, 0);
    }
}
