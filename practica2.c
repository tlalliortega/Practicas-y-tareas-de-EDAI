#include <stdio.h>

int main(void) {

int a[5] = {2, 4, 6, 8, 10};

int *p = a; // p apunta a a[0]

printf("1) a[1] = %d\n", a[1]); //Imprime el numero 4 
printf("2) *(a+3) = %d\n", *(a+3));// Imprime el 8 
printf("3) *p++ = %d\n", *p++);// Imprime 2 y luego p apunta a a[1]
printf("4) *++p = %d\n", *++p); //p avanza a a[2], imprime 6
printf("5) p[1] = %d\n", p[1]); // p apunta a a[2], p[1] ≡ a[3], imprime 8
printf("6) *(p+=2) = %d\n", *(p+=2)); // p avanza a a[4], imprime 10
printf("7) p - a = %ld\n", p - a); // p apunta a a[4], a apunta a a[0], imprime 4
return 0;
}