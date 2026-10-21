#include "common.h"

/* localdecomp:start func_00485EE0 */
typedef struct {
    u8 pad[56];
    u16 unk38;
    u8 pad2[182];
} S_002C5640;

extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern S_002C5640 D_002C5640[];
extern int func_00484718(int, int, int);
extern int func_00484990(int, int, int);
extern void func_00512AB0(int, int, int);
extern void func_005131A0(int, int);

void func_00485EE0(void)
{
    int i;
    int j;
    int a;
    int b;
    S_002C5640 *p;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            a = func_00484718(0, j, i);
            b = func_00484990(0x190039, j, i);
            if (a != 0) {
                func_00512AB0(b, 1, D_00142CA0[a]);
                p = &D_002C5640[D_001425C0[a]];
                func_005131A0(b, p->unk38);
            } else {
                func_00512AB0(b, 1, 0);
            }
        }
    }
}
/* localdecomp:end func_00485EE0 */
