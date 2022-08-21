#include <stdio.h>
#include <string.h>
struct Student
{
    char name[20];
    int mark;
    int roll;
    // int lastMark[10];
};

//----------------------------1-----------------
// struct Student s1 = {.mark = 100, .roll = 1, .name = "A"};
// s1.roll = 100;
// s1.mark = 80;
// strcpy(s1.name, "Riyad");
// for (int i = 0; i < 10; i++)
// {
//     scanf("%d", &s1.lastMark[i]);
// }
// for (int i = 0; i < 10; i++)
// {
//     printf(" this is last no =>%d\n", s1.lastMark[i]);
// }
//-------------------------------------2-----------------------------------
// int n;
// scanf("%d", &n);
// struct Student height = {.mark = 0};
// for (int i = 0; i < n; i++)
// {
//     struct Student s1;
//     scanf("%s %d %d", &s1.name, &s1.mark, &s1.roll);
//     if (s1.mark > height.mark)
//     {
//         height = s1;
//     }
// }

// // printStruc(&s1);
// printf("%s\n", height.name);
//------------------------3-----------------------
void printStruc(struct Student s)
{
    printf("Name: %s roll=>%d mark=>%d mark\n", s.name, s.roll, s.mark);
}
void scanStruc(struct Student *s)
{
    (*s).mark = 100;
    s->roll = 10;
    strcpy(s->name, "Riyad");
    // scanf("%d", s->roll);
}

int main()
{
    struct Student s1 = {.mark = 0, .roll = 1, .name = "A"};
    scanStruc(&s1);
    printStruc(s1);

    return 0;
}