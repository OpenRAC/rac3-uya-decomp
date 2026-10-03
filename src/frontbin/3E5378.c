#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern s32 func_003ECDB8();
extern s32 func_003E1BC8();
extern void **func_003ECC40(void **);
extern char D_001D96B0[];
extern void func_003E8568(void *p, s32, s32);
extern void *func_003E4DA0();
extern void func_003EAA80(void *p, f32, f32);
extern void func_003EAA38(u8 *p, u8, s32);
extern void func_003E8BF8(void *p, s32, s32);
extern s32 func_003EB620(u8 *arg0, s32, s32);
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
extern u8 D_001DAA89;
extern u8 D_001DAA8A;
extern u8 D_001DAA8D;
extern u8 D_001DAA8E;
extern u8 D_001DAA8F;
extern u8 D_001DAA90;
extern u8 D_001DAA91;
extern u8 D_001DAA92;
extern u8 D_001DAA93;
extern u8 D_001DAA94;
extern u8 D_001DAA96;
extern u8 D_001DAA97;
extern u8 D_001DAA98;
extern u8 D_001DAA99;
extern u8 D_001DAA9A;
/* --- end of declarations from other files --- */

/* localdecomp:start func_003E5378 */
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
extern s32 D_001D97D0[];
s32 func_003E5378(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E5378 */

/* localdecomp:start func_003E53E0 */
extern u8 D_001DAA89;
extern void *func_003E4790(HT_8 *, u32);
s32 func_003E53E0(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E4790(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA89) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E53E0 */

/* localdecomp:start func_003E54B0 */
extern s32 D_001D97D0_g;
extern void func_003E8610();
s32 func_003E54B0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) {
        func_003E8610(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E54B0 */

/* localdecomp:start func_003E5518 */
extern u8 D_001DAA8A;
extern void *func_003E4810(HT_8 *, u32);
s32 func_003E5518(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E4810(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA8A) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E5518 */

/* localdecomp:start func_003E55E8 */
extern s32 D_001D97D0_g;
s32 func_003E55E8(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) {
        *(s32 *)(p + 0x3C) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E55E8 */

/* localdecomp:start func_003E5638 */
extern u8 D_001DAA92;
extern void *func_003E4C20(HT_8 *, u32);
s32 func_003E5638(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E4C20(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA92) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E5638 */

/* localdecomp:start func_003E5708 */
extern s32 D_001D97D0[];
s32 func_003E5708(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E5708 */

/* localdecomp:start func_003E5770 */
extern s32 D_001D97D0_g;
s32 func_003E5770(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) {
        *(s32 *)(p + 0x50) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E5770 */

/* localdecomp:start func_003E57C0 */
extern u8 D_001DAA94;
extern void *func_003E4D20(HT_8 *, u32);
s32 func_003E57C0(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E4D20(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA94) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E57C0 */

/* localdecomp:start func_003E5890 */
extern s32 D_001D97D0_g;
extern void func_003E8568(void *, s32, s32);
s32 func_003E5890(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) {
        func_003E8568(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E5890 */

/* localdecomp:start func_003E58F8 */
extern u8 D_001DAA8E;
extern void *func_003E4A20(HT_8 *, u32);
s32 func_003E58F8(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E4A20(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA8E) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E58F8 */

/* localdecomp:start func_003E59C8 */
extern s32 D_001D97D0_g;
extern s32 func_003E8590();
s32 func_003E59C8(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) {
        *out = func_003E8590(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E59C8 */

/* localdecomp:start func_003E5A30 */
extern u8 D_001DAA8F;
extern void *func_003E4AA0(HT_8 *, u32);
s32 func_003E5A30(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E4AA0(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA8F) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E5A30 */

/* localdecomp:start func_003E5B00 */
extern s32 D_001D97D0_g;
extern void func_003E85A0(void *, s32, s32);
s32 func_003E5B00(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) {
        func_003E85A0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E5B00 */

/* localdecomp:start func_003E5B68 */
extern s32 D_001D97D0_g;
extern void func_003E85D8();
s32 func_003E5B68(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) {
        func_003E85D8(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E5B68 */

/* localdecomp:start func_003E5BD0 */
extern u8 D_001DAA90;
extern void *func_003E4B20(HT_8 *, u32);
s32 func_003E5BD0(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E4B20(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA90) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E5BD0 */

/* localdecomp:start func_003E5CA0 */
extern s32 D_001D97D0[];
s32 func_003E5CA0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E5CA0 */

/* localdecomp:start func_003E5D08 */
typedef struct { u8 b[16]; } V16_func_003E5D08;
extern s32 D_001D97D0_func_003E5D08;
extern V16_func_003E5D08 D_001D9700_func_003E5D08;
s32 func_003E5D08(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    V16_func_003E5D08 v;
    f32 out[4];
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D97D0_func_003E5D08) != 0) {
        v = D_001D9700_func_003E5D08;
        (*(s32 (**)(void *, void *, f32 *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x20))(arg0, &v, out, 1);
        *arg1 = out[0];
        *arg2 = out[1];
        *arg3 = out[2];
        *arg4 = out[3];
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E5D08 */

/* localdecomp:start func_003E5DE0 */
extern u8 D_001DAA91;
extern void *func_003E4BA0(HT_8 *, u32);
s32 func_003E5DE0(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E4BA0(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA91) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E5DE0 */

/* localdecomp:start func_003E5EB0 */
extern s32 D_001D97D0_g;
s32 func_003E5EB0(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) {
        *(s32 *)(p + 0x58) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E5EB0 */

/* localdecomp:start func_003E5F00 */
typedef struct {
    u8 pad0[4];
    s32 count;
    struct {
        u32 key;
        void *value;
    } entries[3];
} Table_003E5F00;

extern u8 D_001DAA95_003E5F00;
extern void *func_003E4DA0(void *, u32);

s32 func_003E5F00(Table_003E5F00 *input_table, u32 input_key, void *input_value) {
    register Table_003E5F00 *table __asm__("$17") = input_table;
    register u32 key __asm__("$16") = input_key;
    register void *value __asm__("$18") = input_value;

    if (table->count < 3 && func_003E4DA0(table, key) == 0) {
        register s32 iteration __asm__("$8") = 0;
        register s32 divisor __asm__("$6") = 3;
        register s32 parity __asm__("$11") = key & 1;
        register u8 *value_base __asm__("$9") = (u8 *)table + 0xC;
        register void *sentinel __asm__("$12") = &D_001DAA95_003E5F00;
        register u8 *key_base __asm__("$10") = (u8 *)table + 8;
        register s32 offset __asm__("$7") = 0;

        do {
            register s32 slot __asm__("$3") = ((key % divisor) + offset) % divisor;
            register s32 byte_offset __asm__("$2") = slot << 3;
            register void **selected __asm__("$5") = (void **)(value_base + byte_offset);
            register void *current __asm__("$4") = *selected;
            register s32 next_offset __asm__("$3");

            __asm__ volatile("" : "+r"(selected));
            if (current == 0) {
                goto found;
            }
            if (current != sentinel) {
                goto next;
            }
found:
            *selected = value;
            *(u32 *)(key_base + byte_offset) = key;
            table->count++;
            return 1;
next:
            iteration++;
            next_offset = offset + 1;
            offset = parity + next_offset;
        } while (iteration < 3);
    }
    return 0;
}
/* localdecomp:end func_003E5F00 */

/* localdecomp:start func_003E5FD8 */
extern s32 D_001D9800[];
extern void func_003E8600(void *, f32, f32);
s32 func_003E5FD8(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800[0])) {
        func_003E8600(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E5FD8 */

/* localdecomp:start func_003E6048 */
extern s32 D_001D9800_g;
extern void func_003E8610();
s32 func_003E6048(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003E8610(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6048 */

/* localdecomp:start func_003E60B0 */
extern s32 D_001D9800_g;
extern void func_003EB440();
s32 func_003E60B0(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003EB440(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E60B0 */

/* localdecomp:start func_003E6108 */
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
extern s32 D_001D9800_003E6108;
extern void func_003EB4C0(void *, s32, s16, s16, s32);
s32 func_003E6108(u8 *p, s32 a, s16 b, s16 c, s32 d) {
    if ((*(VT_3E6108 **)(p + 8))->isA(p, D_001D9800_003E6108)) {
        func_003EB4C0(p, a, b, c, d);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6108 */

/* localdecomp:start func_003E6198 */
extern u8 D_001DAA93;
extern void *func_003E4CA0(HT_8 *, u32);
s32 func_003E6198(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E4CA0(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA93) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E6198 */

/* localdecomp:start func_003E6268 */
extern s32 D_001D9800_003E6268[];
extern void func_003E8628(void *, f32, f32);
s32 func_003E6268(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_003E6268[0])) {
        func_003E8628(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6268 */

/* localdecomp:start func_003E62D8 */
extern s32 D_001D9800_g;
extern void func_003EB3F8(void *, s32);
s32 func_003E62D8(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003EB3F8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E62D8 */

/* localdecomp:start func_003E6330 */
extern s32 D_001D9800_g;
extern void func_003E8568(void *, s32, s32);
s32 func_003E6330(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003E8568(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6330 */

/* localdecomp:start func_003E6398 */
extern s32 D_001D9800_g;
extern s32 func_003E8590();
s32 func_003E6398(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        *out = func_003E8590(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6398 */

/* localdecomp:start func_003E6400 */
extern s32 D_001D9800_g;
extern void func_003E85A0(void *, s32, s32);
s32 func_003E6400(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003E85A0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6400 */

/* localdecomp:start func_003E6468 */
extern s32 D_001D9800_g;
extern void func_003E85D8();
s32 func_003E6468(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003E85D8(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6468 */

/* localdecomp:start func_003E64D0 */
extern s32 D_001D9800[];
s32 func_003E64D0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E64D0 */

/* localdecomp:start func_003E6538 */
typedef struct { u8 b[16]; } V16_003E6538;
extern s32 D_001D9800_003E6538;
extern V16_003E6538 D_001D9700_003E6538;
s32 func_003E6538(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    V16_003E6538 v;
    f32 out[4];
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D9800_003E6538) != 0) {
        v = D_001D9700_003E6538;
        (*(s32 (**)(void *, void *, f32 *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x20))(arg0, &v, out, 1);
        *arg1 = out[0];
        *arg2 = out[1];
        *arg3 = out[2];
        *arg4 = out[3];
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6538 */

/* localdecomp:start func_003E6610 */
extern s32 D_001D9800[];
extern void func_003EB538(u8 *, s32, f32, f32);
s32 func_003E6610(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800[0])) {
        func_003EB538(p, 1, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6610 */

/* localdecomp:start func_003E6680 */
typedef struct {
    u8 pad0[4];
    s32 count;
    struct { u32 key; void *value; } entries[3];
} Table_003E6680;

extern u8 D_001DAA8B_003E6680;
extern void *func_003E4890(void *, u32);

s32 func_003E6680(Table_003E6680 *input_table, u32 input_key, void *input_value) {
    register Table_003E6680 *table __asm__("$17") = input_table;
    register u32 key __asm__("$16") = input_key;
    register void *value __asm__("$18") = input_value;

    if (table->count < 3 && func_003E4890(table, key) == 0) {
        register s32 iteration __asm__("$8") = 0;
        register s32 divisor __asm__("$6") = 3;
        register s32 parity __asm__("$11") = key & 1;
        register u8 *value_base __asm__("$9") = (u8 *)table + 0xC;
        register void *sentinel __asm__("$12") = &D_001DAA8B_003E6680;
        register u8 *key_base __asm__("$10") = (u8 *)table + 8;
        register s32 offset __asm__("$7") = 0;

        do {
            register s32 slot __asm__("$3") = ((key % divisor) + offset) % divisor;
            register s32 byte_offset __asm__("$2") = slot << 3;
            register void **selected __asm__("$5") = (void **)(value_base + byte_offset);
            register void *current __asm__("$4") = *selected;
            register s32 next_offset __asm__("$3");

            __asm__ volatile("" : "+r"(selected));
            if (current == 0) goto found;
            if (current != sentinel) goto next;
found:
            *selected = value;
            *(u32 *)(key_base + byte_offset) = key;
            table->count++;
            return 1;
next:
            iteration++;
            next_offset = offset + 1;
            offset = parity + next_offset;
        } while (iteration < 3);
    }
    return 0;
}
/* localdecomp:end func_003E6680 */

/* localdecomp:start func_003E6758 */
extern s32 D_001D9800[];
extern void func_003EB4A8(void *, f32);
s32 func_003E6758(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800[0])) {
        func_003EB4A8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6758 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E67B8);

/* localdecomp:start func_003E6890 */
extern s32 D_001D9800[];
extern void func_003EB4E8(void *, f32);
s32 func_003E6890(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800[0])) {
        func_003EB4E8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6890 */

/* localdecomp:start func_003E68F0 */
extern s32 D_001D9800[];
extern void func_003EB538(u8 *, s32, f32, f32);
s32 func_003E68F0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800[0])) {
        func_003EB538(p, 1, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E68F0 */

/* localdecomp:start func_003E6960 */
extern s32 D_001D9800_g;
extern s32 func_003EB500();
s32 func_003E6960(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003EB500(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6960 */

/* localdecomp:start func_003E69B8 */
extern u8 D_001DAA99;
extern void *func_003E4FA8(HT_8 *, u32);
s32 func_003E69B8(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E4FA8(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA99) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E69B8 */

/* localdecomp:start func_003E6A88 */
extern s32 D_001D9800_g;
extern s32 func_003EB518();
s32 func_003E6A88(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003EB518(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6A88 */

/* localdecomp:start func_003E6AF0 */
extern s32 D_001D9800_g;
extern void func_003EB710(void *, s32);
s32 func_003E6AF0(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003EB710(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6AF0 */

/* localdecomp:start func_003E6B48 */
extern s32 D_001D97A0[];
s32 func_003E6B48(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97A0[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6B48 */

/* localdecomp:start func_003E6BB0 */
extern s32 D_001D97A0_g;
extern void func_003E8610();
s32 func_003E6BB0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97A0_g)) {
        func_003E8610(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6BB0 */

/* localdecomp:start func_003E6C18 */
extern s32 D_001D97A0[];
s32 func_003E6C18(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97A0[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6C18 */

/* localdecomp:start func_003E6C80 */
typedef struct V_3E6C80 { u8 pad[0x10]; s32 (*fn)(void *, s32); } V_3E6C80;
typedef struct { u8 pad[8]; V_3E6C80 *vt; } O_3E6C80;
extern s32 D_001D97A0_003E6C80;
extern void func_003E9D20();
s32 func_003E6C80(O_3E6C80 *a, s32 b) {
    if (a->vt->fn(a, D_001D97A0_003E6C80) != 0) {
        func_003E9D20(a, b, b, b, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6C80 */

/* localdecomp:start func_003E6CE8 */
typedef struct S_3E6CE8 S_3E6CE8;
typedef struct { u8 pad[0x10]; s32 (*fn)(S_3E6CE8 *, s32); } V_3E6CE8;
struct S_3E6CE8 { u8 pad[8]; V_3E6CE8 *vt; u8 p2[0x4A-0xC]; s16 h4A; };
extern s32 D_001D97A0_003E6CE8;
extern void func_003E9C50();
s32 func_003E6CE8(S_3E6CE8 *p, s32 b) {
    s32 r;
    if (!p->vt->fn(p, D_001D97A0_003E6CE8)) r = 0; else {
        func_003E9C50(p, b);
        p->h4A = 0;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_003E6CE8 */

/* localdecomp:start func_003E6D48 */
extern s32 D_001D97A0_g;
extern void func_003E8568(void *, s32, s32);
s32 func_003E6D48(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97A0_g)) {
        func_003E8568(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6D48 */

/* localdecomp:start func_003E6DB0 */
extern s32 D_001D97A0_g;
extern s32 func_003E8590();
s32 func_003E6DB0(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97A0_g)) {
        *out = func_003E8590(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6DB0 */

/* localdecomp:start func_003E6E18 */
extern s32 D_001D97A0_g;
extern void func_003E85A0(void *, s32, s32);
s32 func_003E6E18(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97A0_g)) {
        func_003E85A0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6E18 */

/* localdecomp:start func_003E6E80 */
extern s32 D_001D97A0_g;
extern void func_003E85D8();
s32 func_003E6E80(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97A0_g)) {
        func_003E85D8(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6E80 */

/* localdecomp:start func_003E6EE8 */
extern s32 D_001D97A0[];
s32 func_003E6EE8(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97A0[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6EE8 */

/* localdecomp:start func_003E6F50 */
typedef struct { u8 b[16]; } V16_003E6F50;
extern s32 D_001D97A0_003E6F50;
extern V16_003E6F50 D_001D9700_003E6F50;
s32 func_003E6F50(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    V16_003E6F50 v;
    f32 out[4];
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D97A0_003E6F50) != 0) {
        v = D_001D9700_003E6F50;
        (*(s32 (**)(void *, void *, f32 *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x20))(arg0, &v, out, 1);
        *arg1 = out[0];
        *arg2 = out[1];
        *arg3 = out[2];
        *arg4 = out[3];
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6F50 */

/* localdecomp:start func_003E7028 */
extern void func_003E9D20(void *, s32, s32, s32, s32);
extern s32 D_001D97A0_003E7028;
s32 func_003E7028(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D97A0_003E7028) != 0) {
        func_003E9D20(arg0, arg1, arg2, arg3, arg4);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7028 */

/* localdecomp:start func_003E70B0 */
extern u8 D_001DAA96;
extern void *func_003E4E28(HT_8 *, u32);
s32 func_003E70B0(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E4E28(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA96) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E70B0 */

/* localdecomp:start func_003E7180 */
extern s32 D_001D97A0[];
s32 func_003E7180(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97A0[0])) {
        *(f32 *)(p + 0x2C) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7180 */

/* localdecomp:start func_003E71D8 */
extern u8 D_001DAA8D;
extern void *func_003E49A0(HT_8 *, u32);
s32 func_003E71D8(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E49A0(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA8D) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E71D8 */

/* localdecomp:start func_003E72A8 */
extern s32 D_001D9770[];
s32 func_003E72A8(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E72A8 */

/* localdecomp:start func_003E7310 */
extern s32 D_001D9770_g;
extern void func_003E8610();
s32 func_003E7310(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770_g)) {
        func_003E8610(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7310 */

/* localdecomp:start func_003E7378 */
extern s32 D_001D9770[];
s32 func_003E7378(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7378 */

/* localdecomp:start func_003E73E0 */
extern s32 D_001D9770_g;
s32 func_003E73E0(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770_g)) {
        *(s32 *)(p + 0x30) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E73E0 */

/* localdecomp:start func_003E7430 */
extern s32 D_001D9770_g;
extern void func_003E8568(void *, s32, s32);
s32 func_003E7430(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770_g)) {
        func_003E8568(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7430 */

/* localdecomp:start func_003E7498 */
extern s32 D_001D9770_g;
extern s32 func_003E8590();
s32 func_003E7498(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770_g)) {
        *out = func_003E8590(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7498 */

/* localdecomp:start func_003E7500 */
extern s32 D_001D9770_g;
extern void func_003E85A0(void *, s32, s32);
s32 func_003E7500(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770_g)) {
        func_003E85A0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7500 */

/* localdecomp:start func_003E7568 */
extern s32 D_001D9770_g;
extern void func_003E85D8();
s32 func_003E7568(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770_g)) {
        func_003E85D8(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7568 */

/* localdecomp:start func_003E75D0 */
extern s32 D_001D9770[];
s32 func_003E75D0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E75D0 */

/* localdecomp:start func_003E7638 */
typedef struct { u8 b[16]; } V16_003E7638;
extern s32 D_001D9770_003E7638;
extern V16_003E7638 D_001D9700_003E7638;
s32 func_003E7638(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    V16_003E7638 v;
    f32 out[4];
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D9770_003E7638) != 0) {
        v = D_001D9700_003E7638;
        (*(s32 (**)(void *, void *, f32 *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x20))(arg0, &v, out, 1);
        *arg1 = out[0];
        *arg2 = out[1];
        *arg3 = out[2];
        *arg4 = out[3];
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7638 */

/* localdecomp:start func_003E7710 */
extern s32 D_001D9770[];
s32 func_003E7710(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770[0])) {
        *(f32 *)(p + 0x34) = a;
        *(f32 *)(p + 0x38) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7710 */

/* localdecomp:start func_003E7778 */
extern s32 D_001D9830[];
s32 func_003E7778(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7778 */

/* localdecomp:start func_003E77E0 */
extern s32 D_001D9830_g;
extern void func_003E8610();
s32 func_003E77E0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830_g)) {
        func_003E8610(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E77E0 */

/* localdecomp:start func_003E7848 */
extern s32 D_001D9830[];
s32 func_003E7848(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7848 */

/* localdecomp:start func_003E78B0 */
extern s32 D_001D9830_g;
s32 func_003E78B0(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830_g)) {
        *(s32 *)(p + 0x38) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E78B0 */

/* localdecomp:start func_003E7900 */
typedef struct { s32 pad[4]; s32 (*fn)(void *, s32); } V_3E7900;
typedef struct { s32 a, b; V_3E7900 *vt; u8 pad[0x34]; s32 c; s32 d; } S_3E7900;
extern s32 D_001D9830_003E7900;
s32 func_003E7900(S_3E7900 *s, s32 b, s32 c) {
    if (s->vt->fn(s, D_001D9830_003E7900) != 0) {
        s->d = b;
        s->c = c;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7900 */

/* localdecomp:start func_003E7960 */
extern u8 D_001DAA97;
extern void *func_003E4EA8(HT_8 *, u32);
s32 func_003E7960(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E4EA8(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA97) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E7960 */

/* localdecomp:start func_003E7A30 */
extern s32 D_001D9830_g;
extern void func_003E8568(void *, s32, s32);
s32 func_003E7A30(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830_g)) {
        func_003E8568(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7A30 */

/* localdecomp:start func_003E7A98 */
extern s32 D_001D9830_g;
extern s32 func_003E8590();
s32 func_003E7A98(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830_g)) {
        *out = func_003E8590(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7A98 */

/* localdecomp:start func_003E7B00 */
extern s32 D_001D9830_g;
extern void func_003E85A0(void *, s32, s32);
s32 func_003E7B00(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830_g)) {
        func_003E85A0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7B00 */

/* localdecomp:start func_003E7B68 */
extern s32 D_001D9830_g;
extern void func_003E85D8();
s32 func_003E7B68(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830_g)) {
        func_003E85D8(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7B68 */

/* localdecomp:start func_003E7BD0 */
extern s32 D_001D9830[];
s32 func_003E7BD0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7BD0 */

/* localdecomp:start func_003E7C38 */
extern s32 D_001D9830[];
s32 func_003E7C38(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830[0])) {
        *(f32 *)(p + 0x3C) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7C38 */

/* localdecomp:start func_003E7C90 */
typedef struct { u8 b[16]; } V16_003E7C90;
extern s32 D_001D9830_003E7C90;
extern V16_003E7C90 D_001D9700_003E7C90;
s32 func_003E7C90(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    V16_003E7C90 v;
    f32 out[4];
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D9830_003E7C90) != 0) {
        v = D_001D9700_003E7C90;
        (*(s32 (**)(void *, void *, f32 *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x20))(arg0, &v, out, 1);
        *arg1 = out[0];
        *arg2 = out[1];
        *arg3 = out[2];
        *arg4 = out[3];
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7C90 */

/* localdecomp:start func_003E7D68 */
extern void func_003E8EA0(u8 *, f32, f32, f32, f32);
extern s32 D_001D9740[];
s32 func_003E7D68(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D9740[0]) != 0) {
        func_003E8EA0((u8 *)arg0, fparg0, fparg1, fparg2, fparg3);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E7D68 */

/* localdecomp:start func_003E7DF8 */
extern u8 D_001DAA98;
extern void *func_003E4F28(HT_8 *, u32);
s32 func_003E7DF8(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E4F28(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA98) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E7DF8 */

/* localdecomp:start func_003E7EC8 */
typedef struct S_3E7EC8 S_3E7EC8;
typedef struct { u8 pad[0x10]; s32 (*f10)(S_3E7EC8 *, s32); } V_3E7EC8;
struct S_3E7EC8 { u8 pad[8]; V_3E7EC8 *vt; };
extern s32 D_001D9740_003E7EC8;
extern s32 func_003E8838(S_3E7EC8 *a, s32 b);
s32 func_003E7EC8(S_3E7EC8 *a, s32 b) {
    if (a->vt->f10(a, D_001D9740_003E7EC8)) return func_003E8838(a, b);
    return 0;
}
/* localdecomp:end func_003E7EC8 */

/* localdecomp:start func_003E7F20 */
typedef struct { s32 pad[4]; s32 (*fn)(void *, void *); } V_3E7F20;
typedef struct { s32 a, b; V_3E7F20 *vt; } S_3E7F20;
extern void *D_001D9740_003E7F20[];
extern void func_003E8970();
s32 func_003E7F20(S_3E7F20 *s) {
    if (s->vt->fn(s, D_001D9740_003E7F20[0]) == 0) return 0;
    func_003E8970(s);
    return 1;
}
/* localdecomp:end func_003E7F20 */

/* localdecomp:start func_003E7F70 */
extern u8 D_001DAA9A;
extern void *func_003E5028(HT_8 *, u32);
s32 func_003E7F70(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E5028(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_001DAA9A) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E7F70 */

/* localdecomp:start func_003E8040 */
extern s32 D_001D9740_g;
extern void func_003E8568(void *, s32, s32);
s32 func_003E8040(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9740_g)) {
        func_003E8568(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E8040 */

/* localdecomp:start func_003E80A8 */
extern s32 D_001D9740_g;
extern s32 func_003E8590();
s32 func_003E80A8(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9740_g)) {
        *out = func_003E8590(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E80A8 */

/* localdecomp:start func_003E8110 */
extern s32 D_001D9740_g;
extern void func_003E85A0(void *, s32, s32);
s32 func_003E8110(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9740_g)) {
        func_003E85A0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E8110 */

/* localdecomp:start func_003E8178 */
extern s32 D_001D9740_g;
extern void func_003E85D8();
s32 func_003E8178(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9740_g)) {
        func_003E85D8(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E8178 */

/* localdecomp:start func_003E81E0 */
extern s32 D_001D9740[];
s32 func_003E81E0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9740[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E81E0 */

/* localdecomp:start func_003E8248 */
extern s32 D_001D9740[];
extern void func_003E8600(void *, f32, f32);
s32 func_003E8248(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9740[0])) {
        func_003E8600(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E8248 */

/* localdecomp:start func_003E82B8 */
extern s32 D_001D9740_g;
extern void func_003E8610();
s32 func_003E82B8(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9740_g)) {
        func_003E8610(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E82B8 */

/* localdecomp:start func_003E8320 */
extern s32 D_001D9740[];
extern void func_003E8628(void *, f32, f32);
s32 func_003E8320(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9740[0])) {
        func_003E8628(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E8320 */

LINKER_REMNANT("asm/remnants", func_003E8390);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8420);

LINKER_REMNANT("asm/remnants", func_003E8560);

/* localdecomp:start func_003E8568 */
void func_003E8568(void *p, s32 mask, s32 set) {
    if (set != 0) {
        *(s32 *)((u8 *)p + 0xC) |= mask;
    } else {
        *(s32 *)((u8 *)p + 0xC) &= ~mask;
    }
}
/* localdecomp:end func_003E8568 */

/* localdecomp:start func_003E8590 */
s32 func_003E8590(void *p, s32 mask) {
    return (*(s32 *)((u8 *)p + 0xC) & mask) != 0;
}
/* localdecomp:end func_003E8590 */

/* localdecomp:start func_003E85A0 */
void func_003E85A0(void *p, s32 a, s32 b) {
    *(u32 *)((u8 *)p + 0xC) = (((*(u32 *)((u8 *)p + 0xC) & ~0x600) | (a << 9)) & ~0x1800) | (b << 11);
}
/* localdecomp:end func_003E85A0 */

/* localdecomp:start func_003E85D8 */
void func_003E85D8(void *p, s32 *a, s32 *b) {
    *a = (*(u32 *)((u8 *)p + 0xC) >> 9) & 3;
    *b = (*(u32 *)((u8 *)p + 0xC) >> 11) & 3;
}
/* localdecomp:end func_003E85D8 */

/* localdecomp:start func_003E8600 */
void func_003E8600(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x10) = x;
    *(f32 *)((u8 *)p + 0x14) = y;
}
/* localdecomp:end func_003E8600 */

/* localdecomp:start func_003E8610 */
void func_003E8610(void *a0, f32 *a1, f32 *a2) {
    *a1 = *(f32 *)((u8 *)a0 + 0x10);
    *a2 = *(f32 *)((u8 *)a0 + 0x14);
}
/* localdecomp:end func_003E8610 */

/* localdecomp:start func_003E8628 */
void func_003E8628(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x18) = x;
    *(f32 *)((u8 *)p + 0x1C) = y;
}
/* localdecomp:end func_003E8628 */

/* localdecomp:start func_003E8638 */
s32 func_003E8638(void) {
    return 1;
}
/* localdecomp:end func_003E8638 */

/* localdecomp:start func_003E8640 */
s32 func_003E8640(s32 p, s32 k) {
    if (k == 1) {
        return 1;
    }
    return func_003E1BB0(p, k);   /* defined earlier in text.c */
}
/* localdecomp:end func_003E8640 */

/* localdecomp:start func_003E8670 */
typedef struct V_3E8670 { u8 pad[0x14]; s32 (*fn)(void *, s32); } V_3E8670;
typedef struct { u8 pad[8]; V_3E8670 *vt; } O_3E8670;
extern s32 func_003E8590();
s32 func_003E8670(O_3E8670 *a, s32 b) {
    if (func_003E8590(a, 1) != 0) return a->vt->fn(a, b);
    return 0;
}
/* localdecomp:end func_003E8670 */

/* localdecomp:start func_003E86C8 */
typedef struct { u8 pad[0x18]; void (*fn)(void *, s32); } V_3E86C8;
typedef struct { u8 pad[8]; V_3E86C8 *vt; } S_3E86C8;
extern s32 func_003E8590();
void func_003E86C8(S_3E86C8 *a, s32 b) {
    if (func_003E8590(a, 1)) a->vt->fn(a, b);
}
/* localdecomp:end func_003E86C8 */

/* localdecomp:start func_003E8718 */
extern void func_003E1CC8(void);
extern void func_003E1CE8(void);
extern s32 func_003E8590(void *, s32);
void func_003E8718(void *arg0, s32 arg1) {
    if (func_003E8590(arg0, 1) != 0) {
        (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x1C))(arg0, arg1);
    }
    if (func_003E8590(arg0, 0x4000) != 0) {
        func_003E1CE8();
        func_003E1CC8();
    }
}
/* localdecomp:end func_003E8718 */

/* localdecomp:start func_003E8788 */
s32 func_003E8788(void) {
}
/* localdecomp:end func_003E8788 */

/* localdecomp:start func_003E8790 */
extern char D_001D96B0[];
void func_003E8790(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D96B0; if (f & 1) func_003ECDB8(p); }
/* localdecomp:end func_003E8790 */

LINKER_REMNANT("asm/remnants", func_003E87C0);

/* localdecomp:start func_003E87D8 */
extern f32 D_001D96D8;
extern f32 D_001D96DC;
extern void func_003A3FB0(s32, s32, s32, s32);
void func_003E87D8(f32 a, f32 b, f32 c, f32 d) {
    func_003A3FB0((s32)(a * D_001D96D8), (s32)(c * D_001D96D8), (s32)(b * D_001D96DC), (s32)(d * D_001D96DC));
}
/* localdecomp:end func_003E87D8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E8838);

/* localdecomp:start func_003E8970 */
extern s32 func_003E1BC8();
typedef struct { s32 a[0x12]; s32 x48; } S_E8;
typedef struct { u8 p[0x2C]; S_E8 *x2C; } T_E8;
void func_003E8970(T_E8 *a0) {
    s32 i;
    for (i = 0; i < a0->x2C->x48; i++) {
        s32 *p = (s32 *)((u8 *)(i << 2) + (s32)a0->x2C);
        if (*p != 0) {
            func_003E1BC8(*p);
        }
        *p = 0;
    }
}
/* localdecomp:end func_003E8970 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E89F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8AD0);

/* localdecomp:start func_003E8BF8 */
void func_003E8BF8(void *p, s32 m, s32 set) {
    if (set != 0) {
        *(*(u8 **)((u8 *)p + 0x2C) + 0x4C) |= m;
    } else {
        *(*(u8 **)((u8 *)p + 0x2C) + 0x4C) &= ~m;
    }
}
/* localdecomp:end func_003E8BF8 */

/* localdecomp:start func_003E8C28 */
s32 func_003E8C28(void *a0, s32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    return (*(u8 *)((u8 *)p + 0x4c) & a1) != 0;
}
/* localdecomp:end func_003E8C28 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E8C40);
TEXT_PADDING(2);

/* localdecomp:start func_003E8EA0 */
void func_003E8EA0(u8 *p, f32 a, f32 b, f32 c, f32 d) {
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x50) = a;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x58) = b;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x54) = c;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x5C) = d;
}
/* localdecomp:end func_003E8EA0 */

/* localdecomp:start func_003E8EC8 */
typedef struct O_3E8EC8 O_3E8EC8F;
typedef struct { u8 p0[0x20]; void (*f20)(O_3E8EC8F *, s32, f32 *, s32); } V_3E8EC8;
typedef struct { s32 *tbl[1]; } L_3E8EC8;
typedef struct { u8 p0[0x48]; s32 f48; } L2_3E8EC8;
typedef struct O_3E8EC8 { u8 p0[8]; V_3E8EC8 *f8; u8 pC[0x20]; struct { s32 *e[1]; u8 pad[0x44]; s32 n; } *f2C; } O_3E8EC8;
extern void func_003E8788();
extern s32 func_003E8C28();
extern void func_003E87D8(f32, f32, f32, f32);
extern void func_003E8718();
void func_003E8EC8(O_3E8EC8 *self, s32 b) {
    f32 v[4];
    s32 i;
    self->f8->f20(self, b, v, 1);
    func_003E8788(self, v);
    if (func_003E8C28(self, 1)) {
        func_003E87D8(v[0], v[1], v[2], v[3]);
    }
    for (i = 0; i < self->f2C->n; i++) {
        func_003E8718(((s32 **)self->f2C)[i], b);
    }
    if (func_003E8C28(self, 1)) {
        func_003E87D8(0.0f, 0.0f, 1.0f, 1.0f);
    }
}
/* localdecomp:end func_003E8EC8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E8FB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E90C8);

/* localdecomp:start func_003E91B8 */
s32 func_003E91B8(void) {
    return 7;
}
/* localdecomp:end func_003E91B8 */

/* localdecomp:start func_003E91C0 */
s32 func_003E91C0(s32 p, s32 k) {
    if (k == 7) {
        return 1;
    }
    return func_003E8640(p, k);
}
/* localdecomp:end func_003E91C0 */

LINKER_REMNANT("asm/remnants", func_003E91F0);

/* localdecomp:start func_003E91F8 */
extern void func_003E8420(void);
extern unsigned char D_001D9778[];

void *func_003E91F8(unsigned char *object) {
    register float half __asm__("$f0");
    register float small __asm__("$f1");
    register void *vtable __asm__("$4");
    register void *result __asm__("$2");
    register int color __asm__("$3");

    func_003E8420();
    half = 0.5f;
    vtable = D_001D9778;
    small = 0.01f;
    color = 0x80F00000;
    result = object;
    __asm__ volatile("" : "+r"(result));
    *(void **)(object + 8) = vtable;
    *(int *)(object + 0x30) = color;
    *(float *)(object + 0x18) = half;
    *(float *)(object + 0x34) = small;
    *(float *)(object + 0x1C) = half;
    *(float *)(object + 0x38) = small;
    *(int *)(object + 0x2C) = 0;
    __asm__ volatile("" : "+r"(object));
    return result;
}
/* localdecomp:end func_003E91F8 */

/* localdecomp:start func_003E9260 */
extern s32 D_001D9770_g;
extern s32 func_003E8640(s32, s32);
s32 func_003E9260(s32 p, s32 k) {
    if (k != D_001D9770_g) return func_003E8640(p, k);
    return 1;
}
/* localdecomp:end func_003E9260 */

/* localdecomp:start func_003E9290 */
extern s32 D_001D9770_g;
s32 func_003E9290(void) { return D_001D9770_g; }
/* localdecomp:end func_003E9290 */

/* localdecomp:start func_003E9298 */
void func_003E9298(u8 *p, f32 *a) {
    *(f32 *)(p + 0x10) = a[0] + (a[2] - a[0]) * 0.5f;
    *(f32 *)(p + 0x14) = a[1] + (a[3] - a[1]) * 0.5f;
}
/* localdecomp:end func_003E9298 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E92D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E98B8);

/* localdecomp:start func_003E9B18 */
s32 func_003E9B18(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))((u8 *)p + 0x2C);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003E9B18 */

LINKER_REMNANT("asm/remnants", func_003E9B48);

/* localdecomp:start func_003E9B50 */
extern char D_001D96B0[];
extern s32 func_003ECDB8();
void func_003E9B50(u8 *p, s32 f) {
    *(void **)(p + 8) = D_001D96B0;
    if (f & 1) func_003ECDB8(p);
}
/* localdecomp:end func_003E9B50 */

LINKER_REMNANT("asm/remnants", func_003E9B80);

/* localdecomp:start func_003E9BA8 */
extern void func_003E9C50();
extern void func_003E9D20(void *, s32, s32, s32, s32);
extern void func_003E8420(void);
extern u8 D_001D97A8[];
void *func_003E9BA8(void *arg0)
{
  void **new_var;
  func_003E8420();
  *((s32 *) (((u8 *) arg0) + 0x2C)) = 0;
  *((s32 **) (((u8 *) arg0) + 8)) = D_001D97A8;
  *((s32 *) (((u8 *) arg0) + 0x30)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x38)) = 0x80808080;
  *((s32 *) (((u8 *) arg0) + 0x3C)) = 0x80808080;
  *((s32 *) (((u8 *) arg0) + 0x40)) = 0x80808080;
  *((s32 *) (((u8 *) arg0) + 0x44)) = 0x80808080;
  func_003E9D20(arg0, 0x80F00000, 0x80F00000, 0x80F00000, 0x80F00000);
  *((s32 *) (((u8 *) arg0) + 0x50)) = 0;
  *((f32 *) (((u8 *) arg0) + 0x18)) = 0.5f;
  *((f32 *) (((u8 *) arg0) + 0x1C)) = 0.5f;
  func_003E9C50(arg0, 0);
  new_var = &arg0;
  *((s8 *) (((u8 *) (*new_var)) + 0x4C)) = 0xA;
  *((s16 *) (((u8 *) (*new_var)) + 0x4A)) = 0;
  *((s32 *) (((u8 *) (*new_var)) + 0x34)) = 0;
  *((s8 *) (((u8 *) (*new_var)) + 0x4E)) = 0;
  *((s8 *) (((u8 *) (*new_var)) + 0x4D)) = 0;
  return *new_var;
}
/* localdecomp:end func_003E9BA8 */

/* localdecomp:start func_003E9C50 */
typedef struct S_003E9C50_obj S_003E9C50_obj;
typedef struct {
    u8 pad0[8];
    void (*f8)(S_003E9C50_obj *, s32);
    void (*fC)(S_003E9C50_obj *);
} S_003E9C50_vt;
struct S_003E9C50_obj { s32 f0; S_003E9C50_vt *vt; };
typedef struct {
    u8 pad0[0xC]; s32 fC; u8 pad10[0x38]; u16 f48; u8 pad4A[4]; s8 f4E; u8 pad4F; S_003E9C50_obj *f50;
} S_003E9C50;

void func_003E9C50(S_003E9C50 *arg0, s32 arg1) {
    S_003E9C50_obj *o;

    if (arg0->f48 != arg1) {
        arg0->f48 = arg1;
        if ((u16)arg1 != 0) {
            o = arg0->f50;
            if (o != 0) {
                if ((o->f0 ^ 4) == 0) {
                    o->vt->fC(o);
                }
                if (arg0->fC & 0x8000) {
                    arg0->f4E = 4;
                    return;
                }
                arg0->f50->vt->f8(arg0->f50, arg1 - 1);
            }
        }
    }
}
/* localdecomp:end func_003E9C50 */

/* localdecomp:start func_003E9CE8 */
extern s32 D_001D97A0_g;
extern s32 func_003E8640(s32, s32);
s32 func_003E9CE8(s32 p, s32 k) {
    if (k != D_001D97A0_g) return func_003E8640(p, k);
    return 1;
}
/* localdecomp:end func_003E9CE8 */

/* localdecomp:start func_003E9D18 */
extern s32 D_001D97A0_g;
s32 func_003E9D18(void) {
    return D_001D97A0_g;
}
/* localdecomp:end func_003E9D18 */

/* localdecomp:start func_003E9D20 */
void func_003E9D20(void *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    *(s32 *)((u8 *)a0 + 0x38) = a1;
    *(s32 *)((u8 *)a0 + 0x3c) = a2;
    *(s32 *)((u8 *)a0 + 0x40) = a3;
    *(s32 *)((u8 *)a0 + 0x44) = a4;
}
/* localdecomp:end func_003E9D20 */

/* localdecomp:start func_003E9D38 */
void func_003E9D38(u8 *p, f32 *a) {
    *(f32 *)(p + 0x10) = a[0] + (a[2] - a[0]) * 0.5f;
    *(f32 *)(p + 0x14) = a[1] + (a[3] - a[1]) * 0.5f;
}
/* localdecomp:end func_003E9D38 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E9D78);

INCLUDE_ASM("asm/nonmatchings/text", func_003EA078);

INCLUDE_ASM("asm/nonmatchings/text", func_003EA290);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318C90);

INCLUDE_ASM("asm/nonmatchings/text", func_003EA648);

/* localdecomp:start func_003EA8A8 */
s32 func_003EA8A8(void *arg0, s32 arg1) {
    s32 (*temp_v0)(s32);
    s32 temp_v1;
    void *temp_a0;

    if ((*(u16 *)((u8 *)(arg0) + 0x48)) != 0) {
        temp_a0 = (*(void **)((u8 *)(arg0) + 0x50));
        if ((temp_a0 != 0) && ((temp_v1 = (*(s32 *)((u8 *)(temp_a0) + 0)), ((temp_v1 ^ 1) == 0)) || ((temp_v1 ^ 8) == 0))) {
            (*(s32 (**)(void *, s32))((u8 *)((*(void **)((u8 *)(temp_a0) + 4))) + 8))(temp_a0, (*(u16 *)((u8 *)(arg0) + 0x48)) - 1);
        }
    }
    temp_v0 = (*(s32 (**)(s32))((u8 *)(arg0) + 0x34));
    if (temp_v0 != 0) {
        temp_v0(arg1);
    }
    return 0;
}
/* localdecomp:end func_003EA8A8 */

/* localdecomp:start func_003EA930 */
void func_003EA930(void *p, s32 v) {
    *((u8 *)p + 0x4C) = v;
    if ((u8)v == 0) {
        *((u8 *)p + 0x4C) = 1;
    }
}
/* localdecomp:end func_003EA930 */

/* localdecomp:start func_003EA950 */
extern char D_001D96B0[];
extern s32 func_003ECDB8();
void func_003EA950(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D96B0; if (f & 1) func_003ECDB8(p); }
/* localdecomp:end func_003EA950 */

LINKER_REMNANT("asm/remnants", func_003EA980);

/* localdecomp:start func_003EA9A8 */
s32 func_003EA9A8(void) {
    return 2;
}
/* localdecomp:end func_003EA9A8 */

/* localdecomp:start func_003EA9B0 */
extern void func_003E8420(void);
extern u8 D_001D97D8[];
void *func_003EA9B0(void *arg0) {
    func_003E8420();
    (*(s32 **)((u8 *)arg0 + 8)) = D_001D97D8;
    (*(s32 *)((u8 *)arg0 + 0x50)) = 0x80808080;
    (*(s8 *)((u8 *)arg0 + 0x54)) = 0x10;
    (*(s32 *)((u8 *)arg0 + 0x2C)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x30)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x38)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x3C)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x40)) = 0;
    (*(s8 *)((u8 *)arg0 + 0x44)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x48)) = 0;
    (*(f32 *)((u8 *)arg0 + 0x4C)) = 1.0f;
    (*(s32 *)((u8 *)arg0 + 0x34)) = 0;
    (*(f32 *)((u8 *)arg0 + 0x5C)) = 1.0f;
    (*(f32 *)((u8 *)arg0 + 0x60)) = 1.0f;
    (*(s32 *)((u8 *)arg0 + 0x58)) = 2;
    return arg0;
}
/* localdecomp:end func_003EA9B0 */

/* localdecomp:start func_003EAA38 */
void func_003EAA38(u8 *p, u8 m, s32 set) {
    if (set != 0) {
        p[0x44] |= m;
    } else {
        p[0x44] &= ~m;
    }
}
/* localdecomp:end func_003EAA38 */

/* localdecomp:start func_003EAA68 */
s32 func_003EAA68(void *a0, s32 a1) {
    s32 b = a1 & 0xff;
    return (*(u8 *)((u8 *)a0 + 0x44) & b) != 0;
}
/* localdecomp:end func_003EAA68 */

/* localdecomp:start func_003EAA80 */
void func_003EAA80(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x48) = x;
    *(f32 *)((u8 *)p + 0x4C) = y;
}
/* localdecomp:end func_003EAA80 */

/* localdecomp:start func_003EAA90 */
void func_003EAA90(u8 *p, f32 *a) {
    *(f32 *)(p + 0x10) = a[0] + (a[2] - a[0]) * 0.5f;
    *(f32 *)(p + 0x14) = a[1] + (a[3] - a[1]) * 0.5f;
}
/* localdecomp:end func_003EAA90 */

INCLUDE_ASM("asm/nonmatchings/text", func_003EAAD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003EAC88);

/* localdecomp:start func_003EB0D0 */
s32 func_003EB0D0(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))((u8 *)p + 0x34);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003EB0D0 */

/* localdecomp:start func_003EB100 */
s32 func_003EB100(s32 p, s32 k) {
    if (k != 2) {
        return func_003E8640(p, k);
    }
    return 1;
}
/* localdecomp:end func_003EB100 */

/* localdecomp:start func_003EB130 */
extern char D_001D96B0[];
extern s32 func_003ECDB8();
void func_003EB130(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D96B0; if (f & 1) func_003ECDB8(p); }
/* localdecomp:end func_003EB130 */

LINKER_REMNANT("asm/remnants", func_003EB160);

/* localdecomp:start func_003EB178 */
s32 func_003EB178(void) {
    return 3;
}
/* localdecomp:end func_003EB178 */

INCLUDE_ASM("asm/nonmatchings/text", func_003EB180);

/* localdecomp:start func_003EB358 */
s32 *func_003E16B8_003EB358(s32 *);                  /* extern */
void **func_003E1770_003EB358(s32 *, s32);           /* extern */
void func_003ECDB8_003EB358(void *);
extern u8 D_001D96B0_003EB358;
extern u8 D_001D9808;
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003EB358;
extern S_001DA9B8_003EB358 D_001DA9B8_003EB358[];

void func_003EB358(void *arg0, s32 arg1) {
    s32 *var_v0;
    void **temp_v0;

    (*(s32 **)((u8 *)(arg0) + 8)) = (s32 *)&D_001D9808;
    if (D_001DA9B8_003EB358->f4 != 0) {
        var_v0 = (s32 *)D_001DA9B8_003EB358;
    } else {
        var_v0 = func_003E16B8_003EB358((s32 *)D_001DA9B8_003EB358);
    }
    temp_v0 = func_003E1770_003EB358(var_v0, 1);
    if (temp_v0 != 0) {
        (*(s32 (**)(void **, s32))((u8 *)(*temp_v0) + 0xC))(temp_v0, (*(s32 *)((u8 *)(arg0) + 0x2C)));
        (*(s32 *)((u8 *)(arg0) + 0x2C)) = 0;
    }
    (*(s32 **)((u8 *)(arg0) + 8)) = (s32 *)&D_001D96B0_003EB358;
    if (arg1 & 1) {
        func_003ECDB8_003EB358(arg0);
    }
}
/* localdecomp:end func_003EB358 */

/* localdecomp:start func_003EB3F8 */
void func_003EB3F8(void *p, s32 value) {
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x34) = value;
}
/* localdecomp:end func_003EB3F8 */

/* localdecomp:start func_003EB408 */
void func_003EB408(u8 *p) {
    u8 *q;
    s32 v;
    (*(u8 **)(p + 0x2C))[0x59] = 0;
    q = *(u8 **)(p + 0x2C);
    v = 0;
    if (*(u16 *)(q + 0x48) & 8) v = *(u16 *)(q + 0x4C);
    *(s16 *)(q + 0x56) = v;
    (*(u8 **)(p + 0x2C))[0x5A] = 0;
    *(s32 *)(*(u8 **)(p + 0x2C) + 0x40) = 0;
}
/* localdecomp:end func_003EB408 */

/* localdecomp:start func_003EB440 */
typedef struct { u8 pad[0x10]; s32 w10; u8 p2[0x48-0x14]; u16 h48; } Q_3EB440;
typedef struct { u8 pad[0x2C]; Q_3EB440 *q; u8 b30; u8 p3[3]; s32 w34; } S_3EB440;
extern void func_003EB408();
void func_003EB440(S_3EB440 *p, s32 b) {
    Q_3EB440 *q = p->q;
    if (q->w10 != b && (q->h48 & 0x20)) {
        func_003EB408((u8 *)p);
        p->b30 = 0;
        p->w34 = 0;
    }
    p->q->w10 = b;
}
/* localdecomp:end func_003EB440 */

/* localdecomp:start func_003EB4A8 */
void func_003EB4A8(void *a0, f32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(f32 *)((u8 *)p + 0x28) = a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003EB4A8 */

/* localdecomp:start func_003EB4C0 */
void func_003EB4C0(void *p, s32 a, s16 b, s16 c, s32 d) {
    *(s16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x18) = b;
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x14) = a;
    *(s16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x1A) = c;
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x38) = d;
}
/* localdecomp:end func_003EB4C0 */

/* localdecomp:start func_003EB4E8 */
void func_003EB4E8(void *a0, f32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(f32 *)((u8 *)p + 0x44) = a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003EB4E8 */

/* localdecomp:start func_003EB500 */
s32 func_003EB500(void *a0, f32 *a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *a1 = *(f32 *)((u8 *)p + 0x44);
    return 1;
}
/* localdecomp:end func_003EB500 */

/* localdecomp:start func_003EB518 */
s32 func_003EB518(u32 a0, u32 a1, u32 a2) {
    u32 ptr;

    ptr = *(u32 *)(a0 + 0x2C);
    *(float *)(a1 + 0x00) = *(float *)(ptr + 0x2C);

    ptr = *(u32 *)(a0 + 0x2C);
    *(float *)(a2 + 0x00) = *(float *)(ptr + 0x30);

    return 1;
}
/* localdecomp:end func_003EB518 */

/* localdecomp:start func_003EB538 */
void func_003EB538(u8 *p, s32 a, f32 x, f32 y) {
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x3C) = x;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x40) = y;
    *(s16 *)(*(u8 **)(p + 0x2C) + 0x56) = 0;
    {
        u8 *q = *(u8 **)(p + 0x2C);
        if (a != 0) q[0x59] = 0;
        else q[0x59] = 1;
    }
    p[0x30] = 0;
    *(s32 *)(p + 0x34) = 0;
}
/* localdecomp:end func_003EB538 */

/* localdecomp:start func_003EB578 */
void func_003EB578(void *p, f32 value) {
    *(f32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x50) = value;
}
/* localdecomp:end func_003EB578 */

/* localdecomp:start func_003EB588 */
void func_003EB588(void *p, s16 value) {
    *(s16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x4C) = value;
}
/* localdecomp:end func_003EB588 */

/* localdecomp:start func_003EB598 */
void func_003EB598(void *p, s16 value) {
    *(s16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x54) = value;
}
/* localdecomp:end func_003EB598 */

/* localdecomp:start func_003EB5A8 */
void func_003EB5A8(u8 *p, s32 m, s32 on) {
    if (on) *(u16 *)(*(u8 **)(p + 0x2C) + 0x48) |= m;
    else *(u16 *)(*(u8 **)(p + 0x2C) + 0x48) &= ~m;
    p[0x30] = 0;
    *(s32 *)(p + 0x34) = 0;
}
/* localdecomp:end func_003EB5A8 */

LINKER_REMNANT("asm/remnants", func_003EB5E8);

/* localdecomp:start func_003EB5F0 */
void func_003EB5F0(void *p, s32 *a, s32 *b) {
    *a = *(u16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x48) & 1;
    *b = ((*(u16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x48) >> 1) ^ 1) & 1;
}
/* localdecomp:end func_003EB5F0 */

/* localdecomp:start func_003EB620 */
void func_003EB5A8_003EB620(void *, s32, s32);

s32 func_003EB620(u8 *arg0, s32 arg1, s32 arg2) {
    s32 a = 0;
    s32 ok = 1;
    s32 b = 0;

    if (arg1 != 0) {
        if (arg1 == 1) {
            a = 1;
        } else {
            ok = 0;
        }
    }
    if (arg2 == 0) {
        b = 1;
    } else if (arg2 != 1) {
        ok = 0;
    }
    func_003EB5A8_003EB620(arg0, 1, a);
    func_003EB5A8_003EB620(arg0, 2, b);
    *(s8 *)(arg0 + 0x30) = 0;
    *(s32 *)(arg0 + 0x34) = 0;
    return ok;
}
/* localdecomp:end func_003EB620 */

/* localdecomp:start func_003EB6B0 */
extern void func_003E8600(void *, f32, f32);
void func_003EB6B0(u8 *object, f32 *bounds) {
    register f32 x __asm__("$f12") = bounds[0];
    register f32 half __asm__("$f2") = 0.5f;
    register f32 temp __asm__("$f1") = bounds[2];
    register f32 y __asm__("$f13") = bounds[1];
    register f32 other __asm__("$f0") = bounds[3];
    temp -= x;
    other -= y;
    temp *= half;
    x += temp;
    temp = other * half;
    y += temp;
    func_003E8600(object, x, y);
    *(volatile s32 *)(object + 0x34) = 0;
    *(volatile u8 *)(object + 0x30) = 0;
}
/* localdecomp:end func_003EB6B0 */

/* localdecomp:start func_003EB710 */
void func_003EB710(void *a0, s32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(u8 *)((u8 *)p + 0x58) = (u8)a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003EB710 */

INCLUDE_ASM("asm/nonmatchings/text", func_003EB728);

INCLUDE_ASM("asm/nonmatchings/text", func_003EC3D0);

/* localdecomp:start func_003EC630 */
s32 func_003EC630(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))(*(u8 **)((u8 *)p + 0x2C) + 0x8);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003EC630 */

/* localdecomp:start func_003EC660 */
s32 func_003EC660(s32 p, s32 k) {
    if (k != 3) {
        return func_003E8640(p, k);
    }
    return 1;
}
/* localdecomp:end func_003EC660 */

LINKER_REMNANT("asm/remnants", func_003EC690);

/* localdecomp:start func_003EC6E0 */
extern void func_003E8568(void *, s32, s32);
extern void func_003E8420(void);
extern u8 D_001D9838[];
void *func_003EC6E0(void *arg0)
{
  func_003E8420();
  *((s32 *) (((u8 *) arg0) + 0x2C)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x30)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x44)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x40)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x34)) = 0;
  *((s32 **) (((u8 *) arg0) + 8)) = D_001D9838;
  *((f32 *) (((u8 *) arg0) + 0x14)) = (*((f32 *) (((u8 *) arg0) + 0x10)) = 0.5f);
  *((s32 *) (((u8 *) arg0) + 0x38)) = 0x60F00000;
  *((f32 *) (((u8 *) arg0) + 0x18)) = 1.0f;
  *((f32 *) (((u8 *) arg0) + 0x1C)) = 1.0f;
  func_003E8568(arg0, 0x100, 1);
  return arg0;
}
/* localdecomp:end func_003EC6E0 */

/* localdecomp:start func_003EC760 */
extern s32 D_001D9830_g;
extern s32 func_003E8640(s32, s32);
s32 func_003EC760(s32 p, s32 k) {
    if (k != D_001D9830_g) return func_003E8640(p, k);
    return 1;
}
/* localdecomp:end func_003EC760 */

/* localdecomp:start func_003EC790 */
extern s32 D_001D9830_g;
s32 func_003EC790(void) {
    return D_001D9830_g;
}
/* localdecomp:end func_003EC790 */

/* localdecomp:start func_003EC798 */
void func_003EC798(u8 *p, f32 *a) {
    *(f32 *)(p + 0x10) = a[0] + (a[2] - a[0]) * 0.5f;
    *(f32 *)(p + 0x14) = a[1] + (a[3] - a[1]) * 0.5f;
}
/* localdecomp:end func_003EC798 */

INCLUDE_ASM("asm/nonmatchings/text", func_003EC7D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003EC960);

/* localdecomp:start func_003ECB80 */
s32 func_003ECB80(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))((u8 *)p + 0x34);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003ECB80 */

/* localdecomp:start func_003ECBB0 */
extern char D_001D96B0[];
extern s32 func_003ECDB8();
void func_003ECBB0(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D96B0; if (f & 1) func_003ECDB8(p); }
/* localdecomp:end func_003ECBB0 */

LINKER_REMNANT("asm/remnants", func_003ECBE0);

/* localdecomp:start func_003ECC20 */
void func_003ECC20(s32 *p, s32 a, s32 b, s32 c) {
    p[1] = b;
    p[2] = c;
    p[3] = a;
    p[6] = 0;
    p[4] = 0;
    p[5] = 0;
}
/* localdecomp:end func_003ECC20 */

/* localdecomp:start func_003ECC40 */
extern u8 D_001D9880[];
void **func_003ECC40(void **p) { p[1] = 0; p[0] = D_001D9880; p[2] = 0; p[3] = 0; p[6] = 0; p[4] = 0; p[5] = 0; return p; }
/* localdecomp:end func_003ECC40 */
