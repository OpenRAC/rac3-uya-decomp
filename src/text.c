#include "common.h"

/* localdecomp:start func_0037D100 */
extern void func_003934E8(s32, s32);

void func_0037D100(void) {
    func_003934E8(0, 0);
}
/* localdecomp:end func_0037D100 */

/* localdecomp:start func_0037D120 */
extern void func_003B62D0(s32);
extern void func_003ADC80(void *);
extern s32 func_0039BEC0(s32, s32, s32, s32, u8 *);
extern u8 D_001E2340[];

void func_0037D120(void) {
    func_003B62D0(1);
    func_003ADC80(D_001E2340);
    func_0039BEC0(0x12, 1, 7, 0, 0);
}
/* localdecomp:end func_0037D120 */

/* localdecomp:start func_0037D160 */
extern void func_003B62D0(s32);
extern s32 func_0039BEC0(s32, s32, s32, s32, u8 *);

void func_0037D160(void) {
    func_003B62D0(1);
    func_0039BEC0(0x12, 1, 8, 0, 0);
}
/* localdecomp:end func_0037D160 */

/* localdecomp:start func_0037D198 */
s32 func_0037D198(void) {
}
/* localdecomp:end func_0037D198 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037D1A0);

extern s32 func_0011A264(s32, s32, s32);
extern s32 func_003ECDC0(s32, s32);
extern void *func_003A9B10(void *, s32);
extern s32 D_001D5C78;

typedef struct {
    u8 pad[0x84];
    s32 f84;
} Struct227600;
extern Struct227600 D_00227600;
INCLUDE_ASM("asm/nonmatchings/text", func_0037D1A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037D200);

/* localdecomp:start func_0037DC30 */
s32 func_0037DC30(void) {
    return 0;
}
/* localdecomp:end func_0037DC30 */

/* localdecomp:start func_0037DC38 */
s32 func_0037DC38(void) {
}
/* localdecomp:end func_0037DC38 */

/* localdecomp:start func_0037DC40 */
s32 func_0037DC40(void) {
}
/* localdecomp:end func_0037DC40 */

/* localdecomp:start func_0037DC48 */
s32 func_0037DC48(void) {
}
/* localdecomp:end func_0037DC48 */

/* localdecomp:start func_0037DC50 */
s32 func_0037DC50(void) {
}
/* localdecomp:end func_0037DC50 */

/* localdecomp:start func_0037DC58 */
extern u8 D_001427AB[];
u8 func_0037DC58(void) {
    return D_001427AB[0];
}
/* localdecomp:end func_0037DC58 */

extern s32 func_003E1A50(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
/* localdecomp:start func_0037DC68 */
extern s32 func_003E1A50(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001D9918;
extern s32 D_001D9900[2];
s32 *func_0037DC68(void) {
    if (D_001D9918 == 0) {
        func_003E1A50(D_001D9900, 0, 0, 0, 0, 0);
        D_001D9918 = 1;
    }
    return D_001D9900;
}
/* localdecomp:end func_0037DC68 */

/* localdecomp:start func_0037DCB0 */
extern s32* func_0037DC68(void);
void func_0037DCB0(void) {
    func_0037DC68();
}
/* localdecomp:end func_0037DCB0 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037DCD0);

/* localdecomp:start func_0037DCD8 */
s32 func_0037DCD8(void) {
}
/* localdecomp:end func_0037DCD8 */

/* localdecomp:start func_0037DCE0 */
s32 func_0037DCE0(void) {
}
/* localdecomp:end func_0037DCE0 */

/* localdecomp:start func_0037DCE8 */
s32 func_0037DCE8(void) {
}
/* localdecomp:end func_0037DCE8 */

/* localdecomp:start func_0037DCF0 */
s32 func_0037DCF0(void) {
    return 0;
}
/* localdecomp:end func_0037DCF0 */

/* localdecomp:start func_0037DCF8 */
s32 func_0037DCF8(void) {
    return 0;
}
/* localdecomp:end func_0037DCF8 */

/* localdecomp:start func_0037DD00 */
s32 func_0037DD00(void) {
}
/* localdecomp:end func_0037DD00 */

/* localdecomp:start func_0037DD08 */
s32 func_0037DD08(void) {
}
/* localdecomp:end func_0037DD08 */

/* localdecomp:start func_0037DD10 */
s32 func_0037DD10(void) {
}
/* localdecomp:end func_0037DD10 */

/* localdecomp:start func_0037DD18 */
s32 func_0037DD18(void) {
}
/* localdecomp:end func_0037DD18 */

/* localdecomp:start func_0037DD20 */
s32 func_0037DD20(void) {
    return 0;
}
/* localdecomp:end func_0037DD20 */

/* localdecomp:start func_0037DD28 */
s32 func_0037DD28(void) {
    return 1;
}
/* localdecomp:end func_0037DD28 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037DD30);

INCLUDE_ASM("asm/nonmatchings/text", func_0037DF20);

INCLUDE_ASM("asm/nonmatchings/text", func_0037DF28);

/* localdecomp:start func_0037DF98 */
extern s32 func_0037DF28(s32);

s32 func_0037DF98(s32 id) {
    register u8 *gp __asm__("gp");
    s32 index;
    s32 fallback;
    s32** basePtr;

    index = func_0037DF28(id);
    fallback = (s32)(gp - 0x7128);
    
    // Pattern Library Scheduling Fence: Passing both operands forces the 
    // compiler to completely materialize row 14 BEFORE executing the branch check.
    __asm__ volatile("" : : "r"(index), "r"(fallback));

    if (index < 0) {
        return fallback;
    }
    
    basePtr = (s32**)0x1D9A20; // 0x001E0000 - 0x65E0
    return (*basePtr)[index * 4];
}
/* localdecomp:end func_0037DF98 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037DFD8);

/* localdecomp:start func_0037E030 */
extern s32 func_0037DFD8(void);
void func_0037E030(void) {
    func_0037DF98(func_0037DFD8());
}
/* localdecomp:end func_0037E030 */

/* localdecomp:start func_0037E058 */
extern s32 D_001D5688;
void func_0037E058(void) { D_001D5688 = 0; }
/* localdecomp:end func_0037E058 */

extern s32 D_001D5680;
/* localdecomp:start func_0037E060 */
extern s32 D_001D5680;
void func_0037E060(void) { D_001D5680 = 10; }
/* localdecomp:end func_0037E060 */

/* localdecomp:start func_0037E070 */
extern void func_00393460(void *, s32, s32);
extern u8 D_001D5790[];
 
void func_0037E070(void) {
    func_00393460(D_001D5790, 0, 0);
}
/* localdecomp:end func_0037E070 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037E098);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E0B8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E0F0);

/* localdecomp:start func_0037E1D8 */
extern s32 func_0013D3E0(void);
s32 func_0037E1D8(s32 a) {
    return func_0013D3E0() % a;
}
/* localdecomp:end func_0037E1D8 */

/* localdecomp:start func_0037E208 */
extern s32 func_0013D3E0(void);
s32 func_0037E208(s32 lo, s32 hi) {
    return func_0013D3E0() % (hi - lo + 1) + lo;
}
/* localdecomp:end func_0037E208 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037E250);

/* localdecomp:start func_0037E2A8 */
extern s32 func_0013D3E0(void);
f32 func_0037E2A8(void) {
    return (f32)(func_0013D3E0() - 0x4000) * 3.1415927f * (1.0f / 16384.0f);
}
/* localdecomp:end func_0037E2A8 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037E2F0);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E368);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E4B8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E548);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E568);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E630);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E7C8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E7D8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E878);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E920);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E9B0);

INCLUDE_ASM("asm/nonmatchings/text", func_0037EA98);

INCLUDE_ASM("asm/nonmatchings/text", func_0037EAA0);

/* localdecomp:start func_0037EB20 */
typedef struct { s32 a, b, c, d, e; } S_37D000;
extern S_37D000 D_0037D000[];
void func_0037EB20(u8 *p) {
    void (*f)(u8 *) = (void (*)(u8 *))D_0037D000[*(s16 *)(p + 0x8C)].c;
    if (f != 0) {
        f(p);
    }
}
/* localdecomp:end func_0037EB20 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037EB68);

INCLUDE_ASM("asm/nonmatchings/text", func_0037EE80);

/* localdecomp:start func_0037F090 */
extern S_37D000 D_0037D000[];
void func_0037F090(u8 *p) {
    void (*f)(u8 *) = (void (*)(u8 *))D_0037D000[*(s16 *)(p + 0x8C)].e;
    if (f != 0) {
        f(p);
    }
}
/* localdecomp:end func_0037F090 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037F0D8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F228);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F420);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F4F8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F550);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F588);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F7A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F978);

INCLUDE_ASM("asm/nonmatchings/text", func_0037FEE8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037FF90);

INCLUDE_ASM("asm/nonmatchings/text", func_003801C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003804A0);

INCLUDE_ASM("asm/nonmatchings/text", func_00380600);

INCLUDE_ASM("asm/nonmatchings/text", func_003807F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003808E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003809F0);

INCLUDE_ASM("asm/nonmatchings/text", func_00380AB0);

INCLUDE_ASM("asm/nonmatchings/text", func_00380D28);

INCLUDE_ASM("asm/nonmatchings/text", func_00380D48);

INCLUDE_ASM("asm/nonmatchings/text", func_003810C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003813E0);

INCLUDE_ASM("asm/nonmatchings/text", func_00381A48);

INCLUDE_ASM("asm/nonmatchings/text", func_00381A50);

INCLUDE_ASM("asm/nonmatchings/text", func_00381C18);

INCLUDE_ASM("asm/nonmatchings/text", func_00381D90);

INCLUDE_ASM("asm/nonmatchings/text", func_00381DD0);

INCLUDE_ASM("asm/nonmatchings/text", func_00381F10);

INCLUDE_ASM("asm/nonmatchings/text", func_00381F18);

INCLUDE_ASM("asm/nonmatchings/text", func_003821E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003822C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003823A0);

INCLUDE_ASM("asm/nonmatchings/text", func_00382458);

INCLUDE_ASM("asm/nonmatchings/text", func_00382F40);

INCLUDE_ASM("asm/nonmatchings/text", func_00382F90);

INCLUDE_ASM("asm/nonmatchings/text", func_003830E8);

INCLUDE_ASM("asm/nonmatchings/text", func_00383840);

INCLUDE_ASM("asm/nonmatchings/text", func_00383848);

INCLUDE_ASM("asm/nonmatchings/text", func_003838C0);

/* localdecomp:start func_00383A90 */
extern unsigned long D_001CFEC8[];
void func_00383A90(void) {
    *(volatile unsigned long *)0x120000E0 = 0;
    *(volatile unsigned long *)0x12000000 = 0xFFA1;
    *(volatile unsigned long *)0x12000020 = D_001CFEC8[0];
    *(volatile unsigned long *)0x12000070 = D_001CFEC8[1];
    *(volatile unsigned long *)0x12000090 = D_001CFEC8[1];
    *(volatile unsigned long *)0x12000080 = D_001CFEC8[2];
    *(volatile unsigned long *)0x120000A0 = D_001CFEC8[2];
    *(volatile unsigned long *)0x120000D0 = 0;
}
/* localdecomp:end func_00383A90 */

INCLUDE_ASM("asm/nonmatchings/text", func_00383B08);

/* localdecomp:start func_00383B90 */
extern void func_0038DA80(void);
void func_00383B90(void) {
    func_0038DA80();
}
/* localdecomp:end func_00383B90 */

INCLUDE_ASM("asm/nonmatchings/text", func_00383BB0);

INCLUDE_ASM("asm/nonmatchings/text", func_00383FD8);

INCLUDE_ASM("asm/nonmatchings/text", func_00384418);

INCLUDE_ASM("asm/nonmatchings/text", func_00384420);

INCLUDE_ASM("asm/nonmatchings/text", func_00384B48);

INCLUDE_ASM("asm/nonmatchings/text", func_00384B68);

INCLUDE_ASM("asm/nonmatchings/text", func_00384C98);

INCLUDE_ASM("asm/nonmatchings/text", func_00384DA0);

INCLUDE_ASM("asm/nonmatchings/text", func_00384EB0);

INCLUDE_ASM("asm/nonmatchings/text", func_00384EC0);

INCLUDE_ASM("asm/nonmatchings/text", func_00385438);

INCLUDE_ASM("asm/nonmatchings/text", func_00385570);

INCLUDE_ASM("asm/nonmatchings/text", func_00385628);

INCLUDE_ASM("asm/nonmatchings/text", func_00385688);

/* localdecomp:start func_003856D8 */
extern s32 D_001D9C88;
extern void (*D_00226880[])(s32);
extern s32 D_00226980[];
void func_003856D8(void) {
    s32 i;
    for (i = 0; i < D_001D9C88; i++) D_00226880[i](D_00226980[i]);
}
/* localdecomp:end func_003856D8 */

/* localdecomp:start func_00385750 */
extern s32 D_001D9C90;
extern void (*D_00226C80[])(s32);
extern s32 D_00226D80[];
void func_00385750(void) {
    s32 i;
    for (i = 0; i < D_001D9C90; i++) D_00226C80[i](D_00226D80[i]);
}
/* localdecomp:end func_00385750 */

/* localdecomp:start func_003857C8 */
extern s32 D_001D9C94;
extern void (*D_00226E80[])(s32);
extern s32 D_00226F80[];
void func_003857C8(void) {
    s32 i;
    for (i = 0; i < D_001D9C94; i++) D_00226E80[i](D_00226F80[i]);
}
/* localdecomp:end func_003857C8 */

INCLUDE_ASM("asm/nonmatchings/text", func_00385840);

/* localdecomp:start func_00385890 */
extern s32 D_001D9C8C;
extern void (*D_00226A80[])(s32);
extern s32 D_00226B80[];
void func_00385890(void) {
    s32 i;
    for (i = 0; i < D_001D9C8C; i++) D_00226A80[i](D_00226B80[i]);
}
/* localdecomp:end func_00385890 */

INCLUDE_ASM("asm/nonmatchings/text", func_00385908);

INCLUDE_ASM("asm/nonmatchings/text", func_00385980);

INCLUDE_ASM("asm/nonmatchings/text", func_00385B60);

INCLUDE_ASM("asm/nonmatchings/text", func_00385CE0);

INCLUDE_ASM("asm/nonmatchings/text", func_00385E40);

INCLUDE_ASM("asm/nonmatchings/text", func_00386210);

INCLUDE_ASM("asm/nonmatchings/text", func_00386488);

INCLUDE_ASM("asm/nonmatchings/text", func_00386608);

INCLUDE_ASM("asm/nonmatchings/text", func_003866E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003867F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003869E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003869E8);

INCLUDE_ASM("asm/nonmatchings/text", func_00386D98);

INCLUDE_ASM("asm/nonmatchings/text", func_00386F28);

INCLUDE_ASM("asm/nonmatchings/text", func_00386F38);

INCLUDE_ASM("asm/nonmatchings/text", func_00387118);

INCLUDE_ASM("asm/nonmatchings/text", func_003872F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003875A0);

INCLUDE_ASM("asm/nonmatchings/text", func_00387A00);

INCLUDE_ASM("asm/nonmatchings/text", func_00387B10);

/* localdecomp:start func_00387BD8 */
extern s32 D_001D4BD0[];
extern s32 D_001D4BD4[];
extern void func_00387B10(unsigned long *, s32);
void func_00387BD8(s32 a, s32 b, s32 c, s32 d, unsigned long e, s32 g) {
    unsigned long v[4];
    s32 y = D_001D4BD4[0];
    s32 x = D_001D4BD0[0];
    s32 D = (d << 4) + y - 8;
    s32 C = (c << 4) + x - 8;
    s32 B = (b << 4) + y - 8;
    s32 A = (a << 4) + x - 8;
    v[0] = (unsigned long)A | ((unsigned long)B << 16) | (e << 32);
    v[1] = (unsigned long)C | ((unsigned long)B << 16) | (e << 32);
    v[2] = (unsigned long)A | ((unsigned long)D << 16) | (e << 32);
    v[3] = (unsigned long)C | ((unsigned long)D << 16) | (e << 32);
    func_00387B10(v, g);
}
/* localdecomp:end func_00387BD8 */

INCLUDE_ASM("asm/nonmatchings/text", func_00387C78);

INCLUDE_ASM("asm/nonmatchings/text", func_00387DB8);

INCLUDE_ASM("asm/nonmatchings/text", func_00387DC8);

INCLUDE_ASM("asm/nonmatchings/text", func_00388018);

INCLUDE_ASM("asm/nonmatchings/text", func_00388258);

/* localdecomp:start func_00388278 */
extern void func_003C8CE0(void);
extern void func_003C8C40(void);
extern void func_003C8D50(void);
extern void func_003A3EF0(s32, unsigned long);
extern s32 D_001A1ED8[];
void func_00388278(void) {
    func_003C8CE0();
    func_003C8C40();
    func_003C8D50();
    func_003A3EF0(0x47, 0x5360B);
    func_003A3EF0(0x4E, (D_001A1ED8[0] >> 13) | 0x1000000);
}
/* localdecomp:end func_00388278 */

/* localdecomp:start func_003882D0 */
register char *_gpreg __asm__("$28");
#define D_001D5308 (*(f32 *)(_gpreg + -30120))
f32 func_003882D0(f32 x) {
    f32 val = D_001D5308;
    __asm__ volatile("nop");
    return val * x;
}
/* localdecomp:end func_003882D0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003882E0);

/* localdecomp:start func_00388308 */
register char *_gpreg __asm__("$28");
#define D_001D530C (*(f32 *)(_gpreg + -30116))

f32 func_00388308(f32 x) {
    f32 val = D_001D530C;
    
    // Inject a raw nop right after the load.
    __asm__ volatile("nop"); 

    // The compiler's -O2 will naturally schedule this multiplication 
    // into the branch delay slot of the jr $ra instruction.
    return val * x;
}
/* localdecomp:end func_00388308 */

INCLUDE_ASM("asm/nonmatchings/text", func_00388318);

/* localdecomp:start func_00388340 */
register char *_gpreg __asm__("$28");
#define D_001D5310 (*(f32 *)(_gpreg + -30112))
f32 func_00388340(f32 x) {
    f32 val = D_001D5310;
    __asm__ volatile("nop");
    return val * x;
}
/* localdecomp:end func_00388340 */

INCLUDE_ASM("asm/nonmatchings/text", func_00388350);

/* localdecomp:start func_00388378 */
register char *_gpreg __asm__("$28");
#define D_001D5314 (*(f32 *)(_gpreg + -30108))
f32 func_00388378(f32 x) {
    f32 val = D_001D5314;
    __asm__ volatile("nop");
    return val * x;
}
/* localdecomp:end func_00388378 */

/* localdecomp:start func_00388388 */
register char *_gpreg __asm__("$28");
#define D_001D5318 (*(f32 *)(_gpreg + -30104))
f32 func_00388388(f32 x) {
    f32 val = D_001D5318;
    __asm__ volatile("nop");
    return val * x;
}
/* localdecomp:end func_00388388 */

INCLUDE_ASM("asm/nonmatchings/text", func_00388398);

INCLUDE_ASM("asm/nonmatchings/text", func_003883C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003883F8);

INCLUDE_ASM("asm/nonmatchings/text", func_00388418);

INCLUDE_ASM("asm/nonmatchings/text", func_00388440);

INCLUDE_ASM("asm/nonmatchings/text", func_00388468);

INCLUDE_ASM("asm/nonmatchings/text", func_00388490);

INCLUDE_ASM("asm/nonmatchings/text", func_00388550);

INCLUDE_ASM("asm/nonmatchings/text", func_003885F0);

INCLUDE_ASM("asm/nonmatchings/text", func_00388618);

INCLUDE_ASM("asm/nonmatchings/text", func_00388648);

INCLUDE_ASM("asm/nonmatchings/text", func_00388680);

INCLUDE_ASM("asm/nonmatchings/text", func_00388698);

INCLUDE_ASM("asm/nonmatchings/text", func_003886B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003886C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003886E8);

INCLUDE_ASM("asm/nonmatchings/text", func_00388700);

INCLUDE_ASM("asm/nonmatchings/text", func_00388718);

INCLUDE_ASM("asm/nonmatchings/text", func_00388730);

INCLUDE_ASM("asm/nonmatchings/text", func_00388758);

INCLUDE_ASM("asm/nonmatchings/text", func_00388770);

INCLUDE_ASM("asm/nonmatchings/text", func_003887A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003887C8);

INCLUDE_ASM("asm/nonmatchings/text", func_00388800);

INCLUDE_ASM("asm/nonmatchings/text", func_00388830);

INCLUDE_ASM("asm/nonmatchings/text", func_00388880);

INCLUDE_ASM("asm/nonmatchings/text", func_003888C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003888F0);

INCLUDE_ASM("asm/nonmatchings/text", func_00388920);

INCLUDE_ASM("asm/nonmatchings/text", func_00388948);

INCLUDE_ASM("asm/nonmatchings/text", func_00388960);

INCLUDE_ASM("asm/nonmatchings/text", func_00388978);

INCLUDE_ASM("asm/nonmatchings/text", func_00388990);

INCLUDE_ASM("asm/nonmatchings/text", func_00388A28);

INCLUDE_ASM("asm/nonmatchings/text", func_00388B40);

INCLUDE_ASM("asm/nonmatchings/text", func_00388B68);

INCLUDE_ASM("asm/nonmatchings/text", func_00388B98);

INCLUDE_ASM("asm/nonmatchings/text", func_00388BD0);

INCLUDE_ASM("asm/nonmatchings/text", func_00388BF0);

INCLUDE_ASM("asm/nonmatchings/text", func_00388C10);

INCLUDE_ASM("asm/nonmatchings/text", func_00388E38);

INCLUDE_ASM("asm/nonmatchings/text", func_00388E58);

INCLUDE_ASM("asm/nonmatchings/text", func_00388E78);

INCLUDE_ASM("asm/nonmatchings/text", func_00388EB8);

INCLUDE_ASM("asm/nonmatchings/text", func_00388F08);

INCLUDE_ASM("asm/nonmatchings/text", func_00388F50);

INCLUDE_ASM("asm/nonmatchings/text", func_00388F90);

INCLUDE_ASM("asm/nonmatchings/text", func_00389018);

INCLUDE_ASM("asm/nonmatchings/text", func_003890D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003890F8);

INCLUDE_ASM("asm/nonmatchings/text", func_00389118);

INCLUDE_ASM("asm/nonmatchings/text", func_00389150);

INCLUDE_ASM("asm/nonmatchings/text", func_00389158);

INCLUDE_ASM("asm/nonmatchings/text", func_00389240);

INCLUDE_ASM("asm/nonmatchings/text", func_003892D8);

INCLUDE_ASM("asm/nonmatchings/text", func_00389330);

INCLUDE_ASM("asm/nonmatchings/text", func_00389380);

INCLUDE_ASM("asm/nonmatchings/text", func_003893C8);

INCLUDE_ASM("asm/nonmatchings/text", func_00389410);

INCLUDE_ASM("asm/nonmatchings/text", func_00389468);

INCLUDE_ASM("asm/nonmatchings/text", func_003894A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003894E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003895E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003895E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003896E8);

/* localdecomp:start func_003898C0 */
s32 func_003898C0(u8 *p, s32 off, s32 *out) {
    u8 *q = p + off;
    s32 r = 0;
    s32 b = q[0];
    *out = b;
    if (b & 0x80) {
        r = 1;
        *out = (((b & 0x7F) << 8) | q[1]) + 0x7F;
    }
    return r;
}
/* localdecomp:end func_003898C0 */

INCLUDE_ASM("asm/nonmatchings/text", func_00389900);

extern s32 D_001D9C48[];
register char *_gpreg __asm__("$28");
#define D_001D5B34 (*(s32 *)(_gpreg + -0x6d7c))
INCLUDE_ASM("asm/nonmatchings/text", func_00389908);

INCLUDE_ASM("asm/nonmatchings/text", func_00389920);

INCLUDE_ASM("asm/nonmatchings/text", func_00389998);

INCLUDE_ASM("asm/nonmatchings/text", func_003899B8);

/* localdecomp:start func_00389B90 */
extern u8 D_001D5B42;
void func_00389B90(s32 a) { D_001D5B42 = a; }
/* localdecomp:end func_00389B90 */

INCLUDE_ASM("asm/nonmatchings/text", func_00389B98);

INCLUDE_ASM("asm/nonmatchings/text", func_00389D18);

INCLUDE_ASM("asm/nonmatchings/text", func_00389FB8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038A848);

/* localdecomp:start func_0038B1B0 */
void func_0038B1B0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    p[4] = e;
    p[5] = f;
    p[8] = g;
    p[9] = h;
    p[6] = 0;
    p[7] = 0;
    p[10] = 0;
    p[11] = 0;
}
/* localdecomp:end func_0038B1B0 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038B1E8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038BB50);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C3C0);

/* localdecomp:start func_0038C450 */
extern void func_003899B8(void);

void func_0038C450(void) {
    func_003899B8();
}
/* localdecomp:end func_0038C450 */

/* localdecomp:start func_0038C470 */
extern void func_00389B90(s32 a0);

void func_0038C470(void) {
    func_00389B90(1);
}
/* localdecomp:end func_0038C470 */

/* localdecomp:start func_0038C490 */
extern void func_00389B90();
 
void func_0038C490(void) {
    func_00389B90(0);
}
/* localdecomp:end func_0038C490 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038C4B0);

/* localdecomp:start func_0038C4E8 */
extern void func_00389D18(void);

void func_0038C4E8(void) {
    func_00389D18();
}
/* localdecomp:end func_0038C4E8 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038C508);

/* localdecomp:start func_0038C510 */
extern void func_00389D18();
 
void func_0038C510(void) {
    func_00389D18();
}
/* localdecomp:end func_0038C510 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038C530);

/* localdecomp:start func_0038C538 */
extern void func_00389D18();
 
void func_0038C538(s32 a, s32 b, s32 c, f32 d) {
    func_00389D18();
}
/* localdecomp:end func_0038C538 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038C558);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C580);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C628);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C708);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C718);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C778);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C830);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C840);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C878);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C888);

/* localdecomp:start func_0038C8A8 */
extern void func_0038B1E8(s32, s32, s32, s32, unsigned long, s32, f32, f32);
void func_0038C8A8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g) {
    func_0038B1E8(a, b, c, d, 0x80000000, g, 1.0f, 1.0f);
}
/* localdecomp:end func_0038C8A8 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038C8D8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038C8F8);

/* localdecomp:start func_0038C980 */
extern void func_0038B1E8(s32, s32, s32, s32, unsigned long, s32, f32, f32);
void func_0038C980(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g) {
    func_0038B1E8(a, b, c, d, 0x80000000, g, 1.0f, 1.0f);
}
/* localdecomp:end func_0038C980 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038C9B0);

/* localdecomp:start func_0038C9B8 */
extern void func_0038B1E8(s32, s32, s32, s32, unsigned long, s32, f32, f32);
void func_0038C9B8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g, s32 h, f32 x) {
    func_0038B1E8(a, b, c, d, h, g, x, x);
}
/* localdecomp:end func_0038C9B8 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038C9D8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038CA08);

/* localdecomp:start func_0038CAB0 */
extern void func_003896E8();
 
void func_0038CAB0(void) {
    func_003896E8();
}
/* localdecomp:end func_0038CAB0 */

/* localdecomp:start func_0038CAD0 */
extern void func_0038C3C0();
 
void func_0038CAD0(void) {
    func_0038C3C0();
}
/* localdecomp:end func_0038CAD0 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038CAF0);

/* localdecomp:start func_0038CB60 */
extern s32 D_001D4D08[];
extern s32 D_001D4D0C[];
extern s32 D_001D4D10[];
extern s32 D_001D4D14[];
extern s32 D_001D4D18[];
extern s32 D_001D4D1C[];
extern s32 D_001D4CF8[];
void func_0038CB60(void) {
    *(unsigned long *)((u8 *)D_001D4CF8[0] + 0x18) = (long)D_001D4D08[0] | ((long)D_001D4D0C[0] << 12) | ((long)D_001D4D10[0] << 23) | ((long)D_001D4D14[0] << 27) | ((long)D_001D4D18[0] << 32) | ((long)D_001D4D1C[0] << 44);
}
/* localdecomp:end func_0038CB60 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038CBC8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038CBD0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038CC58);

INCLUDE_ASM("asm/nonmatchings/text", func_0038CC68);

INCLUDE_ASM("asm/nonmatchings/text", func_0038CE40);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DA28);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DA50);

/* localdecomp:start func_0038DA58 */
extern void func_12C4B0(s32);
extern s32 D_001D4CF8[];

void func_0038DA58(void) {
    func_12C4B0(D_001D4CF8[0]);
}
/* localdecomp:end func_0038DA58 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038DA80);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DB18);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DB98);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DC08);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DEB0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DF10);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E030);

/* localdecomp:start func_0038E1E0 */
extern s32 D_001D5C78;
s32 func_0038E1E0(void) { s32 v = D_001D5C78; if (v != 0) return v + 0x7090; return 0; }
/* localdecomp:end func_0038E1E0 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038E200);

/* localdecomp:start func_0038E248 */
typedef struct { s32 a, b; } E_38E;
typedef struct { u8 pad[8]; E_38E e[10]; s32 f58, f5C, f60, f64, f68; u8 f6C; } S_38E;
s32 func_0038E248(S_38E *p, s32 *a, s32 *b) {
    s32 i;
    if (p->f60 == 0) return 0;
    if (--p->f60 == 0) p->f6C = 0;
    *a = p->e[p->f5C].a;
    *b = p->e[p->f5C].b;
    p->e[p->f5C].a = -1;
    p->e[p->f5C].b = -1;
    i = p->f5C + 1;
    if (i == 10) i = 0;
    p->f5C = i;
    return 1;
}
/* localdecomp:end func_0038E248 */

/* localdecomp:start func_0038E2E8 */
s32 func_0038E2E8(S_38E *p, s32 v) {
    s32 i, n;
    if (p->f60 == 10 || p->f6C != 0) return 0;
    p->e[p->f58].a = v;
    p->e[p->f58].b = v >= 100;
    i = p->f58 + 1;
    n = p->f60 + 1;
    if (i == 10) i = 0;
    p->f60 = n;
    p->f58 = i;
    return 1;
}
/* localdecomp:end func_0038E2E8 */

/* localdecomp:start func_0038E360 */
extern void func_0038E200();
 
void func_0038E360(s32 *p) {
    func_0038E200();
}
/* localdecomp:end func_0038E360 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038E380);

/* localdecomp:start func_0038E410 */
extern void func_0038E380(s32 *);
extern void func_0038E360(s32 *);
void func_0038E410(s32 *p) {
    func_0038E380(p);
    *p = 0;
    func_0038E360(p);
}
/* localdecomp:end func_0038E410 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038E440);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E508);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E5B8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E688);

/* localdecomp:start func_0038E6B8 */
extern u8 D_001D551C;
void func_0038E6B8(void) {
    D_001D551C = 0;
}
/* localdecomp:end func_0038E6B8 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038E6C0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E6D0);

/* localdecomp:start func_0038E728 */
extern s32 D_001D5C90;
void func_0038E728(s32 a) {
    D_001D5C90 = a;
}
/* localdecomp:end func_0038E728 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038E730);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E788);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E798);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E8F8);

/* localdecomp:start func_0038E900 */
extern u32 D_001D5D50;
u32 func_0038E900(void) {
    u32 v = D_001D5D50;
    u32 r = 0;
    if (v <= 0x1CFFFF) r = (0x1D0000 - v) >> 2;
    return r;
}
/* localdecomp:end func_0038E900 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038E930);

INCLUDE_ASM("asm/nonmatchings/text", func_0038EA58);

INCLUDE_ASM("asm/nonmatchings/text", func_0038EA88);

INCLUDE_ASM("asm/nonmatchings/text", func_0038EB10);

INCLUDE_ASM("asm/nonmatchings/text", func_0038EC18);

INCLUDE_ASM("asm/nonmatchings/text", func_0038EC80);

INCLUDE_ASM("asm/nonmatchings/text", func_0038ED00);

INCLUDE_ASM("asm/nonmatchings/text", func_0038ED78);

INCLUDE_ASM("asm/nonmatchings/text", func_0038EDE8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038EE58);

INCLUDE_ASM("asm/nonmatchings/text", func_0038EFD0);

/* localdecomp:start func_0038F0C0 */
extern void func_0038EFD0(void *);
 
void func_0038F0C0(void *p) {
    *(s32 *)((u8 *)p + 0x7C) = 0xD2;
    *(s16 *)((u8 *)p + 0x48) = 0;
    *(s16 *)((u8 *)p + 0x4A) = 0;
    func_0038EFD0(p);
}
/* localdecomp:end func_0038F0C0 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038F0F0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038F2A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038F310);

INCLUDE_ASM("asm/nonmatchings/text", func_0038F3A0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038F3F8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038FDC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003906E8);

INCLUDE_ASM("asm/nonmatchings/text", func_00390730);

INCLUDE_ASM("asm/nonmatchings/text", func_00390C18);

INCLUDE_ASM("asm/nonmatchings/text", func_003919E0);

/* localdecomp:start func_00391B30 */
extern void func_0038EFD0(void *);
 
void func_00391B30(void *p) {
    *(s32 *)((u8 *)p + 0x7C) = 0x96;
    *(s32 *)((u8 *)p + 0x58) = 0x20;
    *(s32 *)((u8 *)p + 0x5C) = 0x20;
    func_0038EFD0(p);
}
/* localdecomp:end func_00391B30 */

/* localdecomp:start func_00391B60 */
s32 func_00391B60(void) {
    return 0;
}
/* localdecomp:end func_00391B60 */

INCLUDE_ASM("asm/nonmatchings/text", func_00391B68);

INCLUDE_ASM("asm/nonmatchings/text", func_00391B70);

INCLUDE_ASM("asm/nonmatchings/text", func_00391D08);

INCLUDE_ASM("asm/nonmatchings/text", func_00391E30);

INCLUDE_ASM("asm/nonmatchings/text", func_00391E78);

INCLUDE_ASM("asm/nonmatchings/text", func_00391FD8);

INCLUDE_ASM("asm/nonmatchings/text", func_00392108);

INCLUDE_ASM("asm/nonmatchings/text", func_003921D8);

INCLUDE_ASM("asm/nonmatchings/text", func_00392400);

INCLUDE_ASM("asm/nonmatchings/text", func_003925F0);

INCLUDE_ASM("asm/nonmatchings/text", func_00392878);

INCLUDE_ASM("asm/nonmatchings/text", func_00392A20);

INCLUDE_ASM("asm/nonmatchings/text", func_00392A40);

INCLUDE_ASM("asm/nonmatchings/text", func_00392DD8);

INCLUDE_ASM("asm/nonmatchings/text", func_00393120);

INCLUDE_ASM("asm/nonmatchings/text", func_00393290);

INCLUDE_ASM("asm/nonmatchings/text", func_00393360);

/* localdecomp:start func_00393370 */
extern u8 D_001D5EDC;
void func_00393370(void) { D_001D5EDC = 1; }
/* localdecomp:end func_00393370 */

INCLUDE_ASM("asm/nonmatchings/text", func_00393380);

INCLUDE_ASM("asm/nonmatchings/text", func_00393418);

/* localdecomp:start func_00393420 */
extern u8 D_001D5EDD;
void func_00393420(void) {
    D_001D5EDD = 0;
}
/* localdecomp:end func_00393420 */

INCLUDE_ASM("asm/nonmatchings/text", func_00393428);

/* localdecomp:start func_00393430 */
extern s32 D_001D5EE0;
void func_00393430(void) {
    if (D_001D5EE0 == 0) D_001D5EE0 = 1;
}
/* localdecomp:end func_00393430 */

/* localdecomp:start func_00393448 */
register char *_gpreg __asm__("$28");
#define D_001D5EE0 (*(s32 *)(_gpreg + -0x69d0))
s32 func_00393448(void) {
    return D_001D5EE0 == 3;
}
/* localdecomp:end func_00393448 */

INCLUDE_ASM("asm/nonmatchings/text", func_00393458);

INCLUDE_ASM("asm/nonmatchings/text", func_00393460);

INCLUDE_ASM("asm/nonmatchings/text", func_003934E8);

INCLUDE_ASM("asm/nonmatchings/text", func_00393550);

INCLUDE_ASM("asm/nonmatchings/text", func_00393580);

INCLUDE_ASM("asm/nonmatchings/text", func_003936A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003936A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003937C8);

INCLUDE_ASM("asm/nonmatchings/text", func_00393878);

INCLUDE_ASM("asm/nonmatchings/text", func_00393A18);

INCLUDE_ASM("asm/nonmatchings/text", func_00393C98);

INCLUDE_ASM("asm/nonmatchings/text", func_00393DB0);

INCLUDE_ASM("asm/nonmatchings/text", func_00393DC8);

INCLUDE_ASM("asm/nonmatchings/text", func_00393E90);

INCLUDE_ASM("asm/nonmatchings/text", func_00394060);

INCLUDE_ASM("asm/nonmatchings/text", func_00394300);

INCLUDE_ASM("asm/nonmatchings/text", func_00394368);

INCLUDE_ASM("asm/nonmatchings/text", func_00394660);

INCLUDE_ASM("asm/nonmatchings/text", func_003947B0);

INCLUDE_ASM("asm/nonmatchings/text", func_00394A20);

INCLUDE_ASM("asm/nonmatchings/text", func_00394B38);

/* localdecomp:start func_00394C18 */
void func_00394C18(u8 *d, u8 *s) {
    d[4] = s[0];
    d[5] = s[1];
    d[6] = s[2];
    d[7] = s[3];
    *(u8 **)d = s + *(s32 *)(s + 4);
    *(u8 **)(d + 0x20) = s + *(s32 *)(s + 8);
}
/* localdecomp:end func_00394C18 */

INCLUDE_ASM("asm/nonmatchings/text", func_00394C58);

INCLUDE_ASM("asm/nonmatchings/text", func_00394F78);

INCLUDE_ASM("asm/nonmatchings/text", func_00395088);

INCLUDE_ASM("asm/nonmatchings/text", func_00395090);

INCLUDE_ASM("asm/nonmatchings/text", func_00395358);

INCLUDE_ASM("asm/nonmatchings/text", func_00395360);

INCLUDE_ASM("asm/nonmatchings/text", func_003953E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003953F0);

INCLUDE_ASM("asm/nonmatchings/text", func_00395628);

INCLUDE_ASM("asm/nonmatchings/text", func_00395648);

INCLUDE_ASM("asm/nonmatchings/text", func_003958A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003958F0);

INCLUDE_ASM("asm/nonmatchings/text", func_00395958);

INCLUDE_ASM("asm/nonmatchings/text", func_003959A8);

INCLUDE_ASM("asm/nonmatchings/text", func_00395AC8);

INCLUDE_ASM("asm/nonmatchings/text", func_00395BC0);

INCLUDE_ASM("asm/nonmatchings/text", func_00395C48);

INCLUDE_ASM("asm/nonmatchings/text", func_00395E10);

INCLUDE_ASM("asm/nonmatchings/text", func_00395E18);

INCLUDE_ASM("asm/nonmatchings/text", func_00395EA8);

INCLUDE_ASM("asm/nonmatchings/text", func_00395EB8);

INCLUDE_ASM("asm/nonmatchings/text", func_00395FE0);

INCLUDE_ASM("asm/nonmatchings/text", func_00395FF0);

typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad1[0x150];
    s32 f164;
    s32 f168;
    u8 pad2[0x10];
    s32 f17c;
} S_142430;
extern S_142430 D_00142430;

extern s32 D_001D4CE8[];
/* localdecomp:start func_00396100 */
typedef struct { u8 pad[0x10]; s32 f10; u8 pad2[0x150]; s32 f164; s32 f168; u8 pad3[0x10]; s32 f17C; } S_142430x;
extern S_142430x D_142430;
extern s32 D_001D4CE8_g;
void func_00396100(void) {
    S_142430x *p = &D_142430;
    D_001D4CE8_g = 4;
    p->f17C = 0;
    p->f10 = 0;
}
/* localdecomp:end func_00396100 */

INCLUDE_ASM("asm/nonmatchings/text", func_00396120);

INCLUDE_ASM("asm/nonmatchings/text", func_00396248);

INCLUDE_ASM("asm/nonmatchings/text", func_00396298);

extern s32 D_001D4CE8[];
/* localdecomp:start func_003962C0 */

extern s32 D_001D4CE8_g;
void func_003962C0(void) {
    S_142430x *p = &D_142430;
    p->f164 = -1;
    D_001D4CE8_g = 6;
    p->f168 = -1;
}
/* localdecomp:end func_003962C0 */

extern s32 D_001D4CE8[];
/* localdecomp:start func_003962E8 */

extern s32 D_001D4CE8_g;
void func_003962E8(void) {
    S_142430x *p = &D_142430;
    p->f164 = -1;
    D_001D4CE8_g = 6;
    p->f168 = -1;
}
/* localdecomp:end func_003962E8 */

INCLUDE_ASM("asm/nonmatchings/text", func_00396310);

/* localdecomp:start func_00396378 */
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, rest:17; } F_4CEC;
extern F_4CEC D_001D4CEC_f;
extern s32 D_00142438[];
extern u8 D_001D5BDD;
extern s32 D_001D4CE8_g;
void func_00396378(void) {
    if (D_00142438[0] != 2) {
        D_001D4CE8_g = 4;
        return;
    }
    if (D_001D5BDD != 0 || (*(s32 *)&D_001D4CEC_f & 0x12)) D_001D4CE8_g = 8;
}
/* localdecomp:end func_00396378 */

INCLUDE_ASM("asm/nonmatchings/text", func_003963C8);

/* localdecomp:start func_00396458 */
extern S_142430x D_142430;
extern s32 D_001D4CE8_g;
void func_00396458(void) {
    S_142430x *p = &D_142430;
    p->f10 = 0;
    if (p->f164 < 0) {
        p->f168 = 0;
        p->f164 = 3;
    }
    D_001D4CE8_g = 10;
}
/* localdecomp:end func_00396458 */

INCLUDE_ASM("asm/nonmatchings/text", func_00396488);

INCLUDE_ASM("asm/nonmatchings/text", func_003964E8);

INCLUDE_ASM("asm/nonmatchings/text", func_00396538);

INCLUDE_ASM("asm/nonmatchings/text", func_00396590);

INCLUDE_ASM("asm/nonmatchings/text", func_00396628);

INCLUDE_ASM("asm/nonmatchings/text", func_00396680);

/* localdecomp:start func_00396780 */
extern s32 D_00142438[];
extern s32 D_001D4CE8_g;
extern s32 D_001D4CEC_g;
void func_00396780(void) {
    if (D_00142438[0] != 2) {
        D_001D4CE8_g = 4;
        return;
    }
    if (D_001D4CEC_g & 0x12) D_001D4CE8_g = 15;
}
/* localdecomp:end func_00396780 */

INCLUDE_ASM("asm/nonmatchings/text", func_003967C0);

INCLUDE_ASM("asm/nonmatchings/text", func_00396830);

INCLUDE_ASM("asm/nonmatchings/text", func_00396890);

INCLUDE_ASM("asm/nonmatchings/text", func_003968F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003969B8);

INCLUDE_ASM("asm/nonmatchings/text", func_00396A28);

extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];

/* localdecomp:start func_00396AE0 */
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];

void func_00396AE0(void) {
    if (!(D_001D4CEC[0] & 0x40)) D_001D4CE8[0] = 4;
}
/* localdecomp:end func_00396AE0 */

/* localdecomp:start func_00396B08 */
extern void (*D_001D6304)(void);
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];
void func_00396B08(void) {
    if (D_001D6304 != 0) {
        D_001D6304();
        D_001D6304 = 0;
    }
    if (!(D_001D4CEC[0] & 0x40)) D_001D4CE8[0] = 4;
}
/* localdecomp:end func_00396B08 */

extern s32 D_00142438[];
extern s32 D_001D4CE8[];
/* localdecomp:start func_00396B50 */
extern s32 D_00142438[];
extern s32 D_001D4CE8_g;
void func_00396B50(void) {
    if (D_00142438[0] != 2) D_001D4CE8_g = 4;
}
/* localdecomp:end func_00396B50 */

/* localdecomp:start func_00396B78 */
extern void (*D_001D6300)(void);
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];
void func_00396B78(void) {
    if (D_001D6300 != 0) {
        D_001D6300();
        D_001D6300 = 0;
    }
    if (!(D_001D4CEC[0] & 0x40)) D_001D4CE8[0] = 4;
}
/* localdecomp:end func_00396B78 */

INCLUDE_ASM("asm/nonmatchings/text", func_00396BC0);

extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];

/* localdecomp:start func_00396C20 */
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];

void func_00396C20(void) {
    if (!(D_001D4CEC[0] & 0x40)) D_001D4CE8[0] = 4;
}
/* localdecomp:end func_00396C20 */

INCLUDE_ASM("asm/nonmatchings/text", func_00396C48);

INCLUDE_ASM("asm/nonmatchings/text", func_00396CE8);

INCLUDE_ASM("asm/nonmatchings/text", func_00396D70);

INCLUDE_ASM("asm/nonmatchings/text", func_00396DC8);

INCLUDE_ASM("asm/nonmatchings/text", func_00396E20);

INCLUDE_ASM("asm/nonmatchings/text", func_00396E80);

INCLUDE_ASM("asm/nonmatchings/text", func_00396F18);

/* localdecomp:start func_00396FA0 */
extern void func_00396F18();
extern s32 D_001D4CEC_g;
void func_00396FA0(void *a, s32 b, void *c) {
    func_00396F18(a, b, c);
    D_001D4CEC_g |= 0x4000;
}
/* localdecomp:end func_00396FA0 */

INCLUDE_ASM("asm/nonmatchings/text", func_00396FD0);

/* localdecomp:start func_00397058 */
extern s32 D_001D4CEC_g;
extern s32 D_001D62F0;
s32 func_00397058(u32 a) {
    if (a >= 4) return 0;
    D_001D62F0 = a;
    D_001D4CEC_g |= 0x1000;
    return 1;
}
/* localdecomp:end func_00397058 */

extern s32 D_001D4CEC[];
extern s32 D_00142578[];
register char *_gpreg __asm__("$28");
#define D_001D4CEC_gp (*(s32 *)(_gpreg + -0x7bc4))
INCLUDE_ASM("asm/nonmatchings/text", func_00397080);

extern s32 D_001D4CEC[];
register char *_gpreg __asm__("$28");
#define D_001D4CEC_gp (*(s32 *)(_gpreg + -0x7bc4))
INCLUDE_ASM("asm/nonmatchings/text", func_003970A0);

/* localdecomp:start func_003970B8 */
extern u8 D_001DA028_g;
u8 func_003970B8(void) {
    u8 v = D_001DA028_g;
    D_001DA028_g = 0;
    return v;
}
/* localdecomp:end func_003970B8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003970C8);

/* localdecomp:start func_003970D0 */
void func_003970D0(s16 v) {
    u8 *b = (u8 *)&D_00142430;
    s32 t = *(s32 *)(b + 0x164);
    *(s16 *)(b + 0x18) = v;
    *(s32 *)(b + 0x148) = 0;
    if (t < 0) {
        *(s32 *)(b + 0x168) = 0;
        *(s32 *)(b + 0x164) = 0xD;
    }
}
/* localdecomp:end func_003970D0 */

INCLUDE_ASM("asm/nonmatchings/text", func_00397100);

extern s32 D_001D4CEC[];
register char *_gpreg __asm__("$28");
#define D_001D4CEC_gp (*(s32 *)(_gpreg + -0x7bc4))
/* localdecomp:start func_003971E8 */
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, rest:17; } F_4CEC;
extern F_4CEC D_001D4CEC_f;
void func_003971E8(void) {
    D_001D4CEC_f.b5 = 1;
}
/* localdecomp:end func_003971E8 */

/* localdecomp:start func_00397200 */
extern F_4CEC D_001D4CEC_f;
void func_00397200(void) {
    D_001D4CEC_f.b1 = 0;
    D_001D4CEC_f.b2 = 0;
    D_001D4CEC_f.b12 = 0;
    D_001D4CEC_f.b3 = 0;
    D_001D4CEC_f.b4 = 0;
}
/* localdecomp:end func_00397200 */

extern s32 D_001D4CEC[];
register char *_gpreg __asm__("$28");
#define D_001D4CEC_gp (*(s32 *)(_gpreg + -0x7bc4))
/* localdecomp:start func_00397238 */
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, rest:17; } F_4CEC;
extern F_4CEC D_001D4CEC_f;
void func_00397238(void) {
    D_001D4CEC_f.b5 = 0;
    D_001D4CEC_f.b13 = 0;
}
/* localdecomp:end func_00397238 */

extern s32 D_001D4CEC[];
/* localdecomp:start func_00397258 */
extern s32 D_001D4CEC[];

s32 func_00397258(void) {
    return (D_001D4CEC[0] >> 6) & 1;
}
/* localdecomp:end func_00397258 */

extern s32 D_001D4CEC[];
register char *_gpreg __asm__("$28");
#define D_001D4CEC_gp (*(s32 *)(_gpreg + -0x7bc4))
/* localdecomp:start func_00397270 */
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, rest:17; } F_4CEC;
extern F_4CEC D_001D4CEC_f;
void func_00397270(void) {
    D_001D4CEC_f.b6 = 0;
}
/* localdecomp:end func_00397270 */

INCLUDE_ASM("asm/nonmatchings/text", func_00397288);

INCLUDE_ASM("asm/nonmatchings/text", func_003972A0);

INCLUDE_ASM("asm/nonmatchings/text", func_00397380);

INCLUDE_ASM("asm/nonmatchings/text", func_00397490);

INCLUDE_ASM("asm/nonmatchings/text", func_00399660);

INCLUDE_ASM("asm/nonmatchings/text", func_00399708);

/* localdecomp:start func_00399710 */
s32 func_00399710(s32 *p) {
    s32 n = 8;
    if (p[0] != 0) {
        do {
            n += 8;
            n += p[1];
            p += 4;
            n = (n + 3) & ~3;
        } while (p[0] != 0);
    }
    return n + 8;
}
/* localdecomp:end func_00399710 */

INCLUDE_ASM("asm/nonmatchings/text", func_00399748);

INCLUDE_ASM("asm/nonmatchings/text", func_003997F0);

INCLUDE_ASM("asm/nonmatchings/text", func_00399830);

INCLUDE_ASM("asm/nonmatchings/text", func_00399948);

INCLUDE_ASM("asm/nonmatchings/text", func_00399A00);

INCLUDE_ASM("asm/nonmatchings/text", func_00399C90);

INCLUDE_ASM("asm/nonmatchings/text", func_00399F40);

/* localdecomp:start func_00399F70 */
extern u8 D_001D6580;
u8 func_00399F70(void) { return D_001D6580; }
/* localdecomp:end func_00399F70 */

/* localdecomp:start func_00399F78 */
extern u8 D_001D6580;
void func_00399F78(void) {
    D_001D6580 = 0;
}
/* localdecomp:end func_00399F78 */

/* localdecomp:start func_00399F80 */
extern u8 D_001D6580;
void func_00399F80(void) {
    D_001D6580 = 1;
}
/* localdecomp:end func_00399F80 */

INCLUDE_ASM("asm/nonmatchings/text", func_00399F90);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A040);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A130);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A170);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A3B0);

/* localdecomp:start func_0039A518 */
s32 func_0039A518(u8 *p) {
    return *p == 0;
}
/* localdecomp:end func_0039A518 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039A528);

/* localdecomp:start func_0039A550 */
extern u8 D_00142734[];

s32 func_0039A550(s32 k) {
    if ((u32)(k - 0x1F) < 5) {
        k -= 0x1E;
        if ((u32)k < 8) {
            return (D_00142734[0] >> k) & 1;
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_0039A550 */

/* localdecomp:start func_0039A590 */
extern u8 D_00142734[];
s32 func_0039A590(void) {
    s32 v = D_00142734[0] & 0x1e;
    return v == 0x1e;
}
/* localdecomp:end func_0039A590 */

/* localdecomp:start func_0039A5A8 */
extern func_0039A550(s32);
void func_0039A5A8(void) {
    func_0039A550(0x21);
}
/* localdecomp:end func_0039A5A8 */

/* localdecomp:start func_0039A5C8 */
extern func_0039A550(s32);
void func_0039A5C8(void) {
    func_0039A550(0x22);
}
/* localdecomp:end func_0039A5C8 */

/* localdecomp:start func_0039A5E8 */
extern u8 D_001D5550[];
extern s32 func_0039A5C8(void);
s32 func_0039A5E8(void) {
    s32 r = 0;
    if (D_001D5550[0] != 0) r = func_0039A5C8() != 0;
    return r;
}
/* localdecomp:end func_0039A5E8 */

/* localdecomp:start func_0039A620 */
extern func_0039A550(s32);
void func_0039A620(void) {
    func_0039A550(0x20);
}
/* localdecomp:end func_0039A620 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039A640);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A6E0);

/* localdecomp:start func_0039A720 */
extern u8 D_001427B2[];
 
s32 func_0039A720(void) {
    return D_001427B2[0] & 1;
}
/* localdecomp:end func_0039A720 */

/* localdecomp:start func_0039A730 */
extern u8 D_001427B2[];
 
s32 func_0039A730(void) {
    return D_001427B2[0] & 2;
}
/* localdecomp:end func_0039A730 */

/* localdecomp:start func_0039A740 */
typedef struct { u8 pad[0x25]; u8 f25; u8 pad2[0x0d]; u8 f33; } S_1426E0;
extern S_1426E0 D_001426E0;
s32 func_0039A740(void) {
    return D_001426E0.f25 != 0 && D_001426E0.f33 != 0;
}
/* localdecomp:end func_0039A740 */

/* localdecomp:start func_0039A768 */
extern s32 D_00142C4C[];
s32 func_0039A768(void) {
    s32 v = D_00142C4C[0] & 0x4000;
    return v != 0;
}
/* localdecomp:end func_0039A768 */

/* localdecomp:start func_0039A780 */
extern u16 D_001A8E74[];
extern u8 D_00142CBF[];
s32 func_0039A780(void) {
    if (D_001A8E74[0] != 0) {
        return D_00142CBF[0] == 0;
    }
    return 0;
}
/* localdecomp:end func_0039A780 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039A7A8);

/* localdecomp:start func_0039A7B0 */
s32 func_0039A7B0(u8 *p, s32 a, s32 b, s32 i) {
    for (; i < 0x60; i++) {
        if (p[i * 2] - 1 == a && p[i * 2 + 1] == b) return i;
    }
    return -1;
}
/* localdecomp:end func_0039A7B0 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039A7F8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A980);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A9E0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039AA80);

INCLUDE_ASM("asm/nonmatchings/text", func_0039AAF0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039ABA0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039ABB0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039AE08);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B0E8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B0F8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B198);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B200);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B240);

/* 0x39B2DC is 4 bytes past an 8-byte boundary: GCC pads every C function to 8,
   so this can't be a C function (it's likely leftover bytes after the previous one). */
INCLUDE_ASM("asm/nonmatchings/text", func_0039B2DC);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B2E8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B4E8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B628);

INCLUDE_ASM("asm/nonmatchings/text", func_0039B760);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BA30);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BA50);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BBC8);

/* localdecomp:start func_0039BC00 */
void func_0039BC00(void) {
    __asm__ volatile (
        "lui $3, 0x8\n"
        "addi $3, $3, 0x200\n"
        "mtc0 $3, $25\n"
    );
}
/* localdecomp:end func_0039BC00 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039BC18);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BC40);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BC70);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BC80);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BC90);

/* localdecomp:start func_0039BCA0 */
void func_0039BCA0(void) {
    __asm__ volatile (
        "sync.p\n"
        "mfc0 $8, $24\n"
        "lui $9, 0x7fff\n"
        "ori $9, $9, 0xffff\n"
        "and $8, $8, $9\n"
        "mtc0 $8, $24\n"
        "sync.p\n"
    );
}
/* localdecomp:end func_0039BCA0 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039BCC8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BD08);

/* localdecomp:start func_0039BD40 */
s32 func_0039BD40(void) {
}
/* localdecomp:end func_0039BD40 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039BD48);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BE90);

/* localdecomp:start func_0039BEA0 */
extern s32 D_001D6D98;
void func_0039BEA0(s32 a) {
    D_001D6D98 = a;
}
/* localdecomp:end func_0039BEA0 */

extern s32 D_001D5B90[];
/* localdecomp:start func_0039BEA8 */
extern s32 D_001D5B90[];

s32 func_0039BEA8(s32 a0) {
    return D_001D5B90[0] == a0;
}
/* localdecomp:end func_0039BEA8 */

extern s32 D_001D5B90[];
extern s32 D_001D5B94[];
extern s32 D_001D4CEC[];
extern u8  D_001D5B78[];
extern s32 D_001DA050[];
extern s32 D_001A7430[];
extern s32 D_001D6DA4[];
extern s32 D_001D6D9C[];
extern s32 D_001D6DA0[];
extern s32 D_001D6DA8[];

extern s32 D_001D5B90[];
extern s32 D_001D5B94[];
extern s32 D_001D4CEC[];
extern u8  D_001D5B78[];
extern s32 D_001DA050[];
extern s32 D_001A7430[];
extern s32 D_001D6DA4[];
extern s32 D_001D6D9C[];
extern s32 D_001D6DA0[];
extern s32 D_001D6DA8[];
INCLUDE_ASM("asm/nonmatchings/text", func_0039BEC0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BF98);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C020);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C028);

/* localdecomp:start func_0039C158 */
void func_0039C158(s32 a0, long a1) {
    s32 *p = (s32 *)a1;
    if (p != 0) {
        *p = a0;
    }
}
/* localdecomp:end func_0039C158 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039C170);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C1C8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C210);

extern void func_0013CF40(s32);
/* localdecomp:start func_0039C2A8 */
extern void func_13CF40(void (*)());
extern void func_0039D770();
 
void func_0039C2A8(void) {
    func_13CF40(func_0039D770);
}
/* localdecomp:end func_0039C2A8 */

/* localdecomp:start func_0039C2C8 */
void func_0039C2C8(s32 a0, s32 *a1) {
    if (a0 >= 0x1770) {
        *a1 = 6;
    } else {
        *a1 = 2;
    }
}
/* localdecomp:end func_0039C2C8 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039C2E8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C548);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C710);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C7B0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C8A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039C9A0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039CAB8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039CBA0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039CC70);

typedef struct {
    u8 pad0[0x24];
    s32 f24;
    s32 f28;
    u8 pad1[0x24];
    u16 f50;
    u8 pad2[0x78 - 0x52];
    u16 f78;
    u8 pad3[0xc8 - 0x7a];
    u16 fc8;
} S_1CCFD0;
extern S_1CCFD0 D_001CCFD0;

/* localdecomp:start func_0039CC78 */
void func_0039CC78(void) {
    D_001CCFD0.f50 = 4;
    D_001CCFD0.fc8 = 4;
    D_001CCFD0.f78 = 4;
}
/* localdecomp:end func_0039CC78 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039CC98);

INCLUDE_ASM("asm/nonmatchings/text", func_0039CEA8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D4D0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D510);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D5A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D5F8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D668);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D6C8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D770);

/* localdecomp:start func_0039D800 */
void func_0039D800(s32 a, long l) {
    s16 *p = (s16 *)l;
    if (p != 0 && a != 0 && p[5] == 2) {
        p[5] = 3;
    }
}
/* localdecomp:end func_0039D800 */

/* localdecomp:start func_0039D830 */
typedef struct { u8 pad[0x48]; s16 f48, f4A, f4C; u8 pad2[0x46]; s32 f94; s16 f98, f9A, f9C; u8 pad3[0x12]; s32 fB0; } S_1CCFD0b;
extern S_1CCFD0b D_1CCFD0;
extern u8 D_001A30B0[];
extern void func_0039C548(s32, s32, s32, s32 *, s32);
void func_0039D830(s32 a, long l) {
    u8 *p = (u8 *)(s32)l;
    s32 i;
    if (p == 0) return;
    i = *(s32 *)(p + 0x20);
    *(s32 *)p = a;
    if (i >= 0) { u8 *e = D_001A30B0 + (i << 7); *(s32 *)(e + 0xC0) = a; };
    if (a != 0) {
        if (*(s16 *)(p + 0xA) == 1) *(s16 *)(p + 0xA) = 2;
    } else {
        func_0039C548(D_1CCFD0.f98, D_1CCFD0.f9C, D_1CCFD0.fB0, &D_1CCFD0.f94, D_1CCFD0.f9A);
    }
}
/* localdecomp:end func_0039D830 */

/* localdecomp:start func_0039D8B0 */
extern s32 D_001D6DB8;
extern void func_0039C7B0(s32, s32, s32);
void func_0039D8B0(s32 a, long l) {
    u8 *p = (u8 *)(s32)l;
    if (p == 0) return;
    *(s32 *)p = a;
    if (a != 0) {
        if (*(s16 *)(p + 0xA) == 1) *(s16 *)(p + 0xA) = 2;
    } else if (D_001D6DB8 == 0) {
        func_0039C7B0(D_1CCFD0.f48, D_1CCFD0.f4C, D_1CCFD0.f4A);
    } else {
        *(s16 *)(p + 0xA) = 0;
    }
}
/* localdecomp:end func_0039D8B0 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039D920);

INCLUDE_ASM("asm/nonmatchings/text", func_0039D970);

/* localdecomp:start func_0039D9C8 */
void func_0039D9C8(s32 a, long l) {
    u8 *p = (u8 *)(s32)l;
    if (p == 0) return;
    *(s32 *)p = a;
    if (a != 0) {
        if (*(s16 *)(p + 0xA) == 1) *(s16 *)(p + 0xA) = 8;
    } else {
        *(s16 *)(p + 0xA) = 0;
    }
}
/* localdecomp:end func_0039D9C8 */

/* localdecomp:start func_0039DA08 */
void func_0039DA08(s32 a, long l) {
    u8 *p = (u8 *)(s32)l;
    if (p == 0) return;
    if (*(u32 *)p == 0xFFFFFFFF) {
        *(s32 *)p = a;
        if (a == 0) *(s16 *)(p + 0xA) = 7;
    }
}
/* localdecomp:end func_0039DA08 */

/* localdecomp:start func_0039DA48 */
void func_0039DA48(s32 a0, long a1) {
    s32 *p = (s32 *)a1;
    if (p != 0) {
        p[5] = a0;
    }
}
/* localdecomp:end func_0039DA48 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039DA60);

INCLUDE_ASM("asm/nonmatchings/text", func_0039DAD0);

extern s32 D_001D6DE8[];
/* localdecomp:start func_0039DAE0 */
typedef struct {
    u8 pad0[0x24];
    s32 f24;
    s32 f28;
    u8 pad1[0x24];
    u16 f50;
    u8 pad2[0x78 - 0x52];
    u16 f78;
    u8 pad3[0xc8 - 0x7a];
    u16 fc8;
} S_1CCFD0;
extern S_1CCFD0 D_001CCFD0;
extern s32 D_001D6DE8;
void func_0039DAE0(s32 a0, s32 a1) {
    if (D_001D6DE8 == 0) {
        D_001CCFD0.f24 = a0;
        D_001CCFD0.f28 = a1;
    }
}
/* localdecomp:end func_0039DAE0 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039DB00);

INCLUDE_ASM("asm/nonmatchings/text", func_0039DB38);

INCLUDE_ASM("asm/nonmatchings/text", func_0039E4A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039E4B0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039E8E0);

/* localdecomp:start func_0039E928 */
typedef struct { u8 pad[0xA4]; u8 arr[1]; } S_143950;
extern S_143950 D_143950;
extern u8 D_001A71C4[];
s32 func_0039E928(s32 a, s32 i) {
    if (D_143950.arr[i] != 0 && D_001A71C4[0] == 0) {
        switch (a) {
        case 0x40: return 0x44;
        case 4: return 1;
        case 8: return 2;
        }
    }
    return a;
}
/* localdecomp:end func_0039E928 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039E9A0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039EA58);

INCLUDE_ASM("asm/nonmatchings/text", func_0039EA60);

INCLUDE_ASM("asm/nonmatchings/text", func_0039EB38);

INCLUDE_ASM("asm/nonmatchings/text", func_0039EB98);

INCLUDE_ASM("asm/nonmatchings/text", func_0039ED50);

/* localdecomp:start func_0039EE40 */
extern s32 D_001685EC[];
extern void func_0013CFC0(s32, s32);
void func_0039EE40(void) {
    func_0013CFC0(2, D_001685EC[0]);
}
/* localdecomp:end func_0039EE40 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039EE68);

INCLUDE_ASM("asm/nonmatchings/text", func_0039FAF8);

/* localdecomp:start func_0039FB08 */
extern u8 D_1A30B0[];
void func_0039FB08(u32 i) {
    if (i < 52) {
        u8 *e = D_1A30B0 + i * 128;
        u8 s = e[0xD0];
        if (s == 7) {
            *(s32 *)(e + 0xDC) = 0;
            *(s32 *)(e + 0x100) = 0;
            e[0xD0] = 0;
            return;
        }
        if (s != 0 && s != 6) e[0xD0] = 4;
    }
}
/* localdecomp:end func_0039FB08 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039FB60);

INCLUDE_ASM("asm/nonmatchings/text", func_0039FBD8);

INCLUDE_ASM("asm/nonmatchings/text", func_0039FE80);

INCLUDE_ASM("asm/nonmatchings/text", func_0039FF28);

INCLUDE_ASM("asm/nonmatchings/text", func_0039FFB8);

/* localdecomp:start func_0039FFC8 */
extern u8 D_001A30B0[];
s32 func_0039FFC8(u32 a0, s32 a1) {
    if (a0 < 0x34) {
        u8 *p = (u8 *)&D_001A30B0[0] + a0 * 0x80;
        *(u16 *)(p + 0xcc) = a1;
    }
    return 1;
}
/* localdecomp:end func_0039FFC8 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039FFF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A0010);

/* localdecomp:start func_003A00D0 */
void func_003A00D0(s32 a0, long a1) {
    s32 *p = (s32 *)a1;
    if (p != 0) {
        *p = a0;
    }
}
/* localdecomp:end func_003A00D0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A00E8);

/* localdecomp:start func_003A0130 */
void func_003A0130(s32 a, long l) {
    u8 *p = (u8 *)l;
    if (p == 0) return;
    if (p[0x13] != *(s32 *)(p + 0x4C)) return;
    *(s32 *)p = a;
    if (a == 0) {
        *(s32 *)(p + 0x1C) = 0;
        *(s32 *)(p + 0x40) = 0;
        p[0x10] = 0;
    }
    p[0x13] = 0;
}
/* localdecomp:end func_003A0130 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A0170);

INCLUDE_ASM("asm/nonmatchings/text", func_003A01F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A0200);

INCLUDE_ASM("asm/nonmatchings/text", func_003A0268);

INCLUDE_ASM("asm/nonmatchings/text", func_003A0280);

INCLUDE_ASM("asm/nonmatchings/text", func_003A02D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A04A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A0D20);

INCLUDE_ASM("asm/nonmatchings/text", func_003A0D58);

INCLUDE_ASM("asm/nonmatchings/text", func_003A0EB0);

/* localdecomp:start func_003A1340 */
extern void func_003A0EB0(void *, s32, s32);
void func_003A1340(void *p) {
    func_003A0EB0(p, 1, 0);
    func_003A0EB0(p, 2, 0);
}
/* localdecomp:end func_003A1340 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A1380);

INCLUDE_ASM("asm/nonmatchings/text", func_003A13B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A1438);

INCLUDE_ASM("asm/nonmatchings/text", func_003A1870);

/* localdecomp:start func_003A1AA0 */
extern s32 D_001D6EF8[2];
s32 func_003A1AA0(s32 k) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (D_001D6EF8[i] == k) return i;
    }
    return -1;
}
/* localdecomp:end func_003A1AA0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A1AD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A1E48);

INCLUDE_ASM("asm/nonmatchings/text", func_003A2028);

INCLUDE_ASM("asm/nonmatchings/text", func_003A21C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A2460);

INCLUDE_ASM("asm/nonmatchings/text", func_003A26D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A2BC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A2C18);

INCLUDE_ASM("asm/nonmatchings/text", func_003A2DF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A2E40);

INCLUDE_ASM("asm/nonmatchings/text", func_003A2EE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3028);

INCLUDE_ASM("asm/nonmatchings/text", func_003A30D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A30E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3128);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3220);

/* localdecomp:start func_003A3288 */
extern s32 D_001D8000;
extern s32 D_001D8004;
extern s32 D_001D8008;
extern s32 D_001D800C;
extern s32 D_001D8010;
extern void func_00388490(s32, s32);
void func_003A3288(s32 a, s32 b, s32 c, s32 d) {
    a = (a + 63) & ~63;
    c = (c + 63) & ~63;
    D_001D8008 = c;
    D_001D800C = d;
    D_001D8000 = a;
    D_001D8004 = b;
    D_001D8010 = 0;
    func_00388490(a, b);
    func_00388490(D_001D8008, D_001D800C);
}
/* localdecomp:end func_003A3288 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A32E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3368);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3430);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3508);

INCLUDE_ASM("asm/nonmatchings/text", func_003A35C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3A00);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3A40);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3B00);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3B50);

/* localdecomp:start func_003A3BB8 */
extern Struct227600 D_00227600;
extern s32 D_001DA0C8[];
extern u32 *D_001DA0D0_g;
extern s32 D_001DA0DC_g;
extern void func_003A3B50(void);
void func_003A3BB8(void) {
    u8 *p = (u8 *)&D_00227600;
    D_001DA0C8[0] = *(s32 *)(p + 0xC);
    D_001DA0C8[1] = *(s32 *)(p + 0x10);
    D_001DA0D0_g = *(u32 **)(p + 0xC);
    D_001DA0DC_g = 0;
    func_003A3B50();
}
/* localdecomp:end func_003A3BB8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A3C00);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3C80);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3DA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3DE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3E38);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3E40);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3EE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3EF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3FA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A3FB0);

/* localdecomp:start func_003A40C8 */
extern u32 *D_001DA0D0_g;
extern u8 D_001D7830[];
void func_003A40C8(void) {
    D_001DA0D0_g[0] = 0x30000003;
    D_001DA0D0_g[1] = (u32)D_001D7830;
    D_001DA0D0_g[2] = 0;
    D_001DA0D0_g[3] = 0x50000003;
    D_001DA0D0_g += 4;
}
/* localdecomp:end func_003A40C8 */

/* localdecomp:start func_003A4128 */
extern u32 *D_001DA0D0_g;
extern u8 D_001D7300[];
void func_003A4128(void) {
    D_001DA0D0_g[0] = 0x30000003;
    D_001DA0D0_g[1] = (u32)D_001D7300;
    D_001DA0D0_g[2] = 0;
    D_001DA0D0_g[3] = 0x50000003;
    D_001DA0D0_g += 4;
}
/* localdecomp:end func_003A4128 */

/* localdecomp:start func_003A4188 */
extern u32 *D_001DA0D0_g;
extern u8 D_001D7330[];
void func_003A4188(void) {
    D_001DA0D0_g[0] = 0x30000004;
    D_001DA0D0_g[1] = (u32)D_001D7330;
    D_001DA0D0_g[2] = 0;
    D_001DA0D0_g[3] = 0x50000004;
    D_001DA0D0_g += 4;
}
/* localdecomp:end func_003A4188 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A41E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A41F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A42D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A42E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A44F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A4580);

INCLUDE_ASM("asm/nonmatchings/text", func_003A45F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A46F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A4720);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003A4768);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003A4A78);

INCLUDE_ASM("asm/nonmatchings/text", func_003A4DC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A4E70);

/* localdecomp:start func_003A53B0 */
extern s32 func_003ECDB8();
extern u8 D_001D8190[];
void func_003A53B0(u8 *p, s32 f) {
    *(void **)(p + 4) = D_001D8190;
    if (f & 1) func_003ECDB8(p);
}
/* localdecomp:end func_003A53B0 */

extern void func_00116F98(s32 *a0, s32 a1, s32 *a2);
INCLUDE_ASM("asm/nonmatchings/text", func_003A53E0);

extern char D_001D8160[];
extern void func_003A53B0(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003A5458);

INCLUDE_ASM("asm/nonmatchings/text", func_003A54A0);

/* localdecomp:start func_003A5608 */
extern u8 D_001D8178[];

void func_003A5608(void *a0) {
    register void *dest __asm__("$2");    // $v0 ($2)
    register s32 val __asm__("$3");       // $v1 ($3)

    // Force the exact 64-bit move instruction (daddu) at offset 0.
    // This generates the exact machine code bytes for 0x0080102d.
    __asm__ volatile("daddu %0, %1, $0" : "=r"(dest) : "r"(a0));

    val = (s32)&D_001D8178;

    __asm__ volatile("" : : "r"(dest), "r"(val));

    *(s32 *)dest = val;
}
/* localdecomp:end func_003A5608 */

/* localdecomp:start func_003A5620 */
extern u8 D_001D8178[];
extern s32 func_003ECDB8();
void func_003A5620(void **p, s32 f) { *p = D_001D8178; if (f & 1) func_003ECDB8(p); }
/* localdecomp:end func_003A5620 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A5650);

INCLUDE_ASM("asm/nonmatchings/text", func_003A56C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5750);

INCLUDE_ASM("asm/nonmatchings/text", func_003A57A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5800);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5870);

/* localdecomp:start func_003A58A0 */
extern void func_003A53B0(void);
void func_003A58A0(void) {
    func_003A53B0();
}
/* localdecomp:end func_003A58A0 */

extern s32 D_001D8118[];
extern void func_003A5620();
/* localdecomp:start func_003A58C0 */
extern s32 D_001D8118[2];
extern void func_003A5620(void **p, s32 f);
void func_003A58C0(void **p, s32 f) {
    *p = D_001D8118;
    func_003A5620(p, f);
}
/* localdecomp:end func_003A58C0 */

extern s32 D_001D8100[];
extern void func_003A5620();
/* localdecomp:start func_003A58E0 */
extern s32 D_001D8100[2];
extern void func_003A5620(void **p, s32 f);
void func_003A58E0(void **p, s32 f) {
    *p = D_001D8100;
    func_003A5620(p, f);
}
/* localdecomp:end func_003A58E0 */

/* localdecomp:start func_003A5900 */
extern s32 D_001DA0F0;
s32 func_003A5900(void) {
    return D_001DA0F0;
}
/* localdecomp:end func_003A5900 */

/* localdecomp:start func_003A5908 */
s32 func_003A5908(void *p) {
    return *(s32 *)((u8 *)p + 0x4);
}
/* localdecomp:end func_003A5908 */

/* localdecomp:start func_003A5910 */
s32 func_003A5910(void *p) {
    return *(s32 *)((u8 *)p + 0xC);
}
/* localdecomp:end func_003A5910 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A5918);

/* localdecomp:start func_003A5928 */
void func_003A5928(void *a0, f32 a1, f32 a2, f32 a3, f32 a4) {
    *(f32 *)((u8 *)(*(void **)a0) + 0) = a1;
    *(f32 *)((u8 *)(*(void **)a0) + 4) = a2;
    *(f32 *)((u8 *)(*(void **)a0) + 8) = a3;
    *(f32 *)((u8 *)(*(void **)a0) + 0xc) = a4;
}
/* localdecomp:end func_003A5928 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A5950);

/* localdecomp:start func_003A5958 */
void func_003A5958(void *a0, s32 a1) {
    s32 *v0 = *(s32 **)((u8 *)a0 + 0x10);
    if (a1 != 0) {
        *(f32 *)v0 = 1.0f;
    } else {
        *v0 = 0;
    }
}
/* localdecomp:end func_003A5958 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A5978);

INCLUDE_ASM("asm/nonmatchings/text", func_003A59E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A59E8);

/* localdecomp:start func_003A5A50 */
void func_003A5A50(void *a0, f32 a1, f32 a2, f32 a3, f32 a4) {
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 0) = a1;
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 4) = a2;
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 8) = a3;
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 0xc) = a4;
}
/* localdecomp:end func_003A5A50 */

extern s32 D_001D8218[];
/* localdecomp:start func_003A5A78 */
extern s32 D_001D8218;
void func_003A5A78(void *a0) {
    *(s32 *)((u8 *)a0 + 0x24) = (s32)&D_001D8218;
}
/* localdecomp:end func_003A5A78 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A5A90);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5BB8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5BC0);

/* localdecomp:start func_003A5C70 */
extern void func_003A5A78(u8 *);
extern u8 D_001D8200[];
u8 *func_003A5C70(u8 *p) {
    func_003A5A78(p);
    *(u8 **)(p + 0x24) = D_001D8200;
    return p;
}
/* localdecomp:end func_003A5C70 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A5CA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5D58);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5DD8);

/* localdecomp:start func_003A5DE8 */
s32 func_003A5DE8(void *p) {
    return *(s32 *)((u8 *)p + 0x2C);
}
/* localdecomp:end func_003A5DE8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A5DF0);

/* localdecomp:start func_003A5E80 */
extern s32 func_003A6830(u8 *, s32);
void func_003A5E80(u8 *p, u8 *a, s32 b) {
    *(s32 *)(p + 0x34) = func_003A6830(a, b);
}
/* localdecomp:end func_003A5E80 */

/* localdecomp:start func_003A5EB0 */
void func_003A5EB0(void *p, f32 value) {
    **(f32 **)((u8 *)p + 0x2C) = value;
}
/* localdecomp:end func_003A5EB0 */

/* localdecomp:start func_003A5EC0 */
extern void func_003A5A78(u8 *);
extern u8 D_001D81B8[];
u8 *func_003A5EC0(u8 *p) {
    func_003A5A78(p);
    *(u8 **)(p + 0x24) = D_001D81B8;
    return p;
}
/* localdecomp:end func_003A5EC0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A5EF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A5F58);

/* localdecomp:start func_003A5F88 */
void func_003A5F88(void *a0, s32 a1, s32 a2) {
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 0) = a1;
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 4) = a2;
}
/* localdecomp:end func_003A5F88 */

/* localdecomp:start func_003A5FA0 */
void func_003A5FA0(void *a0, s32 a1, s32 a2) {
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 8) = a1;
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 0xc) = a2;
}
/* localdecomp:end func_003A5FA0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A5FB8);

/* localdecomp:start func_003A6190 */
extern void func_003A5A78(u8 *);
extern u8 D_001D81E8[];
u8 *func_003A6190(u8 *p) {
    func_003A5A78(p);
    *(u8 **)(p + 0x24) = D_001D81E8;
    return p;
}
/* localdecomp:end func_003A6190 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A61C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A61D0);

/* localdecomp:start func_003A6278 */
s32 func_003A6278(void *p) {
    return *(s32 *)((u8 *)p + 0x28);
}
/* localdecomp:end func_003A6278 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A6280);

INCLUDE_ASM("asm/nonmatchings/text", func_003A62E8);

/* localdecomp:start func_003A63E0 */
void func_003A63E0(u8 *p, s32 a, s32 b) {
    (*(f32 **)(p + 0x28))[0] = a;
    (*(f32 **)(p + 0x28))[1] = b;
}
/* localdecomp:end func_003A63E0 */

/* localdecomp:start func_003A6410 */
extern void func_003A5A78(u8 *);
extern s32 D_001D81D0[];
u8 *func_003A6410(u8 *p) {
    func_003A5A78(p);
    *(u8 **)(p + 0x24) = (u8 *)D_001D81D0;
    return p;
}
/* localdecomp:end func_003A6410 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A6448);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6450);

extern s32 D_001D81D0[];
extern void func_003A5BC0(void *);
/* localdecomp:start func_003A64B0 */
extern s32 D_001D81D0[];
extern void func_003A5BC0(void *);

void func_003A64B0(void *p) {
    *(s32 **)((u8 *)p + 0x24) = &D_001D81D0[0];
    func_003A5BC0(p);
}
/* localdecomp:end func_003A64B0 */

/* localdecomp:start func_003A64D8 */
void func_003A64D8(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x3C) = value;
}
/* localdecomp:end func_003A64D8 */

/* localdecomp:start func_003A64E0 */
void func_003A64E0(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x38) = value;
}
/* localdecomp:end func_003A64E0 */

/* localdecomp:start func_003A64E8 */
extern void func_0038C538(s32, s32, s32, f32);
void func_003A64E8(u8 *p) {
    func_0038C538(*(s32 *)(p + 0x38), -1, *(s32 *)(p + 0x28), **(f32 **)(p + 4));
}
/* localdecomp:end func_003A64E8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A6518);

/* localdecomp:start func_003A6638 */
void func_003A6638(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x34) = value;
}
/* localdecomp:end func_003A6638 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A6640);

/* localdecomp:start func_003A6768 */
void func_003A6768(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x2C) = value;
}
/* localdecomp:end func_003A6768 */

/* localdecomp:start func_003A6770 */
void func_003A6770(void *a0, s32 a1) {
    f32 result;
    void *p;
    __asm__ volatile (
        "mtc1 %2, %0\n"
        "nop\n"
        "cvt.s.w %0, %0\n"
        "lw %1, 4(%3)\n"
        : "=f"(result), "=r"(p)
        : "r"(a1), "r"(a0)
    );
    *(f32 *)((u8 *)p + 4) = result;
}
/* localdecomp:end func_003A6770 */

/* localdecomp:start func_003A6788 */
void func_003A6788(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x38) = value;
}
/* localdecomp:end func_003A6788 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A6790);

/* localdecomp:start func_003A6830 */
typedef struct { s32 k, v; } E_3A6830;
s32 func_003A6830(u8 *p, s32 k) {
    s32 n = *(s32 *)(p + 0x18);
    E_3A6830 *e = (E_3A6830 *)(p + 0x1C);
    s32 i;
    s32 r = 0;
    for (i = 0; i < n; i++) {
        if (e[i].k == k) {
            r = e[i].v;
            break;
        }
    }
    return r;
}
/* localdecomp:end func_003A6830 */

/* localdecomp:start func_003A6880 */
void *func_003A6880(void *p) {
    return p;
}
/* localdecomp:end func_003A6880 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A6888);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6908);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6910);

/* localdecomp:start func_003A69A0 */
void func_003A69A0(void *a0, void *a1) {
    *(s32 *)a1 = *(s32 *)((u8 *)a0 + 0x14);
    *(s32 *)((u8 *)a0 + 0x14) = (s32)a1;
    *(s32 *)((u8 *)a0 + 0x10) = *(s32 *)((u8 *)a0 + 0x10) - 1;
}
/* localdecomp:end func_003A69A0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A69C0);

/* localdecomp:start func_003A69C8 */
extern u8 *func_003A5C70(u8 *);
u8 *func_003A69C8(u8 *p) {
    func_003A5C70(p + 0x10);
    func_003A5C70(p + 0x4C);
    return p;
}
/* localdecomp:end func_003A69C8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A6A00);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6C08);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6C30);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7090);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7380);

/* localdecomp:start func_003A7398 */
s32 func_003A7398(void) {
}
/* localdecomp:end func_003A7398 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A73A0);

/* localdecomp:start func_003A7610 */
s32 func_003A7610(void) {
}
/* localdecomp:end func_003A7610 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A7618);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7690);

/* localdecomp:start func_003A7CC8 */
s32 func_003A7CC8(void) {
}
/* localdecomp:end func_003A7CC8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A7CD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7D80);

/* localdecomp:start func_003A7E48 */
void *func_003A7E48(u8 *p) {
    s32 i;
    s32 *q = (s32 *)(p + 0x30);
    for (i = 3; i != -1; i--) {
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
        q += 4;
    }
    return p;
}
/* localdecomp:end func_003A7E48 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A7E80);

INCLUDE_ASM("asm/nonmatchings/text", func_003A7F38);

/* localdecomp:start func_003A7F40 */
void func_003A7F40(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x2C) = value;
}
/* localdecomp:end func_003A7F40 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A7F48);

/* localdecomp:start func_003A7F58 */
typedef struct {
    char pad_0[0x18];   /* Offset 0x00 down to 0x18 */
    f32 float_field;    /* Offset 0x18 - Targeted by lwc1/swc1 */
    char pad_1C[0xC];   /* Padding from 0x1C to 0x28 */
    char byte_flag;     /* Offset 0x28 - Targeted by sb $v0, 0x28($a0) */
} InitContext;

void func_003A7F58(InitContext* ctx) {
    // 0: lui $at, 0x3f80
    // 4: mtc1 $at, $f1
    register f32 constant_one __asm__("$f1") = 1.0f;

    // FENCE 1: Blocks 'li $v0, 1' from climbing to offset 0:
    __asm__ __volatile__ ("");

    // 8: li $v0, 1
    ctx->byte_flag = 1;

    // c: lwc1 $f0, 0x18($a0)
    (void)((volatile InitContext*)ctx)->float_field;

    // MEMORY CLOBBER FENCE:
    // This tells ee-gcc that all previous memory actions (the lwc1 load) must be 
    // completely processed and finalized before any subsequent memory instructions 
    // are evaluated. This forces 'sb' perfectly down to offset 10:!
    __asm__ __volatile__ ("" : : : "memory");

    // 18: swc1 $f1, 0x18($a0)
    ctx->float_field = constant_one;
}
/* localdecomp:end func_003A7F58 */

/* localdecomp:start func_003A7F78 */
void func_003A7F78(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x80) = value;
}
/* localdecomp:end func_003A7F78 */

/* localdecomp:start func_003A7F80 */
u8 func_003A7F80(void *p, u8 value) {
    u8 old = *((u8 *)p + 0x28);
    *((u8 *)p + 0x28) = value;
    return old;
}
/* localdecomp:end func_003A7F80 */

/* localdecomp:start func_003A7F90 */
typedef struct { u8 pad[0x30]; f32 m[4][4]; f32 v[4]; } S_3A7F90;
void func_003A7F90(S_3A7F90 *p, s32 i, f32 a, f32 b, f32 c, f32 d, f32 e) {
    p->m[i][0] = b;
    p->m[i][1] = c;
    p->m[i][2] = d;
    p->m[i][3] = e;
    p->v[i] = a;
}
/* localdecomp:end func_003A7F90 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A7FC8);

/* localdecomp:start func_003A7FE0 */
void func_003A7FE0(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x84) = value;
}
/* localdecomp:end func_003A7FE0 */

/* localdecomp:start func_003A7FE8 */
void func_003A7FE8(u8 *p, s32 a) {
    *(s32 *)(p + 0x1C) = a;
    if (p[0x28] == 0) {
        if (a == 1) *(f32 *)(p + 0x18) = 0.0f;
        else *(f32 *)(p + 0x18) = 1.0f;
        p[0x28] = 1;
    }
}
/* localdecomp:end func_003A7FE8 */

/* localdecomp:start func_003A8028 */
void func_003A8028(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x20) = value;
}
/* localdecomp:end func_003A8028 */

/* localdecomp:start func_003A8030 */
void func_003A8030(void *p, f32 value) {
    *(f32 *)((u8 *)p + 0x24) = value;
}
/* localdecomp:end func_003A8030 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A8038);

INCLUDE_ASM("asm/nonmatchings/text", func_003A8060);

INCLUDE_ASM("asm/nonmatchings/text", func_003A8228);

INCLUDE_ASM("asm/nonmatchings/text", func_003A8230);

INCLUDE_ASM("asm/nonmatchings/text", func_003A95A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9698);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9758);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9768);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9890);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9AB0);

/* localdecomp:start func_003A9AC0 */
extern void func_003A7618(void *);
 
void func_003A9AC0(void *p, s32 i) {
    func_003A7618((u8 *)p + (i * 0x230 + 0x4610));
}
/* localdecomp:end func_003A9AC0 */

/* localdecomp:start func_003A9AE8 */
extern void func_003A7CD0(void *);
 
void func_003A9AE8(void *p, s32 i) {
    func_003A7CD0((u8 *)p + (i * 0x230 + 0x4610));
}
/* localdecomp:end func_003A9AE8 */

extern void *func_003A6880(void *);
extern void func_003A9768(void *);
extern void func_00121760(void *, void *);
extern void func_0039D668(void *, s32, s32);
extern void func_003A6888(void *, s32, void *, s32);
extern void func_0011F0A0(s32);
extern void func_0039D6C8(s32);
extern void func_003A6790(void *);
extern void func_003A9890(void *, void *, void *);
extern s32 D_001D5C78;
extern u8 D_00160C40[];
INCLUDE_ASM("asm/nonmatchings/text", func_003A9B10);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9CE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9CF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9DE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9E00);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9E60);

INCLUDE_ASM("asm/nonmatchings/text", func_003A9EF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AA080);

INCLUDE_ASM("asm/nonmatchings/text", func_003AA0B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AA278);

INCLUDE_ASM("asm/nonmatchings/text", func_003AA290);

INCLUDE_ASM("asm/nonmatchings/text", func_003AA2D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AA2E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AA4B0);

/* localdecomp:start func_003AA7E0 */
// Declare the external game function target matching address 0x0011ECD0
extern void func_0011ECD0(s32 parameter);

// Signature must be void to eliminate the implicit return zero instruction (0x102d)
void func_003AA7E0(void) {
    // Calling this function with 1 triggers the 'li $a0, 1' optimization pass, 
    // which naturally slides directly into the jal branch delay slot at offset c:
    func_0011ECD0(1);
}
/* localdecomp:end func_003AA7E0 */

/* localdecomp:start func_003AA800 */
extern s32 func_003AAE00();
extern s32 D_001DA138[];

void func_003AA800(void) {
    func_003AAE00(D_001DA138[0]);
}
/* localdecomp:end func_003AA800 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AA828);

INCLUDE_ASM("asm/nonmatchings/text", func_003AAA00);

/* localdecomp:start func_003AAA98 */
s32 func_003AAA98(void) {
}
/* localdecomp:end func_003AAA98 */

/* localdecomp:start func_003AAAA0 */
extern void func_003AAE60(s32 *);
extern s32 D_001DA138[];

void func_003AAAA0(void) {
    func_003AAE60((s32 *)D_001DA138[0]);
}
/* localdecomp:end func_003AAAA0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AAAC8);

/* localdecomp:start func_003AAB60 */
extern void func_13D0F8();
 
s32 func_003AAB60(void) {
    func_13D0F8();
    return 1;
}
/* localdecomp:end func_003AAB60 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AAB80);

INCLUDE_ASM("asm/nonmatchings/text", func_003AAB88);

/* localdecomp:start func_003AAC28 */
extern void func_0013D0C0(s32 *);
void func_003AAC28(s32 *p) {
    func_0013D0C0(p);
    p[0] = 0;
    p[0x30 / 4] = 0;
    p[0x38 / 4] = 0;
    p[0x3C / 4] = 0;
    p[0x44 / 4] = 0;
    p[0x50 / 4] = 0;
    p[0x58 / 4] = 0;
    p[0x5C / 4] = 0;
}
/* localdecomp:end func_003AAC28 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AAC70);

INCLUDE_ASM("asm/nonmatchings/text", func_003AAD40);

/* localdecomp:start func_003AAE00 */
s32 func_003AAE00(u8 *p) {
    switch (*(s32 *)(p + 4)) {
    case 4:
    case 2:
        return *(s32 *)(p + 0x50) >= *(s32 *)(p + 0x4C);
    case 3:
        return *(s32 *)(p + 0x50) >= 0x1000;
    default:
        return 1;
    }
}
/* localdecomp:end func_003AAE00 */

/* localdecomp:start func_003AAE60 */
extern s32 func_003AB608(void);
extern void func_003AB220(s32 *);
extern void func_003AB3A8(s32 *);
void func_003AAE60(s32 *p) {
    if (p[0] != 0) {
        s32 t = p[1];
        if (t == 4) func_003AB608();
        else if (t == 2) func_003AB220(p);
        else if (t == 3) func_003AB3A8(p);
    }
}
/* localdecomp:end func_003AAE60 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AAEC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AAF88);

INCLUDE_ASM("asm/nonmatchings/text", func_003AB100);

INCLUDE_ASM("asm/nonmatchings/text", func_003AB180);

INCLUDE_ASM("asm/nonmatchings/text", func_003AB220);

INCLUDE_ASM("asm/nonmatchings/text", func_003AB3A8);

/* localdecomp:start func_003AB608 */
s32 func_003AB608(void) {
}
/* localdecomp:end func_003AB608 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AB610);

INCLUDE_ASM("asm/nonmatchings/text", func_003AB7B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AB9A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AB9E8);

/* localdecomp:start func_003ABA38 */
extern s32 D_001DA150[];

void func_003ABA38(void) {
    D_001DA150[0] = 0;
}
/* localdecomp:end func_003ABA38 */

INCLUDE_ASM("asm/nonmatchings/text", func_003ABA48);

INCLUDE_ASM("asm/nonmatchings/text", func_003ABB60);

INCLUDE_ASM("asm/nonmatchings/text", func_003ABC30);

/* localdecomp:start func_003ABD60 */
void func_003ABD60(void *a0) {
    u8 *p = (u8 *)a0 + 0x50000;
    *(s32 *)(p + 8) = 0x50000;
    *(s32 *)(p + 0) = 0;
    *(s32 *)(p + 4) = 0;
}
/* localdecomp:end func_003ABD60 */

/* localdecomp:start func_003ABD78 */
s32 func_003ABD78(void) {
}
/* localdecomp:end func_003ABD78 */

/* localdecomp:start func_003ABD80 */
s32 func_003ABD80(u8 *p, void **out) {
    u8 *q = p + 0x50000;
    s32 n = *(s32 *)(q + 8) - *(s32 *)(q + 4);
    if (n != 0) {
        *out = p + *(s32 *)q;
    }
    return n;
}
/* localdecomp:end func_003ABD80 */

/* localdecomp:start func_003ABDB0 */
typedef struct { s32 a, b, c; } R_3ABDB0;
void func_003ABDB0(u8 *p, s32 n) {
    R_3ABDB0 *r = (R_3ABDB0 *)(p + 0x50000);
    s32 m = r->c - r->b;
    if (n < m) m = n;
    r->b += m;
    r->a = (r->a + m) % r->c;
}
/* localdecomp:end func_003ABDB0 */

/* localdecomp:start func_003ABDF0 */
typedef struct { s32 a, b, c; } R_3ABDF0;
s32 func_003ABDF0(u8 *p, u8 **out) {
    R_3ABDF0 *r = (R_3ABDF0 *)(p + 0x50000);
    if (r->b != 0) *out = p + (r->a - r->b + r->c) % r->c;
    return r->b;
}
/* localdecomp:end func_003ABDF0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003ABE30);

/* localdecomp:start func_003ABE58 */
extern s32 D_001D87E0;
s32 func_003ABE58(s32 *p, s32 b, s32 c) { D_001D87E0 = 0; p[2] = b; p[0] = c; return 1; }
/* localdecomp:end func_003ABE58 */

/* localdecomp:start func_003ABE70 */
extern void func_13CEB0();
extern void func_13CDF0(s32);
 
s32 func_003ABE70(void) {
    func_13CEB0();
    func_13CDF0(0);
    return 1;
}
/* localdecomp:end func_003ABE70 */

INCLUDE_ASM("asm/nonmatchings/text", func_003ABE98);

INCLUDE_ASM("asm/nonmatchings/text", func_003ABF88);

INCLUDE_ASM("asm/nonmatchings/text", func_003ABFD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AC040);

/* localdecomp:start func_003AC0B0 */
void func_003AC0B0(unsigned long *p, unsigned long a, unsigned long b, unsigned long c) {
    *p = (a << 32) | ((b << 32) >> 4) | ((c << 32) >> 32);
}
/* localdecomp:end func_003AC0B0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AC0D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AC150);

INCLUDE_ASM("asm/nonmatchings/text", func_003AC2B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AC3A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AC3F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AC5E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AC6F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003ACA00);

/* localdecomp:start func_003ACA58 */
extern void func_0011EE60(s32);
extern void func_0011EE40(s32);
s32 func_003ACA58(u8 *p) {
    s32 r;
    func_0011EE60(*(s32 *)(p + 0x40));
    r = (*(s32 *)(p + 0x10) << 11) + *(s32 *)(p + 0x14);
    func_0011EE40(*(s32 *)(p + 0x40));
    return r;
}
/* localdecomp:end func_003ACA58 */

INCLUDE_ASM("asm/nonmatchings/text", func_003ACAA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003ACB00);

INCLUDE_ASM("asm/nonmatchings/text", func_003ACC30);

INCLUDE_ASM("asm/nonmatchings/text", func_003ACD38);

INCLUDE_ASM("asm/nonmatchings/text", func_003ACED0);

INCLUDE_ASM("asm/nonmatchings/text", func_003ACFD0);

/* localdecomp:start func_003ACFD8 */
extern void func_139E50();
 
s32 func_003ACFD8(void) {
    func_139E50();
    return 1;
}
/* localdecomp:end func_003ACFD8 */

/* localdecomp:start func_003ACFF8 */
s32 func_003ACFF8(s32 arg0) {
    func_003AC2B0(arg0 + 0x48);
}
/* localdecomp:end func_003ACFF8 */

/* localdecomp:start func_003AD018 */
s32 func_003AD018(s32 arg0) {
    func_003AC3A0(arg0 + 0x48);
}
/* localdecomp:end func_003AD018 */

/* localdecomp:start func_003AD038 */
void func_003AD038(void *p) {
    *(s32 *)((u8 *)p + 0xA8) = 0;
}
/* localdecomp:end func_003AD038 */

/* localdecomp:start func_003AD040 */
extern void func_003ACA00(u8 *);
extern void func_00135C00(u8 *);
s32 func_003AD040(u8 *p) {
    func_003ACA00(p + 0x48);
    func_00135C00(p);
    return 1;
}
/* localdecomp:end func_003AD040 */

/* localdecomp:start func_003AD078 */
void func_003AD078(void *a0) {
    *(s32 *)((u8 *)a0 + 168) = 1;
}
/* localdecomp:end func_003AD078 */

/* localdecomp:start func_003AD088 */
s32 func_003AD088(void *p) {
    return *(s32 *)((u8 *)p + 0xA8);
}
/* localdecomp:end func_003AD088 */

/* localdecomp:start func_003AD090 */
s32 func_003AD090(void *a0, s32 a1) {
    s32 old = *(s32 *)((u8 *)a0 + 168);
    *(s32 *)((u8 *)a0 + 168) = a1;
    return old;
}
/* localdecomp:end func_003AD090 */

/* localdecomp:start func_003AD0A0 */
typedef struct { unsigned long a, b; s32 c, d; } S_3AD0A0;
extern u8 *D_001DA134[];
extern void func_003ACC30(u8 *, S_3AD0A0 *);
void func_003AD0A0(u8 *p, unsigned long a, unsigned long b, s32 c, s32 d) {
    S_3AD0A0 s;
    s.a = a;
    s.b = b;
    s.c = c - *(s32 *)(p + 0x48);
    s.d = d;
    func_003ACC30(D_001DA134[0] + 0x48, &s);
}
/* localdecomp:end func_003AD0A0 */

/* localdecomp:start func_003AD0E0 */
s32 func_003AD0E0(s32 arg0) {
    func_003ACA58(arg0 + 0x48);
}
/* localdecomp:end func_003AD0E0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AD100);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD108);

/* localdecomp:start func_003AD1D8 */
extern s32 func_00135CF0(void *);
s32 func_003AD1D8(void *p) {
    s32 r = 0;
    if (func_003AD0E0(p) == 0) r = func_00135CF0(p) != 0;
    return r;
}
/* localdecomp:end func_003AD1D8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AD220);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD288);

/* localdecomp:start func_003AD430 */
extern void func_11AF48(void *, s32);
extern u8 D_001D8878[];
 
s32 func_003AD430(s32 a0, void *p) {
    func_11AF48(D_001D8878, *(s32 *)((u8 *)p + 0x4));
    return 1;
}
/* localdecomp:end func_003AD430 */

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

INCLUDE_ASM("asm/nonmatchings/text", func_003AD520);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD650);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003AD6D8);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003AD798);

/* localdecomp:start func_003AD7F8 */
void func_003AD7F8(volatile s32 *p) {
    if (p[3] > 0) {
        p[3]--;
    }
}
/* localdecomp:end func_003AD7F8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AD818);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD820);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD8A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AD8A8);

/* localdecomp:start func_003ADAA8 */
extern void *func_003E16B8(void);
extern void func_003E14A8(void *);
extern u8 D_001DA9B8[];
 
void func_003ADAA8(void) {
    void *x = D_001DA9B8;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_003E16B8();
    }
    func_003E14A8(x);
}
/* localdecomp:end func_003ADAA8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003ADAE0);

/* localdecomp:start func_003ADB40 */
extern u8 D_001DA9B8[];
extern void *func_003E16B8(void);
extern void func_003E1548(void *);
 
void func_003ADB40(void) {
    void *x = D_001DA9B8;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_003E16B8();
    }
    func_003E1548(x);
}
/* localdecomp:end func_003ADB40 */

/* localdecomp:start func_003ADB78 */
extern u8 D_001DA9B8[];
extern void *func_003E16B8(void);
extern void func_003E15D8(void *);

void func_003ADB78(void) {
    void *x = D_001DA9B8;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_003E16B8();
    }
    func_003E15D8(x);
}
/* localdecomp:end func_003ADB78 */

INCLUDE_ASM("asm/nonmatchings/text", func_003ADBB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003ADC68);

extern s32 D_001D8888;
extern s32 D_001D888C;
/* localdecomp:start func_003ADC70 */
extern s32 D_001D8888;
extern s32 D_001D888C;
void func_003ADC70(s32 a) { D_001D8888 = a; D_001D888C = 0; }
/* localdecomp:end func_003ADC70 */

/* localdecomp:start func_003ADC80 */
extern void *D_001D8890;
void func_003ADC80(void *a) {
    D_001D8890 = a;
}
/* localdecomp:end func_003ADC80 */

/* localdecomp:start func_003ADC88 */
extern void *D_001D8890;
extern void func_003ADCB0(void *, s32);
void func_003ADC88(void) {
    if (D_001D8890 != 0) func_003ADCB0(D_001D8890, 0);
}
/* localdecomp:end func_003ADC88 */

INCLUDE_ASM("asm/nonmatchings/text", func_003ADCB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003ADD30);

INCLUDE_ASM("asm/nonmatchings/text", func_003ADDD0);

/* localdecomp:start func_003ADE68 */
extern s32 D_001D888C;
extern void func_00396F18();
extern void func_003ADC88();
extern s32 func_0039BEC0(s32, s32, s32, s32, u8 *);
extern void func_003AE430(void);
void func_003ADE68(void) {
    switch (D_001D888C) {
    case 0:
        func_00396F18(func_003ADC88, 0, 0);
    case 1:
        func_0039BEC0(4, 1, 1, 0, 0);
        D_001D888C++;
        break;
    case 2:
        func_003AE430();
        break;
    }
}
/* localdecomp:end func_003ADE68 */

/* localdecomp:start func_003ADEF8 */
extern s32 D_001D888C;
extern void func_00396FA0();
extern void func_003ADC88();
extern s32 func_0039BEC0(s32, s32, s32, s32, u8 *);
extern void func_003AE430(void);
void func_003ADEF8(void) {
    switch (D_001D888C) {
    case 0:
        func_00396FA0(func_003ADC88, 0, 0);
    case 1:
        func_0039BEC0(4, 1, 1, 0, 0);
        D_001D888C++;
        break;
    case 2:
        func_003AE430();
        break;
    }
}
/* localdecomp:end func_003ADEF8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003ADF88);

/* localdecomp:start func_003AE068 */
void func_003AE068(void) {
    u8 *b = (u8 *)&D_00142430;
    s32 t = *(s32 *)(b + 0x164);
    *(s16 *)(b + 0x18) = 0;
    *(s32 *)(b + 0x148) = 0;
    if (t < 0) {
        *(s32 *)(b + 0x168) = 0;
        *(s32 *)(b + 0x164) = 0xD;
    }
}
/* localdecomp:end func_003AE068 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AE098);

INCLUDE_ASM("asm/nonmatchings/text", func_003AE120);

INCLUDE_ASM("asm/nonmatchings/text", func_003AE1A8);

/* localdecomp:start func_003AE240 */
extern s32 D_001D888C;
extern s32 D_001D8898;
extern void func_00396FD0();
extern void func_003AE068();
extern void func_003AE120();
extern void func_003AE438(void);
extern void func_003AE8A8(void);
extern void func_003AE430(void);
void func_003AE240(void) {
    switch (D_001D888C) {
    case 0:
        func_00396FD0(func_003AE068, 0, func_003AE120);
        func_003AE438();
        D_001D8898 = 30;
        D_001D888C++;
        break;
    case 1:
        func_003AE438();
        { s32 t = D_001D8898; if (t > 0) { t--; D_001D8898 = t; } D_001D8898 = t; if (t == 0) func_003AE8A8(); }
        break;
    case 2:
        func_003AE430();
        break;
    }
}
/* localdecomp:end func_003AE240 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AE300);

INCLUDE_ASM("asm/nonmatchings/text", func_003AE368);

/* localdecomp:start func_003AE430 */
extern s32 D_001D8888;
void func_003AE430(void) {
    D_001D8888 = 0;
}
/* localdecomp:end func_003AE430 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AE438);

INCLUDE_ASM("asm/nonmatchings/text", func_003AE8A8);

/* localdecomp:start func_003AECA0 */
void func_003AECA0(void *p, s32 a) {
    void *q = *(void **)((u8 *)p + 0x4);
    ((void (*)(void *, s32, s32))*(void **)((u8 *)q + 0x1C))(p, a, 0);
}
/* localdecomp:end func_003AECA0 */

/* localdecomp:start func_003AECC8 */
extern s32 func_00392108(s32, s32);
s32 func_003AECC8(u8 *p, s32 a, s32 b) {
    s32 r = func_00392108(a, b);
    *(s32 *)(p + 8) = r;
    return r != 0;
}
/* localdecomp:end func_003AECC8 */

/* localdecomp:start func_003AED00 */
s32 func_003AED00(void *p) {
    return *(s32 *)((u8 *)p + 0x8);
}
/* localdecomp:end func_003AED00 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AED08);

INCLUDE_ASM("asm/nonmatchings/text", func_003AED40);

INCLUDE_ASM("asm/nonmatchings/text", func_003AEDC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AEDF8);

/* localdecomp:start func_003AEE80 */
extern u8 D_001D8928[];
void **func_003AEE80(void **p) { p[0] = (void *)1; p[1] = D_001D8928; p[2] = 0; p[3] = 0; p[4] = 0; p[5] = 0; p[6] = 0; p[7] = 0; return p; }
/* localdecomp:end func_003AEE80 */

/* localdecomp:start func_003AEEB8 */
s32 func_003AEEB8(s32 *p) {
    *p = 8;
    return 1;
}
/* localdecomp:end func_003AEEB8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AEEC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003AEF70);

/* localdecomp:start func_003AEFB0 */
s32 func_003AEFB0(s32 *arg0) {
    s32 val = arg0[4]; // offset 0x10 (4 * 4 bytes)
    
    if (val != 0) {
        return val;
    }
    
    return arg0[3]; // offset 0x0C (3 * 4 bytes)
}
/* localdecomp:end func_003AEFB0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AEFD0);

/* localdecomp:start func_003AF0A0 */
extern u8 D_001D8908[];
void **func_003AF0A0(void **p) { p[0] = (void *)1; p[1] = D_001D8908; p[2] = 0; p[3] = 0; p[4] = 0; return p; }
/* localdecomp:end func_003AF0A0 */

/* localdecomp:start func_003AF0C8 */
s32 func_003AF0C8(void) {
    return 1;
}
/* localdecomp:end func_003AF0C8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AF0D0);

/* localdecomp:start func_003AF120 */
s32 func_003AF120(s32 *arg0) {
    if (arg0[4] != 0) {
        return arg0[4];
    }
    return arg0[3];
}
/* localdecomp:end func_003AF120 */

/* localdecomp:start func_003AF140 */
s32 func_003AF140(void) {
    return 1;
}
/* localdecomp:end func_003AF140 */

/* localdecomp:start func_003AF148 */
s32 func_003AF148(void) {
    return 2;
}
/* localdecomp:end func_003AF148 */

/* localdecomp:start func_003AF150 */
s32 func_003AF150(void) {
    return 0;
}
/* localdecomp:end func_003AF150 */

/* localdecomp:start func_003AF158 */
s32 func_003AF158(void) {
    return 1;
}
/* localdecomp:end func_003AF158 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AF160);

/* localdecomp:start func_003AF170 */
s32 func_003AF170(void) {
    return 1;
}
/* localdecomp:end func_003AF170 */

/* localdecomp:start func_003AF178 */
s32 func_003AF178(void) {
    return 0;
}
/* localdecomp:end func_003AF178 */

/* localdecomp:start func_003AF180 */
s32 func_003AF180(void) {
    return 0;
}
/* localdecomp:end func_003AF180 */

/* localdecomp:start func_003AF188 */
s32 func_003AF188(void) {
    return 0;
}
/* localdecomp:end func_003AF188 */

/* localdecomp:start func_003AF190 */
s32 func_003AF190(void) {
    return 1;
}
/* localdecomp:end func_003AF190 */

/* localdecomp:start func_003AF198 */
extern void func_003934E8(s32, s32);
 
void func_003AF198(void) {
    func_003934E8(0, 0);
}
/* localdecomp:end func_003AF198 */

/* localdecomp:start func_003AF1B8 */
extern void func_003B62D0(s32);
extern void func_003ADC80(void *);
extern void func_003B1028(s32);
extern s32 func_003B2AA0(void);
extern void func_003E2E60(s32);
extern void *func_003AFA18();
extern void func_003E1AA8(void *p);
extern u8 D_0023CB70[];
void func_003AF1B8(void) {
    func_003B62D0(1);
    func_003ADC80(D_0023CB70);
    func_003B1028(2);
    func_003E2E60(func_003B2AA0());
    func_003E1AA8(func_003AFA18());
}
/* localdecomp:end func_003AF1B8 */

/* localdecomp:start func_003AF208 */
extern void func_003B62D0(s32);
extern void func_003B1028(s32);
extern s32 func_003B2AA0(void);
extern void func_003E2E60(s32);
extern void *func_003AFA18();
extern void func_003E1AA8(void *p);
void func_003AF208(void) {
    func_003B1028(1);
    func_003B62D0(1);
    func_003E2E60(func_003B2AA0());
    func_003E1AA8(func_003AFA18());
}
/* localdecomp:end func_003AF208 */

/* localdecomp:start func_003AF250 */
extern s32 func_003AFC10(void);
extern void func_003E2E60(s32);
extern void *func_003AFA18();   /* no prototype: func_003AFA70 passes an arg */
extern void func_003E1AA8(void *p);
 
void func_003AF250(void) {
    func_003E2E60(func_003AFC10());
    func_003E1AA8(func_003AFA18());
}
/* localdecomp:end func_003AF250 */

/* localdecomp:start func_003AF288 */
extern u8 D_00227480[];
extern s32 func_0038E2E8(void *, s32);
extern void func_0038E440(void *);
void func_003AF288(void) {
    func_0038E2E8(D_00227480, 0x2B);
    func_0038E440(D_00227480);
}
/* localdecomp:end func_003AF288 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AF2C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AF718);

/* localdecomp:start func_003AF9E0 */
extern void func_003E3040(s32);
 
void func_003AF9E0(void) {
    func_003E3040(0x10);
    func_003E3040(0x11);
}
/* localdecomp:end func_003AF9E0 */

/* localdecomp:start func_003AFA08 */
s32 func_003AFA08(void) {
}
/* localdecomp:end func_003AFA08 */

/* localdecomp:start func_003AFA10 */
s32 func_003AFA10(void) {
}
/* localdecomp:end func_003AFA10 */

/* localdecomp:start func_003AFA18 */
extern s32 func_003E1A50(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA1E0;
extern s32 D_001DA1C8[2];
extern void func_003AF2C0();
extern void func_003AF9E0(void);
extern void func_003AF718();
extern s32 func_003AFA08(void);
extern s32 func_003AFA10(void);
void *func_003AFA18() {
    if (D_001DA1E0 == 0) {
        func_003E1A50(D_001DA1C8, (s32)func_003AF2C0, (s32)func_003AF9E0, (s32)func_003AF718, (s32)func_003AFA08, (s32)func_003AFA10);
        D_001DA1E0 = 1;
    }
    return D_001DA1C8;
}
/* localdecomp:end func_003AFA18 */

/* localdecomp:start func_003AFA70 */
void func_003AFA70(s32 arg0) {
    func_003AFA18(arg0);
}
/* localdecomp:end func_003AFA70 */

/* localdecomp:start func_003AFA90 */
extern u8 D_003336D0[];
 
void *func_003AFA90(s32 i) {
    return D_003336D0 + i * 0x9000;
}
/* localdecomp:end func_003AFA90 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AFAA8);

/* localdecomp:start func_003AFC10 */
extern s32 func_003E1A50(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA200;
extern s32 D_001DA1E8[2];
extern void func_003AFC68();
extern void func_003B0210(void);
extern void func_003AFF20();
extern void func_003B0258(void);
extern void func_003B0278(void);
s32 func_003AFC10(void) {
    if (D_001DA200 == 0) {
        func_003E1A50(D_001DA1E8, (s32)func_003AFC68, (s32)func_003B0210, (s32)func_003AFF20, (s32)func_003B0258, (s32)func_003B0278);
        D_001DA200 = 1;
    }
    return (s32)D_001DA1E8;
}
/* localdecomp:end func_003AFC10 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AFC68);

INCLUDE_ASM("asm/nonmatchings/text", func_003AFF20);

/* localdecomp:start func_003B0210 */
extern void func_003E3040(s32);
extern void func_003B05D8(void);
extern void func_0039D6C8(s32);
extern void func_003B43B0(void);
void func_003B0210(void) {
    func_003E3040(0x10);
    func_003E3040(0x11);
    func_003E3040(0x14);
    func_003B05D8();
    func_0039D6C8(1);
    func_003B43B0();
}
/* localdecomp:end func_003B0210 */

/* localdecomp:start func_003B0258 */
void func_003B0258(void) {
    func_0037DCE0();
}
/* localdecomp:end func_003B0258 */

/* localdecomp:start func_003B0278 */
extern s32 func_0037DCE8(void);
extern void func_003B43C0();
 
void func_003B0278(void) {
    func_0037DCE8();
    func_003B43C0();
}
/* localdecomp:end func_003B0278 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B02A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B0580);

/* localdecomp:start func_003B05D8 */
extern void *func_003AED40(s32);
 
void func_003B05D8(void) {
    void *o = func_003AED40(0);
    ((void (*)(void *))(*(void ***)((u8 *)o + 0x4))[3])(o);
}
/* localdecomp:end func_003B05D8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B0608);

/* localdecomp:start func_003B0720 */
typedef struct { s32 a, b, c, d; } E_37B870;
extern E_37B870 D_0037B870[];
extern s32 D_001D89E8;
extern s32 D_001D89EC;
extern s32 D_001D8A30;
extern s32 *func_003B46F0(s32);
extern s32 func_003B4778(s32 *);
extern void func_003E28E0(s32, s32);
extern void func_003E24B0(s32, s32);
void func_003B0720(void) {
    s32 v = func_003B4778(func_003B46F0(0));
    D_001D89E8 = v;
    if (v < 0) return;
    if (D_001D89EC != v) {
        if (D_001D89EC >= 0) D_001D8A30 = 30;
        else D_001D8A30 = 1;
    }
    if (D_001D8A30 != 0) {
        if (--D_001D8A30 == 0) {
            func_003E28E0(0x1C0003, D_0037B870[D_001D89E8].d);
            func_003E24B0(0x1C0003, 1);
        }
    }
    D_001D89EC = D_001D89E8;
}
/* localdecomp:end func_003B0720 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B07B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B0A60);

/* localdecomp:start func_003B0C40 */
extern s32 D_00143950_b[];
extern void func_003830E8();
 
void func_003B0C40(void) {
    u8 *b = (u8 *)D_00143950_b;
    b[0xAD] = b[0xAD] == 0;
    func_003830E8();
}
/* localdecomp:end func_003B0C40 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B0C70);

/* localdecomp:start func_003B0D18 */
extern s32 D_00143950_b[];
extern void func_003B0DA0(void);
void func_003B0D18(void) {
    u8 *b = (u8 *)D_00143950_b;
    u8 s = b[0xB7];
    if (s == 0) b[0xB7] = 2;
    else if (s == 2) b[0xB7] = 4;
    else if (s == 4) b[0xB7] = 0;
    func_003B0DA0();
}
/* localdecomp:end func_003B0D18 */

/* localdecomp:start func_003B0D70 */
extern u8 D_00143950[];
s32 func_003B0D70(void) {
    u8 *p = &D_00143950[0];
    s32 v = p[6] == 0;
    p[6] = v;
    return v;
}
/* localdecomp:end func_003B0D70 */

/* localdecomp:start func_003B0D88 */
extern s32 D_00143950_b[];

s32 func_003B0D88(void) {
    s32 inverted_val = !D_00143950_b[2];
    D_00143950_b[2] = inverted_val;
    return inverted_val;
}
/* localdecomp:end func_003B0D88 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B0DA0);

/* localdecomp:start func_003B0F58 */
extern void func_003A3DA0(s32);
extern void func_0038CAF0(void);
extern s32 D_001D5520[];
extern void func_0038CE40(s32, s32, s32, s32, s32, s32);
void func_003B0F58(void) {
    func_003A3DA0(1);
    func_0038CAF0();
    if (D_001D5520[0] != 0) {
        func_0038CE40(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
    } else {
        func_0038CE40(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
    }
}
/* localdecomp:end func_003B0F58 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B0FC8);

/* localdecomp:start func_003B1028 */
extern s32 D_001D8A48;
void func_003B1028(s32 a) { D_001D8A48 = a; }
/* localdecomp:end func_003B1028 */

/* localdecomp:start func_003B1030 */
extern s32 func_00397258(void);
extern void func_0013D3C0(s32);
extern s32 D_001D8A70_g;
void func_003B1030(void) {
    if (func_00397258()) D_001D8A70_g = 5;
    else func_0013D3C0(1);
}
/* localdecomp:end func_003B1030 */

/* localdecomp:start func_003B1068 */
extern s32 D_001D8AD8;
extern s32 func_00397258(void);
extern void func_003972A0(s32);
void func_003B1068(void) {
    if (func_00397258()) func_003972A0(D_001D8AD8);
}
/* localdecomp:end func_003B1068 */

extern s32 D_001D8A70[];
INCLUDE_ASM("asm/nonmatchings/text", func_003B1098);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003B11C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B1210);

INCLUDE_ASM("asm/nonmatchings/text", func_003B12C8);

/* localdecomp:start func_003B1368 */
extern s32 D_001D8ACC;
extern s32 D_001D8AE4;
extern s32 D_001D8A70_g;
extern void func_00396F18();
extern void func_003B1158();
extern void func_003B1030();
void func_003B1368(void) {
    func_003ADC80((void *)D_001D8ACC);
    D_001D8A70_g = 1;
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

INCLUDE_ASM("asm/nonmatchings/text", func_003B1430);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003B1518);

/* localdecomp:start func_003B15B8 */
extern void func_0039FF28(s32, s32, s32);
 
void func_003B15B8(void) {
    func_0039FF28(5, 0, 0);
}
/* localdecomp:end func_003B15B8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B15E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B16B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B1DA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B1EB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B22C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B23F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B2640);

/* localdecomp:start func_003B26E8 */
extern void func_003B15E0(s32);
extern void func_003B1EB0(void);
extern void func_003B23F8(s32);
void func_003B26E8(s32 a) {
    func_003B15E0(a);
    func_003B1EB0();
    func_003B23F8(a);
}
/* localdecomp:end func_003B26E8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B2720);

INCLUDE_ASM("asm/nonmatchings/text", func_003B27A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B2958);

/* localdecomp:start func_003B2A28 */
extern u8 D_001D5BDC[];

void func_003B2A28(void) {
    if (D_001D5BDC[0] == 0) {
        func_0037DCE0();
    }
}
/* localdecomp:end func_003B2A28 */

/* localdecomp:start func_003B2A50 */
extern u8 D_001D5BDC[];
extern s32 D_001D8A70_g;
extern void func_003866E8(s32, s32, s32, s32);
extern void func_003B2AF8(void);
void func_003B2A50(void) {
    if (D_001D5BDC[0] == 0) func_0037DCE8();
    if (D_001D8A70_g != 0) {
        func_003866E8(0, 0, 0, 0x30);
        func_003B2AF8();
    }
}
/* localdecomp:end func_003B2A50 */

/* localdecomp:start func_003B2AA0 */
extern s32 func_003E1A50(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA220;
extern s32 D_001DA208[2];
extern void func_003B22C0();
extern void func_003B2958();
extern void func_003B27A8();
extern void func_003B2A28(void);
extern void func_003B2A50();
s32 func_003B2AA0(void) {
    if (D_001DA220 == 0) {
        func_003E1A50(D_001DA208, (s32)func_003B22C0, (s32)func_003B2958, (s32)func_003B27A8, (s32)func_003B2A28, (s32)func_003B2A50);
        D_001DA220 = 1;
    }
    return (s32)D_001DA208;
}
/* localdecomp:end func_003B2AA0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B2AF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B2F50);

INCLUDE_ASM("asm/nonmatchings/text", func_003B3558);

INCLUDE_ASM("asm/nonmatchings/text", func_003B3DB8);

/* localdecomp:start func_003B41E8 */
extern s32 D_001D8BF0;
void func_003B41E8(void) {
    D_001D8BF0 = 0;
}
/* localdecomp:end func_003B41E8 */

/* localdecomp:start func_003B41F0 */
extern s32 D_001D8BF0;
s32 func_003B41F0(void) {
    return D_001D8BF0;
}
/* localdecomp:end func_003B41F0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B41F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B4220);

extern s32 D_001D8C0C;
extern s32 D_001D8C10;
/* localdecomp:start func_003B42C0 */
extern s32 D_001D8C0C;
extern s32 D_001D8C10;
void func_003B42C0(s32 a, s32 b) { D_001D8C0C = a; D_001D8C10 = b; }
/* localdecomp:end func_003B42C0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B42D0);

/* localdecomp:start func_003B43B0 */
extern s32 D_001D8BF0;
extern s32 D_001D8BEC;
void func_003B43B0(void) {
    D_001D8BF0 = 0;
    D_001D8BEC = 1;
}
/* localdecomp:end func_003B43B0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B43C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B45B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B46F0);

/* localdecomp:start func_003B4778 */
s32 func_003B4778(s32 *p) {
    return p[1] + p[2];
}
/* localdecomp:end func_003B4778 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B4788);

/* localdecomp:start func_003B4950 */
s32 func_003B4950(void *p, s32 x, s32 y) {
    return *(s32 *)((u8 *)p + 0xB0) + (*(s32 *)((u8 *)p + 0x14) * y + x) * 0x44;
}
/* localdecomp:end func_003B4950 */

/* localdecomp:start func_003B4970 */
s32 func_003B4970(void *p, s32 x, s32 y) {
    y += 0x4F0000;
    return x * (*(s32 *)((u8 *)p + 0x14) * *(s32 *)((u8 *)p + 0x10)) + y;
}
/* localdecomp:end func_003B4970 */

/* localdecomp:start func_003B4990 */
s32 func_003B4990(s32 a0, s32 a1) {
    return a1 + 0x4F0048;
}
/* localdecomp:end func_003B4990 */

/* localdecomp:start func_003B49A0 */
s32 func_003B49A0(s32 a0, s32 a1) {
    return a1 + 0x4F00A9;
}
/* localdecomp:end func_003B49A0 */

/* localdecomp:start func_003B49B0 */
extern void func_003E3040(s32);
 
s32 func_003B49B0(u8 *p) {
    s32 r = 0;
    if (p[0] != 0) {
        p[0] = 0;
        func_003E3040(*(s32 *)(p + 0x18));
        r = 1;
    }
    return r;
}
/* localdecomp:end func_003B49B0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B49E8);

/* localdecomp:start func_003B4E60 */
void func_003B4E60(void *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    *(s32 *)((u8 *)a0 + 0x8c) = a1;
    *(s32 *)((u8 *)a0 + 0x90) = a2;
    *(s32 *)((u8 *)a0 + 0x94) = a3;
    *(s32 *)((u8 *)a0 + 0x98) = a4;
}
/* localdecomp:end func_003B4E60 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B4E78);

INCLUDE_ASM("asm/nonmatchings/text", func_003B4F08);

/* localdecomp:start func_003B4F10 */
extern void func_003E24B0(s32, s32);
void func_003B4F10(u8 *p) {
    func_003E24B0(0x4F00B0, p[0xA8]);
    func_003E24B0(0x4F00B1, p[0xA8]);
}
/* localdecomp:end func_003B4F10 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B4F50);

/* localdecomp:start func_003B5000 */
void func_003B5000(void *a0, s32 a1, f32 a2, f32 a3, f32 a4) {
    __asm__ volatile (
        "sb $5, 0x74($4)\n"
        "swc1 $12, 0x70($4)\n"
        "swc1 $13, 0xa4($4)\n"
        :: "r"(a0), "r"(a1)
    );
    *(f32 *)((u8 *)a0 + 0xa0) = a4;
}
/* localdecomp:end func_003B5000 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B5018);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5128);

INCLUDE_ASM("asm/nonmatchings/text", func_003B51F0);

/* localdecomp:start func_003B5290 */
void func_003B5290(s32 *p) {
    s32 c = p[3];
    if (p[1] >= c) {
        p[1] = c - 1;
    }
}
/* localdecomp:end func_003B5290 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B52B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5440);

INCLUDE_ASM("asm/nonmatchings/text", func_003B56C8);

/* localdecomp:start func_003B56D0 */
void func_003B56D0(s32 *arg0, float float1, float float2, float float3, float float4, float float5) {
    float *floatPtr = (float *)arg0;
    
    floatPtr[24] = float2; // $f13 -> 0x60
    floatPtr[25] = float3; // $f14 -> 0x64
    floatPtr[26] = float4; // $f15 -> 0x68
    floatPtr[27] = float5; // $f16 -> 0x6c
    floatPtr[23] = float1; // $f12 -> 0x5c
    
    arg0[30] = 0;          // $zero -> 0x78
}
/* localdecomp:end func_003B56D0 */

/* localdecomp:start func_003B56F0 */
void func_003B56F0(void *a0, f32 a1, f32 a2, f32 a3, f32 a4) {
    __asm__ volatile (
        "swc1 $15, 0x88($4)\n"
        "swc1 $12, 0x7c($4)\n"
        "swc1 $13, 0x80($4)\n"
        :: "r"(a0)
    );
    *(f32 *)((u8 *)a0 + 0x84) = a3;
}
/* localdecomp:end func_003B56F0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B5708);

INCLUDE_ASM("asm/nonmatchings/text", func_003B57F8);

/* localdecomp:start func_003B5A70 */
extern s32 func_0037DF98(s32);
extern void func_003B5AB0(s32, s32, s32);
void func_003B5A70(s32 a, s32 b, s32 c) {
    func_003B5AB0(func_0037DF98(a), b, c);
}
/* localdecomp:end func_003B5A70 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B5AB0);

extern s32 D_001D8C18[];
INCLUDE_ASM("asm/nonmatchings/text", func_003B5BD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5BE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5BE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5BF0);

/* localdecomp:start func_003B5BF8 */
extern s32 D_0037BA94[];
 
void func_003B5BF8(void) {
    D_0037BA94[0] = 7;
}
/* localdecomp:end func_003B5BF8 */

/* localdecomp:start func_003B5C08 */
typedef struct {
    char pad_0[0x74];
    s32 field_74;      
    s32 field_78;       
} TargetStruct_0037BA20;

extern TargetStruct_0037BA20 D_0037BA20;

void func_003B5C08(s32 arg_a0) {
    D_0037BA20.field_74 = 1;
    D_0037BA20.field_78 = arg_a0;
}
/* localdecomp:end func_003B5C08 */

/* localdecomp:start func_003B5C20 */
extern s32 D_0037BA94[];
s32 func_003B5C20(s32 a0) {
    return D_0037BA94[0] == a0;
}
/* localdecomp:end func_003B5C20 */

/* localdecomp:start func_003B5C38 */
s32 func_003B5C38(u32 i) {
    if (i < 4) {
        return ((struct { s32 pad[3]; s32 arr[4]; } *)&D_0037BA20)->arr[i];
    }
    return 0;
}
/* localdecomp:end func_003B5C38 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B5C60);

/* localdecomp:start func_003B5C68 */
extern s8 D_001D8C20[1];
s32 func_003B5C68(s32 i) {
    if (i >= 60) return -1;
    return D_001D8C20[i];
}
/* localdecomp:end func_003B5C68 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B5C90);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5CA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5D10);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5EC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B5F88);

INCLUDE_ASM("asm/nonmatchings/text", func_003B6050);

/* localdecomp:start func_003B60B0 */
extern f32 D_001D8C5C;
extern s32 func_003894A0(s32, s32, f32);
extern void func_003E2808(s32, s32);
void func_003B60B0(s32 a) {
    func_003E2808(a, func_003894A0(0x20000000, 0x402299DE, D_001D8C5C));
}
/* localdecomp:end func_003B60B0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B60F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B6190);

/* localdecomp:start func_003B6198 */
s32 func_003B6198(void) {
    return 0;
}
/* localdecomp:end func_003B6198 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B61A0);

/* localdecomp:start func_003B62D0 */
extern u8 D_001D8CE0;
void func_003B62D0(s32 a) {
    D_001D8CE0 = a;
}
/* localdecomp:end func_003B62D0 */

/* localdecomp:start func_003B62D8 */
extern s32 D_001D8D1C;
s32 func_003B62D8(void) {
    return D_001D8D1C;
}
/* localdecomp:end func_003B62D8 */

/* localdecomp:start func_003B62E0 */
extern s32 D_001D8D18;
s32 func_003B62E0(void) {
    return D_001D8D18;
}
/* localdecomp:end func_003B62E0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B62E8);

/* localdecomp:start func_003B6358 */
void func_003B6358(s32 a0, long a1) {
    *(s32 *)a1 = a0;
}
/* localdecomp:end func_003B6358 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B6368);

INCLUDE_ASM("asm/nonmatchings/text", func_003B6410);

INCLUDE_ASM("asm/nonmatchings/text", func_003B6488);

INCLUDE_ASM("asm/nonmatchings/text", func_003B6528);

INCLUDE_ASM("asm/nonmatchings/text", func_003B6F28);

INCLUDE_ASM("asm/nonmatchings/text", func_003B70A8);

/* localdecomp:start func_003B7190 */
extern unsigned long func_00395EB8(s32);
void func_003B7190(s32 a, unsigned long *out) {
    *out = func_00395EB8(a);
}
/* localdecomp:end func_003B7190 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B71B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7288);

/* localdecomp:start func_003B7320 */
extern void func_00381F18(void);
extern void func_003BD8A0(void);
extern void func_003838C0(void);
extern void func_003B7378(void);
extern void func_0038DEB0(void);
extern s32 D_001D9D9C;
extern void (*D_001D8CF0)(void);
void func_003B7320(void) {
    void (*fn)(void);
    func_00381F18();
    func_003BD8A0();
    func_003838C0();
    fn = D_001D8CF0;
    D_001D9D9C = -1;
    if (fn != 0) fn();
    func_003B7378();
    func_0038DEB0();
}
/* localdecomp:end func_003B7320 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B7378);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7568);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7618);

/* localdecomp:start func_003B7870 */
extern void func_003C8CE0(void);
extern void func_003C8C40(void);
extern void func_003C8D50(void);
extern void func_003A3EF0(s32, unsigned long);
extern s32 D_001A1ED8[];
void func_003B7870(void) {
    func_003C8CE0();
    func_003C8C40();
    func_003C8D50();
    func_003A3EF0(0x47, 0x5360B);
    func_003A3EF0(0x4E, (D_001A1ED8[0] >> 13) | 0x1000000);
}
/* localdecomp:end func_003B7870 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B78C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7AA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7B50);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7EB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B7FD8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8168);

/* localdecomp:start func_003B8280 */
extern u8 D_001DA320[];
extern s32 D_001DA330[];
extern f32 D_001DA334[];
extern f32 D_001DA338[];
extern void func_003BFEF0(void *, s32, f32, f32);
void func_003B8280(void) {
    func_003BFEF0(D_001DA320, D_001DA330[0], D_001DA334[0], D_001DA338[0]);
}
/* localdecomp:end func_003B8280 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B82C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8440);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8560);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8700);

INCLUDE_ASM("asm/nonmatchings/text", func_003B87B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8810);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8840);

/* localdecomp:start func_003B8928 */
typedef struct { u8 pad[0x64]; s32 f64; s32 f68; } S_16C580b;
extern S_16C580b D_16C580;
extern void func_003B71B8(s32);
extern void func_003958A0(s32);
void func_003B8928(s32 a) {
    func_003B71B8(a);
    D_16C580.f64 = a;
    D_16C580.f68 = 0;
    func_003958A0(0);
}
/* localdecomp:end func_003B8928 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B8968);

/* localdecomp:start func_003B89F8 */
extern s32 D_0016C5E4[];
 
s32 func_003B89F8(void) {
    return D_0016C5E4[0];
}
/* localdecomp:end func_003B89F8 */

/* localdecomp:start func_003B8A08 */
extern s32 D_002257B4[];
s32 func_003B8A08(void) {
    return D_002257B4[0];
}
/* localdecomp:end func_003B8A08 */

/* localdecomp:start func_003B8A18 */
extern s32 D_001D8D0C;
s32 func_003B8A18(void) { return D_001D8D0C; }
/* localdecomp:end func_003B8A18 */

/* localdecomp:start func_003B8A20 */
extern s32 D_001D4B4C[];
extern s32 D_001D4B48;
s32 func_003B8A20(void) {
    if (D_001D4B4C[0] != 0 && D_001D4B48 >= 2) return 1;
    return 0;
}
/* localdecomp:end func_003B8A20 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B8A48);

INCLUDE_ASM("asm/nonmatchings/text", func_003B8A68);

/* localdecomp:start func_003B8B10 */
extern f32 D_001D8D20;
void func_003B8B10(f32 a) {
    D_001D8D20 = a;
}
/* localdecomp:end func_003B8B10 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B8B18);

/* localdecomp:start func_003B8BC8 */
extern s32 func_003B8B18(s32, s32, s32);
extern u8 D_001D558C[];
void func_003B8BC8(void) {
    if (func_003B8B18(0x1C, 8, 0)) return;
    if (func_003B8B18(8, 8, 0)) return;
    if (func_003B8B18(8, 0x1B, 0)) return;
    if (func_003B8B18(8, 0x1C, 0)) return;
    if (func_003B8B18(-1, 8, 0x11)) return;
    if (D_001D558C[0] != 0) func_003B8B18(8, -1, 0x12);
}
/* localdecomp:end func_003B8BC8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B8C70);

/* localdecomp:start func_003B8D00 */
extern u8 D_001D8D24;
void func_003B8D00(s32 a) {
    D_001D8D24 = a;
}
/* localdecomp:end func_003B8D00 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B8D08);

/* localdecomp:start func_003B8E08 */
extern u8 D_001D8D01;
u8 func_003B8E08(void) {
    return D_001D8D01;
}
/* localdecomp:end func_003B8E08 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B8E10);

/* localdecomp:start func_003B8EC0 */
extern void func_003B6528(s32, s32);
extern void func_00385B60(s32);
extern s32 D_001DA340[];
s32 func_003B8EC0(void) {
    func_003B6528(0, 0);
    func_00385B60(6);
    D_001DA340[0] = 300;
    return 1;
}
/* localdecomp:end func_003B8EC0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B8EF8);

/* localdecomp:start func_003B8F48 */
s32 func_003B8F48(void) {
}
/* localdecomp:end func_003B8F48 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B8F50);

/* localdecomp:start func_003B9030 */
extern s32 func_003B9090();
extern void func_003B9880();
void func_003B9030(u8 *p) {
    s32 ok = 0;
    switch (*(s16 *)(p + 0xAA)) {
    case 0x19E9:
        ok = 1;
        *(void **)(p + 0x64) = func_003B9090;
        break;
    case 0x1D98:
        ok = 1;
        *(void **)(p + 0x64) = func_003B9880;
        break;
    }
    if (ok) *(u16 *)(p + 0x34) &= ~2;
    else *(u16 *)(p + 0x34) |= 2;
}
/* localdecomp:end func_003B9030 */

/* localdecomp:start func_003B9090 */
s32 func_003B9090(void) {
}
/* localdecomp:end func_003B9090 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B9098);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9160);

INCLUDE_ASM("asm/nonmatchings/text", func_003B92B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9730);

/* localdecomp:start func_003B9880 */
extern void func_003B98B8();
extern void func_00385840(void *, void *);
extern void func_003B9730(void *);
void func_003B9880(void *p) {
    func_00385840(func_003B98B8, p);
    func_003B9730(p);
}
/* localdecomp:end func_003B9880 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B98B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B99A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9A08);

/* localdecomp:start func_003B9B38 */
extern void func_003B8A48();
extern void func_003B7288();
 
void func_003B9B38(void) {
    func_003B8A48();
    func_003B7288();
}
/* localdecomp:end func_003B9B38 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B9B60);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9BE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9C50);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9DA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9E98);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA0B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA108);

/* localdecomp:start func_003BA280 */
extern void func_003B8A48();
extern void func_003B7288();
 
void func_003BA280(void) {
    func_003B8A48();
    func_003B7288();
}
/* localdecomp:end func_003BA280 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BA2A8);

/* localdecomp:start func_003BA350 */
extern s32 D_0016C5E4[];
s32 func_003BA350(void) {
    return D_0016C5E4[0] == 1;
}
/* localdecomp:end func_003BA350 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BA368);

/* localdecomp:start func_003BA3C8 */
extern void func_003A2DF8(void *);
extern u8 D_00319170[];
 
void func_003BA3C8(void) {
    func_003A2DF8(D_00319170);
}
/* localdecomp:end func_003BA3C8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BA3E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA490);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA5B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA748);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA850);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA948);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA9A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BAE98);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB210);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB398);

/* localdecomp:start func_003BB4D8 */
extern void func_003A3028();
extern s32 func_003BA350(void);
extern void func_003BA9A0(void *);
extern void func_003BAE98(void *);
void func_003BB4D8(void *p) {
    func_003A3028(p);
    if (func_003BA350()) func_003BA9A0(p);
    func_003BAE98(p);
}
/* localdecomp:end func_003BB4D8 */

/* localdecomp:start func_003BB520 */
extern void func_003B8A48();
extern void func_003B7288();
extern void func_003BA948();
 
void func_003BB520(void) {
    func_003B8A48();
    func_003B7288();
    func_003BA948();
    func_003BA3C8();
}
/* localdecomp:end func_003BB520 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BB558);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB5C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB730);

/* localdecomp:start func_003BB790 */
extern void func_003A2DF8(void *);
extern u8 D_00319170[];
 
void func_003BB790(void) {
    func_003A2DF8(D_00319170);
}
/* localdecomp:end func_003BB790 */

/* localdecomp:start func_003BB7B0 */
extern u8 D_001D8D50;
void func_003BB7B0(void) {
    D_001D8D50 = 0;
}
/* localdecomp:end func_003BB7B0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BB7B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB7E8);

/* localdecomp:start func_003BB9F0 */
extern void func_003BBD70();
void func_003BB9F0(u8 *p) {
    s32 ok = 0;
    switch (*(s16 *)(p + 0xAA)) {
    case 0x1E03:
        *(u16 *)(p + 0x34) |= 1;
        *(void **)(p + 0x64) = func_003BBD70;
        ok = 1;
        break;
    case 0xD54:
        *(void **)(p + 0x64) = 0;
        ok = 1;
        break;
    }
    if (ok) *(u16 *)(p + 0x34) &= ~2;
    else *(u16 *)(p + 0x34) |= 2;
}
/* localdecomp:end func_003BB9F0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BBA50);

INCLUDE_ASM("asm/nonmatchings/text", func_003BBC48);

/* localdecomp:start func_003BBD70 */
extern void func_00385688(void (*)(), s32);
extern void func_003BBD98();
 
void func_003BBD70(s32 a0) {
    func_00385688(func_003BBD98, a0);
}
/* localdecomp:end func_003BBD70 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BBD98);

/* localdecomp:start func_003BBF80 */
extern void func_003A1340(void *);
extern void func_003A26D0(void *);
extern void func_003A3028();
void func_003BBF80(u8 *p) {
    if (p[0x95] < 11) return;
    func_003A1340(p);
    func_003A26D0(p);
    func_003A3028();
}
/* localdecomp:end func_003BBF80 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BBFC8);

/* localdecomp:start func_003BC0B8 */
extern s16 D_0016C5AC[];
 
void func_003BC0B8(void) {
    func_003B8A48();
    func_003B7288();
    func_003BB790();
    D_0016C5AC[0] = 1;
}
/* localdecomp:end func_003BC0B8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BC0F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BC218);

INCLUDE_ASM("asm/nonmatchings/text", func_003BC568);

INCLUDE_ASM("asm/nonmatchings/text", func_003BCFB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD0D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD360);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD428);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD490);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD550);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD630);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD668);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD768);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD778);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD810);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD868);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD8A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD9A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDA38);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDAC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDAC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDBA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDC90);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDD68);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDEA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE0D0);

/* localdecomp:start func_003BE118 */
extern void func_00388440(s32, s32, s32);
 
void func_003BE118(void) {
    func_00388440(0x70003A00, 0x40000000, 0x3C0);
}
/* localdecomp:end func_003BE118 */

/* localdecomp:start func_003BE140 */
extern void func_003885F0(s32, s32, s32);
extern u8 D_002D6400[];
 
void func_003BE140(void) {
    func_003885F0((s32)D_002D6400, 0x70003A00, 0x3C0);
}
/* localdecomp:end func_003BE140 */

/* localdecomp:start func_003BE170 */
extern void func_003885F0(s32, s32, s32);
 extern u8 D_002D6400[];

void func_003BE170(void) {
    func_003885F0(0x70003A00, (s32)D_002D6400, 0x3C0);
}
/* localdecomp:end func_003BE170 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BE1A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE260);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE2E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE340);

/* localdecomp:start func_003BE3A0 */
// Bypass the C compiler entirely so it stops adding jr $ra
__asm__(    
    ".section .text\n"
    ".global func_003BE3A0\n"
    "func_003BE3A0:\n"
    "addiu $29, $29, 0x30\n"
    "nop\n"
    "addiu $2, $0, 0xff\n"
    "nop\n"
    "sw    $0, 0($3)\n"
    "nop\n"
    "addiu $2, $0, 0x1\n"
    "nop\n"
);
/* localdecomp:end func_003BE3A0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BE3C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE400);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE418);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE4F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE688);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE6A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE740);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE7F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE860);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE948);

INCLUDE_ASM("asm/nonmatchings/text", func_003BE988);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEA80);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEB18);

/* localdecomp:start func_003BEB48 */
f32 func_003BEB48(f32 a, f32 b, f32 t) {
    return a + (b - a) * t;
}
/* localdecomp:end func_003BEB48 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BEB58);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEBF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEBF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEC48);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEC60);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEE08);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEE20);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEFF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF058);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF2A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF2F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF2F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF360);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF4F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF5C0);

/* localdecomp:start func_003BF5D0 */
s32 func_003BF5D0(s32 arg0) {
    return (u32)(arg0 - 500) < 41;
}
/* localdecomp:end func_003BF5D0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BF5E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF630);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF640);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF690);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF6A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF728);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF778);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF7C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF7E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF820);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF838);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF8F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BF910);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFA18);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFAF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFB60);

/* localdecomp:start func_003BFB80 */
extern void func_003BFAF8(s32, f32 *, s32, s32);
f32 func_003BFB80(s32 a, s32 b, s32 c) {
    f32 v[4];
    func_003BFAF8(a, v, b, c);
    return v[2];
}
/* localdecomp:end func_003BFB80 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BFBA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFC18);

/* localdecomp:start func_003BFCE8 */
extern void func_003BFC18(void *);
 
void func_003BFCE8(void *p) {
    func_003BFC18((u8 *)p + 0x10);
}
/* localdecomp:end func_003BFCE8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BFD08);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFD10);

/* localdecomp:start func_003BFD90 */
extern void func_003BFD10(void *);
 
void func_003BFD90(void *p) {
    func_003BFD10((u8 *)p + 0x10);
}
/* localdecomp:end func_003BFD90 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BFDB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFDB8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFE08);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFEE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BFEF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C00B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C0B10);

INCLUDE_ASM("asm/nonmatchings/text", func_003C0D70);

INCLUDE_ASM("asm/nonmatchings/text", func_003C0E08);

INCLUDE_ASM("asm/nonmatchings/text", func_003C0E10);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1070);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1130);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1440);

INCLUDE_ASM("asm/nonmatchings/text", func_003C18F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1950);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1A28);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1A40);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1A60);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1A90);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1DA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1F10);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1FE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C21A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C2310);

INCLUDE_ASM("asm/nonmatchings/text", func_003C2370);

INCLUDE_ASM("asm/nonmatchings/text", func_003C23E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C26C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C2868);

INCLUDE_ASM("asm/nonmatchings/text", func_003C28B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C35A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C4280);

INCLUDE_ASM("asm/nonmatchings/text", func_003C4F30);

INCLUDE_ASM("asm/nonmatchings/text", func_003C5098);

INCLUDE_ASM("asm/nonmatchings/text", func_003C5AE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C5D90);

INCLUDE_ASM("asm/nonmatchings/text", func_003C5E70);

INCLUDE_ASM("asm/nonmatchings/text", func_003C78B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C79F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C7AD8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C7AE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C7B90);

INCLUDE_ASM("asm/nonmatchings/text", func_003C7B98);

INCLUDE_ASM("asm/nonmatchings/text", func_003C7BA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C7CE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C7DE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C7E68);

INCLUDE_ASM("asm/nonmatchings/text", func_003C8A90);

INCLUDE_ASM("asm/nonmatchings/text", func_003C8B28);

INCLUDE_ASM("asm/nonmatchings/text", func_003C8C40);

INCLUDE_ASM("asm/nonmatchings/text", func_003C8CD8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C8CE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C8D50);

INCLUDE_ASM("asm/nonmatchings/text", func_003C8E68);

INCLUDE_ASM("asm/nonmatchings/text", func_003C8E70);

INCLUDE_ASM("asm/nonmatchings/text", func_003C8ED0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C9078);

INCLUDE_ASM("asm/nonmatchings/text", func_003C9208);

INCLUDE_ASM("asm/nonmatchings/text", func_003C9210);

INCLUDE_ASM("asm/nonmatchings/text", func_003C92B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C93B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C94B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C9798);

INCLUDE_ASM("asm/nonmatchings/text", func_003C9888);

INCLUDE_ASM("asm/nonmatchings/text", func_003C99D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C9AE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C9B80);

INCLUDE_ASM("asm/nonmatchings/text", func_003C9C58);

INCLUDE_ASM("asm/nonmatchings/text", func_003CA860);

INCLUDE_ASM("asm/nonmatchings/text", func_003CA9C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003CAC10);

INCLUDE_ASM("asm/nonmatchings/text", func_003CB310);

INCLUDE_ASM("asm/nonmatchings/text", func_003CB498);

INCLUDE_ASM("asm/nonmatchings/text", func_003CB5A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CB5B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CB748);

/* localdecomp:start func_003CB860 */
extern void func_003CB890(void *);
extern void func_003CB748(void *);
void func_003CB860(void *p) {
    func_003CB890(p);
    func_003CB748(p);
}
/* localdecomp:end func_003CB860 */

INCLUDE_ASM("asm/nonmatchings/text", func_003CB890);

INCLUDE_ASM("asm/nonmatchings/text", func_003CB958);

INCLUDE_ASM("asm/nonmatchings/text", func_003CBA68);

INCLUDE_ASM("asm/nonmatchings/text", func_003CBAC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CBC70);

INCLUDE_ASM("asm/nonmatchings/text", func_003CBE40);

INCLUDE_ASM("asm/nonmatchings/text", func_003CC198);

INCLUDE_ASM("asm/nonmatchings/text", func_003CC4B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CC5F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003CC838);

INCLUDE_ASM("asm/nonmatchings/text", func_003CC880);

INCLUDE_ASM("asm/nonmatchings/text", func_003CC884);

INCLUDE_ASM("asm/nonmatchings/text", func_003CC8B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003CC950);

INCLUDE_ASM("asm/nonmatchings/text", func_003CCB40);

INCLUDE_ASM("asm/nonmatchings/text", func_003CCCF8);

INCLUDE_ASM("asm/nonmatchings/text", func_003CCD08);

INCLUDE_ASM("asm/nonmatchings/text", func_003CCDC4);

INCLUDE_ASM("asm/nonmatchings/text", func_003CCE10);

INCLUDE_ASM("asm/nonmatchings/text", func_003CCF38);

INCLUDE_ASM("asm/nonmatchings/text", func_003CCFB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD194);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD250);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD470);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD4A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD510);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD548);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD598);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD710);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD7D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CD830);

INCLUDE_ASM("asm/nonmatchings/text", func_003CDDF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CDE70);

INCLUDE_ASM("asm/nonmatchings/text", func_003CDEB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CE4B4);

INCLUDE_ASM("asm/nonmatchings/text", func_003CE6A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003CE740);

INCLUDE_ASM("asm/nonmatchings/text", func_003CF790);

INCLUDE_ASM("asm/nonmatchings/text", func_003D00C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D00F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D00F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003D14B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D14D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1570);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1650);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1978);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1B08);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1B10);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1D40);

INCLUDE_ASM("asm/nonmatchings/text", func_003D1E68);

INCLUDE_ASM("asm/nonmatchings/text", func_003D22D8);

/* localdecomp:start func_003D22E0 */
extern void func_003D1E68(s32, s32, s32, s32, s32);
 
void func_003D22E0(s32 a0, s32 a1, s32 a2) {
    func_003D1E68(a0, a1, 0x100, 0x100, a2);
}
/* localdecomp:end func_003D22E0 */

/* localdecomp:start func_003D2308 */
extern void func_003D1E68(s32, s32, s32, s32, s32);
 
void func_003D2308(s32 a0, s32 a1, s32 a2) {
    func_003D1E68(a0, a1, 0x80, 0x80, a2);
}
/* localdecomp:end func_003D2308 */

/* localdecomp:start func_003D2330 */
extern void func_003D1E68(s32, s32, s32, s32, s32);
 
void func_003D2330(s32 a0, s32 a1, s32 a2) {
    func_003D1E68(a0, a1, 0x40, 0x40, a2);
}
/* localdecomp:end func_003D2330 */

INCLUDE_ASM("asm/nonmatchings/text", func_003D2358);

INCLUDE_ASM("asm/nonmatchings/text", func_003D2370);

INCLUDE_ASM("asm/nonmatchings/text", func_003D27C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D2878);

INCLUDE_ASM("asm/nonmatchings/text", func_003D2F90);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3050);

INCLUDE_ASM("asm/nonmatchings/text", func_003D30D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3148);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3428);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3780);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3A50);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3B90);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3C80);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3CF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3DC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3E08);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3E40);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3EE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3F78);

INCLUDE_ASM("asm/nonmatchings/text", func_003D3FA0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D4198);

INCLUDE_ASM("asm/nonmatchings/text", func_003D41E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D4680);

/* localdecomp:start func_003D46B0 */
extern s32 D_001D4BB0[];
extern void func_003D76A0(s32);
extern void func_003A40C8(void);
void func_003D46B0(void) {
    func_003D76A0(D_001D4BB0[0]);
    func_003A40C8();
}
/* localdecomp:end func_003D46B0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003D46E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D47A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D4850);

INCLUDE_ASM("asm/nonmatchings/text", func_003D4858);

INCLUDE_ASM("asm/nonmatchings/text", func_003D48D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003D5814);

INCLUDE_ASM("asm/nonmatchings/text", func_003D5840);

INCLUDE_ASM("asm/nonmatchings/text", func_003D6130);

INCLUDE_ASM("asm/nonmatchings/text", func_003D6BC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D6BE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003D6C10);

INCLUDE_ASM("asm/nonmatchings/text", func_003D764C);

INCLUDE_ASM("asm/nonmatchings/text", func_003D7674);

INCLUDE_ASM("asm/nonmatchings/text", func_003D76A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D7950);

INCLUDE_ASM("asm/nonmatchings/text", func_003D8098);

INCLUDE_ASM("asm/nonmatchings/text", func_003D80C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D81E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D8218);

INCLUDE_ASM("asm/nonmatchings/text", func_003D9308);

INCLUDE_ASM("asm/nonmatchings/text", func_003D9330);

INCLUDE_ASM("asm/nonmatchings/text", func_003D94A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003D95B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D96C4);

INCLUDE_ASM("asm/nonmatchings/text", func_003D97C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003D98D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003D99D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003D9A40);

INCLUDE_ASM("asm/nonmatchings/text", func_003DB318);

INCLUDE_ASM("asm/nonmatchings/text", func_003DB5C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DBB70);

INCLUDE_ASM("asm/nonmatchings/text", func_003DBCE8);

INCLUDE_ASM("asm/nonmatchings/text", func_003DBDF0);

/* localdecomp:start func_003DBE20 */
extern void func_003A3DA0(s32);
extern void func_0038CAF0(void);
extern s32 D_001D5520[];
extern void func_0038CE40(s32, s32, s32, s32, s32, s32);
extern void func_003D3DC8(void);
void func_003DBE20(void) {   /* same as func_003B0F58 plus the call below */
    func_003A3DA0(1);
    func_0038CAF0();
    if (D_001D5520[0] != 0) {
        func_0038CE40(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
    } else {
        func_0038CE40(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
    }
    func_003D3DC8();
}
/* localdecomp:end func_003DBE20 */

INCLUDE_ASM("asm/nonmatchings/text", func_003DBE98);

/* localdecomp:start func_003DBEA0 */
extern s32 D_00302DC0[];
 
s32 func_003DBEA0(void) {
    return D_00302DC0[0];
}
/* localdecomp:end func_003DBEA0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003DBEB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DCD08);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE260);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE3A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE430);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE4A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE558);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE560);

/* localdecomp:start func_003DE870 */
typedef struct { u8 pad[0x40]; s32 f40; u8 pad2[0x14]; s32 f58; } S_302D80;
extern S_302D80 D_00302D80;
 
void func_003DE870(void) {
    S_302D80 *s = &D_00302D80;
    if (s->f40 == 7 && s->f58 == 1) {
        s->f58 = 2;
    }
}
/* localdecomp:end func_003DE870 */

/* localdecomp:start func_003DE8A0 */
extern s32 D_00302DC0[];
s32 func_003DE8A0(void) {
    return D_00302DC0[0] == 7;
}
/* localdecomp:end func_003DE8A0 */

/* localdecomp:start func_003DE8B8 */
extern s32 D_001D94F0;
void func_003DE8B8(void) {
    D_001D94F0 = 3;
}
/* localdecomp:end func_003DE8B8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003DE8C8);

/* localdecomp:start func_003DE8D0 */
extern s16 D_00302E04[];
 
void func_003DE8D0(void) {
    D_00302E04[0] = 0;
}
/* localdecomp:end func_003DE8D0 */

/* localdecomp:start func_003DE8E0 */
void *func_003DE8E0(void *p) {
    return (u8 *)p + 0xED1C;
}
/* localdecomp:end func_003DE8E0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003DE8F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DEEF0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DEFB8);

INCLUDE_ASM("asm/nonmatchings/text", func_003DF038);

/* localdecomp:start func_003DF7C0 */
extern u8 D_001D9594;
extern u8 D_001D95A6;
extern s32 D_001D9590;
extern void func_003E22D0(s32, s32, s32);
extern s32 func_003DF9E0(s32);
extern void func_003DF958(s32);
void func_003DF7C0(s32 a) {
    if (D_001D9594 != 0 && D_001D95A6 == 0) {
        D_001D9590 = a;
        func_003E22D0(0x90000, 1, a != 0);
        func_003DF958(func_003DF9E0(0));
    }
}
/* localdecomp:end func_003DF7C0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003DF810);

INCLUDE_ASM("asm/nonmatchings/text", func_003DF820);

INCLUDE_ASM("asm/nonmatchings/text", func_003DF958);

/* localdecomp:start func_003DF9C0 */
extern u8 D_001D9594;
extern void func_003E3040(s32);
void func_003DF9C0(void) {
    D_001D9594 = 0;
    func_003E3040(7);
}
/* localdecomp:end func_003DF9C0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003DF9E0);

/* localdecomp:start func_003DFB20 */
void func_003DFB20(f32 *p, f32 a) {
    *p = (a < *p) ? a : *p;
}
/* localdecomp:end func_003DFB20 */

INCLUDE_ASM("asm/nonmatchings/text", func_003DFB40);

INCLUDE_ASM("asm/nonmatchings/text", func_003DFCA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003DFE10);

INCLUDE_ASM("asm/nonmatchings/text", func_003DFF78);

/* localdecomp:start func_003DFF90 */
extern u8 D_001D95C0;
extern s32 D_001D95B8;
extern void func_003E22D0(s32, s32, s32);
void func_003DFF90(s32 a) {
    if (D_001D95C0 != 0) {
        D_001D95B8 = a;
        func_003E22D0(0x10000, 1, a != 0);
    }
}
/* localdecomp:end func_003DFF90 */

INCLUDE_ASM("asm/nonmatchings/text", func_003DFFC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DFFD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0068);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0178);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0190);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0358);

/* localdecomp:start func_003E0370 */
void func_003E0370(f32 *p, f32 lo, f32 hi) {
    *p = (*p < lo) ? lo : *p;
    *p = (hi < *p) ? hi : *p;
}
/* localdecomp:end func_003E0370 */

/* localdecomp:start func_003E03A8 */
extern s32 func_003E0E28(void **);
 
s32 func_003E03A8(void **p) {
    return func_003E0E28(p) != 0;
}
/* localdecomp:end func_003E03A8 */

/* localdecomp:start func_003E03C8 */
s32 *func_003E03C8(s32 *p) {
    *p = 0;
    return p;
}
/* localdecomp:end func_003E03C8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E03D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0478);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0550);

/* localdecomp:start func_003E0680 */
s32 func_003E0680(void **p) {
    return *(s32 *)((u8 *)*p + 0x1C0);
}
/* localdecomp:end func_003E0680 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E0690);

/* localdecomp:start func_003E06A0 */
typedef struct { u8 pad[0x10]; s32 a[16]; } S_3E06A0;
void func_003E06A0(S_3E06A0 **p) {
    s32 i;
    for (i = 0; i < 16; i++) (*p)->a[i] = 0;
}
/* localdecomp:end func_003E06A0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E06D0);

/* localdecomp:start func_003E0770 */
s32 func_003E0770(void **p) {
    return *(s32 *)((u8 *)*p + 0x1BC);
}
/* localdecomp:end func_003E0770 */

/* localdecomp:start func_003E0780 */
typedef struct { u8 pad[0xDC]; s32 arr[1]; } S_3E0780;
 
s32 func_003E0780(S_3E0780 **p, s32 i) {
    return (*p)->arr[i];
}
/* localdecomp:end func_003E0780 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E0798);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0870);

/* localdecomp:start func_003E0900 */
void func_003E0900(s32 **p) {
    s32 i;
    for (i = 0; i < 35; i++) (*p)[i + 20] = 0;
}
/* localdecomp:end func_003E0900 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E0930);

INCLUDE_ASM("asm/nonmatchings/text", func_003E09D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0B78);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0CC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0D78);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0DF0);

/* localdecomp:start func_003E0DF8 */
extern void func_003E11D0(void *, s32, s32);
 
void func_003E0DF8(void **p, s32 a, s32 b) {
    func_003E11D0((u8 *)*p + 0x1C4, b, a);
}
/* localdecomp:end func_003E0DF8 */

/* localdecomp:start func_003E0E28 */
extern s32 func_003E1150(void *);
 
s32 func_003E0E28(void **p) {
    return func_003E1150((u8 *)*p + 0x1C4);
}
/* localdecomp:end func_003E0E28 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E0E48);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0E90);

INCLUDE_ASM("asm/nonmatchings/text", func_003E0FC8);

/* localdecomp:start func_003E10E8 */
void func_003E10E8(u8 *p) {
    func_00388440((s32)(p + 8), 0, 0x2000);
    *(s32 *)(p + 4) = 0;
}
/* localdecomp:end func_003E10E8 */

/* localdecomp:start func_003E1120 */
extern s32 *func_003ECDC8(s32 *);
void *func_003E1120(void *p) {
    func_003ECDC8((s32 *)p);
    func_003E10E8(p);
    return p;
}
/* localdecomp:end func_003E1120 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E1150);

INCLUDE_ASM("asm/nonmatchings/text", func_003E11D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E12A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1338);

INCLUDE_ASM("asm/nonmatchings/text", func_003E13D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1460);

INCLUDE_ASM("asm/nonmatchings/text", func_003E14A8);

/* localdecomp:start func_003E1510 */
extern void func_003E09D8(void *);
 
typedef struct { void *arr[5]; s32 idx; } S_3E1510;
 
void func_003E1510(void *p) {
    S_3E1510 *q = *(S_3E1510 **)((u8 *)p + 0x4);
    void *x = q->arr[q->idx];
    if (x != 0) {
        func_003E09D8(x);
    }
}
/* localdecomp:end func_003E1510 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E1548);

INCLUDE_ASM("asm/nonmatchings/text", func_003E15D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1668);

INCLUDE_ASM("asm/nonmatchings/text", func_003E16B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1760);

/* localdecomp:start func_003E1770 */
typedef struct { u8 pad[0x18]; s32 arr[1]; } S_3E1770;
 
s32 func_003E1770(void *p, s32 i) {
    return (*(S_3E1770 **)((u8 *)p + 0x4))->arr[i];
}
/* localdecomp:end func_003E1770 */

/* localdecomp:start func_003E1788 */
s32 func_003E1788(void *p, u32 i, s32 v) {
    if (i < 8) {
        s32 *q = *(s32 **)((u8 *)p + 0x4) + i;
        if (*q == 0) {
            *q = v;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E1788 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E17C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1890);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1898);

INCLUDE_ASM("asm/nonmatchings/text", func_003E18C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1928);

/* localdecomp:start func_003E1930 */
s32 *func_003E1930(s32 *p, s32 a, s32 b, s32 c, s32 d) {
    p[2] = a;
    p[1] = b;
    p[4] = d;
    p[3] = c;
    p[0] = 0;
    return p;
}
/* localdecomp:end func_003E1930 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E1950);

INCLUDE_ASM("asm/nonmatchings/text", func_003E19C8);

/* localdecomp:start func_003E1A50 */
extern void func_003E1A90(void *);
s32 func_003E1A50(s32 *p, s32 a, s32 b, s32 c, s32 d, s32 e) {
    p[1] = a;
    p[2] = b;
    p[3] = c;
    p[4] = d;
    p[5] = e;
    func_003E1A90(p);
    return (s32)p;
}
/* localdecomp:end func_003E1A50 */

/* localdecomp:start func_003E1A90 */
void func_003E1A90(void *p) {
    *(s32 *)p = 0;
}
/* localdecomp:end func_003E1A90 */

/* localdecomp:start func_003E1A98 */
s32 func_003E1A98(void *p) {
    return *(s32 *)((u8 *)p + 0x0);
}
/* localdecomp:end func_003E1A98 */

/* localdecomp:start func_003E1AA0 */
void func_003E1AA0(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x0) = value;
}
/* localdecomp:end func_003E1AA0 */

/* localdecomp:start func_003E1AA8 */
extern void func_003E1AA0(void *, s32);
 
void func_003E1AA8(void *p) {
    func_003E1AA0(p, 0);
}
/* localdecomp:end func_003E1AA8 */

/* localdecomp:start func_003E1AC8 */
void func_003E1AC8(void *p) {
    void (*fn)() = *(void (**)())((u8 *)p + 0x4);
    if (fn != 0) {
        fn();
    }
}
/* localdecomp:end func_003E1AC8 */

/* localdecomp:start func_003E1AF0 */
void func_003E1AF0(void *p) {
    void (*fn)() = *(void (**)())((u8 *)p + 0x8);
    if (fn != 0) {
        fn();
    }
}
/* localdecomp:end func_003E1AF0 */

/* localdecomp:start func_003E1B18 */
void func_003E1B18(void *p) {
    void (*fn)() = *(void (**)())((u8 *)p + 0xC);
    if (fn != 0) {
        fn();
    }
}
/* localdecomp:end func_003E1B18 */

/* localdecomp:start func_003E1B40 */
void func_003E1B40(void *p) {
    void (*fn)() = *(void (**)())((u8 *)p + 0x10);
    if (fn != 0) {
        fn();
    }
}
/* localdecomp:end func_003E1B40 */

/* localdecomp:start func_003E1B68 */
void func_003E1B68(void *p) {
    void (*fn)() = *(void (**)())((u8 *)p + 0x14);
    if (fn != 0) {
        fn();
    }
}
/* localdecomp:end func_003E1B68 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E1B90);

typedef struct {
    s32 field_0;        /* Offset 0x00 - Targeted by sw $zero, 0($a0) */
    s32 field_4;        /* Offset 0x04 - Padding */
    void* field_8;      /* Offset 0x08 - Targeted by sw $v0, 8($a0) */
} TargetStruct;

extern char D_001D96B0[];
/* localdecomp:start func_003E1B98 */
extern char D_001D96B0[];
void **func_003E1B98(void **p) { p[0] = 0; p[2] = D_001D96B0; return p; }
/* localdecomp:end func_003E1B98 */

/* localdecomp:start func_003E1BB0 */
s32 func_003E1BB0(s32 arg0, s32 arg1) {
    return arg1 == 0;
}
/* localdecomp:end func_003E1BB0 */

/* localdecomp:start func_003E1BB8 */
void func_003E1BB8(s32 *p) {
    *p += 1;
}
/* localdecomp:end func_003E1BB8 */

/* localdecomp:start func_003E1BC8 */
// Define the context structure passing through $a0
typedef struct {
    s32 counter; /* Offset 0x00 - Targeted by lw/sw operations */
} CounterContext;

// Signature must take the context pointer ($a0) and return an s32 ($v0)
s32 func_003E1BC8(CounterContext* ctx) {
    // 0: lw $v0, 0($a0)
    s32 current_val = ctx->counter;

    // 4: beqz $v0
    if (current_val != 0) {
        // 8: addiu $v0, $v0, -1
        // c: sw $v0, 0($a0)
        ctx->counter = current_val - 1;
    }

    // 14: lw $v0, 0($a0) (Scheduled cleanly into the jr $ra delay slot)
    return ctx->counter;
}
/* localdecomp:end func_003E1BC8 */

/* localdecomp:start func_003E1BE0 */
extern u8 D_001D96B0_g;
extern s32 func_003ECDB8();
void func_003E1BE0(u8 *p, s32 f) {
    *(u8 **)(p + 8) = &D_001D96B0_g;
    if (f & 1) func_003ECDB8(p);
}
/* localdecomp:end func_003E1BE0 */

/* localdecomp:start func_003E1C10 */
extern void func_003A3EF0(s32, unsigned long);
void func_003E1C10(void) {
    func_003A3EF0(0x47, 0x33001);
}
/* localdecomp:end func_003E1C10 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E1C38);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1C90);

/* localdecomp:start func_003E1CC8 */
extern void func_00384B68();
 
void func_003E1CC8(void) {
    func_00384B68(0);
}
/* localdecomp:end func_003E1CC8 */

/* localdecomp:start func_003E1CE8 */
extern void func_00384C98();
 
void func_003E1CE8(void) {
    func_00384C98();
}
/* localdecomp:end func_003E1CE8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E1D08);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1D18);

/* localdecomp:start func_003E1D50 */
extern f32 D_001D96E8;
extern f32 D_001D96EC;
void func_003E1D50(f32 *a, f32 *b) { *a = D_001D96E8; *b = D_001D96EC; }
/* localdecomp:end func_003E1D50 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E1D68);

/* localdecomp:start func_003E1E38 */
extern s32 D_001D96F8;
void func_003E1E38(s32 a) {
    D_001D96F8 = a;
}
/* localdecomp:end func_003E1E38 */

/* localdecomp:start func_003E1E40 */
extern s32 D_001D96F8;
s32 func_003E1E40(void) {
    return D_001D96F8;
}
/* localdecomp:end func_003E1E40 */

/* localdecomp:start func_003E1E48 */
s32 func_003E1E48(void) {
}
/* localdecomp:end func_003E1E48 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E1E50);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1F38);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1F40);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2028);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2110);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2118);

INCLUDE_ASM("asm/nonmatchings/text", func_003E21F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E21F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E22D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E23B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E23C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E24A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E24B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2560);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2610);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2618);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2720);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2728);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2800);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2808);

INCLUDE_ASM("asm/nonmatchings/text", func_003E28E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E29B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2A90);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2B98);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2C80);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2C88);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2D70);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2D90);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2DD8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2DE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2E60);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2ED0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2ED8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2F48);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2FB8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E2FC0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3040);

INCLUDE_ASM("asm/nonmatchings/text", func_003E30B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E30C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E31A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3250);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3320);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3330);

INCLUDE_ASM("asm/nonmatchings/text", func_003E33E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E33F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E34A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E34F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3580);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3630);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3700);

INCLUDE_ASM("asm/nonmatchings/text", func_003E37F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E38A8);

/* localdecomp:start func_003E38B0 */
extern void func_003E37F0(void *, s32, s32);
 
void func_003E38B0(void *p, s32 arg1) {
    func_003E37F0(p, 1, arg1);
}
/* localdecomp:end func_003E38B0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E38D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3988);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3A80);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3B50);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3BD0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3D08);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3DF0);

/* localdecomp:start func_003E3EE8 */
extern void func_003AFAA8();
 
void func_003E3EE8(void) {
    func_003AFAA8();
}
/* localdecomp:end func_003E3EE8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E3F08);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4788);

/* localdecomp:start func_003E4790 */
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
extern u8 D_001DAA89;
void *func_003E4790(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA89) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4790 */

/* localdecomp:start func_003E4810 */
extern u8 D_001DAA8A;
void *func_003E4810(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA8A) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4810 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E4890);

INCLUDE_ASM("asm/nonmatchings/text", func_003E4918);

/* localdecomp:start func_003E49A0 */
extern u8 D_001DAA8D;
void *func_003E49A0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA8D) return v;
    }
    return 0;
}
/* localdecomp:end func_003E49A0 */

/* localdecomp:start func_003E4A20 */
extern u8 D_001DAA8E;
void *func_003E4A20(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA8E) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4A20 */

/* localdecomp:start func_003E4AA0 */
extern u8 D_001DAA8F;
void *func_003E4AA0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA8F) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4AA0 */

/* localdecomp:start func_003E4B20 */
extern u8 D_001DAA90;
void *func_003E4B20(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA90) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4B20 */

/* localdecomp:start func_003E4BA0 */
extern u8 D_001DAA91;
void *func_003E4BA0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA91) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4BA0 */

/* localdecomp:start func_003E4C20 */
extern u8 D_001DAA92;
void *func_003E4C20(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA92) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4C20 */

/* localdecomp:start func_003E4CA0 */
extern u8 D_001DAA93;
void *func_003E4CA0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA93) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4CA0 */

/* localdecomp:start func_003E4D20 */
extern u8 D_001DAA94;
void *func_003E4D20(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA94) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4D20 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E4DA0);

/* localdecomp:start func_003E4E28 */
extern u8 D_001DAA96;
void *func_003E4E28(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA96) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4E28 */

/* localdecomp:start func_003E4EA8 */
extern u8 D_001DAA97;
void *func_003E4EA8(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA97) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4EA8 */

/* localdecomp:start func_003E4F28 */
extern u8 D_001DAA98;
void *func_003E4F28(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA98) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4F28 */

/* localdecomp:start func_003E4FA8 */
extern u8 D_001DAA99;
void *func_003E4FA8(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA99) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4FA8 */

/* localdecomp:start func_003E5028 */
extern u8 D_001DAA9A;
void *func_003E5028(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA9A) return v;
    }
    return 0;
}
/* localdecomp:end func_003E5028 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E50A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5210);

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
extern s32 func_003E8590(void *, s32);
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

INCLUDE_ASM("asm/nonmatchings/text", func_003E5D08);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003E5F00);

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
extern void func_003EB440(void *, s32);
s32 func_003E60B0(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800_g)) {
        func_003EB440(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E60B0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E6108);

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
extern s32 D_001D9800[];
extern void func_003E8628(void *, f32, f32);
s32 func_003E6268(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001D9800[0])) {
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
extern s32 func_003E8590(void *, s32);
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

INCLUDE_ASM("asm/nonmatchings/text", func_003E6538);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003E6680);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003E6C80);

INCLUDE_ASM("asm/nonmatchings/text", func_003E6CE8);

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
extern s32 func_003E8590(void *, s32);
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

INCLUDE_ASM("asm/nonmatchings/text", func_003E6F50);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7028);

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
extern s32 func_003E8590(void *, s32);
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

INCLUDE_ASM("asm/nonmatchings/text", func_003E7638);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003E7900);

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
extern s32 func_003E8590(void *, s32);
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

INCLUDE_ASM("asm/nonmatchings/text", func_003E7C90);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7D68);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003E7EC8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E7F20);

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
extern s32 func_003E8590(void *, s32);
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

INCLUDE_ASM("asm/nonmatchings/text", func_003E8390);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8420);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8560);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003E8670);

INCLUDE_ASM("asm/nonmatchings/text", func_003E86C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8718);

/* localdecomp:start func_003E8788 */
s32 func_003E8788(void) {
}
/* localdecomp:end func_003E8788 */

/* localdecomp:start func_003E8790 */
extern char D_001D96B0[];
void func_003E8790(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D96B0; if (f & 1) func_003ECDB8(p); }
/* localdecomp:end func_003E8790 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E87C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E87D8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8838);

INCLUDE_ASM("asm/nonmatchings/text", func_003E8970);

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

/* localdecomp:start func_003E8EA0 */
void func_003E8EA0(u8 *p, f32 a, f32 b, f32 c, f32 d) {
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x50) = a;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x58) = b;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x54) = c;
    *(f32 *)(*(u8 **)(p + 0x2C) + 0x5C) = d;
}
/* localdecomp:end func_003E8EA0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E8EC8);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003E91F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E91F8);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003E9B48);

INCLUDE_ASM("asm/nonmatchings/text", func_003E9B80);

INCLUDE_ASM("asm/nonmatchings/text", func_003E9BA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E9C50);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003EA648);

INCLUDE_ASM("asm/nonmatchings/text", func_003EA8A8);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003EA980);

INCLUDE_ASM("asm/nonmatchings/text", func_003EA9B0);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003EB160);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB180);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB358);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003EB440);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003EB5E8);

/* localdecomp:start func_003EB5F0 */
void func_003EB5F0(void *p, s32 *a, s32 *b) {
    *a = *(u16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x48) & 1;
    *b = ((*(u16 *)(*(u8 **)((u8 *)p + 0x2C) + 0x48) >> 1) ^ 1) & 1;
}
/* localdecomp:end func_003EB5F0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003EB620);

INCLUDE_ASM("asm/nonmatchings/text", func_003EB6B0);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003EC690);

INCLUDE_ASM("asm/nonmatchings/text", func_003EC6E0);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003ECBE0);

INCLUDE_ASM("asm/nonmatchings/text", func_003ECC20);

/* localdecomp:start func_003ECC40 */
extern u8 D_001D9880[];
void **func_003ECC40(void **p) { p[1] = 0; p[0] = D_001D9880; p[2] = 0; p[3] = 0; p[6] = 0; p[4] = 0; p[5] = 0; return p; }
/* localdecomp:end func_003ECC40 */

/* localdecomp:start func_003ECC70 */
extern u8 D_001D9898[];
void func_003ECC70(u8 *p, s32 f) { *(u8 **)p = D_001D9898; if (f & 1) func_003ECDB8(p); }
/* localdecomp:end func_003ECC70 */

/* localdecomp:start func_003ECCA0 */
typedef struct { s32 f0; u8 *base; u32 size; s32 elem; u32 used; s32 count; void **freelist; } P_3ECCA0;
void *func_003ECCA0(P_3ECCA0 *p) {
    void **n = p->freelist;
    u32 off, end;
    if (n != 0) {
        p->freelist = *n;
        p->count++;
        return n;
    }
    off = p->used;
    end = off + p->elem;
    if (p->size < end) return 0;
    { u8 *r = p->base + off; p->used = end; p->count++; return r; }
}
/* localdecomp:end func_003ECCA0 */

/* localdecomp:start func_003ECD08 */
extern void *func_003ECCA0();
 
s32 func_003ECD08(void *p, u32 n) {
    if (*(u32 *)((u8 *)p + 0xC) < n) {
        return 0;
    }
    return (s32)func_003ECCA0(p);
}
/* localdecomp:end func_003ECD08 */

/* localdecomp:start func_003ECD40 */
void func_003ECD40(s32 *p, s32 *node) {
    *node = p[6];
    p[6] = (s32)node;
    p[5]--;
}
/* localdecomp:end func_003ECD40 */

/* localdecomp:start func_003ECD60 */
extern u8 D_001D9898_g;
extern s32 func_003ECDB8();
void func_003ECD60(u8 *p, s32 f) {
    *(u8 **)p = &D_001D9898_g;
    if (f & 1) func_003ECDB8(p);
}
/* localdecomp:end func_003ECD60 */

INCLUDE_ASM("asm/nonmatchings/text", func_003ECD90);

/* localdecomp:start func_003ECDB8 */
s32 func_003ECDB8(void) {
}
/* localdecomp:end func_003ECDB8 */

/* localdecomp:start func_003ECDC0 */
s32 func_003ECDC0(s32 a0, s32 a1) {
    return a1;
}
/* localdecomp:end func_003ECDC0 */

/* localdecomp:start func_003ECDC8 */
s32 *func_003ECDC8(s32 *p) {
    *p = 0;
    return p;
}
/* localdecomp:end func_003ECDC8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003ECDD8);

/* localdecomp:start func_003ECDE0 */
s32 func_003ECDE0(s32 *p) {
    return *p != 0;
}
/* localdecomp:end func_003ECDE0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003ECDF0);
