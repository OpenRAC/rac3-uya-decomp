#include "common.h"

/* localdecomp:start func_00423698 */
extern void func_00423698();

typedef struct { s32 off; s32 x4; } E_394300;
typedef struct { u8 pad[0x18]; E_394300 e[1]; } H_394300;
typedef struct { u8 pad[0x74]; s32 arr[1]; } G_394300;
extern H_394300 *D_001D4B50;
extern G_394300 *D_001DFD98;
void func_00433EA0(u8 *, u32);
void func_00423698(s32 a, u32 b) {
    H_394300 *h;
    b = (b + 15) & 0xFFFFFFF0;
    if (b) {
        h = D_001D4B50;
        func_00433EA0((u8 *)(h->e[a + 1].off + (s32)h), b);
    }
    D_001DFD98->arr[a] = 0;
}
/* localdecomp:end func_00423698 */
