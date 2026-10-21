#include "common.h"

/* localdecomp:start func_0047A2A8 */
extern void func_0047A2A8(s32);

typedef struct {
    char pad_0[0x74];
    s32 field_74;      
    s32 field_78;       
} TargetStruct_0037BA20;

extern TargetStruct_0037BA20 D_002E9FD8;

void func_0047A2A8(s32 arg_a0) {
    D_002E9FD8.field_74 = 1;
    D_002E9FD8.field_78 = arg_a0;
}
/* localdecomp:end func_0047A2A8 */
