#include "common.h"

extern s32 D_00242B80[];
extern u8 *D_0024CF20[];
extern void func_005C2050(void);
extern void func_005C1BE0(s32);
extern void func_005F9780(void);
extern void func_00577308(void);

void func_00576408(void)
{
    s32 i;
    u8 *p;

    if (D_00242B80[0] != 0) {
        func_005C2050();
    } else {
        for (i = 0; i < 8; i++) {
            p = D_0024CF20[i];
            if (p != 0 && *(s32 *)(p + 9524) != 0) {
                func_005C1BE0(*(s32 *)(p + 9524));
            }
        }
    }
    func_005F9780();
    func_00577308();
}
