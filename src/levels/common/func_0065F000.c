#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} Packet;

typedef struct {
    char pad0[0x2544];
    u8 unk2544;
    char pad2545[0x44ED - 0x2545];
    u8 unk44ED;
    u8 unk44EE;
} Player;

typedef struct {
    char pad0[0x4];
    s32 conn;
    char pad8[0x170 - 0x8];
    s32 unk170;
    char pad174[0x7D4 - 0x174];
    u8 unk7D4;
} Net;

extern Net D_001A5E50;
extern s32 D_00240764;
extern void func_0014AD08(s32, s32, s32, s32, s32, Packet *);

void func_0065F000(Player *p, f32 *pos, s32 a, s8 team, s32 b) {
    Packet pkt;

    pkt.b1 = p->unk2544;
    pkt.b0 = p->unk44ED;
    pkt.b2 = p->unk44EE;
    if (a) {
        pkt.b2 |= 0x40;
    }
    if (b) {
        pkt.b2 |= 0x20;
    }
    pkt.b1 |= (team + 1) << 4;
    pkt.x = pos[0];
    pkt.y = pos[1];
    pkt.z = pos[2];
    if (D_001A5E50.unk170 == 0) {
        func_0014AD08(D_001A5E50.unk7D4 | 0x80, D_001A5E50.conn, -1, D_00240764, 16, &pkt);
    }
}
