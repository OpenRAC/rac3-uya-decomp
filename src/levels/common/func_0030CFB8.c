#include "common.h"
typedef struct { char pad[16]; int v; char pad2[28]; } E_0030CFB8;
extern E_0030CFB8 *D_001E17A0[];
/* localdecomp:start func_0030CFB8 */
void func_0030CFB8(int a) {
    E_0030CFB8 *e = D_001E17A0[0];
    int i;
    for (i = 63; i >= 0; i--) {
        if (e[63 - i].v == a) e[63 - i].v = 0;
    }
}
/* localdecomp:end func_0030CFB8 */
