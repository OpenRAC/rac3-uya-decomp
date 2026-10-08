#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00124F20(s32);
extern void func_00125F70(s32, s32);
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124988);

LINKER_REMNANT("asm/boot_elf/remnants", func_001249E8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001249F0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124A28);

ASM_FUNC("asm/boot_elf/handwritten", func_00124A68);

LINKER_REMNANT("asm/boot_elf/remnants", func_00124A78);

/* localdecomp:start func_00124A80 */
extern u32 D_0013E300[4];
extern u32 D_0013E2F8;
extern void func_00124B80(u32, u32);
extern u32 func_00124A68(u32, u32, void *);
extern void func_00124A28(void);
extern void func_001249F0(void);

void func_00124A80(void) {
    u32 a;
    u32 b;
    u32 pa;
    u32 pb;

    func_00124B80(D_0013E300[0], D_0013E300[1]);
    func_00124B80(D_0013E300[2], D_0013E300[3]);
    a = func_00124A68(0x80000000, 0x80080000, func_00124A28);
    b = func_00124A68(0x80000000, 0x80080000, func_001249F0);
    pa = a - 0x20C;
    pb = b - 0x168;
    while (pa != pb) {
        if (pa < pb) {
            a = func_00124A68(a + 4, 0x80080000, func_00124A28);
            pa = a - 0x20C;
        } else {
            b = func_00124A68(b + 4, 0x80080000, func_001249F0);
            pb = b - 0x168;
        }
    }
    D_0013E2F8 = pa;
}
/* localdecomp:end func_00124A80 */

ASM_FUNC("asm/boot_elf/handwritten", func_00124B80);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124B90);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124BE4);

ASM_FUNC("asm/boot_elf/handwritten", func_00124BE8);

ASM_FUNC("asm/boot_elf/handwritten", func_00124BF8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124C08);

ASM_FUNC("asm/boot_elf/handwritten", func_00124C40);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124C50);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124CB8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124D64);

ASM_FUNC("asm/boot_elf/handwritten", func_00124D68);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124D78);

ASM_FUNC("asm/boot_elf/handwritten", func_00124DA8);

/* localdecomp:start func_00124DB8 */
extern char *D_0013E020;
extern int D_0013EAD8[];
extern void func_00124DA8(int a, int b);
extern void *func_00124D68(void *dst, void *src, int n);
extern int func_0011B868();

char *func_00124DB8(char *name, int argc, char **argv)
{
    char *p;
    char *buf;
    char *ret;
    int len;
    int i;

    p = D_0013E020;
    buf = p + 0x40;
    ret = buf;
    func_00124DA8(D_0013EAD8[0], D_0013EAD8[1]);
    if (argc >= 16) {
        argc = 15;
    }
    func_00124D68(p, &buf, 4);
    p += 4;
    len = func_0011B868(name) + 1;
    func_00124D68(buf, name, len);
    buf += len;
    for (i = 0; i < argc; i++) {
        func_00124D68(p, &buf, 4);
        p += 4;
        len = func_0011B868(argv[i]) + 1;
        func_00124D68(buf, argv[i], len);
        buf += len;
    }
    return ret;
}
/* localdecomp:end func_00124DB8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124ED0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124ED8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124F20);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124F48);

ASM_FUNC("asm/boot_elf/handwritten", func_00124F50);

ASM_FUNC("asm/boot_elf/handwritten", func_00124F60);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124F70);

ASM_FUNC("asm/boot_elf/handwritten", func_00124FA8);

/* localdecomp:start func_00124FB8 */
/* libkernl: patch IOP memory from the address/value table when the IOP is not yet up; 2.9-ee-991111 */
typedef struct { u32 a; u32 v; } P_124FB8;

extern void func_00124F50(u32, u32);
extern void func_00124F60(u32, void *, s32);
extern u32 func_00124FA8(u32);
extern void func_0011F0A0(s32);
extern P_124FB8 D_0013F248[];
extern u8 D_0013EAE0[];
extern u8 D_0013F220[];

void func_00124FB8(void) {
    u32 i;

    if (*(volatile u32 *)0x10001810 & 0x100) {
        return;
    }
    func_00124F50(D_0013F248[0].a, D_0013F248[0].v);
    func_00124F60(0x80076000, D_0013EAE0, 0x740);
    func_00124F60(0x82000, D_0013F220, 0x28);
    func_0011F0A0(0);
    func_0011F0A0(2);
    func_00124F50(D_0013F248[1].a, D_0013F248[1].v);
    for (i = 2; i < 8; i++) {
        func_00124F50(D_0013F248[i].a, func_00124FA8(D_0013F248[i].a));
    }
}
/* localdecomp:end func_00124FB8 */

ASM_FUNC("asm/boot_elf/handwritten", func_0012508C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125100);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125110);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125120);

/* localdecomp:start func_00125130 */
typedef struct Alarm_125130 {
    struct Alarm_125130 *next;
    u8 pad4[0x40 - 4];
} Alarm_125130;
typedef struct {
    u64 f0;
    int id;
    int fC;
    int f10;
    Alarm_125130 *free;
} Timer_125130;
extern Timer_125130 D_0013F288;
extern Alarm_125130 D_157AC0[];
extern s32 func_0011A264();
extern void func_00125C68(void);
extern int func_0011EB10(int cause, void *handler, int next, void *arg);
extern int func_0011F8D8(int cause);
extern void func_00125100(int n);
extern void func_00125110(int n);
extern void func_00125120(int n);
extern int func_00125578();
int func_00124920(void);
int func_00124970(void);

int func_00125130(int mode)
{
    int i;
    int id;
    int di;
    u32 m;

    if (D_0013F288.id >= 0) {
        return 0x80008001;
    }
    D_0013F288.f0 = 0;
    D_0013F288.f10 = 0;
    func_0011A264(D_157AC0, 0, 0x2000);
    D_0013F288.free = D_157AC0;
    for (i = 0x7F; i >= 0; i--) {
        D_157AC0[i].next = &D_157AC0[i + 1];
    }
    D_157AC0[0x7F].next = 0;
    func_00125C68();
    id = func_0011EB10(0xB, func_00125578, 0, 0);
    if (id < 0) {
        return 0x80009021;
    }
    D_0013F288.id = id;
    di = func_00124920();
    m = *(volatile u32 *)0x10001010;
    m = (m & ~3) | mode;
    m |= 0x300;
    if (!(m & 0x80)) {
        func_00125100(0);
        m |= 0xC80;
        func_00125120(0xFFFF);
    }
    func_00125110(m);
    func_0011F8D8(0xB);
    if (di) {
        func_00124970();
    }
    return 0;
}
/* localdecomp:end func_00125130 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00125288);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125290);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125320);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125328);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001254B8);

/* localdecomp:start func_00125540 */
typedef struct N_125540 { struct N_125540 *next; struct N_125540 *prev; } N_125540;
extern N_125540 *D_0013F2A0[];
N_125540 *func_00125540(N_125540 *p) {
    N_125540 *next = p->next;
    if (p->prev != 0) {
        p->prev->next = next;
    } else {
        D_0013F2A0[0] = next;
    }
    if (next != 0) {
        next->prev = p->prev;
    }
    p->prev = 0;
    return next;
}
/* localdecomp:end func_00125540 */

ASM_FUNC("asm/boot_elf/handwritten", func_00125578);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125820);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125870);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125878);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001258E8);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125930);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125938);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125940);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001259F0);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125A40);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125A68);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125A70);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125B68);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125BE8);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125C58);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125C60);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125C68);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125CB8);

/* localdecomp:start func_00125D18 */
typedef struct Alarm_125D18 {
    struct Alarm_125D18 *next;
    volatile int id;
    void *handler;
    void *arg;
} Alarm_125D18;
extern Alarm_125D18 *D_159EC0;
extern int func_001258E8(void);
extern void func_00125B68(int id, int time, void *cb, void *arg);
extern void func_001259F0(int id);
extern void func_00125CB8();
int func_00124920(void);
int func_00124970(void);

int func_00125D18(int time, void *handler, void *arg)
{
    Alarm_125D18 *p;
    Alarm_125D18 *q;
    int di;
    int id;

    if (handler == 0) {
        return 0x80000016;
    }
    di = func_00124920();
    q = D_159EC0;
    if (q) {
        D_159EC0 = q->next;
    }
    p = q;
    if (p == 0) {
        if (di) {
            func_00124970();
        }
        return 0x80008005;
    }
    id = func_001258E8();
    if (id < 0) {
        p->next = D_159EC0;
        D_159EC0 = p;
        p->id = 0;
        if (di) {
            func_00124970();
        }
        return id;
    }
    p->handler = handler;
    p->arg = arg;
    p->id = id;
    func_00125B68(id, time, func_00125CB8, p);
    func_001259F0(id);
    if (di) {
        func_00124970();
    }
    return ((u32)p << 4) | (id & 0xFE) | 1;
}
/* localdecomp:end func_00125D18 */

/* localdecomp:start func_00125E48 */
typedef struct Node_125E48 {
    struct Node_125E48 *next;
    volatile s32 id;
    s32 x8;
    s32 xC;
} Node_125E48;

extern Node_125E48 *D_159EC0_00125E48;
extern s32 func_00125878(void);
extern void func_00125A70(s32, s32, void *, Node_125E48 *);
extern void func_00125940(s32);
extern void func_00125CB8(void);

static inline Node_125E48 *alloc_125E48(void) {
    Node_125E48 *n = D_159EC0_00125E48;
    if (n != 0) {
        D_159EC0_00125E48 = n->next;
    }
    return n;
}

static inline void free_125E48(Node_125E48 *n) {
    n->next = D_159EC0_00125E48;
    D_159EC0_00125E48 = n;
}

s32 func_00125E48(s32 a, s32 b, s32 c) {
    Node_125E48 *n;
    s32 id;

    if (b == 0) {
        return 0x80000016;
    }
    n = alloc_125E48();
    if (n == 0) {
        return 0x80008005;
    }
    id = func_00125878();
    if (id < 0) {
        free_125E48(n);
        n->id = 0;
        return id;
    }
    n->x8 = b;
    n->xC = c;
    n->id = id;
    func_00125A70(id, a, func_00125CB8, n);
    func_00125940(id);
    return ((s32)n << 4) | (id & 0xFE) | 1;
}
/* localdecomp:end func_00125E48 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125F38);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125F60);

LINKER_REMNANT("asm/boot_elf/remnants", func_00125F68);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00125F70);

LINKER_REMNANT("asm/boot_elf/remnants", func_00126018);
