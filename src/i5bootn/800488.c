#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_008007C8(int);
/* --- end of declarations from other files --- */

/* localdecomp:start func_00800488 */
/* The launcher's loader (SN 2.95.3 at -O0, like main): decompress the payload at
   D_00806080 into D_8C5F00 with func_00800160, then copy each record (16-byte header:
   destination, size, -, entry point) to its destination, 8 bytes at a time when
   everything is 8-aligned. Returns the entry point; stops at a record whose entry
   point differs from the first. */
typedef struct {
    u32 *dst;
    u32 size;
    u32 pad8;
    u32 entry;
} Hdr_800488;
extern u8 D_8C5F00[];
extern u8 D_00806080[];
extern void func_00800160(void *, void *);

u32 func_00800488(void) {
    u8 *p;
    u32 entry;
    u32 *src;
    u32 *dst;
    Hdr_800488 *hdr;
    long *s8;
    long *d8;
    u32 *end;

    p = D_8C5F00;
    entry = 0;
    func_00800160(D_00806080, p);
    while (1) {
        hdr = (Hdr_800488 *)p;
        p += 0x10;
        src = (u32 *)p;
        dst = hdr->dst;
        if (entry == 0) {
            entry = hdr->entry;
        } else if (entry != hdr->entry) {
            break;
        }
        if ((hdr->size & 7) == 0 && ((u32)src & 7) == 0 && ((u32)dst & 7) == 0) {
            s8 = (long *)src;
            d8 = (long *)dst;
            end = (u32 *)((u8 *)dst + hdr->size);
            while ((u32 *)d8 != end) {
                *d8 = *s8;
                s8++;
                d8++;
            }
        } else {
            end = (u32 *)((u8 *)dst + hdr->size);
            while (dst <= end) {
                *dst = *src;
                src++;
                dst++;
            }
        }
        p += hdr->size;
    }
    return entry;
    /* Two unreachable bare returns: retail has two more `b` to the epilogue after
       `return entry;` (-O0 keeps dead code). */
    return;
    return;
}
/* localdecomp:end func_00800488 */

/* localdecomp:start func_00800698 */
extern void func_008026F0(void);
extern u32 func_00800488(void);

/* main(): built at -O0 (unfilled delay slots, $fp frame saved with sq), see
   docs/compiler_matrix_i5bootn.md. func_008026F0 is libgcc's __main. */
int func_00800698(void) {
    func_008026F0();
    func_00800488();
    return 0;
}
/* localdecomp:end func_00800698 */

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_008006E0);

/* localdecomp:start func_00800790 */
/* Sony 2.9-ee library code: byte copy. */
int func_00800790(unsigned char *d, unsigned char *s, unsigned int n) {
    unsigned int i;
    for (i = 0; i < n; i++)
        *d++ = *s++;
    return 0;
}
/* localdecomp:end func_00800790 */

/* localdecomp:start func_008007C0 */
/* Sony 2.9-ee library code (sibling call). func_008010F8 is in 8010A8.c. */
extern void func_008010F8(void);
void func_008007C0(void) {
    func_008010F8();
}
/* localdecomp:end func_008007C0 */

/* localdecomp:start func_008007C8 */
/* Sony 2.9-ee library code: run func_008007C0, then the Exit syscall stub func_00800840
   (a sibling call). */
extern void func_00800840(int);
void func_008007C8(int code) {
    func_008007C0();
    func_00800840(code);
}
/* localdecomp:end func_008007C8 */

LINKER_REMNANT("asm/i5bootn/remnants", func_008007F0);
