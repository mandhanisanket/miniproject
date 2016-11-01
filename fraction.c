#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"

void print_fraction(fraction x){
	printf(" \n Result is :");
	printf("Numerator = %lf \n", x.numerator);
	printf("Denominator = %lf \n", x.denominator);
}	
void fraction_init(fraction f) {
	f.numerator = 0;
	f.denominator = 0;
}

fraction fraction_add(fraction x, fraction y) {
	fraction f;
	x.numerator = x.numerator * y.denominator;
	y.numerator = y.numerator * x.denominator;
	f.numerator = x.numerator + y.numerator;
	f.denominator =x.denominator * y.denominator;
	return f;
}

fraction fraction_subtract(fraction x, fraction y) {
	fraction f;
	x.numerator *= y.denominator;
	y.numerator *= x.denominator;
	f.numerator = x.numerator - y.numerator;
	f.denominator =x.denominator * y.denominator;
	return f;
}

fraction fraction_multiply(fraction x, fraction y) {
	fraction f;
	f.numerator =x.numerator * y.numerator;
	f.denominator =x.denominator * y.denominator;
	return f;
}

fraction fraction_divide(fraction x, fraction y) {
	fraction f;
	f.numerator = x.numerator * y.denominator;
	f.denominator = x.denominator *= y.numerator;
	return f;
}

fraction fraction_power(fraction f, double power) {
	f.numerator = pow(f.numerator, power);
	f.denominator = pow(f.denominator, power);
	return f;
}
