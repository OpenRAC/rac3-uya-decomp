#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B6828 */
extern s32 D_001D8AD8;
extern s32 func_0039C310(void);
extern void func_0039C4E8(s32);
void func_003B6828(void) {
    if (func_0039C310()) func_0039C4E8(D_001D8AD8);
}
/* localdecomp:end func_003B6828 */

extern s32 D_001D8A70[];

/* localdecomp:start func_003B6858 */
extern s32 D_001D8A70_003B6858;
void func_003B6858(void) {
    D_001D8A70_003B6858 = 4;
}
/* localdecomp:end func_003B6858 */

/* localdecomp:start func_003B6868 */
typedef struct { u8 b[8]; } B8_3B10A8;
typedef struct { s32 f0, f4, f8, fC; B8_3B10A8 f10; s32 f18; } E_3B10A8;
typedef struct { u8 p0[0x30]; E_3B10A8 e[11]; u8 p1[0x17C - 0x30 - 11 * 0x1C]; s32 f17C; } S_3B10A8;
typedef struct { s32 f0; u8 p[0x2E]; u8 f32; } T_3B10A8;
__asm__(".extern D_001D8ACC, 4");
__asm__(".extern D_001D8AE4, 4");
__asm__(".extern D_001D8AE8, 1");
extern S_3B10A8 D_00142430_003B6868;
extern T_3B10A8 D_00142660_003B6868;
extern B8_3B10A8 D_001D4BE0_003B6868;
extern s32 D_001D545C_003B6868;
extern s32 D_001D5528;
extern s32 D_001D8ACC;
extern s32 D_001D8AE4;
extern u8 D_001D8AE8;
extern void func_0039C1B8(s32, s32);
void func_003B6868(void) {
    s32 h = D_001D8ACC;
    s32 i;
    if (h != 0) {
        i = D_001D8AE4;
        D_00142430_003B6868.f17C = 1;
        D_00142430_003B6868.e[i].f4 = D_00142660_003B6868.f0;
        D_00142430_003B6868.e[i].f0 = D_001D545C_003B6868;
        D_00142430_003B6868.e[i].fC = D_001D5528;
        { B8_3B10A8 *q = &D_00142430_003B6868.e[i].f10; *q = D_001D4BE0_003B6868; }
        D_00142430_003B6868.e[i].f8 = D_00142660_003B6868.f32;
        func_0039C1B8(h, -1);
        D_001D8AE8 = 1;
    }
}
/* localdecomp:end func_003B6868 */

/* localdecomp:start func_003B6918 */
extern s32 D_001D8ACC;
extern u8 D_001D8AE8;
extern void func_0039C1B8(s32, s32);
extern void func_0039C5C8(void);
void func_003B6918(void) {
    func_0039C5C8();
    if (D_001D8ACC != 0) {
        func_0039C1B8(D_001D8ACC, 1);
        D_001D8AE8 = 1;
    }
}
/* localdecomp:end func_003B6918 */

/* localdecomp:start func_003B6950 */
extern s32 D_001D8ACC;
extern u8 D_001D8AE8;
extern void func_0039C1B8(s32, s32);
void func_003B6950(void) {
    if (D_001D8ACC != 0) {
        func_0039C1B8(D_001D8ACC, 1);
        D_001D8AE8 = 1;
    }
}
/* localdecomp:end func_003B6950 */

/* localdecomp:start func_003B6980 */
extern s32 D_001D8ACC;
extern s32 D_001D8AE4;
extern u8 D_001D8AE9;
extern s32 D_001D545C[];
extern u8 D_001D5571[];
extern void func_0039E8A8(s32);
extern void func_0039C188(s16);
void func_003B6980(void)
{
  unsigned long new_var;
  u8 v;
  new_var = 0;
  func_0039E8A8(D_001D8ACC);
  v = new_var;
  if (D_001D545C[new_var] < 2)
  {
    new_var = D_001D5571[0] == new_var;
    v = new_var;
  }
  D_001D8AE9 = v;
  ((void (*)(s32)) func_0039C188)(D_001D8AE4);
}
/* localdecomp:end func_003B6980 */

/* localdecomp:start func_003B69D0 */
__asm__(".extern D_001D545C_gp_003B1210, 4");
__asm__(".extern D_001D8ACC, 4");
__asm__(".extern D_001D8A70_003B69D0, 4");
extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s32 D_001D545C_gp_003B1210;
extern s32 D_001D545C_003B69D0;
extern u8 D_001D5571_003B69D0;
extern s32 D_001D5B74;
extern s32 D_001D9D84;
extern u8 D_001D5638;
extern s32 D_0022D010[];
extern s32 D_001D8ACC;
extern s32 D_001D8A70_003B69D0;
extern s32 func_0039C310();
extern void func_0039C4E8();
extern void func_003A42A0(void);
extern s32 func_003A2A10(s32);
extern void func_0013BFE0(s32);
extern void func_003A91C0(void);
void func_003B69D0(void) {
    s32 v;
    if (func_0039C310()) {
        func_0039C4E8(D_001D8ACC);
        D_001D8A70_003B69D0 = 5;
        return;
    }
    D_001425AC[0] = 1;
    func_003A42A0();
    func_003A2A10(1);
    func_0013BFE0(D_00143958[0] == 0);
    v = D_001D545C_gp_003B1210;
    if (D_001D545C_003B69D0 < 2 && D_001D5571_003B69D0 == 0) {
        func_003A91C0();
    } else {
        *(volatile s32 *)&D_001D5B74 = 1;
        *(volatile s32 *)&D_001D9D84 = v;
    }
    D_001D5638 = 1;
    D_0022D010[0] = 0;
}
/* localdecomp:end func_003B69D0 */

/* localdecomp:start func_003B6A88 */
__asm__(".extern D_001D8ACC, 4");
__asm__(".extern D_001D8A70_003B6A88, 4");
__asm__(".extern D_001D8AE9, 1");
__asm__(".extern D_001D545C_003B6A88, 4");
extern s32 func_0039C310(void);
extern void func_0039C4E8(s32);
extern void func_003BB3B8(void);
extern void func_003BB3C8(s32);
extern void func_003A42A0(void);
extern void func_0013BFE0(s32);
extern s32 D_001D8ACC;
extern s32 D_001D8A70_003B6A88;
extern u8 D_001D8AE9;
extern s32 D_001D545C_003B6A88;
extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s8 D_001D5638_003B6A88;
extern s32 D_0022D010[];
void func_003B6A88(void) {
    if (func_0039C310() != 0) {
        func_0039C4E8(D_001D8ACC);
        D_001D8A70_003B6A88 = 5;
        return;
    }
    D_001425AC[0] = 1;
    func_003A42A0();
    ((s32 (*)(s32))func_003A2A10)(1);
    func_0013BFE0(D_00143958[0] == 0);
    if (D_001D8AE9 != 0) {
        func_003BB3B8();
    } else {
        func_003BB3C8(D_001D545C_003B6A88);
    }
    D_001D8A70_003B6A88 = 6;
    D_001D5638_003B6A88 = 1;
    D_0022D010[0] = 0;
}
/* localdecomp:end func_003B6A88 */

/* localdecomp:start func_003B6B28 */
extern s32 D_001D8ACC;
extern s32 D_001D8AE4;
extern s32 D_001D8A70_g;
extern void func_003B3440(void *); // Ensure this prototype matches exactly
extern void func_0039BFD0(void (*)(), s32, void (*)());
extern void func_003B6918();
extern void func_003B67F0();


void func_003B6B28(void) {
    func_003B3440((void *)(s32)D_001D8ACC);
    
    // Explicit sequence point
    *(volatile s32 *)&D_001D8A70_g = 1; 
    
    func_0039BFD0(func_003B6918, D_001D8AE4, func_003B67F0);
}
/* localdecomp:end func_003B6B28 */

/* localdecomp:start func_003B6B68 */
extern void func_0039C138(void);
extern s32 D_001D8A70_g;
void func_003B6B68(void) {
    func_0039C138();
    D_001D8A70_g = 1;
}
/* localdecomp:end func_003B6B68 */

/* localdecomp:start func_003B6B90 */
extern s32 func_0039BF38(s32, void *);
extern void func_003B6858();
extern s32 D_001D8A70_g;
s32 func_003B6B90(void) {
    s32 r = func_0039BF38(0, func_003B6858);
    D_001D8A70_g = 1;
    return r;
}
/* localdecomp:end func_003B6B90 */

/* localdecomp:start func_003B6BC0 */
extern s32 func_0039BF38(s32, void *);
extern void func_003B6858();
extern s32 D_001D8A70_g;
s32 func_003B6BC0(void) {
    s32 r = func_0039BF38(0, func_003B6858);
    D_001D8A70_g = 1;
    return r;
}
/* localdecomp:end func_003B6BC0 */

/* localdecomp:start func_003B6BF0 */
extern unsigned char D_001D5BDC;
extern int D_001D8AE4;
extern int D_001D8A70_g;
__asm__(".extern D_001D8AE4, 4");
__asm__(".extern D_001D8A70_g, 4");
extern void func_0039C088(int, int, int);
extern void func_003B6980(void);
extern void func_003B69D0(void);
extern void func_003B6A88(void);

void func_003B6BF0(void) {
    register int flag __asm__("$2");
    flag = D_001D5BDC;
    if (flag != 0) {
        func_0039C088((int)func_003B6980, D_001D8AE4, (int)func_003B69D0);
    } else {
        func_0039C088((int)func_003B6980, D_001D8AE4, (int)func_003B6A88);
    }
    D_001D8A70_g = 1;
}
/* localdecomp:end func_003B6BF0 */

/* localdecomp:start func_003B6C50 */
extern s32 D_001D8ACC;
extern s32 D_001D8AE4;
extern s32 D_001D8A70_g;
extern void func_003B3440(void *);
extern void func_0039BFD0();
extern void func_003B6868();
void func_003B6C50(void) {
    func_003B3440((void *)D_001D8ACC);
    func_0039BFD0(func_003B6868, D_001D8AE4, 0);
    D_001D8A70_g = 1;
}
/* localdecomp:end func_003B6C50 */

/* localdecomp:start func_003B6C90 */
extern s32 D_001D8ACC;
extern s32 D_001D8AE4;
extern s32 D_001D8A70_g;
extern void func_003B3440(void *);
extern void func_003B8D18(s32);
extern void func_0039BFD0();
extern void func_003B6950();
extern void func_003B6828();
void func_003B6C90(void) {
    func_003B3440((void *)D_001D8ACC);
    func_003B8D18(D_001D8AE4);
    func_0039BFD0(func_003B6950, D_001D8AE4, func_003B6828);
    D_001D8A70_g = 1;
}
/* localdecomp:end func_003B6C90 */
