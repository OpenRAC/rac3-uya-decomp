#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_0040A590);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_0040A760);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_0040ACC8);

LINKER_REMNANT("asm/veldin/remnants", func_0040AD50);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_0040AD60);

/* localdecomp:start func_0040AE68 */
extern int func_00440848_40AE68(int);
extern float func_004408C0_40AE68(float, float);
extern void func_0040B040_40AE68(void *, int, float);
extern void func_0040B290_40AE68(void *, int, float);
extern void func_00437698_40AE68(void *, int, void *);
extern void func_0032FE90(void *, int, int, int, int, int, int, int,
    float, float, float, float,
    int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
extern int D_001DFBC0_40AE68[];
void func_0040AE68(void *a, int n, int *arr, float scale) {
    int i;
    char buf[0x10];
    if (n > 0) {
    for (i = 0; i < n; i++) {
        if (func_00440848_40AE68(2)) {
            func_0040B040_40AE68(a, arr[i], func_004408C0_40AE68(0.5f, 0.9f) * scale);
            func_0040B290_40AE68(a, arr[i], func_004408C0_40AE68(0.5f, 0.7f) * scale);
        }
    }
    if (D_001DFBC0_40AE68[0] % 80 == 0) {
        func_00437698_40AE68(a, arr[func_00440848_40AE68(n)], buf);
        func_0032FE90(buf, 0, 5, 0, 5, 10, 0, 0, 0.5f, 0.0f, 0.0f, 2.0f,
            0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388ef7, 0x63f7, 0x407fff, 0x20ff, 0x8fff, 0x3064ff, 0x7f60a0ff, 0x280000ff, 0x3064ff, 0);
    }
    }
}
/* localdecomp:end func_0040AE68 */

/* localdecomp:start func_0040B040 */
typedef struct { char pad[0x10]; float x, y; } A_40B040;
typedef struct { char pad[0x140]; float x, y; } G_40B040;
typedef struct { char p0[3]; unsigned char b3; char p4[5]; unsigned char b9; unsigned short ha; char pad[0x16]; } W0_40B040;
typedef struct { char p[4]; int w4; char p8[2]; unsigned char ba; unsigned char bb; char pc[0x10]; float f1c; } W1_40B040;
typedef struct { char p0[3]; unsigned char b3; char p4[5]; unsigned char b9; unsigned char ba; char p[0x15]; W1_40B040 w; } W_40B040;
extern float D_001E2900_40B040[];
extern void func_00437698_40B040(void *, int, float *);
extern float func_0040C490_40B040(float, float);
extern float func_0040CEC8_40B040(float, float);
extern float func_00440918_40B040(float, float);
extern float func_004408C0_40B040(float, float);
extern void func_00440CF8_40B040(float *, float, float, float);
extern int func_00440878_40B040(int, int);
extern char *func_004633E8_40B040(float *, float, float, float, float, int, float *, int, int);
void func_0040B040(A_40B040 *o, int arg, float scale) {
    float v0[4], v10[4], v20[4];
    float ang, spd, el, r;
    char *w, *w2;
    func_00437698_40B040(o, arg, v0);
    ang = func_0040C490_40B040(D_001E2900_40B040[0x50] - o->x, D_001E2900_40B040[0x51] - o->y);
    v10[0] = v0[0] + func_00440918_40B040(0.0f, scale);
    v10[1] = v0[1] + func_00440918_40B040(0.0f, scale);
    v10[2] = v0[2] + func_00440918_40B040(0.0f, scale);
    spd = func_004408C0_40B040(scale * 0.5f * (1.0f / 60.0f), scale * 1.3f * (1.0f / 60.0f));
    el = func_00440918_40B040(0.6981317f, 0.87266463f);
    r = func_00440918_40B040(0.0f, 1.5707964f);
    ang = func_0040CEC8_40B040(ang, r);
    func_00440CF8_40B040(v20, spd, ang, el);
    v20[2] += func_004408C0_40B040(0.9f, 1.7f) * (1.0f / 60.0f);
    w = func_004633E8_40B040(v10, 0.0f, 1.0f, 1.01f, scale * 1.4f * 210000.0f, -1, v20, 0x101010, 0);
    if (w) {
        w[3] = 0x44;
        *(short *)(w + 0xa) = func_00440878_40B040(0x28, 0x46);
        *(unsigned char *)(w + 9) = 100;
        w2 = w + 0x20;
        {
            float f = (float)func_00440878_40B040(1, 10);
            *(int *)(w2 + 4) = 3;
            *(unsigned char *)(w2 + 0xa) = 0x7f;
            *(float *)(w2 + 0x1c) = f;
        }
        *(unsigned char *)(w2 + 0xb) = *(unsigned char *)(w + 0xa);
    }
}
/* localdecomp:end func_0040B040 */

/* localdecomp:start func_0040B290 */
typedef struct { char pad[0x10]; float x, y; } A_40B290;
typedef struct { char pad[0x140]; float x, y; } G_40B290;
typedef struct { char p0[3]; unsigned char b3; char p4[5]; unsigned char b9; unsigned short ha; char pad[0x16]; } W0_40B290;
typedef struct { char p[4]; int w4; char p8[2]; unsigned char ba; unsigned char bb; char pc[0x10]; float f1c; } W1_40B290;
typedef struct { char p0[3]; unsigned char b3; char p4[5]; unsigned char b9; unsigned char ba; char p[0x15]; W1_40B290 w; } W_40B290;
extern float D_001E2900_40B290[];
extern void func_00437698_40B290(void *, int, float *);
extern float func_0040C490_40B290(float, float);
extern float func_0040CEC8_40B290(float, float);
extern float func_00440918_40B290(float, float);
extern float func_004408C0_40B290(float, float);
extern void func_00440CF8_40B290(float *, float, float, float);
extern int func_00440878_40B290(int, int);
extern char *func_004633E8_40B290(float *, float, float, float, float, int, float *, int, int);
void func_0040B290(A_40B290 *o, int arg, float scale) {
    float v0[4], v10[4], v20[4];
    float ang, spd, el, r;
    char *w, *w2;
    func_00437698_40B290(o, arg, v0);
    ang = func_0040C490_40B290(D_001E2900_40B290[0x50] - o->x, D_001E2900_40B290[0x51] - o->y);
    v10[0] = v0[0] + func_00440918_40B290(0.0f, scale);
    v10[1] = v0[1] + func_00440918_40B290(0.0f, scale);
    v10[2] = v0[2] + func_00440918_40B290(0.0f, scale);
    spd = func_004408C0_40B290(scale * 0.5f * (1.0f / 60.0f), scale * (1.0f / 60.0f));
    el = func_00440918_40B290(0.0f, 1.3962634f);
    r = func_00440918_40B290(0.0f, 1.5707964f);
    ang = func_0040CEC8_40B290(ang, r);
    func_00440CF8_40B290(v20, spd, ang, el);
    v20[2] += func_004408C0_40B290(0.7f, 1.2f) * (1.0f / 60.0f);
    w = func_004633E8_40B290(v10, 0.0f, 1.0f, 1.01f, scale * 210000.0f, -1, v20, 0x3582b5bd, 0);
    if (w) {
        w[3] = 0x48;
        *(short *)(w + 0xa) = func_00440878_40B290(0x46, 0x82);
        *(unsigned char *)(w + 9) = 100;
        w2 = w + 0x20;
        {
            float f = (float)func_00440878_40B290(1, 10);
            *(int *)(w2 + 4) = 3;
            *(unsigned char *)(w2 + 0xa) = 0x7f;
            *(float *)(w2 + 0x1c) = f;
        }
        *(unsigned char *)(w2 + 0xb) = *(unsigned char *)(w + 0xa);
    }
}
/* localdecomp:end func_0040B290 */

LINKER_REMNANT("asm/veldin/remnants", func_0040B4B8);
