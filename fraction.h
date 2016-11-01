#ifndef __FRACTION_H
#define __FRACTION_H

typedef struct fraction {
    double numerator;
    double denominator;
}fraction;
void fraction_init(fraction );

void print_fraction(fraction );

fraction fraction_add(fraction , fraction );

fraction fraction_subtract(fraction , fraction );

fraction fraction_multiply(fraction , fraction );

fraction fraction_divide(fraction , fraction );

fraction fraction_power(fraction , double );

#endif 
