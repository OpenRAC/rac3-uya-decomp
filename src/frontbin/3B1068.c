#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B1068 */
extern s32 D_001D8AD8;
extern s32 func_00397258(void);
extern void func_003972A0(s32);
void func_003B1068(void) {
    if (func_00397258()) func_003972A0(D_001D8AD8);
}
/* localdecomp:end func_003B1068 */

extern s32 D_001D8A70[];
/* localdecomp:start func_003B1098 */
extern s32 D_001D8A70_003B1098;
void func_003B1098(void) {
    D_001D8A70_003B1098 = 4;
}
/* localdecomp:end func_003B1098 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B10A8);

/* localdecomp:start func_003B1158 */
extern s32 D_001D8ACC;
extern u8 D_001D8AE8;
extern void func_00397100(s32, s32);
extern void func_00397380(void);
void func_003B1158(void) {
    func_00397380();
    if (D_001D8ACC != 0) {
        func_00397100(D_001D8ACC, 1);
        D_001D8AE8 = 1;
    }
}
/* localdecomp:end func_003B1158 */

/* localdecomp:start func_003B1190 */
extern s32 D_001D8ACC;
extern u8 D_001D8AE8;
extern void func_00397100(s32, s32);
void func_003B1190(void) {
    if (D_001D8ACC != 0) {
        func_00397100(D_001D8ACC, 1);
        D_001D8AE8 = 1;
    }
}
/* localdecomp:end func_003B1190 */

/* localdecomp:start func_003B11C0 */
extern s32 D_001D8ACC;
extern s32 D_001D8AE4;
extern u8 D_001D8AE9;
extern s32 D_001D545C[];
extern u8 D_001D5571[];
extern void func_00399660(s32);
extern void func_003970D0(s16);
void func_003B11C0(void)
{
  unsigned long new_var;
  u8 v;
  new_var = 0;
  func_00399660(D_001D8ACC);
  v = new_var;
  if (D_001D545C[new_var] < 2)
  {
    new_var = D_001D5571[0] == new_var;
    v = new_var;
  }
  D_001D8AE9 = v;
  ((void (*)(s32)) func_003970D0)(D_001D8AE4);
}
/* localdecomp:end func_003B11C0 */

/* localdecomp:start func_003B1210 */
__asm__(".extern D_001D545C_gp_003B1210, 4");
__asm__(".extern D_001D8ACC, 4");
__asm__(".extern D_001D8A70_003B1210, 4");
extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s32 D_001D545C_gp_003B1210;
extern s32 D_001D545C_003B1210;
extern u8 D_001D5571_003B1210;
extern s32 D_001D5B74;
extern s32 D_001D9D84;
extern u8 D_001D5638;
extern s32 D_00229010[];
extern s32 D_001D8ACC;
extern s32 D_001D8A70_003B1210;
extern s32 func_00397258();
extern void func_003972A0();
extern void func_0039ED50(void);
extern s32 func_0039D6C8(s32);
extern void func_0013BFE0(s32);
extern void func_003A3A00(void);
void func_003B1210(void) {
    s32 v;
    if (func_00397258()) {
        func_003972A0(D_001D8ACC);
        D_001D8A70_003B1210 = 5;
        return;
    }
    D_001425AC[0] = 1;
    func_0039ED50();
    func_0039D6C8(1);
    func_0013BFE0(D_00143958[0] == 0);
    v = D_001D545C_gp_003B1210;
    if (D_001D545C_003B1210 < 2 && D_001D5571_003B1210 == 0) {
        func_003A3A00();
    } else {
        *(volatile s32 *)&D_001D5B74 = 1;
        *(volatile s32 *)&D_001D9D84 = v;
    }
    D_001D5638 = 1;
    D_00229010[0] = 0;
}
/* localdecomp:end func_003B1210 */

/* localdecomp:start func_003B12C8 */
__asm__(".extern D_001D8ACC, 4");
__asm__(".extern D_001D8A70_003B12C8, 4");
__asm__(".extern D_001D8AE9, 1");
__asm__(".extern D_001D545C_003B12C8, 4");
extern s32 func_00397258(void);
extern void func_003972A0(s32);
extern void func_003B5BF8(void);
extern void func_003B5C08(s32);
extern void func_0039ED50(void);
extern void func_0013BFE0(s32);
extern s32 D_001D8ACC;
extern s32 D_001D8A70_003B12C8;
extern u8 D_001D8AE9;
extern s32 D_001D545C_003B12C8;
extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s8 D_001D5638_003B12C8;
extern s32 D_00229010[];
void func_003B12C8(void) {
    if (func_00397258() != 0) {
        func_003972A0(D_001D8ACC);
        D_001D8A70_003B12C8 = 5;
        return;
    }
    D_001425AC[0] = 1;
    func_0039ED50();
    ((s32 (*)(s32))func_0039D6C8)(1);
    func_0013BFE0(D_00143958[0] == 0);
    if (D_001D8AE9 != 0) {
        func_003B5BF8();
    } else {
        func_003B5C08(D_001D545C_003B12C8);
    }
    D_001D8A70_003B12C8 = 6;
    D_001D5638_003B12C8 = 1;
    D_00229010[0] = 0;
}
/* localdecomp:end func_003B12C8 */

/* localdecomp:start func_003B1368 */
extern s32 D_001D8ACC;
extern s32 D_001D8AE4;
extern s32 D_001D8A70_g;
extern void func_003ADC80(void *); // Ensure this prototype matches exactly
extern void func_00396F18(void (*)(), s32, void (*)());
extern void func_003B1158();
extern void func_003B1030();


void func_003B1368(void) {
    func_003ADC80((void *)(s32)D_001D8ACC);
    
    // Explicit sequence point
    *(volatile s32 *)&D_001D8A70_g = 1; 
    
    func_00396F18(func_003B1158, D_001D8AE4, func_003B1030);
}
/* localdecomp:end func_003B1368 */

/* localdecomp:start func_003B13A8 */
extern void func_00397080(void);
extern s32 D_001D8A70_g;
void func_003B13A8(void) {
    func_00397080();
    D_001D8A70_g = 1;
}
/* localdecomp:end func_003B13A8 */

/* localdecomp:start func_003B13D0 */
extern s32 func_00396E80(s32, void *);
extern void func_003B1098();
extern s32 D_001D8A70_g;
s32 func_003B13D0(void) {
    s32 r = func_00396E80(0, func_003B1098);
    D_001D8A70_g = 1;
    return r;
}
/* localdecomp:end func_003B13D0 */

/* localdecomp:start func_003B1400 */
extern s32 func_00396E80(s32, void *);
extern void func_003B1098();
extern s32 D_001D8A70_g;
s32 func_003B1400(void) {
    s32 r = func_00396E80(0, func_003B1098);
    D_001D8A70_g = 1;
    return r;
}
/* localdecomp:end func_003B1400 */

/* localdecomp:start func_003B1430 */
extern unsigned char D_001D5BDC;
extern int D_001D8AE4;
extern int D_001D8A70_g;
__asm__(".extern D_001D8AE4, 4");
__asm__(".extern D_001D8A70_g, 4");
extern void func_00396FD0(int, int, int);
extern void func_003B11C0(void);
extern void func_003B1210(void);
extern void func_003B12C8(void);

void func_003B1430(void) {
    register int flag __asm__("$2");
    flag = D_001D5BDC;
    if (flag != 0) {
        func_00396FD0((int)func_003B11C0, D_001D8AE4, (int)func_003B1210);
    } else {
        func_00396FD0((int)func_003B11C0, D_001D8AE4, (int)func_003B12C8);
    }
    D_001D8A70_g = 1;
}
/* localdecomp:end func_003B1430 */

/* localdecomp:start func_003B1490 */
extern s32 D_001D8ACC;
extern s32 D_001D8AE4;
extern s32 D_001D8A70_g;
extern void func_003ADC80(void *);
extern void func_00396F18();
extern void func_003B10A8();
void func_003B1490(void) {
    func_003ADC80((void *)D_001D8ACC);
    func_00396F18(func_003B10A8, D_001D8AE4, 0);
    D_001D8A70_g = 1;
}
/* localdecomp:end func_003B1490 */

/* localdecomp:start func_003B14D0 */
extern s32 D_001D8ACC;
extern s32 D_001D8AE4;
extern s32 D_001D8A70_g;
extern void func_003ADC80(void *);
extern void func_003B3558(s32);
extern void func_00396F18();
extern void func_003B1190();
extern void func_003B1068();
void func_003B14D0(void) {
    func_003ADC80((void *)D_001D8ACC);
    func_003B3558(D_001D8AE4);
    func_00396F18(func_003B1190, D_001D8AE4, func_003B1068);
    D_001D8A70_g = 1;
}
/* localdecomp:end func_003B14D0 */
