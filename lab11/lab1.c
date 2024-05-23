#include <stdio.h> 
#include <math.h> 
 
int factorial(int a) 
{ 
    if( a == 0||a == 1) 
        return 1; 
    return a * factorial(a-1); 
} 
 
double sina(double x, int n) 
{ 
    double F = (pow(x, 2*n-1)/factorial(2*n-1)); 
 
    if(F < pow(10, -2)) 
        return F; 
    return pow(-1,n-1) * F + sina(x, n +1); 
} 
 
int main() 
{ 
    printf("Enter argument for sin: "); 
    double x; 
    scanf("%lf", &x); 
    printf("%lf \n", sina(x, 1)); 
    printf("%lf \n", sin(x)); 
}