#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integer.h"
#include "fraction.h"
#include "complex.h"
#include "matrix.h"
#include "conversion.h"
#include "trigo.h"

int menu_operation();

int menu_integer();

void operation_integer();

int menu_fraction();

void operation_fraction();

void conversion();

int menu_matrix();

void operation_matrix();

void equations();

void operation_complex();

void operation_trigo();

int main() {
    while (1) {
        switch (menu_operation()) {
            case 1:
                // Integer
                operation_integer();
                break;
            case 2:
                // Fraction
                operation_fraction();
                break;
            case 3:
                // conversion
                conversion();
                break;
            case 4:
                // Matrix
                operation_matrix();
                break;
	    case 5:
		// Equations
		equations();
	    case 6:
		// Complex Numbers
		operation_complex();
	    case 7:
		//Trignometric Functions
		operation_trigo();
            default:
                return 0;
        }
    }
}

int menu_operation() {
    int n;
    while (1) {
        printf("Select an option:\n");
        printf("1 - Arithematic on Integers\n");
        printf("2 - Arithematic on Fractions\n");
        printf("3 - Conversion of numbers\n");
        printf("4 - Matries\n");
	printf("5 - Equations\n");
	printf("6 - Complex Numbers\n");
	printf("7 - Trignometric Functions");
        printf("0 - exit\n");
        scanf("%d", &n);
        if (n >= 0 && n <= 6)
            return n;
        else
            printf("Invalid Option!\n");
    }
}
int menu_integer() {
    int n;
    while (1) {
        printf("Select an operation:\n");
        printf("1 - Addition\n");
        printf("2 - Subtracttion\n");
        printf("3 - Multiplication\n");      
        printf("4 - Division\n");
	printf("5 - Power\n");	
	printf("6 - Log to base 10\n");
	printf("7 - Squareroot\n");
	printf("8 - Exponent\n");
        printf("0 - Exit\n");
        scanf("%d", &n);
        printf("\n");
        if (n >= 0 && n <= 9)
            return n;
        else
            printf("Invalid option!\n");
    }
}
void operation_integer() {
    double result,x ,y;
    float i = 0,result1;
    x = y = result = 0;
    int flag = 1;
    while (flag) {
        switch (menu_integer()) {
            case 1:
                // Add
		printf("Enter the 1st value: ");
          	scanf("%lf", &x);
                printf("Enter the next value: ");
                scanf("%lf", &y);
                printf("\n");
                result = integer_add(x, y);
		printf("Result: %lf\n", result);
                break;
            case 2:
                // Subtract
                printf("Enter the 1st value: ");
          	scanf("%lf", &x);
                printf("Enter the next value: ");
                scanf("%lf", &y);
                printf("\n");
                result = integer_subtract(x, y);
		printf("Result: %lf\n", result);
                break;
            case 3:
                // Multiply
                printf("Enter the 1st value: ");
          	scanf("%lf", &x);
                printf("Enter the next value: ");
                scanf("%lf", &y);
                printf("\n");
                result = integer_multiply(x, y);
		printf("Result: %lf\n", result);
                break;
            
            case 4:
                // Divide
                while (1) {
                    printf("Enter the 1st value: ");
          	    scanf("%lf", &x);
                    printf("Enter the next value: ");
                    scanf("%lf", &y);
                    printf("\n");
                    if (y == 0)
                        printf("Invalid value!\n");
                    else
                        break;
                }
                result = integer_divide(x, y);
		printf("Result: %lf\n", result);
                break;
	   case 5:
                // Power
                printf("Enter the 1st value: ");
          	scanf("%lf", &x);
                printf("Enter the next value: ");
                scanf("%lf", &y);
                printf("\n");
                result = integer_power(x, y);
		printf("Result: %lf\n", result);
                break;
	    case 6: 
			printf("Enter the value to find log to base ten: ");
			scanf("%f",&i);
			result1 = logten(i);
			printf("Result: %f\n", result1);     
			break;
            case 7: 
			printf("Enter the value to find Squareroot: ");
			scanf("%f",&i);
			result1 = squareroot(x);
			printf("Result: %f\n", result1);      
			break;
            case 8: 
			printf("Enter the value to find Exponent: ");
			scanf("%f",&i);
			result1 = exponent(x);   
			printf("Result: %f\n", result1);      
			break;
            default:
                flag = 0;
                break;
        }
        
    }
}
int menu_fraction() {
    int n;
    while (1) {
        printf("\nSelect an operation:\n");
        printf("1 - Add\n");
        printf("2 - Subtract\n");
        printf("3 - Multiply\n");
	printf("4 - Divide\n");
        printf("5 - Power \n");
        printf("0 - exit\n");
        scanf("%d", &n);
        printf("\n");
        if (n >= 0 && n <= 5)
            return n;
        else
            printf("Invalid option!\n");
    }
}
void operation_fraction() {
    fraction result, x, y;
    fraction_init (x);
    fraction_init (y);
    fraction_init (result);    
    int flag = 1;
    while (flag) {
        switch (menu_fraction()) {
            case 1:
                // Add
		printf("Enter the 1st numerator: ");
                scanf("%lf", &(x.numerator));
                printf("Enter the 1st denominator: ");
                scanf("%lf", &(x.denominator));
		if (x.denominator == 0)
                	printf("Denominator invalid!\n");
		printf("Enter the 2nd numerator: ");
                scanf("%lf", &(y.numerator));
                printf("Enter the 2nd denominator: ");
                scanf("%lf", &(y.denominator));
		if (y.denominator == 0)
                    	printf("Denominator invalid!\n");
                result = fraction_add(x , y);
		print_fraction(result);
                break;
            case 2:
                // Subtract
		printf("Enter the 1st numerator: ");
                scanf("%lf", &(x.numerator));
                printf("Enter the 1st denominator: ");
                scanf("%lf", &(x.denominator));
		if (x.denominator == 0)
                	printf("Denominator invalid!\n");
		printf("Enter the 2nd numerator: ");
                scanf("%lf", &(y.numerator));
                printf("Enter the 2nd denominator: ");
                scanf("%lf", &(y.denominator));
		if (y.denominator == 0)
                    	printf("Denominator invalid!\n");
                result = fraction_subtract(x, y);
		print_fraction(result);
                break;
            case 3:
                // Multiply
                printf("Enter the 1st numerator: ");
                scanf("%lf", &(x.numerator));
                printf("Enter the 1st denominator: ");
                scanf("%lf", &(x.denominator));
		if (x.denominator == 0)
                	printf("Denominator invalid!\n");
		printf("Enter the 2nd  numerator: ");
                printf("Enter the 2nd numerator: ");
                scanf("%lf", &(y.numerator));
                printf("Enter the 2nd denominator: ");
                scanf("%lf", &(y.denominator));
		if (y.denominator == 0)
                    	printf("Denominator invalid!\n");
                result = fraction_multiply(x, y);
		print_fraction(result);
                break;
	    case 4:
                // Divide
                printf("Enter the 1st numerator: ");
                scanf("%lf", &(x.numerator));
                printf("Enter the 1st denominator: ");
                scanf("%lf", &(x.denominator));
		if (x.denominator == 0)
                	printf("Denominator invalid!\n");
		printf("Enter the 2nd numerator: ");
                scanf("%lf", &(y.numerator));
                printf("Enter the 2nd denominator: ");
                scanf("%lf", &(y.denominator));
		if (y.denominator == 0)
                    	printf("Denominator invalid!\n");
                result = fraction_divide(x, y);
		print_fraction(result);
                break;
            case 5:
                // Power
                printf("Enter the  numerator: ");
                scanf("%lf", &(x.numerator));
                printf("Enter the  denominator: ");
                scanf("%lf", &(x.denominator));
		if (x.denominator == 0)
                		printf("Denominator invalid!\n");
		double n;
		printf("Enter index: ");
		scanf("%lf", &n);
		result = fraction_power(x , n);
		print_fraction(result);
                break;
            
            default:
                flag = 0;
                break;
        }
   }
}
void conversion(){
	int n, choice, y;
	printf("Enter your choice:\n");
	printf("choice\n1.dec_bin\n2.dec_hex\n3.dec_oct\n4.bin_dec\n5.bin_hex\n6.bin_oct\n7.hex_dec\n8.hex_bin\n9.hex_oct\n10.oct_dec	\n11.oct_bin\n12.oct_hex\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("enter the value for n\n");
			scanf("%d",&n);
			y=dec_bin(n);
			printf("The binary value is: %d\n",y);
		  	break;
		case 2:
			printf("enter the value for n\n");
			scanf("%d",&n);
			 dec_hex(n);
			  break;
		case 3:
			printf("enter the value for n\n");
			scanf("%d",&n);
			y= dec_oct(n);
			printf("The octal value is: %d",y);
			 break;
		case 4:
			printf("enter the value for n\n");
			scanf("%d",&n);
			y= bin_dec(n);
			printf("The decimal value is: %d",y);
			break;
		case 5:
			printf("enter the value for n\n");
			scanf("%d",&n);
			bin_hex(n);
			break;
		case 6:
			printf("enter the value for n\n");
			scanf("%d",&n);
			y=bin_oct(n);
			printf("The octal value is: %d",y);
			break;
		case 7:
			y=hex_dec();
			printf("The decimal value is: %d",y);
			break;
		case 8:
			y=hex_bin();
			printf("The binary value is: %d",y);
			break;
		case 9:
			y=hex_oct();
			printf("The Octal value is: %d",y);
			break;
		case 10:
			printf("enter the value for n\n");
			scanf("%d",&n);
			y=oct_dec(n);
			printf("The Decimal value is: %d",y);
			break;
		case 11:
			printf("enter the value for n\n");
			scanf("%d",&n);
			y=oct_bin(n);
			printf("The Binary value is: %d",y);
			break;
	
		case 12:
			printf("enter the value for n\n");
			scanf("%d",&n);
			oct_hex(n);
			break;
		default:
			printf("Invalid Option!");
			break;
}
int menu_matrix() {
    int n;
    while (1) {
        printf("Select an operation:\n");
        printf("1 - Add\n");
        printf("2 - Subtrat\n");
        printf("3 - Multiply\n");
        printf("4 - Power\n");
        printf("0 - Exit\n");
        scanf("%d", &n);
        if (n >= 0 && n <= 4)
            return n;
        else
            printf("Invalid option!\n");
    }
}

void operation_matrix() {
    matrix x, y, result;
    unsigned int index;
    int i, j, num;
    matrix_init(x);
    matrix_init(y);
    matrix_init(result);    
    
    int flag = 1;
    while (flag) {
        switch (flag) {
            case 1 :
                // Add
                printf("Enter the number of rows of the 1st matrix: ");
                scanf("%d", &x.m);
        	if (x.m == 0){
            		printf("Invalid value!\n");
	    		return ;
		}
       		printf("Enter the number of columns of the 1st matrix: ");
        	scanf("%d", &x.n);
        	if (y.n == 0){
            		printf("Invalid value!\n");
	    		return ;
		}
    		printf("Enter the elements of the 1st matrix, separated by spaces and / or line breaks:\n");
    		for (i = 0; i < x.m; i++){
        		for (j = 0; j < y.n; j++) {
            		scanf("%d", &num);
            		x.matrix[i][j] = num ;
        		}
    		}
		printf("Enter the number of rows of the 2nd matrix: ");
                scanf("%d", &y.m);
        	if (y.m == 0){
            		printf("Invalid value!\n");
	    		return ;
		}
       		printf("Enter the number of columns of the 2nd matrix: ");
        	scanf("%d", &y.n);
        	if (y.n == 0){
            		printf("Invalid value!\n");
	    		return ;
		}
		if (!matrix_can_add(x, y)){
                        printf("Its not possible to add the two given matrices because their orders are not same\n");
			return;
		}
    		printf("Enter the elements of the 2nd matrix, separated by spaces and / or line breaks:\n");
    		for (i = 0; i < y.m; i++){
        		for (j = 0; j < y.n; j++) {
            		scanf("%d", &num);
            		y.matrix[i][j] = num ;
        		}
    		}
                result = matrix_add(x, y);
		matrix_print(result);
                break;
            case 2 :
                // Subtract
                printf("Enter the number of rows of the 1st matrix: ");
                scanf("%d", &x.m);
        	if (x.m == 0){
            		printf("Invalid value!\n");
	    			return ;
		}
       		printf("Enter the number of columns of the 1st matrix: ");
        	scanf("%d", &x.n);
        	if (y.n == 0){
            		printf("Invalid value!\n");
	    		return ;
		}
    		printf("Enter the elements of the 1st matrix, separated by spaces and / or line breaks:\n");
    		for (i = 0; i < x.m; i++){
        		for (j = 0; j < y.n; j++) {
            		scanf("%d", &num);
            		x.matrix[i][j] = num ;
        		}
    		}
		printf("Enter the number of rows of the 2nd matrix: ");
                scanf("%d", &y.m);
        	if (y.m == 0){
            		printf("Invalid value!\n");
	    		return ;
		}
       		printf("Enter the number of columns of the 2nd matrix: ");
        	scanf("%d", &y.n);
        	if (y.n == 0){
            		printf("Invalid value!\n");
	    		return ;
		}
                   
                if (!matrix_can_subtract(x, y)){
                        printf("Its not possible to substract the two given matrices because their orders are not same\n");
			return ;
		}
		printf("Enter the elements of the 2nd matrix, separated by spaces and / or line breaks:\n");
    		for (i = 0; i < y.m; i++){
        		for (j = 0; j < y.n; j++) {
            		scanf("%d", &num);
            		y.matrix[i][j] = num ;
        		}
    		}
                result = matrix_subtract(x, y);
		matrix_print(result);
                break;
            case 3 :
                // Multiply
                printf("Enter the number of rows of the 1st matrix: ");
                scanf("%d", &x.m);
        	if (x.m == 0){
            		printf("Invalid value!\n");
	    		return ;
		}
       		printf("Enter the number of columns of the 1st matrix: ");
        	scanf("%d", &x.n);
        	if (y.n == 0){
            		printf("Invalid value!\n");
	    		return ;
		}
    		printf("Enter the elements of the 1st matrix, separated by spaces and / or line breaks:\n");
    		for (i = 0; i < x.m; i++){
        		for (j = 0; j < y.n; j++) {
            		scanf("%d", &num);
            		x.matrix[i][j] = num ;
        		}
    		}
		printf("Enter the number of rows of the 2nd matrix: ");
                scanf("%d", &y.m);
        	if (y.m == 0){
            		printf("Invalid value!\n");
	    		return ;
		}
       		printf("Enter the number of columns of the 2nd matrix: ");
        	scanf("%d", &y.n);
        	if (y.n == 0){
            		printf("Invalid value!\n");
	    		return ;
		}
		if (!matrix_can_multiply(x, y)){
                     printf("Its not possible to multiply both the matrices because number of colmuns of 1st matrix are\n");
		     printf("not equal to number of rows of 2nd matrix\n");
                        return ;
                }
                printf("Enter the elements of the 2nd matrix, separated by spaces and / or line breaks:\n");
    		for (i = 0; i < y.m; i++){
        		for (j = 0; j < y.n; j++) {
            		scanf("%d", &num);
            		y.matrix[i][j] = num ;
        		}
    		}
                result = matrix_multiply(x ,y);
		matrix_print(result);
                break;

            case 4 :

                // Power
		
		printf("Enter the number of rows of the matrix: ");
                scanf("%d", &x.m);
        	if (x.m == 0){
            		printf("Invalid value!\n");
	    		return ;
		}
       		printf("Enter the number of columns of the matrix: ");
        	scanf("%d", &x.n);
        	if (y.n == 0){
            		printf("Invalid value!\n");
	    		return ;
		}
    		printf("Enter the elements of the matrix, separated by spaces and / or line breaks:\n");
    		for (i = 0; i < x.m; i++){
        		for (j = 0; j < y.n; j++) {
            		scanf("%d", &num);
            		x.matrix[i][j] = num ;
        		}
    		}
                if (matrix_can_power(x)) {
                    
                        printf("Enter the index : ");
                        scanf("%d", &index);
                        if (index >= 0) {
                            result = matrix_power(x, index);
                            break;
                        } 
			else
                            printf("Invalid value!\n");
                    
                } 
		else {
                    printf("It is not possible to perform the power operation with the current matrix!\n");
                    break;
		}

            default : 
			flag = 0;
                	break;
       	} 	    
       }
}

void equations(){
	float a,b,c,d,e,f;
	float x,y,root1,root2;
	int choice;
	printf("enter your choice\n 1.linear equation\n 2.quadratic equation\n");
	scanf("%d",&choice);
	switch(choice)
		{
			case 1:
				printf("enter the values of a, b, c, d, e, f:\n  ex: ax+by+c=0\t\n      dx+ey+f=0\n");
				scanf("%f%f%f%f%f%f",&a,&b,&c,&d,&e,&f);
				x=((f*b)-(c*e))/((a*e)-(d*b));
	                        y=((c*d)-(f*a))/((a*e)-(d*b));
				printf("result is: %f  %f\n",x,y);
				break;
	
			case 2:
				printf("enter values of a, b, c: \n like ax^2+bx+c=0\n");
				scanf("%f%f%f",&a,&b,&c);
				printf("%f+sqrt(%f)\n",((-b)/(2*a)),((b*b-4*a*c)/((2*a)*(2*a))));
				printf("%f-sqrt(%f)\n",((-b)/(2*a)),((b*b-4*a*c)/((2*a)*(2*a))));
				break;

			default:
				printf("unable to understand your choice\n");
		}
}
void operation_complex(){
  int choice, temp1, temp2, temp3;
  struct complex a, b, c;
 
  while(1)
  {
    	printf("1 - Addition\n");
        printf("2 - Subtraction\n");
        printf("3 - Multiplication\n");
        printf("4 - Division\n");
        printf("0 - Exit\n");
    	scanf("%d",&choice);
 
    if( choice == 0)
      exit(0);
 
    if(choice >= 1 && choice <= 4)
    {
      printf("Enter a and b where a + ib is the first complex number.");
      printf("\na = ");
      scanf("%d", &a.real);
      printf("b = ");
      scanf("%d", &a.img);
      printf("Enter c and d where c + id is the second complex number.");
      printf("\nc = ");
      scanf("%d", &b.real);
      printf("d = ");
      scanf("%d", &b.img);
    }
    if ( choice == 1 )
    {
      c.real = a.real + b.real;
      c.img = a.img + b.img;
 
      if ( c.img >= 0 )
        printf("Sum of two complex numbers = %d + %di",c.real,c.img);
      else
        printf("Sum of two complex numbers = %d %di",c.real,c.img);
    }
    else if ( choice == 2 )
    {
      c.real = a.real - b.real;
      c.img = a.img - b.img;
 
      if ( c.img >= 0 )
        printf("Difference of two complex numbers = %d + %di",c.real,c.img);
      else
        printf("Difference of two complex numbers = %d %di",c.real,c.img);
    }
    else if ( choice == 3 )
    {
      c.real = a.real*b.real - a.img*b.img;
      c.img = a.img*b.real + a.real*b.img;
 
      if ( c.img >= 0 )
        printf("Multiplication of two complex numbers = %d + %di",c.real,c.img);
      else
        printf("Multiplication of two complex numbers = %d %di",c.real,c.img);
    }
    else if ( choice == 4 )
    {
      if ( b.real == 0 && b.img == 0 )
        printf("Division by 0 + 0i is not allowed.");
      else
      {
        temp1 = a.real*b.real + a.img*b.img;
        temp2 = a.img*b.real - a.real*b.img;
        temp3 = b.real*b.real + b.img*b.img;
 
        if ( temp1%temp3 == 0 && temp2%temp3 == 0 )
        {
          if ( temp2/temp3 >= 0)
            printf("Division of two complex numbers = %d + %di",temp1/temp3,temp2/temp3);
          else
            printf("Division of two complex numbers = %d %di",temp1/temp3,temp2/temp3);
        }
        else if ( temp1%temp3 == 0 && temp2%temp3 != 0 )
        {
          if ( temp2/temp3 >= 0)
            printf("Division of two complex numbers = %d + %d/%di",temp1/temp3,temp2,temp3);
          else
            printf("Division of two complex numbers = %d %d/%di",temp1/temp3,temp2,temp3);
        }
        else if ( temp1%temp3 != 0 && temp2%temp3 == 0 )
        {
          if ( temp2/temp3 >= 0)
            printf("Division of two complex numbers = %d/%d + %di",temp1,temp3,temp2/temp3);
          else
            printf("Division of two complex numbers = %d %d/%di",temp1,temp3,temp2/temp3);
        }
        else
        {
          if ( temp2/temp3 >= 0)
            printf("Division of two complex numbers = %d/%d + %d/%di",temp1,temp3,temp2,temp3);
          else
            printf("Division of two complex numbers = %d/%d %d/%di",temp1,temp3,temp2,temp3);
        }
      }
    }
    else
      printf("Invalid choice.");
 
    printf("\nPress any key to enter choice again...\n");
  }
 }
}
void operation_trigo(){
    int n;
    float x, answer;
    printf("1.sin \n2.cos\n3.tan\n4.sinh\n5.cosh\n6.tanh\n");
    scanf ("%d",&n);
    printf("\n Enter value of x: ");
    scanf("%f",&x);
    	switch (n){
        	case 1: answer = sine(x);       
			break;
        	case 2: answer = cosine(x);     
			break;
        	case 3: answer = tangent(x);    
			break;
        	case 4: answer = sineh(x);      
			break;
        	case 5: answer = cosineh(x);    
			break;
        	case 6: answer = tangenth(x);   
			break;
        	default:
			printf("Invalid Option!\n");
			break;
		}
	printf("Result :%f\n",answer);
}
