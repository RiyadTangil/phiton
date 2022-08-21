#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Student2
{
    char name[100];
    int mark;
    int roll;
};
struct Unique_student
{
    char name[100];
    int total;
    int roll;
};

int main()
{

    FILE *inputFile;
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        printf("Error opening file");
        return 0;
    }
    FILE *outputFile;
    outputFile = fopen("output.txt", "w");
    int n, k = 0;
    // struct Student s1 = {.mark = 0, .roll = 1, .name = "A"};
    fscanf(inputFile, "%d", &n);
    struct Student2 s1[n];
    struct Unique_student unique_student[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(inputFile, "%s %d %d", &s1[i].name, &s1[i].mark, &s1[i].roll);
        bool found = false;
        for (int j = 0; j < k; j++)
        {
            if (s1[i].roll == unique_student[j].roll)
            {

                unique_student[j].total += s1[i].mark;
                found = true;
            }
        }
        if (found == false)
        {

            strcpy(unique_student[k].name, s1[i].name);
            unique_student[k].roll = s1[i].roll;
            unique_student[k].total = s1[i].mark;

            k++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (unique_student[i].total > unique_student[j].total)
            {
                struct Unique_student tmp = unique_student[i];
                unique_student[i] = unique_student[j];
                unique_student[j] = tmp;
            }
        }
    }

    for (int s = 0; s < k; s++)
    {
        fprintf(outputFile, "Name: %s total=>%d roll=>%d\n", unique_student[s].name, unique_student[s].total, unique_student[s].roll);
    }

    return 0;
}