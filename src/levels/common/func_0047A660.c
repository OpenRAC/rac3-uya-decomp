#include "common.h"
typedef struct { s32 x0; s32 x4; s32 next; s32 arr[4]; } Struct002E9FD8;
extern Struct002E9FD8 D_002E9FD8;
extern void func_0047A608(void);
void func_0047A660(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        D_002E9FD8.arr[i] = D_002E9FD8.next;
        D_002E9FD8.next += 2048;
    }
    func_0047A608();
}
