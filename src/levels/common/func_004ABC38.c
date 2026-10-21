#include "common.h"

/* localdecomp:start func_004ABC38 */
extern void func_004ABC38(void);

typedef struct { u8 pad[6]; u8 f6; u8 pad7[5]; u8 fC; u8 padD[0x48 - 0xD]; void *f48[1]; } T_3A1870;
typedef struct { u8 pad[0x10]; u8 n; u8 pad11[0xB]; s32 a[1]; } E_3A1870;
typedef struct {
    u8 pad[0x24]; T_3A1870 *f24; u8 pad28[0x32 - 0x28]; s16 f32; u16 f34; u8 pad36[2];
    long f38; u8 pad40[2]; u8 f42; u8 f43; u8 pad44[0x62 - 0x44]; u8 f62; u8 f63; u8 pad64[4];
    u8 *f68; u8 pad6C[0x98 - 0x6C]; s32 f98; u8 pad9C[0xAA - 0x9C]; s16 fAA;
} O_3A1870;
typedef struct {
    u8 pad[0x38]; s32 f38; u8 pad3C[4]; s16 f40; u8 pad42[2]; s16 f44; u8 pad46[2]; s16 f48;
    u8 pad4A[0x54 - 0x4A]; O_3A1870 *f54; u8 pad58[0x64 - 0x58]; u8 *f64; u8 *f68; s32 f6C;
    u8 pad70[0x1A0 - 0x70]; O_3A1870 *f1A0[1];
} S_225780_3A1870;
extern S_225780_3A1870 D_001E6E00_003A1870;
extern O_3A1870 *D_001DF9CC;
extern void func_0011F0A0(s32);
extern void func_00433EA0(u8 *, u32);
extern void func_00435F98(O_3A1870 *, s32);
extern O_3A1870 *func_00435E70_003A1870(s32, s32);
void func_004ABC38(void) {
    s32 i;
    u8 *data;
    s32 *offs;
    u8 *e;
    u8 *q;
    s32 kind;
    O_3A1870 *o;
    s32 n;
    s32 j;
    func_0011F0A0(0);
    func_00433EA0((u8 *)D_001E6E00_003A1870.f6C, (u32)D_001E6E00_003A1870.f68);
    func_0011F0A0(0);
    data = D_001E6E00_003A1870.f68;
    D_001E6E00_003A1870.f38 = 0;
    offs = (s32 *)(data + 0x14);
    D_001E6E00_003A1870.f40 = *(u16 *)(data + 0);
    D_001E6E00_003A1870.f48 = *(u16 *)(data + 8);
    D_001E6E00_003A1870.f44 = *(u16 *)(data + 0xC);
    D_001E6E00_003A1870.f64 = data + *(s32 *)(data + 0x10);
    for (i = 0; i < D_001E6E00_003A1870.f44; i++) {
        e = data + *offs++;
        kind = *(s32 *)e;
        e += 0xC;
        o = D_001E6E00_003A1870.f1A0[i];
        q = data + *(s32 *)e;
        e += 4;
        if (kind == 0x215) kind = 0xD54;
        if (o == 0) {
            if (kind == 0) {
                o = D_001DF9CC;
                func_00435F98(o, 0);
            } else {
                o = func_00435E70_003A1870(kind, 0x80);
            }
            o->f32 = 0x1FF;
            o->f34 |= 6;
            o->f62 = 0xFF;
            o->f38 = 0x20202000000000UL;
            o->f98 = 0;
            if (o->f24->f6 != 0) {
                if (o->fAA == 0xD54) o->f63 = 0;
                else o->f63 = 8;
            }
            n = o->f24->fC;
            o->f24->fC = n + 1;
            o->f42 = n;
            o->f43 = n;
            D_001E6E00_003A1870.f1A0[i] = o;
            if (o->fAA == 0xD54) D_001E6E00_003A1870.f54 = o;
        }
        o->f68 = q;
        o->f24->f48[o->f42] = e;
        for (j = 0; j < ((E_3A1870 *)e)->n; j++) {
            ((E_3A1870 *)e)->a[j] = (s32)(e + ((E_3A1870 *)e)->a[j]);
        }
    }
}
/* localdecomp:end func_004ABC38 */
