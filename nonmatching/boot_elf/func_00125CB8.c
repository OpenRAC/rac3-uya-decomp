/* libkernl, boot_elf 0x00125CB8, 0x5C bytes: the alarm handler trampoline
   (calls the user's handler; when it returns 0, the alarm goes back on
   the free list). With the range's flags (@ee29 -O2 -G0) 5 instructions
   differ, all in the epilogue: retail branches over a second copy of
   `ld $ra` to the join, ours shares one `ld $ra` in the delay slot. */
typedef struct A_125CB8 {
    struct A_125CB8 *next;
    s32 id;
    s32 (*handler)(s32, s32, s32, void *);
    void *arg;
} A_125CB8;
extern A_125CB8 *D_159EC0_00125CB8;
s32 func_00125CB8(s32 id, s32 t, s32 c, A_125CB8 *p) {
    s32 r = p->handler(((s32)p << 4) | (id & 0xFE) | 1, t, c, p->arg);
    if (r != 0) {
        return r;
    }
    p->next = D_159EC0_00125CB8;
    D_159EC0_00125CB8 = p;
    p->id = 0;
    return -1;
}
