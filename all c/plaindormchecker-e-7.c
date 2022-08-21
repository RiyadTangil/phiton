#include <stdio.h>
#include <string.h>
int main()
{
    char a[100];
    scanf("%s", &a);
    int i = 0;
    int j = strlen(a) - 2;
    while (i < j)
    {
        if (a[i] != a[j])
        {
            printf("No\n");
            break;
        }
    }
}