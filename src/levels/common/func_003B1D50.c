#include "common.h"

/* localdecomp:start func_003B1D50 */
typedef struct { u8 pad[70]; u8 b70; } C_003B1D50;

extern u16 *D_0021DEA0[];
extern u8 *D_001E009C;
extern u8 D_001FDC50[];
extern s16 D_001FDA70[];
extern C_003B1D50 *D_001FD200[];
extern s32 D_001E00D8;
extern s32 func_003B4368(u8 *);
extern s32 func_003B4CC0(u8 *);

s32 func_003B1D50(u8 *self)
{
    u8 *v = *(u8 **)(self + 104);
    s32 n = 0;
    u16 *p;
    u8 *m;
    s32 cls;
    u8 c;

    if (*(s32 *)(v + 12) != -1) {
        p = D_0021DEA0[*(s32 *)(v + 12)];
        while ((*(s32 *)(v + 12) & 0xff) != 0xff && *(s32 *)(v + 12) <= D_001E00D8 && p != 0
               && (((s16 *)p)[-1] >= 0 || p == D_0021DEA0[*(s32 *)(v + 12)])) {
            m = D_001E009C + ((*p & 0x7fff) << 8);
            if (m == 0) break;
            cls = **(s32 **)(m + 104);
            c = D_001FDC50[cls];
            if (D_001FDA70[c] != cls ? cls != 6476 : D_001FD200[c]->b70 != 5) {
            } else {
                if (func_003B4368(m) == 0) {
                    n += func_003B4CC0(m);
                }
            }
            p++;
        }
    }
    return n;
}
/* localdecomp:end func_003B1D50 */
