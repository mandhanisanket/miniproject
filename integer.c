#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"integer.h"

double integer_add(double x, double y) {
    return (x + y);
}

double integer_subtract(double x, double y) {
    return (x - y);
}

double integer_multiply(double x, double y) {
    return (x * y);
}

double integer_divide(double x, double y) {
    return (x/y);
}

double integer_power(double i, double power) {
    return (pow(i, power));
}
float logten(float x){
	return (log10(x));
}
float squareroot(float x){
	return (sqrt(x));
}
float exponent(float x){
	return(exp(x));
}
