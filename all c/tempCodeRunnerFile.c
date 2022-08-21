#include <stdio.h>
int main()
{
    int len;
    char car[100];
    scanf("%s", &car);
    len = strlen(car);
    int arr[10] = {0};
    for (int i = 0; i < len; i++)
    {

        if (car[i] >= '0' && car[i] <= '9')
        {
            arr[car[i] - '0']++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
