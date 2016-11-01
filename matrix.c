#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void matrix_init(matrix x) {
    x.m = x.n = 0;
    x.matrix[x.m][x.n] = 0;
}

int matrix_can_add(matrix x, matrix y) {
    return x.m == y.m && x.n == y.n;
}

matrix matrix_add(matrix x, matrix y) {
    matrix tmp;
    int i, j;
    for (i = 0; i < x.m; i++) {
        for (j = 0; j < x.n; j++)
            tmp.matrix[i][j] = x.matrix[i][j] + y.matrix[i][j];
    }
    return tmp;
}

int matrix_can_subtract(matrix x, matrix y) {
    return x.m == y.m && x.n == y.n;
}

matrix matrix_subtract(matrix x, matrix y) {
    matrix tmp;
    for (int i = 0; i < x.m; i++) {
        for (int j = 0; j < x.n; j++)
            tmp.matrix[i][j] = x.matrix[i][j] - y.matrix[i][j];
    }
    return tmp;
}

int matrix_can_multiply(matrix x, matrix y) {
    return x.n == y.m;
}

matrix matrix_multiply(matrix x, matrix y) {
    matrix tmp;
    tmp.m = x.m ;
    tmp.n = y.n ;
    int i, j ,k;
    for (i = 0; i < tmp.m; i++) {
        for (j = 0; j < tmp.n; j++) 
            tmp.matrix[i][j] = 0;
    }
    for (i = 0; i < x.m; i++) {
        for (j = 0; j < y.n; j++){        
		for (k = 0; k < x.n; k++)
                	tmp.matrix[i][j] += x.matrix[i][k] * y.matrix[k][j];
	}	
    }
    return tmp;
}

int matrix_can_power(matrix x) {
    return x.m == x.n;
}

matrix matrix_power(matrix x, unsigned int power) {
	matrix tmp;
	int i;
	tmp.m = x.m;
	tmp.n = x.n;
	for (int i = 0; i < tmp.m; i++)
            for (int j = 0; j < tmp.n; j++) {
                if (i == j)
                    tmp.matrix[i][j] = 1;
                else
                    tmp.matrix[i][j] = 0;
            }

    
	if (power == 0)
		return tmp;
        else {
        	for (i = 0; i < power; i++)
             		tmp =matrix_multiply(tmp, x);
		return tmp;
	}
}

void matrix_print(matrix x) {
    int i, j;
    for (i= 0; i < x.m; i++) {
        for (j = 0; j < x.n; j++)
            printf("%12d ", x.matrix[i][j]);
        printf("\n");
    }
}
