#include "common.h"

/* localdecomp:start func_003F3660 */
typedef int s128_3F3660 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0xF4];
    u8 *unkF4;
    u8 padF8[0x100 - 0xF8];
    s32 unk100;
} S_sub_3F3660;

typedef struct {
    s128_3F3660 unk0;
    s128_3F3660 unk10;
    s128_3F3660 unk20;
    s128_3F3660 unk30;
    s128_3F3660 unk40;
    u8 *unk50;
    s32 unk54;
    u8 pad58[0x150 - 0x58];
    S_sub_3F3660 unk150;
    u8 pad254[0x2A0 - 0x254];
    s16 unk2A0;
    u8 pad2A2[0x380 - 0x2A2];
    s128_3F3660 unk380;
    s128_3F3660 unk390;
    s128_3F3660 unk3A0;
    u8 pad3B0[0x410 - 0x3B0];
    s128_3F3660 unk410;
    u8 pad420[0x454 - 0x420];
    s32 unk454;
    s32 unk458;
    u8 pad45C[0x460 - 0x45C];
} S_001E2AC0;

extern u8 *D_001DF940[2];
extern s32 D_001DF900[2];
extern S_001E2AC0 D_001E2AC0[];
extern s32 D_001D6698;
extern s32 D_001D7B88;
extern s32 D_001D7B80;

extern void func_003F3340(s32);
extern void func_003F3490(s32);
extern void func_003F3108(s32);
extern void func_003F2CC8(s32, s32);
extern void func_003F1BE0(s32);
extern void func_003F2090(s32);
extern void func_003F29F0(u8 *);
extern void func_00447748(s128_3F3660 *, s128_3F3660 *);
extern void func_003F2A98(s32, s128_3F3660 *, s32);
extern void func_003F2FA8(s32);
extern void func_003F5678(S_001E2AC0 *);
extern void func_003F1068(s32);
extern void func_0040BA90(s32 *);
extern void func_003F35A0(s32);

void func_003F3660(void) {
    s32 saved[16];
    s32 i;
    u8 *p;
    S_001E2AC0 *s;
    u8 *m;
    S_sub_3F3660 *sub;
    s32 j;
    s128_3F3660 *out;
    s32 k;

    for (j = 0; j < 16; j++) {
        p = D_001DF940[j];
        if (p != 0) {
            if (p[32] == 254) {
                D_001DF940[j] = 0;
            } else if (p[32] == 253) {
                D_001DF940[j] = 0;
            } else {
                saved[j] = *(s32 *)(p + 152);
                *(s32 *)(p + 152) = 0;
            }
        }
    }
    out = (s128_3F3660 *)D_001DF900;
    for (i = 0; i < 1; i++) {
        s = &D_001E2AC0[i];
        sub = &s->unk150;
        if (sub->unk100 == 49 && sub->unkF4 != 0) {
            *(s32 *)(sub->unkF4 + 152) = 0;
        }
        s->unk454++;
        func_003F3340(i);
        func_003F3490(i);
        func_003F3108(i);
        func_003F2CC8(i, 0);
        func_003F1BE0(i);
        m = s->unk50;
        if (s->unk458 > 0) {
            s->unk2A0 = 0;
        }
        if ((u16)(s->unk2A0 - 1) < 2) {
            func_003F2090(s->unk54);
        }
        if (s->unk2A0 == 3) {
            func_003F29F0(m);
        } else {
            s->unk0 = ((s128_3F3660 *)m)[3];
            s->unk380 = ((s128_3F3660 *)m)[0];
            s->unk390 = ((s128_3F3660 *)m)[1];
            s->unk3A0 = ((s128_3F3660 *)m)[2];
        }
        func_00447748(&s->unk380, &s->unk10);
        func_003F2A98(i, &s->unk20, 0);
        func_003F2A98(i, &s->unk30, 1);
        func_003F2A98(i, &s->unk40, 2);
        func_003F2FA8(i);
        func_003F5678(s);
        func_003F1068(i);
        __asm__ __volatile__("sq $0,%0" : "=m"(s->unk410));
        if (sub->unk100 == 49 && sub->unkF4 != 0) {
            *(s32 *)(sub->unkF4 + 152) = *(s32 *)(*(u8 **)(sub->unkF4 + 36) + 16);
        }
        *out = s->unk0;
        func_0040BA90(&s->unk458);
        out++;
    }
    if (D_001D6698 == 0) {
        D_001D7B80 = D_001D7B88;
        func_003F35A0(0);
    }
    for (k = 0; k < 16; k++) {
        p = D_001DF940[k];
        if (p != 0) {
            *(s32 *)(p + 152) = saved[k];
        }
    }
}
/* localdecomp:end func_003F3660 */
