#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
   unsigned int a = 60;	/* 60 = 0011 1100 */  
   unsigned int b = 13;	/* 13 = 0000 1101 */
   int c = 0;
    c = a ^ b;       /* 49 = 0011 0001 */
   printf("XOR - Value of c is %d\n", c );
}
