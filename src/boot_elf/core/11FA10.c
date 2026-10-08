#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_0011FA10 */
typedef struct {
    u8 type;
    u8 id;
} Ent_11FA10;

typedef struct {
    s32 x0;
    s32 x4;
    Ent_11FA10 ent[0x200];
} Q_11FA10;

extern s32 D_152800;
extern char D_00150788[];
extern s32 func_0011EE60_0011FA10(s32);
extern void func_0011ED50(s32);
extern void func_0011ECD0(s32);
extern void func_0011ED90(s32);
extern void func_001217E0(const char *, ...);

void func_0011FA10(Q_11FA10 *q) {
    s32 i;

    while (1) {
        func_0011EE60_0011FA10(D_152800);
        i = q->x0 & 0x1FF;
        q->x0 = i + 1;
        switch (q->ent[i].type) {
        case 0:
            func_0011ED50(q->ent[i].id);
            break;
        case 1:
            func_0011ECD0(q->ent[i].id);
            break;
        case 2:
            func_0011ED90(q->ent[i].id);
            break;
        default:
            func_001217E0(D_00150788);
            break;
        }
    }
}
/* localdecomp:end func_0011FA10 */

/* localdecomp:start func_0011FAE8 */
typedef struct {
    int status;
    void *entry;
    void *stack;
    int stackSize;
    void *gpReg;
    int initPriority;
    int currentPriority;
    u32 attr;
    u32 option;
    u8 pad24[0x30 - 0x24];
} ThreadParam_11FAE8;
typedef struct {
    int count;
    int max_count;
    int init_count;
    int wait_threads;
    u32 attr;
    u32 option;
} SemaParam_11FAE8;
extern int D_0013DBF0;
extern int D_152800;
extern int D_152808[];
extern u8 D_152400[];
extern u8 D_1DC8B0[];
extern char D_001507B0[];
extern int func_0011EE20();
extern int func_0011EE30();
extern int func_0011EC20();
extern int func_0011FD40();
extern int func_0011ED10();
extern int func_0011ECB0();
extern void func_0011FA10();

int func_0011FAE8(void)
{
    ThreadParam_11FAE8 tp;
    SemaParam_11FAE8 sp;

    if (D_0013DBF0 > 0) {
        return -1;
    }
    sp.max_count = 0xFF;
    sp.init_count = 0;
    sp.option = (u32)D_001507B0;
    D_152800 = func_0011EE20(&sp);
    if (D_152800 < 0) {
        return -1;
    }
    tp.entry = func_0011FA10;
    tp.stack = D_152400;
    tp.stackSize = 0x400;
    tp.gpReg = D_1DC8B0;
    tp.initPriority = 0;
    tp.option = (u32)D_001507B0;
    D_0013DBF0 = func_0011EC20(&tp);
    if (D_0013DBF0 < 0) {
        func_0011EE30(D_152800);
        return -1;
    }
    D_152808[0] = 0;
    D_152808[1] = 0;
    func_0011FD40(D_0013DBF0, D_152808);
    func_0011ECB0(func_0011ED10(), 1);
    return D_0013DBF0;
}
/* localdecomp:end func_0011FAE8 */

ASM_FUNC("asm/boot_elf/handwritten", func_0011FBD8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0011FC70);

ASM_FUNC("asm/boot_elf/handwritten", func_0011FC78);

/* localdecomp:start func_0011FD40 */
typedef struct {
    s32 status;
    void *entry;
    u8 *stack;
    s32 stackSize;
    s32 pad[8];
} ThreadInfo_11FD40;

extern s32 func_0011F860(void);
extern s32 func_00124920(void);
extern s32 func_00124970(void);
extern s32 func_0011ED20(s32, ThreadInfo_11FD40 *);
extern s32 func_0011EC40(s32, s32);

s32 func_0011FD40(s32 tid, s32 arg) {
    ThreadInfo_11FD40 info;
    s32 r;
    u8 *p;

    if (func_0011F860() != 0) {
        return -1;
    }
    if (func_00124920() == 0) {
        return -1;
    }
    r = func_0011ED20(tid, &info);
    if (r < 0) {
        func_00124970();
        return r;
    }
    if (info.status != 0x10) {
        func_00124970();
        return -1;
    }
    p = info.stack + info.stackSize - 0x2A0;
    __asm__ __volatile__(
        "sq $0, 0x0(%0)\n"
        "sq $0, 0x10(%0)\n"
        "sq $0, 0x20(%0)\n"
        "sq $0, 0x30(%0)\n"
        "sq $0, 0x40(%0)\n"
        "sq $0, 0x50(%0)\n"
        "sq $0, 0x60(%0)\n"
        "sq $0, 0x70(%0)\n"
        "sq $0, 0x80(%0)\n"
        "sq $0, 0x90(%0)\n"
        "sq $0, 0xA0(%0)\n"
        "sq $0, 0xB0(%0)\n"
        "sq $0, 0xC0(%0)\n"
        "sq $0, 0xD0(%0)\n"
        "sq $0, 0xE0(%0)\n"
        "sq $0, 0xF0(%0)\n"
        "sq $0, 0x100(%0)\n"
        "sq $0, 0x110(%0)\n"
        "sq $0, 0x120(%0)\n"
        "sq $0, 0x130(%0)\n"
        "sq $0, 0x140(%0)\n"
        "sq $0, 0x150(%0)\n"
        "sq $0, 0x160(%0)\n"
        "sq $0, 0x170(%0)\n"
        "sq $0, 0x180(%0)\n"
        "sq $0, 0x190(%0)\n"
        "sq $0, 0x1A0(%0)\n"
        "sq $0, 0x1B0(%0)\n"
        "sq $0, 0x200(%0)\n"
        "sq $0, 0x210(%0)\n"
        "sq $0, 0x220(%0)\n"
        "sq $0, 0x230(%0)\n"
        "sq $0, 0x240(%0)\n"
        "sq $0, 0x250(%0)\n"
        "sq $0, 0x260(%0)\n"
        "sq $0, 0x270(%0)\n"
        "sll $8, %1, 0\n"
        "sd $8, 0x40(%0)\n"
        "lw $8, 0x1C0(%0)\n"
        "sd $8, 0x1C0(%0)\n"
        "sd $0, 0x1C8(%0)\n"
        "lw $8, 0x1D0(%0)\n"
        "sd $8, 0x1D0(%0)\n"
        "sd $0, 0x1D8(%0)\n"
        "lw $8, 0x1E0(%0)\n"
        "sd $8, 0x1E0(%0)\n"
        "sd $0, 0x1E8(%0)\n"
        "lw $8, 0x1F0(%0)\n"
        "sd $8, 0x1F0(%0)\n"
        "sd $0, 0x1F8(%0)\n"
        : : "r"(p), "r"(arg) : "$8", "memory");
    func_00124970();
    return func_0011EC40(tid, arg);
}
/* localdecomp:end func_0011FD40 */

ASM_FUNC("asm/boot_elf/handwritten", func_0011FEB8);

/* localdecomp:start func_0011FEE0 */
extern s32 func_0011F250(s32, s32 *);
extern u8 D_152C10[];
s32 func_0011FEE0(u16 a, s32 b, s32 c) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = (s32)D_152C10 | 0x20000000;
    return func_0011F250(1, buf);
}
/* localdecomp:end func_0011FEE0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0011FF28);

/* localdecomp:start func_0011FF30 */
extern s32 func_0011F250(s32, s32 *);
s32 func_0011FF30(s32 a, s8 b) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    return func_0011F250(3, buf);
}
/* localdecomp:end func_0011FF30 */

/* localdecomp:start func_0011FF60 */
extern s32 func_0011F250(s32, s32 *);
s32 func_0011FF60(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0011F250(4, buf);
}
/* localdecomp:end func_0011FF60 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0011FF88);

/* localdecomp:start func_0011FF90 */
extern s32 func_0011F250(s32, s32 *);
s32 func_0011FF90(s32 a, s32 b, u16 c) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    return func_0011F250(-5, buf);
}
/* localdecomp:end func_0011FF90 */

/* localdecomp:start func_0011FFC8 */
extern s32 func_0011F250(s32, s32 *);
s32 func_0011FFC8(s32 a, s32 b, u16 c) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    return func_0011F250(-6, buf);
}
/* localdecomp:end func_0011FFC8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00120000);

LINKER_REMNANT("asm/boot_elf/remnants", func_00120008);

/* localdecomp:start func_00120010 */
extern s32 func_0011F250(s32, s32 *);
s32 func_00120010(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0011F250(0x10, buf);
}
/* localdecomp:end func_00120010 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00120034);

/* localdecomp:start func_00120038 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; u8 x10[0x10]; } S_120038;
extern S_120038 D_152C40;
S_120038 *func_00120038(s32 a) {
    D_152C40.x0 = a;
    D_152C40.x4 = 0;
    D_152C40.xC = (s32)D_152C40.x10;
    D_152C40.x8 = (s32)D_152C40.x10;
    return &D_152C40;
}
/* localdecomp:end func_00120038 */

/* localdecomp:start func_00120060 */
typedef struct { s32 size; s32 count; u8 *rd; u8 *wr; u8 buf[1]; } R_120060;
void func_00120060(R_120060 *p) {
    p->count++;
    p->wr++;
    if (p->wr == p->buf + p->size) {
        p->wr = p->buf;
    }
}
/* localdecomp:end func_00120060 */

/* localdecomp:start func_001200A0 */
typedef struct { s32 size; s32 count; u8 *rd; u8 *wr; u8 buf[1]; } R_1200A0;
void func_001200A0(R_1200A0 *p) {
    p->count--;
    p->rd++;
    if (p->rd == p->buf + p->size) {
        p->rd = p->buf;
    }
}
/* localdecomp:end func_001200A0 */

/* localdecomp:start func_001200E0 */
typedef struct {
    s32 fd;
    volatile s32 count;
    volatile u32 len;
    volatile s32 xC;
    u8 *ptr;
    u8 *buf;
    R_120060 *ring;
} S_1200E0;

extern char D_001507E0[];
extern char D_00150808[];
extern char D_00150820[];
extern char D_00150838[];
extern void func_00120060_001200E0();
extern void func_001217E0(const char *, ...);

void func_001200E0(s32 type, s32 n, S_1200E0 *s) {
    s32 r;
    u32 t;
    u16 *hdr;

    switch (type) {
    case 1:
    case 2:
        if (n != 0) {
            if (s->len + n > 0x140) {
                func_001217E0(D_001507E0);
            }
            t = s->len;
            n = func_0011FF90(s->fd, (s32)(s->buf + t), n & 0xFFFF);
            if (n < 0) {
                func_001217E0(D_00150808);
            }
            s->len += n;
        } else {
            hdr = (u16 *)s->buf;
            for (n = 0xC; n < hdr[0]; n++) {
                *s->ring->wr = s->buf[n];
                func_00120060_001200E0(s->ring);
            }
            s->len = 0;
        }
        break;
    case 3:
        r = func_0011FFC8(s->fd, (s32)s->ptr, s->count & 0xFFFF);
        if (r < 0) {
            func_001217E0(D_00150820, r);
            goto end;
        }
        s->ptr += r;
        s->count -= r;
        break;
    case 4:
        if (s->count != 0) {
            func_001217E0(D_00150838, s->count);
        }
    end:
        s->xC = 0;
        break;
    }
}
/* localdecomp:end func_001200E0 */

/* localdecomp:start func_00120278 */
typedef struct {
    s32 sock;
    volatile s32 len;
    s32 pad8;
    volatile s32 busy;
    s8 *pkt;
} St_120278;

extern volatile St_120278 D_152D50;
extern u8 D_152D80[];
extern s32 func_00124920(void);
extern s32 func_00124970(void);
extern s32 func_0011FF30(s32, s8);
extern s32 func_0011FF60(s32);

s32 func_00120278(s8 *buf, s32 len)
{
    s32 count = 0;
    s32 i = 0;
    s32 r;
    s8 *pkt;
    s8 *dst;

    if (D_152D50.busy != 0) {
        return -1;
    }
    r = func_00124920();
    pkt = (s8 *)((u32)D_152D80 | 0x20000000);
    D_152D50.busy = 1;
    D_152D50.pkt = pkt;
    dst = pkt + 0xC;
    while (--len != -1) {
        if (*buf == '\n') {
            *dst++ = '\r';
            if (++i >= 0x100) {
                break;
            }
        }
        *dst++ = *buf++;
        count++;
        if (++i >= 0x100) {
            break;
        }
    }
    D_152D50.len = i + 0xC;
    *(u16 *)pkt = D_152D50.len;
    if (func_0011FF30(D_152D50.sock, pkt[7]) < 0) {
        D_152D50.busy = 0;
        if (r != 0) {
            func_00124970();
        }
        return -1;
    }
    while (D_152D50.busy != 0) {
        ((void (*)(s32))func_0011FF60)(D_152D50.sock);
    }
    if (r != 0) {
        func_00124970();
    }
    return count;
}
/* localdecomp:end func_00120278 */

/* localdecomp:start func_001203F0 */
typedef struct {
    int f0;
    volatile int f4;
    u8 *f8;
} Ring_1203F0;
typedef struct {
    u8 pad0[0x18];
    Ring_1203F0 *f18;
} Sio_1203F0;
extern Sio_1203F0 D_152D50_001203F0;
extern void func_001200A0();

int func_001203F0(char *buf, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        while (D_152D50_001203F0.f18->f4 == 0) {
        }
        buf[i] = *D_152D50_001203F0.f18->f8;
        func_001200A0(D_152D50_001203F0.f18);
        if (buf[i] == '\n' || buf[i] == '\r') {
            return i + 1;
        }
    }
    return i;
}
/* localdecomp:end func_001203F0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001204C0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012057C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00120580);

/* localdecomp:start func_001205B8 */
extern int D_0013DBF4;
extern char D_153000[];
extern s32 func_00120010();

void func_001205B8(int c)
{
    int i;

    if (D_0013DBF4 >= 0x7E) {
        D_0013DBF4 = 0;
        D_153000[0x7F] = 0;
        func_00120010(D_153000);
    }
    i = D_0013DBF4;
    if (c == '\n') {
        D_0013DBF4 = 0;
        D_153000[i] = c;
        D_153000[i + 1] = 0;
        func_00120010(D_153000);
        return;
    }
    D_0013DBF4 = i + 1;
    D_153000[i] = c;
}
/* localdecomp:end func_001205B8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00120668);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001206A0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00120730);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00120908);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00121620);

/* localdecomp:start func_00121678 */
extern void func_001205B8(s32);
s32 func_00121678(s32 a, s32 b, s32 c) {
    if (c != 0) {
        func_001205B8(c);
    }
    return 1;
}
/* localdecomp:end func_00121678 */

/* localdecomp:start func_001216A0 */
extern void func_00120668(s32);
s32 func_001216A0(s32 a, s32 b, s32 c) {
    if (c != 0) {
        func_00120668(c);
    }
    return 1;
}
/* localdecomp:end func_001216A0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001216C8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00121718);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00121760);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001217E0);

/* localdecomp:start func_00121860 */
typedef struct { u8 pad[0x10]; s32 x10; s32 x14; } A_121860;
typedef struct { u8 pad[0x1C]; s32 *x1C; } B_121860;
void func_00121860(A_121860 *a, B_121860 *b) {
    b->x1C[a->x10] = a->x14;
}
/* localdecomp:end func_00121860 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00121880);

/* localdecomp:start func_00121890 */
extern s32 D_153300[];
s32 func_00121890(s32 i) {
    return D_153300[i];
}
/* localdecomp:end func_00121890 */

LINKER_REMNANT("asm/boot_elf/remnants", func_001218A8);

LINKER_REMNANT("asm/boot_elf/remnants", func_001218B0);

/* localdecomp:start func_001218B8 */
typedef struct {
    void *f0;
    void *f4;
    s32 f8;
    void *fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 *f1C;
} S_1218B8;
typedef struct {
    void (*fn)(void *, void *);
    void *arg;
    s32 pad;
} H_1218B8;
typedef struct {
    u8 pad0[0xC];
    s32 fC;
    void *f10;
} P_1218B8;
extern s32 D_0013DBF8[];
extern s32 D_153300[];
extern s32 D_153154[];
extern u8 D_153080[];
extern u8 D_153100[];
extern S_1218B8 D_153158;
extern H_1218B8 D_153180[];
extern P_1218B8 D_153140;
extern s32 func_00124920(void);
extern s32 func_00124970(void);
extern void func_0011F0A0(s32);
extern void func_0011F200(void);
extern s32 func_0011EB30(s32, void *, s32);
extern s32 func_0011F9A8(s32);
extern u32 func_0011F230();
extern s32 func_0011F220(s32, s32);
extern s32 func_00121D70(s32, s32, s32, s32, s32, s32);
extern void func_00121880();
extern void func_00121860();
extern void func_00121DF0();

void func_001218B8(void)
{
    s32 i;
    s32 r;

    func_00124920();
    if (D_0013DBF8[0] != 0) {
        func_00124970();
        return;
    }
    D_0013DBF8[0] = 1;
    D_153158.f0 = (void *)((u32)D_153080 | 0x20000000);
    D_153158.f4 = (void *)((u32)D_153100 | 0x20000000);
    D_153158.f8 = 0;
    D_153158.fC = D_153180;
    D_153158.f10 = 0x20;
    D_153158.f14 = 0;
    D_153158.f18 = 0;
    D_153158.f1C = D_153300;
    for (i = 0; i < 0x20; i++) {
        D_153180[i].fn = 0;
        D_153180[i].arg = 0;
    }
    for (i = 0; i < 0x20; i++) {
        D_153300[i] = 0;
    }
    D_153180[0].fn = func_00121880;
    D_153180[1].fn = func_00121860;
    D_153180[0].arg = &D_153158;
    D_153180[1].arg = &D_153158;
    func_00124970();
    func_0011F0A0(0);
    if (*(volatile u32 *)0x1000E010 & 0x20) {
        *(volatile u32 *)0x1000E010 = 0x20;
    }
    if (!(*(volatile u32 *)0x1000C000 & 0x100)) {
        func_0011F200();
    }
    D_153154[0] = func_0011EB30(5, func_00121DF0, 0);
    func_0011F9A8(5);
    r = func_0011F230(0x80000000);
    D_153158.f8 = r;
    if (r != 0) {
        D_153140.f10 = D_153080;
        func_00121D70(0x80000000, (s32)&D_153140, 0x14, 0, 0, 0);
        return;
    }
    while (!(func_0011F230(4) & 0x20000)) {
    }
    r = func_0011F230(2);
    D_153158.f8 = r;
    func_0011F220(0x80000000, r);
    func_0011F220(0x80000001, (s32)&D_153158);
    D_153140.f10 = D_153080;
    D_153140.fC = 0;
    func_00121D70(0x80000002, (s32)&D_153140, 0x14, 0, 0, 0);
}
/* localdecomp:end func_001218B8 */

/* localdecomp:start func_00121B38 */
extern s32 func_0011F940(s32);
extern s32 func_0011EB50(s32, s32);
extern s32 D_153154[];
extern s32 D_0013DBF8[];
void func_00121B38(void) {
    func_0011F940(5);
    func_0011EB50(5, D_153154[0]);
    D_0013DBF8[0] = 0;
}
/* localdecomp:end func_00121B38 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00121B70);

/* localdecomp:start func_00121BE8 */
typedef struct { s32 a; s32 b; s32 c; } E_121BE8;
extern E_121BE8 *D_153164[];
extern E_121BE8 *D_15316C[];
void func_00121BE8(s32 i) {
    if (i < 0) {
        D_153164[0][i & 0x7FFFFFFF].a = 0;
    } else {
        D_15316C[0][i].a = 0;
    }
}
/* localdecomp:end func_00121BE8 */

/* localdecomp:start func_00121C38 */
typedef struct {
    u32 psize : 8;
    u32 dsize : 24;
    void *dest;
    s32 cid;
    u32 opt;
} Hdr_121C38;

typedef struct {
    u32 src;
    u32 dest;
    s32 size;
    s32 attr;
} Dma_121C38;

extern void *D_153160;
extern void func_00121F38(void *, s32);
extern s32 func_0011F1F0(Dma_121C38 *, s32);
extern s32 func_0011F1E0(Dma_121C38 *, s32);

s32 func_00121C38(s32 cid, s32 mode, Hdr_121C38 *pkt, s32 pktsize, s32 src, s32 dest, s32 size)
{
    Dma_121C38 dmat[2];
    s32 n;

    if ((u32)(pktsize - 16) > 0x60) {
        return 0;
    }
    n = 0;
    if (size > 0) {
        n = 1;
        dmat[0].src = (u32)src;
        dmat[0].dest = (u32)dest;
        dmat[0].size = size;
        dmat[0].attr = 0;
        pkt->dest = (void *)dest;
        pkt->dsize = size;
        if (mode & 4) {
            func_00121F38((void *)src, size);
        }
    } else {
        pkt->dsize = 0;
        pkt->dest = 0;
    }
    dmat[n].src = (u32)pkt;
    dmat[n].dest = (u32)D_153160;
    dmat[n].size = pktsize;
    pkt->cid = cid;
    pkt->psize = pktsize;
    dmat[n].attr = 0x44;
    n++;
    func_00121F38(pkt, pktsize);
    if (mode & 1) {
        return func_0011F1F0(dmat, n);
    }
    return func_0011F1E0(dmat, n);
}
/* localdecomp:end func_00121C38 */

/* localdecomp:start func_00121D70 */
extern s32 func_00121C38();
s32 func_00121D70(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 r;
    r = func_00121C38(a, 0, b, c, d, e, f);
    do {
    } while (0);
    return r;
}
/* localdecomp:end func_00121D70 */

/* localdecomp:start func_00121DB0 */
extern s32 func_00121C38();
s32 func_00121DB0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 r;
    r = func_00121C38(a, 1, b, c, d, e, f);
    do {
    } while (0);
    return r;
}
/* localdecomp:end func_00121DB0 */

ASM_FUNC("asm/boot_elf/handwritten", func_00121DF0);

ASM_FUNC("asm/boot_elf/handwritten", func_00121F38);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00121FE4);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00121FE8);

/* localdecomp:start func_00122188 */
extern void func_00121B38(void);
extern s32 D_0013DBFC[];
void func_00122188(void) {
    func_00121B38();
    D_0013DBFC[0] = 0;
}
/* localdecomp:end func_00122188 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001221B0);

/* localdecomp:start func_00122258 */
typedef struct { u8 pad[0x10]; u32 x10; s32 x14; s32 x18; } S_122258;
void func_00122258(S_122258 *p) {
    p->x18 = 0;
    p->x10 &= ~1;
}
/* localdecomp:end func_00122258 */

/* localdecomp:start func_00122278 */
typedef struct { u8 pad[0x14]; s32 x14; s32 x18; u8 pad2[8]; s32 x24; } S_122278;
s32 func_00122278(S_122278 *p) {
    s32 i = p->x24 % p->x18;
    s32 r = p->x14 + i * 64;
    p->x24 = i + 1;
    return r;
}
/* localdecomp:end func_00122278 */

/* localdecomp:start func_001222A8 */
typedef struct { u8 pad[0x1C]; u8 *x1C; s32 x20; } S_1222A8;
s32 func_001222A8(S_1222A8 *p, s32 i) {
    if (i < 0 || i >= p->x20) {
        return func_00122278((S_122278 *)p);
    }
    return (s32)(p->x1C + (i << 6));
}
/* localdecomp:end func_001222A8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001222E8);

/* localdecomp:start func_001223B8 */
typedef struct { u8 pad[0x24]; s32 x24; s32 x28; s32 x2C; } S_1223B8;
extern s32 func_00121DB0(s32, s32, s32, s32, s32, s32);
s32 func_001223B8(s32 a, s32 b, s32 c, S_1223B8 *d) {
    s32 r;
    if (func_00121DB0(0x80000008, (s32)d, 0x40, d->x24, d->x28, d->x2C) != 0) {
        r = 0;
    } else {
        r = 0x800;
    }
    return r;
}
/* localdecomp:end func_001223B8 */

/* localdecomp:start func_001223F8 */
typedef struct {
    u8 pad0[0x10];
    u32 f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
} Req_1223F8;
typedef struct {
    u8 pad0[0x14];
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
} Pkt_1223F8;
s32 func_00122278(S_122278 *p);
s32 func_001222A8(S_1222A8 *p, s32 i);
s32 func_00121DB0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern void func_00125E48_001223F8();
extern int func_001223B8();

void func_001223F8(Req_1223F8 *s, void *q)
{
    Pkt_1223F8 *p;
    int t;

    if (s->f10 & 4) {
        p = (Pkt_1223F8 *)func_001222A8(q, s->f10 >> 16);
    } else {
        p = (Pkt_1223F8 *)func_00122278(q);
    }
    t = s->f14;
    p->f1C = s->f1C;
    p->f14 = t;
    p->f20 = 0x8000000C;
    p->f24 = s->f20;
    p->f28 = s->f24;
    p->f2C = s->f28;
    if (func_00121DB0(0x80000008, (s32)p, 0x40, s->f20, s->f24, s->f28) == 0) {
        func_00125E48_001223F8(0x800, func_001223B8, p);
    }
}
/* localdecomp:end func_001223F8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_001224C8);

/* localdecomp:start func_001224D0 */
typedef struct U_1224D0 { s32 x0; u8 pad[0x34]; struct U_1224D0 *x38; } U_1224D0;
typedef struct T_1224D0 { u8 pad[8]; U_1224D0 *x8; u8 pad2[8]; struct T_1224D0 *x14; } T_1224D0;
typedef struct { u8 pad[0x28]; T_1224D0 *x28; } S_1224D0;
U_1224D0 *func_001224D0(s32 key, S_1224D0 *p) {
    T_1224D0 *t;
    U_1224D0 *u;
    for (t = p->x28; t != 0; t = t->x14) {
        for (u = t->x8; u != 0; u = u->x38) {
            if (u->x0 == key) {
                return u;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_001224D0 */

/* localdecomp:start func_00122520 */
extern s32 func_00121DB0(s32, s32, s32, s32, s32, s32);
s32 func_00122520(s32 a, s32 b, s32 c, s32 d) {
    s32 r;
    if (func_00121DB0(0x80000008, d, 0x40, 0, 0, 0) != 0) {
        r = 0;
    } else {
        r = 0x800;
    }
    return r;
}
/* localdecomp:end func_00122520 */

/* localdecomp:start func_00122560 */
/* libkernl: SIF RPC bind request handler (answers with the service found); 2.9-ee-991111 */
typedef struct { u8 pad[0x14]; s32 x14; u8 pad18[4]; s32 x1C; s32 x20; } R_122560;
typedef struct { u8 pad[0x14]; s32 x14; u8 pad18[4]; s32 x1C; s32 x20; s32 x24; s32 x28; } K_122560;

extern void func_00125E48_00122560(s32, void *, void *);
extern s32 func_00122278(S_122278 *);
extern U_1224D0 *func_001224D0(s32, S_1224D0 *);
extern s32 func_00122520(s32, s32, s32, s32);

void func_00122560(R_122560 *req, void *data) {
    K_122560 *k;
    U_1224D0 *srv;

    k = (K_122560 *)func_00122278((S_122278 *)data);
    {
        s32 b = req->x14;
        s32 a = req->x1C;
        k->x1C = a;
        k->x14 = b;
    }
    k->x20 = 0x80000009;
    srv = func_001224D0(req->x20, (S_1224D0 *)data);
    if (srv == 0) {
        k->x24 = 0;
        k->x28 = 0;
    } else {
        k->x24 = (s32)srv;
        k->x28 = *(s32 *)((u8 *)srv + 8);
    }
    if (func_00121DB0(0x80000008, (s32)k, 0x40, 0, 0, 0) == 0) {
        func_00125E48_00122560(0x800, func_00122520, k);
    }
}
/* localdecomp:end func_00122560 */

/* localdecomp:start func_00122630 */
typedef struct {
    void *pkt;
    s32 rpc_id;
    s32 sema;
    s32 xC;
    s32 x10;
    s32 buff;
    s32 gp;
    void *end_func;
    void *end_param;
    s32 server;
} Cd_122630;

typedef struct {
    u8 pad[0x14];
    void *paddr;
    s32 rpc_id;
    void *client;
    s32 rno;
} Pkt_122630;

typedef struct {
    s32 attr;
    s32 option;
    s32 init_count;
    s32 max_count;
    s32 numWaitThreads;
    void *name;
} Sema_122630;

extern u8 D_154B80[];
extern char D_00150A28[];
extern Pkt_122630 *func_001221B0_00122630(void *);
extern s32 func_0011EE20_00122630(Sema_122630 *);
extern s32 func_0011EE30(s32);
extern void func_0011EE60(s32);

s32 func_00122630(Cd_122630 *cd, s32 rno, s32 mode) {
    Pkt_122630 *pkt;
    Sema_122630 sp;

    cd->x10 = 0;
    cd->server = 0;
    pkt = func_001221B0_00122630(D_154B80);
    if (pkt == 0) {
        return -1;
    }
    cd->pkt = pkt;
    cd->rpc_id = pkt->rpc_id;
    pkt->rno = rno;
    pkt->paddr = pkt;
    pkt->client = cd;
    if (!(mode & 1)) {
        sp.option = 1;
        sp.name = D_00150A28;
        sp.init_count = 0;
        cd->sema = func_0011EE20_00122630(&sp);
        if (cd->sema < 0) {
            func_00122258((S_122258 *)pkt);
            return -3;
        }
        if (func_00121D70(0x80000009, (s32)pkt, 0x40, 0, 0, 0) == 0) {
            func_00122258((S_122258 *)pkt);
            func_0011EE30(cd->sema);
            return -2;
        }
        func_0011EE60(cd->sema);
        func_0011EE30(cd->sema);
        return 0;
    }
    cd->sema = -1;
    if (func_00121D70(0x80000009, (s32)pkt, 0x40, 0, 0, 0) == 0) {
        func_00122258((S_122258 *)pkt);
        return -2;
    }
    return 0;
}
/* localdecomp:end func_00122630 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00122780);

/* localdecomp:start func_00122810 */
typedef struct {
    void *pkt;
    s32 rpc_id;
    s32 sema;
    u8 pad[0x8];
    s32 buff;
    s32 gp;
    void *end_func;
    void *end_param;
    s32 server;
} Cd_122810;

typedef struct {
    u8 pad[0x14];
    void *paddr;
    s32 rpc_id;
    void *client;
    s32 fno;
    s32 ssize;
    s32 recv;
    s32 rsize;
    s32 rmode;
    s32 server;
} Pkt_122810;

typedef struct {
    s32 attr;
    s32 option;
    s32 init_count;
    s32 max_count;
    s32 numWaitThreads;
    void *name;
} Sema_122810;

extern u8 D_154B80[];
extern char D_00150A38[];
extern Pkt_122810 *func_001221B0(void *);
extern void func_00121F38(void *, s32);
extern s32 func_0011EE20_00122810(Sema_122810 *);
extern s32 func_0011EE30(s32);
extern void func_0011EE60(s32);

s32 func_00122810(Cd_122810 *cd, s32 fno, s32 mode, void *send, s32 ssize, void *recv, s32 rsize,
                  void *end_func, void *end_param) {
    Pkt_122810 *pkt;
    Sema_122810 sp;

    pkt = func_001221B0(D_154B80);
    if (pkt == 0) {
        return -1;
    }
    cd->end_param = end_param;
    cd->rpc_id = pkt->rpc_id;
    cd->pkt = pkt;
    cd->end_func = end_func;
    __asm__ __volatile__("move %0, $28" : "=r"(cd->gp));
    pkt->fno = fno;
    pkt->ssize = ssize;
    pkt->recv = (s32)recv;
    pkt->rsize = rsize;
    pkt->paddr = pkt;
    pkt->client = cd;
    pkt->server = cd->server;
    if (!(mode & 2)) {
        if (send == recv) {
            func_00121F38(send, ssize < rsize ? rsize : ssize);
        } else {
            if (ssize > 0) {
                func_00121F38(send, ssize);
            }
            if (rsize > 0) {
                func_00121F38(recv, rsize);
            }
        }
    }
    if (mode & 1) {
        if (end_func == 0) {
            pkt->rmode = 0;
        } else {
            pkt->rmode = 1;
        }
        cd->sema = -1;
        if (func_00121D70(0x8000000A, (s32)pkt, 0x40, (s32)send, cd->buff, ssize) != 0) {
            return 0;
        }
        func_00122258((S_122258 *)pkt);
        return -2;
    }
    sp.init_count = 0;
    sp.option = 1;
    sp.name = D_00150A38;
    cd->sema = func_0011EE20_00122810(&sp);
    if (cd->sema < 0) {
        func_00122258((S_122258 *)pkt);
        return -3;
    }
    pkt->rmode = 1;
    if (func_00121D70(0x8000000A, (s32)pkt, 0x40, (s32)send, cd->buff, ssize) == 0) {
        func_0011EE30(cd->sema);
        func_00122258((S_122258 *)pkt);
        return -2;
    }
    func_0011EE60(cd->sema);
    func_0011EE30(cd->sema);
    return 0;
}
/* localdecomp:end func_00122810 */

/* localdecomp:start func_00122A10 */
typedef struct { u8 pad[0x10]; s32 x10; u8 pad2[4]; s32 x18; } T_122A10;
typedef struct { T_122A10 *x0; s32 x4; } S_122A10;
s32 func_00122A10(S_122A10 *p) {
    T_122A10 *q = p->x0;
    if (q == 0 || p->x4 != q->x18 || !(q->x10 & 1)) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_00122A10 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00122A50);

LINKER_REMNANT("asm/boot_elf/remnants", func_00122A60);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00122A68);

LINKER_REMNANT("asm/boot_elf/remnants", func_00122AD8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00122AE0);

/* localdecomp:start func_00122B68 */
extern s32 func_0011FC78(s32);

s32 func_00122B68(void *cd, s32 fno, s32 mode, void *send, s32 ssize, void *recv, s32 rsize,
                  void *end_func, void *end_param, s32 noretry) {
    s32 i;
    s32 delay;
    s32 res;

    delay = 1;
    i = 0;
    do {
        res = func_00122810((Cd_122810 *)cd, fno, mode, send, ssize, recv, rsize, end_func, end_param) < 0;
        if (!res) {
            break;
        }
        if (noretry) {
            break;
        }
        func_0011FC78(delay * 1000);
        if (delay < 0x7F) {
            delay *= 2;
        }
        i++;
    } while (i < 0x65);
    return res;
}
/* localdecomp:end func_00122B68 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00122C58);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00122CC8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123080);

/* localdecomp:start func_001230D8 */
extern void func_00123080(void);
extern void func_0011EE60(s32);
extern s32 D_0013DC8C[];
s32 func_001230D8(void) {
    func_00123080();
    func_0011EE60(D_0013DC8C[0]);
    return 0;
}
/* localdecomp:end func_001230D8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123108);

ASM_FUNC("asm/boot_elf/handwritten", func_00123118);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123160);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123368);

/* localdecomp:start func_001233F8 */
extern s32 func_0011A264(s32, s32, s32);
extern s32 D_0013DC84[];
extern u8 D_156328[];
s32 func_001233F8(void) {
    D_0013DC84[0] = 0;
    ((void (*)(void *, s32, s32))func_0011A264)(D_156328, 0, 4);
    return 0;
}
/* localdecomp:end func_001233F8 */

/* localdecomp:start func_00123430 */
typedef struct {
    s32 sema;
    void *res;
    s32 x8;
    s32 flags;
    s32 mode;
    char name[0x400];
    s32 fd;
} OpenArg_123430;

typedef struct {
    s32 res;
    s32 flags;
} Fd_123430;

typedef struct {
    s32 attr;
    s32 option;
    s32 init_count;
    s32 max_count;
    s32 numWaitThreads;
    void *name;
} Sema_123430;

extern OpenArg_123430 D_154C00;
extern u8 D_156100[];
extern u8 D_156300[];
extern u8 D_155840[];
extern char D_00150AF0[];
extern s32 D_0013DC90;
extern s32 func_001230D8(void);
extern void func_00123160(void);
extern s32 func_00123368(void);
extern void func_00123108(void);
extern Fd_123430 *func_00122AE0(void);
extern s32 func_0011EE20_00123430(Sema_123430 *);
extern s32 func_0011EE30(s32);
extern s32 func_0011EE40(s32);
extern s32 func_0011EE60_00123430(s32);
extern s32 func_00122B68(void *, s32, s32, void *, s32, void *, s32, void *, void *, s32);

s32 func_00123430(const char *name, s32 flags, ...) {
    char *ap;
    OpenArg_123430 *arg;
    Fd_123430 *fd;
    s32 idx;
    s32 i;
    s32 s;
    s32 ok;
    s32 mode;
    Sema_123430 sp;
    s32 res[4];

    arg = &D_154C00;
    ((s32 (*)(s32))func_001230D8)(0);
    if (D_0013DC84[0] == 0) {
        func_00123160();
    }
    if (func_00123368() != 0) {
        func_00123108();
        return 0xFFFEFFFC;
    }
    fd = func_00122AE0();
    if (fd == 0) {
        func_00123108();
        return -0x13;
    }
    ap = (char *)__builtin_next_arg(flags)
         - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    mode = *(s32 *)ap;
    i = 0;
    if ((arg->name[0] = name[0]) != 0) {
        while (++i < 0x400) {
            if ((arg->name[i] = name[i]) == 0) break;
        }
    }
    if (i == 0x400) {
        arg->name[0x3FF] = 0;
    }
    idx = ((u8 *)fd - D_156100) >> 4;
    arg->flags = flags & 0x7FFFFFFF;
    arg->mode = mode;
    sp.option = 1;
    sp.name = D_00150AF0;
    arg->fd = idx;
    sp.init_count = 0;
    s = func_0011EE20_00123430(&sp);
    arg->res = res;
    arg->sema = s;
    arg->x8 = 4;
    if (func_00122B68(D_156300, 0, 0, &D_154C00, 0x418, D_155840, 4, 0, 0, 0) < 0) {
        func_0011EE30(s);
        func_00123108();
        return -0xB;
    }
    ok = *(s32 *)((u32)D_155840 | 0x20000000);
    func_00123108();
    if (ok == 0) {
        func_0011EE30(s);
        return -0xB;
    }
    func_0011EE60_00123430(s);
    func_0011EE30(s);
    if (res[0] < 0) {
        func_0011EE60_00123430(D_0013DC90);
        fd->flags = 0;
        func_0011EE40(D_0013DC90);
        return res[0];
    }
    ok = idx;
    func_0011EE60_00123430(D_0013DC90);
    fd->res = res[0];
    fd->flags |= flags;
    func_0011EE40(D_0013DC90);
    return ok;
}
/* localdecomp:end func_00123430 */

/* localdecomp:start func_001236C0 */
/* libkernl: file I/O RPC close; 2.9-ee-991111. func_001230D8 takes an argument here, the file declares it (void). */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } F_1236C0;
typedef struct { s32 x0; void *x4; s32 x8; s32 xC; s32 x10; } P_1236C0;
typedef struct { s32 count; s32 max; s32 init; s32 wait; u32 attr; void *option; } Q_1236C0;

extern F_1236C0 *func_00122C58(s32);
extern s32 func_001230D8_001236C0(s32);
extern void func_00123108(void);
extern s32 func_0011EE20_001236C0(Q_1236C0 *);
extern s32 func_0011EE30(s32);
extern s32 func_00122B68();
extern F_1236C0 D_156100_001236C0[];
extern P_1236C0 D_154C00_001236C0;
extern u8 D_156300[];
extern s32 D_155840_001236C0[];
extern char D_00150B08[];

s32 func_001236C0(s32 fd) {
    F_1236C0 *f;
    Q_1236C0 q;
    s32 res;
    s32 s;
    s32 r;
    P_1236C0 *p = &D_154C00_001236C0;

    f = func_00122C58(fd);
    func_001230D8_001236C0(1);
    if (D_0013DC84[0] == 0 || f == 0 || f->x4 == 0) {
        func_00123108();
        return -9;
    }
    p->xC = f->x0;
    p->x10 = f - D_156100_001236C0;
    q.max = 1;
    q.init = 0;
    q.option = D_00150B08;
    s = func_0011EE20_001236C0(&q);
    p->x0 = s;
    p->x4 = &res;
    p->x8 = 4;
    if (func_00122B68(D_156300, 1, 0, p, 0x14, D_155840_001236C0, 4, 0, 0, 0) < 0) {
        func_0011EE30(s);
        func_00123108();
        return -11;
    }
    f->x4 = 0;
    r = *(s32 *)((u32)D_155840_001236C0 | 0x20000000);
    func_00123108();
    if (r == 0) {
        func_0011EE30(s);
        return -11;
    }
    func_0011EE60(s);
    func_0011EE30(s);
    if (res < 0) {
        return res;
    }
    return 0;
}
/* localdecomp:end func_001236C0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00123838);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123840);

LINKER_REMNANT("asm/boot_elf/remnants", func_00123AB0);

LINKER_REMNANT("asm/boot_elf/remnants", func_00123B08);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123B10);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123B98);

LINKER_REMNANT("asm/boot_elf/remnants", func_00123C18);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123C20);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123C90);

LINKER_REMNANT("asm/boot_elf/remnants", func_00123D00);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123D08);

/* localdecomp:start func_00123D10 */
typedef struct {
    u8 b[4];
} B4_123D10;

extern s32 D_0013DCA0[];
extern u8 D_1567C0[];
extern u8 D_1567E8[];
extern u8 D_1565C0_123D10[];
extern s32 func_00122630(void *, u32, s32);
extern s32 func_00122810();

s32 func_00123D10(void)
{
    s32 i;

    if (D_0013DCA0[0] < 0) {
        for (;;) {
            if (func_00122630(D_1567C0, 0x80000006, 0) < 0) {
                return -1;
            }
            if (*(s32 *)(D_1567C0 + 0x24) != 0) {
                D_0013DCA0[0] = 0;
                if (func_00122810(D_1567C0, 0xFF, 0, 0, 0, D_1565C0_123D10, 4, 0, 0) < 0) {
                    return 0xFFFEFFFF;
                }
                *(B4_123D10 *)D_1567E8 = *(B4_123D10 *)D_1565C0_123D10;
                return 0;
            }
            i = 0x100000;
            while (--i != -1) {
            }
        }
    }
    return 0;
}
/* localdecomp:end func_00123D10 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00123E10);

/* localdecomp:start func_00123EA0 */
extern s32 func_0011A264(s32, s32, s32);
extern s32 D_0013DCA0[];
extern u8 D_1567E8[];
s32 func_00123EA0(void) {
    D_0013DCA0[0] = -1;
    ((void (*)(void *, s32, s32))func_0011A264)(D_1567E8, 0, 4);
    return 0;
}
/* localdecomp:end func_00123EA0 */

/* localdecomp:start func_00123ED8 */
typedef struct {
    s32 f0;
    s32 f4;
    char path[0xFC];
    char args[0xFC];
} L_123ED8;

typedef struct {
    char b[0xFC];
} A_123ED8;

extern L_123ED8 D_1565C0;
extern u8 D_1567C0[];
extern s32 func_00123D10();
extern s32 func_00123E10();
extern s32 func_00122810();
extern void func_0011A0B0(void *, void *, s32);

s32 func_00123ED8(s32 id, s32 len, s32 args, s32 *res)
{
    if (func_00123D10() < 0) {
        return 0xFFFF0000;
    }
    if (func_00123E10() != 0) {
        return 0xFFFEFFFC;
    }
    D_1565C0.f0 = id;
    if (args != 0) {
        if (len > 0xFC) {
            *(A_123ED8 *)D_1565C0.args = *(A_123ED8 *)args;
            D_1565C0.f4 = 0xFC;
        } else {
            func_0011A0B0(D_1565C0.args, (void *)args, len);
            D_1565C0.f4 = len;
        }
    } else {
        D_1565C0.f4 = 0;
    }
    if (func_00122810(D_1567C0, 6, 0, &D_1565C0, 0x200, &D_1565C0, 8, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    {
        s32 r = D_1565C0.f0;
        *res = D_1565C0.f4;
        return r;
    }
}
/* localdecomp:end func_00123ED8 */

/* localdecomp:start func_001240E0 */
extern s32 func_00123ED8(s32, s32, s32, s32 *);
s32 func_001240E0(s32 a, s32 b, s32 c) {
    s32 buf[4];
    return func_00123ED8(a, b, c, buf);
}
/* localdecomp:end func_001240E0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00124100);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124130);

/* localdecomp:start func_00124138 */
/* libkernl: IOP reset request (sceSifResetIop-style packet over SIF DMA); 2.9-ee-991111 */
typedef struct {
    u32 psize : 8;
    u32 dsize : 24;
    u32 dest;
    s32 cid;
    u32 opt;
    s32 arglen;
    s32 mode;
    char arg[0x50];
} __attribute__((aligned(16))) R_124138;

typedef struct {
    void *src;
    u32 dest;
    s32 size;
    s32 attr;
} M_124138;

extern void func_00125F70(s32, s32);
extern void func_0011F0F0(void);
extern u32 func_0011F230(s32);
extern void func_0011F220_00124138(s32, s32);
extern s32 func_0011F1E0_00124138(M_124138 *, s32);
extern void func_00121F38();
extern R_124138 D_156800;

s32 func_00124138(const char *arg, s32 mode) {
    M_124138 dmat;
    u32 dest;
    s32 i;

    func_00125F70(0, 0);
    func_00125F70(1, 0);
    func_0011F0F0();
    dest = func_0011F230(0x80000000);
    D_156800.mode = mode;
    for (i = 0; arg[i] != 0; i++) {
        D_156800.arg[i] = arg[i];
    }
    D_156800.dest = 0;
    D_156800.arglen = i;
    D_156800.cid = 0x80000003;
    D_156800.dsize = 0;
    D_156800.psize = 0x68;
    dmat.src = &D_156800;
    dmat.dest = dest;
    dmat.size = 0x68;
    dmat.attr = 0x44;
    func_00121F38(&D_156800, 0x68);
    func_0011F220_00124138(4, 0x40000);
    if (func_0011F1E0_00124138(&dmat, 1) != 0) {
        func_0011F220_00124138(4, 0x10000);
        func_0011F220_00124138(4, 0x20000);
        func_0011F220_00124138(0x80000002, 0);
        func_0011F220_00124138(0x80000000, 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00124138 */

/* localdecomp:start func_00124290 */
extern u32 func_0011F230(s32);
s32 func_00124290(void) {
    u32 r = func_0011F230(4) & 0x10000;
    return r != 0;
}
/* localdecomp:end func_00124290 */

/* localdecomp:start func_001242B8 */
extern u32 func_0011F230(s32);
extern void func_0011F2A0(void);
extern void func_00125F70(s32, s32);
s32 func_001242B8(void) {
    if (func_0011F230(4) & 0x40000) {
        func_0011F2A0();
        func_00125F70(1, 1);
        func_00125F70(0, 1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_001242B8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124308);

LINKER_REMNANT("asm/boot_elf/remnants", func_00124418);

ASM_FUNC("asm/boot_elf/handwritten", func_00124420);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00124430);

ASM_FUNC("asm/boot_elf/handwritten", func_00124468);

ASM_FUNC("asm/boot_elf/handwritten", func_00124478);

/* localdecomp:start func_00124488 */
typedef struct {
    s32 a;
    s32 b;
} Pair_124488;

extern Pair_124488 D_0013E028[8];
extern s32 D_0013E020;
extern u8 D_0013DCA8[];
extern s32 func_00124468(s32);
extern void func_00124478(s32, s32);
extern void func_00124420(u32, void *, s32);
extern void func_0011F0A0(s32);

void func_00124488(void) {
    u32 i;

    func_00124478(D_0013E028[0].a, D_0013E028[0].b);
    func_00124420(0x80075000, D_0013DCA8, 0x330);
    func_0011F0A0(0);
    func_0011F0A0(2);
    func_00124478(D_0013E028[1].a, D_0013E028[1].b);
    func_00124478(D_0013E028[2].a, D_0013E028[2].b);
    for (i = 3; i < 8; i++) {
        func_00124478(D_0013E028[i].a, func_00124468(D_0013E028[i].a));
    }
    D_0013E020 = func_00124468(3);
}
/* localdecomp:end func_00124488 */

ASM_FUNC("asm/boot_elf/handwritten", func_00124550);

/* localdecomp:start func_00124560 */
extern s32 func_0011F280(void);
extern void func_001245A0(void);
extern void func_0011F290(void);
void func_00124560(void) {
    if (func_0011F280() == 0x2000000) {
        func_001245A0();
    } else {
        func_0011F290();
    }
}
/* localdecomp:end func_00124560 */
