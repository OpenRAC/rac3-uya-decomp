#include "common.h"

/* localdecomp:start func_003477F8 */
typedef struct {
    char pad0[0x20];
    unsigned char b32;
} Obj;

extern int func_00347B88(Obj *);
extern int func_003482F8(Obj *);
extern int func_00348B90(Obj *);
extern void func_00347888(void);
extern void func_004026A0(void (*)(void), Obj *);
extern void func_00436220(Obj *);

void func_003477F8(Obj *obj) {
    int a = func_00347B88(obj);
    int b = func_003482F8(obj);
    int c = func_00348B90(obj);

    if (a == 0 && b == 0 && c == 0) {
        if (obj->b32 == 2) {
            func_00436220(obj);
        }
    } else {
        func_004026A0(func_00347888, obj);
    }
}
/* localdecomp:end func_003477F8 */
