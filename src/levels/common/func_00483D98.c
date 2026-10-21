#include "common.h"

/* localdecomp:start func_00483D98 */
extern f32 D_001D86F8;
extern f32 D_001D86FC;
extern f32 D_001D8700;
extern f32 D_001D8704;
extern s32 D_001D8718;
extern s32 D_001D871C;
extern void func_00512480(s32, f32, f32);

void func_00483D98(void) {
    f32 off = 0.0f;
    if (D_001D871C > 0) {
        off = D_001D8700 * 0.5f;
    }
    func_00512480(0xF0002, D_001D86F8 + off + (f32)D_001D8718 * D_001D8700, D_001D86FC + (f32)D_001D871C * D_001D8704);
}
/* localdecomp:end func_00483D98 */
