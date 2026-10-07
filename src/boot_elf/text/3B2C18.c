#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003B2E10();
extern s32 func_003B2E68();
extern s32 func_003B2C18();
extern s32 func_003B2C48();
extern s32 func_003B2C70();
extern s32 func_003B2C98();
extern s32 func_003B2CE0();
extern void func_003B2E70();
extern s32 func_003B2F08();
extern void func_003B2E98();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B2C18 */
extern void func_003AFFA0(void);
extern void func_003B1BB8(u8 *);
extern u8 *D_001DA134[];
s32 func_003B2C18(void) {
    func_003AFFA0();
    func_003B1BB8(D_001DA134[0] + 0x48);
    return 1;
}
/* localdecomp:end func_003B2C18 */

/* localdecomp:start func_003B2C48 */
extern void func_003B1DA0(void *);
extern u8 *D_001DA134[];

s32 func_003B2C48(void) {
    func_003B1DA0(D_001DA134[0] + 0x48);
    return 1;
}
/* localdecomp:end func_003B2C48 */

/* localdecomp:start func_003B2C70 */
extern void func_003B1EB0(void *);
extern u8 *D_001DA134[];

s32 func_003B2C70(void) {
    func_003B1EB0(D_001DA134[0] + 0x48);
    return 1;
}
/* localdecomp:end func_003B2C70 */

/* localdecomp:start func_003B2C98 */
typedef struct { unsigned long a, b, c; } Q_3AD4D8;
extern u8 *D_001DA134[];
extern void func_003B24F8(u8 *, Q_3AD4D8 *);
s32 func_003B2C98(s32 unused, u8 *out) {
    Q_3AD4D8 t;
    func_003B24F8(D_001DA134[0] + 0x48, &t);
    *(unsigned long *)(out + 8) = t.a;
    *(unsigned long *)(out + 0x10) = t.b;
    return 1;
}
/* localdecomp:end func_003B2C98 */

/* localdecomp:start func_003B2CE0 */
extern void func_11A0B0();
s32 func_003B2CE0(u8 *a, s32 sz, u8 *b, s32 off, u8 *src1, s32 len1, u8 *src2, s32 len2) {
    s32 d;
    if (sz + off < len1 + len2) return 0;
    if (len1 >= sz) {
        d = sz - len1;
        func_11A0B0(a, src1, sz);
        func_11A0B0(b, src1 + sz, len1 - sz);
        func_11A0B0(b + len1 - sz, src2, len2);
    } else {
        d = sz - len1;
        if (len2 >= d) {
            func_11A0B0(a, src1, len1);
            func_11A0B0(a + len1, src2, d);
            func_11A0B0(b, src2 + sz - len1, len2 - d);
        } else {
            func_11A0B0(a, src1, len1);
            func_11A0B0(a + len1, src2, len2);
        }
    }
    return len1 + len2;
}
/* localdecomp:end func_003B2CE0 */

/* localdecomp:start func_003B2E10 */
typedef struct {
    s32 stream;
    u8 *entries;
    s32 write_index;
    s32 count;
    s32 capacity;
} Queue_003AD650;
void func_003B2E10(volatile Queue_003AD650 *queue, s32 stream, u8 *entries, s32 capacity) {
    s32 index = 0;
    s32 offset;
    queue->count = 0;
    queue->stream = stream;
    queue->entries = entries;
    queue->capacity = capacity;
    queue->write_index = 0;
    if (capacity > 0) {
        offset = 0;
        do {
            *(s32 *)(offset + (s32)queue->entries) = 0;
            *(s32 *)(offset + (s32)queue->entries + 4) = index;
            index++;
            offset += 0x27E40;
        } while (index < capacity);
    }
}
/* localdecomp:end func_003B2E10 */

/* localdecomp:start func_003B2E68 */
s32 func_003B2E68(void) {
}
/* localdecomp:end func_003B2E68 */

/* localdecomp:start func_003B2E70 */
void func_003B2E70(void *p) {
    *(volatile s32 *)((u8 *)p + 0xC) = 0;
    *(volatile s32 *)((u8 *)p + 0x8) = 0;
}
/* localdecomp:end func_003B2E70 */

/* localdecomp:start func_003B2E80 */
s32 func_003B2E80(void *a0) {
    return *(s32 *)((u8 *)a0 + 0xc) == *(s32 *)((u8 *)a0 + 0x10);
}
/* localdecomp:end func_003B2E80 */

/* localdecomp:start func_003B2E98 */
typedef struct { s32 x0; s32 x4; volatile s32 x8; volatile s32 xC; s32 x10; } S_3AD6D8;
void func_124920(void);
void func_124970(void);
void func_003B2E98(S_3AD6D8 *p) {
    func_124920();
    *(s32 *)(p->x8 * 0x27E40 + p->x4) = 2;
    p->xC++;
    p->x8 = (p->x8 + 1) % p->x10;
    func_124970();
}
/* localdecomp:end func_003B2E98 */

/* localdecomp:start func_003B2F08 */
s32 func_003B2F08(s32 *p) {
    if (func_003B2E80(p)) return 0;
    return p[0] + p[2] * 0xD0000;
}
/* localdecomp:end func_003B2F08 */

/* localdecomp:start func_003B2F48 */
s32 func_003B2F48(void *p) {
    return *(s32 *)((u8 *)p + 0xC) == 0;
}
/* localdecomp:end func_003B2F48 */

/* localdecomp:start func_003B2F58 */
typedef struct { s32 x0; s32 x4; volatile s32 x8; volatile s32 xC; s32 x10; } S_3AD798;
s32 func_003B2F58(S_3AD798 *p) {
 if (func_003B2F48(p)) return 0; return p->x4 + ((p->x8 - p->xC + p->x10) % p->x10) * 0x27E40;
}
/* localdecomp:end func_003B2F58 */

/* localdecomp:start func_003B2FB8 */
void func_003B2FB8(volatile s32 *p) {
    if (p[3] > 0) {
        p[3]--;
    }
}
/* localdecomp:end func_003B2FB8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003B2FD8);

/* localdecomp:start func_003B2FE0 */
extern s32 D_001DA168;
extern s32 D_001DA17C;
extern s32 *func_003E5B88(s32 *);
s32 *func_003B2FE0(s32 idx) {
    s32 i;
    s32 *p;
    if (D_001DA17C == 0) {
        p = &D_001DA168;
        i = 4;
        do {
            func_003E5B88(p);
            i--;
            __asm__ volatile("nop");
            p++;
        } while (i != -1);
        D_001DA17C = 1;
    }
    return &D_001DA168 + idx;
}
/* localdecomp:end func_003B2FE0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003B3060);
