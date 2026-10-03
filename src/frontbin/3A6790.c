#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003A69A0();
extern void *func_003A6910();
extern s32 func_003A6830(u8 *, s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003A6790 */
extern void func_00121760();
extern void func_003A4768();
extern char D_001D8230[];
extern char D_001D8270[];
extern char D_001D82A0[];
extern s32 D_001D5C84;
void func_003A6790(s32 *arg0)
{
  s32 *p;
  s32 n;
  s32 *new_var;
  new_var = arg0 + 7;
  func_00121760(D_001D8230);
  p = new_var;
  n = arg0[6];
  func_00121760(D_001D8270, p, n);
  if (n > 0)
  {
    do
    {
      p[1] += (s32) arg0;
      func_003A4768(p[1]);
      p += 2;
      D_001D5C84 = D_001D5C84 + 1;
      n--;
    }
    while (n != 0);
  }
  func_00121760(D_001D82A0);
}
/* localdecomp:end func_003A6790 */

/* localdecomp:start func_003A6830 */
typedef struct { s32 k, v; } E_3A6830;
s32 func_003A6830(u8 *p, s32 k) {
    s32 n = *(s32 *)(p + 0x18);
    E_3A6830 *e = (E_3A6830 *)(p + 0x1C);
    s32 i;
    s32 r = 0;
    for (i = 0; i < n; i++) {
        if (e[i].k == k) {
            r = e[i].v;
            break;
        }
    }
    return r;
}
/* localdecomp:end func_003A6830 */

/* localdecomp:start func_003A6880 */
void *func_003A6880(void *p) {
    return p;
}
/* localdecomp:end func_003A6880 */

/* localdecomp:start func_003A6888 */
void func_00116F98_003A6888(void *, s32, void *);
extern u8 D_001D82D8[];
extern u8 D_001D82F8[];
typedef struct { s32 f0; s32 f4; u32 f8; s32 fC; s32 f10; s32 f14; } S_003A6888;

void func_003A6888(S_003A6888 *arg0, u32 arg1, s32 arg2, s32 arg3) {
    if (arg1 < 4U) {
        func_00116F98_003A6888(D_001D82D8, 0x26, D_001D82F8);
    }
    arg0->f0 = arg2;
    arg0->f4 = arg3;
    arg0->f8 = arg1;
    arg0->f14 = 0;
    arg0->fC = 0;
    arg0->f10 = 0;
}
/* localdecomp:end func_003A6888 */

LINKER_REMNANT("asm/remnants", func_003A6908);

/* localdecomp:start func_003A6910 */
void func_00116F98_003A6910(void *, s32, void *);
extern u8 D_001D82D8[];
extern u8 D_001D8320[];
typedef struct { u8 *base; u32 size; s32 elem; u32 used; s32 count; void **free; } S_003A6910;

void *func_003A6910(S_003A6910 *pool) {
    void **p;
    u32 used;
    u32 next;

    p = pool->free;
    if (p != 0) {
        pool->free = *p;
        pool->count++;
        return p;
    }
    used = pool->used;
    next = used + pool->elem;
    if (pool->size < next) {
        func_00116F98_003A6910(D_001D82D8, 0x54, D_001D8320);
        return 0;
    }
    { u8 *r = pool->base + used; pool->used = next; pool->count++; return r; }
}
/* localdecomp:end func_003A6910 */

/* localdecomp:start func_003A69A0 */
void func_003A69A0(void *a0, void *a1) {
    *(s32 *)a1 = *(s32 *)((u8 *)a0 + 0x14);
    *(s32 *)((u8 *)a0 + 0x14) = (s32)a1;
    *(s32 *)((u8 *)a0 + 0x10) = *(s32 *)((u8 *)a0 + 0x10) - 1;
}
/* localdecomp:end func_003A69A0 */

LINKER_REMNANT("asm/remnants", func_003A69C0);

/* localdecomp:start func_003A69C8 */
extern u8 *func_003A5C70(u8 *);
u8 *func_003A69C8(u8 *p) {
    func_003A5C70(p + 0x10);
    func_003A5C70(p + 0x4C);
    return p;
}
/* localdecomp:end func_003A69C8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A6A00);

LINKER_REMNANT("asm/remnants", func_003A6C08);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6C30);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7090);

LINKER_REMNANT("asm/remnants", func_003A7380);

/* localdecomp:start func_003A7398 */
s32 func_003A7398() {
}
/* localdecomp:end func_003A7398 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A73A0);

/* localdecomp:start func_003A7610 */
s32 func_003A7610() {
}
/* localdecomp:end func_003A7610 */

/* localdecomp:start func_003A7618 */
extern s32 func_003A73A0(void *);

void func_003A7618(void *arg0) {
    s32 temp_v1;

    if (*(*(f32 **)((u8 *)(arg0) + 4)) != 0.0f) {
        temp_v1 = (*(s32 *)((u8 *)(arg0) + 0x1A8));
        switch (temp_v1) {                          /* irregular */
        case 0:
            func_003A73A0(arg0);
            break;
        case 2:
            func_003A7610(arg0);
            break;
        }
        func_003A7398(arg0);
    }
}
/* localdecomp:end func_003A7618 */
