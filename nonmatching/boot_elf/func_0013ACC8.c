/* libscf, boot_elf 0x0013ACC8, 0x8C bytes: add a number of minutes to a
   date/time with carry into hours (func_0013AC70 / func_0013ACA0).
   With the range's flags (@ee29 -O2 -G0) 4 instructions differ: retail
   loads the minute byte into $v0 and computes `addu $s0, $v0, $s0`; ours
   uses $v1 and `addu $s0, $s0, $v1` (and $v1 for the slti in the loop).
   n += t->x2, n = t->x2 + n, a separate local, u8* or S_13AA40* all give
   the same. The if/else order below is the one that lays the blocks out
   like retail. */
void func_0013ACC8(S_13AA40 *t, s32 n) {
    func_0013AA40(t);
    n += t->x2;
    if (n >= 0) {
        while (n >= 60) { func_0013AC70((u8 *)t); n -= 60; }
    } else {
        while (n < 0) { n += 60; func_0013ACA0((u8 *)t); }
    }
    t->x2 = n;
    func_0013AAA8((u8 *)t);
}
