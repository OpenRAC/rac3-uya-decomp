#include "common.h"

/* localdecomp:start func_0047A2D8 */
extern s32 func_0047A2D8(u32);
typedef struct {
    char pad_0[0x74];
    s32 field_74;      
    s32 field_78;       
} TargetStruct_0037BA20;
extern TargetStruct_0037BA20 D_002E9FD8;

s32 func_0047A2D8(u32 i) {
    if (i < 4) {
        return ((struct { s32 pad[3]; s32 arr[4]; } *)&D_002E9FD8)->arr[i];
    }
    return 0;
}
/* localdecomp:end func_0047A2D8 */
