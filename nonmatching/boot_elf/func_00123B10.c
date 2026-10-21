/* libkernl, boot_elf 0x00123B10, 0x88 bytes: poll an RPC server bind
   (func_00122630) until it answers, with a busy-wait between tries.
   With the range's flags (@ee29 -O2 -G0) 3 instructions differ, at the
   end: retail builds &D_0013DC9C in $v0 and writes `move $v0, $zero`
   after the store; ours uses $v1 and moves the zero first. The busy-wait
   needs `i = 0x100000; while (--i != -1)` to get retail's lui/addiu
   split across the loop label. */
extern u8 D_156400[];
extern s32 D_0013DC9C;
s32 func_00123B10(void) {
    s32 i;
    for (;;) {
        if (func_00122630((Cd_122630 *)D_156400, 0x80000003, 0) < 0) {
            return -1;
        }
        if (*(s32 *)(D_156400 + 0x24) != 0) {
            break;
        }
        i = 0x100000;
        while (--i != -1) {
        }
    }
    D_0013DC9C = 0;
    return 0;
}
