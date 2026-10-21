#include "common.h"

/* localdecomp:start func_0045C030 */
typedef struct { u32 f0; s16 f4; s16 f6; s16 f8; s16 fA; s16 fC; u8 fE[2]; } S_39CC98;
extern void func_0013C118(s32);
extern void func_0013CC10(s32);
extern void func_0013CC40(s32);
extern void func_0013CC70(s32, void *, unsigned long);
extern void func_0013CCA0(s32, void *, unsigned long);
extern void func_0013C200(s32, void *, unsigned long);
extern void func_0013CCD0(s32, void *, unsigned long);
extern s32 func_0040BAC0(void *);
extern void func_0045CDE0(s32, long);
extern void func_0045CDF8(s32, long);
extern void func_0045CDA0(s32, long);
extern void func_0045CB98(s32, long);
void func_0045C030(S_39CC98 *s) {
    s32 h;
    if (s->fA != 9 && s->f0 != 0 && s->f0 != 0xFFFFFFFF) {
        if (s->fA == 5) {
            if (s->f0 == 0) {
                s->fA = 0;
            } else {
                func_0013C118(s->f0);
                s->fA = 6;
            }
        } else if (s->fA == 6) {
            if (s->f0 == 0) s->fA = 0;
        }
        if (s->f0 != 0) {
            if (s->fC & 0x8000) {
                if (!(s->fA & 0x8000)) {
                    func_0013CC10(s->f0);
                    s->fA |= 0x8000;
                }
                if (func_0040BAC0(s->fE) == 2) s->fC = 4;
            } else if (s->fA & 0x8000) {
                func_0013CC40(s->f0);
                s->fA ^= 0x8000;
            }
            if (!(s->fA & 0x8000)) {
                if (s->fA == 1 || s->fA == 8 || s->fA == 9) {
                } else if (s->fA != 2 && s->fA != 3) {
                    h = s->f0;
                    s->f0 = 0xFFFFFFFF;
                    func_0013CC70(h, func_0045CDE0, (u32)s);
                    func_0013CCA0(h, func_0045CDF8, (u32)s);
                    func_0013C200(h, func_0045CDA0, (u32)s);
                } else if (s->f0 != 0xFFFFFFFF && s->fA == 2) {
                    func_0013CCD0(s->f0, func_0045CB98, (u32)s);
                }
            }
        }
    } else if (s->fA == 7 || s->f0 == 0) {
        s->fA = 0;
    }
    if (s->fA == 0) s->f4 = -1;
}
/* localdecomp:end func_0045C030 */
