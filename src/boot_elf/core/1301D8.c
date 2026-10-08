#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001301D8);

/* localdecomp:start func_00130210 */
typedef struct {
    u8 pad0[0x184];
    int f184;
    int f188;
} S_130210;

void func_00130210(S_130210 *s, int *dmv, int *dmvector, int mvx, int mvy)
{
    if (s->f184 == 3) {
        if (s->f188) {
            dmv[0] = ((mvx + (mvx > 0)) >> 1) + dmvector[0];
            dmv[1] = ((mvy + (mvy > 0)) >> 1) + dmvector[1] - 1;
            dmv[2] = ((3 * mvx + (mvx > 0)) >> 1) + dmvector[0];
            dmv[3] = ((3 * mvy + (mvy > 0)) >> 1) + dmvector[1] + 1;
        } else {
            dmv[0] = ((3 * mvx + (mvx > 0)) >> 1) + dmvector[0];
            dmv[1] = ((3 * mvy + (mvy > 0)) >> 1) + dmvector[1] - 1;
            dmv[2] = ((mvx + (mvx > 0)) >> 1) + dmvector[0];
            dmv[3] = ((mvy + (mvy > 0)) >> 1) + dmvector[1] + 1;
        }
    } else {
        dmv[0] = ((mvx + (mvx > 0)) >> 1) + dmvector[0];
        dmv[1] = ((mvy + (mvy > 0)) >> 1) + dmvector[1];
        if (s->f184 == 1) {
            dmv[1]--;
        } else {
            dmv[1]++;
        }
    }
}
/* localdecomp:end func_00130210 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00130398);

/* localdecomp:start func_00130AA0 */
typedef struct {
    int f0;
    u8 pad4[0x10 - 4];
    int f10;
} Pic_130AA0;
typedef struct {
    int f0;
    int pad4;
    int f8;
    int fC;
    int f10;
    u8 pad14[0x140 - 0x14];
} Blk_130AA0;
typedef struct {
    u8 pad0[0x12C];
    int f12C;
    u8 pad130[0x13C - 0x130];
    int f13C;
    u8 pad140[0x184 - 0x140];
    int f184;
    u8 pad188[0x1D0 - 0x188];
    Pic_130AA0 *f1D0;
    u8 pad1D4[0x1E0 - 0x1D4];
    Pic_130AA0 *f1E0;
    u8 pad1E4[0x1F0 - 0x1E4];
    Pic_130AA0 *f1F0;
    u8 pad1F4[0x6C8 - 0x1F4];
    Blk_130AA0 blk[1];
    u8 pad808[0x820 - 0x808];
    int f820;
} S_130AA0;
extern char D_00151CF0[];
void func_0013A150(void *s, char *fmt, int x);
void func_00130398(S_130AA0 *s, int x, int y, int flags, int mode, int *mv, int *fs, int a7);
void func_00132D48();

int func_00130AA0(S_130AA0 *s, int addr, int type, int flags, int mode, int *mv, int *fs, int a7)
{
    int intra;
    int mbx;
    int mby;
    Pic_130AA0 *p;
    int px;
    int py;

    intra = flags & 1;
    mby = addr / s->f13C;
    mbx = addr % s->f13C;
    px = mbx << 4;
    py = mby << 4;
    if (intra) {
        while ((*(volatile u32 *)0x1000D400 >> 8) & 1) {
        }
        s->blk[s->f820].f10 = 0;
    } else {
        if ((u32)(mode - 1) >= 3) {
            func_0013A150(s, D_00151CF0, mode);
            s->f12C = 1;
            return 0;
        }
        func_00130398(s, px, py, flags, mode, mv, fs, a7);
        while ((*(volatile u32 *)0x1000D400 >> 8) & 1) {
        }
        func_00132D48(s);
        s->blk[s->f820].f10 = 1;
    }
    if (type == 1 && (flags & 2)) {
        s->blk[s->f820].fC = type;
    } else {
        s->blk[s->f820].fC = 0;
    }
    s->blk[s->f820].f8 = intra;
    if (s->f184 == 3) {
        s->blk[s->f820].f0 = s->f1D0->f0 + (mbx * s->f1D0->f10 + mby) * 0x180;
    } else {
        if (s->f184 == 2) {
            p = s->f1F0;
        } else {
            p = s->f1E0;
        }
        s->blk[s->f820].f0 = p->f0 + (mbx * p->f10 + mby) * 0x180;
    }
    return 1;
}
/* localdecomp:end func_00130AA0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00130CF0);

/* localdecomp:start func_00131178 */
/* libmpeg: run the two callbacks of each entry of buffer n, then hand it on; 2.9-ee-991111 */
typedef struct {
    s32 x00;                        /* 0x5A0 */
    s32 x04;                        /* 0x5A4 */
    u8 pad08[0x28 - 0x08];
    void (*cbA[4])(void *);         /* 0x5C8 */
    void (*cbB[4])(void *);         /* 0x5D8 */
    u8 a[4][0x1C];                  /* 0x5E8 */
    u8 b[4][0x1C];                  /* 0x658 */
    s32 x128;                       /* 0x6C8 */
    s32 x12C;                       /* 0x6CC */
    s32 x130;                       /* 0x6D0 */
    s32 x134;                       /* 0x6D4 */
    s32 x138;                       /* 0x6D8 */
    s32 x13C;                       /* 0x6DC */
} E_131178;

typedef struct {
    u8 pad0[0x5A0];
    E_131178 e[2];                  /* 0x5A0 */
    u8 pad820[0x830 - 0x820];
    s32 x830;                       /* 0x830 */
} S_131178;

extern void func_00132C88();
extern s32 func_0013A0F8();
extern char D_00151D18[];
extern void func_00132B98();

void func_00131178(S_131178 *p, s32 n) {
    s32 i;

    if (p->e[n].x138 != 0) {
        for (i = 0; i < p->e[n].x12C; i++) {
            p->e[n].cbA[i](p->e[n].a[i]);
            p->e[n].cbB[i](p->e[n].b[i]);
        }
    }
    if (p->e[n].x130 != 0 && p->e[n].x13C != 0) {
        func_0013A0F8(p, D_00151D18);
    }
    if (p->e[n].x130 != 0) {
        func_00132C88(p->e[n].x128, p->e[n].x04);
    } else if (p->e[n].x13C != 0) {
        func_00132C88(p->e[n].x128, p->x830);
    } else {
        func_00132B98(p->e[n].x128, p->x830, p->e[n].x04);
    }
}
/* localdecomp:end func_00131178 */

/* localdecomp:start func_00131398 */
typedef struct {
    u8 pad0[0x13C];
    int f13C;
    int f140;
    u8 pad144[0x184 - 0x144];
    int f184;
    u8 pad188[0x820 - 0x188];
    int f820;
    int f824;
    u8 pad828[0x848 - 0x828];
    int f848;
    int f84C;
    u8 pad850[0x868 - 0x850];
    int f868;
    u8 pad86C[0x878 - 0x86C];
    int f878;
} S_131398;
extern char D_00151D30[];
int func_001315D8_00131398(void *s, int n);
void func_00132A98_00131398(void *s);
int func_00135DC8(int x);
void func_00139F90(void);
void func_0013A030(void *s);
void func_00131178_00131398(void *s, int first);
extern s32 func_0013A0F8();

static inline int sync_131398(S_131398 *s)
{
    int ok;
    u32 bp;
    long top;
    u32 t;
    int k;

    ok = 1;
    func_00132A98_00131398(s);
    func_00132A98_00131398(s);
    while (*(volatile u32 *)0x1000B020 != 0 && !(*(volatile u32 *)0x10002010 & 0x4000)) {
        if (*(volatile u32 *)0x1000B420 == 0 && !(*(volatile u32 *)0x1000B400 & 0x100)) {
            func_00135DC8(s->f868);
        }
        if (s->f878) {
            func_00139F90();
            return 0;
        }
    }
    bp = *(volatile u32 *)0x10002020;
    top = *(volatile long *)0x10002030;
    s->f848 = top;
    if (top < 0) {
        t = bp & 0x1F;
        if (t) {
            k = 0x20 - t;
        } else {
            k = 0;
        }
    } else {
        k = 0x20;
    }
    s->f84C = k;
    if (*(volatile u32 *)0x10002010 & 0x4000) {
        func_0013A030(s);
        ok = 0;
    }
    return ok;
}

int func_00131398(S_131398 *s)
{
    int n;
    int r;

    s->f820 = 0;
    s->f824 = 0;
    n = s->f13C * s->f140;
    if (s->f184 != 3) {
        n >>= 1;
    }
    do {
        r = func_001315D8_00131398(s, n);
    } while (r == 1 || r == 3);
    if (!sync_131398(s)) {
        if (s->f878) {
            return 4;
        }
        r = 2;
    }
    while ((*(volatile u32 *)0x1000D400 >> 8) & 1) {
    }
    if (r == 0) {
        func_00131178_00131398(s, s->f820 == 0);
    }
    if ((u32)(r - 1) < 2) {
        func_0013A0F8(s, D_00151D30);
    }
    return r == 0;
}
/* localdecomp:end func_00131398 */

/* localdecomp:start func_001315D8 */
/* libmpeg: decode loop over the pictures of a buffer (IPU/DMA polling); 2.9-ee-991111 */
typedef struct {
    u8 pad0[0x12C];
    s32 x12C;           /* 0x12C */
    u8 pad130[0x6DC - 0x130];
    s32 x6DC;           /* 0x6DC: first of an array of 0x140-byte entries */
    u8 pad6E0[0x820 - 0x6E0];
    s32 x820;           /* 0x820 */
    u8 pad824[0x848 - 0x824];
    s32 x848;           /* 0x848 */
    s32 x84C;           /* 0x84C */
    u8 pad850[0x868 - 0x850];
    s32 x868;           /* 0x868 */
    u8 pad86C[0x878 - 0x86C];
    s32 x878;           /* 0x878 */
} S_1315D8;

extern s32 func_00133C58();
extern void func_00132A98();
extern void func_00135DC8_001315D8();
extern void func_00139F90();
extern void func_0013A030();
extern s32 func_00132970();
extern s32 func_00132428();
extern s32 func_00131ED0();
extern s32 func_00132AD8();
extern s32 func_00130AA0();
extern void func_00131178();
extern s32 func_0013A0F8();
extern char D_00151D50[];

s32 func_001315D8(S_1315D8 *p, s32 n) {
    s32 buf[8];
    s32 buf20[4];
    s32 buf30[4];
    s32 i, k;
    s32 a48, a4C, a50;
    s32 r;

    i = 0;
    k = 0;
    r = func_00133C58(p, n, &i, &k, buf);
    if (r != 0) {
        return r;
    }
    p->x12C = 0;
    for (;;) {
        s32 ok;
        if (!(i < n)) {
            return 0;
        }
        *(s32 *)((u8 *)p + p->x820 * 0x140 + 0x6DC) = 0;
        ok = 1;
        func_00132A98(p);
        while (*(volatile s32 *)0x1000B020 != 0 && !(*(volatile s32 *)0x10002010 & 0x4000)) {
            if (*(volatile s32 *)0x1000B420 == 0 && !(*(volatile s32 *)0x1000B400 & 0x100)) {
                func_00135DC8_001315D8(p->x868);
            }
            if (p->x878 != 0) {
                func_00139F90();
                r = 0;
                goto done;
            }
        }
        {
            s32 bp = *(volatile s32 *)0x10002020;
            long top = *(volatile long *)0x10002030;
            s32 v;
            p->x848 = top;
            if (top < 0) {
                s32 b = bp & 0x1F;
                if (b != 0) {
                    v = 0x20 - b;
                } else {
                    v = 0;
                }
            } else {
                v = 0x20;
            }
            p->x84C = v;
        }
        if (*(volatile s32 *)0x10002010 & 0x4000) {
            func_0013A030(p);
            ok = 0;
        }
        r = ok;
    done:
        if (r == 0) {
            return p->x878 == 0 ? 2 : 4;
        }
        if (k == 0) {
            if (func_00132970(p, 0x17) == 0 || p->x12C != 0) {
                p->x12C = 0;
                return 3;
            }
            k = func_00132428(p);
            if (p->x12C != 0) {
                p->x12C = 0;
                return 1;
            }
        }
        if (!(i < n)) {
            func_0013A0F8(p, D_00151D50);
            return 2;
        }
        if (k == 1) {
            if (func_00131ED0(p, &a48, &a4C, &a50, buf, buf20, buf30) == 0) {
                p->x12C = 0;
                return 1;
            }
        } else {
            if (func_00132AD8(p, buf, &a4C, buf20, &a48) == 0) {
                p->x12C = 0;
                return 2;
            }
        }
        if (func_00130AA0(p, i, k, a48, a4C, buf, buf20, buf30) == 0) {
            p->x12C = 0;
            return 2;
        }
        if (i != 0) {
            func_00131178(p, p->x820 ^ 1);
        }
        i++;
        p->x820 ^= 1;
        k--;
    }
}
/* localdecomp:end func_001315D8 */

/* localdecomp:start func_00131908 */
typedef struct {
    u8 pad0[0x12C];
    s32 x12C;
    u8 pad1[0x828 - 0x130];
    s32 x828;
    u32 x82C;
    u8 pad2[0x848 - 0x830];
    s32 x848;
    s32 x84C;
} S_131908;

extern void func_00132A98_00131908(S_131908 *);
extern u64 func_00132708_00131908(S_131908 *);
extern s32 func_00132888_00131908(S_131908 *, s32);

#define IPU_CMD_131908 ((volatile u32 *)0x10002000)
#define IPU_BP_131908  ((volatile u32 *)0x10002020)
#define IPU_TOP_131908 ((volatile s64 *)0x10002030)

static __inline__ void cmd_131908(S_131908 *p, u32 cmd) {
    *IPU_CMD_131908 = cmd;
    p->x82C = cmd & 0xF0000000;
    if (p->x82C == 0x20000000 || p->x82C == 0x30000000 || p->x82C == 0x40000000) {
        p->x828 = 0;
    } else {
        p->x828 = 1;
    }
}

static __inline__ s16 vdec_131908(S_131908 *p, u32 cmd) {
    u64 r;
    u32 bp;
    s64 top;
    cmd_131908(p, cmd);
    r = func_00132708_00131908(p);
    bp = *IPU_BP_131908;
    top = *IPU_TOP_131908;
    p->x848 = top;
    if (top < 0) {
        p->x84C = -(bp & 0x1F) & 0x1F;
    } else {
        p->x84C = 32;
    }
    p->x12C = (s32)r == 0;
    return r;
}

static __inline__ s16 vdecw_131908(S_131908 *p, s32 tbl) {
    return vdec_131908(p, 0x30000000 | (tbl << 26));
}

static __inline__ void dmv_131908(s32 *pred, s32 r_size, s32 motion_code, s32 motion_residual, s32 full_pel_vector) {
    s32 lim, vec;
    lim = 16 << r_size;
    vec = full_pel_vector ? (*pred >> 1) : (*pred);
    if (motion_code > 0) {
        vec += ((motion_code - 1) << r_size) + motion_residual + 1;
        if (vec >= lim) vec -= lim + lim;
    } else if (motion_code < 0) {
        vec -= ((-motion_code - 1) << r_size) + motion_residual + 1;
        if (vec < -lim) vec += lim + lim;
    }
    *pred = full_pel_vector ? (vec << 1) : vec;
}

void func_00131908(S_131908 *p, s32 *PMV, s32 *dmvector, s32 h_r_size, s32 v_r_size, s32 dmv, s32 mvscale, s32 full_pel_vector) {
    s32 motion_code, motion_residual;

    func_00132A98_00131908(p);
    motion_code = vdecw_131908(p, 2);
    motion_residual = (h_r_size != 0 && motion_code != 0) ? func_00132888_00131908(p, h_r_size) : 0;
    dmv_131908(&PMV[0], h_r_size, motion_code, motion_residual, full_pel_vector);
    if (dmv) {
        func_00132A98_00131908(p);
        dmvector[0] = vdecw_131908(p, 3);
    }
    func_00132A98_00131908(p);
    motion_code = vdecw_131908(p, 2);
    motion_residual = (v_r_size != 0 && motion_code != 0) ? func_00132888_00131908(p, v_r_size) : 0;
    if (mvscale) PMV[1] >>= 1;
    dmv_131908(&PMV[1], v_r_size, motion_code, motion_residual, full_pel_vector);
    if (mvscale) PMV[1] <<= 1;
    if (dmv) {
        func_00132A98_00131908(p);
        dmvector[1] = vdecw_131908(p, 3);
    }
}
/* localdecomp:end func_00131908 */

/* localdecomp:start func_00131D30 */
typedef struct {
    s32 x;
    s32 y;
} Mv_131D30;

extern s32 func_00132888_00131D30();
extern void func_00131908();

void func_00131D30(void *p, Mv_131D30 *mv, s32 a6, s32 *a5, s32 idx, s32 fwd, s32 bwd, s32 rx, s32 ry, s32 isB, s32 dual)
{
    if (fwd == 1) {
        if (bwd == 0 && isB == 0) {
            s32 v = func_00132888_00131D30(p, 1);
            a5[idx] = v;
            a5[idx + 2] = v;
        }
        func_00131908(p, &mv[idx], a6, rx, ry, isB, dual, 0);
        mv[idx + 2].x = mv[idx].x;
        mv[idx + 2].y = mv[idx].y;
    } else {
        a5[idx] = func_00132888_00131D30(p, 1);
        func_00131908(p, &mv[idx], a6, rx, ry, isB, dual, 0);
        a5[idx + 2] = func_00132888_00131D30(p, 1);
        func_00131908(p, &mv[idx + 2], a6, rx, ry, isB, dual, 0);
    }
}
/* localdecomp:end func_00131D30 */

/* localdecomp:start func_00131ED0 */
typedef struct {
    s32 f0;
    u8 pad4[0x138 - 4];
    s32 f138;
    u8 pad13C[0x140 - 0x13C];
} Blk_131ED0;

typedef struct {
    u8 pad0[0x12C];
    s32 f12C;
    u8 pad130[0x160 - 0x130];
    s32 f160;
    s32 f164;
    s32 f168;
    s32 f16C;
    s32 f170;
    s32 f174;
    s32 f178;
    s32 f17C;
    s32 f180;
    s32 f184;
    s32 f188;
    s32 f18C;
    s32 f190;
    u8 pad194[0x1C0 - 0x194];
    s32 f1C0;
    s32 f1C4;
    u8 pad1C8[0x5A4 - 0x1C8];
    Blk_131ED0 blk[1];
    u8 pad6E4[0x820 - 0x6E4];
    s32 f820;
    s32 f824;
    s32 f828;
    s32 f82C;
    u8 pad830[0x848 - 0x830];
    s32 f848;
    s32 f84C;
    u8 pad850[0x858 - 0x850];
    s32 f858;
} S_131ED0;

extern void func_00132A98();
extern long func_00132708();
extern s32 func_0013A0F8();
extern s32 func_00132888_00131ED0();
extern void func_00131D30();
extern void func_00131908();
extern void func_00132AD0();
extern void func_00133BB8();
extern char D_00151DA0[];

static __inline__ void ipucmd_131ED0(S_131ED0 *p, u32 cmd)
{
    u32 m;

    *(volatile u32 *)0x10002000 = cmd;
    m = cmd & 0xF0000000;
    p->f82C = m;
    if (m == 0x20000000 || m == 0x30000000 || m == 0x40000000) {
        p->f828 = 0;
    } else {
        p->f828 = 1;
    }
}

s32 func_00131ED0(S_131ED0 *p, s32 *flags, s32 *type, s32 *a3, s32 *mv, s32 *a5, s32 a6)
{
    long r;
    u32 bp;
    long top;
    s32 s;
    s32 fwd;
    s32 bwd;
    s32 isB;
    s32 dual;
    s32 v;

    *(volatile u32 *)0x10002010 = (*(volatile u32 *)0x10002010 & 0xF8FFFFFF) | (p->f160 << 24);
    func_00132A98(p);
    ipucmd_131ED0(p, 0x34000000);
    r = func_00132708(p);
    bp = *(volatile u32 *)0x10002020;
    top = *(volatile long *)0x10002030;
    p->f848 = top;
    if (top < 0) {
        p->f84C = -(bp & 0x1F) & 0x1F;
    } else {
        p->f84C = 0x20;
    }
    p->f12C = (s32)r == 0;
    s = (s16)r;
    *flags = s;
    if (s == 0) {
        func_0013A0F8(p, D_00151DA0);
        p->f12C = 1;
        return 0;
    }
    if (s & 0xC) {
        if (p->f184 == 3 && p->f18C != 0) {
            *type = 2;
        } else {
            *type = func_00132888_00131ED0(p, 2);
        }
    } else if (s & 1) {
        if (p->f190 != 0) {
            *type = (p->f184 == 3) ? 2 : 1;
        }
    }
    if (p->f184 == 3) {
        fwd = (*type == 1) ? 2 : 1;
        bwd = (*type == 2);
    } else {
        fwd = (*type == 2) ? 2 : 1;
        bwd = 0;
    }
    isB = (*type == 3);
    dual = 0;
    if (!bwd) {
        dual = (p->f184 == 3);
    }
    *a3 = (p->f184 == 3 && p->f18C == 0 && (*flags & 3)) ? func_00132888_00131ED0(p, 1) : 0;
    if (*flags & 0x10) {
        p->f1C4 = func_00132888_00131ED0(p, 5);
    }
    if ((*flags & 8) || ((*flags & 1) && p->f190 != 0)) {
        if (p->f858 != 0) {
            func_00131D30(p, mv, a6, a5, 0, fwd, bwd, p->f174 - 1, p->f178 - 1, isB, dual);
        } else {
            func_00131908(p, mv, a6, p->f168 - 1, p->f168 - 1, 0, 0, p->f164);
        }
    }
    if (p->f12C != 0) {
        return 0;
    }
    if (*flags & 4) {
        if (p->f858 != 0) {
            func_00131D30(p, mv, a6, a5, 1, fwd, bwd, p->f17C - 1, p->f180 - 1, 0, dual);
        } else {
            func_00131908(p, mv + 2, a6, p->f170 - 1, p->f170 - 1, 0, 0, p->f16C);
        }
    }
    if (p->f12C != 0) {
        return 0;
    }
    if ((*flags & 1) && p->f190 != 0) {
        func_00132AD0(p, 1);
    }
    if (*flags & 3) {
        func_00133BB8(p->blk[p->f820].f0, 0x300);
        func_00132A98(p);
        ipucmd_131ED0(p, ((*flags & 1) << 27) | (((*a3 << 25) | (p->f1C0 << 26)) | ((p->f1C4 << 16) | 0x20000000)));
    } else {
        p->blk[p->f820].f138 = 1;
    }
    p->f1C0 = 0;
    if (p->f12C != 0) {
        return 0;
    }
    if (!(*flags & 1)) {
        p->f1C0 = 1;
    }
    if ((*flags & 1) && p->f190 == 0) {
        mv[5] = 0;
        mv[4] = 0;
        mv[1] = 0;
        mv[0] = 0;
        mv[7] = 0;
        mv[6] = 0;
        mv[3] = 0;
        mv[2] = 0;
    }
    if (p->f160 == 2 && !(*flags & 9)) {
        mv[5] = 0;
        mv[4] = 0;
        mv[1] = 0;
        mv[0] = 0;
        if (p->f184 == 3) {
            *type = 2;
        } else {
            *type = 1;
            *a5 = (p->f184 == 2);
        }
    }
    return 1;
}
/* localdecomp:end func_00131ED0 */

/* localdecomp:start func_00132428 */
/* libmpeg: macroblock_address_increment through IPU VDEC; 2.9-ee-991111 */
typedef struct {
    u8 pad0[0x12C];
    s32 x12C;           /* 0x12C */
    u8 pad130[0x828 - 0x130];
    s32 x828;           /* 0x828 */
    s32 x82C;           /* 0x82C */
    u8 pad830[0x848 - 0x830];
    s32 x848;           /* 0x848 */
    s32 x84C;           /* 0x84C */
    u8 pad850[0x858 - 0x850];
    s32 x858;           /* 0x858 */
} S_132428;

extern void func_00132A98_00132428(S_132428 *);
extern long func_00132708_00132428(S_132428 *);
extern s32 func_00132970(S_132428 *, s32);
extern void func_00132AD0(S_132428 *, s32);
extern void func_0013A150_00132428(S_132428 *, char *, s32);
extern char D_00151DC0[];

s32 func_00132428(S_132428 *p) {
    s32 total = 0;
    s32 again;

    do {
        long r;
        u32 code;
        s32 c;
        func_00132A98_00132428(p);
        {
            u32 cmd = 0x30000000;
            *(volatile u32 *)0x10002000 = cmd;
            p->x82C = cmd;
            p->x828 = 0;
        }
        r = func_00132708_00132428(p);
        {
            s32 bp = *(volatile s32 *)0x10002020;
            long top = *(volatile long *)0x10002030;
            p->x848 = top;
            if (top < 0) {
                p->x84C = (0x20 - (bp & 0x1F)) & 0x1F;
            } else {
                p->x84C = 0x20;
            }
        }
        p->x12C = (s32)r == 0;
        code = (s16)r;
        switch (code) {
        case 0x22:
            again = 1;
            break;
        case 0x23:
            again = 1;
            total += 0x21;
            break;
        case 0:
            c = func_00132970(p, 0xB);
            if (p->x858 != 0 && c == 0xF) {
                func_00132AD0(p, 0xB);
                again = 1;
                break;
            }
            func_0013A150_00132428(p, D_00151DC0, code);
            p->x12C = 1;
            return 1;
        default:
            total += code;
            again = 0;
            break;
        }
    } while (again);
    return total;
}
/* localdecomp:end func_00132428 */

/* localdecomp:start func_001325A0 */
typedef struct {
    u8 pad0[0x82C];
    int f82C;
    u8 pad830[0x868 - 0x830];
    int f868;
    u8 pad86C[0x878 - 0x86C];
    int f878;
} S_1325A0;
int func_00135DC8(int x);
void func_00139F90(void);

void func_001325A0(S_1325A0 *s)
{
    int cnt;
    u32 bp;
    int mode;
    u32 avail;

    cnt = 0;
    while ((*(volatile u32 *)0x10002010 & 0x80004000) == 0x80000000) {
        bp = *(volatile u32 *)0x10002020;
        mode = s->f82C;
        avail = ((bp & 0xFF00) >> 1) + ((bp & 0x30000) >> 9) - (bp & 0x7F);
        if ((mode == 0x20000000 || mode == 0x30000000 || mode == 0x40000000) && avail < 0x20 &&
            *(volatile u32 *)0x1000B420 == 0) {
            func_00135DC8(s->f868);
            if (s->f878) {
                goto err;
            }
            cnt = 0;
        }
        if (cnt++ > 0x1388) {
            func_00135DC8(s->f868);
            if (s->f878) {
            err:
                func_00139F90();
                s->f82C = 0;
                return;
            }
            cnt = 0;
        }
    }
    s->f82C = 0;
}
/* localdecomp:end func_001325A0 */

/* localdecomp:start func_00132708 */
typedef struct {
    u8 pad0[0x82C];
    s32 f82C;
    u8 pad830[0x868 - 0x830];
    s32 f868;
    u8 pad86C[0x878 - 0x86C];
    s32 f878;
} S_132708;

extern s32 func_00135DC8_00132708(s32);
extern void func_00139F90(void);

long func_00132708(S_132708 *p)
{
    long r;
    s32 n;
    u32 bp;
    s32 m;
    u32 avail;

    n = 0;
    while ((r = *(volatile long *)0x10002000) < 0 && !(*(volatile u32 *)0x10002010 & 0x4000)) {
        bp = *(volatile u32 *)0x10002020;
        m = p->f82C;
        avail = ((bp & 0xFF00) >> 1) + ((bp & 0x30000) >> 9) - (bp & 0x7F);
        if ((m == 0x20000000 || m == 0x30000000 || m == 0x40000000) && avail < 0x20
            && *(volatile u32 *)0x1000B420 == 0) {
            func_00135DC8_00132708(p->f868);
            if (p->f878 != 0) {
                func_00139F90();
                break;
            }
            n = 0;
        }
        if (n++ >= 0x1F5) {
            func_00135DC8_00132708(p->f868);
            if (p->f878 != 0) {
                func_00139F90();
                break;
            }
            n = 0;
        }
    }
    p->f82C = 0;
    return r;
}
/* localdecomp:end func_00132708 */

/* localdecomp:start func_00132888 */
/* libmpeg: get n bits through IPU FDEC; 2.9-ee-991111 */
static __inline__ void cmd_132888(S_132428 *p, u32 cmd) {
    *(volatile u32 *)0x10002000 = cmd;
    p->x82C = cmd & 0xF0000000;
    if (p->x82C == 0x20000000 || p->x82C == 0x30000000 || p->x82C == 0x40000000) {
        p->x828 = 0;
    } else {
        p->x828 = 1;
    }
}

u32 func_00132888(S_132428 *p, s32 n) {
    u32 r;

    func_00132A98(p);
    if (p->x828 != 0 || p->x84C < n) {
        cmd_132888(p, 0x40000000);
        p->x848 = func_00132708(p);
    }
    r = (u32)p->x848 >> (0x20 - n);
    p->x84C = 0x20;
    cmd_132888(p, n | 0x40000000);
    p->x848 = func_00132708(p);
    return r;
}
/* localdecomp:end func_00132888 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00132970);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00132A00);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00132A98);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00132AD0);

/* localdecomp:start func_00132AD8 */
typedef struct {
    u8 pad[0x1C];
    s32 x1C;
    u8 pad20[0x120];
} Pic_132AD8;

typedef struct {
    u8 pad[0x160];
    s32 x160;
    u8 pad164[0x20];
    s32 x184;
    u8 pad188[0x38];
    s32 x1C0;
    u8 pad1C4[0x4FC];
    Pic_132AD8 pics[1];
} Dec_132AD8;

typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[8];
    s32 x10;
    s32 x14;
} Rect_132AD8;

extern char D_00151D70[];
extern s32 func_0013A0F8();

s32 func_00132AD8(Dec_132AD8 *d, Rect_132AD8 *r, s32 *a, s32 *b, s32 *flags) {
    s32 ret;
    s32 t;

    ret = 1;
    d->pics[*(s32 *)((u8 *)d + 0x820)].x1C = 1;
    d->x1C0 = 1;
    if (d->x160 == 2) {
        r->x14 = 0;
        r->x10 = 0;
        r->x4 = 0;
        r->x0 = 0;
    }
    if (d->x184 == 3) {
        *a = 2;
    } else {
        *a = 1;
        t = d->x184 == 2;
        b[1] = t;
        b[0] = t;
    }
    if (d->x160 == 1) {
        func_0013A0F8(d, D_00151D70);
        ret = 0;
    }
    *flags &= ~1;
    return ret;
}
/* localdecomp:end func_00132AD8 */

ASM_FUNC("asm/boot_elf/handwritten", func_00132B98);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00132C84);

/* localdecomp:start func_00132D48 */
typedef struct {
    int f0;
    int pad4;
    int a[4];
    int b[4];
    u8 pad28[0x12C - 0x28];
    int n;
    u8 pad130[0x140 - 0x130];
} Blk_132D48;
typedef struct {
    u8 pad0[0x5A0];
    Blk_132D48 blk[2];
    int f820;
    u8 pad824[0x87C - 0x824];
    int f87C;
} S_132D48;
extern u64 D_15BE40[];
int func_00124920(void);
void func_00124970(void);

static inline u64 tag_132D48(u32 addr, int id, int qwc)
{
    return ((u64)addr << 32) | ((u64)id << 28) | (u64)qwc;
}

void func_00132D48(S_132D48 *s)
{
    u64 *p;
    int i;
    int n;
    int idx;
    int di;
    int id;

    if (s->f87C == 0) {
        idx = s->f820;
        n = s->blk[idx].n;
        p = (u64 *)(((u32)D_15BE40 & 0x0FFFFFFF) | 0x20000000);
        for (i = 0; i < n; i++) {
            p[0] = tag_132D48(s->blk[idx].a[i] & 0x0FFFFFFF, 3, 0x30);
            p[2] = tag_132D48(s->blk[idx].b[i] & 0x0FFFFFFF, i == n - 1 ? 0 : 3, 0x30);
            p += 4;
        }
        di = func_00124920();
        __asm__ __volatile__("sync");
        *(volatile u32 *)0x1000D480 = s->blk[s->f820].f0;
        *(volatile u32 *)0x1000D430 = (u32)D_15BE40;
        *(volatile u32 *)0x1000D420 = 0;
        *(volatile u32 *)0x1000D400 = 0x105;
        if (di) {
            func_00124970();
        }
    }
}
/* localdecomp:end func_00132D48 */
