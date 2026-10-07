#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern s32 func_003F2578();
extern s32 func_003EE1B0();
extern void *func_003F1EA0();
extern void *func_003EF368();
extern void *func_003F0170();
extern void **func_003F2400(void **);
void func_003F00F0(void *, s32);
extern void func_003F0240(void *p, f32, f32);
extern void func_003F01F8(u8 *p, u8, s32);
extern void func_003EE3B8(void *p, s32, s32);
extern s32 func_003F0DE0(u8 *arg0, s32, s32);
extern s32 func_003EBF78(void *, s32, void *);
extern s32 func_003EAB38(u8 *p, f32 a, f32 b);
extern s32 func_003EAC70(u8 *p, s32 a, s32 b);
extern s32 func_003EADA8(u8 *p, s32 a);
extern s32 func_003EAEC8(u8 *p, f32 a, f32 b);
extern s32 func_003EAF30(u8 *p, s32 a);
extern s32 func_003EB050(u8 *p, s32 a, s32 b);
extern s32 func_003EB188(u8 *p, s32 a, u8 *out);
extern s32 func_003EB2C0(u8 *p, s32 a, s32 b);
extern s32 func_003EB328(u8 *p, s32 a, s32 b);
extern s32 func_003EB460(u8 *p, f32 a, f32 b);
extern s32 func_003EB4C8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003EB670(u8 *p, s32 a);
extern s32 func_003EB798(u8 *p, f32 a, f32 b);
extern s32 func_003EB808(u8 *p, s32 a, s32 b);
extern s32 func_003EB870(u8 *p, s32 a);
extern s32 func_003EB8C8(u8 *p, s32 a, s16 b, s16 c, s32 d);
extern s32 func_003EBA28(u8 *p, f32 a, f32 b);
extern s32 func_003EBA98(u8 *p, s32 a);
extern s32 func_003EBAF0(u8 *p, s32 a, s32 b);
extern s32 func_003EBB58(u8 *p, s32 a, u8 *out);
extern s32 func_003EBBC0(u8 *p, s32 a, s32 b);
extern s32 func_003EBC28(u8 *p, s32 a, s32 b);
extern s32 func_003EBC90(u8 *p, f32 a, f32 b);
extern s32 func_003EBCF8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003EBDD0(u8 *p, f32 a, f32 b);
extern s32 func_003EBF18(u8 *p, f32 a);
extern s32 func_003EC050(u8 *p, f32 a);
extern s32 func_003EC0B0(u8 *p, f32 a, f32 b);
extern s32 func_003EC120(u8 *p, s32 a);
extern s32 func_003EC248(u8 *p, s32 a, s32 b);
extern s32 func_003EC2B0(u8 *p, s32 a);
extern s32 func_003EC308(u8 *p, f32 a, f32 b);
extern s32 func_003EC370(u8 *p, s32 a, s32 b);
extern s32 func_003EC3D8(u8 *p, f32 a, f32 b);
extern s32 func_003EC440();
extern s32 func_003EC4A8();
extern s32 func_003EC508(u8 *p, s32 a, s32 b);
extern s32 func_003EC570(u8 *p, s32 a, u8 *out);
extern s32 func_003EC5D8(u8 *p, s32 a, s32 b);
extern s32 func_003EC640(u8 *p, s32 a, s32 b);
extern s32 func_003EC6A8(u8 *p, f32 a, f32 b);
extern s32 func_003EC710(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003EC7E8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_003EC940(u8 *p, f32 a);
extern s32 func_003ECA68(u8 *p, f32 a, f32 b);
extern s32 func_003ECAD0(u8 *p, s32 a, s32 b);
extern s32 func_003ECB38(u8 *p, f32 a, f32 b);
extern s32 func_003ECBA0(u8 *p, s32 a);
extern s32 func_003ECBF0(u8 *p, s32 a, s32 b);
extern s32 func_003ECC58(u8 *p, s32 a, u8 *out);
extern s32 func_003ECCC0(u8 *p, s32 a, s32 b);
extern s32 func_003ECD28(u8 *p, s32 a, s32 b);
extern s32 func_003ECD90(u8 *p, f32 a, f32 b);
extern s32 func_003ECDF8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003ECED0(u8 *p, f32 a, f32 b);
extern s32 func_003ECF38(u8 *p, f32 a, f32 b);
extern s32 func_003ECFA0(u8 *p, s32 a, s32 b);
extern s32 func_003ED008(u8 *p, f32 a, f32 b);
extern s32 func_003ED070(u8 *p, s32 a);
extern s32 func_003ED0C0();
extern s32 func_003ED1F0(u8 *p, s32 a, s32 b);
extern s32 func_003ED258(u8 *p, s32 a, u8 *out);
extern s32 func_003ED2C0(u8 *p, s32 a, s32 b);
extern s32 func_003ED328(u8 *p, s32 a, s32 b);
extern s32 func_003ED390(u8 *p, f32 a, f32 b);
extern s32 func_003ED3F8(u8 *p, f32 a);
extern s32 func_003ED450(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003ED528(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern s32 func_003ED688();
extern s32 func_003ED6E0();
extern s32 func_003ED800(u8 *p, s32 a, s32 b);
extern s32 func_003ED868(u8 *p, s32 a, u8 *out);
extern s32 func_003ED8D0(u8 *p, s32 a, s32 b);
extern s32 func_003ED938(u8 *p, s32 a, s32 b);
extern s32 func_003ED9A0(u8 *p, f32 a, f32 b);
extern s32 func_003EDA08(u8 *p, f32 a, f32 b);
extern s32 func_003EDA78(u8 *p, s32 a, s32 b);
extern s32 func_003EDAE0(u8 *p, f32 a, f32 b);
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
extern void *func_003EE9B8();
extern void *func_003F0940();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003EAB38 */
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
extern s32 D_001D97D0[];
s32 func_003EAB38(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EAB38 */

/* localdecomp:start func_003EABA0 */
extern u8 D_001DAA89;
extern void *func_003E9F50(HT_8 *, u32);
s32 func_003EABA0(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E9F50(t, key) != 0) return 0;
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
/* localdecomp:end func_003EABA0 */

/* localdecomp:start func_003EAC70 */
extern s32 D_001D97D0_g;
extern void func_003EDDD0();
s32 func_003EAC70(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) {
        func_003EDDD0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EAC70 */

/* localdecomp:start func_003EACD8 */
extern u8 D_001DAA8A;
extern void *func_003E9FD0(HT_8 *, u32);
s32 func_003EACD8(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003E9FD0(t, key) != 0) return 0;
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
/* localdecomp:end func_003EACD8 */

/* localdecomp:start func_003EADA8 */
extern s32 D_001D97D0_g;
s32 func_003EADA8(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) {
        *(s32 *)(p + 0x3C) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EADA8 */

/* localdecomp:start func_003EADF8 */
extern u8 D_001DAA92;
extern void *func_003EA3E0(HT_8 *, u32);
s32 func_003EADF8(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA3E0(t, key) != 0) return 0;
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
/* localdecomp:end func_003EADF8 */

/* localdecomp:start func_003EAEC8 */
extern s32 D_001D97D0[];
s32 func_003EAEC8(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EAEC8 */

/* localdecomp:start func_003EAF30 */
extern s32 D_001D97D0_g;
s32 func_003EAF30(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) {
        *(s32 *)(p + 0x50) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EAF30 */

/* localdecomp:start func_003EAF80 */
extern u8 D_001DAA94;
extern void *func_003EA4E0(HT_8 *, u32);
s32 func_003EAF80(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA4E0(t, key) != 0) return 0;
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
/* localdecomp:end func_003EAF80 */

/* localdecomp:start func_003EB050 */
extern s32 D_001D97D0_g;
extern void func_003EDD28(void *, s32, s32);
s32 func_003EB050(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) {
        func_003EDD28(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB050 */

/* localdecomp:start func_003EB0B8 */
extern u8 D_001DAA8E;
extern void *func_003EA1E0(HT_8 *, u32);
s32 func_003EB0B8(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA1E0(t, key) != 0) return 0;
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
/* localdecomp:end func_003EB0B8 */

/* localdecomp:start func_003EB188 */
extern s32 D_001D97D0_g;
extern s32 func_003EDD50();
s32 func_003EB188(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) {
        *out = func_003EDD50(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB188 */

/* localdecomp:start func_003EB1F0 */
extern u8 D_001DAA8F;
extern void *func_003EA260(HT_8 *, u32);
s32 func_003EB1F0(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA260(t, key) != 0) return 0;
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
/* localdecomp:end func_003EB1F0 */

/* localdecomp:start func_003EB2C0 */
extern s32 D_001D97D0_g;
extern void func_003EDD60(void *, s32, s32);
s32 func_003EB2C0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) {
        func_003EDD60(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB2C0 */

/* localdecomp:start func_003EB328 */
extern s32 D_001D97D0_g;
extern void func_003EDD98();
s32 func_003EB328(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) {
        func_003EDD98(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB328 */

/* localdecomp:start func_003EB390 */
extern u8 D_001DAA90;
extern void *func_003EA2E0(HT_8 *, u32);
s32 func_003EB390(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA2E0(t, key) != 0) return 0;
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
/* localdecomp:end func_003EB390 */

/* localdecomp:start func_003EB460 */
extern s32 D_001D97D0[];
s32 func_003EB460(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB460 */

/* localdecomp:start func_003EB4C8 */
typedef struct { u8 b[16]; } V16_func_003E5D08;
extern s32 D_001D97D0_func_003E5D08;
extern V16_func_003E5D08 D_001D9700_func_003E5D08;
s32 func_003EB4C8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
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
/* localdecomp:end func_003EB4C8 */

/* localdecomp:start func_003EB5A0 */
extern u8 D_001DAA91;
extern void *func_003EA360(HT_8 *, u32);
s32 func_003EB5A0(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA360(t, key) != 0) return 0;
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
/* localdecomp:end func_003EB5A0 */

/* localdecomp:start func_003EB670 */
extern s32 D_001D97D0_g;
s32 func_003EB670(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) {
        *(s32 *)(p + 0x58) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB670 */

/* localdecomp:start func_003EB6C0 */
typedef struct {
    u8 pad0[4];
    s32 count;
    struct {
        u32 key;
        void *value;
    } entries[3];
} Table_003E5F00;

extern u8 D_001DAA95;
extern void *func_003EA560(void *, u32);

s32 func_003EB6C0(Table_003E5F00 *input_table, u32 input_key, void *input_value) {
    register Table_003E5F00 *table __asm__("$17") = input_table;
    register u32 key __asm__("$16") = input_key;
    register void *value __asm__("$18") = input_value;

    if (table->count < 3 && func_003EA560(table, key) == 0) {
        register s32 iteration __asm__("$8") = 0;
        register s32 divisor __asm__("$6") = 3;
        register s32 parity __asm__("$11") = key & 1;
        register u8 *value_base __asm__("$9") = (u8 *)table + 0xC;
        register void *sentinel __asm__("$12") = &D_001DAA95;
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
/* localdecomp:end func_003EB6C0 */

/* localdecomp:start func_003EB798 */
extern s32 D_001D9800[];
extern void func_003EDDC0(void *, f32, f32);
s32 func_003EB798(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800[0])) {
        func_003EDDC0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB798 */

/* localdecomp:start func_003EB808 */
extern s32 D_001D9800_g;
extern void func_003EDDD0();
s32 func_003EB808(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003EDDD0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB808 */

/* localdecomp:start func_003EB870 */
extern s32 D_001D9800_g;
extern void func_003F0C00();
s32 func_003EB870(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003F0C00(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB870 */

/* localdecomp:start func_003EB8C8 */
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
extern s32 D_001D9800_003EB8C8;
extern void func_003F0C80(void *, s32, s16, s16, s32);
s32 func_003EB8C8(u8 *p, s32 a, s16 b, s16 c, s32 d) {
    if ((*(VT_3E6108 **)(p + 8))->isA(p, D_001D9800_003EB8C8)) {
        func_003F0C80(p, a, b, c, d);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB8C8 */

/* localdecomp:start func_003EB958 */
extern u8 D_001DAA93;
extern void *func_003EA460(HT_8 *, u32);
s32 func_003EB958(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA460(t, key) != 0) return 0;
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
/* localdecomp:end func_003EB958 */

/* localdecomp:start func_003EBA28 */
extern s32 D_001D9800[];
extern void func_003EDDE8(void *, f32, f32);
s32 func_003EBA28(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800[0])) {
        func_003EDDE8(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBA28 */

/* localdecomp:start func_003EBA98 */
extern s32 D_001D9800_g;
extern void func_003F0BB8(void *, s32);
s32 func_003EBA98(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003F0BB8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBA98 */

/* localdecomp:start func_003EBAF0 */
extern s32 D_001D9800_g;
extern void func_003EDD28(void *, s32, s32);
s32 func_003EBAF0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003EDD28(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBAF0 */

/* localdecomp:start func_003EBB58 */
extern s32 D_001D9800_g;
extern s32 func_003EDD50();
s32 func_003EBB58(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        *out = func_003EDD50(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBB58 */

/* localdecomp:start func_003EBBC0 */
extern s32 D_001D9800_g;
extern void func_003EDD60(void *, s32, s32);
s32 func_003EBBC0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003EDD60(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBBC0 */

/* localdecomp:start func_003EBC28 */
extern s32 D_001D9800_g;
extern void func_003EDD98();
s32 func_003EBC28(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003EDD98(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBC28 */

/* localdecomp:start func_003EBC90 */
extern s32 D_001D9800[];
s32 func_003EBC90(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBC90 */

/* localdecomp:start func_003EBCF8 */
typedef struct { u8 b[16]; } V16_003E6538;
extern s32 D_001D9800_003EBCF8;
extern V16_003E6538 D_001D9700;
s32 func_003EBCF8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    V16_003E6538 v;
    f32 out[4];
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D9800_003EBCF8) != 0) {
        v = D_001D9700;
        (*(s32 (**)(void *, void *, f32 *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x20))(arg0, &v, out, 1);
        *arg1 = out[0];
        *arg2 = out[1];
        *arg3 = out[2];
        *arg4 = out[3];
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBCF8 */

/* localdecomp:start func_003EBDD0 */
extern s32 D_001D9800[];
extern void func_003F0CF8(u8 *, s32, f32, f32);
s32 func_003EBDD0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800[0])) {
        func_003F0CF8(p, 1, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBDD0 */

/* localdecomp:start func_003EBE40 */
typedef struct {
    u8 pad0[4];
    s32 count;
    struct { u32 key; void *value; } entries[3];
} Table_003E6680;

extern u8 D_001DAA8B;
extern void *func_003EA050(void *, u32);

s32 func_003EBE40(Table_003E6680 *input_table, u32 input_key, void *input_value) {
    register Table_003E6680 *table __asm__("$17") = input_table;
    register u32 key __asm__("$16") = input_key;
    register void *value __asm__("$18") = input_value;

    if (table->count < 3 && func_003EA050(table, key) == 0) {
        register s32 iteration __asm__("$8") = 0;
        register s32 divisor __asm__("$6") = 3;
        register s32 parity __asm__("$11") = key & 1;
        register u8 *value_base __asm__("$9") = (u8 *)table + 0xC;
        register void *sentinel __asm__("$12") = &D_001DAA8B;
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
/* localdecomp:end func_003EBE40 */

/* localdecomp:start func_003EBF18 */
extern s32 D_001D9800[];
extern void func_003F0C68(void *, f32);
s32 func_003EBF18(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800[0])) {
        func_003F0C68(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EBF18 */

/* localdecomp:start func_003EBF78 */
extern s32 D_001DAA8C_003EBF78;
__asm__(".extern D_001DAA8C_003EBF78, 4");
typedef struct { s32 key; s32 val; } E;
typedef struct { s32 pad; s32 n; E e[3]; } T;
extern s32 func_003EA0D8();
s32 func_003EBF78(void *pp, s32 k, void *v) {
    T *p = pp;
    if (p->n < 3) {
        if (func_003EA0D8() == 0) {
            s32 i;
            for (i = 0; i < 3; i++) {
                s32 t = (u32)k % 3; s32 b = k & 1;
                s32 idx = (u32)(t + i * (b + 1)) % 3;
                if (p->e[idx].val == 0 || p->e[idx].val == (s32)&D_001DAA8C_003EBF78) {
                    p->e[idx].val = (s32)v;
                    p->e[idx].key = k;
                    p->n++;
                    return 1;
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_003EBF78 */

/* localdecomp:start func_003EC050 */
extern s32 D_001D9800[];
extern void func_003F0CA8(void *, f32);
s32 func_003EC050(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800[0])) {
        func_003F0CA8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC050 */

/* localdecomp:start func_003EC0B0 */
extern s32 D_001D9800[];
extern void func_003F0CF8(u8 *, s32, f32, f32);
s32 func_003EC0B0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800[0])) {
        func_003F0CF8(p, 1, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC0B0 */

/* localdecomp:start func_003EC120 */
extern s32 D_001D9800_g;
extern s32 func_003F0CC0();
s32 func_003EC120(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003F0CC0(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC120 */

/* localdecomp:start func_003EC178 */
extern u8 D_001DAA99;
extern void *func_003EA768(HT_8 *, u32);
s32 func_003EC178(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA768(t, key) != 0) return 0;
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
/* localdecomp:end func_003EC178 */

/* localdecomp:start func_003EC248 */
extern s32 D_001D9800_g;
extern s32 func_003F0CD8();
s32 func_003EC248(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003F0CD8(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC248 */

/* localdecomp:start func_003EC2B0 */
extern s32 D_001D9800_g;
extern void func_003F0ED0(void *, s32);
s32 func_003EC2B0(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003F0ED0(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC2B0 */

/* localdecomp:start func_003EC308 */
extern s32 D_001D97A0[];
s32 func_003EC308(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97A0[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC308 */

/* localdecomp:start func_003EC370 */
extern s32 D_001D97A0_g;
extern void func_003EDDD0();
s32 func_003EC370(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97A0_g)) {
        func_003EDDD0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC370 */

/* localdecomp:start func_003EC3D8 */
extern s32 D_001D97A0[];
s32 func_003EC3D8(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97A0[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC3D8 */

/* localdecomp:start func_003EC440 */
typedef struct V_3E6C80 { u8 pad[0x10]; s32 (*fn)(void *, s32); } V_3E6C80;
typedef struct { u8 pad[8]; V_3E6C80 *vt; } O_3E6C80;
extern s32 D_001D97A0_003EC440;
extern void func_003EF4E0();
s32 func_003EC440(O_3E6C80 *a, s32 b) {
    if (a->vt->fn(a, D_001D97A0_003EC440) != 0) {
        func_003EF4E0(a, b, b, b, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC440 */

/* localdecomp:start func_003EC4A8 */
typedef struct S_3E6CE8 S_3E6CE8;
typedef struct { u8 pad[0x10]; s32 (*fn)(S_3E6CE8 *, s32); } V_3E6CE8;
struct S_3E6CE8 { u8 pad[8]; V_3E6CE8 *vt; u8 p2[0x4A-0xC]; s16 h4A; };
extern s32 D_001D97A0_003EC4A8;
extern void func_003EF410();
s32 func_003EC4A8(S_3E6CE8 *p, s32 b) {
    s32 r;
    if (!p->vt->fn(p, D_001D97A0_003EC4A8)) r = 0; else {
        func_003EF410(p, b);
        p->h4A = 0;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_003EC4A8 */

/* localdecomp:start func_003EC508 */
extern s32 D_001D97A0_g;
extern void func_003EDD28(void *, s32, s32);
s32 func_003EC508(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97A0_g)) {
        func_003EDD28(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC508 */

/* localdecomp:start func_003EC570 */
extern s32 D_001D97A0_g;
extern s32 func_003EDD50();
s32 func_003EC570(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97A0_g)) {
        *out = func_003EDD50(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC570 */

/* localdecomp:start func_003EC5D8 */
extern s32 D_001D97A0_g;
extern void func_003EDD60(void *, s32, s32);
s32 func_003EC5D8(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97A0_g)) {
        func_003EDD60(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC5D8 */

/* localdecomp:start func_003EC640 */
extern s32 D_001D97A0_g;
extern void func_003EDD98();
s32 func_003EC640(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97A0_g)) {
        func_003EDD98(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC640 */

/* localdecomp:start func_003EC6A8 */
extern s32 D_001D97A0[];
s32 func_003EC6A8(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97A0[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC6A8 */

/* localdecomp:start func_003EC710 */
typedef struct { u8 b[16]; } V16_003E6F50;
extern s32 D_001D97A0_003EC710;
extern V16_003E6F50 D_001D9700_003EC710;
s32 func_003EC710(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    V16_003E6F50 v;
    f32 out[4];
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D97A0_003EC710) != 0) {
        v = D_001D9700_003EC710;
        (*(s32 (**)(void *, void *, f32 *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x20))(arg0, &v, out, 1);
        *arg1 = out[0];
        *arg2 = out[1];
        *arg3 = out[2];
        *arg4 = out[3];
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC710 */

/* localdecomp:start func_003EC7E8 */
extern void func_003EF4E0(void *, s32, s32, s32, s32);
extern s32 D_001D97A0_003EC7E8;
s32 func_003EC7E8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D97A0_003EC7E8) != 0) {
        func_003EF4E0(arg0, arg1, arg2, arg3, arg4);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC7E8 */

/* localdecomp:start func_003EC870 */
extern u8 D_001DAA96;
extern void *func_003EA5E8(HT_8 *, u32);
s32 func_003EC870(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA5E8(t, key) != 0) return 0;
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
/* localdecomp:end func_003EC870 */

/* localdecomp:start func_003EC940 */
extern s32 D_001D97A0[];
s32 func_003EC940(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D97A0[0])) {
        *(f32 *)(p + 0x2C) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EC940 */

/* localdecomp:start func_003EC998 */
extern u8 D_001DAA8D;
extern void *func_003EA160(HT_8 *, u32);
s32 func_003EC998(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA160(t, key) != 0) return 0;
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
/* localdecomp:end func_003EC998 */

/* localdecomp:start func_003ECA68 */
extern s32 D_001D9770[];
s32 func_003ECA68(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECA68 */

/* localdecomp:start func_003ECAD0 */
extern s32 D_001D9770_g;
extern void func_003EDDD0();
s32 func_003ECAD0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770_g)) {
        func_003EDDD0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECAD0 */

/* localdecomp:start func_003ECB38 */
extern s32 D_001D9770[];
s32 func_003ECB38(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECB38 */

/* localdecomp:start func_003ECBA0 */
extern s32 D_001D9770_g;
s32 func_003ECBA0(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770_g)) {
        *(s32 *)(p + 0x30) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECBA0 */

/* localdecomp:start func_003ECBF0 */
extern s32 D_001D9770_g;
extern void func_003EDD28(void *, s32, s32);
s32 func_003ECBF0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770_g)) {
        func_003EDD28(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECBF0 */

/* localdecomp:start func_003ECC58 */
extern s32 D_001D9770_g;
extern s32 func_003EDD50();
s32 func_003ECC58(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770_g)) {
        *out = func_003EDD50(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECC58 */

/* localdecomp:start func_003ECCC0 */
extern s32 D_001D9770_g;
extern void func_003EDD60(void *, s32, s32);
s32 func_003ECCC0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770_g)) {
        func_003EDD60(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECCC0 */

/* localdecomp:start func_003ECD28 */
extern s32 D_001D9770_g;
extern void func_003EDD98();
s32 func_003ECD28(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770_g)) {
        func_003EDD98(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECD28 */

/* localdecomp:start func_003ECD90 */
extern s32 D_001D9770[];
s32 func_003ECD90(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECD90 */

/* localdecomp:start func_003ECDF8 */
typedef struct { u8 b[16]; } V16_003E7638;
extern s32 D_001D9770_003ECDF8;
extern V16_003E7638 D_001D9700_003ECDF8;
s32 func_003ECDF8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    V16_003E7638 v;
    f32 out[4];
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D9770_003ECDF8) != 0) {
        v = D_001D9700_003ECDF8;
        (*(s32 (**)(void *, void *, f32 *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x20))(arg0, &v, out, 1);
        *arg1 = out[0];
        *arg2 = out[1];
        *arg3 = out[2];
        *arg4 = out[3];
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECDF8 */

/* localdecomp:start func_003ECED0 */
extern s32 D_001D9770[];
s32 func_003ECED0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9770[0])) {
        *(f32 *)(p + 0x34) = a;
        *(f32 *)(p + 0x38) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECED0 */

/* localdecomp:start func_003ECF38 */
extern s32 D_001D9830[];
s32 func_003ECF38(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECF38 */

/* localdecomp:start func_003ECFA0 */
extern s32 D_001D9830_g;
extern void func_003EDDD0();
s32 func_003ECFA0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830_g)) {
        func_003EDDD0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ECFA0 */

/* localdecomp:start func_003ED008 */
extern s32 D_001D9830[];
s32 func_003ED008(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED008 */

/* localdecomp:start func_003ED070 */
extern s32 D_001D9830_g;
s32 func_003ED070(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830_g)) {
        *(s32 *)(p + 0x38) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED070 */

/* localdecomp:start func_003ED0C0 */
typedef struct { s32 pad[4]; s32 (*fn)(void *, s32); } V_3E7900;
typedef struct { s32 a, b; V_3E7900 *vt; u8 pad[0x34]; s32 c; s32 d; } S_3E7900;
extern s32 D_001D9830_003ED0C0;
s32 func_003ED0C0(S_3E7900 *s, s32 b, s32 c) {
    if (s->vt->fn(s, D_001D9830_003ED0C0) != 0) {
        s->d = b;
        s->c = c;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED0C0 */

/* localdecomp:start func_003ED120 */
extern u8 D_001DAA97;
extern void *func_003EA668(HT_8 *, u32);
s32 func_003ED120(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA668(t, key) != 0) return 0;
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
/* localdecomp:end func_003ED120 */

/* localdecomp:start func_003ED1F0 */
extern s32 D_001D9830_g;
extern void func_003EDD28(void *, s32, s32);
s32 func_003ED1F0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830_g)) {
        func_003EDD28(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED1F0 */

/* localdecomp:start func_003ED258 */
extern s32 D_001D9830_g;
extern s32 func_003EDD50();
s32 func_003ED258(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830_g)) {
        *out = func_003EDD50(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED258 */

/* localdecomp:start func_003ED2C0 */
extern s32 D_001D9830_g;
extern void func_003EDD60(void *, s32, s32);
s32 func_003ED2C0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830_g)) {
        func_003EDD60(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED2C0 */

/* localdecomp:start func_003ED328 */
extern s32 D_001D9830_g;
extern void func_003EDD98();
s32 func_003ED328(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830_g)) {
        func_003EDD98(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED328 */

/* localdecomp:start func_003ED390 */
extern s32 D_001D9830[];
s32 func_003ED390(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED390 */

/* localdecomp:start func_003ED3F8 */
extern s32 D_001D9830[];
s32 func_003ED3F8(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9830[0])) {
        *(f32 *)(p + 0x3C) = a;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED3F8 */

/* localdecomp:start func_003ED450 */
typedef struct { u8 b[16]; } V16_003E7C90;
extern s32 D_001D9830_003ED450;
extern V16_003E7C90 D_001D9700_003ED450;
s32 func_003ED450(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    V16_003E7C90 v;
    f32 out[4];
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D9830_003ED450) != 0) {
        v = D_001D9700_003ED450;
        (*(s32 (**)(void *, void *, f32 *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x20))(arg0, &v, out, 1);
        *arg1 = out[0];
        *arg2 = out[1];
        *arg3 = out[2];
        *arg4 = out[3];
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED450 */

/* localdecomp:start func_003ED528 */
extern void func_003EE660(u8 *, f32, f32, f32, f32);
extern s32 D_001D9740[];
s32 func_003ED528(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D9740[0]) != 0) {
        func_003EE660((u8 *)arg0, fparg0, fparg1, fparg2, fparg3);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED528 */

/* localdecomp:start func_003ED5B8 */
extern u8 D_001DAA98;
extern void *func_003EA6E8(HT_8 *, u32);
s32 func_003ED5B8(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA6E8(t, key) != 0) return 0;
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
/* localdecomp:end func_003ED5B8 */

/* localdecomp:start func_003ED688 */
typedef struct S_3E7EC8 S_3E7EC8;
typedef struct { u8 pad[0x10]; s32 (*f10)(S_3E7EC8 *, s32); } V_3E7EC8;
struct S_3E7EC8 { u8 pad[8]; V_3E7EC8 *vt; };
extern s32 D_001D9740_003ED688;
extern s32 func_003EDFF8(S_3E7EC8 *a, s32 b);
s32 func_003ED688(S_3E7EC8 *a, s32 b) {
    if (a->vt->f10(a, D_001D9740_003ED688)) return func_003EDFF8(a, b);
    return 0;
}
/* localdecomp:end func_003ED688 */

/* localdecomp:start func_003ED6E0 */
typedef struct { s32 pad[4]; s32 (*fn)(void *, void *); } V_3E7F20;
typedef struct { s32 a, b; V_3E7F20 *vt; } S_3E7F20;
extern void *D_001D9740_003ED6E0[];
extern void func_003EE130();
s32 func_003ED6E0(S_3E7F20 *s) {
    if (s->vt->fn(s, D_001D9740_003ED6E0[0]) == 0) return 0;
    func_003EE130(s);
    return 1;
}
/* localdecomp:end func_003ED6E0 */

/* localdecomp:start func_003ED730 */
extern u8 D_001DAA9A;
extern void *func_003EA7E8(HT_8 *, u32);
s32 func_003ED730(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_003EA7E8(t, key) != 0) return 0;
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
/* localdecomp:end func_003ED730 */

/* localdecomp:start func_003ED800 */
extern s32 D_001D9740_g;
extern void func_003EDD28(void *, s32, s32);
s32 func_003ED800(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9740_g)) {
        func_003EDD28(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED800 */

/* localdecomp:start func_003ED868 */
extern s32 D_001D9740_g;
extern s32 func_003EDD50();
s32 func_003ED868(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9740_g)) {
        *out = func_003EDD50(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED868 */

/* localdecomp:start func_003ED8D0 */
extern s32 D_001D9740_g;
extern void func_003EDD60(void *, s32, s32);
s32 func_003ED8D0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9740_g)) {
        func_003EDD60(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED8D0 */

/* localdecomp:start func_003ED938 */
extern s32 D_001D9740_g;
extern void func_003EDD98();
s32 func_003ED938(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9740_g)) {
        func_003EDD98(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED938 */

/* localdecomp:start func_003ED9A0 */
extern s32 D_001D9740[];
s32 func_003ED9A0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9740[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED9A0 */

/* localdecomp:start func_003EDA08 */
extern s32 D_001D9740[];
extern void func_003EDDC0(void *, f32, f32);
s32 func_003EDA08(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9740[0])) {
        func_003EDDC0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EDA08 */

/* localdecomp:start func_003EDA78 */
extern s32 D_001D9740_g;
extern void func_003EDDD0();
s32 func_003EDA78(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9740_g)) {
        func_003EDDD0(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EDA78 */

/* localdecomp:start func_003EDAE0 */
extern s32 D_001D9740[];
extern void func_003EDDE8(void *, f32, f32);
s32 func_003EDAE0(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9740[0])) {
        func_003EDDE8(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EDAE0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003EDB50);

/* localdecomp:start func_003EDBE0 */
typedef struct { u8 p0[8]; void *f8; u8 pC[4]; s32 f10, f14, f18, f1C; f32 f20, f24; s32 f28; } O_3E8420;
extern u8 D_001D9718[];
extern void **func_003E7358();
extern void func_003EDD28(void *, s32, s32);
extern void func_003EDD60(void *, s32, s32);
extern void func_003EDDC0(void *, f32, f32);
extern void func_003EDDE8(void *, f32, f32);
O_3E8420 *func_003EDBE0(O_3E8420 *p) {
    func_003E7358(p);
    p->f8 = D_001D9718;
    p->f28 = 0x80808080;
    p->f10 = 0;
    p->f14 = 0;
    p->f18 = 0;
    p->f1C = 0;
    p->f20 = 0;
    p->f24 = 0;
    func_003EDD28(p, 1, 1);
    func_003EDD28(p, 2, 0);
    func_003EDD28(p, 4, 1);
    func_003EDD28(p, 8, 1);
    func_003EDD28(p, 0x20, 0);
    func_003EDD28(p, 0x10, 0);
    func_003EDD28(p, 0x40, 0);
    func_003EDD28(p, 0x80, 0);
    func_003EDD28(p, 0x100, 0);
    func_003EDD60(p, 3, 3);
    func_003EDDC0(p, 0.5f, 0.5f);
    func_003EDDE8(p, 1.0f, 1.0f);
    p->f28 = 0x40000000;
    p->f20 = 0.005f;
    p->f24 = 0.005f;
    return p;
}
/* localdecomp:end func_003EDBE0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003EDD20);

/* localdecomp:start func_003EDD28 */
void func_003EDD28(void *p, s32 mask, s32 set) {
    if (set != 0) {
        *(s32 *)((u8 *)p + 0xC) |= mask;
    } else {
        *(s32 *)((u8 *)p + 0xC) &= ~mask;
    }
}
/* localdecomp:end func_003EDD28 */

/* localdecomp:start func_003EDD50 */
s32 func_003EDD50(void *p, s32 mask) {
    return (*(s32 *)((u8 *)p + 0xC) & mask) != 0;
}
/* localdecomp:end func_003EDD50 */

/* localdecomp:start func_003EDD60 */
void func_003EDD60(void *p, s32 a, s32 b) {
    *(u32 *)((u8 *)p + 0xC) = (((*(u32 *)((u8 *)p + 0xC) & ~0x600) | (a << 9)) & ~0x1800) | (b << 11);
}
/* localdecomp:end func_003EDD60 */

/* localdecomp:start func_003EDD98 */
void func_003EDD98(void *p, s32 *a, s32 *b) {
    *a = (*(u32 *)((u8 *)p + 0xC) >> 9) & 3;
    *b = (*(u32 *)((u8 *)p + 0xC) >> 11) & 3;
}
/* localdecomp:end func_003EDD98 */

/* localdecomp:start func_003EDDC0 */
void func_003EDDC0(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x10) = x;
    *(f32 *)((u8 *)p + 0x14) = y;
}
/* localdecomp:end func_003EDDC0 */

/* localdecomp:start func_003EDDD0 */
void func_003EDDD0(void *a0, f32 *a1, f32 *a2) {
    *a1 = *(f32 *)((u8 *)a0 + 0x10);
    *a2 = *(f32 *)((u8 *)a0 + 0x14);
}
/* localdecomp:end func_003EDDD0 */

/* localdecomp:start func_003EDDE8 */
void func_003EDDE8(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x18) = x;
    *(f32 *)((u8 *)p + 0x1C) = y;
}
/* localdecomp:end func_003EDDE8 */

/* localdecomp:start func_003EDDF8 */
s32 func_003EDDF8(void) {
    return 1;
}
/* localdecomp:end func_003EDDF8 */

/* localdecomp:start func_003EDE00 */
s32 func_003EDE00(s32 p, s32 k) {
    if (k == 1) {
        return 1;
    }
    return func_003E7370(p, k);   /* defined earlier in text.c */
}
/* localdecomp:end func_003EDE00 */

/* localdecomp:start func_003EDE30 */
typedef struct V_3E8670 { u8 pad[0x14]; s32 (*fn)(void *, s32); } V_3E8670;
typedef struct { u8 pad[8]; V_3E8670 *vt; } O_3E8670;
extern s32 func_003EDD50();
s32 func_003EDE30(O_3E8670 *a, s32 b) {
    if (func_003EDD50(a, 1) != 0) return a->vt->fn(a, b);
    return 0;
}
/* localdecomp:end func_003EDE30 */

/* localdecomp:start func_003EDE88 */
typedef struct { u8 pad[0x18]; void (*fn)(void *, s32); } V_3E86C8;
typedef struct { u8 pad[8]; V_3E86C8 *vt; } S_3E86C8;
extern s32 func_003EDD50();
void func_003EDE88(S_3E86C8 *a, s32 b) {
    if (func_003EDD50(a, 1)) a->vt->fn(a, b);
}
/* localdecomp:end func_003EDE88 */

/* localdecomp:start func_003EDED8 */
extern void func_003E7488(void);
extern void func_003E74A8(void);
extern s32 func_003EDD50(void *, s32);
void func_003EDED8(void *arg0, s32 arg1) {
    if (func_003EDD50(arg0, 1) != 0) {
        (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x1C))(arg0, arg1);
    }
    if (func_003EDD50(arg0, 0x4000) != 0) {
        func_003E74A8();
        func_003E7488();
    }
}
/* localdecomp:end func_003EDED8 */

/* localdecomp:start func_003EDF48 */
s32 func_003EDF48(void) {
}
/* localdecomp:end func_003EDF48 */

/* localdecomp:start func_003EDF50 */
extern char D_001D96B0[];
void func_003EDF50(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D96B0; if (f & 1) func_003F2578(p); }
/* localdecomp:end func_003EDF50 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003EDF80);

/* localdecomp:start func_003EDF98 */
extern f32 D_001D96D8;
extern f32 D_001D96DC;
extern void func_003A9770(s32, s32, s32, s32);
void func_003EDF98(f32 a, f32 b, f32 c, f32 d) {
    func_003A9770((s32)(a * D_001D96D8), (s32)(c * D_001D96D8), (s32)(b * D_001D96DC), (s32)(d * D_001D96DC));
}
/* localdecomp:end func_003EDF98 */

/* localdecomp:start func_003EDFF8 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E8838;
typedef struct { s32 *e[16]; s32 pad[2]; s32 n; } O_003E8838;
typedef struct { u8 p0[0x2C]; O_003E8838 *x2C; } T_003E8838;
extern S_003E8838 D_001DA9B8_003EDFF8[];
extern s32 *func_003E6E78();
extern s32 func_003E7058();
extern s32 func_003E65E8();
extern s32 D_001D9710;
extern s32 func_003E7388();
extern void func_003E7378();
s32 func_003EDFF8(S_3E7EC8 *a, s32 key) {
    T_003E8838 *self = (T_003E8838 *)a;
    S_003E8838 *q;
    S_003E8838 *p;
    void *t;
    s32 v;
    s32 i, cnt;
    s32 *slot;
    p = D_001DA9B8_003EDFF8;
    if (p->x4) q = p;
    else q = (S_003E8838 *)func_003E6E78(p);
    t = (void *)func_003E65E8(func_003E7058(q), key);
    if (t == 0 || (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D9710) == 0) t = 0;
    v = (s32)t;
    if (v == 0) return 0;
    cnt = 0;
    for (i = 0; i < self->x2C->n; i++) {
        if (*(s32 *)((i << 2) + (s32)self->x2C) == v) cnt++;
    }
    if (cnt != 0) return 0;
    if (self->x2C->n < 16) {
        slot = (s32 *)((self->x2C->n << 2) + (s32)self->x2C);
        if (*slot != 0) func_003E7388(*slot);
        *slot = v;
        if (v != 0) func_003E7378(v);
        self->x2C->n = self->x2C->n + 1;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EDFF8 */

/* localdecomp:start func_003EE130 */
extern s32 func_003E7388();
typedef struct { s32 a[0x12]; s32 x48; } S_E8;
typedef struct { u8 p[0x2C]; S_E8 *x2C; } T_E8;
void func_003EE130(T_E8 *a0) {
    s32 i;
    for (i = 0; i < a0->x2C->x48; i++) {
        s32 *p = (s32 *)((u8 *)(i << 2) + (s32)a0->x2C);
        if (*p != 0) {
            func_003E7388(*p);
        }
        *p = 0;
    }
}
/* localdecomp:end func_003EE130 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EE1B0);

/* localdecomp:start func_003EE290 */
typedef struct { s32 *arr[16]; s32 x40; s32 x44; } O_3E8AD0;
typedef struct { u8 p0[8]; void *f8; u8 p1[0x2C - 0xC]; O_3E8AD0 *x2C; } T_3E8AD0;
typedef struct { u8 p0[4]; s32 f4; } S_3E8AD0;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); s32 (*fC)(); } VT_3E8AD0;
extern u8 D_001D9748[8];
extern u8 D_001D96B0_003EE290[8];
extern S_3E8AD0 D_001DA9B8_003EE290[];
extern s32 *func_003E6E78();
extern s32 **func_003E6F30_003EE290();
extern s32 func_003E7388();
extern void func_003EE130();
void func_003EE290(T_3E8AD0 *p, s32 flags) {
    O_3E8AD0 *a, *b;
    s32 *q;
    s32 **t;
    s32 **w;
    p->f8 = &D_001D9748;
    func_003EE130(p);
    a = p->x2C;
    if (a->x44 != 0) func_003E7388(a->x44);
    a->x44 = 0;
    b = p->x2C;
    if (b->x44 != 0) func_003E7388(b->x44);
    b->x44 = 0;
    if (b->arr != 0) {
        w = b->arr + 16;
        if (b->arr != w) {
            do {
                w--;
                if (*w) func_003E7388(*w);
                *w = 0;
            } while (b->arr != w);
        }
    }
    if (D_001DA9B8_003EE290->f4 != 0) {
        q = (s32 *)D_001DA9B8_003EE290;
    } else {
        q = func_003E6E78(D_001DA9B8_003EE290);
    }
    t = func_003E6F30_003EE290(q, 1);
    if (t != 0) {
        ((VT_3E8AD0 *)*t)->fC(t, p->x2C);
        p->x2C = 0;
    }
    p->f8 = &D_001D96B0_003EE290;
    if (flags & 1) func_003F2578(p);
}
/* localdecomp:end func_003EE290 */

/* localdecomp:start func_003EE3B8 */
void func_003EE3B8(void *p, s32 m, s32 set) {
    if (set != 0) {
        *(*(u8 **)((u8 *)p + 0x2C) + 0x4C) |= m;
    } else {
        *(*(u8 **)((u8 *)p + 0x2C) + 0x4C) &= ~m;
    }
}
/* localdecomp:end func_003EE3B8 */

/* localdecomp:start func_003EE3E8 */
s32 func_003EE3E8(void *a0, s32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    return (*(u8 *)((u8 *)p + 0x4c) & a1) != 0;
}
/* localdecomp:end func_003EE3E8 */

/* localdecomp:start func_003EE400 */
typedef struct { u8 b[16]; } B16_3E8C40;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3E8C40;
extern s32 func_0011A264(void *, s32, s32);
void func_003EE400(O_3E8C40 *o, f32 *p, f32 *out, s32 flag) {
    f32 sy = 2.0f;
    f32 ay = 0.0f;
    f32 sx = 2.0f;
    f32 ax = 0.0f;
    f32 t[4];
    f32 x0, y0, h, dx, dy;
    s32 k1, k2;
    if (flag) {
        k1 = 0;
        k2 = 0;
        func_003EDD98(o, &k1, &k2);
        if (k1 != 3) {
            if (k1 == 1) {
                ax = 1.0f;
            } else {
                sx = 2.0f;
                ax = -1.0f;
            }
        }
        if (k2 != 3) {
            if (k2 == 2) {
                sy = 2.0f;
                ay = -1.0f;
            } else {
                sy = 2.0f;
                ay = 1.0f;
            }
        }
    }
    x0 = o->f10;
    x0 = (p[2] - p[0]) * x0 + p[0];
    y0 = o->f14;
    y0 = (p[3] - p[1]) * y0 + p[1];
    out[0] = x0 - o->f18 * ((ax + 1.0f) / sx);
    h = o->f1C;
    out[1] = (y0 - h / sy) + (ay * h) / sy;
    out[2] = out[0] + o->f18;
    out[3] = out[1] + o->f1C;
    if (func_003EDD50(o, 0x40)) {
        dx = o->f20;
        dy = o->f24;
        func_0011A264(t, 0, 0x10);
        *(B16_3E8C40 *)t = *(B16_3E8C40 *)out;
        t[0] += dx;
        t[2] += dx;
        t[1] += dy;
        t[3] += dy;
        out[0] = (t[0] < out[0]) ? t[0] : out[0];
        out[2] = (out[2] < t[2]) ? t[2] : out[2];
        out[3] = (out[3] < t[3]) ? t[3] : out[3];
        out[1] = (t[1] < out[1]) ? t[1] : out[1];
    }
}
/* localdecomp:end func_003EE400 */
TEXT_PADDING(2);

/* localdecomp:start func_003EE660 */
void func_003EE660(u8 *p, f32 a, f32 b, f32 c, f32 d) {
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x50) = a;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x58) = b;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x54) = c;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x5C) = d;
}
/* localdecomp:end func_003EE660 */

/* localdecomp:start func_003EE688 */
typedef struct O_3E8EC8 O_3E8EC8F;
typedef struct { u8 p0[0x20]; void (*f20)(O_3E8EC8F *, s32, f32 *, s32); } V_3E8EC8;
typedef struct { s32 *tbl[1]; } L_3E8EC8;
typedef struct { u8 p0[0x48]; s32 f48; } L2_3E8EC8;
typedef struct O_3E8EC8 { u8 p0[8]; V_3E8EC8 *f8; u8 pC[0x20]; struct { s32 *e[1]; u8 pad[0x44]; s32 n; } *f2C; } O_3E8EC8;
extern void func_003EDF48();
extern s32 func_003EE3E8();
extern void func_003EDF98(f32, f32, f32, f32);
extern void func_003EDED8();
void func_003EE688(O_3E8EC8 *self, s32 b) {
    f32 v[4];
    s32 i;
    self->f8->f20(self, b, v, 1);
    func_003EDF48(self, v);
    if (func_003EE3E8(self, 1)) {
        func_003EDF98(v[0], v[1], v[2], v[3]);
    }
    for (i = 0; i < self->f2C->n; i++) {
        func_003EDED8(((s32 **)self->f2C)[i], b);
    }
    if (func_003EE3E8(self, 1)) {
        func_003EDF98(0.0f, 0.0f, 1.0f, 1.0f);
    }
}
/* localdecomp:end func_003EE688 */

/* localdecomp:start func_003EE770 */
typedef struct { u8 b[16]; } B16_3E8FB0;
typedef struct { u8 p0[8]; s32 (**vt)(); } C_3E8FB0;
typedef struct { s32 *e[1]; u8 p0[0x40]; C_3E8FB0 *f44; s32 n; s32 p1; f32 f50, f54, f58, f5C; } S_3E8FB0;
typedef struct { u8 p0[0x2C]; S_3E8FB0 *f2C; } O_3E8FB0;
extern s32 func_003EDE30();
s32 func_003EE770(O_3E8FB0 *self, f32 *b) {
    B16_3E8FB0 t;
    S_3E8FB0 *s;
    f32 dx, dy;
    s32 i;
    s = self->f2C;
    t = *(B16_3E8FB0 *)b;
    dx = b[2] - b[0];
    dy = b[3] - b[1];
    ((f32 *)&t)[0] = dx * s->f50 + b[0];
    ((f32 *)&t)[1] = dy * s->f54 + b[1];
    ((f32 *)&t)[2] = dx * s->f58 + b[0];
    ((f32 *)&t)[3] = dy * s->f5C + b[1];
    if (s->f44 != 0) {
        ((s32 (*)())(s->f44->vt[0x14 / 4]))(s->f44, &t, s);
    } else {
        for (i = 0; i < self->f2C->n; i++) {
            func_003EDE30(((s32 **)self->f2C)[i], b);
        }
    }
    return 1;
}
/* localdecomp:end func_003EE770 */

/* localdecomp:start func_003EE888 */
typedef struct { u8 b[16]; } B16_3E90C8;
typedef struct { s32 *e[1]; u8 p0[0x44]; s32 n; s32 p1; f32 f50, f54, f58, f5C; } S_3E90C8;
typedef struct { u8 p0[0x2C]; S_3E90C8 *f2C; } O_3E90C8;
extern void func_003EDE88();
void func_003EE888(O_3E90C8 *self, f32 *b) {
    B16_3E90C8 t;
    S_3E90C8 *s;
    f32 dx, dy;
    s32 i;
    s = self->f2C;
    t = *(B16_3E90C8 *)b;
    dx = b[2] - b[0];
    dy = b[3] - b[1];
    ((f32 *)&t)[0] = dx * s->f50 + b[0];
    ((f32 *)&t)[1] = dy * s->f54 + b[1];
    ((f32 *)&t)[2] = dx * s->f58 + b[0];
    ((f32 *)&t)[3] = dy * s->f5C + b[1];
    for (i = 0; i < self->f2C->n; i++) {
        func_003EDE88(((s32 **)self->f2C)[i], b);
    }
}
/* localdecomp:end func_003EE888 */

/* localdecomp:start func_003EE978 */
s32 func_003EE978(void) {
    return 7;
}
/* localdecomp:end func_003EE978 */

/* localdecomp:start func_003EE980 */
s32 func_003EE980(s32 p, s32 k) {
    if (k == 7) {
        return 1;
    }
    return func_003EDE00(p, k);
}
/* localdecomp:end func_003EE980 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003EE9B0);

/* localdecomp:start func_003EE9B8 */
extern void func_003EDBE0(void);
extern unsigned char D_001D9778[];

void *func_003EE9B8(unsigned char *object) {
    register float half __asm__("$f0");
    register float small __asm__("$f1");
    register void *vtable __asm__("$4");
    register void *result __asm__("$2");
    register int color __asm__("$3");

    func_003EDBE0();
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
/* localdecomp:end func_003EE9B8 */

/* localdecomp:start func_003EEA20 */
extern s32 D_001D9770_g;
extern s32 func_003EDE00(s32, s32);
s32 func_003EEA20(s32 p, s32 k) {
    if (k != D_001D9770_g) return func_003EDE00(p, k);
    return 1;
}
/* localdecomp:end func_003EEA20 */

/* localdecomp:start func_003EEA50 */
extern s32 D_001D9770_g;
s32 func_003EEA50(void) { return D_001D9770_g; }
/* localdecomp:end func_003EEA50 */

/* localdecomp:start func_003EEA58 */
void func_003EEA58(u8 *p, f32 *a) {
    *(f32 *)(p + 0x10) = a[0] + (a[2] - a[0]) * 0.5f;
    *(f32 *)(p + 0x14) = a[1] + (a[3] - a[1]) * 0.5f;
}
/* localdecomp:end func_003EEA58 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EEA98);

/* localdecomp:start func_003EF078 */
typedef struct { u8 b[16]; } B16_3E98B8;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3E98B8;
extern s32 func_0011A264(void *, s32, s32);
void func_003EF078(O_3E98B8 *o, f32 *p, f32 *out, s32 flag) {
    f32 sy = 2.0f;
    f32 ay = 0.0f;
    f32 sx = 2.0f;
    f32 ax = 0.0f;
    f32 t[4];
    f32 x0, y0, h, dx, dy;
    s32 k1, k2;
    if (flag) do {
        k1 = 0;
        k2 = 0;
        func_003EDD98(o, &k1, &k2);
        if (k1 != 3) {
            if (k1 == 1) {
                ax = 1.0f;
            } else {
                sx = 2.0f;
                ax = -1.0f;
            }
        }
        if (k2 != 3) {
            if (k2 == 2) {
                sy = 2.0f;
                ay = -1.0f;
            } else {
                sy = 2.0f;
                ay = 1.0f;
            }
        }
    } while (0);
    x0 = o->f10;
    x0 = (p[2] - p[0]) * x0 + p[0];
    y0 = o->f14;
    y0 = (p[3] - p[1]) * y0 + p[1];
    out[0] = (x0 - o->f18 / sx) + (ax * o->f18) / sx;
    h = o->f1C;
    out[1] = (y0 - h / sy) + (ay * h) / sy;
    out[2] = out[0] + o->f18;
    out[3] = out[1] + o->f1C;
    if (func_003EDD50(o, 0x40)) {
        dx = o->f20;
        dy = o->f24;
        func_0011A264(t, 0, 0x10);
        *(B16_3E98B8 *)t = *(B16_3E98B8 *)out;
        t[0] += dx;
        t[2] += dx;
        t[1] += dy;
        t[3] += dy;
        out[0] = (t[0] < out[0]) ? t[0] : out[0];
        out[2] = (out[2] < t[2]) ? t[2] : out[2];
        out[3] = (out[3] < t[3]) ? t[3] : out[3];
        out[1] = (t[1] < out[1]) ? t[1] : out[1];
    }
}
/* localdecomp:end func_003EF078 */

/* localdecomp:start func_003EF2D8 */
s32 func_003EF2D8(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))((u8 *)p + 0x2C);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003EF2D8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003EF308);

/* localdecomp:start func_003EF310 */
extern char D_001D96B0[];
extern s32 func_003F2578();
void func_003EF310(u8 *p, s32 f) {
    *(void **)(p + 8) = D_001D96B0;
    if (f & 1) func_003F2578(p);
}
/* localdecomp:end func_003EF310 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003EF340);

/* localdecomp:start func_003EF368 */
extern void func_003EF410();
extern void func_003EF4E0(void *, s32, s32, s32, s32);
extern void func_003EDBE0(void);
extern u8 D_001D97A8[];
void *func_003EF368(void *arg0)
{
  void **new_var;
  func_003EDBE0();
  *((s32 *) (((u8 *) arg0) + 0x2C)) = 0;
  *((s32 **) (((u8 *) arg0) + 8)) = D_001D97A8;
  *((s32 *) (((u8 *) arg0) + 0x30)) = 0;
  *((s32 *) (((u8 *) arg0) + 0x38)) = 0x80808080;
  *((s32 *) (((u8 *) arg0) + 0x3C)) = 0x80808080;
  *((s32 *) (((u8 *) arg0) + 0x40)) = 0x80808080;
  *((s32 *) (((u8 *) arg0) + 0x44)) = 0x80808080;
  func_003EF4E0(arg0, 0x80F00000, 0x80F00000, 0x80F00000, 0x80F00000);
  *((s32 *) (((u8 *) arg0) + 0x50)) = 0;
  *((f32 *) (((u8 *) arg0) + 0x18)) = 0.5f;
  *((f32 *) (((u8 *) arg0) + 0x1C)) = 0.5f;
  func_003EF410(arg0, 0);
  new_var = &arg0;
  *((s8 *) (((u8 *) (*new_var)) + 0x4C)) = 0xA;
  *((s16 *) (((u8 *) (*new_var)) + 0x4A)) = 0;
  *((s32 *) (((u8 *) (*new_var)) + 0x34)) = 0;
  *((s8 *) (((u8 *) (*new_var)) + 0x4E)) = 0;
  *((s8 *) (((u8 *) (*new_var)) + 0x4D)) = 0;
  return *new_var;
}
/* localdecomp:end func_003EF368 */

/* localdecomp:start func_003EF410 */
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

void func_003EF410(S_003E9C50 *arg0, s32 arg1) {
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
/* localdecomp:end func_003EF410 */

/* localdecomp:start func_003EF4A8 */
extern s32 D_001D97A0_g;
extern s32 func_003EDE00(s32, s32);
s32 func_003EF4A8(s32 p, s32 k) {
    if (k != D_001D97A0_g) return func_003EDE00(p, k);
    return 1;
}
/* localdecomp:end func_003EF4A8 */

/* localdecomp:start func_003EF4D8 */
extern s32 D_001D97A0_g;
s32 func_003EF4D8(void) {
    return D_001D97A0_g;
}
/* localdecomp:end func_003EF4D8 */

/* localdecomp:start func_003EF4E0 */
void func_003EF4E0(void *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    *(s32 *)((u8 *)a0 + 0x38) = a1;
    *(s32 *)((u8 *)a0 + 0x3c) = a2;
    *(s32 *)((u8 *)a0 + 0x40) = a3;
    *(s32 *)((u8 *)a0 + 0x44) = a4;
}
/* localdecomp:end func_003EF4E0 */

/* localdecomp:start func_003EF4F8 */
void func_003EF4F8(u8 *p, f32 *a) {
    *(f32 *)(p + 0x10) = a[0] + (a[2] - a[0]) * 0.5f;
    *(f32 *)(p + 0x14) = a[1] + (a[3] - a[1]) * 0.5f;
}
/* localdecomp:end func_003EF4F8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EF538);

/* localdecomp:start func_003EF838 */
typedef struct { s32 f0; s32 *vt4; } OB_3EA078;
typedef struct { u8 p0[8]; s32 f8; s32 fC; } PP_3EA078;
typedef struct { u8 pad0[0x20]; f32 f20, f24; s32 f28; f32 f2C; u8 pad1[0x8]; s32 f38; u8 pad2[0x14]; OB_3EA078 *f50; } O_3EA078;
extern f32 D_001D96D8;
extern f32 D_001D96DC;
extern s32 func_003EDD50();
extern unsigned long func_0039AF70(s32);
extern void func_0038B448(s32, s32, s32, s32, s32, s32, s32, s32, f32, unsigned long, unsigned long);
s32 func_003EF838(O_3EA078 *o, f32 *r) {
    OB_3EA078 *ob = o->f50;
    s32 k38;
    if ((ob->f0 ^ 2) == 0) {
        k38 = o->f38;
        if (func_003EDD50(o, 0x40)) {
            f32 x1, y1, x0, y0, ox, oy, sc, w, h;
            s32 a, b, k28;
            unsigned long res;
            PP_3EA078 *pp;
            ox = o->f20;
            oy = o->f24;
            k28 = o->f28;
            pp = (PP_3EA078 *)((s32 (*)())*(s32 *)((u8 *)ob->vt4 + 0x18))(ob);
            x0 = r[0] + ox;
            y0 = r[1] + oy;
            x1 = r[2] + ox;
            y1 = r[3] + oy;
            sc = o->f2C;
            a = pp->f8;
            b = pp->fC;
            w = x1 - x0;
            h = y1 - y0;
            res = func_0039AF70((s32)pp);
            func_0038B448((s32)(x0 * D_001D96D8), (s32)(y0 * D_001D96DC), (s32)(w * D_001D96D8), (s32)(h * D_001D96DC), 0, 0, a, b, sc, (unsigned long)(u32)k28, res);
        }
        {
            f32 x1, y1, x0, y0, sc;
            s32 a, b;
            unsigned long res;
            PP_3EA078 *pp;
            pp = (PP_3EA078 *)((s32 (*)())*(s32 *)((u8 *)ob->vt4 + 0x18))(ob);
            x0 = r[0];
            y0 = r[1];
            x1 = r[2] - x0;
            y1 = r[3] - y0;
            sc = o->f2C;
            a = pp->f8;
            b = pp->fC;
            res = func_0039AF70((s32)pp);
            func_0038B448((s32)(x0 * D_001D96D8), (s32)(y0 * D_001D96DC), (s32)(x1 * D_001D96D8), (s32)(y1 * D_001D96DC), 0, 0, a, b, sc, (unsigned long)(u32)k38, res);
        }
    }
    return 0;
}
/* localdecomp:end func_003EF838 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EFA50);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031CCC0);

/* localdecomp:start func_003EFE08 */
typedef struct { u8 b[16]; } B16_3EA648;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3EA648;
extern s32 func_0011A264(void *, s32, s32);
void func_003EFE08(O_3EA648 *o, f32 *p, f32 *out, s32 flag) {
    f32 sy = 2.0f;
    f32 ay = 0.0f;
    f32 sx = 2.0f;
    f32 ax = 0.0f;
    f32 t[4];
    f32 x0, y0, h, dx, dy;
    s32 k1, k2;
    if (flag) do {
        k1 = 0;
        k2 = 0;
        func_003EDD98(o, &k1, &k2);
        if (k1 != 3) {
            if (k1 == 1) {
                ax = 1.0f;
            } else {
                sx = 2.0f;
                ax = -1.0f;
            }
        }
        if (k2 != 3) {
            if (k2 == 2) {
                sy = 2.0f;
                ay = -1.0f;
            } else {
                sy = 2.0f;
                ay = 1.0f;
            }
        }
    } while (0);
    x0 = o->f10;
    x0 = (p[2] - p[0]) * x0 + p[0];
    y0 = o->f14;
    y0 = (p[3] - p[1]) * y0 + p[1];
    out[0] = (x0 - o->f18 / sx) + (ax * o->f18) / sx;
    h = o->f1C;
    out[1] = (y0 - h / sy) + (ay * h) / sy;
    out[2] = out[0] + o->f18;
    out[3] = out[1] + o->f1C;
    if (func_003EDD50(o, 0x40)) {
        dx = o->f20;
        dy = o->f24;
        func_0011A264(t, 0, 0x10);
        *(B16_3EA648 *)t = *(B16_3EA648 *)out;
        t[0] += dx;
        t[2] += dx;
        t[1] += dy;
        t[3] += dy;
        out[0] = (t[0] < out[0]) ? t[0] : out[0];
        out[2] = (out[2] < t[2]) ? t[2] : out[2];
        out[3] = (out[3] < t[3]) ? t[3] : out[3];
        out[1] = (t[1] < out[1]) ? t[1] : out[1];
    }
}
/* localdecomp:end func_003EFE08 */

/* localdecomp:start func_003F0068 */
s32 func_003F0068(void *arg0, s32 arg1) {
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
/* localdecomp:end func_003F0068 */

/* localdecomp:start func_003F00F0 */
void func_003F00F0(void *p, s32 v) {
    *((u8 *)p + 0x4C) = v;
    if ((u8)v == 0) {
        *((u8 *)p + 0x4C) = 1;
    }
}
/* localdecomp:end func_003F00F0 */

/* localdecomp:start func_003F0110 */
extern char D_001D96B0[];
extern s32 func_003F2578();
void func_003F0110(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D96B0; if (f & 1) func_003F2578(p); }
/* localdecomp:end func_003F0110 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003F0140);

/* localdecomp:start func_003F0168 */
s32 func_003F0168(void) {
    return 2;
}
/* localdecomp:end func_003F0168 */

/* localdecomp:start func_003F0170 */
extern void func_003EDBE0(void);
extern u8 D_001D97D8[];
void *func_003F0170(void *arg0) {
    func_003EDBE0();
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
/* localdecomp:end func_003F0170 */

/* localdecomp:start func_003F01F8 */
void func_003F01F8(u8 *p, u8 m, s32 set) {
    if (set != 0) {
        p[0x44] |= m;
    } else {
        p[0x44] &= ~m;
    }
}
/* localdecomp:end func_003F01F8 */

/* localdecomp:start func_003F0228 */
s32 func_003F0228(void *a0, s32 a1) {
    s32 b = a1 & 0xff;
    return (*(u8 *)((u8 *)a0 + 0x44) & b) != 0;
}
/* localdecomp:end func_003F0228 */

/* localdecomp:start func_003F0240 */
void func_003F0240(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x48) = x;
    *(f32 *)((u8 *)p + 0x4C) = y;
}
/* localdecomp:end func_003F0240 */

/* localdecomp:start func_003F0250 */
void func_003F0250(u8 *p, f32 *a) {
    *(f32 *)(p + 0x10) = a[0] + (a[2] - a[0]) * 0.5f;
    *(f32 *)(p + 0x14) = a[1] + (a[3] - a[1]) * 0.5f;
}
/* localdecomp:end func_003F0250 */

/* localdecomp:start func_003F0290 */
typedef struct {
    void *vt0; void *vt4; s32 (**vt)(); u8 pad0[0x4]; f32 f10, f14, f18, f1C, f20, f24; u32 f28; u8 pad2[0xC]; s32 f38; s32 f3C; u32 f40; u32 f44; u8 pad3[0x4]; u32 f4C; u32 f50; u8 pad4[0x8]; f32 f5C; f32 f60;
} O_3EAAD0;
extern f32 D_001D96D8;
extern f32 D_001D96DC;
extern f32 D_001D96F4;
extern s32 func_003EDD50();
extern void func_003EDF48();
extern void func_0038EB10_003F0290(unsigned long, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32);
void func_003F0290(O_3EAAD0 *o, s32 a) {
    f32 b[4];
    s32 flag, r;
    f32 x, y, z;
    f32 cx, cy, h, dy, w;
    unsigned long p50, p28;
    s32 p3C;
    if (o->f3C == 0) return;
    flag = 0;
    x = 0.0f;
    z = x;
    ((void (*)())o->vt[8])(o, a, b, 1);
    func_003EDF48(o, b);
    y = x;
    cx = b[0] + (b[2] - b[0]) * 0.5f;
    cy = b[1] + (b[3] - b[1]) * 0.5f;
    r = func_003EDD50(o, 0x40);
    if (r) {
        x = o->f20;
        y = o->f24;
        flag = 1;
    }
    h = o->f60;
    dy = D_001D96F4 * h;
    p28 = o->f28;
    p3C = o->f3C;
    w = o->f5C;
    p50 = o->f50;
    if (flag) {
        func_0038EB10_003F0290(p50, p3C, -1, 1, flag, p28, (f32)(s32)(cx * D_001D96D8), (f32)(s32)((cy - dy) * D_001D96DC), w, h, x * D_001D96D8, y * D_001D96DC);
    } else {
        func_0038EB10_003F0290(p50, p3C, -1, 1, 0, p28, (f32)(s32)(cx * D_001D96D8), (f32)(s32)((cy - dy) * D_001D96DC), w, h, z, z);
    }
}
/* localdecomp:end func_003F0290 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003F0448);

/* localdecomp:start func_003F0890 */
s32 func_003F0890(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))((u8 *)p + 0x34);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003F0890 */

/* localdecomp:start func_003F08C0 */
s32 func_003F08C0(s32 p, s32 k) {
    if (k != 2) {
        return func_003EDE00(p, k);
    }
    return 1;
}
/* localdecomp:end func_003F08C0 */

/* localdecomp:start func_003F08F0 */
extern char D_001D96B0[];
extern s32 func_003F2578();
void func_003F08F0(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D96B0; if (f & 1) func_003F2578(p); }
/* localdecomp:end func_003F08F0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003F0920);

/* localdecomp:start func_003F0938 */
s32 func_003F0938(void) {
    return 3;
}
/* localdecomp:end func_003F0938 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003F0940);

/* localdecomp:start func_003F0B18 */
s32 *func_003E6E78(s32 *);                  /* extern */
void **func_003E6F30(s32 *, s32);           /* extern */
void func_003F2578_003F0B18(void *);
extern u8 D_001D96B0_003F0B18;
extern u8 D_001D9808;
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003EB358;
extern S_001DA9B8_003EB358 D_001DA9B8[];

void func_003F0B18(void *arg0, s32 arg1) {
    s32 *var_v0;
    void **temp_v0;

    (*(s32 **)((u8 *)(arg0) + 8)) = (s32 *)&D_001D9808;
    if (D_001DA9B8->f4 != 0) {
        var_v0 = (s32 *)D_001DA9B8;
    } else {
        var_v0 = func_003E6E78((s32 *)D_001DA9B8);
    }
    temp_v0 = func_003E6F30(var_v0, 1);
    if (temp_v0 != 0) {
        (*(s32 (**)(void **, s32))((u8 *)(*temp_v0) + 0xC))(temp_v0, (*(s32 *)((u8 *)(arg0) + 0x2C)));
        (*(s32 *)((u8 *)(arg0) + 0x2C)) = 0;
    }
    (*(s32 **)((u8 *)(arg0) + 8)) = (s32 *)&D_001D96B0_003F0B18;
    if (arg1 & 1) {
        func_003F2578_003F0B18(arg0);
    }
}
/* localdecomp:end func_003F0B18 */

/* localdecomp:start func_003F0BB8 */
void func_003F0BB8(void *p, s32 value) {
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x34) = value;
}
/* localdecomp:end func_003F0BB8 */

/* localdecomp:start func_003F0BC8 */
void func_003F0BC8(u8 *p) {
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
/* localdecomp:end func_003F0BC8 */

/* localdecomp:start func_003F0C00 */
typedef struct { u8 pad[0x10]; s32 w10; u8 p2[0x48-0x14]; u16 h48; } Q_3EB440;
typedef struct { u8 pad[0x2C]; Q_3EB440 *q; u8 b30; u8 p3[3]; s32 w34; } S_3EB440;
extern void func_003F0BC8();
void func_003F0C00(S_3EB440 *p, s32 b) {
    Q_3EB440 *q = p->q;
    if (q->w10 != b && (q->h48 & 0x20)) {
        func_003F0BC8((u8 *)p);
        p->b30 = 0;
        p->w34 = 0;
    }
    p->q->w10 = b;
}
/* localdecomp:end func_003F0C00 */

/* localdecomp:start func_003F0C68 */
void func_003F0C68(void *a0, f32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(f32 *)((u8 *)p + 0x28) = a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003F0C68 */

/* localdecomp:start func_003F0C80 */
void func_003F0C80(void *p, s32 a, s16 b, s16 c, s32 d) {
    *(s16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x18) = b;
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x14) = a;
    *(s16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x1A) = c;
    *(s32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x38) = d;
}
/* localdecomp:end func_003F0C80 */

/* localdecomp:start func_003F0CA8 */
void func_003F0CA8(void *a0, f32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(f32 *)((u8 *)p + 0x44) = a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003F0CA8 */

/* localdecomp:start func_003F0CC0 */
s32 func_003F0CC0(void *a0, f32 *a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *a1 = *(f32 *)((u8 *)p + 0x44);
    return 1;
}
/* localdecomp:end func_003F0CC0 */

/* localdecomp:start func_003F0CD8 */
s32 func_003F0CD8(u32 a0, u32 a1, u32 a2) {
    u32 ptr;

    ptr = *(u32 *)(a0 + 0x2C);
    *(float *)(a1 + 0x00) = *(float *)(ptr + 0x2C);

    ptr = *(u32 *)(a0 + 0x2C);
    *(float *)(a2 + 0x00) = *(float *)(ptr + 0x30);

    return 1;
}
/* localdecomp:end func_003F0CD8 */

/* localdecomp:start func_003F0CF8 */
void func_003F0CF8(u8 *p, s32 a, f32 x, f32 y) {
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
/* localdecomp:end func_003F0CF8 */

/* localdecomp:start func_003F0D38 */
void func_003F0D38(void *p, f32 value) {
    *(f32 *)(*(u8 **)((u8 *)p + 0x2C) + 0x50) = value;
}
/* localdecomp:end func_003F0D38 */

/* localdecomp:start func_003F0D48 */
void func_003F0D48(void *p, s16 value) {
    *(s16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x4C) = value;
}
/* localdecomp:end func_003F0D48 */

/* localdecomp:start func_003F0D58 */
void func_003F0D58(void *p, s16 value) {
    *(s16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x54) = value;
}
/* localdecomp:end func_003F0D58 */

/* localdecomp:start func_003F0D68 */
void func_003F0D68(u8 *p, s32 m, s32 on) {
    if (on) *(u16 *)(*(u8 **)(p + 0x2C) + 0x48) |= m;
    else *(u16 *)(*(u8 **)(p + 0x2C) + 0x48) &= ~m;
    p[0x30] = 0;
    *(s32 *)(p + 0x34) = 0;
}
/* localdecomp:end func_003F0D68 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003F0DA8);

/* localdecomp:start func_003F0DB0 */
void func_003F0DB0(void *p, s32 *a, s32 *b) {
    *a = *(u16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x48) & 1;
    *b = ((*(u16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x48) >> 1) ^ 1) & 1;
}
/* localdecomp:end func_003F0DB0 */

/* localdecomp:start func_003F0DE0 */
void func_003F0D68_003F0DE0(void *, s32, s32);

s32 func_003F0DE0(u8 *arg0, s32 arg1, s32 arg2) {
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
    func_003F0D68_003F0DE0(arg0, 1, a);
    func_003F0D68_003F0DE0(arg0, 2, b);
    *(s8 *)(arg0 + 0x30) = 0;
    *(s32 *)(arg0 + 0x34) = 0;
    return ok;
}
/* localdecomp:end func_003F0DE0 */

/* localdecomp:start func_003F0E70 */
extern void func_003EDDC0(void *, f32, f32);
void func_003F0E70(u8 *object, f32 *bounds) {
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
    func_003EDDC0(object, x, y);
    *(volatile s32 *)(object + 0x34) = 0;
    *(volatile u8 *)(object + 0x30) = 0;
}
/* localdecomp:end func_003F0E70 */

/* localdecomp:start func_003F0ED0 */
void func_003F0ED0(void *a0, s32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    *(u8 *)((u8 *)p + 0x58) = (u8)a1;
    *(u8 *)((u8 *)a0 + 0x30) = 0;
    *(s32 *)((u8 *)a0 + 0x34) = 0;
}
/* localdecomp:end func_003F0ED0 */

/* localdecomp:start func_003F0EE8 */
typedef struct {
    u8 p00[0x10];
    s32 f10;
    s32 f14;
    s16 h18;
    s16 h1A;
    u8 p1C[0xC];
    f32 f28;
    f32 f2C;
    f32 f30;
    u32 f34;
    u32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    u16 h48;
    u16 p4A;
    u16 h4C;
    u16 p4E;
    f32 f50;
    u16 h54;
    u16 h56;
    u8 b58;
    u8 b59;
    u8 b5A;
} P_3EB728;

typedef struct {
    u8 p00[0x20];
    void (*f20)(void *, s32, f32 *, s32);
} VT_3EB728;

typedef struct {
    u8 p00[8];
    VT_3EB728 *vt;
    u8 p0C[0x14];
    f32 f20;
    f32 f24;
    u32 f28;
    P_3EB728 *p;
    u8 b30;
    u8 p31[3];
    f32 f34;
} O_3EB728;

typedef struct {
    s16 y0, y1, x0, x1, tx, ty, w, h, f30, flags, f34, f36, f38, f3A;
} Desc_3EB728;

extern f32 D_001D96D0;
extern f32 D_001D96D4;
extern f32 D_001D96D8;
extern f32 D_001D96DC;
extern s32 D_001D55C4;
extern s32 D_00335860[];
extern void func_0038E478(s32);
extern void func_003EDF48(void *, f32 *);
extern void func_003F0DB0(void *, s32 *, s32 *);
extern s32 func_003EDD50(void *, s32);
extern void func_00391530();
extern void func_00391510();
extern void func_00390FE8(void);
extern void func_00390FC8(void);
extern void func_003E73D0(void);
extern long func_00389920(s32);

static __inline__ void TextA_3EB728(Desc_3EB728 *d, f32 f44, f32 ty, f32 *pw, f32 *px, unsigned long b1, s32 dd, s32 g, f32 l, f32 tx, s32 c, f32 t, unsigned long hh, f32 r, f32 sc3C, f32 *ph, f32 sc40, f32 *py, f32 b, f32 fl, s32 flags) {
    s32 o1, o2;
    f32 tt;
    s32 it;
    s32 fr;
    o1 = 0;
    o2 = 0;
    d->x0 = l * D_001D96D8;
    d->x1 = r * D_001D96D8;
    d->y0 = t * D_001D96DC;
    d->y1 = b * D_001D96DC;
    d->tx = tx * D_001D96D8;
    if (flags & 2) d->ty = (t + (b - t) * 0.5f) * D_001D96DC;
    else d->ty = ty * D_001D96DC;
    tt = sc40 * D_001D96DC;
    it = tt;
    d->ty += it;
    d->h = 0;
    d->w = 0;
    d->flags = flags;
    fr = (tt - it) * 16.0f;
    if (sc3C != 0.0f || sc40 != 0.0f) d->flags = flags | 8;
    d->f36 = fr;
    d->f30 = f44 * D_001D96DC;
    d->f34 = (s32)(sc3C * D_001D96D8) << 4;
    ((void (*)(void *, unsigned long, s32, s32, long, void *, s32, unsigned long, f32, s32 *, s32 *))func_00391530)(d, b1, c, dd, func_00389920(1), D_00335860, g, hh, fl, &o1, &o2);
    *pw = d->w;
    *ph = d->h;
    *px = (f32)o1 / D_001D96D8 + D_001D96D0;
    *py = (f32)o2 / D_001D96DC + D_001D96D4;
    func_003E73D0();
}

static __inline__ void TextB_3EB728(Desc_3EB728 *d, f32 tx, f32 *pw, f32 l, s32 flags, f32 ox, f32 f44, s32 c, f32 t, f32 r, f32 *ph, unsigned long b1, f32 b, f32 sc3C, f32 oy, f32 ty, f32 sc40, unsigned long hh, f32 fl) {
    f32 tt;
    s32 it;
    s32 fr;
    d->x0 = l * D_001D96D8;
    d->x1 = r * D_001D96D8;
    d->y0 = t * D_001D96DC;
    d->y1 = b * D_001D96DC;
    d->tx = tx * D_001D96D8;
    d->f38 = ox * D_001D96D8;
    d->f3A = oy * D_001D96D8;
    if (flags & 2) d->ty = (t + (b - t) * 0.5f) * D_001D96DC;
    else d->ty = ty * D_001D96DC;
    tt = sc40 * D_001D96DC;
    it = tt;
    d->ty += it;
    d->h = 0;
    d->w = 0;
    d->flags = flags;
    fr = (tt - it) * 16.0f;
    if (sc3C != 0.0f || sc40 != 0.0f) d->flags = flags | 8;
    d->f36 = fr;
    d->f30 = f44 * D_001D96DC;
    d->f34 = (s32)(sc3C * D_001D96D8) << 4;
    ((void (*)(void *, unsigned long, s32, s32, s32, s32, unsigned long, f32))func_00391510)(d, b1, c, -1, 0, D_001D55C4, hh, fl);
    *pw = d->w / D_001D96D8;
    *ph = d->h / D_001D96DC;
    func_003E73D0();
}

void func_003F0EE8(O_3EB728 *o, s32 a1) {
    f32 r[4];
    Desc_3EB728 d;
    s32 b40;
    s32 b44;
    f32 w;
    f32 h;
    f32 x0;
    f32 y0;
    f32 ox;
    f32 oy;
    s32 flags;
    P_3EB728 *p;

    if (o->p->f10 == 0 && o->p->f14 == 0) return;
    switch (o->p->b58) {
    case 1:
        func_0038E478(1);
        break;
    case 2:
        func_0038E478(0);
        break;
    case 0:
    default:
        func_0038E478(0);
        break;
    }
    o->vt->f20(o, a1, r, 1);
    func_003EDF48(o, r);
    {
        f32 dx;
        dx = r[2] - r[0];
        x0 = r[0];
        if (o->p->h48 & 1) x0 += dx * 0.5f;
    }
    y0 = r[1];
    w = 0.0f;
    h = 0.0f;
    func_003F0DB0(o, &b40, &b44);
    flags = b40 == 1;
    if (b44 == 1) flags |= 2;
    if (func_003EDD50(o, 0x40)) flags |= 0x20;
    ox = o->f20;
    oy = o->f24;
    if (func_003EDD50(o, 0x40)) {
        if (o->p->h18 == 0) goto check4;
        func_00390FE8();
        {
        P_3EB728 *q = o->p;
        TextA_3EB728(&d, q->f44, y0 + oy, &w, &q->f2C, o->f28, q->h18, q->h1A, r[0] + ox, x0 + ox, q->f14, r[1] + oy, o->f28, r[2] + ox, q->f3C, &h, q->f40, &q->f30, r[3] + oy, q->f28, flags);
        }
        func_00390FC8();
    }
    p = o->p;
    if (p->h18 == 0) {
check4:
        if (o->p->h48 & 4) {
            flags |= 4;
            TextB_3EB728(&d, x0, &w, r[0], flags, ox, o->p->f44, o->p->f10, r[1], r[2], &h, o->p->f34, r[3], o->p->f3C, oy, y0, o->p->f40, o->f28, o->p->f28);
            flags &= ~4;
            if (r[3] - r[1] < h) {
                switch (o->p->b59) {
                case 0:
                    if (o->p->b5A == 0 && (o->p->h48 & 0x40)) o->p->f40 = (r[3] - r[1]) + 0.005f;
                    if ((s16)--o->p->h56 > 0) break;
                    o->p->h56 = 0;
                    o->p->b59++;
                    if (o->p->b5A != 0) {
                        f32 v;
                        f32 z;
                        if (o->p->h48 & 0x40) v = (r[3] - r[1]) + 0.005f;
                        else v = o->p->f40;
                        z = 0.0f;
                        if (!(o->p->h48 & 0x10)) z = v;
                        o->p->f40 = z;
                    } else {
                        o->p->b5A = 1;
                    }
                    /* fallthrough */
                case 1:
                    if (h + r[1] + o->p->f40 < r[1]) {
                        o->p->f40 = o->p->f40 - o->p->f50;
                        o->p->h56 = o->p->h54;
                        o->p->b59++;
                    } else {
                        o->p->f40 = o->p->f40 - o->p->f50;
                    }
                    break;
                case 2:
                    if ((s16)--o->p->h56 > 0) break;
                    o->p->h56 = o->p->h4C;
                    o->p->b59 = 0;
                    {
                        f32 v;
                        P_3EB728 *q = o->p;
                        if (!(q->h48 & 0x10)) v = (r[3] - r[1]) + 0.005f;
                        else v = 0.0f;
                        q->f40 = v;
                    }
                    break;
                }
            }
        }
        TextB_3EB728(&d, x0, &w, r[0], flags, ox, o->p->f44, o->p->f10, r[1], r[2], &h, o->p->f34, r[3], o->p->f3C, oy, y0, o->p->f40, o->f28, o->p->f28);
        o->b30 = 1;
        o->f34 = h;

    } else {
        TextA_3EB728(&d, p->f44, y0, &w, &p->f2C, p->f34, p->h18, p->h1A, r[0], x0, p->f14, r[1], p->f38, r[2], p->f3C, &h, p->f40, &p->f30, r[3], p->f28, flags);
    }
}
/* localdecomp:end func_003F0EE8 */

/* localdecomp:start func_003F1B90 */
typedef struct { u8 b[16]; } B16_3EC3D0;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3EC3D0;
extern s32 func_0011A264(void *, s32, s32);
void func_003F1B90(O_3EC3D0 *o, f32 *p, f32 *out, s32 flag) {
    f32 sy = 2.0f;
    f32 ay = 0.0f;
    f32 sx = 2.0f;
    f32 ax = 0.0f;
    f32 t[4];
    f32 x0, y0, h, dx, dy;
    s32 k1, k2;
    if (flag) do {
        k1 = 0;
        k2 = 0;
        func_003EDD98(o, &k1, &k2);
        if (k1 != 3) {
            if (k1 == 1) {
                ax = 1.0f;
            } else {
                sx = 2.0f;
                ax = -1.0f;
            }
        }
        if (k2 != 3) {
            if (k2 == 2) {
                sy = 2.0f;
                ay = -1.0f;
            } else {
                sy = 2.0f;
                ay = 1.0f;
            }
        }
    } while (0);
    x0 = o->f10;
    x0 = (p[2] - p[0]) * x0 + p[0];
    y0 = o->f14;
    y0 = (p[3] - p[1]) * y0 + p[1];
    out[0] = (x0 - o->f18 / sx) + (ax * o->f18) / sx;
    h = o->f1C;
    out[1] = (y0 - h / sy) + (ay * h) / sy;
    out[2] = out[0] + o->f18;
    out[3] = out[1] + o->f1C;
    if (func_003EDD50(o, 0x40)) {
        dx = o->f20;
        dy = o->f24;
        func_0011A264(t, 0, 0x10);
        *(B16_3EC3D0 *)t = *(B16_3EC3D0 *)out;
        t[0] += dx;
        t[2] += dx;
        t[1] += dy;
        t[3] += dy;
        out[0] = (t[0] < out[0]) ? t[0] : out[0];
        out[2] = (out[2] < t[2]) ? t[2] : out[2];
        out[3] = (out[3] < t[3]) ? t[3] : out[3];
        out[1] = (t[1] < out[1]) ? t[1] : out[1];
    }
}
/* localdecomp:end func_003F1B90 */

/* localdecomp:start func_003F1DF0 */
s32 func_003F1DF0(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))(*(u8 **)((u8 *)p + 0x2C) + 0x8);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003F1DF0 */

/* localdecomp:start func_003F1E20 */
s32 func_003F1E20(s32 p, s32 k) {
    if (k != 3) {
        return func_003EDE00(p, k);
    }
    return 1;
}
/* localdecomp:end func_003F1E20 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003F1E50);

/* localdecomp:start func_003F1EA0 */
extern void func_003EDD28(void *, s32, s32);
extern void func_003EDBE0(void);
extern u8 D_001D9838[];
void *func_003F1EA0(void *arg0)
{
  func_003EDBE0();
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
  func_003EDD28(arg0, 0x100, 1);
  return arg0;
}
/* localdecomp:end func_003F1EA0 */

/* localdecomp:start func_003F1F20 */
extern s32 D_001D9830_g;
extern s32 func_003EDE00(s32, s32);
s32 func_003F1F20(s32 p, s32 k) {
    if (k != D_001D9830_g) return func_003EDE00(p, k);
    return 1;
}
/* localdecomp:end func_003F1F20 */

/* localdecomp:start func_003F1F50 */
extern s32 D_001D9830_g;
s32 func_003F1F50(void) {
    return D_001D9830_g;
}
/* localdecomp:end func_003F1F50 */

/* localdecomp:start func_003F1F58 */
void func_003F1F58(u8 *p, f32 *a) {
    *(f32 *)(p + 0x10) = a[0] + (a[2] - a[0]) * 0.5f;
    *(f32 *)(p + 0x14) = a[1] + (a[3] - a[1]) * 0.5f;
}
/* localdecomp:end func_003F1F58 */

/* localdecomp:start func_003F1F98 */
typedef struct {
    void *vt0; void *vt4; s32 (**vt)(); u8 pad0[0x4]; f32 f10, f14, f18, f1C; u8 pad20[0x18]; s32 f38; f32 f3C; s32 f40; s32 f44;
} O_3EC7D8;
extern f32 D_001D96C8[], D_001D96CC[], D_001D96D0_003F1F98[], D_001D96D4_003F1F98[], D_001D96D8_003F1F98[], D_001D96DC_003F1F98[];
extern s32 func_003EDD50();
extern void func_003EDF48();
extern s32 func_003ABFF0();
extern void func_003AA588(void *, s32, f32, f32, f32, f32, f32);
void func_003F1F98(O_3EC7D8 *o, s32 a) {
    f32 b[4];
    s32 p;
    f32 x, y;
    if (o->f44 == 0) return;
    o->vt[8](o, a, b, 1);
    if (func_003EDD50(o, 0x100) != 0) {
        f32 x, y;
        f32 c;
        f32 d;
        f32 e;
        s32 fl;
        s32 k = o->f40;
        p = func_003ABFF0(o->f44, k);
        x = o->f10; y = o->f14; fl = o->f38; c = o->f18; d = o->f1C; e = o->f3C;
        if (p == 0) return;
        func_003AA588((void *)p, fl, (x + D_001D96D0_003F1F98[0]) * D_001D96D8_003F1F98[0], (y + D_001D96D4_003F1F98[0]) * D_001D96DC_003F1F98[0], c * D_001D96C8[0], d * D_001D96CC[0], e);
    } else {
        s32 k;
        f32 c;
        f32 d;
        f32 e;
        s32 fl;
        func_003EDF48(o, b);
        x = b[0] + (b[2] - b[0]) * 0.5f;
        y = b[1] + (b[3] - b[1]) * 0.5f;
        k = o->f40;
        p = func_003ABFF0(o->f44, k);
        fl = o->f38; c = o->f18; d = o->f1C; e = o->f3C;
        if (p == 0) return;
        func_003AA588((void *)p, fl, (x + D_001D96D0_003F1F98[0]) * D_001D96D8_003F1F98[0], (y + D_001D96D4_003F1F98[0]) * D_001D96DC_003F1F98[0], c * D_001D96C8[0], d * D_001D96CC[0], e);
    }
}
/* localdecomp:end func_003F1F98 */

/* localdecomp:start func_003F2120 */
typedef struct { u8 p0[0x10]; f32 f10; f32 f14; f32 f18; f32 f1C; u8 p1[0x1C]; f32 f3C; s32 f40; u8 *f44; } O_3EC960;
extern s32 func_003ABFF0(u8 *, s32);
extern void func_003AA238(f32, f32, f32, s32, f32 *, f32 *);
void func_003F2120(O_3EC960 *a, f32 *b, f32 *out) {
    struct { s32 st[2]; f32 w[2]; } v;
    f32 one, cx, cy, sx, sy, dx, dy;
    f32 w0, w1;
    s32 r;
    v.st[0] = 0;
    v.st[1] = 0;
    func_003EDD98(a, &v.st[0], &v.st[1]);
    one = 1.0f;
    cx = a->f10;
    cy = a->f14;
    cx = (b[2] - b[0]) * cx + b[0];
    cy = (b[3] - b[1]) * cy + b[1];
    sy = 2.0f;
    sx = sy;
    dy = 0.0f;
    dx = dy;
    v.w[0] = one;
    v.w[1] = one;
    if (func_003EDD50(a, 0x100)) {
        out[0] = dy;
        out[3] = one;
        out[2] = one;
        out[1] = dy;
        return;
    }
    if (v.st[0] != 3) {
        if (v.st[0] == 1) {
            sx = 2.0f;
            dx = 1.0f;
        } else {
            sx = 2.0f;
            dx = -1.0f;
        }
    }
    if (v.st[1] != 3) {
        if (v.st[1] == 2) {
            sy = 2.0f;
            dy = -1.0f;
        } else {
            sy = 2.0f;
            dy = 1.0f;
        }
    }
    r = func_003ABFF0(a->f44, a->f40);
    func_003AA238(a->f18, a->f1C, a->f3C, r, &v.w[0], &v.w[1]);
    w0 = v.w[0] / D_001D96D8;
    w1 = v.w[1] / D_001D96DC;
    v.w[0] = w0;
    v.w[1] = w1;
    out[0] = cx - w0 / sx + dx * w0 / sx;
    out[1] = cy - w1 / sy + dy * w1 / sy;
    out[2] = out[0] + w0;
    out[3] = out[1] + w1;
}
/* localdecomp:end func_003F2120 */

/* localdecomp:start func_003F2340 */
s32 func_003F2340(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))((u8 *)p + 0x34);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003F2340 */

/* localdecomp:start func_003F2370 */
extern char D_001D96B0[];
extern s32 func_003F2578();
void func_003F2370(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D96B0; if (f & 1) func_003F2578(p); }
/* localdecomp:end func_003F2370 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003F23A0);

/* localdecomp:start func_003F23E0 */
void func_003F23E0(s32 *p, s32 a, s32 b, s32 c) {
    p[1] = b;
    p[2] = c;
    p[3] = a;
    p[6] = 0;
    p[4] = 0;
    p[5] = 0;
}
/* localdecomp:end func_003F23E0 */

/* localdecomp:start func_003F2400 */
extern u8 D_001D9880[];
void **func_003F2400(void **p) { p[1] = 0; p[0] = D_001D9880; p[2] = 0; p[3] = 0; p[6] = 0; p[4] = 0; p[5] = 0; return p; }
/* localdecomp:end func_003F2400 */
