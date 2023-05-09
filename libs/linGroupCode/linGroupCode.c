#include "linGroupCode.h"

void step(int* i, int *j, int n) {
    if (*j < n - 1)
        (*j)++;
    else {
        (*i)++;
        *j = (*i) + 1;
    }
}

void initBitesRecord(struct linGroup *lg, int i) {
    int index = i - 1;
    int j = 0;
    while (i) {
        if ((i & 1) != 0) {
            for (int k = 0; k < lg->n; k++)
                if (lg->g.a[j][k])
                    invertBite(&lg->table[index].code, k);
        }
        i >>= 1;
        j++;
    }
}

int find(struct linGroup *lg, char c) {
    for (int i = 0; i < lg->letters; ++i) {
        if (lg->table[i].c == c)
            return i;
    }
    return -1;
}

void insertCode(struct linGroup *lg, char c, int poz) {
    int index = find(lg, c);
    if (index == -1) {
        ERROR;
    }
    for (int i = 0; i < lg->n; ++i) {
        setBite(&lg->msg, poz + i, getBite(&lg->table[index].code, i));
    }
}

struct linGroup *initGroup(struct message *msg) {
    struct linGroup *answ = calloc(1, sizeof(struct linGroup));
    for (int i = 0; i < msg->n; ++i) {
        (answ->t[(unsigned char)msg->bufPtr[i]])++;
    }
    answ->i = 0;
    for (int i = 0; i < 256; ++i) {
        if (answ->t[i]) {
            answ->i++;
        }
    }
    answ->letters = answ->i;
    answ->num_letters = msg->n;
    answ->i = ceil(log2(answ->i));
    answ->k = ceil(log2(answ->i+1 + ceil(log2(answ->i+1))));
    answ->n = answ->k + answ->i;
    initMessage(&answ->msg, answ->num_letters*answ->n / 8 + (answ->num_letters*answ->n % 8 != 0));
    initMatr(&answ->g, answ->i, answ->i+answ->k);
    for (int i = 0; i < answ->g.n; ++i) {
        answ->g.a[i][i] = 1;
    }
    for (int i = answ->i; i < answ->n; ++i) {
        answ->g.a[0][i] = 1;
    }
    int i = answ->i;
    int j = i+1;
    int k = 1;
    while (k < answ->i) {
        answ->g.a[k][i] = 1;
        answ->g.a[k][j] = 1;
        step(&i, &j, answ->n);
        k++;
    }
    i = 0;
    for (int l = 0; l < 256; ++l) {
        if (answ->t[l]) {
            answ->table[i].c = (char)l;
            initMessage(&answ->table[i].code, answ->n);
            initBitesRecord(answ, i+1);
            i++;
        }
    }
    for (int l = 0; l < msg->n; ++l) {
        insertCode(answ, msg->bufPtr[l], l * answ->n);
    }
    return answ;

}

int weight(struct linGroup *group, int i) {
    int res = 0;
    for (int j = 0; j < group->n; ++j) {
        res += group->g.a[i][j];
    }
    return res;
}

int minWeight(struct linGroup * group) {
    int res = weight(group, 0);
    for (int i = 1; i < group->i; ++i) {
        int tmp = weight(group, i);
        if (tmp < res)
            res = tmp;
    }
    return res;
}

int distance(struct linGroup *group, int i1, int i2) {
    int res = 0;
    for (int i = 0; i < group->n; ++i) {
        if (group->g.a[i1][i] != group->g.a[i2][i])
            res++;
    }
    return res;
}

int minDistance(struct linGroup * group) {
    int res = distance(group, 0, 1);
    for (int i = 0; i < group->i; ++i) {
        for (int j = i+1; j < group->n; ++j) {
            if (distance(group, i, j) < res)
                res = distance(group, i, j);
        }
    }
    return res;
}

void writeCodes(struct linGroup *lg) {
    for (int i = 0; i < lg->letters; ++i) {
        printf("Letter = %c, codes = ", lg->table[i].c);
        writeBites(&lg->table[i].code, lg->n);
        printf("\n");
    }
}

void writeMsg(struct linGroup *lg) {
    writeBites(&lg->msg, lg->num_letters*lg->n);
}

void makeError(struct linGroup *lg) {
    int num = lg->n*lg->num_letters;
    srand(time(NULL));
    int poz = rand() % num;
    printf("Сгенерирована ошибка в разряде %i\n", poz);
    invertBite(&lg->msg, poz);
}

void initS(struct linGroup *lg, int i) {
    int index = i - lg->n;
    for (int j = 0; j < lg->i; ++j) {
        if (lg->g.a[j][i-lg->k])
            lg->m.a[j][i] = 1;
    }
    lg->m.a[i-lg->k][i] = 1;
}

void initMatrS(struct linGroup *lg) {
    initMatr(&lg->m, lg->n, lg->n+lg->k);
    for (int i = 0; i < lg->n; ++i) {
        lg->m.a[i][i] = 1;
    }
    for (int i = 0; i < lg->k; ++i) {
        initS(lg, i+lg->n);
    }
}

int findElS(struct linGroup *lg, int j, int i) {
    int res = 0;
    for (int k = 0; k < lg->n; ++k) {
        if (lg->m.a[k][j+lg->n])
            res = res ^ getBite(&lg->msg, i+k);
    }
    return res;
}

struct matrix findS(struct linGroup *lg, int i) {
    struct matrix res;
    initMatr(&res, 1, lg->k);
    for (int j = 0; j < lg->k; ++j) {
        res.a[0][j] = findElS(lg, j, i*lg->n);
        printf("%d", res.a[0][j]);
    }
    printf("\n");
    return res;
}

int isOk(struct matrix *v, int n) {
    for (int i = 0; i < n; ++i) {
        if (v->a[0][i] != 0)
            return 0;
    }
    return 1;
}

int findSInMatr(struct matrix *m, struct linGroup *lg) {
    fflush(stdout);
    for (int i = 0; i < lg->n; ++i) {
        int f = 1;
        for (int j = 0; j < lg->k && f; ++j) {
            if (lg->m.a[i][j+lg->n] != m->a[0][j]) {
                f = 0;
            }
        }
        if (f)
            return i;
    }
    return -1;
}

void fixError(struct linGroup * lg) {
    initMatrS(lg);
    writeMatr(&lg->m);
    for (int i = 0; i < lg->num_letters; ++i) {
        printf("Синдром %d-й буквы = ", i);
        struct matrix m = findS(lg, i);
        if (!isOk(&m, lg->k)) {
            int k = findSInMatr(&m, lg);
            if (k == -1)
                ERROR;
            invertBite(&lg->msg, k + lg->n*i);
            printf("k + lg->n*i = %d\nfindSInMatr = %d\n", k + lg->n*i, k);
            printf("Синдром %d-й буквы после обработки ошибки = ", i);
            m = findS(lg, i);
        }
    }
}

int isEqual(struct message *msg, int msgPoz, struct tableEl *rec, int n) {
    for (int i = 0; i < n; ++i) {
        if (getBite(msg, msgPoz + i) != getBite(&rec->code, i))
            return 0;
    }
    return 1;
}

void toText(struct linGroup *lg, char* str) {
    int k = 0;
    for (int i = 0; i < lg->num_letters; ++i) {
        for (int j = 0; j < lg->letters; ++j) {
            if (isEqual(&lg->msg, i * lg->n, &lg->table[j], lg->n)) {
                str[k++] = lg->table[j].c;
                break;
            }
        }
    }
    str[k] = 0;
}