#include "common.h"
typedef struct {
    s32 v[3];
} Ids3;
extern Ids3 D_001D80D8;
extern void func_005131A0(s32 a0, s32 a1);
extern void func_00512AB0(s32 a0, s32 a1, s32 a2);
void func_00477F48(s32 a0, s32 a1) {
    Ids3 t;
    t = D_001D80D8;
    func_005131A0(t.v[a1], a0);
    if (a0 == 0) {
        func_00512AB0(t.v[a1], 1, 0);
    } else {
        func_00512AB0(t.v[a1], 1, 1);
    }
}
