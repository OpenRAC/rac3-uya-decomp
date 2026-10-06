#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003A4758 */
extern u8 D_001D8060;
void func_003A4758(u8 a) { D_001D8060 = a; }
/* localdecomp:end func_003A4758 */

/* localdecomp:start func_003A4760 */
extern u8 D_001D8060;
u8 func_003A4760(void) {
    return D_001D8060;
}
/* localdecomp:end func_003A4760 */

/* localdecomp:start func_003A4768 */
u8 *func_003A4768(u8 *p) {
    register u8 *r __asm__("$8");
    __asm__ __volatile__(
        ".set noreorder\n"
        "daddu $8, $4, $0\n"
        "lw $2, 0x10($8)\n"
        "lw $4, 0x14($8)\n"
        "lw $5, 0x18($8)\n"
        "addu $2, $2, $8\n"
        "lw $3, 0x1C($8)\n"
        "addu $4, $4, $8\n"
        "addu $5, $5, $8\n"
        "lw $6, 0x20($8)\n"
        "addu $3, $3, $8\n"
        "sw $2, 0x10($8)\n"
        "sw $4, 0x14($8)\n"
        "sw $5, 0x18($8)\n"
        "beqz $6, .L003A47AC_003A4768\n"
        "sw $3, 0x1C($8)\n"
        "addu $2, $6, $8\n"
        "sw $2, 0x20($8)\n"
        ".L003A47AC_003A4768:\n"
        "lwc1 $f0, 0xC($8)\n"
        "daddu $10, $0, $0\n"
        "lui $at, 0x3b52\n"
        "ori $at, $at, 0x79bc\n"
        "mtc1 $at, $f1\n"
        "lh $2, 0x6($8)\n"
        "mul.s $f0, $f0, $f1\n"
        "lw $9, 0x18($8)\n"
        "blez $2, .L003A4854_003A4768\n"
        "swc1 $f0, 0xC($8)\n"
        "addiu $11, $0, 0x1E\n"
        ".L003A47D8_003A4768:\n"
        "lw $3, 0x0($9)\n"
        "sll $5, $10, 4\n"
        "lw $2, 0x18($8)\n"
        "addiu $10, $10, 0x1\n"
        "lw $7, 0x4($9)\n"
        "sra $3, $3, 4\n"
        "lw $4, 0x8($9)\n"
        "addu $2, $5, $2\n"
        "lw $6, 0xC($9)\n"
        "sra $7, $7, 4\n"
        "sh $3, 0xA($2)\n"
        "plzcw $4, $4\n"
        "subu $4, $11, $4\n"
        "plzcw $6, $6\n"
        "lw $3, 0x18($8)\n"
        "subu $6, $11, $6\n"
        "addu $3, $5, $3\n"
        "sh $7, 0x8($3)\n"
        "lw $2, 0x18($8)\n"
        "addu $2, $5, $2\n"
        "sh $4, 0xC($2)\n"
        "lw $3, 0x18($8)\n"
        "addu $3, $5, $3\n"
        "sh $6, 0xE($3)\n"
        "lw $2, 0x18($8)\n"
        "addu $5, $5, $2\n"
        "sd $0, 0x0($5)\n"
        "lh $2, 0x6($8)\n"
        "slt $2, $10, $2\n"
        "bnez $2, .L003A47D8_003A4768\n"
        "addiu $9, $9, 0x10\n"
        ".L003A4854_003A4768:\n"
        ".set reorder\n"
        : "=r"(r) : : "memory"
    );
    return r;
}
/* localdecomp:end func_003A4768 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A4860);

extern int D_001DA0D0[];
/* localdecomp:start func_003A4A20 */
extern int D_001DA0D0[];
extern u32 *D_001DA0D0_g;
extern u8 D_001D8030;
void func_003A4A20(void) {
    ((u32 *)D_001DA0D0[0])[0] = 0x30000003;
    ((u32 *)D_001DA0D0[0])[1] = (u32)&D_001D8030;
    ((u32 *)D_001DA0D0[0])[2] = 0;
    ((u32 *)D_001DA0D0[0])[3] = 0x50000003;
    D_001DA0D0_g = (u32 *)D_001DA0D0[0] + 4;
}
/* localdecomp:end func_003A4A20 */

/* localdecomp:start func_003A4A78 */
typedef struct { s16 n; u8 p2[4]; s16 j6; u8 p8[8]; } E1_3A4A78;
typedef struct { s16 n; u8 p2[6]; s16 h8; u8 pA[2]; f32 fC; void *e10; u8 p14[0x10]; s32 f24; } A_3A4A78;
typedef struct { u8 p0[0xB0]; f32 fB0; f32 fB4; } C_3A4A78;
__asm__(".extern D_001D8060, 1");
extern u8 D_001D8060;
extern s32 D_001D4BC0;
extern s32 D_001D4BC4;
extern C_3A4A78 D_00225980_003A4A78;
extern void func_00388468();
extern void func_00388B68();
extern void func_00388948(void *, long);
extern void func_003888F0();
extern void func_00388698(void *, void *, void *);
extern void func_00388680();
extern void func_003A4860(A_3A4A78 *, void *, f32);
void func_003A4A78(A_3A4A78 *a, f32 *ow, f32 *oh, f32 sx, f32 sy, f32 t) {
    f32 m[16];
    f32 mn[4];
    f32 mx[4];
    f32 v[4];
    f32 v2[4];
    u8 *spr;
    if (D_001D8060 != 0) {
        sx *= a->fC * 1.18f;
        sy *= a->fC * 1.126f;
    } else {
        sx *= a->fC;
        sy *= a->fC;
    }
    func_00388468(m, 0x40);
    spr = (u8 *)0x70002000;
    m[0] = ((f32)(D_001D4BC0 >> 1) / D_00225980_003A4A78.fB0) * sx;
    m[9] = -((f32)(D_001D4BC4 >> 1) / D_00225980_003A4A78.fB4) * sy;
    func_00388B68(0x70001FC0);
    if (a->h8 != 0) func_003A4860(a, (void *)0x70002000, t);
    mn[0] = 100000.0f;
    mn[1] = 1000000.0f;
    mx[0] = -100000.0f;
    mx[1] = -1000000.0f;
    if (a->f24 == 0) {
        E1_3A4A78 *p = a->e10;
        s32 i;
        for (i = 0; i < a->n; i++) {
            func_00388948(v, *(long *)p);
            v[3] = 1.0f;
            func_003888F0(v, v, spr + p->j6 * 64);
            func_003888F0(v, v, m);
            func_00388698(mn, mn, v);
            func_00388680(mx, mx, v);
            p++;
        }
    } else {
        s32 *p = a->e10;
        s32 i;
        for (i = 0; i < a->n; i++) {
            s32 j;
            ((s32 *)v)[0] = (*p << 18) >> 16;
            ((s32 *)v)[1] = (*p << 4) >> 16;
            j = *p >> 28;
            func_00388948(v2, *(long *)v);
            v2[3] = 1.0f;
            func_003888F0(v2, v2, spr + j * 64);
            func_003888F0(v2, v2, m);
            func_00388698(mn, mn, v2);
            func_00388680(mx, mx, v2);
            p++;
        }
    }
    *ow = (mx[0] - mn[0]) * 0.0625f;
    *oh = (mx[1] - mn[1]) * 0.0625f;
}
/* localdecomp:end func_003A4A78 */

/* localdecomp:start func_003A4DC8 */
typedef struct { u8 p0[0xC]; f32 fC; } O_A4DC8;
extern void func_00388B68();
extern void func_003A4E70(O_A4DC8 *, f32, f32, s32, f32, f32 *);
void func_003A4DC8(O_A4DC8 *o, s32 flag, f32 a, f32 b, f32 c, f32 d, f32 e) {
    f32 m[16];
    if ((flag >> 24) != 0) {
        func_00388B68(m);
        m[0] = c * o->fC;
        m[10] = d * o->fC;
        func_003A4E70(o, a, b, flag, e, m);
    }
}
/* localdecomp:end func_003A4DC8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A4E70);
