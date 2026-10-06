#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003AD650();
extern s32 func_003AD6A8();
extern s32 func_003AD458();
extern s32 func_003AD488();
extern s32 func_003AD4B0();
extern s32 func_003AD4D8();
extern s32 func_003AD520();
extern void func_003AD6B0();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AD458 */
extern void func_003AA7E0(void);
extern void func_003AC3F8(u8 *);
extern u8 *D_001DA134[];
s32 func_003AD458(void) {
    func_003AA7E0();
    func_003AC3F8(D_001DA134[0] + 0x48);
    return 1;
}
/* localdecomp:end func_003AD458 */

/* localdecomp:start func_003AD488 */
extern void func_003AC5E0(void *);
extern u8 *D_001DA134[];

s32 func_003AD488(void) {
    func_003AC5E0(D_001DA134[0] + 0x48);
    return 1;
}
/* localdecomp:end func_003AD488 */

/* localdecomp:start func_003AD4B0 */
extern void func_003AC6F0(void *);
extern u8 *D_001DA134[];

s32 func_003AD4B0(void) {
    func_003AC6F0(D_001DA134[0] + 0x48);
    return 1;
}
/* localdecomp:end func_003AD4B0 */

/* localdecomp:start func_003AD4D8 */
typedef struct { unsigned long a, b, c; } Q_3AD4D8;
extern u8 *D_001DA134[];
extern void func_003ACD38(u8 *, Q_3AD4D8 *);
s32 func_003AD4D8(s32 unused, u8 *out) {
    Q_3AD4D8 t;
    func_003ACD38(D_001DA134[0] + 0x48, &t);
    *(unsigned long *)(out + 8) = t.a;
    *(unsigned long *)(out + 0x10) = t.b;
    return 1;
}
/* localdecomp:end func_003AD4D8 */

/* localdecomp:start func_003AD520 */
extern void func_11A0B0();
s32 func_003AD520(u8 *a, s32 sz, u8 *b, s32 off, u8 *src1, s32 len1, u8 *src2, s32 len2) {
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
/* localdecomp:end func_003AD520 */

/* localdecomp:start func_003AD650 */
typedef struct {
    s32 stream;
    u8 *entries;
    s32 write_index;
    s32 count;
    s32 capacity;
} Queue_003AD650;
void func_003AD650(volatile Queue_003AD650 *queue, s32 stream, u8 *entries, s32 capacity) {
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
/* localdecomp:end func_003AD650 */

/* localdecomp:start func_003AD6A8 */
s32 func_003AD6A8(void) {
}
/* localdecomp:end func_003AD6A8 */

/* localdecomp:start func_003AD6B0 */
void func_003AD6B0(void *p) {
    *(volatile s32 *)((u8 *)p + 0xC) = 0;
    *(volatile s32 *)((u8 *)p + 0x8) = 0;
}
/* localdecomp:end func_003AD6B0 */

/* localdecomp:start func_003AD6C0 */
s32 func_003AD6C0(void *a0) {
    return *(s32 *)((u8 *)a0 + 0xc) == *(s32 *)((u8 *)a0 + 0x10);
}
/* localdecomp:end func_003AD6C0 */

/* localdecomp:start func_003AD6D8 */
typedef struct { s32 x0; s32 x4; volatile s32 x8; volatile s32 xC; s32 x10; } S_3AD6D8;
void func_124920(void);
void func_124970(void);
void func_003AD6D8(S_3AD6D8 *p) {
    func_124920();
    *(s32 *)(p->x8 * 0x27E40 + p->x4) = 2;
    p->xC++;
    p->x8 = (p->x8 + 1) % p->x10;
    func_124970();
}
/* localdecomp:end func_003AD6D8 */

/* localdecomp:start func_003AD748 */
s32 func_003AD748(s32 *p) {
    if (func_003AD6C0(p)) return 0;
    return p[0] + p[2] * 0xD0000;
}
/* localdecomp:end func_003AD748 */

/* localdecomp:start func_003AD788 */
s32 func_003AD788(void *p) {
    return *(s32 *)((u8 *)p + 0xC) == 0;
}
/* localdecomp:end func_003AD788 */

/* localdecomp:start func_003AD798 */
typedef struct { s32 x0; s32 x4; volatile s32 x8; volatile s32 xC; s32 x10; } S_3AD798;
s32 func_003AD798(S_3AD798 *p) {
 if (func_003AD788(p)) return 0; return p->x4 + ((p->x8 - p->xC + p->x10) % p->x10) * 0x27E40;
}
/* localdecomp:end func_003AD798 */

/* localdecomp:start func_003AD7F8 */
void func_003AD7F8(volatile s32 *p) {
    if (p[3] > 0) {
        p[3]--;
    }
}
/* localdecomp:end func_003AD7F8 */

LINKER_REMNANT("asm/remnants", func_003AD818);

/* localdecomp:start func_003AD820 */
extern s32 D_001DA168;
extern s32 D_001DA17C;
extern s32 *func_003E03C8(s32 *);
s32 *func_003AD820(s32 idx) {
    s32 i;
    s32 *p;
    if (D_001DA17C == 0) {
        p = &D_001DA168;
        i = 4;
        do {
            func_003E03C8(p);
            i--;
            __asm__ volatile("nop");
            p++;
        } while (i != -1);
        D_001DA17C = 1;
    }
    return &D_001DA168 + idx;
}
/* localdecomp:end func_003AD820 */

LINKER_REMNANT("asm/remnants", func_003AD8A0);
