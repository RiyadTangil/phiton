#include <stdio.h> // define the header file
void update(int n, char a[])
{
    n++;
    printf("%d d from function",n);
    a[0] = '0';
}
int main()
{
    int n = 10;
    char a[] = "10000";
    update(n, a);
    printf("%d %s", n, a);
}