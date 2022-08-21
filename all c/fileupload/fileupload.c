#include <stdio.h>
#include <time.h>
int main()
{
    //---------------------------------2------------------------------------
    // int n, sum = 0;
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     scanf("%d", &x);
    //     sum += x;
    // }
    // printf("Sum of total is => %d\n", sum);

    //--------------------------1----------------------------------
    // FILE *inputFile;
    // inputFile = fopen("input.txt", "r");
    // if (inputFile == NULL)
    // {
    //     printf("Error opening file");
    //     return 0;
    // }
    // FILE *outputFile;
    // outputFile = fopen("output.txt", "w");
    // while (1)
    // {
    //     char ch = fgetc(inputFile);
    //     if (ch == EOF)
    //     {
    //         break;
    //     }
    //     fputc(ch, outputFile);
    // }
    //---------------------------3----------------------------------
    // int n, sum = 0;

    // FILE *inputFile;
    // inputFile = fopen("input.txt", "r");
    // FILE *outputFile;
    // outputFile = fopen("output.txt", "w");
    // fscanf(inputFile, "%d", &n);
    // if (inputFile == NULL)
    // {
    //     printf("Error opening file");
    //     return 0;
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     fscanf(inputFile, "%d", &x);
    //     sum += x;
    // }
    // fprintf(outputFile, "Sum of total are => %d\n", sum);

    //----------------------------------4----------------------------------
    int n, sum = 0;

    FILE *inputFile;
    inputFile = fopen("input2.txt", "r");
    FILE *logFile = fopen("log.txt", "a");
    FILE *outputFile;
    outputFile = fopen("output.txt", "w");
    fscanf(inputFile, "%d", &n);
    if (inputFile == NULL)
    {
        time_t t = time(NULL);
        fprintf(logFile, "Error opening file at  %s", ctime(&t));
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        fscanf(inputFile, "%d", &x);
        sum += x;
    }
    fprintf(outputFile, "Sum of total are => %d\n", sum);
    fclose(outputFile);
    fclose(inputFile);
    return 0;
}