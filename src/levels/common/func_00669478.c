#include "common.h"

typedef struct {
    int id;
} Node00669478;

extern Node00669478 *D_0024D06C;
extern Node00669478 *D_001E17DC;
extern u8 D_001A5E50[];
extern int D_00240744;
extern void func_0014AD08(int, int, int, int, int, Node00669478 *);
extern void func_00669808(int, int, int, Node00669478 *);
extern Node00669478 *func_00669A08(Node00669478 *);

void func_00669478(int max)
{
    Node00669478 *n = D_0024D06C;
    int count = 0;
    u8 *g;

    if (n == 0)
        return;
    g = D_001A5E50;
    do {
        if (*(int *)(g + 368) == 0)
            func_0014AD08(g[2004] | 0x50, *(int *)(g + 4), -1, D_00240744, n->id, n);
        func_00669808(0, 0, 0, n);
        count++;
        n = func_00669A08(n);
        if (count >= max) {
            D_001E17DC = n;
            return;
        }
    } while (n != 0);
}
