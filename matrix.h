#ifndef __MATRIX_H
#define __MATRIX_H

typedef struct matrix {
    int m;
    int n;
    int matrix[][0];
}matrix;


void matrix_init(matrix );

int matrix_can_add(matrix , matrix );

matrix matrix_add(matrix , matrix );

int matrix_can_subtract(matrix , matrix );

matrix matrix_subtract(matrix , matrix );

int matrix_can_multiply(matrix , matrix );

matrix matrix_multiply(matrix , matrix );

int matrix_can_power(matrix m);

matrix matrix_power(matrix , unsigned  int );

void matrix_print(matrix );

#endif 
