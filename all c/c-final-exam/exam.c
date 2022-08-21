
#include <stdio.h>
struct Student
{
    int roll;
    int class;
    int marks;
};
int main()
{
    int n, totalMarks = 0;
    scanf("%d", &n);
    struct Student s1[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &s1[i].roll, &s1[i].class, &s1[i].marks);
    }
    for (int i = 0; i < n; i++)
    {
        // printf("%d %d %d\n", s1[i].roll,  s1[i].class, s1[i].marks);
        totalMarks += s1[i].marks;
    }
    printf("%d", totalMarks);
    return 0;
}
