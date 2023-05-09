#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct message {
    char* bufPtr;
    int n;
};

void writeBites(struct message * ptr, int bites);
void initMessage(struct message * ptr, int n);
void freeMessage(struct message * ptr);
void setMessage(struct message * ptr, char* str);
int getBite(struct message * ptr, int i);
void setBite(struct message * ptr, int i, char x);
void invertBite(struct message * ptr, int i);

#endif