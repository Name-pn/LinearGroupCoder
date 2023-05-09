//
// Created by Alexandr on 08.05.2023.
//

#ifndef NETKURSOV2_MATRIX_H
#define NETKURSOV2_MATRIX_H

#define MAX_WIDTH_MATR 100
#define MAX_HEIGHT_MATR 100
#include <stdio.h>

struct matrix {
    int a[MAX_HEIGHT_MATR][MAX_WIDTH_MATR];
    int n;
    int m;
};

void initMatr(struct matrix *m, int height, int width);
void writeMatr(struct matrix *m);

#endif //NETKURSOV2_MATRIX_H
