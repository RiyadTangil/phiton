// #include <stdio.h>
// #include <string.h>
// int main()
// {

//     char car[1001];
//     scanf("%s", &car);
//     int n = strlen(car);
//     int arr[10] = {0};
//     for (int i = 0; i < n; i++)
//     {

//         if (car[i] >= '0' && car[i] <= '9')
//         {
//             arr[car[i] - '0']++;
//         }
//     }

//     for (int i = 0; i < 10; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     int no;
//     scanf("%d", &no);
//     int resArray[no];
//     for (int j = 0; j < no; j++)
//     {
//         int n, result = -1;
//         scanf("%d", &n);
//         int arr[n], arr2[n + 1];
//         memset(arr2, 0, sizeof(arr2));
//         for (int i = 0; i < n; i++)
//         {
//             scanf("%d", &arr[i]);
//             arr2[arr[i]]++;
//             if (arr2[arr[i]] > 2)
//             {
//                 result = arr[i];
//             }
//         }
//         // resArray[j] = result;
//         printf("%d\n", result);
//     }

//     // for (int i = 0; i < no; i++)
//     // {
//     //     printf("%d\n", resArray[i]);
//     //     // if (i != no - 1)
//     //     // {

//     //     //     printf("\n");
//     //     // }
//     // }
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     int sum = 0, n, m;
//     scanf("%d", &n);
//     while (n > 0)
//     {
//         m = n % 10;
//         sum += m;
//         n = n / 10;
//     }
//     printf("%d", sum);
//     return 0;
// }
// #include <stdio.h>
// #include <string.h>
// int main()
// {

//     int n, setNumber = 0;
//     scanf("%d", &n);
//     char name[n];
//     scanf("%s", &name);
//     int matched[n + 1];
//     memset(matched, 0, n);
//     for (int i = 0; i < n; i++)
//     {
//         if (name[i] == 'n')
//         {
//             matched[1] = matched[1] + 1;
//         }
//         else if (name[i] == 'z')
//         {
//             matched[0] = matched[0] + 1;
//         }
//     };
//     for (int i = 0; i < matched[1]; i++)
//     {
//         printf("%d ", 1);
//     }
//     for (int i = 0; i < matched[0]; i++)
//     {
//         printf("%d ", 0);
//     }
// printf("length =>%d isupper=>%d\n", strlen(inputName), restUpperlet);
// if (strlen(inputName) == restUpperlet + 1 && !isupper(inputName[0]))
// {
//     // printf("YES one small letter\n");
//     inputName[0] = toupper(inputName[0]);
//     for (int i = 1; i < strlen(inputName); i++)
//     {
//         inputName[i] = tolower(inputName[i]);
//     }
//     printf("%s", inputName);
//     return 0;
//     //  toupper(c)
// }
// else if (strlen(inputName) == restUpperlet && isupper(inputName[0]))
// {
//     // printf("YES all first letter\n");
//     for (int i = 0; i < strlen(inputName); i++)
//     {
//         inputName[i] = tolower(inputName[i]);
//     }
//     printf("%s", inputName);
//     return 0;
// }
// else
// {
//     printf("%s", inputName);
// }

#include <stdio.h>
#include <string.h>

// int n, result = 0;
// scanf("%d", &n);
// char number[n + 1];
// scanf("%s", &number);
// for (int j = 0; j < n; j++)
// {
//     if (number[j] == '8' && strlen(number) >= 11)
//     {
//         resultArr[i] = 1;

//         printf("%d\n", resultArr[i]);
//         // result[i] = 1;
//         break;
//     }
// }

// int main()
// {
//     int num;
//     scanf("%d", &num);
//     int resultArr[num];
//     memset(resultArr, 0, num);

//     for (int i = 0; i < num; i++)
//     {
//         int n;
//         scanf("%d", &n);
//         char number[n + 1];
//         scanf("%s", &number);
//         for (int j = 0; j < n; j++)
//         {
//             if (number[j] == '8' && strlen(number) >= 11 && n - j >= 11)
//             {
//                 resultArr[i] = 1;
//                // printf("  resultArr[0] in first loop =>%d I %d\n", resultArr[i], i);
//                 break;
//             }
//             else if (j == n - 1)
//             {
//                 resultArr[i] = 0;
//                 //  printf("  resultArr[0] in second loop =>%d I %d\n", resultArr[i], i);
//             }
//             // printf("test first befor for  resultArr[i]=> %d\n", resultArr[i]);
//         }
//     }

//     for (int i = 0; i < num; i++)
//     {
//         // printf("this is the result arry=>%d\n", resultArr[i]);
//         if (resultArr[i])
//             printf("YES\n");
//         else
//             printf("NO\n");
//         // if (i != num - 1)
//         //     printf("\n");
//     }
//     // }
//     return 0;
// }


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
char *strrev(char *str)
{
    if (!str || *str)
    {
        return str;
        int i = strlen(str) - 1, j = 0;

        char ch;
        while (i > j)
        {
            ch = str[i];
            str[i] = str[j];
            str[j] = ch;
            i--;
            j++;
        }
        return str;
    }
};

struct Binary
{
    char str[50];
};

struct Binary toBinary(unsigned int val, int k)
{
    struct Binary ans;
    int idx = 0;
    while (val > 0)
    {
        int d = val % 2;
        val /= 2;
        ans.str[idx] = d + '0';
        idx++;
    }
    for (int i = idx; i < k; i++)
    {
        ans.str[i] = '0';
    };
    ans.str[k] = 0;
    strrev(ans.str);
    return ans;
};





unsigned int clearBit(unsigned int mask, int k)
{
    int initialMask = mask;
    for (int i = 8; i >= k; i--)
    {
        int newMask = initialMask & ~(1 << i);
        initialMask = newMask;
       
    }

    return initialMask;
}


int main()
{
    int x = 56;

     printf("Clear: %s\n", toBinary(clearBit(x, 4), 8).str);
}
