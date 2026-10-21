/* 989snd (EE side), boot_elf 0x0013CB20, 0xDC bytes: packs its twelve
   arguments into an 8-word command and sends it with func_0013C578.
   The range is SN ee-gcc 2.95.3. Tried with SN's flags without
   -fopt-stack (`-mvu0-use-vf0-vf2 -O2 -G8 -mno-check-zero-division`) and
   the function listed in config/boot_elf/sq_ra_funcs.txt (retail saves
   $s0-$s7 and $ra with sq, ascending, $ra highest, which only that
   post-pass gives): 2 instructions differ. Retail computes
   `andi $v0, $s4, 0xffff` (a3's mask) before `or $v1, $v1, $a0`
   (buf[2]); ours the other way round. Operand order, unsigned types,
   statement order and a struct instead of the array don't change it
   (or make it worse). With -fopt-stack the body is the same and only the
   frame differs; 2.9-ee and Sony's 2.95.x builds give other frames. */
extern char D_001D52C8[];
int func_0013CB20(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, long a11) {
    int buf[8];
    if (a0 == 0) func_0011AF48(D_001D52C8);
    buf[0] = a0;
    buf[1] = a1;
    buf[2] = (a4 << 16) | (a2 & 0xFFFF);
    buf[3] = (a5 << 16) | (a3 & 0xFFFF);
    buf[4] = a6;
    buf[5] = a7;
    buf[6] = a8;
    buf[7] = a9;
    return func_0013C578(0x2C, 0x20, buf, a10, a11);
}
