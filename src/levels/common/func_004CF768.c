#include "common.h"

extern void func_004CF768(s32 *);

extern s32 func_004CFF10(void);
extern void func_004CFB28(s32 *);
extern void func_004CFCB0(s32 *);
void func_004CF768(s32 *p) {
    if (p[0] != 0) {
        s32 t = p[1];
        if (t == 4) func_004CFF10();
        else if (t == 2) func_004CFB28(p);
        else if (t == 3) func_004CFCB0(p);
    }
}
