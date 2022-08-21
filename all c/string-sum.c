#include <stdio.h>
#include <string.h>
int main()
{
    char a[100], b[100], jogfol[101];
    scanf("%s %s", &a, &b);
    strrev(a);
    strrev(b);
    int i = 0, j = 0, k = 0, hate = 0;
    while (i < strlen(a) && j < strlen(b))
    {
        int sum = (a[i] - '0') + (b[j] - '0') + hate;
        jogfol[k] = (sum % 10 + '0');
        hate = sum / 10;
        printf("hate of %d from while> %d \n", i, hate);
        i++;
        j++;
        k++;
    }
    printf("out of while hate of %d from while> %d \n", i, hate);
    // printf("after first while %s no of i %d a length %d  hate>\n", jogfol, i, strlen(a),hate);
    while (i < strlen(a))
    {
        printf("yes entered");
        int sum = (a[i] - '0') + hate;
        jogfol[k] = (sum % 10 + '0');
        hate = sum / 10;
        i++;
        k++;
    }
    printf("after 2nd while %s ", jogfol);
    while (j < strlen(b))
    {
        int sum = (b[j] - '0') + hate;
        jogfol[k] = (sum % 10 + '0');
        hate = sum / 10;
        j++;
        k++;
    }
    if (hate > 0)
    {
        printf("entered if blocked %s no of k %c\n", jogfol, hate + '0');
        jogfol[k] = (hate + '0');

    }
    strrev(jogfol);
    printf("from last print %s", jogfol);
    return 0;
}
