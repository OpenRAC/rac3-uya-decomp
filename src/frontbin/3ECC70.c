#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003ECDC0(s32, s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern s32 func_003ECDB8();
extern s32 func_003ECDC0();
extern s32 *func_003ECDC8(s32 *);
extern s32 func_003ECDE0(s32 *);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003ECC70 */
extern u8 D_001D9898[];
void func_003ECC70(u8 *p, s32 f) { *(u8 **)p = D_001D9898; if (f & 1) func_003ECDB8(p); }
/* localdecomp:end func_003ECC70 */

/* localdecomp:start func_003ECCA0 */
typedef struct { s32 f0; u8 *base; u32 size; s32 elem; u32 used; s32 count; void **freelist; } P_3ECCA0;
void *func_003ECCA0(P_3ECCA0 *p) {
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
/* localdecomp:end func_003ECCA0 */

/* localdecomp:start func_003ECD08 */
extern void * func_003ECCA0();
 
s32 func_003ECD08(void *p, u32 n) {
    if (*(u32 *)((u8 *)p + 0xC) < n) {
        return 0;
    }
    return (s32)func_003ECCA0(p);
}
/* localdecomp:end func_003ECD08 */

/* localdecomp:start func_003ECD40 */
void func_003ECD40(s32 *p, s32 *node) {
    *node = p[6];
    p[6] = (s32)node;
    p[5]--;
}
/* localdecomp:end func_003ECD40 */

/* localdecomp:start func_003ECD60 */
extern u8 D_001D9898_g;
extern s32 func_003ECDB8();
void func_003ECD60(u8 *p, s32 f) {
    *(u8 **)p = &D_001D9898_g;
    if (f & 1) func_003ECDB8(p);
}
/* localdecomp:end func_003ECD60 */

LINKER_REMNANT("asm/remnants", func_003ECD90);

/* localdecomp:start func_003ECDB8 */
s32 func_003ECDB8(void) {
}
/* localdecomp:end func_003ECDB8 */

/* localdecomp:start func_003ECDC0 */
s32 func_003ECDC0(s32 a0, s32 a1) {
    return a1;
}
/* localdecomp:end func_003ECDC0 */

/* localdecomp:start func_003ECDC8 */
s32 *func_003ECDC8(s32 *p) {
    *p = 0;
    return p;
}
/* localdecomp:end func_003ECDC8 */

LINKER_REMNANT("asm/remnants", func_003ECDD8);

/* localdecomp:start func_003ECDE0 */
s32 func_003ECDE0(s32 *p) {
    return *p != 0;
}
/* localdecomp:end func_003ECDE0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003ECDF0);
