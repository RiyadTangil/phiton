// #include <stdio.h>
// #include <string.h>
// unsigned int binaryToInt(char str[])
// {
//     int len = strlen(str);
//     unsigned int ans = 0;
//     for (int i = len - 1, p2 = 1; i >= 0; i--, p2 *= 2)
//     {
//         int bit = str[i] - '0';
//         if (bit == 1)
//         {
//             ans += p2;
//         }
//     }
//         return ans;
// }
// int main()
// {
//     printf(" result%d\n", binaryToInt("1010"));
//     return 0;
// }

//..........................tobynary.................................................

#include <stdio.h>
#include <string.h>
void toBinary(unsigned int val, char str[])
{
    int idx = 0;
    while (val > 0)
    {
        int d = val % 2;
        val /= 2;
        str[idx] = d + '0';
        idx++;
    }
    // for("have to reverse my self")
    str[idx] = '\0';
}
int main()
{

    char str[100];
    unsigned int val = 25;
    toBinary(val, str);
    printf("%s\n", str);
    return 0;
}
