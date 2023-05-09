//
// Created by Alexandr on 08.05.2023.
//

#include "matrix.h"

void initMatr(struct matrix *m, int height, int width) {
    m->n = height;
    m->m = width;
}

void writeMatr(struct matrix *m) {
    for (int i = 0; i < m->n; ++i) {
        for (int j = 0; j < m->m; ++j) {
            printf("%i ", m->a[i][j]);
        }
        printf("\n");
    }
}