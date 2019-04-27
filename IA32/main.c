#include<stdio.h>

int main() {
    long x = 0;
    scanf("%ld", &x);
    if (x < 5) {
        x = -10;
    }
    
    return 0;
}
