#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4EC500;
typedef struct {
    u8 pad0[128];
    V4_4EC500 v128;
    u8 pad90[240 - 144];
    V4_4EC500 v240;
    f32 f256;
    u8 pad104[296 - 260];
    f32 f296;
    u8 pad12C[608 - 300];
    V4_4EC500 v608;
    u8 pad270[644 - 624];
    f32 f644;
    u8 pad288[679 - 648];
    u8 b679;
    u8 pad2A8[752 - 680];
    V4_4EC500 v752;
    u8 pad300[824 - 768];
    f32 f824;
    f32 f828;
    u8 pad340[868 - 832];
    s32 i868;
    u8 pad368[878 - 872];
    s16 h878;
    u8 pad370[9716 - 880];
    u8 b9716;
} P_4EC500;
extern P_4EC500 D_001A4BE0;
typedef struct {
    f32 f0;
    u8 pad4[688 - 4];
    f32 f688;
    u8 pad2B4[732 - 692];
    s32 i732;
} Q_4EC500;
extern Q_4EC500 D_001A4C68;
extern f32 func_0050D4D8(void *);
extern f32 func_0040BFE8(void *, void *);
extern void func_00445208(void *, void *, void *, f32, f32, f32);
extern void func_00445168(void *, f32, void *, f32, f32, f32);

/* localdecomp:start func_004EC500 */
void func_004EC500(void) {
    P_4EC500 *p = &D_001A4BE0;
    f32 a, b;

    if (p->b9716 != 0) {
        if (p->h878 == 0 && p->f828 < 0.0f) {
            __asm__("abs.s %0, %1" : "=f"(a) : "f"(p->f828));
            b = func_0050D4D8(&p->v240);
            __asm__("abs.s %0, %1" : "=f"(b) : "f"(b));
            if (a < b + 0.01f) {
                if (p->b679 == 0 || func_0040BFE8(&p->v608, &p->v128) > p->f644 * 0.5f) {
                    p->v128 = p->v752;
                } else {
                    func_00445208(&p->v128, &p->v752, &p->i868, 0.05f, 0.21f, 0.083333336f);
                }
            } else {
                func_00445208(&p->v128, &p->v752, &p->i868, 0.05f, 0.21f, 0.083333336f);
            }
        } else {
            D_001A4BE0.i868 = 0;
        }
    } else {
        if (p->h878 == 0 && p->v128.z < p->f824) {
            if (fabsf(p->v128.z - p->f824) < fabsf(p->v240.z) + 0.01f) {
                if (p->b679 == 0 || func_0040BFE8(&p->v608, &p->v128) > p->f644 * 0.5f) {
                    p->v128.z = p->f824;
                    return;
                }
                func_00445168(&p->v128.z, p->f824, &p->i868, 0.05f, 0.17f, 0.083333336f);
                return;
            }
            if (p->f296 < 0.0f) {
                p->v128.z = p->v128.z - p->f296;
                if (p->f824 < p->v128.z) {
                    p->v128.z = p->f824;
                }
            }
            func_00445168(&D_001A4C68.f0, D_001A4C68.f688, &D_001A4C68.i732, 0.05f, 0.17f, 0.083333336f);
        } else {
            D_001A4BE0.i868 = 0;
        }
    }
}
/* localdecomp:end func_004EC500 */
