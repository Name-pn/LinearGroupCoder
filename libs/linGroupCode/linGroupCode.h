#ifndef LINGROUPCODE_H
#define LINGROUPCODE_H
#include "../matrix/matrix.h"
#include "../message/message.h"
#include <math.h>

#define ERROR printf("Error in function %s\n", __FUNCTION__)
#include <time.h>
struct tableEl {
    struct message code;
    char c;
};

struct linGroup {
    struct matrix g;
    struct matrix m;
    char t[256];
    struct tableEl table[256];
    int k;
    int n;
    int i;
    int letters;
    int num_letters;
    struct message msg;
};

struct linGroup *initGroup(struct message *);
int minWeight(struct linGroup *);
int minDistance(struct linGroup *);
void writeCodes(struct linGroup *);
void writeMsg(struct linGroup *);
void makeError(struct linGroup *);
void fixError(struct linGroup *);
void toText(struct linGroup *, char*);
#endif