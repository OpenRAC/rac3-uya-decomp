#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003F2580(s32, s32);
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern s32 func_003F2578();
extern s32 func_003F2580();
extern s32 *func_003F2588(s32 *);
extern s32 func_003F25A0(s32 *);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003F2430 */
extern u8 D_001D9898[];
void func_003F2430(u8 *p, s32 f) { *(u8 **)p = D_001D9898; if (f & 1) func_003F2578(p); }
/* localdecomp:end func_003F2430 */

/* localdecomp:start func_003F2460 */
typedef struct { s32 f0; u8 *base; u32 size; s32 elem; u32 used; s32 count; void **freelist; } P_3ECCA0;
void *func_003F2460(P_3ECCA0 *p) {
    void **n = p->freelist;
    u32 off, end;
    if (n != 0) {
        p->freelist = *n;
        p->count++;
        return n;
    }
    off = p->used;
    end = off + p->elem;
    if (p->size < end) return 0;
    { u8 *r = p->base + off; p->used = end; p->count++; return r; }
}
/* localdecomp:end func_003F2460 */

/* localdecomp:start func_003F24C8 */
extern void * func_003F2460();
 
s32 func_003F24C8(void *p, u32 n) {
    if (*(u32 *)((u8 *)p + 0xC) < n) {
        return 0;
    }
    return (s32)func_003F2460(p);
}
/* localdecomp:end func_003F24C8 */

/* localdecomp:start func_003F2500 */
void func_003F2500(s32 *p, s32 *node) {
    *node = p[6];
    p[6] = (s32)node;
    p[5]--;
}
/* localdecomp:end func_003F2500 */

/* localdecomp:start func_003F2520 */
extern u8 D_001D9898_g;
extern s32 func_003F2578();
void func_003F2520(u8 *p, s32 f) {
    *(u8 **)p = &D_001D9898_g;
    if (f & 1) func_003F2578(p);
}
/* localdecomp:end func_003F2520 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003F2550);

/* localdecomp:start func_003F2578 */
s32 func_003F2578(void) {
}
/* localdecomp:end func_003F2578 */

/* localdecomp:start func_003F2580 */
s32 func_003F2580(s32 a0, s32 a1) {
    return a1;
}
/* localdecomp:end func_003F2580 */

/* localdecomp:start func_003F2588 */
s32 *func_003F2588(s32 *p) {
    *p = 0;
    return p;
}
/* localdecomp:end func_003F2588 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003F2598);

/* localdecomp:start func_003F25A0 */
s32 func_003F25A0(s32 *p) {
    return *p != 0;
}
/* localdecomp:end func_003F25A0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003F25B0);
