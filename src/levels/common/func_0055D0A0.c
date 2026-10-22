#include "common.h"

/* localdecomp:start func_0055D0A0 */
typedef struct {
    u8 pad[0x68];
    s32 *info;
    u8 pad6C[0x100 - 0x6C];
} E_0055D0A0;
typedef struct {
    u8 pad[0x88];
    s32 a[8];
    s32 b[8];
} T_0055D0A0;
extern E_0055D0A0 *D_0024C05C[1];
extern T_0055D0A0 *D_00352C4C[];
extern s32 func_0055CD90(E_0055D0A0 *);
extern s32 func_0055CDA0(E_0055D0A0 *);

s32 func_0055D0A0(u8 *a0) {
    s32 r = -1;
    if (*(s32 *)(a0 + 0x24C) >= 0) {
        if (func_0055CD90(&D_0024C05C[0][*(s32 *)(a0 + 0x24C)])) {
            r = D_00352C4C[0]->a[D_0024C05C[0][*(s32 *)(a0 + 0x24C)].info[7]];
        } else if (func_0055CDA0(&D_0024C05C[0][*(s32 *)(a0 + 0x24C)])) {
            r = D_00352C4C[0]->b[D_0024C05C[0][*(s32 *)(a0 + 0x24C)].info[11]];
        }
    }
    return r;
}
/* localdecomp:end func_0055D0A0 */
