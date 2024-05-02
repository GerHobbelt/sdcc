#include <stdio.h>

/* function statement */
int main(){
    int a = 1;
    int b = 10;
    int n = 100;
    while (n > 0) {
        a = a*3+ b;
        b = a*4 + 5*b+ 1;
        n = n-1;
    }
    a = a*3+ b;
    b = a*4 + 5*b+ 1;
    return a + b;
}