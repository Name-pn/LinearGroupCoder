#include "message.h"

void initMessage(struct message * ptr, int n) {
    ptr->bufPtr = calloc(1, n);
    ptr->n = n;
}

void freeMessage(struct message * ptr) {
    free(ptr->bufPtr);
}

void setMessage(struct message * ptr, char* str) {
    strcpy(ptr->bufPtr, str);
}

int getBiteFromChar(unsigned char c, int k) {
    int res = (c >> k) & 1;
    return res;
}

int getBite(struct message * ptr, int i) {
    int j = i / 8;
    int k = i % 8;
    int res = getBiteFromChar(ptr->bufPtr[j], k);
    return res;
}

void setBite(struct message * ptr, int i, char x) {
    int j = i / 8;
    int k = i % 8;
    if (x == 1)
        ptr->bufPtr[j] = ptr->bufPtr[j] | (1 << k);
    else
        ptr->bufPtr[j] = ptr->bufPtr[j] & (~(1 << k));
}

void writeBites(struct message * ptr, int bites) {
    for (int i = 0; i < ptr->n; ++i) {
        for (int j = 0; j < 8 && i*8+j < bites; ++j) {
            printf("%d", getBite(ptr, i*8+j));
        }
        printf(" ");
    }
}

void invertBite(struct message * ptr, int i) {
    if (getBite(ptr, i))
        setBite(ptr, i, 0);
    else
        setBite(ptr, i, 1);
}