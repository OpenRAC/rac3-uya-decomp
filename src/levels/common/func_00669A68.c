#include "common.h"

typedef struct Node00669A68 {
    u8 pad[128];
    struct Node00669A68 *prev;
    struct Node00669A68 *next;
} Node00669A68;

extern Node00669A68 *D_0024D060;

Node00669A68 *func_00669A68(Node00669A68 **head) {
    Node00669A68 *n = D_0024D060;
    if (n != 0 && n->next != 0) {
        D_0024D060 = n->next;
        n->next->prev = 0;
        n->prev = 0;
        n->next = *head;
        if (*head != 0) {
            (*head)->prev = n;
        }
        *head = n;
        return n;
    }
    return 0;
}
